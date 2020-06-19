//https://codeforces.com/contest/1118/problem/D2
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


const int nax = 2e5 + 5;


int a[nax];


int main()
{
    GOGOGO
    int n, m; cin >> n >> m;
    int su = 0;
    rep(i, n)
    {
        cin >> a[i];
        su += a[i];
    }

    if (su < m)
    {
        cout << -1 << endl;
        BYEBYE
    }
    if (su == m)
    {
        cout << n << endl;
        BYEBYE
    }
    sort(a, a+n);
    reverse(a, a+n);
    // bs
    int l = 1; int h = n;
    int best = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        ll res = 0;
        for(int j = 0; j < n; ++j)
        {
            res += max(0, a[j] - (j / mid));
        }
        if (res >= m)
        {
            best = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }
    cout << best << endl;
    BYEBYE
}