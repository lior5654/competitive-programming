#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef tuple<int, int, int> iii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N = 1e5; const int M = 1e5; const int W = 1e6;
const ll LINF = 1e11 + 5;
int n, m;
vvpll g;
ll d[N+1] = { 0 };
int p[N+1] = { 0 };
bitset<N+1> vis = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n+1);
    ll s, t, w;
    for(int i = 0; i < m; ++i)
    {
        cin >> s >> t >> w;
        g[s].pb(mp(t, w));
        g[t].pb(mp(s, w));
    }
    for(int i = 1; i<=n; ++i)
    {
        d[i] = LINF;
    }
    priority_queue<pll, vpll, greater<pll>> q;
    q.push({0, 1});
    d[1] = 0;
    pll c;
    while (!q.empty())
    {
        c = q.top(); q.pop();
        if (vis[c.se]) continue;
        vis[c.se] = true;
        for(auto ne : g[c.se])
        {
            if (d[c.se] + ne.se < d[ne.fi])
            {
                d[ne.fi] = d[c.se] + ne.se;
                p[ne.fi] = c.se;
                q.push({d[ne.fi], ne.fi});
            }
        }
    }
    if (d[n] == LINF)
    {
        cout << -1 << endl;
    }
    else
    {
        stack<int> pth;
        int co = n;
        while(co)
        {
            pth.push(co);
            co = p[co];
        }
        while(!pth.empty())
        {
            cout << pth.top() << " "; pth.pop();
        }
        cout << endl;
    }
    

    return 0;
}