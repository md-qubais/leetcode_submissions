class Solution {
public:
    vector<int> replaceElements(vector<int>& arr){
    	vector<int> ans(arr.size());
    	ans[arr.size()-1]=-1;
    	int num=arr[arr.size()-1];
    	for(int i=arr.size()-2;i>=0;i--){
    		ans[i]=num;
    		num=max(num,arr[i]);
    	}
    	return ans;
    }
};