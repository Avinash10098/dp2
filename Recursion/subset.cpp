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

void helper(vector<int>&arr, int n , vector<vector<int>>&ans , vector<int>&temp , int index){
    if(index >= n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[index]);
    helper(arr, n, ans, temp, index + 1);
    temp.pop_back();
    helper(arr, n, ans, temp, index + 1);
}

vector<vector<int>>subset(vector<int>&arr, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(arr, n, ans, temp, 0);
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    auto p = subset(arr, n);
    for(auto it : p){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
}