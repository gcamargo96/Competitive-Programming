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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f
const int N = 200005;
int t, n, d;
int v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &d);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		if(d < 0){
			bool ok = 0;
			for(int i = 0; i < n; i++){
				if(v[i] >= d){
					ok = 1;
					break;
				}
			}

			if(ok){
				printf("1\n");
			}
			else{
				printf("-1\n");
			}
			continue;
		}

		int l = 0, r = 0, sum = 0, ans = INF;
		for(r = 0; r < n; r++){
			sum += v[r];

			if(sum >= d){
				ans = min(ans, r-l+1);
			}

			if(sum <= 0){
				l = r+1;
				sum = 0;
				continue;
			}

			while(l < r and (sum >= d or v[l] <= 0)){
				sum -= v[l];
				l++;

				if(sum >= d){
					ans = min(ans, r-l+1);
				}
			}

			if(sum >= d){
				ans = min(ans, r-l+1);
			}
		}


		if(ans != INF){
			printf("%d\n", ans);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}