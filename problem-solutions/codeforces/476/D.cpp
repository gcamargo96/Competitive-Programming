#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 100005;
int l, w;
int v[N], acum[N];

bool check(int x){
	for(int i = 1; i <= w-l; i++){
		if(acum[i+l-1] - acum[i-1] < x){
			return 0;
		}
	}
	return 1;
}

int main(void){
	scanf("%d%d", &w, &l);

	for(int i = 1; i < w; i++){
		scanf("%d", &v[i]);
		acum[i] = acum[i-1] + v[i];
	}

	int l = 0, r = 1000000005, ans = 0;
	while(l <= r){
		int mid = (l+r)/2;

		if(check(mid)){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	printf("%d\n", ans);

	return 0;
}