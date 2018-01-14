#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 1502;
int n, m;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	ll total = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(v[i] > v[j]){
				total++;
				total %= 2;
			}
		}
	}

	scanf("%d", &m);

	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);
		
		ll x = r-l+1;
		total = total + x*(x-1)/2;
		total %= 2;

		if(total == 0){
			printf("even\n");
		}
		else{
			printf("odd\n");
		}
	}

	return 0;
}