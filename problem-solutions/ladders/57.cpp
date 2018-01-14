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

const int N = 302;
int n, r, t;
set<int> velas;
bool tempo[2*N];

int main(void){
	scanf("%d%d%d", &n, &t, &r);

	int w, res = 0;
	bool ok = 1;
	For(i,0,n){
		scanf("%d", &w);

		vector<int> apagar;
		for(auto it = velas.begin(); it != velas.end(); it++){
			if(*it < N+w) apagar.pb(*it);
		}
		For(i,0,apagar.size()){
			velas.erase(apagar[i]);
		}

		if(velas.size() < r){
			//cout << "faltam velas em " << w << endl;
			for(int j = N + w-1; j >= N + w - t and velas.size() < r; j--){
				if(tempo[j] == 0){
					res++;
					velas.insert(j+t);
					tempo[j] = 1;
					//cout << "acender vela em " << j-N << endl;
				}
			}
		}
		if(velas.size() < r) ok = 0;
	}

	if(ok){
		printf("%d\n", res);
	}
	else{
		printf("-1\n");
	}

	return 0;
}

