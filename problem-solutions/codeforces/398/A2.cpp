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

const int N = 100002;
int n;
ii v[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i].fi);
		v[i].se = i;
	}

	sort(v, v+n);

	int i = n-1, tmp = 0;
	while(i >= 0){
		int j = i;
		vi aux;
		for(j = i; j > 0 and v[j].se > v[j-1].se; j--){
			aux.pb(v[j].fi);
		}
		aux.pb(v[j].fi);
		
		For(j,tmp,v[i].se) printf("\n");
		tmp = v[i].se + 1;

		//if(j == i) j--;
		i = j-1;
	

		For(j,0,aux.size()){
			printf("%d ", aux[j]);
		}
		printf("\n");
	}

	return 0;
}

