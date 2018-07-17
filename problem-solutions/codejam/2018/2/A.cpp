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
int t;
int n, mx;
int b[N], ans[N];
char mat[N][N];

void init(){
	mx = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = '.';
		}
	}
}

void build_mat(){
	// for(int i = 0; i < n; i++){
	// 	printf("%d ", ans[i]);
	// }
	// printf("\n");

	for(int i = 0; i < n; i++){
		if(b[i] > 0){
			// printf("i = %d\n", i);
			int lastj = i;
			for(int j = i-1; j >= 0; j--){
				if(ans[j] == i) lastj = j;
			}
			int r = 0;
			for(int j = lastj; j < i; j++){
				mat[r++][j] = '\\';
			}

			lastj = i;
			for(int j = i+1; j < n; j++){
				if(ans[j] == i) lastj = j;
			}
			r = 0;
			for(int j = lastj; j > i; j--){
				mat[r++][j] = '/';
			}
		}
	}
}

void print_ans(){
	for(int i = 0; i < mx+1; i++){
		for(int j = 0; j < n; j++){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &b[i]);
		}

		printf("Case #%d: ", caso);

		if(b[0] == 0 or b[n-1] == 0){
			printf("IMPOSSIBLE\n");
			continue;
		}

		int last = 0;
		bool ok = 1;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			while(last < n and cnt < b[i]){
				mx = max(mx, abs(i-last));
				ans[last] = i;
				cnt++;
				last++;
			}
			if(cnt < b[i]){
				ok = 0;
				break;
			}
		}

		if(ok){
			printf("%d\n", mx+1);
			build_mat();
			print_ans();
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}