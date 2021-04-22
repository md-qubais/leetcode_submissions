class Solution {
public:
    int minimumMountainRemovals(vector<int>&arr){
        int left_dp[100000]={0};
        int right_dp[100000]={0};
        for(int i=0;i<arr.size();i++){
            int n=0;
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    n=max(n,left_dp[j]);
                }
            }
            left_dp[i]=n+1;
        }

        for(int i=arr.size()-1;i>=0;i--){
            int n=0;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    n=max(n,right_dp[j]);
                }
            }
            right_dp[i]=n+1;
        }
        int ans=0;
        vector<int> indexes;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>=arr[i-1] and arr[i]>=arr[i+1]){
                indexes.push_back(i);
            }
        }
        for(int i=0;i<indexes.size();i++){
            if(left_dp[indexes[i]]>1 and right_dp[indexes[i]]>1)
            ans=max(ans,left_dp[indexes[i]]+right_dp[indexes[i]]-1);
        }
        return arr.size()-ans;
    }
};