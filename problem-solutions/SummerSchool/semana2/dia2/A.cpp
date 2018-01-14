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

const int N = 200002;
int n;
int z[N], p[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &z[i]);
	}

	For(i,0,n){
		if(z[i] != 0)
			p[i+z[i]-1] = max(z[i], p[i+z[i]-1]);
	}

	for(int i = n-2; i >= 0; i--){
		p[i] = max(p[i], p[i+1]-1);
	}

	For(i,0,n){
		printf("%d ", p[i]);
	}
	printf("\n");
	
	return 0;
}

