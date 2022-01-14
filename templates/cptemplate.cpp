#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


#define forn(i, s, n) for (int i = s; i < (n); i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, true : false; }
template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

void solve(){
	
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
