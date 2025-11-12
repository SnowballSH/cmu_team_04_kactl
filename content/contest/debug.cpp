template <class T> concept C = !is_same<T, string>::value && !is_same_v<std::remove_all_extents_t<T>, char> && ranges::range<T>;
template <C T> ostream& operator<<(ostream &os, const T &v) {for (auto x : v) os << x << ' '; return os << '\n';}
template <class... T> void pr(T... a) {((cerr << " " << a), ...);}
#define debug(...) cerr << __LINE__ << ": [" << #__VA_ARGS__ << "]\n", pr(__VA_ARGS__, '\n')