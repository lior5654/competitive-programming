//https://codeforces.com/contest/1065/problem/C
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
const int maxh = maxn;

int h[maxn+1] = { 0 };

ll dp[maxh  + 2] = { 0 };
int helper[maxh+1] = { 0 };
// dp[i] - number oh boxes between height [1 ... i] 
// dp[i+1] = dp[i+1] + count of boxes from sweep line
// binary search dp for best cut every time (greedy approach)

// count will increase every time 
void solve();

int n, k;

int main()
{
    GOGOGO
    int minh = INFI;
    int maxh = -1;
    cin >> n >> k;
    rep(i, n) { cin >> h[i]; minh = min(minh, h[i]); maxh = max(maxh, h[i]); helper[h[i]]++;}
    dp[maxh+1] = 0;
    int count = 0;
    for(int i = maxh; i > 0; --i)
    {
        count += helper[i];
        dp[i] = dp[i+1] + (ll)count;
    }
    int cuts = 0;
    int curr = maxh;
    ll removed = 0;
    while(true)
    {
        if (curr == minh)
        {
            if (removed != dp[curr+1])
            {
                cuts++;
            }
            break;
        }
        if (removed + k < dp[curr])
        {
            removed = dp[curr+1];
            ++cuts;
        }
        --curr;
    }
    cout << cuts << endl;
    // we want to binary search every time position of best cut until we get to a  height of less than or equal to minh
    // we dont even need binary search this is possible in O(n)
    
    
    BYEBYE
}
