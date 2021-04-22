class Graph{
public:
	unordered_map<int,list<int>> l;
	void add_edge(int u,int v,bool bidir=false){
		l[u].push_back(v);
		if(bidir) l[v].push_back(u);
	}

	bool bfs(int start=0){
		queue<int> q;
		q.push(start);
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;
		while(!q.empty()){
			int node=q.front();
			q.pop();
            cout<<node<<endl;
            if(visited[node]){
				return false;
			}
			visited[node]=true;
			for(auto it:l[node]){
				q.push(it);
				if(parent[node]==0) parent[it]=parent[node]+1;
				else if(parent[node]==1 and parent[it]==1) return false;
				else{
					parent[it]=parent[it];
				} 
			}
		}
		int count=0;
		for(auto it:parent){
			if(parent[it.first]==0){
				count++:
			}
		}
		if(count>1){
			return false;
		}
		return true;
	}
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>&left, vector<int>&right){
    	Graph g;
    	for(int i=0;i<n;i++){
    		if(left[i]!=-1){
    			g.add_edge(i,left[i]);
    		}
    		if(right[i]!=-1){
    			g.add_edge(i,right[i]);
    		}
    	}
    	return g.bfs();
    }
};