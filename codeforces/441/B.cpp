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



// ai day bi amount
// collect day ai and ai+1
// collect  v fruits at max
const int maxn = 3000;
const int maxv = 3000;
const int maxa = 3001;
int a[maxn+1] = { 0 };
int f[maxa+1] = { 0 };
int s[maxa+2] = { 0 };
int main()
{
    GOGOGO
    int n, v; cin >> n >> v;
    rep(i, n)
    {
        int t;
        cin >> a[i] >> t;
        f[a[i]] += t;
        s[a[i]+1] += t;
    }
    int out = 0;
    // take everything you can from s, then f, then nothing
    for(int i = 1; i <= maxa; ++i)
    {
        int left = v;
        int m = min(s[i], left);
        out += m;
        left -= m;
        if (left)
        {
            m = min(f[i], left);
            out += m;
            left -= m;
            if ( i < maxa)
            {
                s[i+1] -= m;
                if (s[i+1] < 0) s[i+1] = 0;
            }
        }
    }
    cout << out << endl;
    BYEBYE
}