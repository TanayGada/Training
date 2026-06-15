# Things to memorize
### 1. Time
```
- 1 day ≈ 10^5 sec
- 1 year ≈ 3 × 10^7 sec
```

### 2. Storage
![](../images/1.png)

### 3. Numbers
![](../images/2.png)

### 4. Network
```
- 1 Gbps ≈ 125 MB/s
- 1 MB ≈ 8 Mb
```

### 5. Concurrency
```
- concurrent user = 5 - 20% of DAU
- no of sockets on server = concurrent users
```

# Estimation
### Do this
1. Estimate users
2. Estimate actions per user
3. Convert to per sec
4. Estimate size
5. Multiply
### get this
1. qeuries per sec (QPS)
2. Storage per day
3. Bandwidth

# Estimation Factors
## 1. peak vs average
#### Why it matters
- Systems fail during spikes, not average.
#### Memorise
```
- Peak = 3–5× average (normal apps)
- Peak = 10–20× (events/live/viral)
```
#### Assumptions
1. diurnal pattern
2. retries amplify
3. bursts occur

#### Which decisions it influences
1. server count
2. autoscaling
3. queue buffers
4. DB capacity

#### How decisions change
1. Peak small (≤2×) → static provisioning ok
2. Peak medium (3–5×) → autoscaling + buffers
3. Peak huge (10–20×) → queues mandatory + rate limiting + async

#### What interviewers probe
- What happens during traffic spike?

#### Critical systems
- ticketing, live events, payments balancing


## 2. Server Capacity Benchmarks
#### Why it matters
- Translates QPS → machine count

#### What to memorize
```
Web server → 5k–10k RPS
WebSocket server → 10k–50k connections
DB node → 10k–50k writes/sec
Redis → 100k–1M ops/sec
Kafka partition → ~50k–100k msgs/sec
```

#### Assumptions
- medium hardware

#### Which decisions it influences
1. cluster size
2. cost
3. shard count

#### How decisions change
1. Load fits few nodes → simpler design
2. 100s nodes → sharding required
3. 1000s nodes → multi-region + partitioning mandatory

#### What interviewers probe
- “How many machines?”

#### Critical systems
- all

## 3. Read vs Write Ratio
#### Why it matters
Defines DB architecture

#### What to memorize
```
Feed/search → 100–1000:1
Chat → 1:1
Analytics → write-heavy
```

#### Assumptions
- reads dominate

#### Which decisions it influences
1. caching
2. replicas
3. DB choice

#### How decisions change
1. Read-heavy → heavy cache + read replicas
2. Balanced → simple primary DB
3. Write-heavy → log/Kafka + batch processing

#### What interviewers probe
- “Do we need caching?”

#### Critical systems
- feeds, search


## 4. Fanout Amplification
#### Why it matters
- One write may explode to many

#### What to memorize
```
cost = writes × fanout
```

#### Assumptions
- multiple recipients

#### Which decisions it influences
1. push vs pull
2. storage duplication

#### How decisions change
1. Small fanout (<100) → fanout on write
2. Medium (100–10k) → hybrid
3. Large (100k+) → fanout on read

#### What interviewers probe
- “How handle large groups?”

#### Critical systems
- chat, feeds


## 5. Replication & Storage Multiplier
#### Why it matters
- Storage 4–5× raw

#### What to memorize
```
replication is 3x raw
indexes/overhead is 1.5x raw
effective_storage = raw × replication × indexes
effective_storage = 5x raw
```

#### Assumptions
- HA + indexes

#### Which decisions it influences
1. retention
2. storage tiering

#### How decisions change
1. Small storage → all hot DB
2. TB scale → partial cold tier
3. PB scale → object storage mandatory

#### What interviewers probe
- “Cost implications?”

#### Critical systems
- logs, chat history

## 6. Tail Latency (p99)
#### Why it matters
- Users feel slowest requests

#### What to memorize
```
p99 = 3–10× p50
```

#### Assumptions
- GC/network spikes

#### Which decisions it influences
1. caching
2. replication
3. timeouts


#### How decisions change
1. p99 acceptable → simple
2. p99 high → cache + replicate + reduce hops

#### What interviewers probe
- “How reduce tail latency?”

#### Critical systems
- search, payments

## 7. Hot Keys / Skew
#### Why it matters
- Uneven traffic crashes partitions

#### What to memorize
```
Top 1% → 30–50% load
```

#### Assumptions
- celebrity effect

#### Which decisions it influences
1. partition key
2. consistent hashing

#### How decisions change
1. Uniform → simple sharding
2. Mild skew → more shards
3. Heavy skew → dynamic/hashed/sharded by secondary key

#### What interviewers probe
“What about hotspots?”

#### Critical systems
- feeds, leaderboards


## 8. Message Size Realism
#### Why it matters
- Size mistakes multiply infra 10×

#### What to memorize
```
text msg → 200–500B
JSON API → 1–5 KB
image → 2–5 MB
video → 5–50 MB/min
log line → 200–500B

```

#### Assumptions
- metadata overhead

#### Which decisions it influences
1. bandwidth
2. storage
3. CDN

#### How decisions change
1. Small payload → DB fine
2. Medium → compression
3. Large media → CDN/object store

#### What interviewers probe
“What’s average size?”

#### Critical systems
- media


## 9. Cache Effect Math
#### Why it matters
- Cache reduces DB load drastically

#### What to memorize
```
DB = traffic × (1 – hit)
```

#### Assumptions
- temporal locality

#### Which decisions it influences
1. caching necessity
2. DB scaling

#### How decisions change
1. <50% hit → weak benefit
2. 80–90% → big improvement
3. 95%+ → DB almost idle

#### What interviewers probe
- “How much does cache help?”

#### Critical systems
- read-heavy


## 10. Retry / Failure Amplification
#### Why it matters
- Failures multiply load

#### What to memorize
```
effective = base × (1+retries)
```

#### Assumptions
- clients retry

#### Which decisions it influences
1. rate limits
2. backoff
3. queues

#### How decisions change
1. Few retries → simple
2. heavy retries → circuit breakers mandatory

#### What interviewers probe
- “What happens during outage?”

#### Critical systems
- all


## 11. Multi-Region Replication Cost
#### Why it matters
- Latency + $$$

#### What to memorize
```
50–200ms extra latency
cross-region bandwidth expensive (2–5× cost)
```

#### Assumptions
- geo separation

#### Which decisions it influences
1. async vs sync replication

#### How decisions change
1. low latency need → regional isolation
2. strong consistency need → sync (higher latency)

#### What interviewers probe
- “How handle global users?”

#### Critical systems
- global apps


## 12. Growth Over Time
#### Why it matters
- Systems must survive growth

#### What to memorize
```
3–5× yearly growth
```

#### Assumptions
- business grows


#### Which decisions it influences
1. shards
2. partitioning

#### How decisions change
1. slow growth → simple
2. fast growth → pre-shard early

#### What interviewers probe
- “How future-proof?”

#### Critical systems
- all


## 13. Disk IOPS
#### Why it matters
- DB bottleneck = IO, not size

#### What to memorize
```
HDD → ~100 IOPS
SSD → ~5k–50k IOPS
NVMe → 100k+ IOPS
```

#### Assumptions
- random writes

#### Which decisions it influences
1. shard count
2. batching
3. storage type

#### How decisions change
1. low IOPS → more shards
2. high IOPS → fewer nodes

#### What interviewers probe
- “Will disk sustain this?”

#### Critical systems
- DB-heavy


## 14. Memory / RAM Sizing

#### Why it matters
- Many systems are memory-bound, not CPU-bound
- Caches (Redis), in-memory indexes, search engines must fit in RAM
- If data doesn’t fit → latency explodes (disk fallback)

#### What to memorize
```
1 Redis node ≈ 50–200 GB practical
RAM is expensive
RAM << disk capacity
```

#### Assumptions
1. hot data fits in memory
2. cache hit rate depends on working set size
3. RAM much faster than disk (100–1000×)
4. Breaks when:
    - working set > memory
    - random access patterns

#### Which decisions it influences
1. cache feasibility
2. number of Redis nodes
3. whether full in-memory system possible
4. index strategy

#### How decisions change
1. small dataset (<50GB) → single Redis/cache node fine
2. medium (100–500GB) → Redis cluster
3. large (TBs) → partial caching only
4. huge (PBs) → disk + tiered storage, not memory


#### What interviewers probe
1. “Can we cache everything?”
2. “How many Redis nodes needed?”
3. “Will this fit in memory?”

#### Critical systems
- cache, feed, leaderboard, search, session stores


## 15. Batch vs Realtime Workload

#### Why it matters
- Not everything needs low latency
- Batch is much cheaper + simpler

#### What to memorize
```
Realtime → latency critical
Batch → throughput focused
```

#### Assumptions
1. some tasks tolerate delay
2. business doesn’t need instant results
3. Breaks when:
    - user-facing actions
    - interactive features

#### Which decisions it influences
1. sync vs async
2. Kafka/queue usage
3. cron/batch jobs
4. infrastructure cost


#### How decisions change
1. latency < 100ms needed → realtime service
2. seconds acceptable → async queue
3. minutes/hours acceptable → batch jobs
4. offline analytics → S3 + batch processing

#### What interviewers probe
- “Can we batch this instead?”
- “How reduce infra cost?”

#### Critical systems
- analytics, logging, reports, ETL, data pipelines


## 16. Availability / SLA Math

#### Why it matters
- Uptime requirements dictate replication + complexity
- Higher SLA = exponentially higher cost

#### What to memorize
```
99%  → 3.6 days downtime/year
99.9% → 8.7 hours
99.99% → 52 min
99.999% → 5 min
```

#### Assumptions
- hardware fails
- networks fail
- deployments cause downtime
- Breaks when:
	- single region
	- no redundancy


#### Which decisions it influences
1. replication factor
2. multi-AZ/multi-region
3. failover strategy
4. redundancy

#### How decisions change
1. 99% → single region OK
2. 99.9% → replicas
3. 99.99% → multi-AZ
4. 99.999% → active-active multi-region

#### What interviewers probe
- “What availability do we target?”
- “How many 9s?”

#### Critical systems
- payments, banking, authentication, infra services
