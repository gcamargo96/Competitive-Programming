#include <bits/stdc++.h>
using namespace std;

int t, n;
int cnt[2505];

int main(void){
	scanf("%d", &t);

	for(int k = 1; k <= t; k++){
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);

		int x;
		for(int i = 0; i < 2*n-1; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &x);
				cnt[x]++;
			}
		}

		vector<int> res;
		for(int i = 0; i <= 2500; i++){
			if(cnt[i]%2 == 1){
				res.push_back(i);
			}
		}

		printf("Case #%d: ", k);
		for(int i = 0; i < n; i++){
			printf("%d ", res[i]);
		}
		printf("\n");
	}

	return 0;
}
