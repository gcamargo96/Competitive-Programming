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

#define INF 0x3f3f3f3f
int n, k;

int main(void){
	scanf("%d%d", &n, &k);
	int min_ans = INF, pos = 1;

	if(k >= n){
		printf("1\n");
		printf("1\n");
		return 0;
	}

	for(int i = 1; i <= min(n, k+1); i++){
		int cnt = 0;
		int last = i;
		for(int j = i; j <= n; j += 2*k+1){
			last = j;
			cnt++;
		}
		if(last + k >= n and cnt < min_ans){
			min_ans = cnt;
			pos = i;
		}
	}

	printf("%d\n", min_ans);
	for(int i = pos; i <= n; i += 2*k+1){
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}