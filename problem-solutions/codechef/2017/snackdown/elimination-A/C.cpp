#include <bits/stdc++.h>
using namespace std;
#define ll long long

// USAR LONG LONG
int t;
ll a, b, c, d;
const ll INF = 100000000000005;

int main(void){
	scanf("%d", &t);
	
	while(t--){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(c != d or a == b){
			printf("0\n");
		}
		else{
			ll dif = abs(a-b); // dif - dif%c + c
			ll res = dif;
			//ll res = min(dif%c, (dif+min(a,b))%dif);
			ll outro = min(a,b)+(dif/c)*c+c-max(a,b);
			if(dif > 1) res = min(res%c, outro);
			if(c == 1) res = 0;
			//printf("%lld\n", abs(a-b)%c);
			//printf("%lld\n", c-(abs(a-b)%c+c)%c);
			printf("%lld\n", res);
		}
	}

	return 0;
}

