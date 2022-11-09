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
            days++;
            int ans;
            if(st.size() == 0){
                ans = days;
            }
            else{
                ans = days-st.top().second;
            }
            st.push({price,days});
            return ans;
        }
        return 0;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */