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

int get_ith_bit(int n, int index)
{
    //      210
    // 7 -> 111

    int bitMask = (1 << index);
    if ((n & bitMask) > 0)
    {
        return 1;
    }
    else if ((n & bitMask) == 0)
    {
        return 0;
    }
}

int set_ith_bit(int &n, int index)
{
    int bitMask = (1 << index);
    n = (n | bitMask);
    return n;
}

int clear_ith_bit(int n, int index)
{
    int bitMask = (1 << index);
    return n = n & ~(bitMask);
}

int update_ith_bit(int &n, int index, int v)
{
    // v can be 0 or 1;

    n = clear_ith_bit(n, index);
    int bitMask = (v << index);
    n = n | bitMask;
    return n;
}

int clear_the_last_ith_bit(int &n, int index)
{
    int mask = (~0) << index + 1;
    return (n & mask);
}

int claerTheRangeOfBits(int &n, int index1, int index2)
{
    int mask1 = clear_the_last_ith_bit(n, index2);
    // cout << mask1 << endl;
    int mask2 = (1 << index1) - 1;
    // cout << mask2 << endl;
    int ans = (mask1 | mask2);
    return ans;
}

// Q. u r given n = 10000000000 and m = 10101 then i = 2 , j = 6;
// u r task is to merge m to n from range 2 and 6

int Q1Solve(int &n, int m, int i, int j)
{
    n = claerTheRangeOfBits(n, i, j);
    // cout << n << endl;
    int mask = (m << i);
    // cout << mask << endl;
    return (n | mask);
}

// INPUT :
// 15
// 2
// 1
// 3

// OUTPUT :
// 5

// Finding the no of set bit

// 13 -> 1101 -> 3 set bits Are there

int countSetBits(int n)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int last_bit = n & (1 << i);
        if (last_bit > 0)
        {
            ans++;
        }
        else
        {
            continue;
        }
    }
    return ans;
}

int M2countSetBits(int n)
{
    int ans = 0;
    while (n > 0)
    { // it is much faster then the first method
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int M3countSetBits(int n)
{
    return __builtin_popcount(n);
}
//--------------------------------------------------------------------
// decimal to binary

int decimal_to_binary(int n)
{
    int ans = 0;
    int p = 1;

    while (n > 0)
    {
        int last_bit = (n & 1);
        ans += last_bit * p;
        n = n >> 1;
        p *= 10;
    }
    return ans;
}
// 13 -> 1101

int fastExponentiation()
{
}

int32_t main()
{
    cout << decimal_to_binary(13) << endl;
    return 0;
}