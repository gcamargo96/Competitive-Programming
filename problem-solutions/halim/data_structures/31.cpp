#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 1000002;
vector<int> g[N];
int n, m, x, k, v;

void init(){
	For(i,0,N){
		g[i].clear();
	}
}

int main(void){
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		
		For(i,1,n+1){
			scanf("%d", &x);
			g[x].pb(i);
		}

		For(i,0,m){
			scanf("%d%d", &k, &v);
			if(g[v].size() < k){
				printf("0\n");
			}
			else{
				printf("%d\n", g[v][k-1]);
			}
		}
	}

	return 0;
}
