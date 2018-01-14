#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct point{
	ll x, y, z;

	point() {}

	point(ll x, ll y, ll z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	point operator-(const point& b) const{
		return point(x-b.x, y-b.y, z-b.z);
	}

	point operator^(const point& b) const{
		return point(y*b.z-z*b.y, z*b.x-x*b.z, x*b.y-y*b.x);
	}

	ll operator*(const point& b) const{
		return x*b.x + y*b.y + z*b.z;
	}
};

const int N = 100002;
int n;
int res;
point p[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y >> p[i].z;
	}

	point u = p[1]-p[0];
	point v, w;
	int i;
	for(i = 2; i < n; i++){
		v = p[i]-p[0];
		w = u^v;
		if(w.x or w.y or w.z) break;
	}

	res = 1;
	if(n > 3 and i < n){
		for(int i = 1; i < n; i++){
			v = p[i]-p[0];
			if(v*w != 0){
				res = 0;
				break;
			}
		}
	}

	if(res) cout << "TAK" << endl;
	else cout << "NIE" << endl;

	return 0;
}
