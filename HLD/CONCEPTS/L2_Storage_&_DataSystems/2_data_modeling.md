# Universal Data Modeling Laws

1. Model for access pattern.
2. Partition first, schema second.
3. Composite index must match WHERE + ORDER BY.
4. Append-only scales better than update-heavy.
5. Every index has a write cost.
6. Avoid cross-partition operations.
7. Hot partitions kill systems.
8. Denormalize for reads.
9. Precompute expensive queries.
10. Data lifecycle must be planned.

## Data Modeling is for
- query patterns
- load distribution
- consistency boundaries
- storage engine behavior
- future evolution

## At scale, bad modeling causes:
- Table scans
- Hot partitions
- Lock contention
- Exploding index size
- Cross-shard joins
- N+1 queries
- Replication lag

---

# Modeling for High write systems (Chats, Payments)
### What are High Write Systems
Examples:
- Chat (messages/sec massive)
- Logging systems
- Payment ledgers
- Metrics ingestion
- Clickstream tracking
- IoT ingestion

Characteristics:
- Write throughput dominates reads
- Writes often append-only
- Low latency write requirement
- Often distributed
- Data volume grows rapidly
- Reads are typically recent-window

### Why writes are expensive at scale
- Indexes must be updated
- Replicas must replicate
- Locks may be acquired
- Disk writes happen
- WAL (write-ahead log) flushed
- Compaction happens (LSM systems)

### Principle 1: Prefer Append-Only
- Updates are expensive
- Bad: `UPDATE messages SET status='read'`
- Becasue
    - Row lock
    - Random disk I/O
    - Replication overhead
    - Index maintenance
    - Write amplification
- Better: `INSERT INTO message_status (message_id, status, updated_at)`
- Append-only means:
    - Sequential disk writes
    - Fewer locks
    - Better batching
    - Better replication

### Principle 2: Partition to Distribute Writes
- Bad partition key → hotspot
- Bad Partition Key: 
    - `country`: If 70% traffic from one country → one node overloaded.
- Good partition Key: High cardinality → even distribution
    - conversation_id
    - user_id
    - ride_id
    - transaction_id

#### Before finalizing partition key:
- Is cardinality high enough?
- Will 80% traffic hit 1 key?
- Does it align with dominant query?
- Does it allow partition-local reads?
- Can partitions be rebalanced?
- What happens when key grows unbounded?

### Principle 3: Minimize Secondary Indexes
Every index adds:
- Extra write cost
- Extra storage
- Extra replication

High write systems should:
- Keep indexes minimal
- Avoid unnecessary secondary indexes
- Avoid indexing large text columns

### Principle 4: Avoid Large Mutable Rows
- Bad:
    ```
    user_profile(
        user_id,
        bio,
        settings,
        preferences,
        last_seen,
        ...
    )
    ```
- Updating last_seen frequently:
    - Locks entire row
    - Index update
    - Replication overhead

- Better:
Separate frequently updated fields:
    ```
    user_last_seen(
        user_id PRIMARY KEY,
        last_seen
    )
    ```
- Small row → faster writes.

### Storage Engine Impact
- B-Tree Systems
    - Random writes
    - Index tree rebalancing
    - Page splits
    - Slower under heavy writes

- LSM-Tree Systems
    - Sequential writes
    - Buffered writes
    - Compaction overhead
    - Good for write-heavy

- High-write systems often use LSM-based databases
- But Compaction tuning becomes critical.

### Write Amplification
Definition: 
- The ratio of data written to the flash memory (NAND) divided by the data written by the host.

Occurs when:
- Indexes are many
- Denormalized fan-out
- Secondary indexes
- Compaction (LSM)

High write systems must minimize:
- Unnecessary indexes
- Heavy transactional overhead
- Large row updates

Random writes generate higher WA than sequential writes

### Replication Lag
- Heavy writes:
    - Replica falls behind
    - Read-after-write inconsistency

- Mitigation:
    - Write batching
    - Async replication tuning
    - Partitioning

### Backpressure
High write systems must:
    - Reject writes under overload
    - Queue intelligently
    - Avoid cascading failure

### High-Write System Modeling — Bad vs Good Patterns

| Bad Model | Good Model |
|------------|------------|
| Frequent updates | Append-only writes |
| Low cardinality partition key | High cardinality partition key |
| Many secondary indexes | Minimal necessary indexes |
| Large mutable rows | Small, focused rows |
| OR-heavy query patterns | Single partition key access pattern |
| Cross-shard joins | Localized partition queries |
| Derived state stored directly | Derived state computed from immutable events |
| Heavy transactional locking | Optimistic or append-based writes |
| Table scans for common queries | Composite index aligned with query pattern |
| Updating counters in-place | Event-based aggregation or batched updates |
| Centralized write bottleneck | Evenly distributed writes across partitions |
| Mixing hot and cold data | Separate hot vs cold partitions |
| Over-normalized schema for read-heavy path | Strategic denormalization for dominant reads |
| Unbounded partition growth | Time-bucketed or size-limited partitions |
| Ignoring write amplification | Minimizing indexes and fan-out writes |


### Whiling designing high-write system,
- Ask write QPS
- Ask cardinality of partition key
- Ask consistency needs
- Suggest append-only
- Suggest composite index
- Mention write amplification
- Mention hot key risk
- Mention compaction (if NoSQL)
- Mention replication lag


---
# Modeling for High read systems (Chats, Payments)
### High-read systems are optimized for:

- Low latency (<100ms or even <20ms)
- High QPS (millions of reads/sec)
- Personalized or filtered queries
- Predictable access patterns
- Heavy fan-out access (feeds, dashboards, search)

### Examples:
- Social media feeds
- Product catalogs
- Search results
- Profile pages
- Leaderboards

### Core Characteristics of High-Read Systems
- Read-to-write ratio often 10:1 to 1000:1
- Reads must avoid joins and sorting at runtime
- Data must be shaped for query patterns
- Denormalization is common
- Caching layers are critical
- Precomputation is often required


## Principle 1: Optimize for the Dominant Query

- Do not model for data purity.
- Model for the most frequent read query.

Ask:

- What is the most common read?
- What filters are applied?
- What sort order is required?
- Is pagination required?
- What is the SLA?

### Query Pattern Types

- Point lookup (WHERE id = ?)
- Range scan (WHERE created_at > ?)
- Sorted pagination (ORDER BY created_at DESC LIMIT N)
- Aggregation (COUNT, SUM)
- Join-heavy
- Time-window queries

Schema must optimize dominant pattern O(log n) or O(1).

## Principle 2: Denormalize Aggressively
- Joins at scale are expensive.
- instead of `posts JOIN users`
- store
    ```
    posts(
      post_id,
      user_id,
      username,
      profile_pic
    )
    ```

- Tradeoff:
    - Duplicate data
    - Need sync on updates

- Benefit:
    - Remove join
    - Faster reads

## Principle 3: Composite Index Matching Query
- Index must match `WHERE conditions + ORDER BY`
- Example
    ```
    WHERE user_id = ?
    ORDER BY created_at DESC
    ```
- Correct Index `(user_id, created_at DESC)`

## Principle 4:  Precompute Expensive Aggregations
- Instead of `COUNT(likes)`
- Maintain 
    ```
    posts(
      like_count
    )
    ```
- Update counter on write.

- Tradeoff:
    - Slight write overhead
    - Fast reads

## Principle 5: Avoid N+1 Queries
- Bad pattern:
    - 1 query to get posts
    - N queries to get comments
- Better: `SELECT * FROM comments WHERE post_id IN (...)`
- Or denormalize comment count.

## Principle 6: Separate Hot vs Cold Data
- Recent feed accessed often.
- Archive old feed.
- Benefits:
    - Smaller working set
    - Better cache hit ratio
    - Faster index traversal

### Cardinality & Selectivity

- High cardinality columns make good partition keys.
- High selectivity columns make good index candidates.
- Low selectivity index = poor performance.

### Pagination Rule
- Avoid OFFSET at scale.
- Use cursor-based pagination.
- Composite index must support cursor field.

### Read Amplification

Occurs when:
- LSM systems require multiple SSTable lookups
- Poor index alignment
- Large partitions scanned

High-read systems must minimize read amplification.

## Storage Engine Considerations
High-read systems benefit from:
- B-Tree indexes (range queries)
- Covering indexes
- Read replicas
- Caching layers (Redis)
- Memory-optimized storage

LSM systems may suffer read amplification.

## Write vs Read Tradeoff

High-read systems accept:
- Write amplification
- Extra storage
- Data duplication
- Background jobs

To achieve:
- Predictable low latency
- Scalable read throughput

## When modeling for high-read systems:
- Do you identify dominant read query?
- Do you denormalize intentionally?
- Do you design composite indexes properly?
- Do you remove joins from hot path?
- Do you precompute expensive aggregations?
- Do you avoid N+1?
- Do you mention caching?
- Do you consider read replicas?

### High-Read System Modeling — Bad vs Good Patterns

| Bad Model | Good Model |
|------------|------------|
| Runtime joins for dominant read | Denormalized read-optimized table |
| Sorting at query time | Pre-sorted composite index |
| No index on filter columns | Composite index matching query pattern |
| Frequent N+1 queries | Batch queries or precomputed data |
| Single huge table for all history | Separate hot vs cold partitions |
| Heavy on-the-fly aggregation | Precomputed counters / materialized views |
| Cross-shard read queries | Partition-local queries |
| Index order mismatch | Index order aligned with `WHERE` + `ORDER BY` |
| Storing only normalized data | Storing duplicated but query-efficient data |
| Full table scans for common queries | Index-covered lookups |
| Filtering after data retrieval | Indexed filtering before retrieval |
| Dynamic sorting on large datasets | Index-driven ordering |
