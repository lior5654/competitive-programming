#include <bits/stdc++.h>
#include <type_traits>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace std;


/*using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/

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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}

/************************************************* BEGIN GEOMETRY TEMPLATE *************************************************/
/************************************************* BEGIN GEOMETRY TEMPLATE *************************************************/
/************************************************* BEGIN GEOMETRY TEMPLATE *************************************************/

// helpful: https://cp-algorithms.com/geometry/basic-geometry.html#toc-tgt-7

/*
Helpful Notes:

vector can be represented with pt.

** dot product **
0. dot(a, b) = a.x * b.x + a.y * b.y
1. a*b = b*a
2. (crd*a)*b = crd*(a*b)
3. (a+b)*c = a*c + b*c
4. norm(v) = v*v
5. abs(v) = sqrt(norm(v)) // length of the vector

** cross product **
0. cross(a, b) = a.x * b.y - a.y * b.x
1. cross(a, b) = -cross(b, a)
2. cross(a, b) == 0 <=> a & b are collinear
3. 
*/


typedef long double ld;

#define EPS ((ld)1e-9)

template<class crd> ll sgn(const crd& x) {
  return x > ((crd)EPS) ? 1 : x < ((crd)-EPS) ? -1 : 0;
}
template<class crd> struct pt
{
    crd x; crd y;
    pt& operator=(const pt& other)
    {
        x=other.x; y=other.y;
        return *this;
    }
    pt& operator+=(const pt& other)
    {
        x+=other.x; y+=other.y;
        return *this;
    }
    pt& operator-=(const pt& other)
    {
        x-=other.x; y-=other.y;
        return *this;
    }
    pt& operator*=(const crd& t)
    {
        x*=t; y*=t;
        return *this;
    }
    pt& operator/=(const crd& t)
    {
        assert(t!=0);
        x/=t; y/=t;
        return *this;
    }
    pt operator+(const pt& other) const
    {
        return pt<crd>(*this) += other;
    }
    pt operator-(const pt& other) const
    {
        return pt<crd>(*this) -= other;
    }
    pt operator*(const crd& t) const
    {
        return pt<crd>(*this) *= t;
    }

    pt operator/(const crd& t) const
    {
        return pt<crd>(*this) /= t;
    }
    operator pt<ld>() const
    {
        pt<ld> newpt;
        newpt.x = this->x; newpt.y = this->y;
        return newpt;
    }
};

template<class crd> pt<crd> operator*(const crd& t, const pt<crd>& pt)
{
    return pt * t;
}

template<class crd> crd dot(const pt<crd>& l, const pt<crd>& r) // dot(l, r) = dot(r, l)
{
    return l.x * r.x + l.y * r.y;
}
template<class crd> crd norm(const pt<crd>& a)
{
    return dot(a, a);
}
template<class crd> ld abs(const pt<crd>& a)
{
    return sqrtl(norm(a));
}
template<class crd> crd cross(const pt<crd>& l, const pt<crd>& r) // cross(l, r) = -cross(r, l)
{
    return l.x * r.y - l.y * r.x;
}

template<class crd> bool upper(const pt<crd>& a) {
  return ((a.y > 0) || (!a.y && a.x > 0));
}

template<class crd> bool operator<(const pt<crd> &a, const pt<crd> &b) {
    if(upper(a) != upper(b)) return upper(a);
    return cross(a, b) > 0;
}

/*
@ brief: find intersection of two lines (or their continuation)
NOTE: will crash due to division by 0 if lines are collinear
*/
pt<ld> intersection(const pt<ld>& a1, const pt<ld>& a2, const pt<ld>& b1, const pt<ld>& b2)
{
    return a1 + ((a2 - a1) * cross(b1 - a1, b2 - b1) / cross(a2 - a1, b2 - b1));
}

template<class crd> bool intersection1d(crd l1, crd r1, crd l2, crd r2)
{
    // note to self: this takes cases of the right and left points of the segment being flipped
    if (l1 > r1)
    {
        r1 += l1;
        l1 = r1 - l1;
        r1 -= l1;
    }
    if (l2 > r2)
    {
        r2 += l2;
        l2 = r2 - l2;
        r2 -= l2;
    }
    return max(l1, l2) <= min(r1, r2) + ((crd)EPS);
} 

/*
@ brief: whether or not two given line segments (a1-a2, b1-b2) intersect
*/
template<class crd> bool segseg(const pt<crd>& a1, const pt<crd>& a2, const pt<crd>& b1, const pt<crd>& b2) {
    return intersection1d(a1.y, a2.y, b1.y, b2.y) && intersection1d(a1.x, a2.x, b1.x, b2.x) && 
        sgn(cross(a1 - b1, b2 - b1)) * sgn(cross(a2 - b1, b2 - b1)) <= 0 &&
        sgn(cross(b1 - a1, a2 - a1)) * sgn(cross(b2 - a1, a2 - a1)) <= 0;
}

/*
@ brief: area of polygon, points ordered by edge order
*/
template<class crd> ld polyarea(const vector<pt<crd>>& points)
{
    int sz = points.size();
    ld res = 0;
    for(int i = 0; i < sz; ++i)
    {
        res += (ld)cross(points[i], points[(i==sz-1)?0:i+1]);
    }
    return abs(res / 2.0);
}    
ld evaluate_line(const pt<ld>& a, const pt<ld>& b, ld x)
{
    if(abs(a.x - b.x) < EPS)
    {
        return a.y;
    }
    return a.y + (b.y - a.y) * (x - a.x) / (b.x - a.x);
}


/********************** bruh **********************/
#define ADD 1
#define REM 0
const int maxn = 25e3 + 5;
int n;

struct car
{
    pt<ld> o; pt<ld> d; ld s; 
} cars[maxn];

typedef struct seg
{
    pt<ld> s; pt<ld> e; int id;// what if two segments are the exact same segments?
} seg; 
bool operator<(const seg& a, const seg& b)
{
    //cerr << "<: " << a.id << " " << b.id << endl;
    // find the x of the latest one that was added and compare ys evaluated at that x
    ld ex = max(min(a.s.x, a.e.x), min(b.s.x, b.e.x));
    
    return evaluate_line(a.s, a.e, ex) < evaluate_line(b.s, b.e, ex) - EPS;
}
seg lines[maxn];
set<seg>::iterator prev(set<seg>::iterator it, const set<seg>& s)
{
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it, const set<seg>& s)
{
    return ++it;
}

typedef struct ev
{
    ld x; 
    int type; 
    int id;

} ev;

bool operator<(const ev& a, const ev& other)
{
    if(abs(a.x - other.x) <= EPS)
    {
        return a.type > other.type;
    }
    return a.x < other.x;
}

set<seg>::const_iterator where[maxn];
bool crash(ld m)
{
    vector<ev> events; // fi - add, se - rem
    for(int i = 0; i < n; ++i)
    {
        lines[i].s = cars[i].o;
        lines[i].e = cars[i].o + cars[i].d * m;
        lines[i].id = i;
        events.push_back(ev{min(lines[i].s.x,lines[i].e.x), ADD, i});
        events.push_back(ev{max(lines[i].s.x,lines[i].e.x), REM, i});
    }
    sort(all(events));
    //cout<<"gi";`
    set<seg> ordering;
    for(auto e : events)
    {
        if(e.type == ADD)
        {
            //cout << "hi";
            set<seg>::iterator up = ordering.lower_bound(lines[e.id]);
            set<seg>::iterator down = prev(up, ordering);
            if(up != ordering.end() && segseg((*up).s, (*up).e, lines[e.id].s, lines[e.id].e))
            {
                return true;
            }
            if(down != ordering.end() && segseg((*down).s, (*down).e, lines[e.id].s, lines[e.id].e))
            {
                return true;
            }
            where[e.id] = ordering.insert(lines[e.id]).fi;
        }
        else
        {
            //cout << "hi";
            // set<seg>::iterator me = ordering.find(lines[e.id]);
            set<seg>::iterator up = next(where[e.id]);
            set<seg>::iterator down = prev(where[e.id]);
            if(up != ordering.end() && down != ordering.end() && segseg((*up).s, (*up).e, (*down).s, (*down).e))
            {
                return true;
            }
            // assert(me!=ordering.end());
            ordering.erase(where[e.id]);
        }
    }
    return false;

    

}



int main()
{
    /*pt<ld> a, b, c, d;
    a.x = 0;
    a.y = 0;
    b.x = 2;
    b.y = 2;
    c.x = 0.5;
    c.y = 0.5;
    d.x = 1.5;
    d.y = 1.5;
    cout << (segseg(a, b, c ,d) ? "YES!" : "FUCK ME!") << endl;*/
    const ld pers = 5e-7;
    cout << fixed << setprecision(20);
    //cerr << fixed << setprecision(20);
    cin >> n;
    rep(i, n)
    {
        cin >> cars[i].o.x >> cars[i].o.y >> 
        cars[i].d.x >> cars[i].d.y >> 
        cars[i].s;
        cars[i].d /= abs(cars[i].d);
        cars[i].d *= cars[i].s;
    }
    ld l = EPS; ld h = 1e12;
    if(!crash(h))
    {
        cout << "No show :(" << endl;
    }
    else
    {
        while (h-l > pers)
        {
            ld m = l + (h - l) / 2.0;
            if(crash(m))
            {
                h = m - EPS;
            }
            else
            {
                l = m + EPS;
            }
            
        }
        cout << l << endl;
    }
}