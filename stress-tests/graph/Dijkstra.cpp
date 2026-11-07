#include "../utilities/template.h"
#include "../../content/graph/Dijkstra.h"

int main() {
	vector<vector<pair<int, int>>> g = {
		{{1, 5}, {2, 20}}, {{2, 2}}, {}, {}
	};
	auto [dist, from] = dijkstra(g, 0);
	assert((from == vi{-1, 0, 1, -1}));
	assert(dist[0] == 0 && dist[1] == 5 && dist[2] == 7);
	assert(dist[3] == numeric_limits<ll>::max());
	g = {{{1, 2'000'000'000}}, {{2, 2'000'000'000}}, {}};
	auto [large, prev] = dijkstra(g, 0);
	assert(large[2] == 4'000'000'000LL && prev[2] == 1);

	const ll INF = LLONG_MAX;
	rep(it, 0, 20000) {
		int n = rand() % 8 + 1, m = rand() % 20;
		vector<vector<pair<int, ll>>> h(n);
		vector<vector<ll>> fw(n, vector<ll>(n, INF));
		rep(i, 0, n) fw[i][i] = 0;
		rep(i, 0, m) {
			int a = rand() % n, b = rand() % n;
			ll w = rand() % 10;
			h[a].push_back({b, w});
			fw[a][b] = min(fw[a][b], w);
		}
		rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
			if (fw[i][k] != INF && fw[k][j] != INF)
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
		int s = rand() % n;
		auto [d, p] = dijkstra(h, s);
		assert(p[s] == -1);
		rep(v, 0, n) {
			assert(d[v] == fw[s][v]);
			if (v == s || d[v] == INF) { assert(p[v] == -1); continue; }
			bool ok = false;
			for (auto [x, w] : h[p[v]]) ok |= x == v && d[p[v]] + w == d[v];
			assert(ok);
		}
	}
	cout << "Tests passed!" << endl;
}
