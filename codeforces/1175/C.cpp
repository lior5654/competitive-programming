//https://codeforces.com/contest/1175/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
using namespace std;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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


const int maxn = 2e5 + 5;
int a[maxn] = { 0 };

void solve();
int main()
{
    GOGOGO
    int t; cin >> t; while(t--) {solve();}
    BYEBYE
}


void solve()
{
    ordered_set rd;
    int n, k; cin >> n >> k;
    rep(i, n) { cin >> a[i]; rd.insert(a[i]);}
    int l = 1; int h = 1e9;
    int an_answer = -1;
    int the_answer = -1;
    if (k == 0)
    {
        cout << a[0] << endl;
        return;
    }
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int mx = -1;
        // consider every point to be leftmost, and count how many other points are in the range of 2 * mid
        rep(i, n)
        {
            int my_order = rd.order_of_key(a[i]);
            int the_order = rd.order_of_key(a[i] + 2*mid + 1);
            int amount_in_range = the_order - my_order;
            mx = max(mx, amount_in_range);
            if (amount_in_range == k + 1 || amount_in_range == k+2 && rd.find(a[i] - 2 * mid) != rd.end())
            {
                an_answer = a[i] + mid;
            }
        }
        rep(i, n)
        {
            int my_order = rd.order_of_key(a[i] + 1); // include a[i]
            int the_order = rd.order_of_key(a[i] - 2*mid);  // with plus one since I dont want the annoying case of k+2 elements bla bla bla
            int amount_in_range = my_order - the_order;
            mx = max(mx, amount_in_range);
            if (amount_in_range == k + 1 || amount_in_range == k+2 && rd.find(a[i] + 2 * mid) != rd.end())
            {
                an_answer = a[i] - mid;
            }
        }
        if (mx >= k + 1)
        {
            h = mid - 1;
            if (an_answer >= 0)
            {
                the_answer = an_answer;
            }
        }
        else
        {
            l = mid + 1;
        }
        
    }
    cout << the_answer << endl;

}