//https://codeforces.com/contest/1238/problem/B
#include <bits/stdc++.h>

using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

void solve()
{
    int q; cin >> q;
    set<int> x;
    int xi;
    int fac = 0;
    int out = 0;
    for(int i = 0; i < q; ++i)
    {
        int n, r; cin >> n >> r;
        for(int i = 0; i < n; ++i)
        {
            cin >> xi;
            x.insert(-1 * xi);
        }
        fac = 0;
        out = 0;
        while (!x.empty())
        {   
            set<int>::const_iterator itc = x.begin();
            int c = -1 * (*itc);
            x.erase(itc);
            if (c - fac * r > 0)
            {
                out++; ++fac;
            }
            

        }
        cout << out << endl;

    }
}