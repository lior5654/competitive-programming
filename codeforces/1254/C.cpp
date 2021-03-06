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
               ___,'`-._ \_/     `,._        ;
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
pl,
null_type,
less<pl>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
 
typedef long double ld;
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
const ll INFL = 1e17 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}





//#define BRUH_WHY_TESTCASES
//#define PREC 6
//#define USACO "sleepy"

int left_point; int right_point; int n;

int get_sign(int i, int j, int k) {
    cout << 2 << " " << i << " " << j << " " <<  k << endl;
    int sign; cin >> sign; return sign;
}
ll get_area(int i, int j, int k) {
    cout << 1 << " " << i << " " << j << " " <<  k << endl;
    ll area; cin >> area; return area;
}
void solve() {
    cin >> n; left_point = 1;
    right_point = 2;
    for(int i = 3; i <= n; ++i) {
        if(get_sign(left_point, right_point, i) < 0) {
            right_point = i;
        }
    }
    vector<pair<ll, int>> others;
    for(int i = 1; i <= n; ++i) {
        if(i == left_point || i == right_point) continue;
        others.emplace_back(get_area(left_point, i, right_point), i);
    }
    sort(all(others));
    assert(others.size() == n - 2);


    vector<int> resl; vector<int> resr;
    resl.pb(left_point);
    resr.pb(right_point);
    for(int i = 0; i < n -3; ++i) {
        int sign = get_sign(others[i].se, resr[resr.size()-1], others[i+1].se);
        if(sign > 0) {
            resl.pb(others[i].se);
        } else {
            resr.pb(others[i].se);
        }
    }
    cout << 0;
    cout << " " << resl[0];
    reverse(all(resl));
    for(auto e : resr) {
        cout << " " << e;
    }
    cout << " " << others[n-3].se;
    for(auto e : resl) {
        if(e!=left_point) {
            cout << " " << e;
        }
    }
    cout << endl;

    /*
    int next = 0;
    for(int i = 0; i < n-3; ++i) {
        int sign = get_sign(others[i].se, right_point, others[next].se);
        if(sign >0) {
            res.pb(others[next].se); next = sign;
        } else {
            res.pb(others[i].se);
        }
    }
    res.pb(others[next].se);
    cout << 0;
    for(auto e : res) {
        cout << " " << e;
    }
    cout << endl;*/
}

























































 
signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
    #endif
    //GOGOGO
    #ifdef PREC
      cout << fixed << setprecision(PREC);
    #endif
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
