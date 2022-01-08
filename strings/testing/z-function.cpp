#include <bits/stdc++.h>

using namespace std;

#include "../z-function.hpp"

int main(){
	cout << "Enter a string. \n";
	string s; cin >> s;
	vector<int> z = z_func(s);
	for(int i = 0; i < s.length(); i++){
		cout << z[i] << ' ';
	}
	cout << '\n';
}

