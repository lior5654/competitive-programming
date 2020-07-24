//https://codeforces.com/contest/1384/problem/B1
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



// LIOR ORZ ORZ ORZ ORZ ORZ ORZ ORZ XD

const int maxn = 100 + 5;
const int maxk = 100 + 5;
int d[maxn] = { 0 };
// bool dp[maxn][201][201] = { { false } };
bool dp[maxn][201] = { { false } };
void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    // int t = 1;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < 2 * k; ++j)
        {
            dp[i][j] = false;
        }
    }
    rep(i, n)
    {
        cin >> d[i+1];
    }
    vector<int> p(2*k);
    for(int  i = 0; i <= k; ++i)
    {
        p[i] = i;
    }
    for(int i = k + 1; i < 2 * k; ++i)
    {
        p[i] = 2*k - i;
    }
    for(int i = 0; i < 2 * k; ++i)
    {
        dp[n+1][i] = true;
    }
    for(int i = n; i > 0; --i)
    {
        for(int st = 0; st < 2*k; ++st)
        {
            int cd = d[i] + p[st];
            if(cd > l) {dp[i][st] = false; continue;};
            bool yeet = false;
            for(int et = st; et < 2*k; ++et)
            {
                if(d[i]+p[et]>l)
                {
                    yeet = true;
                    break;
                }
                if(dp[i+1][(et+1)%(2*k)])
                {
                    dp[i][st] = true;
                    break;
                }
            }
            if(!yeet && !dp[i][st])
            {
                for(int et = 0; et < st; ++et)
                {
                    if(d[i]+p[et]>l)
                    {
                        yeet = true;
                        break;
                    }
                    if(dp[i+1][(et+1)%(2*k)])
                    {
                        dp[i][st] = true;
                        break;
                    }
                }
            }
        }
    }
    bool yes = false;
    for(int i = 0; i < 2 * k; ++i)
    {
        if(dp[1][i])
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}