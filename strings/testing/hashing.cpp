#include <bits/stdc++.h>

using namespace std;

#include "../poly-hash.hpp"

template<typename T> ostream& operator<<(ostream &cout, array<T, 2> const&a){
	cout << "["; 
	for(int i = 0; i < 2; i++){
		if(i) cout << ", ";
		cout << a[i];
	}
	return cout << "]";
}

int main(){
	std::string s1 = "abcdef";
	std::string s2 = "abbdef";
	
	Hashing::HashRange hr1, hr2;
	hr1.add(s1); hr2.add(s2);
	std::array<int, 2> hash1 = hr1.hash(0, 1);
	std::array<int, 2> hash2 = hr2.hash(0, 1);
	cout << hash1 << '\n';
	cout << hash2 << '\n';
	if(hash1[0] == hash2[0] && hash1[1] == hash2[1]) cout << "Same string" << '\n';
	else cout << "Probably different substrings" << '\n';

	cout << Hashing::compute_hash(s1) << '\n';	
	cout << Hashing::compute_hash(s2) << '\n';
}
