mint p[N], q[N];
const int N2 = 499122177;
void sqrts(mint *a, mint *b, int d) {
	if(d == 1) {
		b[0] = 1;
		return;
	}
	sqrts(a, b, (d + 1) >> 1);
	int lim = 1, l = 0;
	while(lim < (d << 1)) lim <<= 1, l++;
	REP(i, lim) p[i] = 0;
	REP(i, lim) q[i] = a[i];
	FOR(i, d, lim - 1) q[i] = 0;
	invs(b, p, lim >> 1);
	REP(i, lim) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	NTT(q, lim, 1);
	NTT(p, lim, 1);
	REP(i, lim) q[i] *= p[i];
	NTT(q, lim, -1);
	REP(i, lim) b[i] += q[i];
	REP(i, lim) b[i] *= N2;
	FOR(i, d, lim - 1) b[i] = 0;
}