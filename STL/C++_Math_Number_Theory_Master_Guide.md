# 🚀 C++ Math & Number Theory Master Guide (LeetCode + CP)

Complete reference for: - LeetCode Interviews - Competitive
Programming - Placement Preparation

------------------------------------------------------------------------

# 📌 1️⃣ Basic Math Functions (`<cmath>`)

Include:

``` cpp
#include <cmath>
```

  Function   Purpose
  ---------- -----------------------
  abs(x)     Absolute value
  sqrt(x)    Square root
  cbrt(x)    Cube root
  pow(a,b)   a\^b (returns double)
  ceil(x)    Round up
  floor(x)   Round down
  round(x)   Nearest integer
  log(x)     Natural log
  log10(x)   Base 10 log
  exp(x)     e\^x

⚠️ Avoid using `pow()` for integers in CP --- use binary exponentiation
instead.

------------------------------------------------------------------------

# 📌 2️⃣ GCD & LCM

``` cpp
#include <algorithm>
int g = __gcd(a, b);  // O(log min(a,b))
int lcm = (a / __gcd(a,b)) * b;
```

C++17:

``` cpp
#include <numeric>
lcm(a,b);
```

------------------------------------------------------------------------

# 📌 3️⃣ Fast Power (Binary Exponentiation)

Time: O(log n)

``` cpp
long long power(long long a, long long b){
    long long result = 1;
    while(b > 0){
        if(b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}
```

------------------------------------------------------------------------

# 📌 4️⃣ Modular Exponentiation

``` cpp
const int MOD = 1e9+7;

long long modPower(long long a, long long b){
    long long result = 1;
    a %= MOD;

    while(b > 0){
        if(b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}
```

------------------------------------------------------------------------

# 📌 5️⃣ Modular Inverse (Fermat's Theorem)

If MOD is prime:

``` cpp
long long modInverse(long long a){
    return modPower(a, MOD-2);
}
```

------------------------------------------------------------------------

# 📌 6️⃣ nCr (Combination)

Precompute factorials:

``` cpp
const int N = 1e5+5;
long long fact[N], invFact[N];

void precompute(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % MOD;

    invFact[N-1] = modInverse(fact[N-1]);
    for(int i = N-2; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}

long long nCr(int n, int r){
    if(r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}
```

------------------------------------------------------------------------

# 📌 7️⃣ Prime Checking

``` cpp
bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}
```

Time: O(√n)

------------------------------------------------------------------------

# 📌 8️⃣ Sieve of Eratosthenes

``` cpp
vector<bool> sieve(int n){
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}
```

Time: O(n log log n)

------------------------------------------------------------------------

# 📌 9️⃣ Prefix Sum

``` cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for(int i = 1; i < n; i++)
    prefix[i] = prefix[i-1] + arr[i];
```

Range sum:

    sum(l,r) = prefix[r] - prefix[l-1]

------------------------------------------------------------------------

# 📌 🔟 Bit Built-ins

  Function                    Purpose
  --------------------------- ----------------------------
  \_\_builtin_popcount(n)     Count set bits
  \_\_builtin_popcountll(n)   Count set bits (long long)
  \_\_builtin_clz(n)          Count leading zeros
  \_\_builtin_ctz(n)          Count trailing zeros

------------------------------------------------------------------------

# 📌 1️⃣1️⃣ Useful Limits

``` cpp
#include <climits>

INT_MAX
INT_MIN
LLONG_MAX
LLONG_MIN
```

------------------------------------------------------------------------

# 🧠 Must Know for CP

  Category     Important
  ------------ -----------------------
  GCD          \_\_gcd
  Power        Binary exponentiation
  Modulo       1e9+7
  nCr          factorial + inverse
  Prime        sieve
  Bit count    popcount
  Prefix sum   running sum

------------------------------------------------------------------------

🔥 Master these math tools and you unlock many CP & interview problems.
