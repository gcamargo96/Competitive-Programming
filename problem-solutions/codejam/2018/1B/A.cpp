#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
int t, n, l;
double p[N];
int d[N];
bool flag[N];

void precalc(){
	for(int i = 0; i <= n; i++){
		p[i] = 100.0 * (double(i)/double(n));
	}

	int dist = 1000000;
	for(int i = n; i > 0; i--){
		d[i] = dist++;
		if(p[i] - floor(p[i]) >= 0.5 and p[i-1] - floor(p[i-1]) < 0.5){ // ponto de round up
			dist = 1;
		}
	}
	if(p[1] - floor(p[1]) >= 0.5){
		d[0] = 1;
	}
	else{
		d[0] = dist;
	}

	// for(int i = 0; i <= n; i++){
	// 	printf("%lf ", p[i]);
	// }
	// printf("\n");

	// for(int i = 0; i <= n; i++){
	// 	printf("%d ", d[i]);
	// }
	// printf("\n");
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &l);
	
		precalc();

		int c, tot = 0;
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
		for(int i = 0; i < l; i++){
			scanf("%d", &c);
			tot += c;
			pq.push(ii(d[c], c));
		}

		int falta = n-tot;
		for(int i = 0; i < falta; i++){
			pq.push(ii(d[0], 0));
		}

		while(falta){
			int dist = pq.top().fi;
			int cnt = pq.top().se;
			pq.pop();

			int cur = min(falta, dist);
			falta -= cur;
			cnt += cur;
			pq.push(ii(d[cnt], cnt));
		}

		double ans = 0;
		while(!pq.empty()){
			int cnt = pq.top().se;
			double porc = p[cnt];
			// printf("porc = %lf\n", porc);
			pq.pop();
			
			if(porc - floor(porc) < 0.5){
				ans += floor(porc);
			}
			else{
				ans += ceil(porc);
			}
		}

		printf("Case #%d: %.0lf\n", caso, ans);
	}

	return 0;
}