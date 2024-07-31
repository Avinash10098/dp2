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

int helper(vector<int>&arr , int n , int i , int prev){
    if(i == n)
        return 0;
    int notTake = helper(arr, n, i + 1, prev);
    int take = INT_MIN;
    if(prev < arr[i]){
        take = 1+helper(arr, n, i + 1, arr[i]);
    }
    return max(notTake, take);
}

int solve(vector<int>&arr , int n){
    return helper(arr, n, 0, 0);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    cout<<solve(arr, n);
}