#include <bits/stdc++.h>
using namespace std;

class EllysSocks{
	public:
		int getDifference(vector<int> S,int P){
			sort(S.begin(), S.end());
			int vis[1005], res = 0;
			memset(vis,0,sizeof(vis));
			for(int i = 0; i < P; i++){
				int menor = 1000000001, dir = 0, esq = 0;
				for(int j = 0; j < S.size()-1; j++){
					if(S[j+1]-S[j] < menor and !vis[j] and !vis[j+1]){
						menor = S[j+1]-S[j];
						esq = j;
						dir = j+1;
					}
					//vis[esq] = 1;
					//vis[dir] = 1;
				}
				if(res < menor and menor < 1000000000){
					res = menor;
				}

					vis[esq] = 1;
					vis[dir] = 1;
			}	
			
			return res;
		}
};

int main(void){
	EllysSocks E;
	vector<int> v;
	int p, n, x;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	cin >> p;
	

	int res = E.getDifference(v, p);
	cout << res << endl;

	return 0;
}
