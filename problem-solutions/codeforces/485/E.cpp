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

const int N = 1000005;
int n;
int v[N], p[N];

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		v[i] = x;
		p[x] = i;
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == i) continue;

		int x = i, y = v[i];
		// printf("%d %d\n", i, p[y]);

		swap(v[i], v[p[i]]);
		swap(p[i], p[y]);
		cnt++;

		// for(int i = 1; i <= n; i++){
		// 	printf("%d ", v[i]);
		// }
		// printf("\n");

	}

	// printf("cnt = %d\n", cnt);

	if(cnt%2 == n%2){
		printf("Petr\n");
	}
	else{
		printf("Um_nik\n");
	}

	return 0;
}