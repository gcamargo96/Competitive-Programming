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

int n;

int main(void){
	scanf("%d", &n);

	if(n == 2){
		printf("1\n");
		return 0;
	}
	if(n == 3){
		printf("3\n");
		return 0;
	}
	if(n == 4){
		printf("6\n");
		return 0;
	}


	int maxsum = n-1 + n;

	int aux = maxsum;
	bool sonove = 1;
	string num;
	while(aux > 0){
		int d = aux%10;
		if(d != 9)
			sonove = 0;
		
		num += d+'0';
		aux /= 10;
	}

	if(sonove){
		printf("1\n");
		return 0;
	}

	reverse(num.begin(), num.end());

	// desconsiderando o primeiro digito
	sonove = 1, aux = maxsum;
	while(aux > 9){
		int d = aux%10;
		if(d != 9)
			sonove = 0;
		aux /= 10;
	}

	if(!sonove){
		num[0]--;
		for(int i = 1; i < num.size(); i++){
			num[i] = '9';
		}
	}

	int largest = stoi(num);

	// cout << "num = " << num << endl;

	ll ans = 0;

	while(num[0] >= '0'){
		int cur = stoi(num);
		ans += (cur-1)/2;
		if(n < cur){
			ans -= (cur-n)-1;
		}
		num[0]--;
	}

	cout << ans << endl;

	return 0;
}