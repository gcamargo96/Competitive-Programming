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

const int N = 100002;
int L[N], R[N];
int ans[N], n;


int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &L[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &R[i]);
	}

	for(int i = 1; i < n; i++){
		if(L[i] > L[i-1]){
			ans[i-1] = 0;
		}
		else{
			ans[i-1] = 1;
		}
	}

	if(R[n-2] > R[n-1]){
		ans[n-1] = 0;
	}
	else{
		ans[n-1] = 1;
	}

	for(int i = 0; i < n; i++){
		printf("%d", ans[i]);
	}
	printf("\n");


	return 0;
}