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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002;
ll f[N];
set<ll> fib;
int n;

void precalc(){
	f[1] = f[2] = 1;
	fib.insert(1);
	for(int i = 3; i < N; i++){
		f[i] = f[i-1] + f[i-2];
		fib.insert(f[i]);
	}
}

int main(void){
	precalc();
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		if(fib.count(i)){
			printf("O");
		}
		else{
			printf("o");
		}
	}
	printf("\n");

	return 0;
}