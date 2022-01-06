#include <bits/stdc++.h>

using namespace std;

#include "../sparse-table-general.hpp"
#include "../sparse-table-index.hpp"

void testgeneral(){
	cout << "--------- Testing SparseTable --------- \n";

	cout << "What is the size of the vector? \n";
	int n;
	cin >> n;

	cout << "Enter the vector, separated by whitespace. \n";
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	SparseTable<int> st(v);

	cout << "How many queries would you like to make? \n";
	int q; cin >> q;

	while(q--){
		int l, r;
		cout << "Enter left and right indices. \n";
		cin >> l >> r;
		cout << "min = " << st.query(l, r) << '\n';
	}
}

void testindex(){
	cout << "--------- Testing SparseTableIndex --------- \n";

	cout << "What is the size of the vector? \n";
	int n;
	cin >> n;

	cout << "Enter the vector, separated by whitespace. \n";
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	SparseTableIndex<int> sti(v);

	cout << "How many queries would you like to make? \n";
	int q; cin >> q;

	while(q--){
		int l, r;
		cout << "Enter left and right indices. \n";
		cin >> l >> r;

		cout << "(index, min) = " << "(" << sti.index(l, r) << ", " << sti.query(l, r) << ")" << '\n';
	}
}

int main(){
	testgeneral();
	testindex();
}



