//https://codeforces.com/contest/1382/problem/A
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


// guess a guess a guess a guess a
const int maxn = 1e3 + 5;
const int maxm = 1e3 + 5;
int a[maxn] = { 0 };
int b[maxm] = { 0 };

void solve();
int main()
{
    GOGOGO
    int t; cin >> t; while(t--) {solve();}
    // a-bazinga!
    BYEBYE
}

void solve()
{
    int n, m; cin >> n >> m;
    rep(i, n) {cin >> a[i];}
    int found = -1;
    rep(i, m) {cin >> b[i];
        if(found == -1)
        {
            for(int j = 0; j < n; ++j)
            {
                if (b[i] == a[j])
                {
                    found = j; 
                    break;
                }
            }
        }
    }
    if (found == -1 ) {cout << "NO" << endl;}
    else
    {
        cout << "YES\n1 " << a[found] << endl;
    }
    

}


// A GUESSY!