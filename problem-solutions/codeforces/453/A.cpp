#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, m;
int v[N];

int main(void){
	scanf("%d%d", &n, &m);

	int a, b;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		for(int j = a+1; j <= b; j++){
			v[j] = 1;
		}
	}

	// for(int i = 0; i <= m; i++){
	// 	printf("%d ", v[i]);
	// }


	bool ans = 1;
	for(int i = 1; i <= m; i++){
		if(v[i] != 1)
			ans = 0;
	}

	if(ans)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}