//https://codeforces.com/contest/1373/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
using namespace std;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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

#define PL '+'
#define MN '-'


const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;


const int maxn = 1e6 + 5;

int pre[maxn] = { 0 };


void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}



void solve()
{
    ll res = 0;
    pre[0] = 0;
    string s; cin >> s;
    int mn = 0;
    int n = s.size();
    for(int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i-1] + (s[i-1] == '+' ? 1 : -1);
        mn = min(mn, pre[i]);
    }
    int ok = -1 * mn + 1;
    int cmin = 0;
    rep(i, n)
    {
        if (!ok) {break;}
        res += ok;
        if (pre[i+1] < cmin)
        {
            ok--;
            cmin = pre[i+1];
        }
    }
    cout << res << endl;
}