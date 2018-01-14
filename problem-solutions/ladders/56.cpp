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

string s;
int k;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> k;

	int res = 0, intervalo = 0;
	for(int i = 0; i < s.size()+k; i++){ // pos
		for(int j = 1; i+2*j-1 < s.size() + k; j++){ // n
			int cnt = 0;
			for(int l = i; l < i+j; l++){ // itera posicao a posicao
				if(l+j < s.size()){
					if(s[l] == s[l+j]) cnt++;
					else break;
				}
				else{
					cnt++;
				}
			}
			//cout << i << " " << j << " " << cnt << endl;
			if(cnt == j) res = max(res, 2*j);
		}
	}

	//printf("%d %d\n", intervalo, res);
	printf("%d\n", res);

	return 0;
}

