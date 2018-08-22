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

const int N = 100005;
int v[N];
int n;

int main(void){
	scanf("%d", &n);

	if(n == 1){
		printf("1\n");
		return 0;
	}
	if(n == 2){
		printf("2 1\n");
		return 0;
	}

	int half = n/2;
	int ans = 100000;

	int a = 1, b = n;
	for(int i = 1; i*i <= n; i++){
		// if(n%i != 0) continue;

		int ca = i, cb = (n + i-1)/i;
		// printf("a = %d, b = %d\n", ca, cb);
		if(ca+cb < ans){
			a = ca, b = cb;
		}
	}


	vector<vi> res;
	int cur = 1;
	for(int i = 0; i < a; i++){
		vi aux;
		for(int j = 0; j < b and cur <= n; j++){
			aux.pb(cur++);
		}
		res.pb(aux);
	}

	reverse(res.begin(), res. end());

	for(int i = 0; i < a; i++){
		for(int j = 0; j < res[i].size(); j++){
			printf("%d ", res[i][j]);
		}
	}
	printf("\n");

	return 0;
}