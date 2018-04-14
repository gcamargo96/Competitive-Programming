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

int t, a;
int g[5][5];

bool complete(){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			if(g[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

void print(){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			fprintf(stderr, "%d", g[i][j]);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n");
}

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%d", &a);

		int squares;
		if(a == 20)
			squares = 3;
		else
			squares = 23;

		int center = 2, x, y;
		int ok = 0;
		for(int i = 0; i < squares; i++){
			memset(g, 0, sizeof g);
			
			while(!complete()){
				printf("%d %d\n", 2, center);
				fflush(stdout);
				scanf("%d%d", &x, &y);

				if(x == 0 and y == 0){
					ok = 1;
					break;
				}
				if(x == -1 and y == -1){
					return 0;
				}

				g[x][y-(center-2)] = 1;
				// fprintf(stderr, "x = %d, y = %d\n", x, y);
				// print();
			}

			if(ok == 1){
				break;
			}

			center += 3;
		}
	}

	return 0;
}