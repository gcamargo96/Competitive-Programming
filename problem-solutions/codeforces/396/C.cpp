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

#define MOD 1000000007
const int N = 1002;
int n;
string s;
int a[30];
int lim = INF, cnt = 1;
ll pd[N][N];
int maior_tam = 0;
int minimo = INF;

ll solve(int i, int tam, int lim){
	//int aux = lim;
	lim = min(lim, a[s[i]-'a']);
	if(tam+1 > lim){
		//lim = aux;
		return 0;
	}

	maior_tam = max(maior_tam, tam+1);
	if(i == n-1){
		//lim = aux;
		minimo = min(minimo, cnt);
		return 1;
	}
	if(pd[i][tam] != -1){
		//lim = aux;
		return pd[i][tam];
	}

	ll ret = solve(i+1, tam+1, lim);
	cnt++;
	//lim = INF;
   	ret = (ret + solve(i+1, 0, INF))%MOD;
	cnt--;

	//lim = aux;
	return pd[i][tam] = ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	For(i,0,26){
		cin >> a[i];
	}

	For(i,0,N)
		For(j,0,N)
			pd[i][j] = -1;
	
	ll res = solve(0, 0, INF);

	cout << res << endl;
	cout << maior_tam << endl;
	cout << minimo << endl;

	return 0;
}

