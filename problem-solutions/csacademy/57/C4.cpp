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
int match_fox[N], match_hole[N];

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
		if(v[i] == HOLE){
			if(v[L] == FOX) match_hole[i]++;
			if(v[R] == FOX) match_hole[i]++;
		}
	}

	for(int i = 1; i <= n; i++){
		int L = (i-1 > 0 ? i-1 : n);
		int R = (i+1 <= n ? i+1 : 1);
		if(v[i] == FOX){
			if(v[L] == HOLE) match_fox[i]++;
			if(v[R] == HOLE) match_fox[i]++;
		}
	}


	int cnt_fox = 0, cnt_hole = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == FOX and match_fox[i] == 0) cnt_fox++;
		if(v[i] == HOLE and match_hole[i] == 0) cnt_hole++;
	}

	int cnt = max(cnt_fox, cnt_hole);
	int ans = 2*cnt + (k-cnt);

	printf("%d\n", ans);

	return 0;
}