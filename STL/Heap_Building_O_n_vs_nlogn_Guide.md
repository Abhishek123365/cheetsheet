# 🚀 Heap Building in C++ (O(n) vs O(n log n))

Understanding how to efficiently build a heap in C++ for: - LeetCode -
Competitive Programming - Interviews

------------------------------------------------------------------------

# 📌 1️⃣ Building Heap by Pushing One by One

``` cpp
priority_queue<int> pq;

for(int x : arr)
    pq.push(x);
```

### ⏱ Time Complexity

Each `push()` operation takes **O(log n)**.

Total time:

    log(1) + log(2) + ... + log(n)
    ≈ n log n

So total complexity:

    O(n log n)

------------------------------------------------------------------------

# 📌 2️⃣ Building Heap in O(n) Time

Instead of inserting one by one, use:

``` cpp
#include <algorithm>

vector<int> arr = {4,1,3,2};
make_heap(arr.begin(), arr.end());
```

### ⏱ Time Complexity

    O(n)

------------------------------------------------------------------------

# 📌 3️⃣ Why is make_heap O(n)?

`make_heap()` uses **bottom-up heapify**:

-   Starts from last non-leaf node
-   Heapifies downward
-   Most nodes are near bottom (small height)
-   Total work becomes linear

Mathematically proven → **O(n)**

------------------------------------------------------------------------

# 📌 4️⃣ Heap Operations Using Heap Algorithms

### 🔹 Build heap

``` cpp
make_heap(v.begin(), v.end());
```

### 🔹 Insert element

``` cpp
v.push_back(x);
push_heap(v.begin(), v.end());
```

### 🔹 Remove top element

``` cpp
pop_heap(v.begin(), v.end());
v.pop_back();
```

------------------------------------------------------------------------

# 📌 5️⃣ Build Min Heap in O(n)

``` cpp
make_heap(v.begin(), v.end(), greater<int>());
```

------------------------------------------------------------------------

# 📌 6️⃣ Efficient priority_queue Construction

Better way:

``` cpp
vector<int> arr = {4,1,3,2};
priority_queue<int> pq(arr.begin(), arr.end());
```

### ⏱ Time Complexity

    O(n)

Internally builds heap using bottom-up method.

------------------------------------------------------------------------

# 📌 7️⃣ When Should You Care?

Important when:

-   Large inputs (10\^5 or more)
-   Tight time limits (Codeforces)
-   Building heap once before multiple queries
-   Implementing heap sort efficiently

------------------------------------------------------------------------

# 📌 8️⃣ Quick Comparison

  Method                              Time Complexity
  ----------------------------------- -----------------
  Push one by one                     O(n log n)
  make_heap                           O(n)
  priority_queue(range constructor)   O(n)

------------------------------------------------------------------------

# 🎯 Interview Insight

If asked:

> What is the time complexity of building a heap?

Correct answer:

    O(n)

Not O(n log n).

------------------------------------------------------------------------

🔥 Understanding this difference helps optimize performance in
competitive programming.
