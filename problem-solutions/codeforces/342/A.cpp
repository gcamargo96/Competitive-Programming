#include <bits/stdc++.h>
using namespace std;

int main(void){
	long long n, a, b, c, res = 0;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);

	if(a <= b-c or b > n){
		res = n/a;
	}
	else{
		res = (n-c)/(b-c);
		res +=  (n-res*(b-c))/a;
	}
	if(res < 0) res = 0;

	printf("%lld\n", res);

	return 0;
}
