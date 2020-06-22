//https://codeforces.com/contest/1355/problem/C
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




ll solve(int dif, int b, int c, int d)
{
    // B ------ C ------- D
    // in max case either z is max or y is max
    int l = max(c - dif, b);
    int h = min(c, d - dif);
    // cout << dif << " " << l << " " << h << endl;
    return max(0, h - l + 1);
    

}

int main()
{
    GOGOGO
    int a, b, c, d; cin >> a >> b >> c >> d;
    // this is a monotonic sequence
    // solve a >= z - y then you are done
    ll curr = 0;
    repk(dif, 0 , a)
    {
        // z - y == d
        curr += solve(dif, b, c, d);

    }
    ll out = curr;
    repk(x, a, b)
    {
        curr += solve(x, b, c, d);
        out += curr;

    }
    cout << out << endl;
    BYEBYE
}