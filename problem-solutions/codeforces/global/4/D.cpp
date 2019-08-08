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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000005;
int vis[N];
vi p;

void sieve(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			p.pb(i);
			
			for(int j = i+i; j < N; j += i){
				vis[j] = 1;
			}
		}
	}
}

int main(void){
	sieve();

	int d = 0;
	for(int i = 1; i < p.size(); i++){
		d = max(d, p[i]-p[i-1]);
		if(d > p[i-1]/2){
			printf("warning em %d\n", p[i-1]);
		}
	}

	printf("%d\n", d);

	return 0;
}