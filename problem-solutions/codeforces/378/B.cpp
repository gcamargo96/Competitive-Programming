#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, L, R;

struct info{
	int l, r, diff, pos;
};

info ml, mr;

int main(void){
	scanf("%d", &n);

	int l, r;
	For(i,0,n){
		scanf("%d%d", &l, &r);
		L += l, R += r;
		if(ml.diff < l-r){
			ml.diff = l-r;
			ml.l = l;
			ml.r = r;
			ml.pos = i+1;
		}
		if(mr.diff < r-l){
			mr.diff = r-l;
			mr.l = l;
			mr.r = r;
			mr.pos = i+1;
		}
	}

	/*printf("L = %d / R = %d\n", L, R);
	printf("ml.diff = %d / mr.diff = %d\n", ml.diff, mr.diff);
	printf("ml.l = %d / ml.r = %d\n", ml.l, ml.r);
	printf("mr.l = %d / mr.r = %d\n", mr.l, mr.r);
	*/
	
	if(ml.diff == 0 or mr.diff == 0){
		printf("0\n");
	}
	else if((L - mr.l + mr.r) - (R - mr.r + mr.l) > (R - ml.r + ml.l) - (L - ml.l + ml.r)){
		//else{
			printf("%d\n", mr.pos);
		//}
	}
	else{
		//else{
			printf("%d\n", ml.pos);
		//}
	}

	return 0;
}

