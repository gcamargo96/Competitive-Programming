#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 502;
int a[N][N];
int n;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		For(j,0,n){
			scanf("%d", &a[i][j]);
		}
	}

	int ans = -1000000000;
	For(i,0,n){
		int sum = 0;
		For(k,0,n){
			sum += a[(i+k)%n][k];
		}
		ans = max(ans, sum);
	}

	printf("%d\n", ans);

	return 0;
}