# 🚀 Greedy Algorithms Master Guide (C++)

Complete reference for: - LeetCode - Competitive Programming - Placement
Interviews

------------------------------------------------------------------------

# 📌 1️⃣ What is Greedy Algorithm?

A Greedy algorithm makes the **locally optimal choice** at each step,
hoping it leads to a **globally optimal solution**.

Used when: - Problem has greedy choice property - Optimal substructure
exists - Sorting helps simplify decision making

------------------------------------------------------------------------

# 📌 2️⃣ Activity Selection Problem

## 📌 Pattern:

-   Maximum number of non-overlapping intervals

### ⏱ Time Complexity: O(n log n)

``` cpp
int maxActivities(vector<pair<int,int>>& intervals){
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b){
             return a.second < b.second;
         });

    int count = 0, lastEnd = -1;

    for(auto &interval : intervals){
        if(interval.first >= lastEnd){
            count++;
            lastEnd = interval.second;
        }
    }

    return count;
}
```

------------------------------------------------------------------------

# 📌 3️⃣ Fractional Knapsack

## 📌 Pattern:

-   Maximize profit
-   Items can be divided

### ⏱ Time Complexity: O(n log n)

``` cpp
double fractionalKnapsack(vector<pair<int,int>>& items, int W){
    // pair -> {value, weight}

    sort(items.begin(), items.end(),
         [](auto &a, auto &b){
             return (double)a.first/a.second >
                    (double)b.first/b.second;
         });

    double totalValue = 0;

    for(auto &item : items){
        if(W >= item.second){
            totalValue += item.first;
            W -= item.second;
        }
        else{
            totalValue += (double)item.first *
                          W / item.second;
            break;
        }
    }

    return totalValue;
}
```

------------------------------------------------------------------------

# 📌 4️⃣ Minimum Number of Coins (Greedy Works for Canonical Coins)

``` cpp
int minCoins(vector<int>& coins, int amount){
    sort(coins.rbegin(), coins.rend());

    int count = 0;

    for(int coin : coins){
        count += amount / coin;
        amount %= coin;
    }

    return amount == 0 ? count : -1;
}
```

⚠️ Note: Greedy works only when coin system is canonical.

------------------------------------------------------------------------

# 📌 5️⃣ Interval Merging

## 📌 Pattern:

-   Merge overlapping intervals

``` cpp
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= result.back()[1])
            result.back()[1] = max(result.back()[1],
                                   intervals[i][1]);
        else
            result.push_back(intervals[i]);
    }

    return result;
}
```

------------------------------------------------------------------------

# 📌 6️⃣ Jump Game

## 📌 Pattern:

-   Reachability
-   Greedy farthest reach

``` cpp
bool canJump(vector<int>& nums){
    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++){
        if(i > maxReach)
            return false;

        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}
```

------------------------------------------------------------------------

# 📌 7️⃣ Gas Station Problem

``` cpp
int canCompleteCircuit(vector<int>& gas,
                       vector<int>& cost){
    int total = 0, tank = 0, start = 0;

    for(int i = 0; i < gas.size(); i++){
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;

        if(tank < 0){
            tank = 0;
            start = i + 1;
        }
    }

    return total >= 0 ? start : -1;
}
```

------------------------------------------------------------------------

# 📌 8️⃣ Huffman Coding Concept

## 📌 Pattern:

-   Always combine smallest elements first

Use: - `priority_queue` (Min Heap)

------------------------------------------------------------------------

# 📌 9️⃣ Greedy Strategy Checklist

Ask yourself:

1️⃣ Can I sort the data?\
2️⃣ Can I make a local decision that seems best?\
3️⃣ Once chosen, does it reduce problem size?\
4️⃣ Is backtracking unnecessary?

If YES → Try Greedy

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type          Greedy Strategy
  --------------------- ------------------------
  Interval scheduling   Sort by end time
  Fractional knapsack   Sort by ratio
  Jump game             Track max reach
  Gas station           Reset on negative tank
  Merge intervals       Sort by start
  Huffman coding        Min heap

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Applying greedy where DP is required
-   Not proving greedy choice property
-   Forgetting to sort
-   Ignoring edge cases

------------------------------------------------------------------------

🔥 Master these greedy patterns and you can solve most interval &
optimization problems confidently.
