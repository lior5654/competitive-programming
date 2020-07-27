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

typedef struct inq
{
    int a, t, x;
} inq;




const int maxn = 1e5 + 5;

inq queries[maxn];

set<int> moment_types;
map<int, int> tt;
int __t = 0;
int n;

map<int, int> fen[maxn];
void update(int t, int p, int inc)
{
    if(t==0) return;
    for(int i = t; i <= n; i += i & (-i))
    {
        if(fen[i].find(p) == fen[i].end())
        {
            fen[i].insert({p, 0});
        }
        fen[i][p] += inc;
    }
}
int rquery(int t, int p)
{
    if(t==0) return 0;
    int res = 0;
    for(int i = t; i > 0; i -= i & (-i))
    {
        if(fen[i].find(p) == fen[i].end()){continue;}
        res += fen[i][p];
    }
    return res;
}

int main()
{
    GOGOGO
    int q; cin >> q;
    rep(i, q)
    {
        cin >> queries[i].a >> queries[i].t >> queries[i].x;
        moment_types.insert(queries[i].t);
    } 
    n = moment_types.size();
    for(auto moment : moment_types)
    {
        tt.insert({moment, ++__t});
    }
    // tt is a map between time to a value between 1 to n
    for(int i = 0; i < q; ++i)
    {
        inq query = queries[i];
        if(query.a == 1)
        {
            update(tt[query.t], query.x, 1);
        }
        else if(query.a == 2)
        {
            update(tt[query.t], query.x, -1);
        }
        else
        {
            cout << rquery(tt[query.t], query.x) << endl;
        }
        
    }

    BYEBYE
}




/*


class Segtree
{
public:
    Segtree* l; Segtree* r; int tl, tr, tm;
    map<int, int> val;
    map<int, int> lazy;
    Segtree(int _tl, int _tr)
    {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2; l=r=nullptr;
        val.clear();
    }
    void push()
    {
        if(l==nullptr ||r==nullptr) return;
        for(auto laz : lazy)
        {
            if(l->val.find(laz.))
        }
    }
}*/