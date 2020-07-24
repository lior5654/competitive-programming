//https://codeforces.com/contest/1384/problem/C
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



// LIOR ORZ ORZ ORZ ORZ ORZ ORZ ORZ XD
const int maxn = 1e5 + 5;
const int maxa = 20;
char a[maxn] = { 0 };
char b[maxn] = { 0 };
vector<int> g[20];
si ag[20];
void solve();
int main()
{
    GOGOGO
    int t; cin >> t;
    // int t = 1;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

void solve()
{
    int n; cin >> n;
    for(int i = 0; i < 20; ++i)
    {
        g[i].clear();
        ag[i].clear();
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ag[a[i]-'a'].insert(i);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
        g[b[i]-'a'].pb(i);
    }
    int res = 0;
    for(int i = 0; i < 20; ++i)
    {
        /*cout << res << endl;
        for(int j = 0; j < n; ++j)
        {
            cout << a[j];
        }
        cout << endl;*/
        // cout << i << endl;
        queue<int> lol;
        bitset<maxa> used = 0;
        for(auto e : g[i])
        {
            if (a[e] > b[e])
            {
                cout << -1 << endl;
                return;
            }
            if(a[e] < b[e] && !used[a[e]])
            {
                lol.push(e);
                used[a[e]] = 1;
            }
        }
        bitset<maxa> seen = 0;
        if(!lol.empty())
        {
            while(!lol.empty())
            {
                int c= lol.front(); lol.pop();
                // cout << c << endl;
                if(!seen[a[c]-'a'])
                {
                    seen[a[c]-'a'] = 1; res++;
                    queue<int> rm;
                    for(auto e : ag[a[c]-'a'])
                    {
                        if(e==c) continue;
                        if (a[e] < b[e])
                        {
                            rm.push(e);
                        }
                    }
                    while(!rm.empty())
                    {
                        int e = rm.front(); rm.pop();
                        ag[a[c]-'a'].erase(e);
                        ag[i].insert(e);
                        a[e] = 'a' + i;
                    }
                    ag[a[c]-'a'].erase(c);
                    ag[i].insert(c);
                    a[c] = 'a' + i;
                }
            }
        }
    }
    cout << res << endl;

}