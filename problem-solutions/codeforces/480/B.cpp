#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, k;
char g[4][N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < n; j++){
			g[i][j] = '.';
		}
	}

	int cnt = 0, mid = n/2;
	for(int i = 1; i < mid and cnt <= k-2; i++, cnt += 2){
		g[1][i] = '#';
		g[1][n-i-1] = '#';
	}
	if(cnt < k){
		g[1][mid] = '#';
		cnt++;
	}

	for(int i = 1; i < mid and cnt <= k-2; i++, cnt += 2){
		g[2][i] = '#';
		g[2][n-i-1] = '#';
	}
	if(cnt < k){
		g[2][mid] = '#';
		cnt++;
	}

	printf("YES\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < n; j++){
			printf("%c", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}