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

int solve(int n, int m, vector<int> &arr1, vector<int>&arr2 , int k){
    sort(all(arr1));
    sort(all(arr2));
    int cnt = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
       if(abs(arr1[i] - arr2[j]) <= k){
           cnt++;
           i++;
           j++;
       }else if(arr1[i] < arr2[j]){
           i++;
       }else{
           j++;
       }
    }
    return cnt;
}

    int32_t main()
{
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> appS(n), Sapp(m);
    for (int i = 0; i < n; i++){
        cin >> appS[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Sapp[i];
    }
    cout<<solve(n, m, appS, Sapp , k);
    return 0;
}