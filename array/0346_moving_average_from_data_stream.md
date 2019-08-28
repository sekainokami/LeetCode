### [346\. Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/)

Difficulty: **Easy**


Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

**Example:**

```
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
```


#### Solution

Language: **C++**

```c++
class MovingAverage {
private:
    deque<int> data;
    int sz;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):sz(size) {
    }
    
    double next(int val) {
        if (data.size() == sz)
        {
            data.pop_front();
        }
        data.push_back(val);
        return accumulate(data.begin(),data.end(),0.0) / data.size();
        
    }
};
​
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
