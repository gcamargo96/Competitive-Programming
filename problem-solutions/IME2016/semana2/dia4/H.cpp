#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back

const int N = 52;
int n, x;
int p1[N][N], p2[N][N], p3[N][N];
string s;

int main(){
	ios_base::sync_with_stdio(false);	

	int caso = 1;
	while(cin >> n, n != 0){
		for(int i = 1; i <= n; i++){	
			cin >> s;
			for(int j = 1; j <= 2*i-1; j++){
				p1[i][j] = s[j-1] - '0';
			}
		}	
		
		For(i, 1, n+1){
			p2[n-i+1][1] = p1[i][2*i-1];
			int cnt = 2;
			For(j, i+1, n+1){
				for(int k = 2*i; k > 2*i-2; k--){
					p2[n-i+1][cnt++] = p1[j][k];
				}
			}
		}

		For(i, 1, n+1){
			p3[n-i+1][1] = p2[i][2*i-1];
			int cnt = 2;
			For(j, i+1, n+1){
				for(int k = 2*i; k > 2*i-2; k--){
					p3[n-i+1][cnt++] = p2[j][k];
				}
			}
		}

		/*For(i, 1, n+1){
			For(j, 1, 2*i){
				cout << p1[i][j];
			}
			cout << endl;
		}
		cout << endl;*/

		bool flag = 1, res = 0;
		For(i, 1, n+1){
			bool one = 0;
			For(j, 1, 2*i){
				if(p1[i][j] == 1) one = 1;
				if(one and p1[i][j] == 0) flag = 0;
			}
		}
		if(flag) res = 1;
		
		flag = 1;
		For(i, 1, n+1){
			bool zero = 0;
			For(j, 1, 2*i){
				if(p1[i][j] == 0) zero = 1;
				if(zero and p1[i][j] == 1) flag = 0;
			}
		}
		if(flag) res = 1;


		flag = 1;
		For(i, 1, n+1){
			bool one = 0;
			For(j, 1, 2*i){
				if(p2[i][j] == 1) one = 1;
				if(one and p2[i][j] == 0) flag = 0;
			}
		}
		if(flag) res = 1;
		
		flag = 1;
		For(i, 1, n+1){
			bool zero = 0;
			For(j, 1, 2*i){
				if(p2[i][j] == 0) zero = 1;
				if(zero and p2[i][j] == 1) flag = 0;
			}
		}
		if(flag) res = 1;
		
		flag = 1;
		For(i, 1, n+1){
			bool one = 0;
			For(j, 1, 2*i){
				if(p3[i][j] == 1) one = 1;
				if(one and p3[i][j] == 0) flag = 0;
			}
		}
		if(flag) res = 1;
		
		flag = 1;
		For(i, 1, n+1){
			bool zero = 0;
			For(j, 1, 2*i){
				if(p3[i][j] == 0) zero = 1;
				if(zero and p3[i][j] == 1) flag = 0;
			}
		}
		if(flag) res = 1;

		cout << "Puzzle " << caso++ << endl;	
		if(res) cout << "Parts can be separated" << endl;
		else cout << "Parts cannot be separated" << endl;
		cout << endl;
	}
	

	return 0;
}
