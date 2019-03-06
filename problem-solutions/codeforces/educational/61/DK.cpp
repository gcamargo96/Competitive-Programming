#include <bits/stdc++.h>
using namespace std;

struct node {
	long long c, b;
	long long lst;

	node () {}
	node (long long _c, long long _b) {
		c = _c; b = _b;
		lst = c / b;
	}

	bool operator < (const node nd) const {
		return lst > nd.lst;
	}

	void add (const long long x) {
		c += x;
		lst = c / b;
	}
};

const int MAXN = 212345;

int n;
long long k;
node v[MAXN];

bool solve (long long x) {

	priority_queue <node> pq;
	
	for (int i = 0; i < n; ++i)
		pq.push (v[i]);

	long long lst;
	node curr;

	for (long long i = 0; i < k; ++i) {
		curr = pq.top();
		pq.pop();

		if (curr.lst >= k) return true;
		if (i > curr.lst) return false;
		curr.add (x);

		pq.push (curr);
	}

	return true;
}

int main () {

	cin >> n >> k;

	for (int i = 0; i < n; ++i) scanf ("%lld", &v[i].c);
	for (int i = 0; i < n; ++i) scanf ("%lld", &v[i].b);
	for (int i = 0; i < n; ++i) v[i].lst = v[i].c / v[i].b;

	long long l = 0, r = 1e13;
	long long best = -1;

	// cout << solve (4) << endl;

	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (solve (mid)) {
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << best << endl;

	return 0;
}