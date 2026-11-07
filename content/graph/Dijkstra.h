/**
 * Author: Aakash Gokhale
 * Description: Single-source shortest paths with non-negative edge weights.
 * Returns $(dist, from)$: $dist[i]$ is the distance from $s$ to $i$ and $from[i]$
 * the previous node on a shortest path. Unreachable nodes get
 * $dist = $ \texttt{numeric\_limits<T>::max()}; they and $s$ get $from = -1$.
 * Distances have type T (default ll), weights type W.
 * Usage: vector<vector<pair<int, int>>> g(n); g[u].push_back({v, w});
 * auto [dist, from] = dijkstra(g, s);
 * Time: O(E \log V)
 * Status: stress-tested
 */
#pragma once

template <class T = ll, class W>
pair<vector<T>, vi> dijkstra(const vector<vector<pair<int, W>>>& g, int s) {
	vector<T> dist(sz(g), numeric_limits<T>::max());
	vi from(sz(g), -1);
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
	pq.emplace(dist[s] = 0, s);
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dist[u]) continue;
		for (auto [v, w] : g[u]) if (d + w < dist[v]) {
			assert(w >= 0);
			pq.emplace(dist[v] = d + w, v), from[v] = u;
		}
	}
	return {dist, from};
}
