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

#define int int64_t

vi primeFactors(int n)  
{  
    // Print the number of 2s that divide n  
    vi out;
    while (n % 2 == 0)  
    {  
        out.pb(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            out.pb(i); 
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        out.pb(n);
    return out;  
} 

void solve()
{
    int n, k, l1, r1, l2, r2;
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    if(max(l1, l2) <= min(r1, r2))
    {
        int I =  (min(r1, r2) - max(l1, l2)) * n;
        if(I >= k)
        {
            cout << 0 << endl;
            return;
        }
        int mI = (max(r1, r2) - min(l1, l2)) * n;
        if(mI >= k)
        {
            cout << k - I << endl;
        }
        else
        {
            cout << mI - I + (k - mI) * 2 << endl;
        }
        
    }
    else
    {
        int cost = max(l1, l2) - min(r1, r2);
        int gain = max(r1, r2) - min(l1, l2);
        // cout << cost <<  " " << gain << endl;
        if (gain >= k)
        {
            cout << cost + k << endl;
        }
        else
        {
            int tcost = cost + gain;
            if (cost  < gain)
            {
                if (k >= n * gain)
                {
                    cout << (cost + gain) * n + 2 * (k - n * gain) << endl;
                }
                else
                {
                    int full = k / gain;
                    int leftover = k - full * gain;
                    int add = 0;
                    if(cost < leftover)
                    {
                        add = cost + leftover;
                    }
                    else
                    {
                        add = 2 * leftover;
                    }
                    cout << full * (cost + gain) + add << endl;
                    
                }
                
            }
            else
            {
                cout << tcost + 2 * (k - gain) << endl;
            }
            
            

        }
    }
    
    
}
signed main()
{
    GOGOGO
    int t;
    //t=1
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