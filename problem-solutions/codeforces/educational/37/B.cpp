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

int t, n;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		int l, r;
		queue<ii> q;
		for(int i = 1; i <= n; i++){
			scanf("%d%d", &l, &r);
			q.push(ii(l, r));
		}

		int temp = 1;
		while(!q.empty()){
			int l = q.front().fi;
			int r = q.front().se;
			q.pop();

			if(temp < l){
				temp = l;
			}

			if(temp > r){
				printf("0 ");
				continue;
			}
			else{
				printf("%d ", temp);
			}
			temp++;
		}
		printf("\n");
	}

	return 0;
}