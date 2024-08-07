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

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr)
        cin >> it;

    int xr = arr[0];
    for (int i = 1; i < n; i++){
        xr = xr^arr[i];
    }
    cout << xr << endl;
    return 0;
}