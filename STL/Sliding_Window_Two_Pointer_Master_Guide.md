# 🚀 Sliding Window + Two Pointer Master Guide (C++)

Complete reference for: - LeetCode - Competitive Programming - Placement
Interviews

------------------------------------------------------------------------

# 📌 1️⃣ Fixed Size Sliding Window

## 📌 Use When:

-   Subarray of size k
-   Maximum/Minimum sum of size k
-   Average of window

### ⏱ Time Complexity: O(n)

``` cpp
int maxSumSubarray(vector<int>& arr, int k){
    int n = arr.size();
    int windowSum = 0;

    for(int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    for(int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

------------------------------------------------------------------------

# 📌 2️⃣ Variable Size Sliding Window

## 📌 Use When:

-   Longest substring without repeating characters
-   Smallest subarray with sum ≥ target
-   At most K distinct elements

### ⏱ Time Complexity: O(n)

``` cpp
int longestUniqueSubstring(string s){
    unordered_set<char> st;
    int left = 0, maxLen = 0;

    for(int right = 0; right < s.size(); right++){
        while(st.count(s[right])){
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

------------------------------------------------------------------------

# 📌 3️⃣ Sliding Window with Hash Map (Frequency Count)

``` cpp
int longestAtMostKDistinct(vector<int>& nums, int k){
    unordered_map<int,int> freq;
    int left = 0, maxLen = 0;

    for(int right = 0; right < nums.size(); right++){
        freq[nums[right]]++;

        while(freq.size() > k){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

------------------------------------------------------------------------

# 📌 4️⃣ Two Pointer (Sorted Array)

## 📌 Use When:

-   2 Sum in sorted array
-   Remove duplicates
-   3 Sum
-   Container with most water

### ⏱ Time Complexity: O(n)

``` cpp
bool twoSumSorted(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target)
            return true;
        else if(sum < target)
            left++;
        else
            right--;
    }

    return false;
}
```

------------------------------------------------------------------------

# 📌 5️⃣ Remove Duplicates (In-place)

``` cpp
int removeDuplicates(vector<int>& nums){
    int slow = 0;

    for(int fast = 1; fast < nums.size(); fast++){
        if(nums[fast] != nums[slow]){
            slow++;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1;
}
```

------------------------------------------------------------------------

# 📌 6️⃣ 3 Sum Pattern

``` cpp
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1, right = nums.size() - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0){
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
            else if(sum < 0)
                left++;
            else
                right--;
        }
    }

    return result;
}
```

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type                Use
  --------------------------- ---------------------------
  Fixed size window           Sliding Window (fixed)
  Variable window condition   Sliding Window (variable)
  Sorted + pair sum           Two Pointer
  Remove duplicates           Two Pointer
  Substring problems          Sliding Window
  Triplet problems            Sort + Two Pointer

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Forgetting to shrink window in variable window
-   Not handling duplicates in 3 sum
-   Using sliding window when array is unsorted for 2 pointer pattern
-   Off-by-one errors in window size

------------------------------------------------------------------------

🔥 Master these templates and you can solve most medium sliding window &
two pointer problems confidently.
