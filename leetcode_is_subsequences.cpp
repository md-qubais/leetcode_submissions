class Solution {
public:
	bool is(string s ,string t){
		if(t.length()==0){
			if(s.length()==0){
				return true;
			}
			return false;
		}
		if(s[0]==t[0]){
			return is(s.substr(1),t.substr(1));
		}

		return is(s,t.substr(1));
	}
    bool isSubsequence(string s, string t){
    	return is(s,t);
    }
};