#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define make_pair mp
#define push_back pb

int n, p;
char s[20];
ll res = 0;

ll POW(int b, int e){
	ll res = 1;
	for(int i = 1; i <= e; i++){
		res *= b;
	}
	return res;
}

int main(void){
	scanf("%d%d", &n, &p);

	
	for(int i = n-1; i >= 0; i--){
		scanf("%s", s);
		if(s[4] == '\0'){
			res += ((POW(2, i))/2)*p;
			//cout << "half " << res << endl;
		}
		else if(s[4] == 'p'){
			res += ((POW(2, i))/2)*p + p/2;
			//cout << "halfplus " << res << endl;
		}
	}

	printf("%lld\n", res);

	return 0;
}
