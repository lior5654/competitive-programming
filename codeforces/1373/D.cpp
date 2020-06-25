//https://codeforces.com/contest/1373/problem/D
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



ll kadanes(ll array[],int length) {
   ll highestMax = 0;
   ll currentElementMax = 0;
   ll bestl = 0;
   ll bestr = 0;
   for(int i = 0; i < length; i++){
      currentElementMax =max(array[i],currentElementMax + array[i]) ;
      highestMax = max(highestMax,currentElementMax);
   }
   return highestMax;
}


const int maxn = 2e5 + 5;

ll a[maxn] = { 0 };
ll d1[maxn] = { 0 };
ll d2[maxn] = { 0 };
void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    while(t--) {solve();}
    BYEBYE
}



void solve()
{
    ll res = 0;
    int n; cin >> n;
    int nd = 0;
    rep(i, n)
    {
        cin >> a[i];
        if (!(i % 2))
        {
            res += a[i];
            a[i] = -1 * a[i];
        }

    }
    int i1 = 0;
    int i2 = 0;
    rep(i, n)
    {
        if (i % 2 && i != n - 1)
        {
            d1[i1++] = a[i] + a[i+1];
        }
        else if (!(i % 2) && i != n - 1)
        {
            d2[i2++] = a[i] + a[i+1];
        }
    }

    cout << res +  max((ll)0, max(kadanes(d1, i1), kadanes(d2, i2))) << endl;
}