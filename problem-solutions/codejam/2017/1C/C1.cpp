#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 52;
int t, n, k;
double u;
double p[N];

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &k);
		scanf("%lf", &u);
		
		For(i,0,n){
			scanf("%lf", &p[i]);
		}

		sort(p, p+n);

		For(i,0,n-1){
			if(u == 0) break;
			double add = min(u/(i+1), p[i+1]-p[i]);
			for(int j = 0; j <= i; j++){
				p[j] += add;
				u -= add;
			}
		}

		if(u > 0){
			double add = u/n;
			For(i,0,n){
				p[i] = min(1.0, p[i]+add);
			}
			//u = 0;
		}
		
		double res = 1;
		For(i,0,n){
			res *= p[i];
		}

		printf("Case #%d: %lf\n", caso, res);
	}


	return 0;
}

