#include "../utilities/template.h"
#include "../../content/graph/Dijkstra.h"

int main() {
	vector<vector<pair<int, int>>> g = {
		{{1, 5}, {2, 20}}, {{2, 2}}, {}, {}
	};
	auto [dist, from] = dijkstras<ll>(g);
	assert((from == vi{-1, 0, 1, -1}));
	assert(dist[0] == 0 && dist[1] == 5 && dist[2] == 7);
	assert(dist[3] == numeric_limits<ll>::max());
	g = {{{1, 2'000'000'000}}, {{2, 2'000'000'000}}, {}};
	auto [large, prev] = dijkstras<ll>(g);
	assert(large[2] == 4'000'000'000LL && prev[2] == 1);
	cout << "Tests passed!" << endl;
}
