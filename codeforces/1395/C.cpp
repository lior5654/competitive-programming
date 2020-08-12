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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ

const int maxn = 200 + 5;
int a[maxn] = { 0 };
int b[maxn] = { 0 };
int dp[512][maxn] = { { 0 } };
void solve()
{
    int n, m; cin >> n >> m;
    aread(a+1, n);
    aread(b+1, m);
    bitset<513> prev = 0;
    bitset<513> next = 0;
    prev[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            for(int k = prev._Find_first(); k != 513; k = prev._Find_next(k))
            {
                next[k|(a[i]&b[j])] = 1;
            }
        }
        prev = next;
        next = 0;
    }
    cout << prev._Find_first() << endl;
}
int main()
{
    GOGOGO
    int t;
    t=1;
    //cin >> t;
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