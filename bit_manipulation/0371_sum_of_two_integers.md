### [371\. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)

Difficulty: **Easy**


Calculate the sum of two integers _a_ and _b_, but you are **not allowed** to use the operator `+` and `-`.


**Example 1:**

```
Input: a = 1, b = 2
Output: 3
```


**Example 2:**

```
Input: a = -2, b = 3
Output: 1
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int getSum(int a, int b) {
     /*
     我们在做加法运算的时候，每位相加之后可能会有进位 Carry 产生，然后在下一位计算时需要加上进位一起运算，那么我们能不能将两部分拆开呢，我们来看一个例子 759+674

     1. 如果我们不考虑进位，可以得到 323

     2. 如果我们只考虑进位，可以得到 1110

     3. 我们把上面两个数字假期 323+1110=1433 就是最终结果了

     然后我们进一步分析，如果得到上面的第一第二种情况，我们在二进制下来看，
     不考虑进位的加，0+0=0，0+1=1, 1+0=1，1+1=0，这就是异或的运算规则，
     如果只考虑进位的加 0+0=0, 0+1=0, 1+0=0, 1+1=1，而这其实这就是'与'的运算，
     而第三步在将两者相加时，我们再递归调用这个算法，终止条件是当进位为0时，


     class Solution {
        public:
            int getSum(int a, int b) {
                if (b == 0) return a;
                int sum = a ^ b;
                int carry = (a & b & 0x7fffffff) << 1;
                return getSum(sum, carry);
            }
        };

    0x7fffffff 是一个首位为0，之后都为1的数
     */


        if (b == 0) return a;
        int sum = a ^ b;
        //Carry has to be casted to the uint
        unsigned carry = (a & b);
        carry <<= 1;
        return getSum(sum,carry);
    }
};
```
