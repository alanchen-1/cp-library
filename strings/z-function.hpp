#pragma once

template <class S> std::vector<int> z_func(S s){
	int n = (int) s.size();
	std::vector<int> z(n);
	z[0] = n;
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i <= r){
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
			z[i]++;
		}
		if(i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}
