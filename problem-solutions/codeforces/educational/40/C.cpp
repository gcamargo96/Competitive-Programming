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
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		v[i]--;
	}

	set<int> dif;
	for(int i = 0; i < n-1; i++){
		int step = abs(v[i]-v[i+1]);
		if(step > 1){
			dif.insert(step);
		}
	}

	if(dif.size() > 1){
		printf("NO\n");
		return 0;
	}

	int x = 1000000000, y = (dif.size() > 0 ? *(dif.begin()) : 1000000000);

	bool ok = 1;
	for(int i = 1; i < n; i++){
		if(v[i] == v[i-1]){
			ok = 0;
		}
		if(v[i] == v[i-1]+1 and v[i-1]%y == y-1){ // ->
			// printf("1 i = %d\n", i);
			ok = 0;
		}
		if(v[i] == v[i-1]-1 and v[i-1]%y == 0){ // <-
			// printf("2 i = %d\n", i);
			ok = 0;
		}
	}

	if(ok){
		printf("YES\n");
		printf("%d %d\n", x, y);
	}
	else{
		printf("NO\n");
	}

	return 0;
}