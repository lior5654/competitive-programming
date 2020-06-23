//https://codeforces.com/contest/1369/problem/C
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




void solve()
{
    int n, k; cin >> n >> k;
    vl a(n); 
    vl w;
    int cur;
    rep(i, n) {cin >> a[i];}
    sort(all(a));
    ll sum = 0;
    int cmax = n - 1;
    rep(i, k) {cin >> cur;
        if (cur == 1)
        {
            sum += 2 * a[cmax];
            cmax--;

        }
        else
        {
            w.pb(cur);
        }
    }
        
    sort(w.rbegin(), w.rend());
    // we want every time f - 1 minimums and a maximum
    int cmin = 0;
    int old = -1;
    for(auto f : w)
    {
        if (f == 1)
        {
            sum += 2 * a[cmax];
            cmax--;
        }
        else 
        {
            sum += a[cmax] + a[cmin];
            cmin += f-1;
            cmax--;
        }
        /*
        // old+1 - old + w
        if ( f - 2 >= 0)
        {
            sum += a[cmin];
            cmin = cmin + f - 1;
            sum += a[cmax];
        }
        else
        {
            sum += 2 * a[cmax];
        }
        
        cmax--;*/
    }
    cout << sum << endl;
}

int main()
{
    GOGOGO
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}