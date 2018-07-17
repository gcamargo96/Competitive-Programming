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

const int N = 52;
char g[N][N];
int a, b, c, d;

int main(void){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a--, b--, c--, d--;

	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 50; j++){
			if(i < 12){
				g[i][j] = 'A';
			}
			else if(i < 24){
				g[i][j] = 'B';
			}
			else if(i < 36){
				g[i][j] = 'C';
			}
			else{
				g[i][j] = 'D';
			}
		}
	}

	for(int i = 0; i < 12; i += 2){
		for(int j = 0; j < 50; j += 2){
			if(c > 0){
				g[i][j] = 'C';
				c--;
			}
		}
	}

	for(int i = 12; i < 24; i += 2){
		for(int j = 0; j < 50; j += 2){
			if(d > 0){
				g[i][j] = 'D';
				d--;
			}
		}
	}

	for(int i = 24; i < 36; i += 2){
		for(int j = 0; j < 50; j += 2){
			if(a > 0){
				g[i][j] = 'A';
				a--;
			}
		}
	}

	for(int i = 36; i < 48; i += 2){
		for(int j = 0; j < 50; j += 2){
			if(b > 0){
				g[i][j] = 'B';
				b--;
			}
		}
	}

	printf("48 50\n");
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 50; j++){
			printf("%c", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}