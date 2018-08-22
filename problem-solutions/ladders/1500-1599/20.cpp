#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define MOD 1000000007;

const int N = 2002;
int n, k;
int pd[N][N];

int main(void){
	scanf("%d%d", &n, &k);
	pd[0][1] = 1;

	for(int i = 0; i < k; i++){
		for(int a = 1; a <= n; a++){
			for(int b = a; b <= n; b += a){
				pd[i+1][b] = (pd[i+1][b]+pd[i][a])%MOD;
			}
		}
	}	

	int res = 0;
	for(int a = 1; a <= n; a++){
		res = (res+pd[k][a])%MOD;
	}

	printf("%d\n", res);

	return 0;
}

