mint c[N];
void invs(mint *a, mint *b, int d) {
	if(d == 1) {
		b[0] = fp(a[0], P - 2);
		return;
	}
	invs(a, b, (d + 1) >> 1);
	int lim = 1, l = 0;
	while(lim < (d << 1)) lim <<= 1, l++;
	REP(i, lim) c[i] = a[i];
	FOR(i, d, lim - 1) c[i] = 0;
	REP(i, lim) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	NTT(b, lim, 1);
	NTT(c, lim, 1);
	REP(i, lim) b[i] = (mint(2) - c[i] * b[i]) * b[i];
	NTT(b, lim, -1);
	FOR(i, d, lim - 1) b[i] = 0;
}