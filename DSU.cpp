struct DSU{
	vector<int> f;
	int find(int u) {
		if(f[u] == u) return u;
		return f[u] = find(f[u]);
	}
	bool diff(int u, int v) {
		return find(u) != find(v);
	}
	void conc(int u, int v) {
		if(find(u) != find(v)) f[find(u)] = find(v);
	}
	DSU(int n) {
		f = vector<int>(n + 1);
		iota(ALL(f), 0);
	}
};