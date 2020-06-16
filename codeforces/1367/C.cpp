//https://codeforces.com/contest/1367/problem/C
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




void solve();

int main()
{
    GOGOGO
    int t; cin >> t;
    while ( t--)
    {
        solve();
    }
    BYEBYE
}


void solve()
{
    int n, k; cin >> n >> k;
    vector<int> pref(n+1);
    pref[0] = 0;
    clrcin
    string s; cin >> s;
    for(int i = 1; i <= n; ++i)
    {
        pref[i] = ((s[i-1] == '1') ? 1 : 0) + pref[i-1];
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    int rcount = 0;
    for(int i = 1; i <= n; ++i)
    {
        if (s[i-1] == '1') {++rcount;}
        // check if you can actually occupy it
        if (s[i-1] == '0' && ((i <= (1+k)  && !pref[i]) || (i > (k+1) && !(pref[i] - pref[i - k-1]))) && !(pref[min(i+k, n)] - pref[i]))
        {
            if (i <= k+1)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = max(dp[i-1], 1 + dp[i-k-1]);
            }
        }
        else
        {
            dp[i] = dp[i-1];
        }
        
    }
    cout << dp[n]<< endl;

}