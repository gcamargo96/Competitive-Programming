#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002;
int n, k1, k2;
int a[N], b[N];

int main(void){
	scanf("%d%d%d", &n, &k1, &k2);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	while(k1--){
		int mx = -1, id = -1;
		for(int i = 0; i < n; i++){
			int d = abs(a[i]-b[i]);
			if(d > mx){
				mx = d;
				id = i;
			}
		}


		if(a[id] >= b[id]){
			a[id]--;
		}
		else{
			a[id]++;
		}
	}

	while(k2--){
		int mx = -1, id = -1;
		for(int i = 0; i < n; i++){
			int d = abs(a[i]-b[i]);
			if(d > mx){
				mx = d;
				id = i;
			}
		}

		if(b[id] >= a[id]){
			b[id]--;
		}
		else{
			b[id]++;
		}
	}

	ll error = 0;

	for(int i = 0; i < n; i++){
		error += ll(a[i]-b[i]) * ll(a[i]-b[i]);
	}

	printf("%lld\n", error);

	return 0;
}