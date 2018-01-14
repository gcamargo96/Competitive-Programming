#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define mk make_pair

double PI = acos(-1);

double a[4123];

int main(){

	int n; double R; cin >> n >> R;

	for (int i = 1; i <= n; i++){
		scanf ("%lf", a+i);
	}
	sort(a+1, a+1+n);

	double last_x = a[1];
	double ANS= PI*R*R;
	for (int i = 2; i <= n; i++){
		double curr_x = a[i];

		if (curr_x - last_x < 2*R){
			double x1 = last_x + R;
			double x2 = curr_x - R;
			double d;
			double A;
			double y;

			d = (curr_x - last_x)/2.0;
			y = sqrt(R*R - d*d);
			A = d*y;

		   	/*if (curr_x - last_x >= R){
				
				y1 = sqrt(R*R-xm*xm);
				A = (R-xm)*y1;
			}else {
				xm = (curr_x-last_x)/2.0;
				y1 = sqrt(R*R - xm*xm);
				A = xm*y1;
			}*/

			//double L = 2.0*y;
			//double meuCos = (2*R*R - L*L)/(2*R*R);
			//double meuAng = acos(meuCos);
			double meuAng = 2*atan2(y,d);
			if(meuAng < 0) meuAng += 2*PI;

			double K = R*R*meuAng/2.0; 

			ANS -= (2.0 * (K-A));
		}
		ANS +=  ( (PI*R*R) );
		last_x = a[i];
	}
	printf ("%lf\n", ANS);
}
