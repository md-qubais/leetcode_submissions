#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
class StockSpanner {
public:
	vector<int> val;
	stack<int> s;
	StockSpanner() {
        
    }
    int next(int price) {
    	val.push_back(price);
    	while(!s.empty() and val[s.top()]<=price){
    		s.pop();
    	}
    	if(s.empty()){
    	s.push(val.size()-1);
    	return	val.size();
    	}
    	int num=(val.size()-1)-s.top();
    	s.push(val.size()-1);
    	return num;
    }
};

int32_t main(){
	qubais_judge;
	IOS;

    return 0;
}