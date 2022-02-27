#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define all(c) ((c).begin()), ((c).end())
#define csz(c) (c.size())
#define pb push_back

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;

const int maxn = 3e5 + 5;

void solve() {
    int n, m;
    set<pl> bad_pairs;
    vl a;
    vpl compressed_a;
    set<int> frequencies_set;
    vl frequencies_vector;
    vl frequency_to_index;
    vvl sorted_values_by_frequency_index;

    // input
    cin >> n >> m;
    a = vl(n, 0);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        int x, y; cin >> x >> y;
        bad_pairs.insert({min(x,y),max(x,y)});
    }

    // compressing a by frequencies and collecting the unique frequencies to a set
    sort(all(a));
    int curr_count = 0;
    for(int i = 0; i < n; i++) {
        curr_count++;
        if(i == n-1 || a[i+1] != a[i]) {
            compressed_a.pb({a[i], curr_count});
            frequencies_set.insert(curr_count);
            curr_count = 0;
        }
    }

    // compressing the frequencies and making an o(1) frequency to compressed frequency conversion vector
    frequency_to_index = vl(n, -1);
    for(auto e : frequencies_set) {
        frequencies_vector.pb(e);
        frequency_to_index[e] = csz(frequencies_vector) - 1;
    }

    // grouping values by their frequency index and sorting each group non increasingly
    sorted_values_by_frequency_index = vvl(csz(frequencies_vector), vl());
    for(auto e : compressed_a) {
        sorted_values_by_frequency_index[frequency_to_index[e.second]].pb(e.first);
    }
    rep(i, csz(frequencies_vector)) {
        sort(all(sorted_values_by_frequency_index[i]), [&](ll l, ll r) {
            return l > r;
        });
        
    }

    // getting the value of the best choice which is not bad
    ll res = 0; 
    for(int i = 0; i < csz(compressed_a); i++) {
        ll my_value = compressed_a[i].first;
        ll my_frequency = compressed_a[i].second;

        for(int frequency_index = csz(frequencies_vector) - 1; frequency_index >= 0; frequency_index--) {
            ll other_frequency = frequencies_vector[frequency_index];
            
            for(int value_index = 0; value_index < csz(sorted_values_by_frequency_index[frequency_index]); value_index++) {
                ll other_value = sorted_values_by_frequency_index[frequency_index][value_index];
                ll f = (my_value + other_value) * (my_frequency + other_frequency);
                if(f < res) {
                    break;
                }
                if (my_value == other_value) {
                    continue;
                }
                if (bad_pairs.find({min(my_value, other_value), max(my_value, other_value)}) != bad_pairs.end()) {
                    continue;
                }
                res = f;
                break; // critical observation: we don't need to check the other pairs with the higher value index as they are definitely worse
            }
        }
    }

    cout << res << '\n';
    
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}