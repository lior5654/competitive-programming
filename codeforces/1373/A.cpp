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





void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    while (t--) {solve();}
    BYEBYE
}


void solve()
{
    ll a, b, c; cin >> a >> b >> c;
    if (b == 1)
    {
        if (c == a)
        {
            cout << -1 << " " << -1 << endl;
            return;
        }
        else if (c > a)
        {
            cout << 1 << " " << -1 << endl;
        }
        else
        {
            cout << -1 << " " << 1 << endl;
        }
        
    }
    else
    {
        if (a > c)
        {
            cout << -1 << " " << 1 << endl;
        }
        else if (c > a)
        {
            cout << 1 << " " << ((a * (b) > c) ? b : -1) << endl;
        }
        else
        {
            cout << -1 << " " << b<< endl;
        }
        
    }
    
}