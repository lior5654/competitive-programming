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
//#define PREC 10
//#define USACO "sleepy"

const int maxn = 1e5 + 5;

int p[maxn]; int n;
int upl[maxn]; int upr[maxn]; int downr[maxn]; int downl[maxn];
int predownl[maxn]; int preupl[maxn];
int sufdownr[maxn]; int sufupr[maxn];
void solve() {
    cin >> n;
    rep(i, n) {
        cin >> p[i+1];
    }
    upl[1] = 0; upr[n] = 0;
    for(int i = 2; i <= n; ++i) {
        if(p[i-1] > p[i]) {
            upl[i] = upl[i-1] + 1;
        } else {
            upl[i] = 0;
        }
    }
    for(int i = n - 1; i >= 1; --i) {
        if(p[i+1] > p[i]) {
            upr[i] = upr[i+1] + 1;
        } else {
            upr[i] = 0;
        }
    }
    downl[1] = 0; downr[n] = 0;
    for(int i = 2; i <= n; ++i) {
        if(p[i-1] < p[i]) {
            downl[i] = downl[i-1] + 1;
        } else {
            downl[i] = 0;
        }
    }
    for(int i = n - 1; i >= 1; --i) {
        if(p[i+1] < p[i]) {
            downr[i] = downr[i+1] + 1;
        } else {
            downr[i] = 0;
        }
    }
    for(int i = 1; i <= n; ++i) {
        predownl[i] = max(downl[i], predownl[i-1]);
        preupl[i] = max(upl[i], preupl[i-1]);
    }
    for(int i = n; i >= 1; --i) {
        sufdownr[i] = max(downr[i], sufdownr[i+1]);
        sufupr[i] = max(upr[i], sufupr[i+1]);
    }


    int res = 0;
    for(int i = 1; i <= n; ++i) {
        if(!(i == 1 || downl[i] == 0 || downr[i] == 0 || i==n)) {
            int gol = downl[i]; int gor = downr[i];
            int l = i - gol;
            int r = i + gor;
            int besl = max(predownl[l], preupl[l]);
            int besr = max(sufdownr[r], sufupr[r]);
            int bes = max(besl, besr);
            int mybes = max(gol, gor);
            if(bes < mybes) {
                int ml = gol;
                if(!(ml%2)) {
                    ml--;
                }
                int mr = gor;
                if(!(mr%2)) {
                    mr--;
                }
                if(!(ml >= gor || mr >= gol)) {
                    res++;
                }
            }

        }

    }
    cout << res << '\n';

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
