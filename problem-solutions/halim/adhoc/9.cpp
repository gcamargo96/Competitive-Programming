#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	int a;
	while(cin >> a){
		if(a == 0) break;

		string dir, ponta = "+x";
	   	int x, y, z;

		for(int i = 0; i < a-1; i++){
			cin >> dir;
			if(dir == "+y"){
				if(ponta == "+x"){
					ponta = "+y";
				}
				else if(ponta == "-x"){
					ponta = "-y";
				}
				else if(ponta == "+y"){
					ponta = "-x";
				}
				else if(ponta == "-y"){
					ponta = "+x";
				}
			}
			if(dir == "-y"){
				if(ponta == "+x"){
					ponta = "-y";
				}
				else if(ponta == "-x"){
					ponta = "+y";
				}
				else if(ponta == "+y"){
					ponta = "+x";
				}
				else if(ponta == "-y"){
					ponta = "-x";
				}
			}
			if(dir == "+z"){
				if(ponta == "+x"){
					ponta = "+z";
				}
				else if(ponta == "-x"){
					ponta = "-z";
				}
				else if(ponta == "+z"){
					ponta = "-x";
				}
				else if(ponta == "-z"){
					ponta = "+x";
				}
			}
			if(dir == "-z"){
				if(ponta == "+x"){
					ponta = "-z";
				}
				else if(ponta == "-x"){
					ponta = "+z";
				}
				else if(ponta == "+z"){
					ponta = "+x";
				}
				else if(ponta == "-z"){
					ponta = "-x";
				}
			}
		}
		cout << ponta << endl;
	}

	return 0;
}
