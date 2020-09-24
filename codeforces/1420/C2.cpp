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
               ___,'`-._ \_/ `,._        ;
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

template<class T> using func = function<T>;

#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)

//#define mp make_pair
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
















class Segtree
{
public:
    int tl, tr, tm;
    Segtree* l; Segtree* r;
    ll mm, mp, pm, pp;
    //ms - end with minus
    // pl - end with plus
    // both start with +
    // you want min aswell?
    // observation: pl would always end with +

    Segtree(int _tl, int _tr)
    {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2;
        mm= mp= pm= pp=0; l=r=0;
    }
    void pull()
    {
        if(!l || !r) return;
        if(tr-tl == 1) // anoying case
        {
            mm=max(l->mm, r->mm);
            mp=l->mm + r->pp;
            pp = max(l->pp, r->pp);
            pm = l->pp + r->mm;
        }
        else if(tr - tl == 2)
        {
            mm=max({l->mm, r->mm, l->mp + r->mm});
            mp=max({l->mp, l->mm + r->pp});
            pm=max({l->pm, l->pp + r->mm});
            pp=max({l->pp, r->pp, l->pm + r->pp});
        }
        else
        {
            mm=max({l->mm, r->mm, l->mm + r->pm, l->mp + r->mm});
            mp=max({l->mp, r->mp, l->mm + r->pp, l->mp + r->mp});
            pm=max({l->pm, r->pm, l->pm + r->pm, l->pp + r->mm});
            pp=max({l->pp, r->pp, l->pp + r->mp, l->pm + r->pp});
        }

    }
    void build(ll a[])
    {
        if(tl == tr)
        {
            mm = -a[tl];
            pp = a[tl];
            mp=0;
            pm=0;
        }
        else
        {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(a); r->build(a);
            pull();
        }
    }
    void update(ll val, ll pos)
    {
        if(tl == tr)
        {
            pp = val;
            mm = -val;
        }
        else
        {
            if (pos <= tm)
            {
                l->update(val, pos);
            }
            else
            {
                r->update(val, pos);
            }
            pull();
            
        }
        
    }
};

















const int maxn = 3e5 + 5;
ll in[maxn];
#define BRUH_WHY_TESTCASES
void solve()
{
    int n, q; cin >> n >> q;
    aread(in, n);
    Segtree* st = new Segtree(0, n-1);
    st->build(in);
    cout << st->pp << '\n';
    for(int i = 0; i < q; ++i)
    {
        int l, r; cin >> l >> r; --l; --r;
        swap(in[l], in[r]);
        st->update(in[l], l);
        st->update(in[r], r);
        cout << st->pp << '\n';
    }

}










































int main()
{
    GOGOGO
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