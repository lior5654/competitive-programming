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
const ll INFL = 4e18 + 5;

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ

































// #define BRUH_WHY_TESTCASES
#define int int64_t
const ll mod = 1e9 + 7;
const int maxl = 32;
vector<bool> vis;
int lineans[maxl] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14, -1};
map<int, int> vline[maxl];
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
int rec(int mask, int lsz)
{
    // parent = mask that recursion was called with
    // mask = mask tested (child of parent)
    // l -> result of query of mask (child of parent)
    if(vline[lsz].find(mask) != vline[lsz].end())
    {
        return vline[lsz][mask];
    }
    int omask = mask;
    vector<int> bruh;
    for(int i = 0; i < lsz; ++i)
    {
        mask = omask;
        if(omask&(1<<i))
        {
            for(int j = i; j < lsz; j += i + 1)
            {
                mask &= (1L<<lsz) - (1L<<j) - 1L;
            }
            if(mask != omask)
            {
                int l = rec(mask, lsz);
                bruh.pb(l);
            }
        }
    }
    if(bruh.empty())
    {
        return vline[lsz][omask] = 0;
    }
    
    return vline[lsz][omask] = MEX(bruh);

}



void solve()
{
    /*cout << "{";
    for(int i = 1; i <= 30; ++i)
    {
        cout << rec((1L << i) - 1L, i) << ", ";
    }
    cout << "}" << endl;*/
    ll n; cin >> n;
    int cnt = 1L; // number of things bigger than sqrt(n) we took
    int sz = sqrt(n);
    ll xr = 1L;
    vis.resize(sz+1, false);
    for(int i = 2; i * i <= n; ++i)
    {
        if(vis[i]) continue;
        int lsz = 1L;
        cnt++;
        int temp = i;
        while(temp * i <= n) { 
            if(temp<=sz)
            {
                vis[temp] = true;
            }
            cnt++; 
            temp *= i;  
            lsz++;
        }
        if(lineans[lsz] >= 0)
        {
            xr ^= lineans[lsz];
        }
        else
        {
            assert(false);
            xr ^= (lineans[lsz] = rec((1L << lsz) - 1L, lsz));
        }
        
    }
    xr ^= (n - cnt) % 2L;
    cout << (xr?"Vasya":"Petya") << '\n';

}










































signed main()
{
    //GOGOGO
    cout << fixed << setprecision(6);
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