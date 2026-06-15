## Introduction

- Typically used for dynamic graphs
- Dynamic graphs are graphs which changes their configuration continously

You have elements divided into groups (sets), and you want to:

* Quickly check if two elements belong to the same group
* Efficiently merge two groups

## Disjoint Set data structure
2 types of functionalities
1. findPar() -> finding the parent of a node
2. union() -> adds an edge between 2 vertices (union by rank, union by size)

    

## Union by Rank
### Rank
The rank of a node generally refers to the distance (the number of nodes including the leaf node) between the furthest leaf node and the current node. Basically rank includes all the nodes beneath the current node.

### Ultimate parent:
The parent of a node generally refers to the node right above that particular node. But the ultimate parent refers to the topmost node or the root node.

### Union of u,v
Step1: find ultimate parent of u and v
Step2: find rank of them
Step3: connect ultimate parent with smaller rank node to ultimate parent having larger rank


### Path Compression
Instead of recursively finding the ultimate parent, we can compress path to have node always have its direct parent as ultimate path

TC is 4 alpha, near about constant
```cpp
class DisjoinSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    // path compression
    int findUltimateParent(int node){
        if(parent[node] == node)    return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ultParU = findUltimateParent(u);
        int ultParV = findUltimateParent(v);
        if(ultParU == ultParV)  return;
        if(rank[ultParU] < rank[ultParV]){
            parent[ultParU] = ultParV;
        }
        else if(rank[ultParV] < rank[ultParU]){
            parent[ultParV] = ultParU;
        }
        else{
            parent[ultParV] = ultParU;
            rank[ultParU]++;
        }
    }
}

```

## Union by Size
Instead of storing and using the rank, we use size for union
```cpp
class DisjoinSet{
    vector<int> sz, parent;
public:
    DisjointSet(int n){
        sz.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    // path compression
    int findUltimateParent(int node){
        if(parent[node] == node)    return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ultParU = findUltimateParent(u);
        int ultParV = findUltimateParent(v);
        if(ultParU == ultParV)  return;
        if(sz[ultParU] < sz[ultParV]){
            parent[ultParU] = ultParV;
            sz[ultParV] += sz[ultParU];
        }
        else{
            parent[ultParV] = ultParU;
            sz[ultParU] += sz[ultParV];
        }
    }
}

```