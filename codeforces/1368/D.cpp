//https://codeforces.com/contest/1368/problem/D
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



const int maxn = 2e5;

int cnt[21] = { 0 };
int main()
{
    GOGOGO
    int n; cin >> n;
    ll out = 0;
    ll curr;
    rep(i, n)
    {
        cin >> curr;
        for(int j = 0; j <= 20; ++j)
        {
            if((curr & (ll)(1 << j)))
            {
                cnt[j]++;
            }
        }
    }
     bool found = true; 
    while (found)
    {
        ll x = 0;
        found = false;
        rep(j, 21)
        {
            if (cnt[j])
            {
                found = true;
                x |= 1 << j;
                --cnt[j];
            }
        }
        out += x * x;
    }
    cout << out << endl;

    BYEBYE
}