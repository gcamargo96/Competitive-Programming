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

const int N = 10002;
vector<int> col[N], idx[N];
int n, m, k, x;

void init(){
	For(i,0,N){
		col[i].clear();
		idx[i].clear();
	}
}

int main(void){
	while(scanf("%d%d", &n, &m) != EOF){
		init();

		For(i,1,n+1){
			scanf("%d", &k);
			if(k == 0){
				string s;
				getline(cin, s);
				continue;
			}

			vector<int> pos;
			For(j,0,k){
				scanf("%d", &x);
				pos.pb(x);
				idx[x].pb(i);
			}
			For(j,0,k){
				scanf("%d", &x);
				col[pos[j]].pb(x);
			}
		}

		printf("%d %d\n", m, n);
		For(i,1,m+1){
			if(col[i].size() == 0){
				printf("0\n\n");
				continue;
			}

			printf("%zu ", idx[i].size());
			
			For(j,0,idx[i].size()){
				printf("%d", idx[i][j]);
				if(j < idx[i].size()-1) printf(" ");
			}
			printf("\n");

			For(j,0,col[i].size()){
				printf("%d", col[i][j]);
				if(j < col[i].size()-1) printf(" ");
			}
			printf("\n");
		}

	}

	return 0;
}
