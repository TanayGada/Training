# "SQL doesnt scale" is wrong

- Modern SQL databases scale very well.
- Many NoSQL systems fail badly under poor modeling.
- Scalability is a property of architecture + workload — not just database type

# Factors Influencing scaling of SQL

### 1. Data Model Rigidity

| SQL | NoSQL |
|------|--------|
| Fixed schema | Flexible schema |
| Strong constraints (FK, types) | App-level validation |
| Structure-first | Data-shape evolves |
| Safer for complex domains | Faster for product iteration |


### 2. Access Pattern Predictability

| SQL | NoSQL |
|------|--------|
| Supports ad-hoc queries | Must design for known queries |
| Joins are natural | Joins avoided |
| Query planner optimizes | Access path must exist |
| Good for evolving reporting needs | Good for fixed lookup patterns |


### 3. Consistency Requirements

| SQL | NoSQL |
|------|--------|
| Strong ACID by default | Often eventual consistency |
| Single leader common | Leaderless or distributed writes |
| Safe for financial logic | Safe for high-availability systems |
| Strict ordering possible | Ordering harder across partitions |



### 3. Horizontal Scaling Model

| SQL | NoSQL |
|------|--------|
| Vertical scale first | Horizontal scale native |
| Sharding is complex | Partitioning built-in |
| Cross-shard joins painful | Cross-partition queries limited |
| Primary node write bottleneck | Writes distributed across cluster |


### 4. Operational Complexity

| SQL | NoSQL |
|------|--------|
| Mature tooling | Distributed systems tuning |
| Easier debugging | Harder debugging |
| Predictable behavior | Compaction, partition balancing |
| Fewer moving parts | More infrastructure moving parts |


## Recall Table

| Factor | SQL | NoSQL |
|---------|------|--------|
| Schema | Rigid | Flexible |
| Queries | Ad-hoc friendly | Predefined patterns |
| Consistency | Strong | Tunable/Eventual |
| Scaling | Harder horizontal | Native horizontal |
| Ops | Mature & stable | Distributed complexity |


> Why not SQL here?

- Access pattern is predictable
- High write throughput required
- Eventual consistency acceptable
- Global distribution needed

> Why not NoSQL?

- Strong transactional integrity required
- Complex joins needed
- Ad-hoc reporting required
- Strict ordering guarantees needed


SQL = Correctness + Flexibility in queries  
NoSQL = Scale + Simplicity in access patterns

# Database Types

## 1. Relational vs Key-Value vs Document vs Wide-Column


| Type | Best For | Core Idea |
|------|----------|-----------|
| Relational (SQL) | Strong correctness + complex queries | Structured schema + ACID |
| Key-Value | Simple lookups at massive scale | O(1) key access |
| Document | Flexible product iteration | JSON documents |
| Wide-Column | Massive write-heavy distributed systems | Partition-first design |



## 2. Data Model Comparison

| Factor | Relational | Key-Value | Document | Wide-Column |
|---------|------------|------------|------------|--------------|
| Structure | Fixed schema | Key → value | JSON documents | Partitioned rows |
| Joins | Supported | Not supported | Avoided (embed instead) | Not supported |
| Constraints | Strong (FK, integrity) | None | Minimal | None |
| Schema Evolution | Rigid | Easy | Easy | Moderate |
| Query Flexibility | Very high | Very low | Medium | Low |


## 3. Consistency & Transactions

| Factor | Relational | Key-Value | Document | Wide-Column |
|---------|------------|------------|------------|--------------|
| ACID | Strong | Limited | Limited | Tunable / eventual |
| Multi-row Transactions | Yes | Usually no | Limited | No (generally avoided) |
| Ordering Guarantees | Strong | Per key | Per document | Per partition |
| CAP Leaning | CP | AP (often) | Mixed | AP (default) |


## 4. Scaling Model

| Factor | Relational | Key-Value | Document | Wide-Column |
|---------|------------|------------|------------|--------------|
| Write Scaling | Primary bottleneck | Distributed | Sharded | Fully distributed |
| Read Scaling | Replicas | Distributed | Replica sets | Distributed |
| Native Sharding | Hard | Built-in | Built-in | Built-in |
| Cross-Partition Queries | Complex | Not possible | Limited | Limited |


## 5. Storage Engine Characteristics

| Engine Type | Used By | Strength | Weakness |
|-------------|----------|----------|----------|
| B-Tree | Relational DBs | Great for reads & complex queries | Random I/O heavy |
| LSM Tree | Key-Value, Wide-Column | High write throughput | Compaction overhead, read amplification |

# Strengths vs Weaknesses 

### 1. Relational 

| Strengths | Breaks / Weaknesses |
|------------|---------------------|
| Strong ACID guarantees | Very high global write throughput |
| Complex joins & aggregations | Multi-region active-active setups complex |
| Mature indexing (B-Tree, composite, partial) | Manual sharding complexity |
| Advanced query planner optimization | Large table schema migrations painful |
| Referential integrity | Primary write bottleneck |
| Strict transactional correctness | Cross-shard joins difficult |


### 2. Key Value stores
| Strengths | Breaks / Weaknesses |
|------------|---------------------|
| O(1) key-based lookups | No ad-hoc queries |
| Very high write throughput | No aggregations |
| Simple horizontal scaling | Relationship-heavy data modeling hard |
| Excellent for predictable access patterns | Complex reporting difficult |
| Low latency | Requires denormalization |
| Easy to scale operationally | Limited secondary indexing |


### 3. Document Stores
| Strengths | Breaks / Weaknesses |
|------------|---------------------|
| Flexible schema | Heavy relational joins painful |
| Embedded documents reduce joins | Large document updates expensive |
| Rapid iteration friendly | Lock contention on large docs |
| Good balance of flexibility + scale | Massive analytics weaker than SQL |
| Natural JSON modeling | Cross-document transactions limited |
| Easier schema evolution | Data duplication possible |


### 4. Wide-Column Stores
| Strengths | Breaks / Weaknesses |
|------------|---------------------|
| Massive write throughput | No joins |
| Multi-region support | Query flexibility limited |
| Leaderless replication | Must design for known access patterns |
| Tunable consistency | Partition key mistakes cause hot shards |
| Horizontally scalable by design | Cross-partition queries difficult |
| Highly available | Data modeling errors are costly |




> Case 1 — Global Chat System (500K msgs/sec)

Use Wide-Column.

Why not SQL?
- Primary write bottleneck
- Cross-region strong consistency expensive
- No need for complex joins
- Eventual consistency acceptable

> Case 2 — Payment Ledger

Use Relational.

Why not Cassandra?
- Need strict ACID
- Need guaranteed ordering
- Financial correctness > availability


> Case 3 — User Profile Service

Use Document Store.

Why not SQL?
- Schema evolves frequently
- Nested JSON structures
- Reads dominate writes
- Complex joins unnecessary



# Tradeoffs

## 1. Consistency vs Availability

| Type | Bias |
|------|------|
| Relational | CP leaning |
| Wide-Column | AP leaning |
| Dynamo-style KV | Tunable |


## 2. Operational Complexity

| Relational | Distributed NoSQL |
|------------|-------------------|
| Mature tooling | Partition balancing |
| Easier debugging | Repair & compaction |
| Predictable behavior | Tombstone cleanup |


## 3. Cost Model

| Relational | NoSQL |
|------------|--------|
| Vertical scaling expensive | More machines required |
| License costs (enterprise) | Operational overhead |
| Simpler infra | Distributed infra complexity |



### Few questions to ask before deciding type of DB

- What are read/write patterns?
- Do we need cross-row transactions?
- What consistency level is required?
- Expected QPS & data growth?
- Multi-region requirement?
- Schema volatility?
- Required query types?

## Final Mental Model

Relational = Correctness + Query Power  
Key-Value = Simplicity + Massive Scale  
Document = Flexibility + Product Speed  
Wide-Column = Write Scale + Global Distribution