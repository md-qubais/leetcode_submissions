class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&arr){
    	vector<int> right(arr.size());//right max val
    	vector<int> left(arr.size());//left max val
    	stack<int> s;//store the values in the stack
    	deque<int> q;//for taking out the left max;
    	for(int i=arr.size()-1;i>=0;i--){
    		while(!s.empty() and s.top()<=arr[i]){
    			s.pop();
    		}
    		if(s.empty()){
    			right[i]=-1;
    		}else{
    			right[i]=s.top();
    		}
    		s.push(arr[i]);
    	}
    	while(!s.empty()){
    		s.pop();
    	}
    	//now storing indices in the stack
    	for(int i=0;i<arr.size();i++){
    		
    	}
    	vector<int> ans(arr.size());
    	for(int i=0;i<arr.size();i++){
    		int n1=right[i];

    	}
    	return ans;
    }
};