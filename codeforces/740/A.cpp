//https://codeforces.com/contest/740/problem/A
#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, a, b, c; cin >> n >> a >> b >> c;
    if (!(n % 4))
    {
        cout << 0 << endl;
    }
    else if (n % 4 == 1)
    {
        cout << min({3*a, c, b + a}) << endl;
    }
    else if (n % 4 == 2)
    {
        cout << min({2*a, b, 2 * c});
    }
    else
    {
        cout << min({a, b + c, 3 * c});
    }
    return 0;

}
