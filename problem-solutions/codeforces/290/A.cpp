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

int n, m;

int main(void){
	//ios_base::sync-with_stdio(false);
	//cin >> n >> m;
	scanf("%d%d", &n,&m);

	bool turn = 0;
	For(i,1,n+1){
		For(j,1,m+1){
			if(i%2 == 1){
				printf("#");
			}
			else{
				if(j == m and !turn){
					printf("#");
					//turn = !turn;
				}
				else if(j == 1 and turn){
					printf("#");
					//turn = !turn;
				}
				else{
					printf(".");
				}

				if(j == m) turn = !turn;
			}
		}
		printf("\n");
	}

	return 0;
}
