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
    int t;
    int d;
    int result;
    int n;
    int input;
    int days;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> d;
        cin >> result;
        for (int j = 1; j < n; ++j)
        {
            cin >> input;
            if (d > 0)
            {
                days = j * input;
                if (days <= d)
                {
                    result += input;
                    d -= days;
                }
                else
                {
                    result += d/j;
                    d = -1;
                }
            }
            
        }
        cout << result << endl;
    }

    ext
}
