#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define I 0
#define V 1

const int N = 200002;
int n;
int v[N];
int pr = -1, ult = -1;
bool achou;
int neg = 0;

int main(void){
	scanf("%d%d", &n, &k);


	For(i,0,n){
		scanf("%d", &v[i]);
		if(v[i] < 0){
			neg++;
			if(!achou){
				achou = 1;
				pr = i;
			}
			ult = i;
		}
	}

	if(pr == -1 and ult == -1){
		printf("0\n");
		return 0;
	}
	if(neg > k){
		printf("-1\n");
		return 0;
	}

	int tam = ult-pr+1, res = 0;
	bool state = V;
	for(int i = pr; i <= ult; i++){
		if(v[i] < 0 and state == V){
			state = I;
			res++;
		}
		if(v[i] >= 0 and 
	}

	return 0;
}

