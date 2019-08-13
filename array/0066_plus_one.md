### [66\. Plus One](https://leetcode.com/problems/plus-one/)

Difficulty: **Easy**


Given a **non-empty** array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```

**Example 2:**

```
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // increment the last element
        digits.back()++;
        // if the element is greater than 10, need to do some further work
        if (digits.back() < 10)
            return digits;
        // get the carry
        int carry = digits.back() / 10;
        // update the last elment
        digits.back() %= 10;
        // index of the current element under consideration
        int curr = digits.size()-2;
        // as long as there is a carry AND we still have not reached the beginning of the array
        while (carry && curr >= 0)
        {
            int s = digits[curr] + carry;
            carry = s / 10;
            digits[curr] = s % 10;
            curr --;
        }
        // insert the leftover carry to the beginning of the array
        if (carry)
            digits.insert(digits.begin(),carry);
        return digits;
    }
};
```
