class Solution {
public:
    vector<string> buildArray(vector<int>&arr, int n) {
        vector<string> ans;
        int j=0;
        for(int i=1;i<=n and j<arr.size() ;i++){
        	if(arr[j]==i){
        		j++;
        		ans.push_back("Push");
        	}else{
        		ans.push_back("Push");
        		ans.push_back("Pop");
        	}
        }
        return ans;
    }
};