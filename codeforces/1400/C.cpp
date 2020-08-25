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























void solve()
{
    string s; cin >> s;
    int x; cin >> x; clrcin
    int n  = s.size();
    vector<char> w(n, 0);
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '0')
        {
            bool good = false;
            if(i>=x)
            {
                w[i-x] = '0';
                good = true;
            }
            if(i<n-x)
            {
                w[i+x]='0';
                good = true;
            }
        }
    }
    rep(i, n)
    {
        if(!w[i])
        {
            w[i] = '1';
        }
    }
    rep(i, n)
    {
        bool good = false;
        if(i>=x && w[i-x] == '1')
        {
            if(s[i] == '0')
            {
                cout << -1 << endl; return;
            }
            good = true;
        }
        if(i<n-x && w[i+x] == '1')
        {
            if(s[i] == '0')
            {
                cout << -1 << endl; return;
            }
            good = true;
        }
        if(!good && s[i] == '1')
        {
            cout << -1 << endl; return;
        }
    }
    /*
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
        {
            if(i>=x && i >= n-x)
            {
                if(w[i-x] == '0')
                {
                    cout << -1 << endl; return;
                }
                w[i-x] = '1';
            }
            else if(i<x && i < n-x)
            {
                if(w[i+x] == '0')
                {
                    cout << -1 << endl; return;
                }
                w[i+x] = '1';
            }
            else if (i >= x && i < n-x)
            {
                if(w[i+x] == '0')
                {
                    if(w[i-x] == '0')
                    {
                        cout << -1 << endl; return;
                    }
                    w[i-x] = '1';
                }
                else
                {
                    w[i+x] = '1';
                }
                
            }
            
        }
    }*/
    for(int i = 0; i < n; ++i)
    {
        cout << w[i];
        
    }
    cout << endl;
}










































int main()
{
    GOGOGO
    int t=1;
    cin >> t; clrcin
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