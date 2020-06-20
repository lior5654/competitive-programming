//https://codeforces.com/contest/1253/problem/D
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

const int maxn = 2e5 + 5;









class UnionFind
{
public:
    int p[maxn+1] = { 0 }; int rank[maxn+1] = { 0 }; int _n;
    UnionFind(int __n)
    {
        this->_n = __n;
        rep(i, this->_n)
        {this->p[i] = i; this->rank[i] = 1;}
    }

    int find(int x)
    {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool unify(int x, int y)
    {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] > rank[y])
        {
            x += y;
            y  =x - y;
            x -= y;
        }
        if (rank[x] == rank[y]) rank[y]++;
        p[x] = y;


        return true;
    }
};

typedef struct cm
{
    int s; int e;
} cm;

vi g[maxn+1];
int n, m;
vector<cm> mi = {{0, 0} };

int ma[maxn+1] = { 0 };
int main()
{
    GOGOGO
    cin >> n >> m;
    mi.resize(n+1, {0, 0});
    int s, t;
    UnionFind uf(n);
    rep(i, m)
    {
        cin >> s >> t;
        g[s].pb(t);
        g[t].pb(s);
        uf.unify(s, t);

    }
    int r;
    ma[n] = INFI;
    repk(i, 1, n+1)
    {
        r = uf.find(i);
        if (!mi[r].s)
        {
            mi[r].s = i;
        }
    }
    for(int i = n; i > 0; --i)
    {
        r = uf.find(i);
        if (!mi[r].e)
        {
            mi[r].e = i;
        }
    }
    int out = 0;
    sort(all(mi), [](const cm& a, const cm& b) {return a.s < b.s;});
    int next = 0;
    int ce = 0;
    int curr = 0;
    while(next < n)
    {
        curr = next;
        ce = mi[curr].e;
        next++;
        while (next < n && mi[next].s < ce) { ce = max(ce, mi[next].e); ++next;}
        // cout << mi[curr].s << " " << ce << endl;
        for(int i = mi[curr].s; i <= ce; ++i)
        {
            if (uf.unify(i, mi[curr].s))
            {
                ++out;
            }
        }
    }
    cout << out << endl;



    BYEBYE
}