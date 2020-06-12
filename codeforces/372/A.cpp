//https://codeforces.com/contest/372/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 5e5;
const int SI = 1e5;
ll n;
ll s[N+1];
ll out = 0;
bitset<N+1> vis = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    sort(s, s + n);

    int h = n/2;
    int l = 0;
    out = 0;
    while (h < n && l < n/2)
    {
        if (!vis[l])
        {
            while (h < n && 2 * s[l] > s[h] ) ++h;
            if (h == n) break;

            // cout << l << " " << h << endl;
            out += 1;
            vis[h] = true;
            ++h;
        }
            // cout << out << endl;

        ++l;
    }

    cout << n - out  << endl;
    return 0;
}