#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2010;
ll mod = 1000000007;
ll n, m, a = 0, res = 0, precisa_abrir = 0, precisa_fechar = 0;
ll pd[N][N][2];
string s;

ll solve(int id, int abertos, int flag){	
	if(id > n-m+1) return 0;
	if(abertos > n/2) return 0;	
	if(id == n-m+1 and abertos == 0 and flag == 1) return 1;
	if(abertos < 0) return 0;
	if(id == n-m+1 and (abertos > 0 or flag == 0)) return 0;
	if(pd[id][abertos][flag] != -1) return pd[id][abertos][flag];

	pd[id][abertos][flag] = ((solve(id+1, abertos+1, flag))%mod + (solve(id+1, abertos-1, flag))%mod)%mod;
	if(!flag and abertos >= precisa_abrir) pd[id][abertos][flag] = (pd[id][abertos][flag] + (solve(id+1, abertos+a, 1))%mod)%mod;
	
	return pd[id][abertos][flag];
}

int main(void){
	//ios_base::sync_with_stdio(false);
	cin >> n >> m;
	memset(pd, -1, sizeof pd);

	//cin >> s;
	char c;
	for(int i = 0; i < m; i++){
		scanf(" %c", &c);
		if(c == '(') a++;
		else a--;
		if(a < -precisa_abrir) precisa_abrir = -a;
	}

	if(n == m and precisa_abrir == 0 and a == 0){
		cout << "1" << endl;
		return 0;
	}
	if(n == m and (a != 0 or precisa_abrir > 0)){
		cout << "0" << endl;
		return 0;
	}

	res = solve(1, 1, 0);
	if (precisa_abrir == 0) res = (res+solve(1, a, 1))%mod;

	cout << res << endl;

	return 0;
}
