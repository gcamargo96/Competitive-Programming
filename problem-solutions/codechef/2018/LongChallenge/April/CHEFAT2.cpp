#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 100005;
int n, q;
double p[N];

int main(void){
	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++){
		scanf("%lf", &p[i]);
	}

	int tipo, l, r;
	double t;
	while(q--){
		scanf("%d", &tipo);
	
		if(tipo == 0){
			scanf("%d%d", &l, &r);
			double prob = 1;
			for(int i = l; i <= r; i++){
				prob *= (1.0-p[i]);
			}
			printf("%.7lf\n", prob);
		}
		else{
			scanf("%d%d%lf", &l, &r, &t);
			for(int i = l; i <= r; i++){
				p[i] *= t;
			}			
		}
	}

	return 0;
}