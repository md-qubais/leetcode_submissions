class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>&arr){
    	vector<pair<int,int>> temp;
    	for(int i=0;i<arr.size();i++){
    		temp.push_back(make_pair(arr[i][0],arr[i][1]));
    	}
    	sort(temp.begin(),temp.end());
    	for(auto it:temp){
    		cout<<it.first<<" "<<it.second<<endl;
    	}
    	vector<pair<int,int>> ans;
    	for(int i=0;i<temp.size();i++){
    		if(ans.size()==0){
    			ans.push_back(temp[i]);
    			continue;
    		}
    		int index=ans.size()-1;
    		if(ans[index].first<=temp[i].first and ans[index].second>=temp[i].second){
    			continue;
    		}
    		if(ans[index].first>=temp[i].first and ans[index].second<=temp[i].second){
    			ans[index]=temp[i];
    		}else{
    			ans.push_back(temp[i]);
    		}
    	}
    	return ans.size();
    }
};