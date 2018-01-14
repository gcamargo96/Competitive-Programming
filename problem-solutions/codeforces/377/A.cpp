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

ll k, r;

int main(void){
	ios_base::sync_with_stdio(false);
	//scanf("%lld%lld", &k, &r);	
	cin >> k >> r;

	if(k == r){
		//printf("1\n");
		cout << "1" << endl;
		return 0;
	}

	int i;
	int flag = 0;
	for(i = 1; i < 1050; i++){
		if((k*i)%10 == 0){
			flag = 0;
			break;
		}
		if((k*i)%10 == r){
			flag = 1;
			break;
		}
	}

	//printf("%d\n", i);
	cout << i << endl;

	return 0;
}

