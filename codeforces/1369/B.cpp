//https://codeforces.com/contest/1369/problem/B

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




void solve();

int main()
{
    GOGOGO
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}


void solve()
{
    int n; cin >>n;
    string s; cin >> s;
    int curr = 0;
    while ( curr < n && s[curr] == '1')
    {
        curr++;
    }
    if (curr == 0)
    {
        while ( curr < n && s[curr] == '0')
        {
            cout << 0;
            curr++;
        }
    }
    if (curr != n)
    {
        if (curr == n) return;
        bool found = false;

        for(int i = curr; i < n; ++i)
        {
            if (found) break;
            found = s[i] == '0';
        }
        if (found)
        {
            cout << 0;
        }
    }
    for(int i = n-1; i >= 0 && s[i] == '1'; --i)
    {
        cout << 1;
    }
    cout << endl;
}