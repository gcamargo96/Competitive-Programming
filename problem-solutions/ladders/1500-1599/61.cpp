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

int nb, ns, nc;
int pb, ps, pc;
int cb, cs, cc;
ll r;
string s;

int main(void){
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	For(i,0,s.size()){
		if(s[i] == 'B') cb++;
		if(s[i] == 'S') cs++;
		if(s[i] == 'C') cc++;
	}

	int qb = INF, qs = INF, qc = INF;
	if(cb > 0) qb = nb/cb;
	if(cs > 0) qs = ns/cs;
	if(cc > 0) qc = nc/cc;

	ll res = min(qb, min(qs, qc)); // 1 - fazer hamburgueres com o que tem no estoque
	
	nb -= res*cb;
	ns -= res*cs;
	nc -= res*cc;
	
	
	/*ll res = 0;
	while(nb >= cb and ns >= cs and nc >= cc){
		res++;
		nb -= cb;
		ns -= cs;
		nc -= cc;
	}*/

	// 2 - tentar completar o que sobrou do estoque para fazer mais hamburgueres
	while((nb > 0 or ns > 0 or nc > 0) and r > 0){
		if(nb < cb and r - (cb-nb)*pb >= 0){
			r -= (cb-nb)*pb;
			nb = cb;
		}
		if(ns < cs and r - (cs-ns)*ps >= 0){
			r -= (cs-ns)*ps;
			ns = cs;
		}
		if(nc < cc and r - (cc-nc)*pc >= 0){
			r -= (cc-nc)*pc;
			nc = cc;
		}

		if(nb >= cb and ns >= cs and nc >= cc){
			res++;
			nb -= cb;
			ns -= cs;
			nc -= cc;
		}
		else{
			break;
		}
	}

	//cout << "sobrou " << r << " rubles" << endl;
	//cout << "nb = " << nb << " ns = " << ns << "nc = " << nc << endl;

	// 3 - fazer hamburgueres apenas comprando os ingredientes com o que sobrou do dinheiro
	res += r/(cb*pb+cs*ps+cc*pc);

	cout << res << endl;

	return 0;
}

