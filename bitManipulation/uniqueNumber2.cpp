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

// Q. u r given a array [1,2,1,3,2,4]
// u r task is to find the unique number which is in above case is 3 & 4

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }

    int xr = arr[0];
    for (int i = 1; i < n; i++)
    {
        xr = xr ^ arr[i];
    }
    // cout << xr << endl;
    if (n == 2 && xr != 0)
    {
        return arr;
    }

    int temp = xr;
    int pos = 0;
    while ((temp & 1) == 0)
    {
        pos++;
        temp = temp >> 1;
    }
    // cout << pos << endl;
    int ans = 0;

    int mask = (1 << pos);
    for (auto it : arr)
    {
        if ((it & mask) > 0)
        {
            ans = ans ^ it;
        }
    }

    // cout << ans << endl;
    int b = xr ^ ans;
    cout << min(b, ans) << " " << max(ans, b) << endl;

    return 0;
}