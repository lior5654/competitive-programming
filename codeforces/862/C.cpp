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






int main()
{
    GOGOGO
    int n, x; cin >> n >> x;
    int xr = 0;
    if (n == 1)
    {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
    }
    if (n == 2 && !x) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        if (n == 2)
        {
            cout << x << " " << 0 << endl;
        }
        else
        {
            for(int i = 1; i <= n - 3; ++i)
            {
                xr ^= i;
                cout << i << " ";
            }
            if (xr == x)
            {
                cout << (1 << 17) << " " << (1 << 18) << " " << ((1 << 17) + (1 << 18)) << endl;
            }
            else
            {
                cout << 0 << " "  << (1 << 17) << " " << (((1 << 17) ^ xr) ^ x) << endl;
            }
        }
    }

    BYEBYE
}