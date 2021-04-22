class Solution{
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> m;
        for(int i=0;i<allowed.length();i++){
        	m[allowed[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            bool b=false;
        	for(auto it:words[i]){
        		if(m[it]==0){
                    b=true;
        			break;
        		}
        	}
            if(b){
                continue;
            }
            ans++;
        }
        return ans;
    }
};