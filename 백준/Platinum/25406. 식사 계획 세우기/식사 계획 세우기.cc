#include <bits/stdc++.h>
using namespace std;
vector< queue<int> > v;
int plan[321098];
int num[321098];
int a[321098];
int cntfromsize[321098];
int cntfromnumber[321098];
int n;

struct rest{
	int idx, minnum, size;
	friend bool operator<(const rest& a, const rest& b){
		if(a.size == b.size){
		  return a.minnum > b.minnum;
		}
		return a.size < b.size;
	}
};

struct Rest{
	int idx, minnum, size;
	friend bool operator<(const Rest& a, const Rest& b){
		if(a.minnum == b.minnum){
			return a.size < b.size;
		}
		return a.minnum > b.minnum;
	}
};

priority_queue<rest> pq_by_size;
priority_queue<Rest> pq_by_number;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> n;
	v.resize(n+1);
	int m = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v[a[i]].push(i);
		num[a[i]]++;
		if(num[a[i]] > m) m = num[a[i]];
	}
	if(n%2){
		if(m > n/2+1) return !(cout << -1);
	}
	else{
		if(m > n/2) return !(cout << -1);
	}
	for(int i = 1; i <= n; i++){
		if(num[i]){
			rest r;
			Rest R;
			r.idx = R.idx = i;
			r.minnum = R.minnum = v[i].front();
			r.size = R.size = num[i];
			pq_by_size.push(r);
			pq_by_number.push(R);
		}
	}

	int lastidx = 0;
	rest remain;
	Rest Remain;
	bool re = false;
	bool Re = false;
	for(int i = n; i > 0; i--){
		int t = pq_by_size.top().size;
		if((t >= i/2+i%2 && i%2 == 1) || (t > i/2 && t%2 == 0)){
			rest p = pq_by_size.top();
			pq_by_size.pop();
			if(cntfromnumber[p.idx]){
				p.minnum = v[p.idx].front();
				p.size -= cntfromnumber[p.idx];
				cntfromnumber[p.idx] = 0;
				if(p.size > 0) pq_by_size.push(p);
				i++;
				continue;
			}
			else if(lastidx == p.idx){
				re = true;
				remain = p;
				i++;
				continue;
			}
			else{
				cout << p.minnum << ' ';
				v[p.idx].pop();
				p.minnum = v[p.idx].front();
				p.size--;
				lastidx = p.idx;
				if(p.size > 0) pq_by_size.push(p);
				cntfromsize[p.idx]++;
			}
		}

		else{
		   Rest p = pq_by_number.top();
			pq_by_number.pop();
			if(cntfromsize[p.idx]){
				p.minnum = v[p.idx].front();
				p.size -= cntfromsize[p.idx];
				cntfromsize[p.idx] = 0;
				if(p.size > 0) pq_by_number.push(p);
				i++;
				continue;
			}
			else if(lastidx == p.idx){
				Re = true;
				Remain = p;
				i++;
				continue;
			}
			else{
				cout << p.minnum << ' ';
				v[p.idx].pop();
				p.minnum = v[p.idx].front();
				p.size--;
				lastidx = p.idx;
				if(p.size > 0) pq_by_number.push(p);
				cntfromnumber[p.idx]++;
			}
		}
		if(re) pq_by_size.push(remain);
		if(Re) pq_by_number.push(Remain);
		re = Re = false;
	}
}