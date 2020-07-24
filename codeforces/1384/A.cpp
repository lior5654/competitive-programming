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


// GUESS A GUESS A GUESS A GUESS A GUESS A GUESS A GUESS A GUESS A GUESS A

// LIOR ORZ ORZ ORZ ORZ ORZ ORZ ORZ XD

const int maxn = 100 + 5;

int a[maxn] = { 0 };
int id[maxn] = { 0 };
void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    //int t = 1;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

void solve()
{
    int n; cin >> n;
    rep(i, n)
    {
        cin >> a[i];
        id[i] = i;
    }
    sort(id, id + n, [&](int c, int b){return a[c] < a[b];});
    bool f = true;
    string curr = "";
    int old = 0;
    vector<string> out(n+1);
    for(int i = 0; i < a[0]; ++i)
    {
        out[0] += 'a';
        out[1] += 'a';
    }
    out[1] += 'a';
    out[0] += 'b';
    for(int i = 1; i < n; ++i)
    {
        int sz = out[i].size();
        if (a[i] < sz)
        {
            for(int j = 0; j < a[i]; ++j)
            {
                out[i+1] += out[i][j];
            }
            out[i+1] += (out[i][a[i]] - 'a' + 27) % 26 + 'a';
        }
        else
        {
            for(int j = 0; j < sz; ++j)
            {
                out[i+1] += out[i][j];
            }
            for(int j = sz; j < a[i]; ++j)
            {
                out[i+1] += (out[i][sz-1] - 'a' + 27) % 26 + 'a';
                out[i] += (out[i][sz-1] - 'a' + 27) % 26 + 'a';
            }
            out[i] += (out[i][sz-1] - 'a' + 27) % 26 + 'a';
            out[i+1] += (out[i][sz-1] - 'a' + 28) % 26 + 'a';
        }
        
    }
    for(int i = 0; i <= n; ++i)
    {
        cout << out[i] << endl;
    }
}