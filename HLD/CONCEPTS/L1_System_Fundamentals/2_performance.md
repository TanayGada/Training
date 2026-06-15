# Performance vs Scalability
- Performance = how fast we respond
- Scalability = how load grows with more machines
- Performance is per-request.
- Scalability is system growth.
- Performance = latency under load

### 4 Core Dimensions of Performance
1. Latency
2. Throughput
3. Percentiles (p50, p99)
4. Tail Latency

# Latency
- Time taken to complete one request (request → response)
- Measured in `ms`

### Why it matters
- user feel delay in latency directly -> bad ux
```
<100ms → instant
100–300ms → acceptable
300–1000ms → slow
>1s → bad UX
```
Latency directly affects:
- User experience
- Conversion
- Engagement
- Revenue

Even 100ms increase can hurt engagement in consumer apps.

### Numbers to Memorise
```
Same rack → ~0.1–0.5 ms
Same region → 1–5 ms
Cross region → 50–200 ms
SSD read → ~0.1 ms
HDD read → ~5–10 ms
Redis GET → ~0.2–1 ms
DB query → 1–20 ms
```

### Latency Composition
```
Total latency = 
    network +
    queue wait +
    processing +
    disk I/O +
    lock contention
```

### What impacts Latency
1. Network round trips
2. cross-region communication
3. synchronous calls
4. Cache Misses
5. Disk I/O
6. Lock Contension
7. Garbage Collection

### decisions
1. Caching
- If DB = 10ms and cache = 1ms → caching reduces latency 10×

2. Denormalization
- Joins increase round trips.

3. Batch vs Sync
- Synchronous multi-service calls increase latency linearly.

4. Co-location
- Cross-region adds 100ms instantly.

# Throughput
- Number of requests processed per second.
- Queries per second(QPS)/ Transactions per second(TPS)/ Requests per sec/ Writes per sec

### Important Relationship
`Throughput ≈ Concurrency / Latency`
eg:
- if latency = 100ms (0.1s) and server supports 100 concurrent threads
- througput = 100/0.1 = 1000 req/s

### Decisions Influenced
1. Horizontal scaling
- Add servers to increase throughput.
2. Async processing
- Move non-critical tasks to queues.
3. Sharding
- Split writes across DB nodes.
4. Rate limiting
- Prevent overload collapse.

## Tradeoff: Latency vs Throughput
- Sometimes we sacrifice latency to increase throughput.
- Example:
    - Batch writes → slower per request
    - But higher total throughput

# p50 and p99 (Percentiles)
- Average latency hides real problems.
- Percentiles show distribution.
```
p50 → median (typical user)
p90 → 90% of requests faster than this
p99 → worst 1% users experience this
p999 → extreme tail
```

### Why p99 Matters
- Users judge systems by bad experiences
- if p50 = 50ms, p99 = 2 seconds
- System feels slow

### Memorize
`p99 ≈ 3–10× p50 in real systems`

### Tail Amplification
When multiple services chain:
- If 5 services each have p99=100ms
- Combined tail can explode due to probability stacking.

# 4. Tail Latency
- Extreme slow responses
- Tail latency explodes due to:
    - queue buildup
    - GC pause
    - disk contention
    - lock contention
    - retry storms
    - network jitter

### Real Production Example

- Service A calls:
    - Auth
    - Profile
    - Feed
    - Recommendation

- Each adds variability.
- Final p99 = sum of worst components.

### How to Reduce Tail Latency
Production strategies:
1. Replication + hedged requests
    - Send duplicate query to another replica if slow.
    - Google uses this in search.
    - Reduces p99 dramatically.
2. Caching hot data
3. Timeout + fallback
4. Load shedding
5. Circuit breakers
6. Bulkheads

## Designing Flow
#### Step 1
- Define expected latency target:
    - API → <100ms
    - Feed → <200ms
    - Chat → <50ms
    - Search → <100ms

#### Step 2
- Estimate throughput
    - DAU
    - peak QPS
    - concurrency

#### Step 3
- Check saturation
    - CPU?
    - IO?
    - network?

#### Step 4
- Design for p99
    - replication
    - timeouts
    - caching