//https://codeforces.com/contest/1370/problem/B
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


const int maxn = 1000 + 5;

int a[2 * maxn] = { 0 };


void solve();
int main()
{
    GOGOGO
    int t; cin >> t; while(t--) {solve();}
    BYEBYE
}

void solve()
{
    int n; cin >> n;
    int mx = -1;
    vector<int> even;
    vector<int> odd;
    rep(i, 2 * n)
    {
        cin >> a[i];
        if (a[i] % 2) {odd.pb(i);} else {even.pb(i);}
    }
    if (!odd.size() || odd.size() == 2 * n)
    {
        rep(i, n-1)
        {
            cout << 2 * i + 1 << " " << 2 * i + 2 << endl;
        }
        return;
    }
    if (odd.size() % 2)
    {
        rep(i, odd.size() / 2)
        {
            cout << odd[2 * i] + 1 <<  " " << odd[2*i+1] + 1 << endl;
        }
        rep(i, n -1 - (odd.size() / 2))
        {
            cout << even[2*i] + 1 << " " << even[2*i+1] + 1 << endl;
        }
    }
    else
    {
        rep(i, odd.size() / 2)
        {
            cout << odd[2 * i] + 1 <<  " " << odd[2*i+1] + 1<< endl;
        }
        rep(i, n -1 - (odd.size() / 2))
        {
            cout << even[2*i] + 1 << " " << even[2*i+1] + 1 << endl;
        }
    }

}