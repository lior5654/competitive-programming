// optimizing yovanel's code
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vstr;
typedef vector<vstr> vvstr;
typedef pair<ll, ll> pll;
typedef pair<bool, bool> pb;
typedef pair<ld, ld> pld;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pb> vpb;
typedef vector<vpb> vvpb;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

#define F           first
#define S           second
#define FAST        ios_base::sync_with_stdio(0)
#define FASTIN		cin.tie(0)
#define FASTOUT		cout.tie(0)
#define upmin(a, b) a = min(a, b)
#define upmax(a, b) a = max(a, b)
#define  TER_CHAR '‰'

const ll mod = 1e9 + 7;
const ll big = 1e15;
const int maxn =  3e5 + 5;
const int maxv = 1e6 + 5;
 

vll m[maxv];
bitset<maxv> done = 0;
ll arr[maxn];
void sieve() {
    for(int i = 0; i < maxv; ++i) {
        m[i].clear();
    }
    done = 0;
	for (ll i = 2; i < maxv; i++)
	{
		if (done[i]) continue;
		m[i].push_back(i);
		for (ll j = 2*i; j < maxv; j += i)
		{
			done[j] = true;
			ll curdiv = 0;
			ll jt = j;
			while (jt % i == 0)
			{
				curdiv++;
				jt /= i;
 
            }
			if (curdiv & 0x1) m[j].push_back(i);
		}
	}
 
}
 
void solve()
{
 
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<vll, ll> s;
	for (ll i = 0; i < n; i++) {
		ll cur = arr[i];
		auto it = s.find(m[cur]);
		if (it == s.end())
		{
			s.insert({ m[cur], 1 });
		}
		else (it->second)++;
	}
	ll ans0 = 0;
	ll joiningsum = 0;
	for (const auto& it : s)
	{
		ans0 = max(ans0, it.second);
		if (it.first.size() == 0 || it.second % 2 == 0)
		{
			joiningsum += it.second;
		}
	}
	ll ans1 = joiningsum;
	ans1 = max(ans1, ans0);
	ll q;
	cin >> q;
	while (q--)
	{
		ll pow; cin >> pow;
		if (pow == 0) cout << ans0 << endl;
		else cout << ans1 << endl;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	sieve();
	int test;
	cin >> test;
	while (test--)
	{
		solve();
	}
 
}