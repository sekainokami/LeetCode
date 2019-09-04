### [599\. Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

Difficulty: **Easy**


Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their **common interest** with the **least list index sum**. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

**Example 1:**

```
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
```

**Example 2:**

```
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
```

**Note:**

1.  The length of both lists will be in the range of [1, 1000].
2.  The length of strings in both lists will be in the range of [1, 30].
3.  The index is starting from 0 to the list length minus 1.
4.  No duplicates in both lists.


#### Solution

Language: **C++**

```c++
typedef pair<int,int> pii;
​
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,pii> counter;
        for (int i = 0; i < list1.size(); ++i)
        {
            counter[list1[i]] = make_pair(1,i);
        }
        
        for (int j = 0; j < list2.size(); ++j)
        {
            if (counter.count(list2[j]))
                counter[list2[j]] = make_pair(2,counter[list2[j]].second+j);
        }
        
        int min_sum = INT_MAX;
        for (auto & p : counter)
        {
            if (p.second.first == 2)
                min_sum = min(min_sum,p.second.second);
        }
        
        for (auto & p : counter)
        {
            if (p.second.first == 2 && p.second.second == min_sum)
                res.push_back(p.first);
        }
        
        return res;
    }
};
```
