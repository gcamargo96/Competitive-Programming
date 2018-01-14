#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define make_pair mp
#define push_back pb

int n, p;
char s[42][22];
ll res;


int main(void){
	scanf("%d%d", &n, &p);

	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}

	ll cur = 1; 
	res += p/2;
	for(int i = n-2; i >= 0; i--){
		if(s[i][4] == '\0'){
			res += (cur)*p;
			cur *= 2;
		}
		if(s[i][4] == 'p'){
			res += (cur)*p + p/2;
			cur = cur*2 + 1;
		}
	}

	printf("%I64d\n", res);

	return 0;
}
