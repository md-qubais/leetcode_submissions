class Solution {
public:
    int largestAltitude(vector<int>& gain){
    	int ans=0;
    	int res=0;
    	for(int i=0;i<gain.size();i++){
    		ans+=gain[i];
    		res=max(res,ans);
    	}
    	return res;
    }
};
