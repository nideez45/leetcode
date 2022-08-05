class MedianFinder {
public:
    
    // maintain first n/2 elements in low and last n/2 elements in high
    // invariant -> if number of elements till now is even, low and high are of same size
    // if number of element till now is odd, low size = high size +1
    
    multiset<int> low;
    multiset<int> high;
    MedianFinder() {
        
    }
    
    // after every insertion, maintaing the invariant
    void balance(){
        
        // size of low should always be high size or high size+1
        if(low.size()<high.size()){
			int x = *high.begin();
			high.erase(high.find(x));
			low.insert(x);
		}
        if(low.size()>high.size()+1){
			int x = *low.rbegin();
			low.erase(low.find(x));
			high.insert(x);
		}
    }
    
    void addNum(int num) {
        if(low.empty()){
            low.insert(num);
        }
        else if(num<=(*low.rbegin())){
            low.insert(num);
        }
        else high.insert(num);
        balance();
    }
    
    double findMedian() {
        int sz = low.size()+high.size();
        if(sz%2){
            return (*low.rbegin());
        }
        else{
            return (*(low.rbegin()) + *(high.begin()))/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */