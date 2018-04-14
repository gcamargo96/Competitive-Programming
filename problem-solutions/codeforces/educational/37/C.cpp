#include <bits/stdc++.h>
using namespace std;
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

const int N = 200002;
int n;
int v[N], can[N], acum[N];

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = 1; i < n; i++){
		// scanf("%d", &can[i]);
		char c; cin >> c;
		can[i] = c-'0';
	}

	for(int i = 1; i <= n; i++){
		acum[i] = acum[i-1] + can[i];
	}

	for(int i = 1; i <= n; i++){
		if(v[i] < i){
			int sum = acum[i-1] - acum[v[i]-1];
			if(sum < i-v[i]){
				printf("NO\n");
				return 0;
			}
		}
		else if(v[i] > i){
			int sum = acum[v[i]-1] - acum[i-1];
			if(sum < v[i]-i){
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");

	return 0;
}