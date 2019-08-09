### [412\. Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)

Difficulty: **Easy**


Write a program that outputs the string representation of numbers from 1 to _n_.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

**Example:**

```
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; ++i)
        {
            string curr;
            if ((i+1) % 3 == 0 && (i+1) % 5 != 0)
                curr = "Fizz";
            else if ((i+1) % 3 != 0 && (i+1) % 5 == 0)
                curr = "Buzz";
            else if ((i+1) % 3 == 0 && (i+1) % 5 == 0)
                curr = "FizzBuzz";
            else
                curr = to_string(i+1);
            res[i] = curr;
        }
        
        return res;
    }
};
```
