#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define BEG 0
#define END 1
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N = 100002;
int t, n, d;
ll v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &d);

		ll sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%lld", &v[i]);
			sum += v[i];
		}

		if(sum%n != 0){
			printf("-1\n");
			continue;
		}

		int cur = 0;
		ll qnt = sum/n, ans = 0;
		for(int i = 0; i < d; i++){
			int sobra = i;
			for(; sobra < n and v[sobra] <= qnt; sobra += d) {}

			for(cur = i; cur < n; cur += d){
				// printf("cur = %d, sobra = %d\n", cur, sobra);
				while(v[cur] < qnt and sobra < n){
					// while(sobra < n and v[sobra] > qnt){
						ll aux = min (qnt-v[cur], v[sobra]-qnt);
						v[cur] += aux;
						v[sobra] -= aux;
						ans += aux*(abs(cur-sobra)/d);
						// printf("trocou %d de %d a %d\n", aux, cur, sobra);
						while(sobra < n and v[sobra] <= qnt){
							sobra += d;
						}
					// }
				}
			}
		}

		bool ok = 1;
		for(int i = 0; i < n; i++){
			// printf("%d ", v[i]);
			if(v[i] != qnt){
				ok = 0;
				// break;
			}
		}
		// printf("\n");

		if(ok){
			printf("%lld\n", ans);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}