class Solution {
public:
	int count(string s,int i,int j){
		if(i>j){
			return 0;
		}
		if(i==j){
			return 1;
		}
	}
    int countSubstrings(string s){
    	return count(s,0,s.length()-1);
    }
};