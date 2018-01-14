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

int n;
int g1[4][4], g2[4][4];
char c;

void init(){
	For(i,0,3){
		For(j,0,3){
			g1[i][j] = 0;
			g2[i][j] = 0;
		}
	}
}

bool equals(){
	For(i,0,3){
		For(j,0,3){
			if(g1[i][j] != g2[i][j]) return 0;
		}
	}

	return 1;
}

void copy(){
	For(i,0,3){
		For(j,0,3){
			g1[i][j] = g2[i][j];
		}
	}
}

void transform(){
	For(i,0,3){
		For(j,0,3){
			int cnt = 0;
			if(i-1 >= 0) cnt += g1[i-1][j];
			if(j-1 >= 0) cnt += g1[i][j-1];
			if(i+1 < 3) cnt += g1[i+1][j];
			if(j+1 < 3) cnt += g1[i][j+1];
			g2[i][j] = cnt%2;
		}
	}
}

bool zero(){
	For(i,0,3){
		For(j,0,3){
			if(g2[i][j] != 0) return 0;
		}
	}
	return 1;
}

void print(){
	For(i,0,3){
		For(j,0,3){
			printf("%d", g2[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	cin >> n;

	For(i,0,n){
		init();
		For(j,0,3){
			For(k,0,3){
				scanf(" %c", &c);
				g2[j][k] = c - '0';
			}
		}

		int res = 0;
		while(!zero()){
			copy();
			transform();
			res++;
			//printf("\n");
			//print();
			//printf("\n");
		}

		cout << res-1 << endl;
	}

	return 0;
}
