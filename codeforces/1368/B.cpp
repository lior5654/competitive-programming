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




ll k = 0;
const char* ss = "codeforces";
int main()
{
    GOGOGO
    cin >> k;
    int count[10];
    int curr = 0;
    ll amnt = 1;
    for(int i = 0; i < 10; ++i)
    {
        count[i] = 1;
    }
    while (amnt < k)
    {
        count[curr]++;
        if (count[curr] > 1)
        {
            amnt /= count[curr] - 1;
        }
        amnt *= count[curr];
        curr += 1;
        if (curr == 10) {curr = 0;}
    }
    for(int i = 0; i < 10; ++i )
    {
        for(int j = 0; j < count[i]; ++j)
        {
            cout << ss[i];
        }
    }
    cout << endl;
    BYEBYE
}