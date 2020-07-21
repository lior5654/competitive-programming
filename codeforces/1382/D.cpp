//https://codeforces.com/contest/1382/problem/D
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
// typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
// typedef vector<pi> vpi;
typedef vector<pl> vpl;
// typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;

#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm

const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;




const int maxn = 2e3 + 5;
int p[2 * maxn] = { 0 };
int pi[2 * maxn] = { 0 };

void solve();
int main()
{
    GOGOGO
    int t; cin >> t; while(t--) {solve();}
    BYEBYE
}

void solve()
{
    int n; cin >> n;
    repk(i, 1, 2 * n + 1)
    {
        cin >> p[i];
        pi[p[i]] = i;
    }
    vector<bool> vis(2*n+1);
    vector<int> u;
    for(int i = 2 * n; i >= 1; --i)
    {
        if(vis[i]) {continue;}
        else
        {
            vis[i] = true;
            int cnt = 1;
            int next = pi[i]+1;
            while(next <= 2 * n && !vis[p[next]])
            {
                vis[p[next]] = true;
                ++cnt;
                ++next;
            }
            u.push_back(cnt);
        }
        
    }
    // cout << "hi" << endl;
    // knapsack
    vector<vector<bool>> dp(u.size()+1, vector<bool>(2*n + 1, false));
    int un = u.size();
    // cout << un << endl;
    dp[0][0] = true;
    for(int i = 1; i <= un; ++i)
    {
        int cu = u[i-1];
        // cout << cu << " ";
        dp[i][0] = true;
        for(int j = 1; j <= 2 * n; ++j)
        {
            if (j < cu)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                // cout << j << " " << cu << endl;
                dp[i][j] = dp[i-1][j] || dp[i-1][j-cu]; 
            }
        }
    }
    // cout << endl;
    cout << (dp[un][n] ? "YES" : "NO") << endl;
}