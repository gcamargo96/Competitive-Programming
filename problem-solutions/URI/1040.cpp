#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double n1, n2, n3, n4;
double media;

int main(void){
	cin >> n1 >> n2 >> n3 >> n4;

	media = (n1*2.0 + n2*3.0 + n3*4.0 + n4*1.0)/10.0;
	cout << "Media: " << fixed << setprecision(1) << media << endl;

	if(media >= 7.0){
		cout << "Aluno aprovado." << endl;
	}
	else if(media < 5.0){
		cout << "Aluno reprovado." << endl;
	}
	else{
		cout << "Aluno em exame." << endl;

		double ne;
		cin >> ne;
		cout << "Nota do exame: " << ne << endl;

		media = (media+ne)/2.0;

		if(media >= 5.0){
			cout << "Aluno aprovado." << endl;
		}
		else{
			cout << "Aluno reprovado." << endl;
		}

		cout << "Media final: " << fixed << setprecision(1) << media << endl;
	}

	return 0;
}