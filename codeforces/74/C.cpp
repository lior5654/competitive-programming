#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;

#define fi first
#define se second
bitset<N> vis = 0;
typedef pair<int, int> ii;


int h, w;
// w -width, h - height


bool valid(ii p);
int pti(ii p);
ii itp(int i);
void dfs(ii p);
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> h >> w;
    int out = 0;
    for(int i = 0; i < (2*h + 2*w - 4); ++i)
    {
        if (!vis[i])
        {
            dfs(itp(i));
            ++out;
        }
    }
    cout << out << endl;

    return 0;
}


int pti(ii p)
{
    if (p == make_pair<int, int>(0, 0)) return 0;
    if (p == make_pair<int, int>(0, w-1)) return w-1;
    if (p == make_pair<int, int>(h-1, w-1)) return h-1 + w-1;
    if (p == make_pair<int, int>(h-1, 0)) return h-1 + w-1 + w-1;
    if (p.fi == 0)
    {
        return p.se;
    }
    if (p.se == w-1)
    {
        return w-1 + p.fi;
    }
    if (p.fi == h-1)
    {
        return w-1 + h-1 + p.se;
    }
    return w-1 + h-1 + w - 1 + p.fi;
}
ii itp(int i)
{
    if (i <= w -1)
    {
        return {0, i};
    }
    if (i <= w-1 + h-1)
    {
        return {i - (w-1), w-1};
    }
    if (i <= w-1 + h-1 + w - 1)
    {
        return {h-1, i - (w-1 + h-1)};
    }
    return {i - (w-1 + h-1 + w-1), 0};

}
bool valid(ii p)
{
    return !(p.fi < 0 || p.fi >= h || p.se < 0 || p.se >= w);
}
void dfs(ii p)
{
    if (!valid(p)) return;
    int i = pti(p);
    if (vis[i]) return;
    vis[i] = true;

    // |/_
    dfs({p.fi+p.se,0});
    dfs({p.fi-(w-1-p.se),w-1});
    dfs({0, p.se+p.fi});
    dfs({h-1, p.se-(h-1-p.fi)});
    // |\_
    dfs({p.fi-p.se ,0});
    dfs({p.fi+(w-1-p.se),w-1});
    dfs({0, p.se-p.fi});
    dfs({h-1, p.se+(h-1-p.fi)});
}
