#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int TAM = 10002;
int N, n;
char g[TAM][TAM], **p, **p1, **p2, **p3;

void init(){
	p = (char**) malloc(TAM * sizeof(char*));
	p1 = (char**) malloc(TAM * sizeof(char*));
	p2 = (char**) malloc(TAM * sizeof(char*));
	p3 = (char**) malloc(TAM * sizeof(char*));
	
	For(i,0,TAM){
		p[i] = (char*) malloc(TAM * sizeof(char));
		p1[i] = (char*) malloc(TAM * sizeof(char));
		p2[i] = (char*) malloc(TAM * sizeof(char));
		p3[i] = (char*) malloc(TAM * sizeof(char));
	}
}

void destroy(){
	For(i,0,TAM){
		free(p[i]);
		free(p1[i]);
		free(p2[i]);
		free(p3[i]);
	}

	free(p);
	free(p1);
	free(p2);
	free(p3);
}

int check(char **p){
	int cnt = 0;
	For(i,0,N-n+1){
		For(j,0,N-n+1){
			bool foi = 1;
			For(k,0,n){
				For(l,0,n){
					if(g[i+k][j+l] != p[k][l]) foi = 0;
				}
			}
			if(foi) cnt++;
		}
	}
	return cnt;
}

void rot(char **antes, char **depois){
	For(i,0,n){
		For(j,0,n){
			depois[j][n-i-1] = antes[i][j];
		}
	}
}

void print(char **mat){
	For(i,0,n){
		For(j,0,n){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	init();
	while(scanf("%d%d", &N, &n), n != 0 and N != 0){
		For(i,0,N){
			scanf("%s", g[i]);
		}
		For(i,0,n){
			scanf("%s", p[i]);
		}
		
		int res;
		res = check(p);
		cout << res << " ";
		
		rot(p,p1);
		res = check(p1);
		cout << res << " ";

		//print(p1);
		//printf("\n");

		rot(p1,p2);
		res = check(p2);
		cout << res << " ";
		
		//print(p2);
		//printf("\n");

		rot(p2,p3);
		res = check(p3);
		cout << res;
	
		//print(p3);

		cout << endl;
	}

	destroy();
	return 0;
}
