#include <bits/stdc++.h>
using namespace std;

const int N = 1002;	
char str[N], b[N];

void prep() {
	int n=strlen(str);
	b[0]=-1;
	int i=0,j=-1;
	while(i<n){
		while(j>=0 && str[i]!=str[j])j=b[j];
			++i;
			++j;
			b[i]=j;
		}
}

int main(void){
	scanf("%s", str);

	prep();

	int n = strlen(str);
	for(int i = 1; i <= n; i++){
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}