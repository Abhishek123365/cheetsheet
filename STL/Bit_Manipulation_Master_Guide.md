# 🚀 Bit Manipulation Master Guide (C++)

Complete reference for: - LeetCode - Competitive Programming - Placement
Interviews

------------------------------------------------------------------------

# 📌 1️⃣ Why Bit Manipulation?

Used when: - Working with subsets - Optimizing space - Checking parity
(odd/even) - Power of 2 checks - XOR tricks - Masking problems

Bit operations are extremely fast → O(1)

------------------------------------------------------------------------

# 📌 2️⃣ Basic Bit Operators

  Operator   Meaning
  ---------- -------------
  &          AND
             
  \^         XOR
  \~         NOT
  \<\<       Left shift
  \>\>       Right shift

------------------------------------------------------------------------

# 📌 3️⃣ Common Bit Tricks

## 🔹 Check if number is odd or even

``` cpp
if(n & 1) cout << "Odd";
else cout << "Even";
```

------------------------------------------------------------------------

## 🔹 Check if power of 2

``` cpp
bool isPowerOfTwo(int n){
    return n > 0 && (n & (n - 1)) == 0;
}
```

------------------------------------------------------------------------

## 🔹 Count set bits

``` cpp
int countSetBits(int n){
    return __builtin_popcount(n);
}
```

For long long:

``` cpp
__builtin_popcountll(n);
```

------------------------------------------------------------------------

## 🔹 Remove lowest set bit

``` cpp
n = n & (n - 1);
```

------------------------------------------------------------------------

## 🔹 Get lowest set bit

``` cpp
int lowestBit = n & (-n);
```

------------------------------------------------------------------------

# 📌 4️⃣ Set, Clear, Toggle, Check Bit

Assume we want to manipulate ith bit (0-based)

## 🔹 Set ith bit

``` cpp
n = n | (1 << i);
```

## 🔹 Clear ith bit

``` cpp
n = n & ~(1 << i);
```

## 🔹 Toggle ith bit

``` cpp
n = n ^ (1 << i);
```

## 🔹 Check ith bit

``` cpp
bool isSet = (n & (1 << i)) != 0;
```

------------------------------------------------------------------------

# 📌 5️⃣ XOR Tricks

## 🔹 Swap two numbers

``` cpp
a ^= b;
b ^= a;
a ^= b;
```

------------------------------------------------------------------------

## 🔹 Find single number (others appear twice)

``` cpp
int singleNumber(vector<int>& nums){
    int result = 0;
    for(int num : nums)
        result ^= num;
    return result;
}
```

------------------------------------------------------------------------

## 🔹 Find two unique numbers

``` cpp
vector<int> singleNumber(vector<int>& nums){
    int xorAll = 0;
    for(int num : nums)
        xorAll ^= num;

    int diffBit = xorAll & (-xorAll);

    int a = 0, b = 0;
    for(int num : nums){
        if(num & diffBit)
            a ^= num;
        else
            b ^= num;
    }

    return {a, b};
}
```

------------------------------------------------------------------------

# 📌 6️⃣ Subset Generation using Bitmask

## Generate all subsets

``` cpp
vector<vector<int>> subsets(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> result;

    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> subset;

        for(int i = 0; i < n; i++){
            if(mask & (1 << i))
                subset.push_back(nums[i]);
        }

        result.push_back(subset);
    }

    return result;
}
```

Time: O(n \* 2\^n)

------------------------------------------------------------------------

# 📌 7️⃣ Bitmask DP Concept

Used when: - n ≤ 20 - State compression required

State:

    dp[mask]

Example: - Traveling Salesman Problem (TSP) - Assignment problems

------------------------------------------------------------------------

# 📌 8️⃣ Fast Exponentiation (Binary Exponentiation)

``` cpp
long long power(long long a, long long b){
    long long result = 1;

    while(b > 0){
        if(b & 1)
            result *= a;

        a *= a;
        b >>= 1;
    }

    return result;
}
```

Time: O(log b)

------------------------------------------------------------------------

# 📌 9️⃣ Important Built-in Functions

  Function               Purpose
  ---------------------- ----------------------
  \_\_builtin_popcount   Count set bits
  \_\_builtin_clz        Count leading zeros
  \_\_builtin_ctz        Count trailing zeros

------------------------------------------------------------------------

# 🧠 Pattern Recognition Guide

  Problem Type      Trick
  ----------------- -----------------------
  Power of 2        n & (n-1)
  Count bits        popcount
  Unique element    XOR
  Subset problems   Bitmask
  Fast power        Binary exponentiation
  Toggle flags      XOR

------------------------------------------------------------------------

# 🎯 Common Mistakes

-   Forgetting parentheses in shifts
-   Using int instead of long long
-   Overflow in shifts (1 \<\< 31)
-   Confusing signed and unsigned shifts

------------------------------------------------------------------------

🔥 Master bit manipulation and you unlock many advanced optimization
tricks.
