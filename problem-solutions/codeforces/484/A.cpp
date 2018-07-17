#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
int n;
char s[N];

int main(void){
	scanf("%d", &n);

	s[0] = s[n+1] = '0';
	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
	}

	bool ok = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1' and (s[i-1] == '1' or s[i+1] == '1')){
			ok = 0;
		}
	}

	if(!ok){
		printf("No\n");
		return 0;
	}

	for(int i = 1; i <= n; i++){
		if(s[i] == '1') continue;

		int dl = 1, j;
		for(j = i-1; j >= 1 and s[j] == '0'; j--){
			dl++;
		}
		if(j == 0){
			dl = INF;
		}

		int dr = 1;
		for(j = i+1; j <= n and s[j] == '0'; j++){
			dr++;
		}
		if(j == n+1){
			dr = INF;
		}

		// printf("%d: %d %d\n", i, dl, dr);
		if(dr >= 2 and dl >= 2){
			ok = 0;
		}
	}

	if(ok){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}


	return 0;
}