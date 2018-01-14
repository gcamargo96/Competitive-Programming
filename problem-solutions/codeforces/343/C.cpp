#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2005;
ll n, m, a = 0, f = 0, res = 0;
ll pd[N];

ll solve(int placed, int faltameio, int af){
	ll sum = 0;
	
	//if(pd[placed] != 0) return pd[placed];

	if(placed > n) return 0;	
	if(af < 0 or (placed == n and af != 0)) return 0;
	if(af == 0 and placed == n) return 1;
	if(faltameio == 0){
		sum = (solve(placed + m, -1, af + a - f))%1000000007;
		return pd[placed] = sum;
	}

	sum += (solve(placed+1, faltameio-1, af-1))%1000000007;
	sum += (solve(placed+1, faltameio-1, af+1))%1000000007;
	return pd[placed] = sum;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	char c;
	int flag = 0;
	for(int i = 0; i < m; i++){
		scanf(" %c", &c);
		if(c == '(') a++;
		else f++;
		if(f > a) flag = 1;
	}

	if(flag){
		cout << '0' << endl;
		return 0;
	}

	if(n == m and a == f){
		cout << '1' << endl;
		return 0;
	}

	for(int i = 0; i <= n-m; i++){
		res += (solve(1, i, 1))%1000000007;
	}
	//for(int i = 0; i <= n-m; i++){
	//	res += solve(m, -1, a-f);
	//}

	cout << res << endl;

	return 0;
}
