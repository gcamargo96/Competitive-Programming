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

int t, H, S;
int x, y, z;
char sinal;
string s;
double pd[22][402];
double ans = 0, res, razao;

int POW(int b, int e){
	int num = 1;
	For(i,0,e){
		num *= b;
	}
	return num;
}

double solve(int i, int dmg){
	if(i == x){
		if(dmg + z >= H){
			/*double razao = 1;
			For(j,0,x){
				razao /= y;
			}*/
			res += razao;
			return razao;
		}
		return 0;
	}

	double& dp = pd[i][dmg];
	if(dp != -1){
		res += dp;
		return dp;
	}
	
	double ret = 0;
	for(int j = 1; j <= y; j++){
		ret += solve(i+1, dmg+j);
	}

	return dp = ret;
}

int main(void){
	//ios_base::sync_with_stdio(false);
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> H >> S;
		
		ans = 0;
		For(i,0,S){
			cin >> s;
			
			x = 0, y = 0, z = 0;
		  	int j = 0;
			
			if(s[1] >= '0' and s[1] <= '9'){
				x = 10*(s[0]-'0') + s[1]-'0';
				j = 3;
			}
			else{
				x = s[0] - '0';
				j = 2;
			}

			if(j+1 < s.size() and s[j+1] >= '0' and s[j+1] <= '9'){
				y = 10*(s[j]-'0') + s[j+1]-'0';
				j += 2;
			}
			else{
				y = s[j]-'0';
				j += 1;
			}

			if(j < s.size()){
				sinal = s[j];
				j++;

				int tam = s.size()-j;
				while(j < s.size()){
					z += POW(10, tam-1) * (s[j]-'0');
					j++;
					tam--;
				}

				if(sinal == '-') z = -z;
			}

			res = 0;
			razao = 1;
			For(j,0,x){
				razao /= y;
			}
			For(l,0,22){
				For(m,0,402){
					pd[l][m] = -1;
				}
			}
			solve(0,0);
			
			ans = max(ans, res);
		}

		printf("Case #%d: %.6lf\n", caso, ans);
	}

	return 0;
}

