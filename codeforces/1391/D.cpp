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

const int maxm = 1e6 + 5;const int maxn = 1e6 + 5;const int maxp = 3;
int magic3[4] = {2, 3, 0, 1};int magic2[2] = {1, 0};
int n, m;
int cst(int target, int source) {
    return popcnt(target^source);
}
int gen(int ini, int next, int magic[]){
    return cst(magic[min(ini,((1<<n)-1)-ini)],next)<cst(((1<<n)-1)-magic[min(ini,((1<<n)-1)-ini)],next)?magic[min(ini,((1<<n)-1)-ini)]:((1<<n)-1)-magic[min(ini,((1<<n)-1)-ini)];
}
void solve(){// n<=m
    cin >> n >> m;
    if(n >= 4){
        cout << -1 << endl;
    } else if(n == 1 || m == 1){
        cout << 0 << endl;
    } else {
        vector<bitset<maxp>> a(m, 0);
        rep(i, n){rep(j, m){
            char c; cin >> c;
            a[j][i] = c - '0';
        }}
        int best = INFI;
        rep(ini, 1<<n){
            int curr = ini; int p = 0;
            rep(i, m){
                curr = gen(curr,a[i].to_ulong(),(n==2)?magic2:magic3);
                p += cst(curr, a[i].to_ulong());
            }
            best = min(best, p);
        }
        cout << best << endl;
    }
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