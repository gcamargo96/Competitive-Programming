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
		if(v[i] == HOLE){
			if(v[L] == FOX) match[i]++;
			if(v[R] == FOX) match[i]++;
		}
	}

	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == HOLE and match[i] == 0) cnt0++;
		if(v[i] == HOLE and match[i] == 1) cnt1++;
		if(v[i] == HOLE and match[i] == 2) cnt2++;
	}

	int ans = 2*cnt0 + cnt1 + cnt2;

	printf("%d\n", ans);

	return 0;
}