template <class T> concept C = ranges::range<T> && !is_convertible_v<T, string_view>;
template <C T> ostream& operator<<(ostream &os, const T &v) {for (auto&& x : v) os << x << ' '; return os << '\n';}
template <class... T> void pr(const T&... a) {((cerr << " " << a), ...);}
#define debug(...) cerr << __LINE__ << ": [" << #__VA_ARGS__ << "]\n", pr(__VA_ARGS__, '\n')
