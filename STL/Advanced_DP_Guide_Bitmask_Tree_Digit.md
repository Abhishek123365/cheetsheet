# 🚀 Advanced Dynamic Programming Guide

(Bitmask DP + Tree DP + Digit DP) -- C++

For: - Competitive Programming (1600+ CF) - LeetCode Hard - Advanced
Placement Rounds

------------------------------------------------------------------------

# 📌 1️⃣ Bitmask DP

## 📌 Use When:

-   n ≤ 20
-   Subset problems
-   Traveling Salesman Problem (TSP)
-   Assignment / matching problems
-   State compression needed

State Representation:

    dp[mask][last]

Where: - `mask` → represents visited nodes - `last` → last selected
element

------------------------------------------------------------------------

## 🚀 Traveling Salesman Problem (TSP)

### ⏱ Time Complexity: O(n² \* 2ⁿ)

``` cpp
const int INF = 1e9;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int mask, int pos){
    if(mask == (1 << n) - 1)
        return dist[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < n; city++){
        if(!(mask & (1 << city))){
            ans = min(ans,
                      dist[pos][city] +
                      tsp(mask | (1 << city), city));
        }
    }

    return dp[mask][pos] = ans;
}
```

------------------------------------------------------------------------

# 📌 2️⃣ Tree DP

## 📌 Use When:

-   DP on trees
-   Subtree calculations
-   Maximum path sum in tree
-   Independent set in tree

Tree = Graph without cycles

------------------------------------------------------------------------

## 🚀 Example: Subtree Sum

### ⏱ Time Complexity: O(n)

``` cpp
vector<vector<int>> adj;
vector<int> subtreeSum;
vector<int> values;

void dfs(int node, int parent){
    subtreeSum[node] = values[node];

    for(int neighbor : adj[node]){
        if(neighbor == parent) continue;

        dfs(neighbor, node);
        subtreeSum[node] += subtreeSum[neighbor];
    }
}
```

------------------------------------------------------------------------

## 🚀 Example: Maximum Independent Set in Tree

``` cpp
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int node, int parent){
    dp[node][0] = 0;           // not take
    dp[node][1] = 1;           // take

    for(int neighbor : adj[node]){
        if(neighbor == parent) continue;

        dfs(neighbor, node);

        dp[node][0] += max(dp[neighbor][0],
                           dp[neighbor][1]);

        dp[node][1] += dp[neighbor][0];
    }
}
```

State: - dp\[node\]\[0\] → not included - dp\[node\]\[1\] → included

------------------------------------------------------------------------

# 📌 3️⃣ Digit DP

## 📌 Use When:

-   Count numbers in range
-   Constraints on digits
-   "How many numbers ≤ N satisfy condition?"

Typical state:

    dp[pos][tight][other_state]

Where: - pos → current digit index - tight → whether prefix is fixed -
other_state → depends on problem

------------------------------------------------------------------------

## 🚀 Example: Count numbers ≤ N with digit sum ≤ S

``` cpp
string num;
int dp[20][2][200];

int solve(int pos, int tight, int sum){
    if(sum < 0) return 0;
    if(pos == num.size())
        return 1;

    if(dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];

    int limit = tight ? num[pos] - '0' : 9;
    int result = 0;

    for(int digit = 0; digit <= limit; digit++){
        int newTight = tight && (digit == limit);
        result += solve(pos+1, newTight, sum-digit);
    }

    return dp[pos][tight][sum] = result;
}
```

------------------------------------------------------------------------

# 📌 4️⃣ DP Optimization Techniques

## 🔹 State Compression

Use bitmask instead of large arrays.

## 🔹 Space Optimization

If dp\[i\] depends only on previous row → use 1D.

## 🔹 Memoization vs Tabulation

-   Recursion easier to write
-   Iterative faster & safer

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type                Use
  --------------------------- ------------
  Subset / TSP                Bitmask DP
  Tree-based optimization     Tree DP
  Counting numbers in range   Digit DP
  Independent set in tree     Tree DP
  Assignment problem          Bitmask DP
  Number with constraints     Digit DP

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Forgetting to initialize DP with -1
-   Exponential state explosion
-   Not reducing state dimensions
-   Wrong tight logic in Digit DP
-   Forgetting parent check in Tree DP

------------------------------------------------------------------------

🔥 Master these and you move into advanced competitive programming
territory.
