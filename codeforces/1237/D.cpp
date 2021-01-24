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
 
#define popcnt __builtin_popcountll
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm
 
const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}

 
 
















 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES

const int maxn = 1e5 + 5;
const int maxh = 19;

ll a[2*maxn];


ll mn = INFL;
int nextBigger[2*maxn];
int id[maxn];
int ans[maxn];
int n; 
struct rmq {
    ll mem[maxh][2*maxn];
    void init() {
        rep(i, 2*n) {
            mem[0][i] = a[i];
        }
        for(int h = 1; h < maxh; ++h) {
            const int s = 1 << h;
            for(int i = 0; i +s -1< 2*n; ++i) {
                mem[h][i] = min(mem[h-1][i], mem[h-1][i+s/2]);
            }
        }
    }
    ll query(int l, int r) {
        const int lg = log2(r-l+1);
        const int s = 1<<lg;
        return min(mem[lg][l], mem[lg][r-s+1]);
    }
} rmq;
int firstHalf(int pos) {
    int l = pos+1; int r = nextBigger[pos]-1;
    int best = -1;
    while(l <= r) {
        int m = l + (r-l) / 2;
        if(rmq.query(pos,m) < (a[pos]+1)/2) {
            best = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return best;
}
void solve() {
    cin >> n; rep(i, n) {cin >> a[i]; mn = min(mn, a[i]);}
    rep(i,n) {
        a[n+i]=a[i];
    }
    stack<ll> s;
    for(int i = 2*n - 1; i >= 0; --i) {
        while(!s.empty() && a[s.top()] <= a[i]) s.pop();
        nextBigger[i] = (s.empty() ? 2*n : s.top());
        s.push(i);
    }
    rep(i, n) {
        id[i] = i;
    }
    sort(id, id + n, [&](int x, int y){return a[x] > a[y];});
    rmq.init();
    ans[n] = -1;
    rep(i, n) {
        int c = id[i];
        int fh = firstHalf(c);
        if(fh==-1) {
            if(nextBigger[c] == 2*n) {
                ans[c] = -1;
            } else {
                int papa = ans[nextBigger[c]%n];
                if(papa == -1) {
                    ans[c] = -1;
                }
                else {
                    ans[c] = papa + nextBigger[c] - c;
                }
            }
        } else {
            ans[c] = fh - c;
        }
    }
    rep(i, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';


}

 





















































 
signed main()
{
    GOGOGO
    //cout << fixed << setprecision(6);
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
