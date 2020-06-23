//https://codeforces.com/contest/1369/problem/D
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
const ll MOD = 1e9 + 7;

const int maxn = 2 * 1e6 + 5;


ll dp[2][maxn] = { 0 };

void init()
{
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 0;
    dp[1][1] = 0;
    dp[0][2] = 0;
    dp[1][2] = 0;
    dp[0][3] = 0;
    dp[1][3] = 4;
    dp[0][4] = 4;
    dp[1][4] = 4;

    repk(i, 5, maxn - 1)
    {
        dp[1][i] = (4 + 2* dp[0][i-2] + dp[0][i-1]) % MOD;
        dp[0][i] = (2 * max(dp[1][i-2], dp[0][i-2]) + max(dp[1][i-1], dp[0][i-1])) % MOD; 
    }
}

int main()
{
    GOGOGO
    init();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; cout << max(dp[1][n], dp[0][n]) << endl;
    }
    BYEBYE
}