//https://codeforces.com/contest/986/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
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



const int maxn = 1e5;
const int m = 1e5;
const int maxk = 100;
// connected grpah
// k tpes of foods


int a[maxn+1];
vector<int> g[maxn+1];
vector<int> ksrc[maxk+1];
int dp[maxn+1][maxk+1] = { 0 }; //dp[j][i] - min price to bring ith type to jth town 
int main()
{
    GOGOGO
    int n, m, k, s; cin >> n >> m >> k >> s;
    for(int i = 0; i <= n; ++i) { for(int j = 0; j <= k; ++j) { dp[i][j] = -1;}}
    rep(i, n) { cin >> a[i+1]; ksrc[a[i+1]].pb(i+1);}
    int sr, ds;
    rep(i, m)
    {
        cin >> sr >> ds;
        g[sr].pb(ds);
        g[ds].pb(sr);
    }
    // from every single town, shortest path that crosses s different types
    // for every single type, do a dfs
    for(int i = 1; i <= k; ++i)
    {
        queue<int> bfs;
        for(auto src : ksrc[i])
        {
            bfs.push(src);
            dp[src][i] = 0;
        }
        while(!bfs.empty())
        {
            int c = bfs.front(); bfs.pop();
            for(auto e : g[c])
            {

                if (dp[e][i] == -1)
                {
                    dp[e][i] = dp[c][i] + 1;
                    bfs.push(e);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        sort(dp[i]+1, dp[i] + k + 1);
        int out = 0;
        for(int j = 1; j <= s; ++j)
        {
            out += dp[i][j];
        }
        cout << out << " ";
    }
    cout << endl;

    BYEBYE
}