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

const int maxm = 1e6 + 5;
const int maxn = 1e6 + 5;

int cst(int target, int source)
{
    int res = 0;
    while(target || source)
    {
        if(target % 2 != source % 2)
        {
            res++;
        }
        target /= 2;
        source /= 2;
    }
    return res;
}
pi price3(int ini, int next)
{
    pi out = {0, 0};
    if(ini == 0 || ini == 7)
    {
        int g1 = cst(5, next);
        int g2 = cst(2, next);
        if(g1 < g2) return {g1, 5};
        return {g2, 2};
    }
    if(ini == 1 || ini == 6)
    {
        int g1 = cst(3, next);
        int g2 = cst(4, next);
        if(g1 < g2) return {g1, 3};
        return {g2, 4};
    }
    if(ini == 2 || ini == 5)
    {
        int g1 = cst(0, next);
        int g2 = cst(7, next);
        if(g1 < g2) return {g1, 0};
        return {g2, 7};
    }
    if(ini == 3 || ini == 4)
    {
        int g1 = cst(1, next);
        int g2 = cst(6, next);
        if(g1 < g2) return {g1, 1};
        return {g2, 6};
    }
    return out;
}

pi price2(int ini, int next)
{
    if(ini == 0 || ini == 3)
    {
        int g1 = cst(1, next);
        int g2 = cst(2, next);
        if(g1 < g2) return {g1, 1};
        return {g2, 2};
        
    }
    else
    {
        int g1 = cst(0, next);
        int g2 = cst(3, next);
        if(g1 < g2) return {g1, 0};
        return {g2, 3};
    }
    
}
void solve()
{
    int n, m; cin >> n >> m;
    if(n >= 4 && m >= 4)
    {
        cout << -1 << endl;
    }
    else if(n == 1 || m == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<int>> a(n, vector<int>(m, 0));
        rep(i, n)
        {
            rep(j, m)
            {
                char c; cin >> c;
                a[i][j] = c - '0';
            }
        }
        if(n==2)
        {
            int best = INFI;
            for(int ini = 0; ini < 4; ++ini)
            {
                int curr = ini;
                int p = 0;
                for(int i = 0; i < m; ++i)
                {
                    // cout << curr << endl;
                    int next = a[0][i] * 2 + a[1][i];
                    pi lol = price2(curr, next); 
                    p += lol.fi;
                    curr = lol.se;
                }
                best = min(best, p);
            }
            cout << best << endl;
        }
        else if (m == 2)
        {
            int best = INFI;
            for(int ini = 0; ini < 4; ++ini)
            {
                int curr = ini;
                int p = 0;
                for(int i = 0; i < n; ++i)
                {
                    int next = a[i][0] * 2 + a[i][1];
                    pi lol = price2(curr, next); 
                    p += lol.fi;
                    curr = lol.se;
                }
                best = min(best, p);
            }
            cout << best << endl;
        }
        else if (n == 3)
        {
            int best = INFI;
            for(int ini = 0; ini < 8; ++ini)
            {
                int curr = ini;
                int p = 0;
                for(int i = 0; i < m; ++i)
                {
                    // cout << curr << endl;
                    int next = a[0][i] * 4 + a[1][i] * 2 + a[2][i];
                    pi lol = price3(curr, next); 
                    p += lol.fi;
                    curr = lol.se;
                }
                best = min(best, p);
            }
            cout << best << endl;
        }
        else
        {
            assert(m==3);
            int best = INFI;
            for(int ini = 0; ini < 8; ++ini)
            {
                int curr = ini;
                int p = 0;
                for(int i = 0; i < n; ++i)
                {
                    int next = a[i][0] * 4 + a[i][1] * 2 + a[i][2];
                    pi lol = price3(curr, next); 
                    p += lol.fi;
                    curr = lol.se;
                }
                best = min(best, p);
            }
            cout << best << endl;
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