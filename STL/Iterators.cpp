#include<bits/stdc++.h>
using namespace std;

int main(){

/* ============================================================
   1️⃣ VECTOR  (Dynamic Array)
   Access: O(1)
   push_back: O(1) amortized
   pop_back: O(1)
   insert/erase (middle): O(n)
   Random Access Iterator supported
============================================================ */

    vector<int> v = {1,2,3};

    v.push_back(4);          // O(1)
    v.pop_back();            // O(1)

    cout << "Vector size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    // Iterator traversal
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Reverse iterator
    for(auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;

    // Safe erase while iterating
    for(auto it = v.begin(); it != v.end(); ){
        if(*it == 2)
            it = v.erase(it);     // returns next iterator
        else
            it++;
    }


/* ============================================================
   2️⃣ PAIR
   All operations O(1)
============================================================ */

    pair<int,int> p = {10,20};
    cout << p.first << " " << p.second << endl;


/* ============================================================
   3️⃣ UNORDERED_MAP  (Hash Table)
   insert/search/erase: O(1) avg
   worst case: O(n)
   Forward iterator
============================================================ */

    unordered_map<int,int> ump;

    ump[1]++;
    ump[2] = 10;

    for(auto it = ump.begin(); it != ump.end(); it++)
        cout << it->first << " -> " << it->second << endl;


/* ============================================================
   4️⃣ MAP  (Red Black Tree - Sorted)
   insert/search/erase: O(log n)
   Bidirectional iterator
============================================================ */

    map<int,int> mp;
    mp[3] = 30;
    mp[1] = 10;

    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;


/* ============================================================
   5️⃣ SET (Sorted Unique)
   insert/search/erase: O(log n)
============================================================ */

    set<int> s = {5,1,3};

    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;


/* ============================================================
   6️⃣ UNORDERED_SET
   insert/search: O(1) avg
============================================================ */

    unordered_set<int> us = {10,20,10};

    for(auto x : us)
        cout << x << " ";
    cout << endl;


/* ============================================================
   7️⃣ MULTISET (Sorted, Duplicates allowed)
   insert/erase: O(log n)
============================================================ */

    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);

    ms.erase(ms.find(5));   // remove single occurrence

    for(auto x : ms)
        cout << x << " ";
    cout << endl;


/* ============================================================
   8️⃣ STACK  (LIFO)
   push/pop/top: O(1)
   No iterators
============================================================ */

    stack<int> st;
    st.push(1);
    st.push(2);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;


/* ============================================================
   9️⃣ QUEUE  (FIFO)
   push/pop/front: O(1)
   No iterators
============================================================ */

    queue<int> q;
    q.push(10);
    q.push(20);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;


/* ============================================================
   🔟 PRIORITY_QUEUE  (Heap)
   push/pop: O(log n)
   top: O(1)
============================================================ */

    priority_queue<int> pq;    // max heap
    pq.push(3);
    pq.push(10);
    pq.push(1);

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minpq;


/* ============================================================
   1️⃣1️⃣ DEQUE
   push_front/back: O(1)
   pop_front/back: O(1)
   Random access allowed
============================================================ */

    deque<int> dq;
    dq.push_front(5);
    dq.push_back(10);

    for(auto it = dq.begin(); it != dq.end(); it++)
        cout << *it << " ";
    cout << endl;


/* ============================================================
   1️⃣2️⃣ ALGORITHMS (Iterator Based)
============================================================ */

    vector<int> arr = {4,2,1,3};

    sort(arr.begin(), arr.end());        // O(n log n)
    reverse(arr.begin(), arr.end());     // O(n)

    cout << binary_search(arr.begin(), arr.end(), 3) << endl; // O(log n)

    cout << (lower_bound(arr.begin(), arr.end(), 3) - arr.begin()) << endl;

    cout << accumulate(arr.begin(), arr.end(), 0) << endl;


/* ============================================================
   1️⃣3️⃣ STRING
   length: O(1)
   substr: O(k)
   find: O(n)
============================================================ */

    string str = "hello";

    cout << str.length() << endl;
    cout << str.substr(1,3) << endl;
    cout << str.find("ll") << endl;


/* ============================================================
   1️⃣4️⃣ NEXT_PERMUTATION
   Time: O(n)
============================================================ */

    vector<int> perm = {1,2,3};
    next_permutation(perm.begin(), perm.end());

    for(auto x : perm)
        cout << x << " ";
    cout << endl;


/* ============================================================
   ⭐ Iterator Notes

   - begin() -> first element
   - end()   -> after last element
   - rbegin(), rend() -> reverse iteration
   - vector supports it + k
   - set/map DO NOT support it + k
   - erase() invalidates iterator (use returned iterator)

   auto x      -> copy
   auto &x     -> reference (modifies original)
============================================================ */

    return 0;
}
