# 🚀 STL Pattern Guide (LeetCode + CP + Interviews)

This guide helps you quickly decide:

> **Which STL container to use for which problem pattern**

------------------------------------------------------------------------

# 🚀 1️⃣ Frequency Counting

## 📌 Pattern

-   Count occurrences\
-   Find duplicates\
-   Two Sum\
-   Subarray sum equals K

## ✅ Use

**`unordered_map` → O(1) average**

``` cpp
unordered_map<int,int> freq;
freq[x]++;
```

### If order matters:

Use `map` → O(log n)

------------------------------------------------------------------------

# 🚀 2️⃣ Need Unique Elements

## 📌 Pattern

-   Remove duplicates\
-   Check if element exists\
-   Longest substring without repeating characters

## ✅ Use

-   `unordered_set` (fast)
-   `set` (if sorted order required)

------------------------------------------------------------------------

# 🚀 3️⃣ Sorted Data + Fast Insert/Delete

## 📌 Pattern

-   Maintain sorted window\
-   Sliding window median\
-   Order statistics

## ✅ Use

-   `multiset`
-   `set`

### Why?

-   `insert` → O(log n)
-   `erase` → O(log n)
-   Always sorted

------------------------------------------------------------------------

# 🚀 4️⃣ Top K Elements

## 📌 Pattern

-   K largest\
-   K smallest\
-   Merge k sorted lists

## ✅ Use

`priority_queue`

  Need         Use
  ------------ ----------
  K largest    Min heap
  K smallest   Max heap

------------------------------------------------------------------------

# 🚀 5️⃣ BFS / Level Order Traversal

## 📌 Pattern

-   Graph BFS\
-   Shortest path (unweighted)\
-   Tree level traversal

## ✅ Use

`queue`

``` cpp
queue<int> q;
```

------------------------------------------------------------------------

# 🚀 6️⃣ DFS / Backtracking

## 📌 Pattern

-   Recursion problems\
-   Permutations\
-   Subsets

## ✅ Use

-   `vector`
-   Recursion stack (implicit)

------------------------------------------------------------------------

# 🚀 7️⃣ Monotonic Stack Pattern

## 📌 Pattern

-   Next greater element\
-   Largest rectangle in histogram\
-   Daily temperatures

## ✅ Use

`stack`

------------------------------------------------------------------------

# 🚀 8️⃣ Sliding Window Maximum

## 📌 Pattern

-   Maximum in every window of size k

## ✅ Use

`deque`

### Why?

-   `push_front/back` → O(1)
-   `pop_front/back` → O(1)
-   Maintain decreasing order

------------------------------------------------------------------------

# 🚀 9️⃣ Binary Search Problems

## 📌 Pattern

-   Find element in sorted array\
-   Lower bound / upper bound\
-   Search in rotated array

## ✅ Use

-   `vector`
-   `lower_bound`
-   `upper_bound`

------------------------------------------------------------------------

# 🚀 🔟 Sorting Based Problems

## 📌 Pattern

-   Sort intervals\
-   Custom sort\
-   Merge intervals

## ✅ Use

-   `vector`
-   `sort()` with lambda comparator

------------------------------------------------------------------------

# 🚀 1️⃣1️⃣ Graph (Weighted)

## 📌 Pattern

-   Dijkstra\
-   Shortest path (weighted)

## ✅ Use

-   `priority_queue`
-   `vector<pair<int,int>>` adjacency list

------------------------------------------------------------------------

# 🚀 1️⃣2️⃣ Two Pointer Pattern

## 📌 Pattern

-   Sorted array problems\
-   Remove duplicates\
-   3 sum

## ✅ Use

-   `vector`
-   `sort()`

------------------------------------------------------------------------

# 🚀 1️⃣3️⃣ Prefix Sum / Running Sum

## 📌 Pattern

-   Subarray sum\
-   Range queries

## ✅ Use

-   `vector`
-   `unordered_map` (for prefix sum + hashing)

------------------------------------------------------------------------

# 🚀 1️⃣4️⃣ Kth Smallest / Largest

### Small N

Use `sort`

### Large N

Use: - `priority_queue` - `nth_element` → O(n) average

------------------------------------------------------------------------

# 🚀 1️⃣5️⃣ Maintain Order of Insertion

## 📌 Pattern

-   LRU Cache\
-   Maintain insertion order

## ✅ Use

-   `list`
-   `unordered_map`

------------------------------------------------------------------------

# 🔥 Real Interview Summary Table

  Problem Pattern          Best STL
  ------------------------ ----------------------
  Frequency Count          unordered_map
  Remove duplicates        unordered_set
  Sorted + insert/delete   set / multiset
  Top K                    priority_queue
  BFS                      queue
  DFS                      recursion + vector
  Next greater element     stack
  Sliding window max       deque
  Binary search            vector + lower_bound
  Custom sorting           sort + lambda
  Dijkstra                 priority_queue
  Kth smallest             nth_element

------------------------------------------------------------------------

# 🧠 Decision Tree (Quick Thinking Trick)

### 1️⃣ Do I need sorted order?

-   YES → `set` / `map`
-   NO → `unordered_*`

### 2️⃣ Do I need top element repeatedly?

-   YES → `priority_queue`

### 3️⃣ Need fast existence check?

-   YES → `unordered_set`

### 4️⃣ Need FIFO?

-   → `queue`

### 5️⃣ Need LIFO?

-   → `stack`

------------------------------------------------------------------------

🔥 Master this and you can solve 90% of LeetCode Medium problems
confidently.
