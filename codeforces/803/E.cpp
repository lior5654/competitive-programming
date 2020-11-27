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
pi,
null_type,
less<pi>,
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
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


/*
const ll mod = 998244353;
template<int maxf> struct combi
{
    ll fact[maxf];
    ll invfact[maxf];
    ll bexp(ll b, ll p) const
    {
        ll res = 1;
        ll curr = b;   
        while(p)
        {
            if(p % 2ll)    
            {
                res *= curr;
                res %= mod;
            }

            curr *= curr;
            curr %= mod;
            p /= 2;
        }
        return res;
    }
    ll invmod(ll i) const
    {
        return bexp(i, mod - 2ll);
    }
    combi()
    {
        fact[0] = 1;
        fact[1] = 1;
        invfact[0] = invmod(1);
        invfact[1] = invfact[0];
        for(ll i = 2; i < maxf; ++i)
        {
            fact[i] = i * fact[i-1];
            fact[i] %= mod;
            invfact[i] = invmod(i);
        }
    }
    ll choose(ll n, ll k) const
    {
        if(k > n) return 0;
        return (((fact[n] * invfact[n-k]) % mod) * invfact[k]) % mod;
    }
};*/

// LIORZ LIORZ LIORZ LIORZ LIORZ
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
const int maxn = 1e3 + 5;
const int maxk = 1e3 + 5;



const map<char, int> trans = {{'W', 1}, {'L', -1}, {'D', 0}}; 
const map<int, char> itrans = {{1, 'W'}, {-1, 'L'}, {0, 'D'}}; 
bool dp[maxn][3*maxk] = {{false }};
int cons[maxn][3*maxk];
int n, k;




void recover(int u)
{
    string out;
    for(int i = n; i >= 1; --i)
    {
        out += itrans.at(cons[i][maxk+u]);
        u -= cons[i][maxk+u];
    }
    reverse(all(out));
    cout << out << '\n';
}

void solve()
{

    cin >> n >> k; clrcin
    string s; cin >> s;
    dp[0][maxk] = true;
    for(int i = 1; i <= n; ++i)
    { 
        if(s[i-1] == '?')
        {
            if(dp[i-1][maxk+k-2]) {
                dp[i][maxk+k-1] = true;
                cons[i][maxk+k-1] = +1; 
            } else if (dp[i-1][maxk+k-1])
            {
                dp[i][maxk+k-1] = true;
                cons[i][maxk+k-1] = 0; 
            }
            if(dp[i-1][maxk-k+2]) {
                dp[i][maxk-k+1] = true;
                cons[i][maxk-k+1] = -1; 
            } else if (dp[i-1][maxk-k+1])
            {
                dp[i][maxk-k+1] = true;
                cons[i][maxk-k+1] = 0; 
            }
            for(int st = -k + 2; st <= k - 2; ++st)
            {
                if(dp[i-1][maxk+st]) {
                dp[i][maxk+st] = true;
                cons[i][maxk+st] = 0; 
                } else if (dp[i-1][maxk+st+1])
                {
                    dp[i][maxk+st] = true;
                    cons[i][maxk+st] = -1; 
                } else if(dp[i-1][maxk+st-1]) {
                    dp[i][maxk+st] = true;
                    cons[i][maxk+st] = 1; 
                }
            }
            if(i == n)
            {
                for(auto st : {-k, k})
                {
                    if (dp[i-1][maxk+st+1])
                    {
                        dp[i][maxk+st] = true;
                        cons[i][maxk+st] = -1; 
                    } else if(dp[i-1][maxk+st-1]) {
                        dp[i][maxk+st] = true;
                        cons[i][maxk+st] = 1; 
                    }
                }
            }
        }
        else
        {
            for(int st = -k+1; st <= k-1; ++st)
            {
                dp[i][st+maxk] = dp[i-1][st-trans.at(s[i-1])+maxk];
                cons[i][st+maxk] = trans.at(s[i-1]);
            }
            if(i == n)
            {
                for(auto st : {-k, k})
                {
                   dp[i][st+maxk] = dp[i-1][st-trans.at(s[i-1])+maxk];
                   cons[i][st+maxk] = trans.at(s[i-1]);
                }
            }
        }
        
        
    }
    for(auto u : {-k, k})
    {
        if(dp[n][maxk+u])
        {
            recover(u);
            return;
        }
    }
    cout << "NO" << '\n';

    return;

}
 
 
 
 
signed main()
{
    GOGOGO
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
