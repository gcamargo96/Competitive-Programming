#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 95;
int v[N], n;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	if(n == 1){
		if(v[0] == 0) printf("UP\n");
		else if(v[0] == 15) printf("DOWN\n");
		else printf("-1\n");
	}
	else if((v[n-1] > v[n-2] and v[n-1] < 15) or (v[n-1] == 0)){
		printf("UP\n");
	}
	else{
		printf("DOWN\n");
	}

	return 0;
}

