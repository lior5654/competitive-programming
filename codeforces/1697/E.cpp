
/****************************** begin /template.h ******************************/

/***********************************************************************
 * [?] APIO 2021 Template
 * [+] Made By: Lior Yehezkely, FiveSixFiveFour
 * [~] Apples are ORZ
 * *********************************************************************/

/*** begin #define flags ***/
// #define USE_ORDERED_STATISTICS
// #define BIG_BIGINT
/*** end #define flags ***/

/*** begin includes ***/
#include <bits/stdc++.h>

#ifdef USE_ORDERED_STATISTICS
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
#endif

using namespace std;
/*** end includes ***/

/*** begin typedefs ***/
typedef long long int ll;
#ifdef BIG_BIGINT
    typedef __int128_t bigint;
#else
    typedef ll bigint;
#endif
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
typedef long double ld;
template<class T> using func = function<T>;

#ifdef USE_ORDERED_STATISTICS
    typedef tree<
    pl,
    null_type,
    less<pl>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#endif

/*** end typedefs ***/

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
auto dist = uniform_int_distribution<int>(0, INFI); 
auto distll = uniform_int_distribution<ll>(0, INFL); 
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

/****************************** end /template.h ******************************/


/****************************** begin /main.cpp ******************************/


/*** begin #define flags ***/
//#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/

/****************************** begin /math/math.h ******************************/

const ll mod = 998244353;  // CHANGE

ll reduce(ll x) {
    x %= mod;
    if(x < 0) x += mod;
    return x;
}
ll bexp(ll b, ll p) {
    b = reduce(b);
    ll res = 1; ll curr = b;
    while(p) {
        if(p%2) {
            res *= curr; res %= mod;
        }
        curr *= curr; 
        curr %= mod;
        p /= 2LL;
    }
    return res;
}
ll inv(ll x) {
    return bexp(x, mod-2);
}
template<uint32_t world_size> class Combinatorics
{
private:
    ll factorial_cache[world_size+1];
    ll inverse_factorial_cache[world_size+1];
public:
    Combinatorics()
    {
        factorial_cache[0] = 1;
        factorial_cache[1] = 1;
        for(int i = 2; i <= world_size; ++i)
        {
            factorial_cache[i] = factorial_cache[i-1] * i;
            factorial_cache[i] %= mod;
        }
        inverse_factorial_cache[world_size] = inv(factorial_cache[world_size]);
        for(int i = world_size - 1; i >= 0; --i)
        {
            inverse_factorial_cache[i] = (i+1LL) * inverse_factorial_cache[i+1];
            inverse_factorial_cache[i]  %= mod;
        }
    }

    inline ll fact(int x)
    {
        return factorial_cache[x];
    }

    inline ll ifact(int x)
    {
        return inverse_factorial_cache[x];
    }

    inline ll permute(int n, int k)
    {
        if(k > n) return 0;
        return (fact(n) * ifact(n-k)) % mod;
    }
    inline ll choose(int n, int k)
    {
        if(k > n) return 0;
        return (((fact(n) * ifact(k)) % mod) * ifact(n-k)) % mod;
    }
};

inline ll gcd(ll a, ll b) 
{
    return (b == 0) ? a : gcd(b, a % b);
}

inline ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

struct EGCDResult
{
    ll x;
    ll y;
    ll d; 
};

EGCDResult extended_gcd(ll a, ll b) // theorem: there exist x, y such that x*a + y*b == gcd(a, b)
{
    if(b == 0) return EGCDResult{ .x = 1, .y = 0, .d = a };
    EGCDResult next_stage = extended_gcd(b, a % b);
    return EGCDResult{ .x = next_stage.y, .y = next_stage.x - a / b * next_stage.y, .d = next_stage.d };
}

template<uint32_t sieve_size> class FactorSieve
{
public:
    int sieve[sieve_size+1];

    FactorSieve()
    {
        sieve[1] = 1;
        for(int i = 2; i <= sieve_size; ++i)
        {
            if(!sieve[i])
            {
                for(int j = i ; j <= sieve_size; j += i)
                {
                    sieve[j] = i;

                }
            }
        }
    }

    inline vector<pair<int, int>> factor(int x)
    {
        vector<pair<int, int>> factors;
        while(x != 1)
        {
            int cnt = 0;
            int curr = this->sieve[x];
            while(this->sieve[x] == curr)
            {
                cnt++;
                x /= curr;
            }
            factors.emplace_back(curr, cnt);
        }
        return factors;
    }

    void get_divisors(int x, vector<int>& res, int out_factor = 1)
    {
        if(x != 1)
        {
            int cnt = 0;
            int curr = this->sieve[x];
            while(this->sieve[x] == curr)
            {
                cnt++;
                x /= curr;
            }
            for(int chosen_cnt = 0, extra_factor = 1; chosen_cnt <= cnt; ++chosen_cnt, extra_factor *= curr)
            {
                get_divisors(x, res, out_factor * extra_factor);
            }
        }
        else
        {
            return res.push_back(out_factor);
        }
    }
    inline bool is_prime(int x)
    {
        return sieve[x] == x && x != 1;
    }
};

template<uint32_t sieve_size> class BooleanSieve
{
public:
    bitset<sieve_size+1> is_composite;

    BooleanSieve()
    {
        is_composite = 0;
        is_composite[1] = 1;
        for(int i = 2; i <= sieve_size; ++i)
        {
            if(!is_composite[i])
            {
                for(int j = 2*i ; j <= sieve_size; j += i)
                {
                    is_composite[j] = 1;

                }
            }
        }
    }

    inline bool is_prime(int x)
    {
        return !is_composite[x];
    }
};
/****************************** end /math/math.h ******************************/


const int maxn = 105;

Combinatorics<maxn> comb;

struct point_t {
    ll x;
    ll y;
};

int n;
point_t points[maxn];
ll dp[maxn][maxn];

inline ll distance(const point_t& a, const point_t& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void input() {
    cin >> n;
    rep(i, n) {
        cin >> points[i].x >> points[i].y;
    }
}

vector<ll> find_closest_points(int point_index)
{
    vector<ll> closest_points;
    ll best_distance_seen = INFL;
    for(int i = 0; i < n; i++) {
        if(i == point_index) {
            continue;
        }

        ll our_distance = distance(points[point_index], points[i]);
        if(our_distance < best_distance_seen)
        {
            closest_points.clear();
            best_distance_seen = our_distance;
        }
        if(our_distance == best_distance_seen)
        {
            closest_points.push_back(i);
        }
    }
    return closest_points;
}

ll calculate_s_value(int point_index)
{
    vector<ll> s_points = find_closest_points(point_index);
    s_points.push_back(point_index);
    sort(all(s_points));

    if(csz(s_points) > 4) {
        return -point_index - 1;
    }
    ll s_value = 0;
    for(const auto& index: s_points) {
        s_value *= (ll)(n+1);
        s_value += index+1;   
    }

    return s_value;

}

vector<ll> get_s_values()
{
    vector<ll> s_values(n);
    for(int i = 0; i < n; i++)
    {
        s_values[i] = calculate_s_value(i);
    }
    return s_values;
}

ll get_actual_count(ll s_value)
{
    if(s_value < 0)
    {
        return 1;
    }

    ll res = 0;
    while(s_value)
    {
        res += 1;
        s_value /= n+1;
    }
    return res;
}
vector<pair<ll, ll>> get_counts_array()
{
    vector<ll> s_values = get_s_values();
    sort(all(s_values));
    vector<pair<ll, ll>> counts;
    counts.reserve(n);
    int current_count = 1;
    for(int i = 1; i < n; i++)
    {
        if(s_values[i] != s_values[i-1])
        {
        
            counts.push_back({current_count, get_actual_count(s_values[i-1])});
            current_count = 0;
        }
        current_count += 1;
    }
    counts.push_back({current_count, get_actual_count(s_values[n-1])});

    return counts;
}

void calculate_dp(const vector<pair<ll, ll>>& counts)
{
    const int total_elements = csz(counts);
    // Let dp[i][j] be the answer for the problem for the first i elements where j colors exist
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= total_elements; i++)
    {
        ll count = counts[i-1].fi;
        ll actual_count = counts[i-1].se;
        assert(count <= actual_count);
        
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;

            // all in the same color
            if(j > 0 && (count == 1 || count == actual_count))
            {
                dp[i][j] += (((ll)j) * dp[i-1][j-1]) % mod;
                dp[i][j] %= mod;
            } 

            // all different color
            if(j >= count && count > 1)
            {
                dp[i][j] += (comb.permute(j, count) * dp[i-1][j-count]) % mod;
                dp[i][j] %= mod;
            }
        }
    }
}

void solve() {
    input();
    vector<pair<ll, ll>> counts = get_counts_array();


    const int total_elements = csz(counts);
    calculate_dp(counts);


    cout << dp[total_elements][n] << '\n';

}











































signed main()
{
    #ifdef INPUT_FILE
        freopen(INPUT_FILE, "r", stdin);
    #endif
    #ifdef OUTPUT_FILE
        freopen(OUTPUT_FILE, "w", stdout);
    #endif
    GOGOGO
    #ifdef PREC
      cout << fixed << setprecision(PREC);
    #endif
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
            cin >> t;
    #endif
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

/****************************** end /main.cpp ******************************/





