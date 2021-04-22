bool compare(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first>p2.first;
    }
    return p1.second>p2.second;
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>&r, int v, int price, int dis){
        vector<vector<int>> ans;
        for(int i=0;i<r.size();i++){
            if(v==1){
               if(r[i][2]==v and r[i][3]<=price and r[i][4]<=dis){
                  ans.push_back(r[i]);
                }
        }else{
            if( r[i][3]<=price and r[i][4]<=dis){
                  ans.push_back(r[i]);
                }
        }
        }
        vector<pair<int,int>> p;
        for(int i=0;i<ans.size();i++){
            p.push_back(make_pair(ans[i][0],ans[i][1]));
        }
        sort(p.begin(),p.end(),compare);
        vector<int> arr;
        for(auto it:p){
            arr.push_back(it.first);
        }
        return arr;
    }
};