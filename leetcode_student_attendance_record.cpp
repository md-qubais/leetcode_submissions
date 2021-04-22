class Solution {
public:
    bool checkRecord(string s){
    	int absent=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='A'){
    			absent++;
    			continue;
    		}
    		if(s[i]=='L'){
    			int j=i;
    			int count=0;
    			while(j<s.length() and s[j]=='L'){
    				j++;
    				count++;
    			}
    			i=j-1;
    			if(count>=3){
    				return false;
    			}
    		}
    	}
    	if(absent>=2){
    		return false;
    	}
    	return true;
    }
};