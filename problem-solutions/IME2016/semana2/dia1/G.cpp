#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, res;
ll dp[17][17][1]; // numero de 1s / bit atual / eh menor que n?

ll solve(int ones, int curr, int less){
	if(curr < 0){
		if(ones > 0 and ones%3 == 0) return 1;
		return 0;
	}

	if(less == 1){
		ll a = solve(ones+1, curr-1, 1);
		ll b = solve(ones, curr-1, 1);
		return a+b;
	}
	else{
		ll a = 0, b = 0;
		if((n & (1 << curr)) >= 1){ // se o bit atual for == 1
			a = solve(ones+1, curr-1, 0);
			b = solve(ones, curr-1, 1);
		}
		else{
			b = solve(ones, curr-1, 0);
		}
		return a+b;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);

	while(cin >> n){
		res = 0;
		int bit = -1;
		for(int i = 1; i <= 16; i++){
			if((n & (1 << i)) >= 1){
				bit = i;
			}
		}

		ll res = 0;
		if(bit != -1){
			res = solve(0, bit, 0);
		}

		cout << "Day " << n << ": Level = " << res << endl;
	}

	return 0;
}
