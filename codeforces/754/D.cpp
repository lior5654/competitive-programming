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

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_mset;

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














int n, k; const int maxn = 3e5 + 5;

ordered_mset leftPoints;

pl crds[maxn];
bitset<maxn> inc;
bitset<maxn> resbit;
typedef struct ev
{
    int type; ll crd; int id;
    bool operator<(const ev& other) const
    {
        if(crd==other.crd) 
        {
            if(type==-1 && other.type == -1)
            {
                return crds[id].fi > crds[other.id].fi;
            }
            return type>other.type;
        }
        return crd < other.crd;
    }
} ev;
vector<ev> ln;
queue<int> include;
bitset<maxn> dele = 0;
void solve()
{
    cin >> n>> k;
    rep(i, n)
    {
        cin >> crds[i].fi >> crds[i].se;
        ln.pb({1, crds[i].fi, i}); ln.pb({-1, crds[i].se, i});
        
    }
    sort(all(ln));
    int cnt = 0;
    ll res = 0;
    rep(i, k)
    {
        resbit[i] = 1;
    }
    inc = 0;
    for(auto e : ln)
    {
        if(e.type == 1)
        {
            cnt++;
            leftPoints.insert({e.crd, e.id});
            if(cnt<=k)
            {
                inc[e.id] = 1;
            }
            else
            {
                include.push(e.id);
            }
            
        }
        else
        {
            if(cnt >= k)
            {
                assert(!leftPoints.empty());
                bool next = inc[e.id];
                inc[e.id] = 1;
                ll cres = e.crd - max((ll)(*leftPoints.find_by_order(k-1)).fi, crds[e.id].fi) + 1;
                if(cres>=res)
                {
                    res=cres;
                    resbit = inc;
                }
                while(!include.empty() && dele[include.front()]) include.pop();
                if(!include.empty() && next)
                {
                    inc[include.front()] = 1; include.pop();
                }
            }
            cnt--;
            leftPoints.erase({crds[e.id].fi, e.id});
            inc[e.id] = 0;
            dele[e.id] = 1;

        }
        
    }
    cout << res << endl;
    for(int i = resbit._Find_first(); i != maxn; i = resbit._Find_next(i))
    {
        cout << i+1 << " ";
    }
    cout << endl;
}





































signed main()
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