var maxn = 1e3 + 5;
var maxs = 1e4 + 5;
var mod = 1e9 + 7;
var n  = parseInt(readline());
var a = readline().split(" ").map(function(x) { return parseInt(x); });
var dp = new Array(maxn).fill(0).map(() => new Array(2* maxs + 5).fill(0));
for(var i = 1; i < n+1; ++i)
{
    for(var s = -1 * maxs; s <= maxs; ++s)
    {
        if((a[i-1]*a[i-1] == s*s))
        {
            dp[i][s+maxs] = 1;
        }
        if(s-a[i-1]>=-maxs)
        {
            dp[i][s+maxs] += dp[i-1][s+maxs-a[i-1]];
        }
        if(s+a[i-1]<=maxs)
        {
            dp[i][s+maxs] += dp[i-1][s+maxs+a[i-1]];
        }
        dp[i][s+maxs]%=mod;
    }
}
var res = 0;
for(var i = 1; i < n + 1; ++i)
{
    res += dp[i][maxs];
    res %= mod;
}
print(res);