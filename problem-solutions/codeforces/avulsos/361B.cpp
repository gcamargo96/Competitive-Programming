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

const int N = 100005;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	if(n == k){
		printf("-1\n");
	}
	else if(k == n-1){
		for(int i = 1; i <= n; i++){
			printf("%d ", i);
		}
		printf("\n");
	}
	else{
		v[1] = k+2;
		for(int i = 0; i < k; i++){
			v[2+i] = 2+i;
		}
		for(int i = 2+k; i < n; i++){
			v[i] = i+1;
		}
		v[n] = 1;

		for(int i = 1; i <= n; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
	}

	return 0;
}