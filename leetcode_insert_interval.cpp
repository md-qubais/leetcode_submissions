class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<pair<int,int>> arr;
        for(int i=0;i<intervals.size();i++){
            arr.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        arr.push_back(make_pair(newInterval[0],newInterval[1]));
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> temp;
        for(int i=0;i<arr.size();i++){
            if(temp.size()==0){
                temp.push_back(arr[i]);
            }else{
                int index=temp.size()-1;
                if(temp[index].second>=arr[i].first and (temp[index].second<=arr[i].second or temp[index].second>=arr[i].second) ){
                    pair<int,int> p;
                    if(temp[index].second<=arr[i].second) p=make_pair(temp[index].first,arr[i].second);
                    if(temp[index].second>=arr[i].second) p=make_pair(temp[index].first,temp[index].second);
                    temp[index]=p;
                }else{
                    temp.push_back(arr[i]);
                }
            }
        }
        for(auto it:temp){
            vector<int> v;
            v.push_back(it.first);
            v.push_back(it.second);
            ans.push_back(v);
        }
        return ans;
    }
};