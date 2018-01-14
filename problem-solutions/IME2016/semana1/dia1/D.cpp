#include <bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
	
	point() {}

	point(double x, double y){
		this->x = x;
		this->y = y;
	}

	point operator +(const point& b) const{
		return point(x+b.x, y+b.y);
	}

	point operator -(const point& b) const{
		return point(x-b.x, y-b.y);
	}

	double operator *(const point& b) const{
		return x*b.x + y*b.y;
	}

	point operator %(double l) const{
		return point(x*l, y*l);
	}
	
	double operator ^(const point& b) const{
		return x*b.y - y*b.x;
	}
};

struct quad{
	double perimeter, area;
	
	bool operator <(const quad& b) const{
		if(area == b.area) return perimeter > b.perimeter;
		return area > b.area;
	}
};

point A, B, C, D;
double ab, bc, cd, da, an, bn, cn, dn;

int main(void){
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y)){
		if(!A.x and !A.y and !B.x and !B.y and !C.x and !C.y and !D.x and !D.y) break;
		
		point u = C-A;
		point v = D-B;

		double l1, l2;
		l2 = (u^(B-A))/(v^u);
		point N = B + (v%l2);

		ab = sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
		bc = sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
		cd = sqrt((C.x-D.x)*(C.x-D.x)+(C.y-D.y)*(C.y-D.y));
		da = sqrt((D.x-A.x)*(D.x-A.x)+(D.y-A.y)*(D.y-A.y));
		an = sqrt((A.x-N.x)*(A.x-N.x)+(A.y-N.y)*(A.y-N.y));
		bn = sqrt((B.x-N.x)*(B.x-N.x)+(B.y-N.y)*(B.y-N.y));
		cn = sqrt((C.x-N.x)*(C.x-N.x)+(C.y-N.y)*(C.y-N.y));
		dn = sqrt((D.x-N.x)*(D.x-N.x)+(D.y-N.y)*(D.y-N.y));

		quad q[4];
		q[0].perimeter = ab + an + bn;
		q[1].perimeter = bc + bn + cn;
		q[2].perimeter = cd + cn + dn;
		q[3].perimeter = da + dn + an;

		q[0].area = abs(((A-B)^(A-N))*0.5);
		q[1].area = abs(((B-C)^(B-N))*0.5);
		q[2].area = abs(((C-D)^(C-N))*0.5);
		q[3].area = abs(((D-A)^(D-N))*0.5);

		for(int i = 0; i < 4; i++){
			q[i].perimeter = round(1000*q[i].perimeter)/1000;
			q[i].area = round(1000*q[i].area)/1000;
		}

		sort(q, q+4);	

		for(int i = 0; i < 4; i++){
			if(i < 3) printf("%.3lf %.3lf ", abs(q[i].area), abs(q[i].perimeter));
			else printf("%.3lf %.3lf", q[i].area, q[i].perimeter);
		}
		printf("\n");
	}

	return 0;
}
