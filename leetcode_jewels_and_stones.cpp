class Solution {
public:
    int numJewelsInStones(string jewels, string stones){
    	unordered_map<char,int> m;
    	for(auto it:stones){
    		m[it]++;
    	}
    	int ans=0;
    	for(auto it:jewels){
    		ans+=m[it];
    	}
    	return ans;
    }
};