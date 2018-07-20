#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1005;
int n, m;
int v1[N], v2[N];

int main(void){
	scanf("%d%d", &n, &m);

	int ans1 = 0, ans2 = 0;
	bool x = 0;
	for(int i = 0; i < n; i++){
		v1[i] = x;
		v2[i] = !x;
		x = !x;
	}

	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);

		int c0 = 0, c1 = 0;
		for(int j = l; j <= r; j++){
			if(v1[i] == 0) c0++;
			else c1++;
		}
		ans1 += c0*c1;

		c0 = 0, c1 = 0;
		for(int j = l; j <= r; j++){
			if(v2[i] == 0) c0++;
			else c1++;
		}
		ans2 += c0*c1;
	}

	if(ans1 >= ans2){
		for(int i = 0; i < n; i++){
			printf("%d", v1[i]);
		}
	}
	else{
		for(int i = 0; i < n; i++){
			printf("%d", v2[i]);
		}
	}
	printf("\n");

	return 0;
}