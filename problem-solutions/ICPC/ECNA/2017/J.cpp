#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct Jim{
	int u, r;
};

const int N = 15;
int u[N], r[N], t[N];
Jim jim[N];

int main(void){
	for(int i = 0; i < 10; i++){
		scanf("%d%d", &jim[i].u, &jim[i].r);
	}

	for(int i = 0; i < 10; i++){
		scanf("%d%d%d", &u[i], &r[i], &t[i]);
	}

	int tempo = 0;
	for(int j = 0; j < 30; j++){
		int i = j%10;

		if(tempo < t[i]){ // pega o aparelho antes do outro comecar
			tempo += jim[i].u; // usa o aparelho
			t[i] = max(t[i], tempo); // atualiza o t[i], se precisar
		}
		else{ // o cara ja comecou a usar o aparelho
			int ciclos = (tempo-t[i])/(u[i]+r[i]); // ciclos completos
			t[i] += ciclos * (u[i]+r[i]); // atualiza t[i] para o começo do ciclo atual
			tempo = max(tempo, t[i] + u[i]); // espera o cara terminar de usar o aparelho, se precisar
			tempo += jim[i].u; // usa o aparelho
			t[i] = max(tempo, t[i] + u[i] + r[i]); // atualiza o t[i] se necessario
		}
		tempo += jim[i].r; // descansa
		// printf("%d\n", tempo);
	}
	tempo -= jim[9].r;

	printf("%d\n", tempo);

	return 0;
}