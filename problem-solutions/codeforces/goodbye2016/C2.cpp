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

const int N = 200002;
int n;
int c[N], d[N];
int rating, divs;
bool inf;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &c[i], &d[i]);
	}
	
	int Div;
	int sum1 = 0, sum2 = 0;
	if(d[0] == 1){
		inf = 1;
		rating = INF;
		Div = 1;
		sum1 = c[0];
	}
	else{
		rating = 1899;
		Div = 2;
		sum2 = c[0];
	}

	bool ok = 1;
	for(int i = 1; i < n; i++){
		rating += c[i-1];
		
		if(d[i] == 1 and Div == 2) sum1 = 0;
		if(d[i] == 2 and Div == 1) sum2 = 0;

		if(d[i] == 1) sum1 += c[i];
		if(d[i] == 2) sum2 += c[i];

		//if(Div == 2 and sum1 < 0 and sum2 > abs(sum1)) ok = 0;

		if(d[i] == 2 and inf == 1){
			rating = 1899;
			inf = 0;
		}
		else{
			//if(Div == 1 and rating < 1900) ok = 0;
			//if(Div == 2 and rating >= 1900) ok = 0;
		}
		
		Div = d[i];
	}

	//if(Div == 1 and rating < 1900) ok = 0;
	//if(Div == 2 and rating >= 1900) ok = 0;

	if(ok and !inf){
		cout << rating << endl;
	}
	else if(ok and inf){
		cout << "Infinity" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}

	return 0;
}

