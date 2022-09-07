class Solution {
public:
    // average time complexity is O(n)
    // if pivot splits the array almost half every time we get
    // T(n) = n+T(n/2) 
    // which is n+n/2+n/4+... = 2n which is O(n)
    
    int partition(vector <int> &a,int l,int r,int pidx){
        int pivot = a[pidx];
        // rank is the index of pivot element
        int rank = l;
        for(int i=l;i<=r;i++){
            if(a[i]<pivot) rank++;
         }
        // elements before pivot should have smaller value than pivot and
        // those present after should have larger or equal value to pivot
        swap(a[rank],a[l]);
        int i=l;
        int j = rank+1;
        while(i<rank+l && j<=r){
            while(i<rank+l && a[i]<pivot) i++;
            while(j<=r && a[j]>=pivot) j++;
            if(i<rank && j<=r){
                swap(a[i],a[j]);
                i++;
                j++;
            }
        }
        return rank;
    }
    int quicksort(vector<int> &a,int l,int r,int target_idx){
	if(l<r){
        int pivotidx = l;
		int rank = partition(a,l,r,pivotidx);
        
        // if rank is target_idx then the element present at rank is the answer
        if(rank == target_idx){
            return a[rank];
        }
        else if(rank<target_idx){
        // we have to find in right part
		return quicksort(a,rank+1,r,target_idx);
        }
        else{
        // have to find in left part
		return quicksort(a,l,rank-1,target_idx);
        }
	}
        return a[l];
    }

    int findKthLargest(vector<int>& a, int k) {
        int n = a.size();
        // kth largest will be present at (n-k)th index (0-based)
        return quicksort(a,0,n-1,n-k);
    }
};