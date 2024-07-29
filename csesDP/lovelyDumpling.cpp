#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
const int mod = 1e9 + 7;
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;

class comparator
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};
void helper(vector<int> &arr, int n, int t, int s, set<vector<int>> &ans, vector<int> &temp, int index)
{
    if (index == n)
    {
        int res = accumulate(temp.begin(), temp.end(), 0);
        if (res == t && temp.size() == s)
        {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
        }
        return;
    }
    temp.push_back(arr[index]);
    helper(arr, n, t, s, ans, temp, index + 1);
    temp.pop_back();
    helper(arr, n, t, s, ans, temp, index + 1);
}

vector<vector<int>> solve(vector<int> &arr, int n, int t, int s)
{
    set<vector<int>> ans;
    vector<int> temp;
    helper(arr, n, t, s, ans, temp, 0);
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    int target;
    cin >> target;
    int size;
    cin >> size;
    auto p = solve(arr, n, target, size);
    for (auto it : p)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// T.C
// 6 -
// 1 0 1 2 - 1 - 4      ANS : [-1 -1 2] [-1 0 1]
//  0
// 3

// T.C
// 6
// 3 0 1 2 3 -1         ANS : [-1 0 3] [-1 1 2]
// 2
// 3
