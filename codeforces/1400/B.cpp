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




















ll p, f, cs, cw, s, w;
/*
bool valid(ll m)
{
    for(ll ts = 0; ts <= min(cs, m); ++ts)
    {
        int tw = m - ts;
        if(ts * s + tw * w <= p + f)
        {

        }
    }
    return false;
}
*/
void solve()
{
    cin >> p >> f >> cs >> cw >> s >> w;
    /*if(s < w)
    {
        swap(cs, cw);
        swap(s, w);
    }
    int l = 1; int h = cs + cw;
    int best = 0;
    while(l <= h)
    {
        int m = l + (h - l) / 2;
        if(valid(m))
        {
            best = m; l = m + 1;
        }
        else
        {
            h = m - 1;
        }
        
    }
    cout << best << endl;*/
    ll best = 0;
    ll curr = 0;
    for(int i = 0; i <= cs; ++i)
    {
        if(i * s > p) break;
        curr = 0;
        ll ls = cs - i;
        ll j = min(cw, (p - i * s) / w);
        ll lw = max((ll)0, cw - j);

        curr = i + j;
        if(s < w)
        {
            ll can = f / s;
            if(can <= ls)
            {
                best = max(best,curr + can);
            }
            else
            {
                best = max(best, curr + ls + min(lw, (f-ls*s)/w) );
            }
            
        }
        else
        {
            ll can = f / w;
            if(can <= lw)
            {
                best = max(best,curr + can);
            }
            else
            {
                best = max(best, curr + lw + min(ls, (f-lw*w)/s) );
            }
        }
        
    }
    cout << best << endl;
}










































int main()
{
    GOGOGO
    int t=1;
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