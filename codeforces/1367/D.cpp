//https://codeforces.com/contest/1367/problem/D
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
 

const int sax = 50 + 5;

int b[sax] = { 0 };  
 
void solve();
 
int main()
{
    GOGOGO
    int t; cin >> t;
    while ( t--)
    {
        solve();
    }
    BYEBYE
}
 

void solve()
{
    string s; cin >> s;
    sort(all(s));
    reverse(all(s));
    // cout << s << endl;
    int m; cin >> m;
    rep(i, m)
    {
        cin >> b[i];
    }
    int n = s.length();
    int p = 0;

    vector<char> out(m, 0);
    int vis = 0;
    while(vis != m)
    {
        int cnt = 0;
        vector<int> pos;
        rep(i, m)
        {
            if (!out[i] && !b[i])
            {
                pos.pb(i); cnt++; vis++;
            }
        }
        int amnt = 0;
        int beg = 0;
        while (amnt < cnt)
        {
            amnt = 0;
            beg = p;
            while (p < n && s[beg] == s[p]) {++amnt; ++p;}
        }
        for (auto po : pos)
        {
            out[po] = s[beg];
        }
        rep(i, m)
        {
            if (!out[i])
            {
                for (auto po : pos)
                {
                    b[i] -= abs(po - i);
                }
            }
        }

    }
    for(int i = 0; i < m; ++i)
    {
        cout << out[i];
    }
    cout << endl;

}