class Solution {
public:
    int maxProduct(vector<int>&arr){
    	int ans=0;
    	for(int i=0;i<arr.size();i++){
    		for(int j=i+1;j<arr.size();j++){
    			ans=max(ans,(arr[i]-1)*(arr[j]-1));
    		}
    	}
    	return ans;
    }
};