class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    	int i=0;
    	int j=0;
    	string ans="";
    	while(i<word1.length() and j<word2.length()){
    		ans+=word1[i++]+word2[j++];
    	}
    	while(i<word1.length()){
    		ans+=word1[i++];
    	}
    	while(j<word2.length()){
    		ans+=word2[j++];
    	}
    	return ans;
    }
};