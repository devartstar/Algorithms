ll fn(ll i, ll j)
{
    if(i<=mn)
    {
        if(s[j^1][i]=='*')
            return 1;
        return 0;
    }
    ll &ans=dp[i][j];
    if(ans==-1)
    {
        ans=inf;
        ans=2+min(fn(i-1,j),fn(i-1,(j^1)));
        if(s[j^1][i]!='*')
            ans=min(ans,1+fn(i-1,j));
    }
    return ans;
}