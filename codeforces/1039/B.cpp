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
//typedef __int128_t bigint;
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
const ll INFL = 1e18 + 5;

template<class T> using func = function<T>;

/************************************ general.hpp begin ************************************/

namespace CompetitiveProgramming
{

using bigint = long long int;
using ll = long long int;
using ftype = long double;
using ld = long double;

namespace IO
{

template<class ElementType> inline void output_array(ElementType* array, uint32_t size)
{
    if(size)
    {
        cout << *array++;
        size--;
        while(size)
        {
            cout << ' ' << *array++;
            --size;
        }
    }
    cout << '\n';
}

template<class Iterator> inline void output_iterator_range(Iterator begin, const Iterator& end)
{
    if(begin != end)
    {
        cout << *begin++;
        while(begin != end)
        {
            cout << ' ' << *begin++;
        }
    }
    cout << '\n';
}

template<class Container> inline void output_container(const Container& container)
{
    output_iterator_range(container.begin(), container.end());
}

template<class ElementType> inline void read_array(ElementType* array, uint32_t size)
{
    while(size)
    {
        cin >> *array++;
        --size;
    }
}

template<class Iterator> inline void read_iterator_range(Iterator begin, const Iterator& end)
{
    while(begin != end)
    {
        cin >> *begin++;
    }
}
template<class Container> inline void read_container(Container& container)  // I dont think this will work for set etc, only std::array, std::vector etc
{
    read_iterator_range(container.begin(), container.end());
}

}

}


using namespace CompetitiveProgramming;
using namespace IO;

/************************************ general.hpp end ************************************/



//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<ll>(0, INFL);
ll n, k;
ll l, r;


ll grnd()
{
    return DIST(rng);
}
bool query(ll ql, ll qr)
{
    cout << ql << ' ' << qr << endl;
    string res; cin >> res;
    if(res == "Bad") {
        exit(-1);
    }
    return res == "Yes";
}
void fix()
{
    while(r - l > 4*k+1)
    {
        ll m = l + (r-l) / 2;
        if(query(l, m)) {
            l = max(1LL, l-k);
            r = min(n, m+k);
        } else {
            l = max(1LL, m+1LL-k);
            r = min(n, r+k);
        }
    }
}
void solve() {
    cin >> n >> k;
    l = 1; r = n;
    while(true)
    {
        fix();
        ll guess = l + (grnd() % (r - l + 1));
        if(query(guess, guess))
        {
            exit(0);
        }else {
            l -= k; r += k;
            l = max(1LL, l);
            r = min(n, r);
        }
    }
}




signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
    #endif
    GOGOGO
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