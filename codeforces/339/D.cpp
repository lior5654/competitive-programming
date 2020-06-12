//https://codeforces.com/contest/339/problem/D
#include <bits/stdc++.h> 

using namespace std;

const int N = (1 << 17)  + 5;
const int M = 1e5;
const int ROOT = 1;
int t[4*N];

int a[N + 1];
void build(int pre[], int v, int tl, int tr, int _n)
{
    if (tl > tr) return; // shouldnt happen
    if (tl == tr)
        t[v] = pre[tl];
    else
    {
        int tm = tl + (tr - tl) / 2;
        build(pre, 2*v, tl, tm, _n - 1);
        build(pre, 2*v + 1, tm+1, tr, _n - 1);
        if (_n %2 == 1)
        {
            t[v] = t[2*v] | t[2*v + 1];
        }
        else
        {
            t[v] = t[2*v] ^ t[2*v + 1];
        }
        
    }
    
}

int query(void)
{
    return t[ROOT];
}

void update(int v, int val, int pos, int tl, int tr, int _n)
{
    if (tl == tr)
    {
        t[v] = val;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(2*v, val, pos, tl, tm, _n - 1);
        else
            update(2*v+1, val, pos, tm+1, tr, _n -1 );
        if (_n %2 == 1)
        {
            t[v] = t[2*v] | t[2*v + 1];
        }
        else
        {
            t[v] = t[2*v] ^ t[2*v + 1];
        }
    }
    
}


int n, m;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    int xorr = 0;
    for (int i = 1; i <= (1 << n); ++i)
    {
        cin >> a[i]; xorr ^= a[i];
    }
    build(a, ROOT, 1, (1 << n), n);
    int p, b = 0;
    for(int i = 0; i < m; ++i)
    {
        cin >> p>> b;
        update(ROOT, b, p, 1, (1 << n), n);
        cout << query() << endl;
    }
    return 0;
}