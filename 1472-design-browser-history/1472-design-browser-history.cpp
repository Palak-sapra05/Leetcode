class BrowserHistory {
private:
stack<string> main, helper;

public:
    BrowserHistory(string homepage) {
        main.push(homepage);
    }
    
    void visit(string url) {
        main.push(url);
        while(!helper.empty()) helper.pop();
    }
    
    string back(int steps) {
        while(steps--){
            if(main.size()==1) break;
            helper.push(main.top());
            main.pop();

        }
        return main.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(helper.empty()) break;
            main.push(helper.top());
            helper.pop();
        }
        return main.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */