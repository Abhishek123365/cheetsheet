# 🚀 Advanced Graph Guide (MST + Topological Sort + SCC) - C++

Complete reference for: - Competitive Programming - LeetCode Hard -
Placement Interviews

------------------------------------------------------------------------

# 📌 1️⃣ Minimum Spanning Tree (MST)

Used when: - Connect all nodes with minimum total weight - Undirected
weighted graph

Two main algorithms: - Kruskal's Algorithm - Prim's Algorithm

------------------------------------------------------------------------

# 🚀 2️⃣ Kruskal's Algorithm (Using DSU)

### ⏱ Time Complexity: O(E log E)

``` cpp
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n){
        parent.resize(n);
        rank.assign(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

int kruskal(int n, vector<vector<int>>& edges){
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b){
             return a[2] < b[2]; // sort by weight
         });

    DSU dsu(n);
    int mstWeight = 0;

    for(auto &edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];

        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u, v);
            mstWeight += w;
        }
    }

    return mstWeight;
}
```

------------------------------------------------------------------------

# 🚀 3️⃣ Prim's Algorithm (Using Min Heap)

### ⏱ Time Complexity: O((V + E) log V)

``` cpp
int prim(int n, vector<vector<pair<int,int>>>& adj){
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    pq.push({0, 0}); // {weight, node}
    int totalWeight = 0;

    while(!pq.empty()){
        auto [weight, node] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        totalWeight += weight;

        for(auto [neighbor, w] : adj[node]){
            if(!visited[neighbor])
                pq.push({w, neighbor});
        }
    }

    return totalWeight;
}
```

------------------------------------------------------------------------

# 📌 4️⃣ Topological Sort (DAG Only)

Used when: - Task scheduling - Course schedule - Dependency resolution

------------------------------------------------------------------------

# 🚀 5️⃣ Kahn's Algorithm (BFS Based)

### ⏱ Time Complexity: O(V + E)

``` cpp
vector<int> topoSort(int n, vector<vector<int>>& adj){
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++){
        for(int neighbor : adj[i])
            indegree[neighbor]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int neighbor : adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return topo;
}
```

------------------------------------------------------------------------

# 🚀 6️⃣ Topological Sort (DFS Based)

``` cpp
void dfs(int node, vector<vector<int>>& adj,
         vector<bool>& visited, stack<int>& st){
    visited[node] = true;

    for(int neighbor : adj[node]){
        if(!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }

    st.push(node);
}

vector<int> topoDFS(int n, vector<vector<int>>& adj){
    vector<bool> visited(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i, adj, visited, st);

    vector<int> result;

    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
}
```

------------------------------------------------------------------------

# 📌 7️⃣ Strongly Connected Components (SCC)

Used when: - Directed graph - Need to find components where every node
is reachable

------------------------------------------------------------------------

# 🚀 8️⃣ Kosaraju's Algorithm

### ⏱ Time Complexity: O(V + E)

``` cpp
void dfs1(int node, vector<vector<int>>& adj,
          vector<bool>& visited, stack<int>& st){
    visited[node] = true;

    for(int neighbor : adj[node])
        if(!visited[neighbor])
            dfs1(neighbor, adj, visited, st);

    st.push(node);
}

void dfs2(int node, vector<vector<int>>& transpose,
          vector<bool>& visited){
    visited[node] = true;

    for(int neighbor : transpose[node])
        if(!visited[neighbor])
            dfs2(neighbor, transpose, visited);
}

int kosaraju(int n, vector<vector<int>>& adj){
    vector<bool> visited(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs1(i, adj, visited, st);

    vector<vector<int>> transpose(n);
    for(int i = 0; i < n; i++){
        for(int neighbor : adj[i])
            transpose[neighbor].push_back(i);
    }

    fill(visited.begin(), visited.end(), false);

    int sccCount = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!visited[node]){
            dfs2(node, transpose, visited);
            sccCount++;
        }
    }

    return sccCount;
}
```

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type                Algorithm
  --------------------------- ------------------
  Minimum connection cost     MST
  Undirected weighted graph   Kruskal / Prim
  Task scheduling             Topological Sort
  Detect cycle in DAG         Topo Sort
  Strongly connected groups   Kosaraju
  Condensation graph          SCC

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Applying topo sort on cyclic graph
-   Using MST on directed graph
-   Forgetting path compression in DSU
-   Not resetting visited array in Kosaraju

------------------------------------------------------------------------

🔥 Master these and you unlock advanced graph problems in contests.
