class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
      i=0;
    }
    
    int next(int price) {
        
        while(!st.empty() and st.top().first<=price){
            st.pop();
        }
        
        i++;
        int result=st.empty()?i:i-st.top().second;
        st.push({price,i});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */