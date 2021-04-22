vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
	stack<int> s;
	vector<int> ans(nums1.size());
	vector<int> greater(nums2.size());
	for(int i=nums2.size()-1;i>=0;i--){
		while(!s.empty() and s.top()<=nums2[i]){
			s.pop();
		}
		if(!s.empty()){
			greater[i]=-1;
		}else{
			greater[i]=s.top();
		}
		s.push(nums2[i]);
	}
	unordered_map<int,int> m;
	for(int i=0;i<nums2.size();i++){
		m[nums2[i]]=greater[i];
	}
	for(int i=0;i<nums1.size();i++){
		ans[i]=m[nums1[i]];
	}
	return ans;
}