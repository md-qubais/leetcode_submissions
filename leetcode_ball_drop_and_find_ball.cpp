class Solution {
public:
    int findBall(vector<vector<int>>&grid,int i,int j){
	//this is the last case
	if(i==grid.size()-1 and (j==0 or j==grid[0].size()-1)){
		if(j==0 and grid[i][j]==-1){
			return -1;
		}
		if(j==grid[0].size()-1 and grid[i][j]==1){
			return -1;
		}
		
	}
	//this is the last case
	if(i==grid.size()-1){
		if(grid[i][j]==1 and grid[i][j+1]==-1){
			return -1;
		}
		if(grid[i][j]==-1 and grid[i][j-1]==1){
			return -1;
		}
		if(grid[i][j]==1){
			return j+1;
		}
		return j-1;
	}
	//this is the first case
	if(i==0 and (j==0 or j==grid[0].size()-1)){
		if(j==0 and grid[i][j]==-1){
			return -1;
		}
		if(j==grid[0].size()-1 and grid[i][j]==1){
			return -1;
		}
	}
	//check if j==0 or j==grid[0].size()-1
	if(j==0){
		if(grid[i][j]==-1){
			return -1;
		}
	}
	if(j==grid[0].size()-1){
		if(grid[i][j]==1){
			return -1;
		}
	}
	//the middle cases
	if(grid[i][j]==1 and grid[i][j+1]==-1){
		return -1;
	}
	if(grid[i][j]==-1 and grid[i][j-1]==1){
		return -1;
	}
	if(grid[i][j]==1){
		return findBall(grid,i+1,j+1);
	}
	return findBall(grid,i+1,j-1);
}
vector<int> findBall(vector<vector<int>>& grid){
	vector<int> ans(grid[0].size());
	for(int i=0;i<grid[0].size();i++){
		ans[i]=findBall(grid,0,i);
	}
	return ans;
}
};