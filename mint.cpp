struct mint{
	int x;
	mint(int a = 0) {
		x = a;
	}
	bool operator < (const mint &b) const {
		return x < b.x;
	}
	bool operator > (const mint &b) const {
		return x > b.x;
	}
	bool operator == (const mint &b) const {
		return x == b.x;
	}
	bool operator != (const mint &b) const {
		return x != b.x;
	}
	bool operator < (const int &b) const {
		return x < b;
	}
	bool operator > (const int &b) const {
		return x > b;
	}
	bool operator == (const int &b) const {
		return x == b;
	}
	bool operator != (const int &b) const {
		return x != b;
	}
	mint& operator += (const mint &b) {
		int a = (*this).x;
		*this = mint((a + b.x) % P);
		return *this;
	}
	mint& operator -= (const mint &b) {
		int a = (*this).x;
		*this = mint((a - b.x + P) % P);
		return *this;
	}
	mint& operator *= (const mint &b) {
		int a = (*this).x;
		*this = mint((1ll * a * b.x) % P);
		return *this;
	}
	mint& operator /= (const mint &b) {
		int a = (*this).x;
		*this = mint((1ll * a * fp(b.x, P - 2)) % P);
		return *this;
	}
	mint& operator += (const int &b) {
		int a = (*this).x;
		*this = mint((a + b) % P);
		return *this;
	}
	mint& operator -= (const int &b) {
		int a = (*this).x;
		*this = mint((a - b + P) % P);
		return *this;
	}
	mint& operator *= (const int &b) {
		int a = (*this).x;
		*this = mint((1ll * a * b) % P);
		return *this;
	}
	mint& operator /= (const int &b) {
		int a = (*this).x;
		*this = mint((1ll * a * fp(b, P - 2)) % P);
		return *this;
	}
	mint operator + (const mint &b) {
		int a = (*this).x;
		return mint((a + b.x) % P);
	}
	mint operator - (const mint &b) {
		int a = (*this).x;
		return mint((a - b.x + P) % P);
	}
	mint operator * (const mint &b) {
		int a = (*this).x;
		return mint((1ll * a * b.x) % P);
	}
	mint operator / (const mint &b) {
		int a = (*this).x;
		return mint((1ll * a * fp(b.x, P - 2)) % P);
	}
	mint operator + (const int &b) {
		int a = (*this).x;
		return mint((a + b) % P);
	}
	mint operator - (const int &b) {
		int a = (*this).x;
		return mint((a - b + P) % P);
	}
	mint operator * (const int &b) {
		int a = (*this).x;
		return mint((1ll * a * b) % P);
	}
	mint operator / (const int &b) {
		int a = (*this).x;
		return mint((1ll * a * fp(b, P - 2)) % P);
	}
	int val() {
		return x;
	}
};
mint fp(mint x,int y) {
	mint res = 1;
	for(;y;y >>= 1) {
		if(y & 1) res = res * x;
		x = x * x;
	}
	return res;
}
struct Comb{
	int n = 0;
	vector<mint> fac, finv, inv;
	void init(int m) {
		if(m <= n) return;
		fac.resize(m + 1);
		finv.resize(m + 1);
		inv.resize(m + 1);
		fac[0] = 1;
		FOR(i, n + 1, m) {
			fac[i] = fac[i - 1] * i;
		}
		finv[m] = fp(fac[m], P - 2);
		ROF(i, m, n + 1) {
			finv[i - 1] = finv[i] * i;
			inv[i] = finv[i] * fac[i - 1];
		}
		n = m;
	}
	mint com(int n, int m) {
		if (n < m || m < 0) return 0;
		return fac[n] * finv[m] * finv[n - m];
	}
}comb;