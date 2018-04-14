#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 1002;
const ll M = 1000000007;
ll A[N][N], B[N][N], C[N][N], X[N], CX[N], BX[N], ABX[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%lld", &A[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%lld", &B[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%lld", &C[i][j]);
		}
	}

	srand(time(NULL));
	for(int i = 0; i < n; i++){
		X[i] = rand()%M;
	}

	// B*X, C*X
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			CX[i] += C[i][j] * X[j];
			CX[i] %= M;
			BX[i] += B[i][j] * X[j];
			BX[i] %= M;
		}
	}

	// A*BX
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ABX[i] += A[i][j] * BX[j];
			ABX[i] %= M;
		}
	}

	bool eq = 1;
	for(int i = 0; i < n; i++){
		if(ABX[i] != CX[i]){
			eq = 0;
		}
	}

	if(eq){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}