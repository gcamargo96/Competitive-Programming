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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, k;
int m[102][102];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j and k >= 1){
				m[i][j] = 1;
				k--;
			}
			else if(!m[i][j] and !m[j][i] and k >= 2){
				m[i][j] = m[j][i] = 1;
				k -= 2;
			}
		}
	}	

	if(k == 0){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%d ", m[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("-1\n");
	}

	return 0;
}