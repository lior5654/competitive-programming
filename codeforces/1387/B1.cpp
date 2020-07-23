//https://codeforces.com/contest/1387/problem/B1
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long int ll;
#define int ll
const int maxn = 1e5 + 5;
const int maxh = 20;
int n;
bitset<maxn> vis = 0;
vector<int> g[maxn];
int p[maxh][maxn] = { { 0 } };
int d[maxn] = { 0 };
int v[maxn] = { 0 };
int almost[maxn] = { 0 };

void dfs(int c, int pp = -1, int dd=0)
{
    if(pp>0)
    {
        p[0][c] = pp;
    }
    d[c] = dd;
    for(auto e : g[c])
    {
        if (e != pp)
        {
            if(g[e].size() >= 2)
            {
                almost[c]++;
            }
            dfs(e, c,dd+1);
        }
    }
}

void init()
{
    for(int h = 1; h < maxh; ++h)
    {
        for(int i = 1; i <= n; ++i)
        {
            p[h][i] = p[h-1][p[h-1][i]];
        }
    }
}

int raise(int b, int am)
{
    int h = 0;
    while(am)
    {
        if(!b) break;
        if(am%2)
        {
            b = p[h][b];
        }
        am >>= 1;
        ++h;
    }
    return b;
}

int lca(int a, int b)
{
    if(a==b) return a;
    if(d[a] > d[b])
    {
        swap(a,b);
    }
    b = raise(b, d[b] - d[a]);
    if(a==b) return a;
    for(int h = maxh - 1; h >= 0; --h)
    {
        if(p[h][b] != p[h][a])
        {
            b = p[h][b];
            a = p[h][a];
        }
    }
    return p[0][b];
    
}


void solve();
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    /*for(int i = 1; i <= n; ++i)
    {
        cout << almost[i] << " ";
    }
    cout << endl;*/ //v
    // init();
    solve();

    return 0;
}

void solve()
{
    ll cost = 0;
    queue<int> qal;
    int left = n;
    for(int i = 1; i <= n; ++i)
    {
        if(!almost[i] && (g[i].size() > 1 ||!p[0][i])) // almost a leaf (a claw)
        {
            qal.push(i);
        }
    }
    while(!qal.empty())
    {
        int claw = qal.front(); qal.pop();
        // cout << "N"<<claw<<endl;
        vector<int> good;
        for(auto e: g[claw])
        {
            if (e == p[0][claw]) continue;
            if(!vis[e])
            {
                vis[e] = true;
                good.pb(e);
            }
        }
        if(good.empty()) 
        {
            if(p[0][claw])
            {
                // cout << "P" << p[0][claw] << " " << almost[p[0][claw]] << endl;
                almost[p[0][claw]]--;
                if(!almost[p[0][claw]])
                {
                    qal.push(p[0][claw]);
                }
            }
            continue;
        }
        // cout << "C: " << claw << endl;
        vis[claw] = true;
        left -= good.size() + 1;
        if(left == 1)
        {
            // we have a claw with a crown, we can set the crown to be another leaf lmao
            good.push_back(p[0][claw]);
            vis[p[0][claw]] = true;
            cost += 2 * good.size();
            int next = claw;
            for(auto e : good)
            {
                v[next] = e;
                next = e;
            }
            v[next] = claw;
            left--;
            break;
        }
        else
        {
            cost += 2 * good.size();
            if(good.size() == 1)
            {
                v[good[0]] = claw;
                v[claw] = good[0];
            }
            else
            {
                int next = claw;
                for(auto e : good)
                {
                    v[next] = e;
                    next = e;
                }
                v[next] = claw;
            }
            if(p[0][claw])
            {
                // cout << "P" << p[0][claw] << " " << almost[p[0][claw]] << endl;
                almost[p[0][claw]]--;
                if(!almost[p[0][claw]])
                {
                    qal.push(p[0][claw]);
                }
            }
            
        }
        
    }
    cout << cost << endl;
    for(int i = 1; i <= n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}