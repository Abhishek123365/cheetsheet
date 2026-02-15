#include<bits/stdc++.h>
using namespace std;

int main(){

    /* ============================================================
       1. VECTOR  (Dynamic Array)
       Access: O(1)
       push_back: O(1) amortized
       pop_back: O(1)
       insert (middle): O(n)
       erase (middle): O(n)
    ============================================================ */

    vector<int> v;

    v.push_back(10);      // O(1)
    v.push_back(20);
    v.pop_back();         // O(1)

    cout << v.size() << endl;      // O(1)
    cout << v.empty() << endl;     // O(1)

    // Iteration O(n)
    for(int x : v) cout << x << " ";
    cout << endl;



    /* ============================================================
       2. PAIR
       All operations: O(1)
    ============================================================ */

    pair<int,int> p = {1,2};
    cout << p.first << " " << p.second << endl;



    /* ============================================================
       3. UNORDERED_MAP  (Hash Table)
       insert: O(1) average
       access: O(1) average
       erase: O(1) average
       Worst case: O(n)
    ============================================================ */

    unordered_map<int,int> ump;

    ump[5]++;        // O(1) avg
    ump[10] = 100;

    // Iteration O(n)
    for(auto x : ump)
        cout << x.first << " -> " << x.second << endl;



    /* ============================================================
       4. MAP  (Red-Black Tree)
       insert: O(log n)
       access: O(log n)
       erase: O(log n)
       Always sorted
    ============================================================ */

    map<int,int> mp;

    mp[3] = 30;      // O(log n)
    mp[1] = 10;

    for(auto x : mp)   // O(n)
        cout << x.first << " -> " << x.second << endl;



    /* ============================================================
       5. UNORDERED_SET
       insert: O(1) avg
       search: O(1) avg
       erase: O(1) avg
       Worst: O(n)
    ============================================================ */

    unordered_set<int> us;

    us.insert(10);
    cout << us.count(10) << endl;  // O(1)

    for(auto x : us) cout << x << " ";
    cout << endl;



    /* ============================================================
       6. SET (Ordered)
       insert: O(log n)
       search: O(log n)
       erase: O(log n)
    ============================================================ */

    set<int> s;

    s.insert(30);
    s.insert(10);

    for(auto x : s) cout << x << " ";
    cout << endl;



    /* ============================================================
       7. MULTISET
       Same as set but allows duplicates
       All operations: O(log n)
    ============================================================ */

    multiset<int> ms;

    ms.insert(5);
    ms.insert(5);

    ms.erase(ms.find(5));  // O(log n)

    for(auto x : ms) cout << x << " ";
    cout << endl;



    /* ============================================================
       8. STACK (LIFO)
       push: O(1)
       pop: O(1)
       top: O(1)
       Iteration: Not directly allowed
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
       9. QUEUE (FIFO)
       push: O(1)
       pop: O(1)
       front: O(1)
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
       10. PRIORITY_QUEUE (Heap)
       push: O(log n)
       pop: O(log n)
       top: O(1)
    ============================================================ */

    priority_queue<int> pq;  // max heap

    pq.push(5);
    pq.push(10);
    pq.push(1);

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;



    /* ============================================================
       11. DEQUE
       push_front/back: O(1)
       pop_front/back: O(1)
       random access: O(1)
    ============================================================ */

    deque<int> dq;

    dq.push_front(5);
    dq.push_back(10);

    for(auto x : dq) cout << x << " ";
    cout << endl;



    /* ============================================================
       12. ALGORITHMS
    ============================================================ */

    vector<int> arr = {4,1,3,2};

    sort(arr.begin(), arr.end());        // O(n log n)
    reverse(arr.begin(), arr.end());     // O(n)

    binary_search(arr.begin(), arr.end(), 3);   // O(log n)
    lower_bound(arr.begin(), arr.end(), 3);     // O(log n)
    upper_bound(arr.begin(), arr.end(), 3);     // O(log n)

    accumulate(arr.begin(), arr.end(), 0);      // O(n)



    /* ============================================================
       13. STRING
       length: O(1)
       substr: O(k)
       find: O(n)
    ============================================================ */

    string str = "hello";

    cout << str.length() << endl;
    cout << str.substr(1,3) << endl;
    cout << str.find("ll") << endl;



    /* ============================================================
       14. NEXT_PERMUTATION
       Time: O(n)
    ============================================================ */

    vector<int> perm = {1,2,3};

    next_permutation(perm.begin(), perm.end());

    for(int x : perm) cout << x << " ";
    cout << endl;

    return 0;
}
