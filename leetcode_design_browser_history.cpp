class BrowserHistory {
public:
	//instead of list we are using deque
	//because deque support index based accessing
	//whereas list doesnt support index based accessing
	deque<string> q;
	int curr;
    BrowserHistory(string homepage){
    	q.push_back(homepage);
    	curr=0;
    }
    
    void visit(string url){
    	q.erase(q.begin()+curr+1,q.end());
    	q.push_back(url);
    	curr++;
    }
    
    string back(int steps){
    	if(steps<=curr){
    		curr-=steps;
    	}else{
    		curr=0;
    	}
    	return q[curr];
    }
    string forward(int steps){
    	if(q.size()-curr>steps){
    		curr+=steps;
    	}else{
    		curr=q.size()-1;
    	}
    	return q[curr];
    }
};