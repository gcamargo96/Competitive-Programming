#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 4002;
int n;
int v[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int g = v[0];
	for(int i = 1; i < n; i++){
		g = gcd(g, v[i]);
	}

	bool has = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == g)
			has = 1;
	}

	if(!has){
		printf("-1\n");
	}
	else{
		printf("%d\n", 2*n);
		for(int i = 0; i < n; i++){
			printf("%d %d ", v[i], g);
		}
		printf("\n");
	}

	return 0;
}