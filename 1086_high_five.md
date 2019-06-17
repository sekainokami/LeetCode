### [1086\. High Five](https://leetcode.com/problems/high-five/)

Difficulty: **Easy**


Given a list of scores of different students, return the average score of each student's **top five scores** in **the order of each student's id**.

Each entry `items[i]` has `items[i][0]` the student's id, and `items[i][1]` the student's score.  The average score is calculated using integer division.

**Example 1:**

```
Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation:
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6\. But with integer division their average converts to 88.
```

**Note:**

1.  `1 <= items.length <= 1000`
2.  `items[i].length == 2`
3.  The IDs of the students is between `1` to `1000`
4.  The score of the students is between `1` to `100`
5.  For each student, there are at least 5 scores


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int,vector<int>> hash;
        for (auto & item : items)
        {
            hash[item[0]].push_back(item[1]);
        }
        
        
        vector<vector<int>> res;
        for (auto & p : hash)
        {
            int avg = 0;
            sort(p.second.begin(),p.second.end(),[](int a, int b){return a > b;});
            for (int i = 0; i < 5; ++i)
                avg += p.second[i];
            avg /= 5;
            res.push_back({p.first,avg});
        }
        
        sort(res.begin(),res.end(),[](vector<int> a, vector<int> b){return a[0] < b[0];});
        return res;
    }
};
```
