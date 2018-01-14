#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		int cnt = 0;
		char c = 'a';
		while(cnt < n){
			printf("%c", c);
			cnt++;
			c++;
			if(c > 'z') c = 'a';
		}
		printf("\n");
	}

	return 0;
}
