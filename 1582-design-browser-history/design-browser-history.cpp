class BrowserHistory {
public:

    stack<string> backStack;
    stack<string> forwardStack;

    BrowserHistory(string homepage) {
        backStack.push(homepage);
    }
    
    void visit(string url) {
        backStack.push(url);
        while(!forwardStack.empty()){
            forwardStack.pop();
        }
    }
    
    string back(int steps) {
        while(!backStack.empty()&&steps>0){
            forwardStack.push(backStack.top());
            backStack.pop();
            steps--;
        }
        if(backStack.empty()){
            backStack.push(forwardStack.top());
            forwardStack.pop();
        }
        return backStack.top();
    }
    
    string forward(int steps) {
        while(!forwardStack.empty()&&steps>0){
            backStack.push(forwardStack.top());
            forwardStack.pop();
            steps--;
        }
        return backStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */