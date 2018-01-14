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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct Poly{
	int n;
	vi p;

	Poly() {
		n = 0;
	}

	Poly(int _n){
		n = _n;
		p.resize(n+1, 0);
	}

	Poly operator +(const Poly& b) const{
		int sz = max(n, b.n);
		Poly novo(sz);
		
		for(int i = 0; i <= n; i++){
			novo.p[i] += p[i];
		}
		for(int i = 0; i <= b.n; i++){
			novo.p[i] += b.p[i];
		}
		for(int i = 0; i <= sz; i++){
			novo.p[i] %= 2;
		}

		return novo;
	}

	Poly shift(){
		Poly novo(n+1);

		for(int i = 1; i <= novo.n; i++){
			novo.p[i] = p[i-1];
		}

		return novo;
	}
};

const int N = 152;
Poly f[N];
int k;

int main(void){
	f[0] = Poly(0);
	f[0].p[0] = 1;

	f[1] = Poly(1);
	f[1].p[0] = 0;
	f[1].p[1] = 1;

	scanf("%d", &k);

	if(k == 1){
		printf("1\n");
		printf("0 1\n");
		printf("0\n");
		printf("1\n");
		return 0;
	}

	for(int i = 2; i <= k; i++){
		f[i] = f[i-1].shift();
		f[i] = f[i] + f[i-2];
	}

	printf("%d\n", k);
	for(int i = 0; i <= f[k].n; i++){
		printf("%d ", f[k].p[i]);
	}
	printf("\n");

	printf("%d\n", f[k-1].n);
	for(int i = 0; i <= f[k-1].n; i++){
		printf("%d ", f[k-1].p[i]);
	}
	printf("\n");

	return 0;
}