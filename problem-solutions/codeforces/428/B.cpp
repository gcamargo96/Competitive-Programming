#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10002;
int n, k;
int qnt[N];
int quatro, dois, um;
int sobra = 0;

int main(void){
	scanf("%d%d", &n, &k);

	quatro = n;
	dois = 2*n;
	um = 0;

	For(i,0,k){
		scanf("%d", &qnt[i]);
	}

	For(i,0,k){
		int usa = min(quatro, qnt[i]/4);
		qnt[i] -= usa*4;
		quatro -= usa;
	}

	dois += quatro;
	um += quatro;
	quatro = 0;

	For(i,0,k){
		int usa = min(dois, qnt[i]/2);
		qnt[i] -= usa*2;
		dois -= usa;
	}

	um += dois;

	For(i,0,k){
		int usa = min(um, qnt[i]);
		qnt[i] -= usa;
		um -= usa;
	}

	bool ans = 1;
	For(i,0,k){
		if(qnt[i] > 0) ans = 0;
	}
	
	if(ans){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}