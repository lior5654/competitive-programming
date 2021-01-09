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
const ll INFL = 1e18 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}

 
 
 
 
 







typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(str.size()+1), pw(ha) {
		pw[0] = 1;
		for(int i = 0; i < str.size(); ++i)     
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (str.size() < length) return {};
	H h = 0, pw = 1;
	for(int i = 0; i < length; ++i)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	for(int i = length; i < str.size(); ++i) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}


















 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
const int maxn = 1e5 + 5;
//ll dp[maxn] = { 0 };

array<array<int, 2>, 2> mem = {array<int, 2>{0}};
//vector<pair<char, int>> v;
void solve() {
    string s; cin >> s;
    const int n = s.size();
    for(int i = 0; i < n; ++i) {
        mem[s[i]-'a'][i&1]++;
    }
    array<ll, 2> ans = { 0 };
    for(int i = 0; i < n; ++i) {
        ans[1] += mem[s[i]-'a'][i&1];
        ans[0] += mem[s[i]-'a'][!(i&1)];
        mem[s[i]-'a'][i&1]--;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
    /*
    string s; cin >> s;
    string s2;
    const int n = s.size();
    char cur = s[0];
    int cnt = 1;
    s2 = s[0];
    vector<int> pre;
    pre.pb(0);
    for(int i = 1; i < n; ++i) {
        if(s[i] != cur) {
            pre.pb(pre.back() + cnt);
            s2 += s[i];
            v.emplace_back(cur, cnt);
            cnt = 1;
            cur = s[i];
        } else {
            cnt++;
        }
    }
    pre.pb(pre.back() + cnt);
    v.emplace_back(cur, cnt);   
    const int n2 = s2.size();
    HashInterval h = HashInterval(s2);
    ll oddres = 0;
    for(int i = 0; i < n2; ++i) {
        int l = 1;
        int r = i+1;
        int best = 1;
        while(l <= r) {
            int m = l + (r-l) / 2;
            // [i-m+1,i+1) == [i,i+m)
            if((ull)h.hashInterval(i-m+1,i+1) == (ull)h.hashInterval(i,i+m)) {
                best = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // --------[xxxx]--------
        //   a1               a3
        // 

    }
    */
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
