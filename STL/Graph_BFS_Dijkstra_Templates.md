# 🚀 Graph + BFS + Dijkstra Templates (C++)

Complete competitive programming ready templates.

------------------------------------------------------------------------

# 📌 1️⃣ Graph Representation (Adjacency List)

## Unweighted Graph

``` cpp
int n; // number of nodes
vector<vector<int>> adj(n);

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u); // remove if directed
}
```

------------------------------------------------------------------------

## Weighted Graph

``` cpp
int n;
vector<vector<pair<int,int>>> adj(n);
// pair -> {neighbor, weight}

void addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // remove if directed
}
```

------------------------------------------------------------------------

# 🚀 2️⃣ BFS Template (Unweighted Graph)

### 📌 Use When:

-   Shortest path in unweighted graph
-   Level order traversal
-   Connected components

### ⏱ Time Complexity: O(V + E)

``` cpp
vector<int> bfs(int start, vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neighbor : adj[node]){
            if(dist[neighbor] == -1){
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}
```

------------------------------------------------------------------------

# 🚀 3️⃣ DFS Template

### 📌 Use When:

-   Connected components
-   Cycle detection
-   Backtracking

### ⏱ Time Complexity: O(V + E)

``` cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node] = true;

    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, adj, visited);
        }
    }
}
```

------------------------------------------------------------------------

# 🚀 4️⃣ Dijkstra Template (Weighted Graph)

### 📌 Use When:

-   Shortest path in weighted graph
-   All weights are positive

### ⏱ Time Complexity: O((V + E) log V)

``` cpp
vector<int> dijkstra(int start, vector<vector<pair<int,int>>>& adj){
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;
    // {distance, node}

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto [currentDist, node] = pq.top();
        pq.pop();

        if(currentDist > dist[node]) continue;

        for(auto [neighbor, weight] : adj[node]){
            if(dist[node] + weight < dist[neighbor]){
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}
```

------------------------------------------------------------------------

# 🚀 5️⃣ Multi-Source BFS Template

### 📌 Use When:

-   Multiple starting points
-   Rotting oranges type problems

``` cpp
vector<int> multiSourceBFS(vector<int>& sources, vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    for(int s : sources){
        q.push(s);
        dist[s] = 0;
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neighbor : adj[node]){
            if(dist[neighbor] == -1){
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}
```

------------------------------------------------------------------------

# 🚀 6️⃣ Detect Cycle (Undirected Graph - BFS)

``` cpp
bool hasCycle(int start, vector<vector<int>>& adj, vector<bool>& visited){
    queue<pair<int,int>> q; // {node, parent}
    q.push({start, -1});
    visited[start] = true;

    while(!q.empty()){
        auto [node, parent] = q.front();
        q.pop();

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push({neighbor, node});
            }
            else if(neighbor != parent){
                return true;
            }
        }
    }

    return false;
}
```

------------------------------------------------------------------------

# 🧠 Quick Pattern Guide

  Problem Type                         Use
  ------------------------------------ ------------------
  Shortest path (unweighted)           BFS
  Shortest path (weighted, positive)   Dijkstra
  Connected components                 DFS/BFS
  Cycle detection                      DFS/BFS
  Level order traversal                BFS
  Backtracking                         DFS
  Multi-source shortest path           Multi-source BFS

------------------------------------------------------------------------

# 🎯 Final Advice

-   Use adjacency list for sparse graphs.
-   Always use `priority_queue` for Dijkstra.
-   BFS guarantees shortest path only in unweighted graphs.
-   Dijkstra requires non-negative weights.

------------------------------------------------------------------------

🔥 These templates are contest-ready and interview-safe.
