class NumArray {
public:
    vector<int> nums;
    int n;
    
    int t[200000];
    
    void build(int idx,int l,int r){
        if(l == r){
            t[idx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*idx,l,mid);
        build(2*idx+1,mid+1,r);
        t[idx] = (t[2*idx]+t[2*idx+1]);
    }
    
    void upd(int idx,int l,int r,int pos,int val){
        if(l>pos || r<pos) return;
        if(l == r){
            t[idx] = val;
            nums[pos] = val;
            return;
        }
        int mid = (l+r)/2;
        upd(2*idx,l,mid,pos,val);
        upd(2*idx+1,mid+1,r,pos,val);
        t[idx] = (t[2*idx]+t[2*idx+1]);
    }
    
    int query(int idx,int l,int r,int lq,int rq){
        if(l>rq || lq>r)return 0;
        if(lq<=l && r<=rq) return t[idx];
        int mid = (l+r)/2;
        return query(2*idx,l,mid,lq,rq)+query(2*idx+1,mid+1,r,lq,rq);
    }
    
    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        build(1,0,n-1);
    }
    
    void update(int index, int val) {
        upd(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */