#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 12;
const double EPS = 1e-6;
int tests, n;
double s, y;
double v[N], d[N], p[N], c[N];

int main(void){
	scanf("%d", &tests);

	while(tests--){
		scanf("%d%lf%lf", &n, &s, &y);

		for(int i = 0; i < n; i++){
			scanf("%lf", &v[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%lf", &d[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%lf", &p[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%lf", &c[i]);
		}

		double cur = 0;
		double ta = y/s; // tempo para o pedestre atravessar
		for(int i = 0; i < n; i++){
			double ti, tf; // tempos que o carro comeca e termina de atravessar
			
			if(d[i] == 1){ // baixo para cima
				p[i] += cur*v[i];
				
				if(p[i] >= 0){ // carro passou ou esta passando
					if(p[i]-c[i] > 0){ // carro ja passou
						ti = tf = DBL_MAX;
					}
					else{ // carro esta passando
						ti = 0;
						tf = (c[i]-p[i])/v[i]; // tempo que demora para o resto do carro passar
					}
				}
				else{ // carro ainda vai passar
					ti = (-p[i])/v[i];
					tf = (-(p[i]-c[i]))/v[i];
				}
			}
			else{ // cima para baixo
				p[i] -= cur*v[i];
				
				if(p[i] <= 0){ // carro passou ou esta passando
					if(p[i]+c[i] < 0){ // carro ja passou
						ti = tf = DBL_MAX;
					}
					else{ // carro esta passando
						ti = 0;
						tf = (c[i]+p[i])/v[i]; // tempo que demora para o resto do carro passar
					}
				}
				else{ // carro ainda vai passar
					ti = p[i]/v[i];
					tf = (p[i]+c[i])/v[i];
				}
			}

			double tc = tf-ti; // tempo que o carro leva para atravessar
			// printf("tc = %lf\n", tc);

			// printf("ti = %.6lf, ta = %.6lf\n", ti, ta);

			if(ti < ta+EPS){ // se o tempo que o carro demora para comecar a passar for menor ou igual ao tempo do pedestre atravessar
				cur += tf;
			}

			cur += ta;
		}

		printf("%.6lf\n", cur);
	}

	return 0;
}