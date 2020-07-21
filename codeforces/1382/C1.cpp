//https://codeforces.com/contest/1382/problem/C1
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
    int t; cin >> t; while(t--) {solve();}
    BYEBYE
}

void solve()
{
    int n;
    cin >> n;
    string a, b; cin >> a >> b;
    vector<int> out;
    for(int i = n - 1; i >= 0; --i)
    {
        if (a[i] == b[i]) continue;
        else
        {
            out.push_back(i+1);
            out.push_back(1);
            out.push_back(i+1);
        }
        
    }
    cout << out.size() << " ";
    for(auto c : out)
    {
        cout << c << " ";
    }
    cout << endl;
}