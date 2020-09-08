#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 
 
using namespace __gnu_pbds;
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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
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
 
// LIORZ LIORZ LIORZ LIORZ LIORZ


const int maxn = 1e3 + 5;
int a[maxn];
int b[maxn];
void solve()
{
    int n; cin >> n; rep(i, n) {cin >> a[i];}
    sort(a, a+n);
    reverse(a, a+n);
    b[0] = a[0];
    int gc = b[0];
    for(int i = 1; i < n; ++i)
    {
        sort(a +i, a+n, [&](int d, int e){return gcd(gc, d) > gcd(gc, e);});
        b[i] = a[i];
        gc = gcd(gc, b[i]);
    }
    rep(i, n)
    {
        cout << b[i] << ' ';
    }
    cout << '\n'; return;

}

signed main()
{
    GOGOGO
    //cout << fixed << setprecision(9);
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}
 
/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/