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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define FOX 1
#define HOLE 2

const int N = 100002;
int n, k;
int v[N];
int match[N];

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		v[x] = FOX;
	}

	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		v[x] = HOLE;
	}

	for(int i = 1; i <= n; i++){
		int L = (i-1 > 0 ? i-1 : n);
		int R = (i+1 <= n ? i+1 : 1);
		if(v[i] == FOX and v[L] == HOLE){
			match[L]++;
		}
		if(v[i] == FOX and v[R] == HOLE){
			match[R]++;
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == HOLE){
			if(match[i] == 1) cnt++;
		}
	}

	int cnt1 = 0;
	for(int i = 1; i <= n; i++){
		int R = (i+1 <= n ? i+1 : 1);
		if(v[i] == FOX and v[R] == HOLE and match[R] == 2){
			cnt1++;
		}
	}

	int cnt2 = 0;
	for(int i = 1; i <= n; i++){
		int L = (i-1 > 0 ? i-1 : n);
		if(v[i] == FOX and v[L] == HOLE and match[L] == 2){
			cnt2++;
		}		
	}

	int ans1 = cnt + cnt1 + 2*(k-cnt-cnt1);
	int ans2 = cnt + cnt2 + 2*(k-cnt-cnt2);
	// printf("ans1 = %d, ans2 = %d\n", ans1, ans2);
	printf("%d\n", min(ans1, ans2));

	return 0;
}