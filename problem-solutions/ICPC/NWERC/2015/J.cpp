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
int n;
int v[N];

void Set(int& x, int p, int val){
	if(val == 0) return;
	x = x|(1<<p);
}

int get(int x, int p){
	return (x>>p)&1;
}

int get_last_1(int x){
	int last = 0;

	for(int i = 0; i < 8; i++){
		if(get(x,i) == 1) last = i;
	}

	return last;
}

int solve(int x){
	if(x == 0) return 0;

	int a = 0;
	Set(a, 0, get(x,0));

	int len = get_last_1(x);
	for(int i = 1; i < 8; i++){
		if(get(x,i) == 0){
			Set(a, i, get(a,i-1));
		}
		else{
			Set(a, i, 1-get(a,i-1));
		}
	}

	return a;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = 0; i < n; i++){
		int x = v[i];
		printf("%d ", solve(x));
	}
	printf("\n");

	return 0;
}