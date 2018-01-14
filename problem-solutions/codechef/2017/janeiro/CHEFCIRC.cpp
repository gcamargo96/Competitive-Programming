#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

struct circle{
	double x, y, r;

	circle() {}

	circle(double _x, double _y, double _r){
		x = _x;
		y = _x;
		r = _r;
	}

	bool operator<(const circle& b) const{
		if(r == b.r){
			if(x == b.x){
				return y < b.y;
			}
			return x < b.x;
		}
		return r < b.r;
	}
};

struct point{
	double x, y;

	point() {}

	point(double _x, double _y){
		x = _x;
		y = _y;
	}

	bool operator<(const point& b) const{
		if(x == b.x) return y < b.y;
		return x < b.x;
	}
};

const int N = 502;
int n, m;
point p[N];
map<circle, set<point> > M;

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}

	if(n == 1 or m == 1){
		printf("0.000000\n");
		return 0;
	}
	if(n == 2){
		double d2 = (p[1].x-p[0].x)*(p[1].x-p[0].x) + (p[1].y-p[0].y)*(p[1].y-p[0].y);
		printf("%lf\n", sqrt(d2)/2.0);
		return 0;
	}
	if(m == 2){
		double menor = INF;
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				double d2 = (p[1].x-p[0].x)*(p[1].x-p[0].x) + (p[1].y-p[0].y)*(p[1].y-p[0].y);
				menor = min(menor, d2);
			}
		}
		printf("%lf\n", sqrt(menor)/2.0);
		return 0;
	}

	for(int i = 0; i < n-2; i++){
		for(int j = i+1; j < n-1; j++){
			for(int k = j+1; k < n; k++){
				point p1 = point(p[i].x, p[i].y);
				point p2 = point(p[j].x, p[j].y);
				point p3 = point(p[k].x, p[k].y);

				double ab = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
				double bc = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
				double ca = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));

				double p = (ab + bc + ca)/2.0;
				double S = sqrt(p*(p-ab)*(p-bc)*(p-ca));
				double R = (ab*bc*ca)/(4.0*S);
			
				double y0 = -((p1.x*p1.x - p3.x*p3.x) + (p1.x-p3.x)*(-p1.x*p1.x + p2.x*p2.x - p1.y*p1.y + p2.y*p2.y) + (p1.y*p1.y - p3.y*p3.y))/
					((p1.x-p3.x)*(-p1.y+p2.y) + (p1.y*p1.y - p3.y*p3.y));

				double x0 = -((p1.x*p1.x - p2.x*p2.x) + (p1.y*p1.y - p2.y*p2.y) + (p1.y-p2.y)*y0)/(p1.x-p2.x);

				x0 = round(100*x0)/100.0;
				y0 = round(100*y0)/100.0;
				R = round(100*R)/100.0;

				M[circle(x0,y0,R)].insert(p1);
				M[circle(x0,y0,R)].insert(p2);
				M[circle(x0,y0,R)].insert(p3);
			}
		}
	}

	double res;
	for(auto it = M.begin(); it != M.end(); it++){
		if(it->se.size() >= m){
			res = it->fi.r;
			break;
		}
	}

	printf("%lf\n", res);

	return 0;
}

