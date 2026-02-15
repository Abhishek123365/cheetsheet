# 🚀 Dynamic Programming Master Guide (C++)

Complete reference for: - LeetCode - Competitive Programming - Placement
Interviews

------------------------------------------------------------------------

# 📌 1️⃣ What is Dynamic Programming?

Dynamic Programming (DP) is used when:

-   Problem has overlapping subproblems
-   Problem has optimal substructure
-   Brute force recursion gives TLE

DP = Recursion + Memoization OR Tabulation

------------------------------------------------------------------------

# 📌 2️⃣ 1D DP Template

## Example: Fibonacci

### 🔹 Memoization (Top-Down)

``` cpp
vector<int> dp(100, -1);

int fib(int n){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}
```

### 🔹 Tabulation (Bottom-Up)

``` cpp
int fib(int n){
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```

Time: O(n)\
Space: O(n)

------------------------------------------------------------------------

# 📌 3️⃣ 2D DP Template

## Example: Longest Common Subsequence (LCS)

``` cpp
int lcs(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}
```

Time: O(n*m)\
Space: O(n*m)

------------------------------------------------------------------------

# 📌 4️⃣ Knapsack Template (0/1 Knapsack)

``` cpp
int knapsack(vector<int>& wt, vector<int>& val, int W){
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}
```

Time: O(nW)

------------------------------------------------------------------------

# 📌 5️⃣ Subset Sum Template

``` cpp
bool subsetSum(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= n; i++){
        for(int sum = 1; sum <= target; sum++){
            if(nums[i-1] <= sum)
                dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-nums[i-1]];
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }

    return dp[n][target];
}
```

------------------------------------------------------------------------

# 📌 6️⃣ Longest Increasing Subsequence (O(n log n))

``` cpp
int lengthOfLIS(vector<int>& nums){
    vector<int> temp;

    for(int num : nums){
        auto it = lower_bound(temp.begin(), temp.end(), num);

        if(it == temp.end())
            temp.push_back(num);
        else
            *it = num;
    }

    return temp.size();
}
```

Time: O(n log n)

------------------------------------------------------------------------

# 📌 7️⃣ DP on Grid

## Example: Unique Paths

``` cpp
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}
```

------------------------------------------------------------------------

# 📌 8️⃣ DP State Design Trick

Ask yourself:

1️⃣ What is changing?\
2️⃣ What are the parameters?\
3️⃣ What is the recurrence relation?\
4️⃣ What are base cases?

DP State = dp\[index\]\[extra_parameter\]

------------------------------------------------------------------------

# 📌 9️⃣ Space Optimization Trick

If dp\[i\] depends only on dp\[i-1\],\
use 1D array instead of 2D.

Example:

``` cpp
vector<int> dp(n+1);
```

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type             DP Type
  ------------------------ ---------------
  Fibonacci type           1D DP
  Subsequence              2D DP
  Knapsack                 2D DP
  Grid problems            Matrix DP
  Partition problems       Subset Sum DP
  Increasing subsequence   LIS
  Min/Max path             Grid DP

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Not defining correct state
-   Wrong base case
-   Using recursion without memoization
-   Forgetting to initialize DP table
-   Not optimizing space when possible

------------------------------------------------------------------------

🔥 Master these templates and you can solve most medium-to-hard DP
problems confidently.
