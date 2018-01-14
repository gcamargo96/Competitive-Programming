#include <bits/stdc++.h>
using namespace std;

#define BEG 0
#define END 1
#define endl "\n"

int c1, c2, c3;
double t1, t3;

struct event{
	int t;
	int tipo;

	event() {}

	event(int _t, int _tipo){
		t = _t;
		tipo = _tipo;
	}

	bool operator<(const event& b) const{
		if(t == b.t) return tipo < b.tipo;
		return t < b.t;	
	}
};

int main(void){
	scanf("%d%d%d", &c1, &c2, &c3);
	scanf("%lf%lf", &t3, &t1);

	for(int i = 0; i <  1000; i++){
		for(int j = 0; j < 1000; j++){
			// printf("loop");
			int tempo[4];
			tempo[0] = 0, tempo[1] = 0, tempo[2] = 0, tempo[3] = 0;
			vector<event> pq;
			
			pq.emplace_back(0, BEG);
			pq.emplace_back(2*c1, END);

			pq.emplace_back(i, BEG);
			pq.emplace_back(i+2*c2, END);

			pq.emplace_back(j, BEG);
			pq.emplace_back(j+2*c3, END);

			sort(pq.begin(), pq.end());

			int cnt = 0;
			int last = 0;
			for(int k = 0; k < pq.size(); k++){
				event cur = pq[k];
				// pq.pop();

				if(cur.tipo == BEG){
					if(cnt > 0){
						tempo[cnt] += cur.t - last;
					}
					last = cur.t;
					cnt++;
				}
				else{
					tempo[cnt] += cur.t - last;
					last = cur.t;
					cnt--;
				}
			}

			// printf("t1 = %lf / t2 = %lf / t3 = %lf\n", tempo[1], tempo[2], tempo[3]);
			if(tempo[1]/2.0 == t1 and tempo[3]/2.0 == t3){
				cout << (double) tempo[2]/2.0 << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i <  1000; i++){
		for(int j = 0; j < 1000; j++){
			// printf("loop");
			int tempo[4];
			tempo[0] = 0, tempo[1] = 0, tempo[2] = 0, tempo[3] = 0;
			vector<event> pq;
			
			pq.emplace_back(0, BEG);
			pq.emplace_back(2*c2, END);

			pq.emplace_back(i, BEG);
			pq.emplace_back(i+2*c1, END);

			pq.emplace_back(j, BEG);
			pq.emplace_back(j+2*c3, END);

			sort(pq.begin(), pq.end());

			int cnt = 0;
			int last = 0;
			for(int k = 0; k < pq.size(); k++){
				event cur = pq[k];
				// pq.pop();

				if(cur.tipo == BEG){
					if(cnt > 0){
						tempo[cnt] += cur.t - last;
					}
					last = cur.t;
					cnt++;
				}
				else{
					tempo[cnt] += cur.t - last;
					last = cur.t;
					cnt--;
				}
			}

			// printf("t1 = %lf / t2 = %lf / t3 = %lf\n", tempo[1], tempo[2], tempo[3]);
			if(tempo[1]/2.0 == t1 and tempo[3]/2.0 == t3){
				cout << (double) tempo[2]/2.0 << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i <  1000; i++){
		for(int j = 0; j < 1000; j++){
			// printf("loop");
			int tempo[4];
			tempo[0] = 0, tempo[1] = 0, tempo[2] = 0, tempo[3] = 0;
			vector<event> pq;
			
			pq.emplace_back(0, BEG);
			pq.emplace_back(2*c3, END);

			pq.emplace_back(i, BEG);
			pq.emplace_back(i+2*c1, END);

			pq.emplace_back(j, BEG);
			pq.emplace_back(j+2*c2, END);
			
			sort(pq.begin(), pq.end());

			int cnt = 0;
			int last = 0;
			for(int k = 0; k < pq.size(); k++){
				event cur = pq[k];
				// pq.pop();

				if(cur.tipo == BEG){
					if(cnt > 0){
						tempo[cnt] += cur.t - last;
					}
					last = cur.t;
					cnt++;
				}
				else{
					tempo[cnt] += cur.t - last;
					last = cur.t;
					cnt--;
				}
			}

			// printf("t1 = %lf / t2 = %lf / t3 = %lf\n", tempo[1], tempo[2], tempo[3]);
			if(tempo[1]/2.0 == t1 and tempo[3]/2.0 == t3){
				cout << (double) tempo[2]/2.0 << endl;
				return 0;
			}
		}
	}

	return 0;
}