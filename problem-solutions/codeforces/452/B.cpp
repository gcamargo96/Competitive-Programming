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

const int N = 12*9;
int v[N];
int n;

int months[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	bool ans = 0;
	for(int i = 0; i < N - n; i++){
		bool ok = 1;
		for(int j = 0; j < n; j++){
			if(v[j] != months[i+j]){
				ok = 0;
				break;
			}
		}
		if(ok){
			ans = 1;
			break;
		}
	}

	if(ans)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}