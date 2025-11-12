/**
 * Author: Aakash Gokhale?
 * Description: Dijkstra's Algorithm. Returns pair of $(dist, from)$.
 * $dist[i]$ is the shortest distance from start to $i$, $from[i]$ is the node before $i$ on a shortest path from start.
 * Time: O(E \log V)
 */
#pragma once

template <class T>
auto dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

  vector<T> dist(ssize(g), numeric_limits<T>::max());
  vector<int> from(ssize(g), -1);

  dist[start] = 0;
  pq.emplace(0, start);

  while (ssize(pq)) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        from[v] = u;
        pq.emplace(dist[v], v);
      }
    }
  }
  return make_pair(dist, from);
}