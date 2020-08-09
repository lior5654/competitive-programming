#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ

const int maxn = 100 + 5;
const int maxm = 100 + 5;

bool t[maxn][maxm] = { {  false } };
int dp[maxn][maxn] = { { 0 } };
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, n)
    {
        rep(j, m)
        {
            char c; cin >> c;
            t[i][j] = c == 'R';
        }
    }
    int cnt = 0;
    dp[n-1][m-1] = 0;
    for(int j = m - 2; j >= 0; --j)
    {
        cnt +=  (t[n-1][j] ? 0 : 1); 
    }
    for(int j = n-2; j >= 0; --j)
    {
        cnt +=  (t[j][m-1] ? 1 : 0); 
    }
    /*
    for(int i = n - 2; i >= 0; --i)
    {
        for(int j = m - 2; j >= 0; --j)
        {
            dp[i][j] = min(dp[i+1][j] + (t[i][j] ? 1 : 0), dp[i][j+1] + + (t[i][j] ? 0 : 1));
        }
    }*/
    cout << cnt << endl;

}
int main()
{
    GOGOGO
    int t;
    //t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/