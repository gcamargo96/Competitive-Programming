#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

class RabbitStepping{
public:

	struct Rabbit{
		int pos, last;

		Rabbit() {}

		Rabbit(int _pos, int _last){
			pos = _pos;
			last = _last;
		}
	};

	const int N = 20;
	int n;
	string s;;
	vector<Rabbit> rab, rab2;
	int num = 0, den = 0;


	void solve(int len){
		if(len == 2){
			// if(rab2.size() > 0){
			// 	for(int i = 0; i < rab.size(); i++){
			// 		printf("%d ", rab[i].pos);
			// 	}
			// 	printf("-> ");
			// 	for(int i = 0; i < rab2.size(); i++){
			// 		printf("%d ", rab2[i].pos);
			// 	}
			// 	printf("\n");
			// }

			num += rab2.size();
			den++;
			return;
		}

		vi cnt(len, 0);
		for(int i = 0; i < rab2.size(); i++){
			Rabbit *r = &rab2[i];

			if(r->pos == 0){
				r->last = r->pos;
				r->pos++;
			}
			else if(r->pos == len-1 or r->pos == len-2){
				r->last = r->pos;
				r->pos--;
			}
			else if(s[r->pos] == 'W'){
				r->last = r->pos;
				r->pos--;
			}
			else if(s[r->pos] == 'B'){
				r->last = r->pos;
				r->pos++;
			}
			else if(s[r->pos] == 'R'){
				if(r->last == r->pos){
					r->last = r->pos;
					r->pos--;
				}
				else{
					swap(r->pos, r->last);
				}
			}

			cnt[r->pos]++;
		}

		for(int i = rab2.size()-1; i >= 0; i--){
			Rabbit r = rab2[i];

			if(cnt[r.pos] > 1){
				rab2.erase(rab2.begin()+i);
			}
		}

		solve(len-1);	
	}

	void place(int i, int r){
		if(i == s.size()){
			if(r == 0){
				// for(int i = 0; i < rab.size(); i++){
				// 	printf("%d ", rab[i].pos);
				// }
				// printf("-> ");

				rab2 = rab;
				solve(s.size());
			}
			return;
		}

		place(i+1, r);
		if(r > 0){
			rab.eb(i, i);
			place(i+1, r-1);
			rab.pop_back();
		}
	}

	double getExpected(string field, int r){
		s = field;
		n = r;

		place(0, n);

		return double(num)/double(den);
	}
};

string s;
int n;

int main(void){
	cin >> s >> n;

	RabbitStepping rs;

	printf("%.10lf\n", rs.getExpected(s, n));

	return 0;
}