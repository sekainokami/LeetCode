#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_target(vector<int>& v, int target)
{
    int l = 0, u = v.size()-1;
    // Note the equal sign below
    while (l <= u)
    {
        int m = l + (u - l) / 2;
        if (v[m] == target)
            return m;
        // target is on the right half
        else if (v[m] < target)
            l = m + 1;
        // taget is on the left half
        else
            u = m - 1;
    }
    return -1;
}

int main()
{
    vector<int> v = {246,320,203,688,124,246,789,372,532};
    sort(v.begin(),v.end());
    int p = find_target(v,532);

    cout << "532 is at: " << endl;
    for (auto & x : v)
        cout << x << " ";
    cout << endl;
    while (p--)
    {
        cout << "    ";
    }
    cout << " ^" << endl;
    return 0;
}
