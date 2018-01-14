#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;

struct square{
	ll x1, y1, x2, y2;

	square() {}

	square(ll _x1, ll _y1, ll _x2, ll _y2){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

struct evt {
	ll t;
	bool f;
	ll w;
	int id;
	evt(){}
	evt(ll t, bool f, ll w, int id) {
		this->t = t;
		this->f = f;
		this->w = w;
		this->id = id;
	}
	bool operator< (evt e) const {
		return id < e.id;
	}
};

int cmp(evt a, evt b) {
	if(a.t == b.t) return a.f < b.f;
	return a.t < b.t;
}

square sq[1007];
vector<evt> sweepx, sweepy;

ll fx(ll x){
	// printf("X = %lld\n", x);
	ll aux = 0;
	set<evt> s;

	for(int i = 0; i < sweepx.size(); ++i) {
		evt e = sweepx[i];
		if(e.f == 0) {
			if(e.t >= x) break;
			s.insert(e);
		}
		else {
			if(e.t >= x) break;
			auto it = s.find(evt(0, 0, 0, e.id));
			evt start = *it;
			ll xi = abs(start.t - x);
			ll xf = abs(e.t - x);
			// printf("%lld %lld %lld %lld res = %lld\n", start.t, xi, xf, e.w, e.w * (xi + xf) * abs(xi - xf + 1) / 2);
			aux += e.w * (xi + xf) * abs(xi - xf + 1) / 2;
			s.erase(it);
		}
	}

	for(auto it = s.begin(); it != s.end(); ++it) {
		evt start = *it;
		ll xi = abs(start.t - x);
		ll xf = 0;
		// printf("id = %lld\n", start.id);
		// printf("%lld %lld %lld %lld res = %lld\n", start.t, xi, xf, start.w, start.w * (xi + xf) * abs(xi - xf + 1) / 2);
		aux += start.w * (xi + xf) * abs(xi - xf + 1) / 2;
	}

	s.clear();

	for(int i = sweepx.size()-1; i >= 0; --i) {
		evt e = sweepx[i];
		if(e.f == 1) {
			if(e.t <= x) break;
			s.insert(e);
		}
		else {
			if(e.t <= x) break;
			auto it = s.find(evt(0, 0, 0, e.id));
			evt start = *it;
			assert(it != s.end());
			ll xi = abs(start.t - x);
			ll xf = abs(e.t - x);
			// printf("%lld %lld %lld %lld res = %lld\n", start.t, xi, xf, e.w, e.w * (xi + xf) * abs(xi - xf + 1) / 2);
			aux += e.w * (xi + xf) * abs(xi - xf + 1) / 2;
			s.erase(it);
		}
	}

	for(auto it = s.begin(); it != s.end(); ++it) {
		evt start = *it;
		ll xi = abs(start.t - x);
		ll xf = 0;
		// printf("%lld %lld %lld %lld res = %lld\n", start.t, xi, xf, start.w, start.w * (xi + xf) * abs(xi - xf + 1) / 2);
		aux += start.w * (xi + xf) * abs(xi - xf + 1) / 2;
	}

	// printf("ans = %lld\n", aux);
	return aux;
}

ll fy(ll y){
	// printf("Y = %lld\n", y);

	ll ans = 0;
	set<evt> s;
	for(int i = 0; i < sweepy.size(); ++i) {
		evt e = sweepy[i];
		if(e.f == 0) {
			if(e.t >= y) break;
			s.insert(e);
		}
		else {
			if(e.t >= y) break;
			auto it = s.find(evt(0, 0, 0, e.id));
			evt start = *it;
			ll yi = abs(start.t - y);
			ll yf = abs(e.t - y);
			ans += e.w * (yi + yf) * abs(yi - yf + 1) / 2;
			s.erase(it);
		}
	}

	for(auto it = s.begin(); it != s.end(); ++it) {
		evt start = *it;
		ll yi = abs(start.t - y);
		ll yf = 0;
		ans += start.w * (yi + yf) * abs(yi - yf + 1) / 2;
	}

	s.clear();

	for(int i = sweepy.size()-1; i >= 0; --i) {
		evt e = sweepy[i];
		if(e.f == 1) {
			if(e.t <= y) break;
			s.insert(e);
		}
		else {
			if(e.t <= y) break;
			auto it = s.find(evt(0, 0, 0, e.id));
			evt start = *it;
			ll yi = abs(start.t - y);
			ll yf = abs(e.t - y);
			ans += e.w * (yi + yf) * abs(yi - yf + 1) / 2;
			s.erase(it);
		}
	}

	for(auto it = s.begin(); it != s.end(); ++it) {
		evt start = *it;
		ll yi = abs(start.t - y);
		ll yf = 0;
		ans += start.w * (yi + yf) * abs(yi - yf + 1) / 2;
	}

	// printf("ans = %lld\n", ans);

	return ans;
}

pair<ll, ll> ternary_x(ll l, ll r){
	ll mi1 = (l+r)/2;
	ll mi2 = mi1 + 1;

	while(l < r){
		mi1 = (l + r)/2;
		mi2 = mi1 + 1;
		if(fx(mi1) <= fx(mi2)){
			r = mi1;
		}
		else{
			l = mi2;
		}
	}

	return make_pair(l, fx(l));
}

pair<ll, ll> ternary_y(ll l, ll r){
	ll mi1 = (l+r)/2;
	ll mi2 = mi1 + 1;

	while(l < r){
		mi1 = (l + r)/2;
		mi2 = mi1 + 1;

		if(fy(mi1) <= fy(mi2)){
			r = mi1;
		}
		else{
			l = mi2;
		}
	}
	return make_pair(l, fy(l));
}


int main() {
	int r;
	cin >> r;

	for(int i = 0; i < r; ++i) {
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		sweepx.pb(evt(x1, 0, abs(y1 - y2)+1, i));
		sweepx.pb(evt(x2, 1, abs(y1 - y2)+1, i));
		sweepy.pb(evt(y1, 0, abs(x1 - x2)+1, i));
		sweepy.pb(evt(y2, 1, abs(x1 - x2)+1, i));

		sq[i] = square(x1, y1, x2, y2);

	}

	sort(sweepy.begin(), sweepy.end(), cmp);
	sort(sweepx.begin(), sweepx.end(), cmp);

	ll best = 4000000000000000000LL;
	pair<ll, ll> ans;

	for(int i = 0; i < r; ++i) {
		pair<ll, ll> distx = ternary_x(sq[i].x1, sq[i].x2);
		pair<ll, ll> disty = ternary_y(sq[i].y1, sq[i].y2);
		// printf("%lld %lld %lld\n", distx.fi, disty.fi, distx.se + disty.se);
		if(distx.se + disty.se < best or (distx.se + disty.se == best && distx.fi < ans.fi) or (distx.fi == ans.fi && distx.se + disty.se == best && disty.fi < ans.se)) {
			best = distx.se + disty.se;
			ans = make_pair(distx.fi, disty.fi);
		}

	}

	cout << best << endl;
	cout << ans.fi << " " << ans.se << endl;
}