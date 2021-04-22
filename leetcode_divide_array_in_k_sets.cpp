class Solution {
public:
    bool isPossibleDivide(vector<int>&arr, int k){
    	map<int,int> m;
    	for(auto it:arr){
    		m[it]++;
    	}
    	int tot=0;
    	
    	return tot>=k?true:false;
    }
};