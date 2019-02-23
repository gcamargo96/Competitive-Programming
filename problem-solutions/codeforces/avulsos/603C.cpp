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
int n, k;
int a[N];

int f0(int x){
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(x == 2) return 2;
	return !(x%2);
}

int f1(int x){
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(x == 2) return 0;
	if(x == 3) return 1;
	if(x%2) return 0;

	int a = -1, b = -1;
	
	a = f1(x-1);
	if(x%2 == 0) b = f1(x/2);

	if(a != 0 and b != 0) return 0;
	if(a != 1 and b != 1) return 1;
	return 2;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(k%2 == 0){
			ans ^= f0(a[i]);
		}
		else{
			ans ^= f1(a[i]);
		}
	}

	if(ans > 0){
		printf("Kevin\n");
	}
	else{
		printf("Nicky\n");
	}

	return 0;
}