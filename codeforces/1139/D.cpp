/*
                            . .  ,  ,
                            |` \/ \/ \,',
                            ;          ` \/\,.
                           :               ` \,/
                           |                  /
                           ;                 :
                          :                  ;
                          |      ,---.      /
                         :     ,'     `,-._ \
                         ;    (   o    \   `'
                       _:      .      ,'  o ;
                      /,.`      `.__,'`-.__,
                      \_  _               \
                     ,'  / `,          `.,'
               ___,'`-._ \_/     `,._        ;
            __;_,'      `-.`-'./ `--.____)
         ,-'           _,--\^-'
       ,:_____      ,-'     \
      (,'     `--.  \;-._    ;
      :    Y      `-/    `,  :
      :    :       :     /_;'
      :    :       |    :
       \    \      :    :
        `-._ `-.__, \    `.
           \   \  `. \     `.
         ,-;    \---)_\ ,','/
         \_ `---'--'" ,'^-;'
         (_`     ---'" ,-')
         / `--.__,. ,-'    \
-hrr-    )-.__,-- ||___,--' `-.
        /._______,|__________,'\
        `--.____,'|_________,-'

                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including

using namespace __gnu_pbds;
using namespace std;


typedef long long int ll;
//typedef __int128_t bigint;
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
pl,
null_type,
less<pl>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


typedef long double ld;
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

const int INFI = 1e9 + 5;
const ll INFL = 1e17 + 5;



template<class T> using func = function<T>;

/************************************ general.hpp begin ************************************/

namespace CompetitiveProgramming
{

using bigint = long long int;
using ll = long long int;
using ftype = long double;
using ld = long double;

namespace IO
{

template<class ElementType> inline void output_array(ElementType* array, uint32_t size)
{
    if(size)
    {
        cout << *array++;
        size--;
        while(size)
        {
            cout << ' ' << *array++;
            --size;
        }
    }
    cout << '\n';
}

template<class Iterator> inline void output_iterator_range(Iterator begin, const Iterator& end)
{
    if(begin != end)
    {
        cout << *begin++;
        while(begin != end)
        {
            cout << ' ' << *begin++;
        }
    }
    cout << '\n';
}

template<class Container> inline void output_container(const Container& container)
{
    output_iterator_range(container.begin(), container.end());
}

template<class ElementType> inline void read_array(ElementType* array, uint32_t size)
{
    while(size)
    {
        cin >> *array++;
        --size;
    }
}

template<class Iterator> inline void read_iterator_range(Iterator begin, const Iterator& end)
{
    while(begin != end)
    {
        cin >> *begin++;
    }
}
template<class Container> inline void read_container(Container& container)  // I dont think this will work for set etc, only std::array, std::vector etc
{
    read_iterator_range(container.begin(), container.end());
}

}

}


using namespace CompetitiveProgramming;
using namespace IO;

/************************************ general.hpp end ************************************/

/************************************ math/modint.hpp begin ************************************/

namespace CompetitiveProgramming
{

namespace Math

{

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}


template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int mod = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

}

}

using namespace Math;

/************************************ math/modint.hpp end ************************************/

/************************************ math/sieve.hpp begin ************************************/

namespace CompetitiveProgramming
{

namespace Math
{

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

}

}

using namespace Math;

/************************************ math/sieve.hpp end ************************************/



  



//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

const int maxm = 1e5 + 5;

FactorSieve<maxm> sieve;
Mint dp[maxm];
vi primes_dividing[maxm];
int m;

int calc(int a, int r, int i=0, int value=1, int sign=-1)
{
    if(i == primes_dividing[a].size())
    {
        if(value == 1) return 0;
        return sign * (r / value);
    }
    else
    {
        return calc(a, r, i+1, value*primes_dividing[a][i], sign*(-1)) + calc(a, r, i+1, value, sign);
    }
}
void solve() {
    cin >> m;

    dp[1] = 1;
    for(int i = 2; i <= m; ++i)
    {
        vpi temp = sieve.factor(i);
        for(const auto& f : temp)
        {
            primes_dividing[i].pb(f.fi);
        }
        assert(primes_dividing[i].size() <= 6); // stupid upper bound
    }
    for(int i = 2; i <= m; ++i)
    {
        dp[i] = m;
        vi my_divisors; sieve.get_divisors(i, my_divisors);
        int my_cnt = 0;
        for(const auto& d : my_divisors)
        {

            int rem = i / d;
            int mx = m / d;
            int d_cnt = mx;
            if(rem != 1)  {
                d_cnt = mx - calc(rem, mx);
            }
            if(d != i)
            {
                dp[i] += d_cnt * dp[d];
            } else {
                my_cnt = d_cnt;
            }
        }
        dp[i] /= m - my_cnt;
    }

    Mint res = 0;
    for(int i = 1; i <= m; ++i)
    {
        res += dp[i];
    }
    res /= m;
    cout << res << '\n';
    

}




signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
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











