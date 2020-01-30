#include <iostream>
#include <vector>
#include <algorithm>
#define int int64_t
#define vi vector<int>
#define loop(i,s,e) for(int i=s;i<e;++i)
using namespace std;

int32_t main(){
    int n,q; cin>>n>>q;
    vi arr(n),pre(n+1);
    loop(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    loop(i,0,q){
        int l,r; cin>>l>>r;
        l--;
        pre[r]--;
        pre[l]++;
    }
    loop(i,0,n) pre[i+1]+=pre[i];
    sort(pre.begin(),pre.end());
    int ans=0;
    loop(i,0,n) ans+=arr[i]*pre[i+1];
    cout<<ans<<endl;
    return 0;
}