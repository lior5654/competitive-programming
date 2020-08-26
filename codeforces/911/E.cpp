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

#define IMPOSSIBLE cout << -1 << endl; return;
#define DEBUG cout << "reached-this" << endl;
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

















int n, k; const int maxn = 2e5 + 5; int p[maxn]; stack<int> s;
void solve()
{
    cin >> n >> k; int mex = 1;
    rep(i, k)
        cin >> p[i];
    rep(i, n)
    {
        if(i < k)
        {
            if(p[i] == mex)
            {
                mex++;
                while(!s.empty() && mex <= n && s.top() == mex)
                {
                    s.pop(); ++mex;

                }
            }
            else
                s.push(p[i]);
            
        }
        else
        {
            while(!s.empty() && s.top() == mex)
            {
                s.pop(); ++mex;
            }
            if(s.empty())
            {
                for(int j = n; j >= mex; --j)
                {
                    p[i++] = j;
                }
                mex = n+1; --i; assert(i==n-1);
            }
            else
            {
                if(s.top() < mex)
                {
                    IMPOSSIBLE
                }
                p[i] = s.top() - 1;
                s.push(p[i]);
            }
            

        }
        
    }
    while(!s.empty() && s.top() == mex)
    {
        s.pop(); ++mex;
    }
    if(mex != n+1)
    {
        IMPOSSIBLE
    }
    for(int i = 0; i < n; ++i)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}










































int main()
{
    GOGOGO
    int t=1;
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