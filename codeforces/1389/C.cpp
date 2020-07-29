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

// LIORZ LIORZ LIORZ LIORZ LIORZ




void solve()
{
    string s; cin >> s;
    vector<int> cnt(10, 0);
    int sz = s.size();
    int mx = 0;
    rep(i, sz)
    {
        cnt[s[i]-'0']++;
        if (cnt[s[i]-'0']>mx)
        {
            mx=cnt[s[i]-'0'];
        }
    }
    int sn = sz - mx;
    // second option is to alternate
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            for(bool state : {false, true})
            {
                bool cs = state;
                int rem = 0;
                for(auto c : s)
                {
                    int val = c-'0';
                    if(cs && val == i || !cs && val == j)
                    {
                        cs = !cs;
                    }
                    else
                    {
                        rem++;
                    }
                    
                }
                if((sz-rem)%2)
                {
                    rem++;
                }
                sn = min(sn, rem);
            }
        }
    }
    sn = min(sn, sz-2);
    cout << sn << endl;

}
int main()
{
    GOGOGO
    int t;
    // t=1;
    cin >> t;
    clrcin
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