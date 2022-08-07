void insert(vector<int> &v,int val){
    v.push_back(val);
    int j = v.size()-1;
    // element inserted at back, now heapify
    while(j>0 && v[j]<v[(j-1)/2]){
        swap(v[j],v[(j-1)/2]);
        j = (j-1)/2;
    }
}

void remove(vector<int> &v){
    int i=0,j=2*i+1;
    
    v[0] = v[v.size()-1];
    //v[v.size()-1] = tmp; don't why it wrong if we swap
    v.pop_back();
    // popped smallest element ,now just heapify
    while(j<v.size()){
        if(v[j]>v[j+1])
            j = j+1;
        
        if(v[i]>v[j]){
            swap(v[i],v[j]);
            i = j;
            j = 2*i+1;
        }
        else{
            break;
        }
    }
    
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> v,ans;
    
    for(auto &it : q){
        
        if(it[0]==0){
            insert(v,it[1]);
        }
        else{
            ans.push_back(v[0]);
            remove(v);
        }
    }
    
    return ans;
    
}
