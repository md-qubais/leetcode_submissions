class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr){
    	map<int,int> m;
    	int val=*max_element(arr.begin(),arr.end());
    	for(int i=1;i<=arr.size();i++){
    		m[i]=0;
    	}
    	for(auto it:arr){
    		m[it]++;
    	}
    	int dup=-1;
    	int miss=-1;
    	vector<int> ans;
    	for(auto it:m){
    		if(m[it.first]==2){
    			dup=it.first;
    			continue;
    		}
    		if(m[it.first]==0){
    			miss=it.first;
    			continue;
    		}
    		if(dup!=-1 and miss!=-1){
    			ans.push_back(dup);
    			ans.push_back(miss);
    			return ans;
    		}
    	}
    	if(dup!=-1 and miss!=-1){
    			ans.push_back(dup);
    			ans.push_back(miss);
    			return ans;
    	}
    	return ans;
    }
};