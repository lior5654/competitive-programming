//https://codeforces.com/contest/780/problem/B
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




const int maxn = 60000 + 5;

int x[maxn] = { 0 };
int v[maxn] = { 0 };
int n;

bool good(double m)
{
    double mxl = -1; double mnr = INFI;
    rep(i, n)
    {
        mxl = max(mxl, (double)x[i] - m * v[i]);
        mnr = min(mnr, (double)x[i] + m * v[i]);
    }
    return mxl <= mnr;
}
int main()
{
    GOGOGO
    cout << setprecision(10) << endl;
    cin >> n; rep(i, n) { cin >> x[i];}
    rep(i, n) {cin >> v[i];}
    double l = 0;
    double h = 1e9;
    while (h - l > 0.0000001)
    {
        double mid = l + (h - l) / 2;
        if (good(mid))
        {
            h = mid - 0.0000001;
        }
        else
        {
            l = mid + 0.0000001;
        }
        

    }
    cout << (l + h) / 2  << endl;
    BYEBYE
}