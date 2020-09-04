#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ

ll sd(ll i)
{
    ll res = 0;
    while(i)
    {
        res += i % 10;
        i /= 10;
    }
    return res;
}
ll upd(ll i)
{
    string lol = to_string(i); reverse(all(lol));
    int cnt = 0;
    ll whatf = 0;
    ll mul = 1;
    for(auto e : lol)
    {
        if(e!='0')
        {
            whatf = e - '0';
            break;
        }
        cnt++;
        mul *= 10LL;
    }
    return i + mul * (10 - whatf);
}
void solve()
{
    ll n, s; cin >> n >> s;
    ll cost = 0;
    while(true)
    {
        if(sd(n) <= s)
        {
            cout << cost << endl; break;
        }
        ll next = upd(n);
        cost += next - n;
        n = next;
    }
    /*ll digits = log10l(n) + 1;
    string lol = to_string(n);
    vector<int> pre;
    pre.pb(0);
    int i = 0;
    ll ans = lol.size();
    for(auto e : lol)
    {
        pre.pb(pre[pre.size()-1] + e-'0');
    }
    reverse(all(pre));
    for(int i = 0; i < lol.size(); ++i)
    {
        if(pre[i] <= s)
        {

        }
    }*/


}
int main()
{
    GOGOGO
    int t;
    //t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/