#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

int a, b;

int main(void){
	scanf("%d%d", &a, &b);

	bool turn = 0;
	int amount = 1;
	while(1){
		if(turn == 0){
			if(a < amount){
				printf("Vladik\n");
				return 0;
			}
			a -= amount++;
		}
		else{
			if(b < amount){
				printf("Valera\n");
				return 0;
			}
			b -= amount++;
		}
		turn = !turn;
	}

	return 0;
}

