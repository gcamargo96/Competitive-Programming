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
 
const int N = 205;
int n;
vi v[N];
int a[N], ans[N];
 
int main(void){
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
 
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
 
	int x;
	for(int i = 1; i < n; i++){
		v[n-i].pb(0);
		for(int j = 0; j < i; j++){
			scanf("%d", &x);
			v[n-i].pb(x);
		}
	}
 
	for(int i = n-1; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			if(v[j][n-i] == 1){
				// printf("swap %d %d\n", j, j+1);
				swap(a[j], a[j+1]);
			}
		}
	}
 
	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
 
	for(int i = 1; i <= n; i++){
		ans[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		a[i] = ans[i];
	}
 
	for(int i = n-1; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			if(v[j][n-i] == 1){  // ligado tem que swapar
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
				}
				else{
					printf("NO\n");
					return 0;
				}
			}
			else if(a[j] > a[j+1]){ // desligado nao pode swapar
					printf("NO\n");
					return 0;				
			}
		}
	}
 
	for(int i = 1; i <= n; i++){
		if(a[i] != i){
			printf("NO\n");
			return 0;
		}
	}
 
	printf("YES\n");
 
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
 
	return 0;
}