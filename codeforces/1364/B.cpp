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
int p[maxn + 1];
void solve();

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




void solve()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    vi res;
    res.pb(p[0]);
    int lst = 0;
    int curr = 1;
    while (curr < n)
    {
        if (p[curr] < res[lst])
        {
            while(curr < n - 1 && p[curr+1] < p[curr]) ++curr;
        }
        else
        {
            while(curr < n - 1 && p[curr+1] > p[curr]) ++curr;
        }
        res.pb(p[curr]);
        ++curr;
        ++lst;
    }
    cout << res.size() << endl;
    for(auto e : res)
    {
        cout << e << " ";
    }
    cout << endl;

}