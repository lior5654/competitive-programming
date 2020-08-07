//https://codeforces.com/contest/1393/problem/B
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
const int maxn = 1e5 + 5;
int a[maxn] = { 0 };
void solve()
{
    int n; cin >> n;
    aread(a, n);
    map<int, int> am;
    map<int, int> ram;
    ram[0] = 0;
    int twoc = 0;
    int fourc = 0;
    rep(i, n)
    {
        if(am.find(a[i]) == am.end())
        {
            am[a[i]] = 0;
            ram[0]++;
        }
        am[a[i]]++;
        if(ram.find(am[a[i]]) == ram.end())
        {
            ram[am[a[i]]] = 0;
        }
        ram[am[a[i]]]++;
    }
    int q; cin >> q;
    rep(i, q)
    {
        char ty; cin >> ty;
        int x; cin >> x;
        if(ty == '-')
        {
            am[x]--;
            ram[am[x]+1]--;
            if(ram[am[x]+1] == 0)
            {
                ram.erase(am[x]+1);
            }
        }
        else
        {
            if(am.find(x) == am.end())
            {
                am[x] = 0;
                ram[0]++;
            }
            am[x]++;
            if(ram.find(am[x]) == ram.end())
            {
                ram[am[x]] = 0;
            }
            ram[am[x]]++;

        }
        if(ram.find(2) != ram.end() && ram.find(4) != ram.end() && ram[4] >= 1 && (ram[2] >= 3  || (ram.find(6) != ram.end() && ram[6] >= 1 && ram[2] >= 2) || (ram.find(8) != ram.end() && ram[8] >= 1) || ram[4] >= 2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
        
    }
}
int main()
{
    GOGOGO
    int t;
    t=1;
    //cin >> t;
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