/*
                            . .  ,  ,
                            |` \/ \/ \,',
                            ;          ` \/\,.
                           :               ` \,/
                           |                  /
                           ;                 :
                          :                  ;
                          |      ,---.      /
                         :     ,'     `,-._ \
                         ;    (   o    \   `'
                       _:      .      ,'  o ;
                      /,.`      `.__,'`-.__,
                      \_  _               \
                     ,'  / `,          `.,'
               ___,'`-._ \_/ `,._        ;
            __;_,'      `-.`-'./ `--.____)
         ,-'           _,--\^-'
       ,:_____      ,-'     \
      (,'     `--.  \;-._    ;
      :    Y      `-/    `,  :
      :    :       :     /_;'
      :    :       |    :
       \    \      :    :
        `-._ `-.__, \    `.
           \   \  `. \     `.
         ,-;    \---)_\ ,','/
         \_ `---'--'" ,'^-;'
         (_`     ---'" ,-')
         / `--.__,. ,-'    \
-hrr-    )-.__,-- ||___,--' `-.
        /._______,|__________,'\
        `--.____,'|_________,-'

                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including 

//using namespace __gnu_pbds;
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
/*typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/

template<class T> using func = function<T>;

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

































#define BRUH_WHY_TESTCASES
const int maxn = 2e5 + 5;
const int root = 1;
int n;
vi g[maxn];
ll a[maxn];
ll dp[maxn] = { 0 };
int p[maxn];
int maximum_distance = 0;
vector<ll> layer[maxn];

void dfs(int c, int par, int dd=0) {
    p[c] = par;
    maximum_distance = max(maximum_distance, dd);
    layer[dd].pb(c);
    for(auto e : g[c]) {
        if(e != par) {
            dfs(e, c, dd+1);
        }
    }
}
void solve()
{
    maximum_distance = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        layer[i].clear();
        dp[i] = 0;
        p[i] = 0;
    }
    for(int i = 2; i <= n; ++i) {
        int t; cin >> t;
        g[i].pb(t);
        g[t].pb(i); 
    }
    for(int i= 2; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(root,0);
    
    ll best_negative = -INFL; ll best_positive = 0;
    ll best_negative_swap = -INFL; ll best_positive_swap = 0;
    for(auto leaf : layer[maximum_distance]) {
        dp[leaf] = 0;
        best_negative = max(best_negative, -a[leaf]);
        best_positive = max(best_positive, a[leaf]);
        best_negative_swap = max(best_negative_swap, -a[leaf]);
        best_positive_swap = max(best_positive_swap, a[leaf]);
    }
    for(int current_layer = maximum_distance - 1; current_layer >= 0; --current_layer) {
        ll next_negative = -INFL; ll next_positive = 0;
        ll next_negative_swap = -INFL; ll next_positive_swap = 0;
        for(auto node : layer[current_layer]) {
            dp[node] = 0;
            for(auto child : g[node]) {
                if(child == p[node]) continue;
                dp[node] = max(dp[node], max(a[child] + max(best_negative + dp[child], best_negative_swap), 
                              -a[child] + max(best_positive + dp[child], best_positive_swap)));
            }
            next_negative = max(-a[node], next_negative);
            next_positive = max(a[node], next_positive);
            next_negative_swap = max(next_negative_swap, -a[node] + dp[node]);
            next_positive_swap = max(next_positive_swap, a[node] + dp[node]);
        }
        best_negative = next_negative; best_positive = next_positive; 
        best_positive_swap = next_positive_swap; best_negative_swap = next_negative_swap;
    }
    cout << dp[root] << '\n';
}










































int main()
{
    GOGOGO
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
        cin >> t;
    #endif
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