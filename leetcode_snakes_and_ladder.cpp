class Graph{
public:
	map<int,list<int>> l;
	void add_edge(int u,int v){
		l[u].push_back(v);
	}
	int bfs(int start,int n){
		queue<int> q;
		unordered_map<int,int> distance;
		distance[start]=0;
		unordered_map<int,bool> visited;
		q.push(start);
		while(!q.empty()){
			int node=q.front();
			q.pop();
			if(visited[node]) continue;
			visited[node]=true;
			for(auto it:l[node]){
				q.push(it);
                if(visited[it]) continue;
				if(distance[it]==0){
					distance[it]=distance[node]+1;
				}
			    else{
			    	distance[it]=min(distance[it],distance[node]+1);
			    }
			    cout<<it<<" "<<distance[it]<<" "<<node<<endl;
			}
		}
		return distance[n*n];
	}


};
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board){
    	vector<int> edges;
    	edges.push_back(0);
    	for(int i=board.size()-1;i>=0;i--){
    		if(i%2==0){
    			for(int j=board[i].size()-1;j>=0;j--){
    				if(board[i][j]==-1) edges.push_back(0);
    		     	else edges.push_back(board[i][j]);
    			}
    		}else{
    			for(int j=0;j<board[i].size();j++){
    				if(board[i][j]==-1) edges.push_back(0);
    				else edges.push_back(board[i][j]);
    			}	
    		}
    	}
    	int n=board.size();
    	Graph g;
    	for(int i=1;i<=n*n;i++){
    		for(int j=1;j<=6;j++){
                if(i+j>n*n) continue;
                if(edges[i+j]==0 ){
    				g.add_edge(i,i+j);
    			}
    			else{
    				int num=edges[i+j];
    				if(edges[num]!=0 and edges[num]!=num){
    					cout<<num<<" "<<edges[num]<<endl;
                        num=edges[num];
    				}
    				g.add_edge(i,num);
    			}
    		}
    	}
    	int ans=g.bfs(1,n);
    	return ans>0?ans:-1;
    }
};