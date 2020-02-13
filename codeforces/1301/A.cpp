#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <string>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uc unsigned char

#define ii pair<int, int>
#define llll pair<ll, ll>

#define vc vector
#define vi vc<int>
#define vll vc<ll>
#define vuc vc<unsigned int>

#define vvi vc<vi>
#define vvll vc<vll>
#define vvuc vc<vuc>

#define print cout << 
#define el endl

#define in cin >>

#define fast cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);


#define gcd __gcd
#define lcm __lcm
#define pc __builtin__popcount

#define ext return 0;

/******************************* CODE HERE *******************************/
int main()
{
    fast
    int t;
    in t;
    int size;
    int j;
    string a, b, c;
    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b >> c;
        size = a.length();
        for (j = 0; j < size && (a[j] == c[j]) || (b[j] == c[j]); ++j);
        if (j < size)
        {
            cout << "NO" << el;
        }
        else
        {
            cout << "YES" << el;
        }
        
    }

    ext
}
