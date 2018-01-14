#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int v[N];

int main(void){
	int k = 1;
	
	scanf("%d", &k);
	while(k != 0){
		for(int i = 0; i < k; i++){
			scanf("%d", &v[i]);
		}
		int i=0, j=1, l=2, m=3, n=4, o=5, flag = 0;
		for(i = 0; i < j; i++){
			for(j = i+1; j < l; j++){
				for(l = j+1; l < m; l++){
					for(m = l+1; m < n; m++){
						for(n = m+1; n < o; n++){
							for(o = n+1; o < k; o++){
								printf("%d %d %d %d %d %d\n", v[i], v[j], v[l], v[m], v[n], v[o]);
							}
						}
					}
				}
			}
		}
		//printf("\n");
		scanf("%d", &k);
		if(k != 0) printf("\n");
	}

	return 0;
}
