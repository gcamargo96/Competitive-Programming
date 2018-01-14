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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, p, t;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &p);

		int easy = p/2;
		int hard = p/10;

		int x;
		int cnt_easy = 0, cnt_hard = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			if(x >= easy) cnt_easy++;
			if(x <= hard) cnt_hard++;
		}

		if(cnt_easy == 1 and cnt_hard == 2){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}