class Solution {
public:
    #define ll long long

    ll dp[201][201][201];
    ll mod = 1e9+7;

    ll countPairs(ll i, ll ga,ll gb,vector<int> &nums){
        if(i ==  nums.size()){
            if(ga == gb && ga!=0 ) return 1;
            return 0;
        }
        if(dp[i][ga][gb] != -1) return dp[i][ga][gb];       
        ll ans = countPairs(i+1,ga,gb,nums);
        if(ga == 0)
            ans += countPairs(i+1,nums[i],gb,nums);
        else
            ans += countPairs(i+1,__gcd(ga, (ll)nums[i]),gb,nums);       

        ans%=mod;        

        if(gb == 0)
            ans += countPairs(i+1,ga,nums[i],nums);        

        else
            ans += countPairs(i+1,ga,__gcd(gb,(ll) nums[i]),nums);              

        return dp[i][ga][gb] = ans%mod;

    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return countPairs(0,0,0,nums);

    }
};