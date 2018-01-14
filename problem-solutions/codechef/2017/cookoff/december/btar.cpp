#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 100002;
int t, n;
int cnt[5];

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);

		int sum = 0, x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			x %= 4;
			cnt[x]++;
			sum += x;
		}

		if(sum%4 != 0){
			printf("-1\n");
		}
		else{
			int ans = 0;

			x = min(cnt[1], cnt[3]);
			ans += x;
			cnt[1] -= x;
			cnt[3] -= x;
			
			x = cnt[1]/2;
			ans += x;
			cnt[2] += x;
			cnt[1] -= 2*x;

			x = cnt[3]/2;
			ans += x;
			cnt[2] += x;
			cnt[3] -= 2*x;

			ans += cnt[2]/2;

			printf("%d\n", ans);
		}
	}

	return 0;
}