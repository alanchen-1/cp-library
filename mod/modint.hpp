const int MAXN = 2 * 1e5; // change 
const int MOD = 1e9 + 7; // 998244353, 1e9 + 9

typedef std::decay<decltype(MOD)>::type mod_t;
struct mi{
    mod_t v;
    explicit operator mod_t() const{
        return v;
    }
    explicit operator bool() const{
        return v != 0;
    }

    // constructors
    mi() {v = 0;}
    mi(const long long & _v){
        v = (-MOD <= _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; 
    }

    // IO
	friend std::istream& operator>>(std::istream& in, mi& a) { 
		long long x; std::cin >> x; 
        a = mi(x); 
        return in; 
    }
	friend std::ostream& operator<<(std::ostream& os, const mi& a) { 
        return os << a.v; 
    }

    // comparisons
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	friend bool operator>(const mi& a, const mi& b) { return a.v > b.v; }
	friend bool operator<=(const mi& a, const mi& b) { return a.v <= b.v; }
	friend bool operator>=(const mi& a, const mi& b) { return a.v >= b.v; }
	mi operator-() const { return mi(-v); }

    // operations
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this; 
    }
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this;
    }
	mi& operator*=(const mi& m) { 
        v = (long long)v * m.v % MOD;
		return *this;
    }

    // mod inv
	friend mi pow(mi a, long long p) {
		assert(p >= 0);
        mi ans = 1;
        while(p){
            if(p & 1) ans *= a;
            a *= a;
            p >>= 1;
        }
		return ans; 
    }
	friend mi inv(const mi& a) {
        assert(a != 0); 
        return pow(a, MOD - 2);
    }

	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

vector<mi> factorial(MAXN);
void fillfactorial(){
    factorial[0] = 1;
    for(int i = 1; i < MAXN + 1; i++){
        factorial[i] = factorial[i - 1] * i;
    }
}

mi choose(int n, int k){
    if (k > n || k < 0) return 0;
    return factorial[n] * inv(factorial[k] * factorial[n - k]);
}
