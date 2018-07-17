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

const int N = 102;
int n;
int r, c;
char ans[N][N];

void print(int rows, int cols){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			ans[i][j] = '.';
		}
	}

	for(int cnt = 0, i = 1; cnt < rows; cnt++, i += 2){
		for(int j = 0; j < c; j++){
			ans[i][j] = '#';
		}
	}

	for(int cnt = 0, j = 1; cnt < cols; cnt++, j += 2){
		for(int i = 0; i < r; i++){
			ans[i][j] = '#';
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	freopen("kotlin.in", "r", stdin);
	freopen("kotlin.out", "w", stdout);

	scanf("%d%d%d", &r, &c, &n);

	int maxr = (r-1)/2, maxc = (c-1)/2;

	if((maxr+1)*(maxc+1) < n){
		printf("Impossible\n");
		return 0;
	}

	for(int i = 0; i <= maxr; i++){
		int land = i+1;
		for(int j = 0; j <= maxc; j++){
			if(land + land*j == n){
				print(i, j);
				return 0;
			}
		}
	}

	printf("Impossible\n");

	return 0;
}