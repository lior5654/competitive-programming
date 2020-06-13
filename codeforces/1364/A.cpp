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

const int maxn = 1e5;
const int maxx = 1e4;
int a[maxn+1]= { 0 };

int pref[maxn+1] = { 0 };
int fir[maxx+1] = { 0 };
int las[maxx+1] = { 0 };
int n, x; 
int maxres = -1;

void solve();

int main()
{
    GOGOGO
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    BYEBYE
}

void solve()
{
    // iteration for every modulo x is possible
    cin >> n >> x;
    maxres = -1;
    pref[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        pref[i] = (pref[i-1] + a[i]) % x;
    }
    for(int i = 0; i < x; ++i)
    {
        fir[i] = -1;
        las[i] = -1;
    }
    for(int i = 0; i <= n; ++i)
    {
        if (fir[pref[i]] == -1)
        {
            fir[pref[i]] = i;
        }
    }
    for(int i = n; i >= 0; --i)
    {
        if (las[pref[i]] == -1)
        {
            las[pref[i]] = i;
        }
    }
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            if (i == j) continue;
            if (las[j] != -1 && fir[i] != -1)
            {
                maxres = max(maxres, las[j] - fir[i]);
            }
        }
    }



    cout << maxres << endl;

}