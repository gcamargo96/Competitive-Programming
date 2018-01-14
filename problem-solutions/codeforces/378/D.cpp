#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n;
//map<ii, int> dim, sum;
//map<ii, ii> m;
map<ii,ii> dim, mapa;
int v[3];

int main(void){
	scanf("%d", &n);

	int a, b, c;
	For(i,0,n){
		scanf("%d%d%d", &v[0], &v[1], &v[2]);
		sort(v, v+3);
		a = v[0], b = v[1], c = v[2];

		if(c >= dim[mp(a,b)].fi){
			dim[mp(a,b)].se = dim[mp(a,b)].fi;
			dim[mp(a,b)].fi = c;

			mapa[mp(a,b)].se = mapa[mp(a,b)].fi;
			mapa[mp(a,b)].fi = i+1;
		}
		else if(c >= dim[mp(a,b)].se){
			dim[mp(a,b)].se = c;
			mapa[mp(a,b)].se = i+1;
		}

		if(a >= dim[mp(b,c)].fi){
			//printf("a = %d / dim[mp(b,c)].fi = %d\n", a, dim[mp(b,c)].fi);
			dim[mp(b,c)].se = dim[mp(b,c)].fi;
			dim[mp(b,c)].fi = a;
		
			//printf("mapa[mp(b,c)].fi = %d\n", mapa[mp(b,c)].fi);
			mapa[mp(b,c)].se = mapa[mp(b,c)].fi;
			mapa[mp(b,c)].fi = i+1;
		}
		else if(a >= dim[mp(b,c)].se){
			dim[mp(b,c)].se = a;
			mapa[mp(b,c)].se = i+1;
		}

		if(b >= dim[mp(a,c)].fi){
			dim[mp(a,c)].se = dim[mp(a,c)].fi;
			dim[mp(a,c)].fi = b;
			
			mapa[mp(a,c)].se = mapa[mp(a,c)].fi;
			mapa[mp(a,c)].fi = i+1;
		}
		else if(b >= dim[mp(a,c)].se){
			dim[mp(a,c)].se = b;
			mapa[mp(a,c)].se = i+1;
		}
		/*(sum[mp(a,b)] = max(sum[mp(a,b)], dim[mp(a,b)]+c);
		sum[mp(b,c)] = max(sum[mp(b,c)], dim[mp(b,c)]+a);
		sum[mp(a,c)] = max(sum[mp(a,c)], dim[mp(a,c)]+b);	
		
		dim[mp(a,b)] = max(dim[mp(a,b)], c);
		dim[mp(b,c)] = max(dim[mp(b,c)], a);
		dim[mp(a,c)] = max(dim[mp(a,c)], b);
		*/
	}

	int best = 0;
  	ii res;
	printf("\n");
	for(auto it = dim.begin(); it != dim.end(); it++){
		//printf("it->fi.fi = %d / it->fi.se = %d\n", it->fi.fi, it->fi.se);
		//printf("it->se.fi = %d / it->se.fi = %d\n\n", it->se.fi, it->se.se);
		if(best < min(min(it->fi.fi, it->fi.se), it->se.fi + it->se.se)){
			best = min(min(it->fi.fi, it->fi.se), it->se.fi + it->se.se);
			res = mapa[mp(it->fi.fi, it->fi.se)];
			//printf("it->fi.fi = %d / it->fi.se = %d\n", it->fi.fi, it->fi.se);
			//printf("it->se.fi = %d / it->se.fi = %d\n\n", it->se.fi, it->se.se);	
		}
	}

	//printf("best = %d\n", best);
	if(res.fi == 0 or res.se == 0){
		printf("1\n");
		printf("%d\n", max(res.fi, res.se));
	}
	else{
		if(res.fi == res.se){
			printf("1\n");
			printf("%d\n", res.fi);
		}
		else{
			printf("2\n");
			printf("%d %d\n", res.fi, res.se);
		}
	}
	
	return 0;
}

