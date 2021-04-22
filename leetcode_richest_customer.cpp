class Solution {
public:
    int maximumWealth(vector<vector<int>>&arr) {
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
        	int tot=0;
        	for(int j=0;j<arr[i].size();j++){
        		tot+=arr[i][j];
        	}
        	ans=max(ans,tot);
        }


        return ans;
    }
};