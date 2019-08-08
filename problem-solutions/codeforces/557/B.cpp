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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 55;
int n, m;
int a[N][N], b[N][N];

void no(){
	printf("Impossible\n");
	exit(0);
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &b[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(b[i][j] > a[i][j]){
				swap(a[i][j], b[i][j]);
			}
		}
	}

	// check
	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if(a[i][j] <= a[i][j-1] or b[i][j] <= b[i][j-1]){
				no();
			}
		}
	}

	for(int j = 0; j < m; j++){
		for(int i = 1; i < n; i++){
			if(a[i][j] <= a[i-1][j] or b[i][j] <= b[i-1][j]){
				no();
			}
		}
	}

	printf("Possible\n");

	return 0;
}