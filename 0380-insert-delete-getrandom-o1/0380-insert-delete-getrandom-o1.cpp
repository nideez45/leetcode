class RandomizedSet {
public:
    vector<int> v;
    map<int,int> mp;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            v.push_back(val);
            mp[val] = v.size()-1;
            return 1;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        else{
            v[mp[val]] = v[v.size()-1];
            v.pop_back();
            mp[v[mp[val]]] = mp[val];
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int rand_idx = rand()%(v.size());
        return v[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */