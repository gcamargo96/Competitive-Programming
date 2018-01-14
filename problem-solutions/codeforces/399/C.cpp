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
int v[N];
int n, k, x;
int menor[4], maior[4];

int main(void){
	scanf("%d%d%d", &n, &k, &x);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);
	menor[0] = v[0];
	maior[0] = v[n-1];

	for(int i = 0; i < n; i += 2){
		v[i] = v[i]^2;
	}

	sort(v, v+n);
	menor[1] = v[0];
	maior[1] = v[n-1];

	for(int i = 0; i < n; i += 2){
		v[i] = v[i]^2;
	}

	sort(v, v+n);
	menor[2] = v[0];
	maior[2] = v[n-1];

	for(int i = 0; i < n; i += 2){
		v[i] = v[i]^2;
	}

	sort(v, v+n);
	menor[3] = v[0];
	maior[3] = v[n-1];

	if(k%4 == 0){
		printf("%d %d\n", maior[0], menor[0]);
	}
	else if(k%4 == 1){
		printf("%d %d\n", maior[1], menor[1]);
	}
	else if(k%4 == 2){
		printf("%d %d\n", maior[2], menor[2]);
	}
	else if(k%4 == 3){
		printf("%d %d\n", maior[3], menor[3]);
	}

	return 0;
}

