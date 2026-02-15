# 🚀 Binary Search Master Template Guide (C++)

Complete reference for: - LeetCode - Competitive Programming - Placement
Interviews

------------------------------------------------------------------------

# 📌 1️⃣ Basic Binary Search (Exact Match)

### 📌 Use When:

-   Array is sorted
-   Need to find exact element

### ⏱ Time Complexity: O(log n)

``` cpp
int binarySearch(vector<int>& arr, int target){
    int low = 0, high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
```

------------------------------------------------------------------------

# 📌 2️⃣ Lower Bound Template (First \>= target)

### 📌 Use When:

-   Find first occurrence
-   First element ≥ target

``` cpp
int lowerBound(vector<int>& arr, int target){
    int low = 0, high = arr.size();

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
```

Equivalent STL:

``` cpp
lower_bound(arr.begin(), arr.end(), target);
```

------------------------------------------------------------------------

# 📌 3️⃣ Upper Bound Template (First \> target)

``` cpp
int upperBound(vector<int>& arr, int target){
    int low = 0, high = arr.size();

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
```

Equivalent STL:

``` cpp
upper_bound(arr.begin(), arr.end(), target);
```

------------------------------------------------------------------------

# 📌 4️⃣ First True Pattern (Binary Search on Answer)

### 📌 Use When:

-   Search space is answer range
-   Minimize something
-   Capacity / allocation problems

``` cpp
bool check(int mid){
    // return true if mid is valid
}

int binarySearchAnswer(int low, int high){
    while(low < high){
        int mid = low + (high - low) / 2;

        if(check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
```

------------------------------------------------------------------------

# 📌 5️⃣ Last True Pattern

``` cpp
int binarySearchLastTrue(int low, int high){
    while(low < high){
        int mid = low + (high - low + 1) / 2;

        if(check(mid))
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}
```

------------------------------------------------------------------------

# 📌 6️⃣ Binary Search in Rotated Sorted Array

``` cpp
int search(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
```

------------------------------------------------------------------------

# 📌 7️⃣ Floating Point Binary Search

### 📌 Use When:

-   Precision based problems

``` cpp
double binarySearchDouble(double low, double high){
    for(int i = 0; i < 100; i++){ // 100 iterations for precision
        double mid = (low + high) / 2.0;

        if(check(mid))
            high = mid;
        else
            low = mid;
    }
    return low;
}
```

------------------------------------------------------------------------

# 🧠 Binary Search Decision Guide

  Problem Type         Use
  -------------------- ------------------------
  Find exact element   Basic Binary Search
  First ≥ target       Lower Bound
  First \> target      Upper Bound
  Minimize answer      First True
  Maximize answer      Last True
  Rotated array        Modified Binary Search
  Precision required   Floating Point BS

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Infinite loop → wrong mid calculation
-   Overflow → use `low + (high - low) / 2`
-   Wrong condition in answer search
-   Forgetting sorted requirement

------------------------------------------------------------------------

🔥 Master these templates and you can solve 95% of binary search
problems confidently.
