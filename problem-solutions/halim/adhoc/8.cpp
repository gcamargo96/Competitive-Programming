#include <bits/stdc++.h>
using namespace std;

int n, p, cont = 1;
//string requirements[1005];
//string proposals[1005];

int main(void){
	ios_base::sync_with_stdio(false);

	while(1){
		cin >> n >> p;
		if(n == 0 and p == 0) break;
		else if(cont > 1) cout << endl;

		cin.get();
		string requirements;
		for(int i = 0; i < n; i++){
			//cin >> requirements[i];
			getline(cin, requirements);
		}
		double price, bestcomp = 0, bestprice = 0;
	   	string bestprop;
		int r;
		string req, proposal;
		for(int i = 0; i < p; i++){
			//cin >> proposals[i];
			getline(cin, proposal);
			//cout << "debugando: " << proposal << endl;
			cin >> price >> r;
			//cout << price << endl;
			cin.get();
			for(int j = 0; j < r; j++){
				getline(cin, req);
			}
			double complience;
			complience = (double)r/(double)n;
			//cout << "complience = " << complience << endl;

			if(complience > bestcomp){
				bestcomp = complience;
				bestprice = price;
				bestprop = proposal;
				//cout << "debug" << endl;
				//cout << bestprop << " " << proposal;
			}	
			else if(complience == bestcomp){
				if(price < bestprice){
					bestcomp = complience;
					bestprice = price;
					bestprop = proposal;
				}
			}
		}
		cout << "RFP #" << cont++ << endl << bestprop << endl;
	}

	return 0;
}
