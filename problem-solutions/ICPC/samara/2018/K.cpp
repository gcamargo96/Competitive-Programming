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

const int N = 200005;
int n, m;
int v[N];

bool check(int x){
	int cnt = 0, used = 0;
	for(int i = 0; i < n; i++){
		if(v[i] <= cnt){
			cnt++;
		}
		else if(used < x){
			cnt++;
			used++;
		}
	}

	// printf("x = %d, cnt = %d\n", x, cnt);

	return cnt >= m;
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int l = 0, r = n;
	int ans = n;
	while(l <= r){
		int mid = (l+r)/2;

		if(check(mid)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	printf("%d\n", ans);

	return 0;
}