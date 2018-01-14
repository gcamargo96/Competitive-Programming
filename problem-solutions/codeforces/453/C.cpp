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

const int N = 200002;
int h;
int v[N], sum[N];

int main(void){
	scanf("%d", &h);

	int n = 0;
	for(int i = 0; i < h+1; i++){
		scanf("%d", &v[i]);
		n += v[i];

		if(i == 0)
			sum[0] = v[i];
		else
			sum[i] = sum[i-1] + v[i];
	}

	bool ans = 1;
	for(int i = 1; i < h+1; i++){
		if(v[i-1] > 1 and v[i] > 1){
			ans = 0;
			break;
		}
	}

	if(ans){
		printf("perfect\n");
	}
	else{
		printf("ambiguous\n");
		printf("0 ");
		for(int i = 1; i <= h; i++){
			for(int j = 0; j < v[i]; j++){
				printf("%d ", sum[i-1] - v[i-1] + 1);
			}
		}
		printf("\n");

		printf("0 ");
		for(int i = 1; i <= h; i++){
			for(int j = 0; j < v[i]/2; j++){
				printf("%d ", sum[i-1] - v[i-1] + 1);
			}
			for(int j = v[i]/2; j < v[i]; j++){
				printf("%d ", sum[i-1]);
			}
		}
		printf("\n");
	}

	return 0;
}