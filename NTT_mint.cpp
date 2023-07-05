int r[N];
void NTT(mint *a, int lim, int opt) {
	REP(i, lim) {
		if(i < r[i]) swap(a[i], a[r[i]]);
	}
	for(int i = 1; i < lim; i <<= 1) {
		mint wn = fp((opt == 1 ? G : GI), (P - 1) / (i << 1));
		for(int j = 0; j < lim; j += (i << 1)) {
			mint w = 1;
			for(int k = 0; k < i; k++, w =  w * wn) {
				mint x = a[j + k];
				mint y = w * a[j + k + i];
				a[j + k] = x + y;
				a[j + k + i] = x - y;
			}
		}
	}
	if(opt == 1) return;
	int inv = fp(lim, P - 2);
	REP(i, lim) a[i] = a[i] * inv;	
}