#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct Point{
	ll x, y;

	Point() {}

	Point(ll _x, ll _y){
		x = _x;
		y = _y;
	}

	ll operator^(const Point& b) const{
		return x*b.y - y*b.x;
	}

	void print(){
		printf("%lld %lld\n", x, y);
	}
};

int n;
vector<Point> p;

int mod(int i){
	return (i+n)%n;
}

int main(void){
	scanf("%d", &n);

	ll x, y;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &x, &y);
		p.eb(x, y);
	}

	ll ans = LLONG_MAX;
	for(int i = 0; i < n; i++){
		Point u(p[mod(i+1)].x - p[i].x, p[mod(i+1)].y - p[i].y);
		Point v(p[i].x-p[mod(i-1)].x, p[i].y - p[mod(i-1)].y);
		ans = min(ans, abs(u^v));

		// u.print(); v.print();
		// printf("%lld ", ans);

		v = Point(p[mod(i+1)].x - p[mod(i+2)].x, p[mod(i+1)].y - p[mod(i+2)].y);
		ans = min(ans, abs(u^v));

		// printf("%lld\n", ans);
	}

	printf("%lld\n", ans);

	return 0;
}