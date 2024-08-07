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

int solve(int n){

    if(n >= 0 && n <= 9){
        return 1;
    }

    string s = to_string(n);
    int ans = 1e7;
    for(int i = 0 ; i < s.size() ; i++){
        int t = s[i] - 48;
        cout << t << endl;
        ans = min(ans , solve(n - t) + 1);
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    cout<<solve(n);
    return 0;
}