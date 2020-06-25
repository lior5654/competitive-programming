//https://codeforces.com/contest/1366/problem/C
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

const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;

const int md = 30 + 5;

int brd[md][md] = { { 0 } };


void solve();

int main()
{
    GOGOGO
    int t; cin >> t; while(t--) { solve();}
    BYEBYE
}

void solve()
{
    int n, m; cin >> n >> m;
    vvi count(n + m - 1, vi(2));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> brd[i][j];
            count[i + j][brd[i][j]]++;
        }
    }
    // d <-> n + m - 2 - d
    // ignore (n + m - 2)/2
    int out = 0;
    rep(i, n+m)
    {
        if (i >= n + m - 2 - i) break;
        out += min(count[i][0] + count[n + m - 2 - i][0], count[i][1] + count[n + m - 2 - i][1]);
    }
    cout << out << endl;

}