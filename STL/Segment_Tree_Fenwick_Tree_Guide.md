# 🚀 Segment Tree + Fenwick Tree (Binary Indexed Tree) Guide (C++)

Complete reference for: - Competitive Programming - LeetCode Hard -
Range Query Problems

------------------------------------------------------------------------

# 📌 1️⃣ When to Use These?

Use when problem involves:

-   Range sum / min / max queries
-   Point updates + range queries
-   Dynamic array updates
-   Prefix sums with updates
-   Order statistics (advanced)

------------------------------------------------------------------------

# 🚀 2️⃣ Fenwick Tree (Binary Indexed Tree - BIT)

## 📌 Best For:

-   Prefix sum queries
-   Point updates
-   Simpler than segment tree
-   Less memory

### ⏱ Time Complexity

-   Update: O(log n)
-   Query: O(log n)
-   Space: O(n)

------------------------------------------------------------------------

## 📌 Fenwick Tree Template

``` cpp
class Fenwick {
    vector<long long> bit;
    int n;

public:
    Fenwick(int n){
        this->n = n;
        bit.assign(n+1, 0);
    }

    // Add value at index
    void update(int index, long long delta){
        for(++index; index <= n; index += index & -index)
            bit[index] += delta;
    }

    // Prefix sum [0...index]
    long long query(int index){
        long long sum = 0;
        for(++index; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }

    // Range sum [l...r]
    long long rangeQuery(int l, int r){
        return query(r) - query(l-1);
    }
};
```

------------------------------------------------------------------------

# 🚀 3️⃣ Segment Tree

## 📌 Best For:

-   Range sum/min/max
-   Range updates (lazy propagation)
-   Complex queries

### ⏱ Time Complexity

-   Build: O(n)
-   Query: O(log n)
-   Update: O(log n)
-   Space: O(4n)

------------------------------------------------------------------------

# 📌 Segment Tree (Range Sum) Template

``` cpp
class SegmentTree {
    vector<long long> tree;
    int n;

public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        tree.resize(4*n);
        build(arr, 0, 0, n-1);
    }

    void build(vector<int>& arr, int node, int start, int end){
        if(start == end){
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    long long query(int node, int start, int end, int l, int r){
        if(r < start || end < l)
            return 0;

        if(l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) +
               query(2*node+2, mid+1, end, l, r);
    }

    void update(int node, int start, int end, int idx, int val){
        if(start == end){
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if(idx <= mid)
                update(2*node+1, start, mid, idx, val);
            else
                update(2*node+2, mid+1, end, idx, val);

            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }
};
```

------------------------------------------------------------------------

# 🚀 4️⃣ Lazy Propagation (Range Update)

## 📌 Use When:

-   Range updates
-   Range queries

Time: O(log n)

Concept: - Delay updates - Store pending updates in lazy array

------------------------------------------------------------------------

# 🚀 5️⃣ Fenwick vs Segment Tree

  Feature           Fenwick           Segment Tree
  ----------------- ----------------- -----------------
  Code Complexity   Easy              Medium
  Range Sum         Yes               Yes
  Range Min/Max     No                Yes
  Range Update      Hard              Easy (Lazy)
  Memory            O(n)              O(4n)
  Speed             Slightly Faster   Slightly Slower

------------------------------------------------------------------------

# 🚀 6️⃣ When to Use What?

-   Only prefix sum + point update → Fenwick
-   Range min/max → Segment Tree
-   Range update + range query → Segment Tree (Lazy)
-   Competitive programming quick solution → Fenwick

------------------------------------------------------------------------

# 🧠 Pattern Recognition

  Problem Type            Use
  ----------------------- -------------------------
  Dynamic prefix sum      Fenwick
  Range sum queries       Both
  Range minimum query     Segment Tree
  Range update            Segment Tree
  Kth smallest in range   Segment Tree (advanced)

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Off-by-one indexing in Fenwick
-   Not allocating 4\*n in segment tree
-   Forgetting base case in recursion
-   Confusing 0-based vs 1-based indexing

------------------------------------------------------------------------

🔥 Master these and you unlock advanced range query problems.
