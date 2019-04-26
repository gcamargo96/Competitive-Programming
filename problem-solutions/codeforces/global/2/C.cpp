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

const int N = 505;
int n, m;
int A[N][N], B[N][N];
int row[N], col[N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &A[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &B[i][j]);
		
			if(A[i][j] != B[i][j]){
				row[i]++;
				col[j]++;
			}
		}
	}

	bool ans = 1;

	for(int i = 1; i <= n; i++){
		if(row[i]%2 != 0){
			ans = 0;
		}
	}

	for(int i = 1; i <= m; i++){
		if(col[i]%2 != 0){
			ans = 0;
		}
	}

	if(ans){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}