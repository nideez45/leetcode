class StockSpanner {
public:
    
    // previous greater element but online
    stack<pair<int,int>> st;
    int days;
    StockSpanner() {
        days = 1;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,days});
            return 1;
        }
        else{
            int sz = st.size();
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            int idx;
            if(!st.empty()){
                idx = st.top().second;
            }
            days++;
            st.push({price,days});
            if(st.size() == 1) return days;
            else if(st.size() == sz+1) return 1;
            else{
                return days-idx;
            }
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */