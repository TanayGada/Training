# Performance vs Scalability
- Performance = how fast we respond
- Scalability = how load grows with more machines
- Performance is per-request.
- Scalability is system growth.

## Scalability means:
- “Can the system handle 10× load without redesign?”

- Good systems scale by `add machines → still works`

## 3 Core Dimensions of Scalability
1. Vertical and Horizontal
2. Stateless and Stateful
3. Partitioning (Sharding)

# 1. Vertical and Horizontal Scaling
## Vertical Scaling
- Increase power of machine when load increases
### When it works well
- small systems
- prototypes
- single-node DB
- low traffic (< few 1000 QPS)
### Advantages
- simple
- no code changes
- no distributed complexity
- strong consistency easy

### Limitations
- hardware limit exists
- expensive (non-linear cost)
- single point of failure
- downtime during upgrade
- can’t reach massive scale

## Horizontal Scaling
- Increase number of machines when load increases
- Provides fault tolerance and elasticity

### When needed
- large scale
- millions of users
- high availability required

### Advantages
- near infinite scale
- fault tolerant
- cheaper commodity hardware
- rolling deploys possible

### Limitations
- distributed complexity
- consistency problems
- network overhead
- harder debugging
- operational complexity

# 2. Stateless and Stateful services
- What problem this solves: `“How easily can we add/remove servers?”`

## Stateless Services
- Server stores no session/user state locally
- Every request is independent
- Example:
    1. REST API
    2. auth service with JWT
    3. read-only services

### Why is this easier to scale
- Scales easily, because any service can be mapped to any servers
- No coordination is required, just add servers

### Advantages
- easy horizontal scaling
- simple load balancing
- easy autoscaling
- easy failover
- cheap

## Stateful
- Server stores session/user/connection state locally
- Examples
    1. WebSockets
	2. chat connections
	3. multiplayer games
	4. streaming sessions

### Why is this difficult to scale
- User is tied to server, so
1. Sticky session needed
2. Harder scaling
3. failover complicated

### Problems
- load imbalance
- harder autoscaling
- reconnection complexity
- state migration needed

#### Stateless possible?
- always choose stateless

#### Must be stateful (WebSockets)?
1. shard connections
2. use sticky sessions
3. externalize metadata

## Convert Stateful services to logically Stateless services
- Servers become stateless when we move states to
1. Redis
2. DB
3. Kafka
4. Shared storage
- keep services stateless and push state to Redis/DB so we can horizontally scale easily

# 3. Partitioning (Sharding)
- used when horizontal scaling is not enough
- What problem this solves: `One DB/service cannot handle all data/traffic`
- Def: Split data across multiple nodes.
```
users 1–1M → shard A
1M–2M → shard B
```

### Why needed
- Even horizontally scaled replicas fail because:
    - DB write limits
    - IOPS limits
    - memory limits
- eventually, 1 machine cannot hold all data

## Types of Partitioning
### 1. Hash Partitioning
`hash(key) % N`
#### Pros:
- uniform
#### Cons:
- hard rebalancing

### 2. Range Partitioning
```
userID ranges
time ranges
```
#### Pros:
- good for time-series
#### Cons:
- hotspots possible

### 3. Geo-Partitioning
`location based`
#### Pros:
- low latency
#### Cons:
- cross-region consistency

## Tradeoffs

### Pros
- massive scale
- parallelism
- isolates failures

### Cons
- cross-shard queries hard
- rebalancing hard
- operational complexity
- joins expensive

## Case
- When scale grows
1. first scale vertically
2. then scale horizontally
3. then scale by partioning
4. then scale by multi-region

## Case
1. small data -> single DB
2. large traffic but small data -> replicas
3. large data + large traffic -> sharding
4. global -> geo partitioning

```
Stateless first
Horizontal second
Partition when necessary
Vertical only early


API layer will be stateless so we can scale horizontally.
Once a single DB node becomes bottleneck, we’ll shard by userID.
For further growth, we can geo-partition per region.
```