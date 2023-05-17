class Solution {
public:
    int dp[31][3001];
    int solve(vector<int>& s,int idx,int a,int b)
    {
        int diff=abs(a-b);
        
        if(idx==s.size())
            return diff ;
        
        if(dp[idx][diff]!=-1)
            return dp[idx][diff];
        
        int k=min(solve(s,idx+1,a+s[idx],b),solve(s,idx+1,a,b+s[idx]));
        
        return dp[idx][diff]=k;
    }
    int lastStoneWeightII(vector<int>& stones) 
    {
        int n=stones.size();
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,0,0);
    }
};
