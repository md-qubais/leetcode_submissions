class Solution {
public:
    int rob(vector<int>& nums){
        int dp[1000]={0};
        for(int i=0;i<nums.size();i++){
            dp[i]=nums[i];
        }
        if(nums.size()==1){
            return nums[nums.size()-1];
        }
        int ans=0;
        for(int i=nums.size()-1;i>=1;i--){
            for(int j=i-2;j>=0;j--){
                if(i==nums.size()-1 and j==0){
                    continue;
                }
                dp[j]+=nums[i];
            }
            for(int k=0;k<nums.size();k++){
                cout<<dp[k]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        cout<<endl;
        return ans;
    }
};