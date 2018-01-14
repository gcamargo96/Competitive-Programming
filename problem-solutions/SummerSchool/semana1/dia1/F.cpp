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

const double EPS = 1e-10;
int t;
double lm, lg;

struct point{
	double x, y;

	point() {}

	point(double _x, double _y){
		x = _x;
		y = _y;
	}

	point operator+(const point& b) const{
		return point(x+b.x, y+b.y);
	}

	point operator-(const point& b) const{
		return point(x-b.x, y-b.y);
	}

	point operator*(double c) const{
		return point(x*c, y*c);
	}
};

double dist(point A, point B){
	return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

double dot(point A, point B){
	return A.x*B.x + A.y*B.y;
}

double cross(point A, point B){
	return A.x*B.y - B.x*A.y;
}

point p[3];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lf%lf", &lm, &lg);
		
		For(i,0,3){
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}

		bool ok = 0;

		point A = p[0], B = p[1], C = p[2];

		if(abs(cross(C-A, C-B)) < EPS){
			if(dist(A,B) > max(lm*lm, (2*lg)*(2*lg)) + EPS){
				printf("NO\n");
				continue;
			}
			if(dist(B,C) > max(lm*lm, (2*lg)*(2*lg)) + EPS){
				printf("NO\n");
				continue;
			}
			if(dist(C,A) > max(lm*lm, (2*lg)*(2*lg)) + EPS){
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			continue;
		}

		For(i,0,3){
			point A = p[i], B = p[(i+1)%3], C = p[(i+2)%3];
			
			if(dist(A, B) > lm*lm + EPS) continue;

			point u = C-A;
			point v = B-A;

			point P = A + v*(dot(u,v)/dot(v,v));
			
			if(P.x < max(A.x, B.x) - EPS and P.x > min(A.x, B.x) + EPS) continue;
			if(P.y < max(A.y, B.y) - EPS and P.y > min(A.y, B.y) + EPS) continue;

			if(dist(P,A) > lm*lm + EPS) continue;
			if(dist(P,B) > lm*lm + EPS) continue;
			
			if(dist(P,C) > lg*lg + EPS) continue;

			ok = 1;
		}

		For(i,0,3){
			point A = p[i], B = p[(i+1)%3], C = p[(i+2)%3];
			
			if(dist(A, B) > (2*lg)*(2*lg) + EPS) continue;

			point u = C-A;
			point v = B-A;

			point P = A + v*(dot(u,v)/dot(v,v));

			if(dist(P,A) > lg*lg + EPS) continue;
			if(dist(P,B) > lg*lg + EPS) continue;

			if(dist(P,C) > lm*lm + EPS) continue;

			ok = 1;
		}

		if(ok) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

