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

const int N = 502;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	For(i,0,n){
		scanf("%d", &v[i]);
	}
	v[n] = k;

	int res = 0;
	For(i,0,n){
		if(v[i]+v[i+1] < k){
			res += k-(v[i]+v[i+1]);
			v[i+1] += k-(v[i]+v[i+1]);
		}
	}

	printf("%d\n", res);
	For(i,0,n){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}

