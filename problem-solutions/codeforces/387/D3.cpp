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

#define NEG 0
#define POS 1

struct interval{
	int ini, fim;

	interval() {}

	interval(int _ini, int _fim){
		ini = _ini;
		fim = _fim;
	}

	bool operator<(const interval& b) const{
		if(fim-ini == b.fim-b.ini) return ini < b.ini;
		return fim-ini+1 < b.fim-b.ini+1;
	}
};

const int N = 200002;
int n, k;
int v[N];
set<interval> positivos;
int cntneg, lastneg = -1, res;
interval last;

int main(void){
	scanf("%d%d", &n, &k);

	int status = POS;
	int ini = -1, fim = -1;
	For(i,0,n){
		scanf("%d", &v[i]);

		if(v[i] < 0){
			cntneg++;
			lastneg = i;
		}

		if(status == NEG and v[i] >= 0){
			ini = i;
			res += 2;
		}
		else if(status == POS and v[i] < 0){
			fim = i-1;
			if(ini != -1){
				positivos.insert(interval(ini, fim));
			}
		}
		
		if(v[i] >= 0) status = POS;
		else status = NEG;
	}
	if(status == POS){
		last.ini = ini;
		last.fim = n-1;
	}
	else{
		//cout << "termina negativo" << endl;
		res += 2;
		last.ini = n;
		last.fim = n;
	}


	if(cntneg > k){
		printf("-1\n");
		return 0;
	}
	if(cntneg == 0){
		printf("0\n");
		return 0;
	}
	if(cntneg == n){
		printf("1\n");
		return 0;
	}

	int cnt = 0;
	for(auto it = positivos.begin(); it != positivos.end(); it++){
		if(it->fim - it->ini + 1 <= k-cntneg){
			cntneg += it->fim - it->ini + 1;
			//positivos.erase(it);
			res -= 2;
		}
	}

	if(last.ini == n or last.fim - last.ini + 1 <= k-cntneg) res -= 1;

	printf("%d\n", res);
	
	return 0;
}

