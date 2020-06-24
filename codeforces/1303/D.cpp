//https://codeforces.com/contest/1303/problem/D
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


const int maxlog = 61;
int p[maxlog + 1] = { 0 };

void solve()
{
    ll n; cin >> n;
    ll sm = 0;
    int out = 0;
    int m; cin >> m;
    rep(i, maxlog)
    {
        p[i] = 0;
    }
    int cur;
    rep(i, m)
    {
        cin >> cur;
        sm += cur;
        int ci = 0;
        while (cur >>= 1) {ci++;}
        p[ci]++;
    }
    if (sm < n)
    {
        cout << -1 << endl;
        return;
    }
    // it is possible
    int moves = 0;
    rep(i, maxlog)
    {
         if (!(n & ((ll)1 << (ll)i)))
        {
            p[i+1] += p[i] / 2;
        }
        else
        {
            if (p[i])
            {
                p[i]--;
                p[i+1] += p[i] / 2;
            }
            else
            {
                // find highest non used power
                // this hamortizes complexity its fine
                int ccc = i;
                int of = 1;
                while(!p[++ccc]) { p[ccc] = 1; of++;}
                // cout << i << " " << of << endl;
                out += of;
                p[ccc]--;

            }
            
        }
    }
   cout << out << endl;
    
    
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