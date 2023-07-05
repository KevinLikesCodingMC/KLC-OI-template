mint stirling(int n, int m) {
	mint res = 0;
	FOR(i, 0, m) {
		mint val = ((m - i) % 2 ? P - 1 : 1);
		val *= fp(i, n);
		val *= comb.finv[i];
		val *= comb.finv[m - i];
		res += val;
	}
	return res;
}