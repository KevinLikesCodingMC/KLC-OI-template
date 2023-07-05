template <class T>
struct fenwick {
	vector<T> a;
	int n;
	fenwick(int N) {
		n = N;
		a.resize(n + 1);
	}
	int lowbit(int x) {
		return -x & x;
	}
	T query(int u) {
		T res = 0;
		for(int i = u; i; i -= lowbit(i)) {
			res += a[i];
		}
		return res;
	}
	void modify(int u, int x) {
		for(int i = u; i <= n; i += lowbit(i)) {
			a[i] += x;
		}
	}
	T getsum(int l, int r) {
		return query(r) - query(l - 1);
	}
};
