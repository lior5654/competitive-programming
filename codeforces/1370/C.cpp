//https://codeforces.com/contest/1370/problem/C
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



bool is_prime(int n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}


int main()
{
    GOGOGO
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if (n == 1) { cout << "FastestFinger" << endl;}
        else if (n == 2) {cout << "Ashishgup" << endl;}
        else if (n % 2) {cout << "Ashishgup" << endl;}
        else
        {
            int q = 2;
            while (q < n) {q <<= 1;}
            if (q == n) {cout << "FastestFinger" << endl;}
            else if (!(n % 4)) { cout << "Ashishgup" << endl;}
            else
            {
                if (is_prime(n/2))
                {
                    cout << "FastestFinger" << endl;
                }
                else
                {
                    cout << "Ashishgup" << endl;
                }
                

            }
            
        }
        

    }
    BYEBYE
}