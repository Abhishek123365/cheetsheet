#include<bits/stdc++.h>
using namespace std;

/* ============================================================
   1️⃣ BASIC CUSTOM SORTING
============================================================ */

int main(){

    vector<int> v = {4,1,3,2};

    // Default sort (Ascending)
    sort(v.begin(), v.end());   // O(n log n)

    // Descending order
    sort(v.begin(), v.end(), greater<int>());

    // Custom comparator using lambda
    sort(v.begin(), v.end(), [](int a, int b){
        return a > b;  // descending
    });



/* ============================================================
   2️⃣ SORTING PAIR
============================================================ */

    vector<pair<int,int>> vp = {{1,5}, {2,3}, {1,2}, {2,1}};

    // Default behavior:
    // First compare first element
    // If equal, compare second element
    sort(vp.begin(), vp.end());

    // Custom: sort by second value only
    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    // Custom: first ascending, second descending
    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });



/* ============================================================
   3️⃣ CUSTOM COMPARATOR FUNCTION (Outside Lambda)
============================================================ */

    // Comparator must return true if a should come before b

    auto comp = [](int a, int b){
        return abs(a) < abs(b);   // sort by absolute value
    };

    sort(v.begin(), v.end(), comp);



/* ============================================================
   4️⃣ MIN HEAP / MAX HEAP
============================================================ */

    // Max Heap (Default)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);



/* ============================================================
   5️⃣ PRIORITY QUEUE OF PAIRS
============================================================ */

    // Default: max heap based on FIRST value
    priority_queue<pair<int,int>> pq1;

    pq1.push({10,1});
    pq1.push({5,2});

    // Min heap based on FIRST
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq2;



/* ============================================================
   6️⃣ CUSTOM HEAP (Sort by SECOND value)
============================================================ */

    auto comp2 = [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;  
        // min heap based on second
    };

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   decltype(comp2)> pq3(comp2);

    pq3.push({1,5});
    pq3.push({2,3});
    pq3.push({3,1});



/* ============================================================
   7️⃣ SORTING STRUCT
============================================================ */

    struct Node{
        int x, y;
    };

    vector<Node> nodes = {{1,5}, {2,3}, {1,2}};

    sort(nodes.begin(), nodes.end(), [](Node a, Node b){
        if(a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    });



/* ============================================================
   8️⃣ nth_element (Find kth smallest in O(n))
============================================================ */

    vector<int> arr = {7,4,6,3,9,1};

    nth_element(arr.begin(), arr.begin()+2, arr.end());
    // Now arr[2] is the 3rd smallest element



/* ============================================================
   ⭐ IMPORTANT RULES

   🔹 Comparator must return TRUE if:
      "a should come before b"

   🔹 For sorting:
      sort(begin, end, comparator);

   🔹 For priority_queue:
      comparator works opposite logic (careful!)

   🔹 Default pair sorting:
      first → then second

============================================================ */

    return 0;
}
