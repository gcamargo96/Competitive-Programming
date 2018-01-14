#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n;

int main(void){
	while(scanf("%d", &n), n != 0){
		int a = 0, b = 0;
		int vez = 0;
		For(i,0,31){
			/*if(vez == -1 and (n & (1 << i))){
				if(i%2 == 1){
					a |= (1 << i);
					vez = 1;
				}
				else{
					b |= (1 << i);
					vez = 0;
				}
			}*/
			if(vez == 0 and (n & (1 << i))){
				a |= (1 << i);
				vez = 1;
			}
			else if(vez == 1 and (n & (1 << i))){
				b |= (1 << i);
				vez = 0;
			}
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
