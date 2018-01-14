#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define PAR 0
#define IMPAR 1

const int N = 100002;
ll pd[N][2];
int n;
ll v[N];

ll go(int i, int tipo){
	if(i == n-1){
		if(tipo == PAR){
			if(i%2 == 0) return abs(v[i] - v[i+1]);
			else return 0;
		}
		if(tipo == IMPAR){
			if(i%2 == 1){
				return abs(v[i] - v[i+1]);
			}
			else return 0;
		}
	}

	if(pd[i][tipo] != -1LL) return pd[i][tipo];

	ll cur = abs(v[i]-v[i+1]);
	if(tipo == PAR and i%2 == 1) cur = -cur;
	if(tipo == IMPAR and i%2 == 0) cur = -cur;

	return pd[i][tipo] = max(cur + go(i+1, tipo), 0LL);
}

int main(void){
	For(i,0,N){
		For(j,0,2){
			pd[i][j] = -1LL;
		}
	}
	
	scanf("%d", &n);

	For(i,1,n+1){
		scanf("%lld", &v[i]);
	}

	ll res = 0;
	For(i,1,n){
		res = max(res, go(i,i%2));
	}

	printf("%lld\n", res);

	return 0;
}

