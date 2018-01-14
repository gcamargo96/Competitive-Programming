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
int r1[N], r2[N];

int main(void){
	scanf("%d%d", &n, &k);
	
	int x;
	r1[0] = r2[0] = k;
	For(i,1,n+1){
		scanf("%d", &x);
		r1[i] = r2[i] = x;
	}
	r1[n+1] = r2[n+1] = k;

	int s1 = 0;
	for(int i = 1; i <= n; i += 2){
		if(r1[i]+r1[i-1] < k){
			s1 += k-min(r1[i-1], r1[i]);
			r1[i] += k-min(r1[i-1], r1[i]);
		}
		if(r1[i]+r1[i+1] < k){
			s1 += k-min(r1[i], r1[i+1]);
			r1[i] += k-min(r1[i+1], r1[i]);
		}
	}

	int s2 = 0;
	for(int i = 2; i <= n; i += 2){
		if(r2[i]+r2[i-1] < k){
			s2 += k-min(r2[i-1], r2[i]);
			r2[i] += k-min(r2[i-1], r2[i]);
		}
		if(r2[i]+r2[i+1] < k){
			s2 += k-min(r2[i], r2[i+1]);
			r2[i] += k-min(r2[i+1], r2[i]);
		}
	}

	if(s1 < s2){
		for(int i = 1; i <= n; i++){
			printf("%d ", r1[i]);
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			printf("%d ", r2[i]);
		}	
	}
	printf("\n");
	
	return 0;
}

