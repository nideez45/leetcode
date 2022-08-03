class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty()){
            st.insert({start,end-1});
            return true;
        }
        auto it = st.lower_bound({end,-1});
        if(it==st.begin()){
            st.insert({start,end-1});
            return true;
        }
        else{
            it--;
            if((*it).second<start){
                st.insert({start,end-1});
                return true;
            }
            else return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */