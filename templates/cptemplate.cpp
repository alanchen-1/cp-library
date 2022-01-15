#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, n) for (int i = s; i < (n); i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()

template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, true : false; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

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
