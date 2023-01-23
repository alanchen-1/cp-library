// for longest decreasing/nonincreasing, reverse input v
int longest_inc(std::vector<int>& v){
    int n = v.size();
    std::vector<int> d;

    for(int i = 0; i < n; i++){
        // upper_bound for nondecreasing, lower_bound for increasing
        std::vector<int>::iterator it = std::upper_bound(d.begin(), d.end(), v[i]);
        if(it == d.end()){
            d.push_back(v[i]);
        }else{
            *it = v[i];
        }
    }
    return d.size();
}
