#include <bits/stdc++.h>
using namespace std;

int n, b, h, w;

int main(void){
	while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF){
		int p, menor = 20000005, a, res = 0;
		for(int i = 0; i < h; i++){
			scanf("%d", &p);
			for(int j = 0; j < w; j++){
				scanf("%d", &a);
				if(a >= n and n*p < b){
					b = n*p;
					res = 1;
				}
			}
		}
		if(res) printf("%d\n", b);
		else printf("stay home\n");
	}

	return 0;
}
