// We have the following two conditions given to us.

// S1 + S2 = D   – (i)

// S1 >= S2     – (ii)

//  If we calculate the total sum of elements of the array (say totSum), we can say that,

// S1 = totSum - S2      – (iii)

// Now solving for equations (i) and (iii), we can say that

// S2 = (totSum - D)/2    – (iv)

// Therefore the question “Count Partitions with a difference D” is modified to “Count Number of subsets with sum (totSum - D)/2 ”. This is exactly what we had discussed in the article  Count Subsets with Sum K.

// Edge Cases:

// The following edge cases need to be handled:

// As the array elements are positive integers including zero, we don’t want to find the case when S2 is negative or we can say that totSum is lesser than D, therefore if totSum<D, we simply return 0.
// S2 can’t be a fraction, as all elements are integers, therefore if totSum - D is odd, we can return 0.
// From here on we will discuss the approach to “Count Subsets with Sum K” with the required modifications. Moreover, as the array elements can also contain 0, we will handle it as discussed in part-1 of this article.

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

int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp, int index)
{
    if (sum < 0)
        return 0;
    if (index == n)
    {
        if (sum == 0)
            return 1;
        return 0;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];

    int ans = solve(arr, n, sum - arr[index], dp, index + 1);
    ans += solve(arr, n, sum, dp, index + 1);
    dp[index][sum] = ans % mod;
    return dp[index][sum];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // s1 + s2 = d; -- 1
    // s1 >= s1; ---- 2
    // s1 + s2 = totalSum;(given);
    // s1 = totalSum - s2; ----------- 3
    // ---------solving 1 & 3;
    // s2 = (totalSum - d ) / 2;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int s2 = (totalSum - d) / 2;

    if ((totalSum - d) & 1)
        return 0;
    if (totalSum - d < 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return solve(arr, n, s2, dp, 0);
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
    int d;
    cin >> d;
    cout << countPartitions(n, d, arr);
    return 0;
}