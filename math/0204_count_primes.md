### [204\. Count Primes](https://leetcode.com/problems/count-primes/)

Difficulty: **Easy**


Count the number of prime numbers less than a non-negative number, **_n_**.

**Example:**

```
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int countPrimes(int n) {
        
        if (n < 3) return 0;
        
        vector<int> primes(n,1);
        primes[0] = primes[1] = 0;
        
        // Sieve of Eratosthenes
        // If x is prime
        //      mark [x^2 : x : n] all non-prime
        
        for (int i = 2; i < sqrt(n); ++i)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j+=i)
                {
                    primes[j] = 0;
                }
            }
        }
        
        return accumulate(primes.begin(),primes.end(),0);
        
    }
};
```
