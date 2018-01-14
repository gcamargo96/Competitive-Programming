#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t, l, r;
int a[12], cnt[12];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &l, &r);

		For(i,0,10){
			scanf("%d", &a[i]);
		}

		int zero_only = 1;
		For(i,0,10){
			if(a[i] != 0){
				zero_only = 0;
				break;
			}
		}

		if(zero_only){
			printf("0\n");
		}
		else{
			int res = 0;
			for(int i = l; i <= r; i++){
				memset(cnt, 0, sizeof cnt);
				int x = i;
				bool ok = 1;

				while(x > 0){
					cnt[x%10]++;
					x /= 10;
				}

				For(j,0,10) if(cnt[j] == a[j]) ok = 0;
				if(ok) res++;
			}
			printf("%d\n", res);
		}
	}

	return 0;
}

