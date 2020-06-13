//https://codeforces.com/contest/1196/problem/D2
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
const int AC = 3;
const int INF = 1e9 + 5;
int dp[AC][maxn+1] = { { 0 } };

void solve();
bool good(int c, char tt);

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--)
        solve();
}

bool good(int c, char tt)
{
    switch(tt)
    {
    case 'R':
        return c == 0;
    case 'G':
        return c == 1;
    case 'B':
        return c == 2;
    default:
        return false;
    }
}
void solve()
{
    // 0 - R, 1 - G, 2 - B
    // c - k % 3 
    int n, k; cin >> n >> k; string s; cin >> s;
    int minres = INF;
    for(int i = 0; i < k - 1; ++i)
    {
        dp[0][i] = 0;
        dp[1][i] = 0;
        dp[2][i] = 0;
    }
    int cnt = 0;
    int curr;
    for(int c = 0; c <= 2; ++c)
    {
        cnt = 0;
        curr = c;
        // I want dp[c][k-1], rest is trivial
        for(int i = k - 1; i >= 0; --i)
        {
            if (!good(curr,s[i]))
            {
                cnt++;
            }
            --curr;
            if (curr == -1) curr = 2;
        }
        dp[c][k-1] = cnt;
        minres = min(dp[c][k-1], minres);
    }
    for(int i = k; i < n; ++i)
    {
        dp[0][i] = dp[2][i-1] + ((good(0, s[i])) ? 0 : 1);
        if (!good((2 * k) % 3,s[i-k])) --dp[0][i];
        minres = min(minres, dp[0][i]);
        for(int c  = 1; c <= 2; ++c)
        {
            dp[c][i] = dp[c-1][i-1] + ((good(c, s[i])) ? 0 : 1);
            if (!good((2 * k + c) % 3,s[i-k])) --dp[c][i];
            minres = min(minres, dp[c][i]);
        }
    }
    cout << minres << endl;
}