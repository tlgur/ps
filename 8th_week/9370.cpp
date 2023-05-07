#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
vector<pair<int, int>> graph[2001];


void print(int s, int n, vector<int> & v){
	cout << "==================distance from : " << s << "================" << endl;
	for(int i = 1; i <= n; i++)
		cout << i << '\t';
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << v[i] << '\t';
	cout << endl;
}


void Dijkstra(int start, vector<int>& distance, PQ& pq){
	int cnt = 0;
	for(int i = 0; i < graph[start].size(); i++){
		int node = graph[start][i].first;
		int w = graph[start][i].second;

		if(distance[node] >= distance[start] + w){
			distance[node] = distance[start] + w;
			pq.push({distance[node], node});
		}
	}
	if(pq.empty()) return;
	int next_node =  pq.top().second;
	pq.pop();
	
	Dijkstra(next_node, distance, pq);
}

int main(){
	int T;
	cin >> T;
	int n, m, t;
	
	int s, g, h;
	int a, b, d;
	int x;
	while(T--){
		int gToH;
		vector<int> sToAll(2001, INT_MAX);
		vector<int> maxToAll(2001, INT_MAX);
		cin >> n >> m >> t;
		for(int i = 1; i <= n; i++)
			graph[i] = vector<pair<int, int>>();
		cin >> s >> g >> h;
		
		for(int i = 0; i < m; i++){
			cin >> a >> b >> d;
			graph[a].push_back({b, d});
			graph[b].push_back({a, d});
			if(a == g && b == h) gToH = d;
			else if(b == g && a == h) gToH = d;
		}
		PQ pq;
		sToAll[s] = 0;
		Dijkstra(s, sToAll, pq);
		pq = PQ();
		int mid_end = g, mid_start = h;
		if(sToAll[g] > sToAll[h]) swap(mid_end, mid_start);
		maxToAll[mid_start] = 0;
		Dijkstra(mid_start, maxToAll, pq);	
		
		vector<int> r;
		for(int i = 0; i < t; i++){
			cin >> x;
			int left = sToAll[x];
			int right = sToAll[mid_end] + gToH + maxToAll[x];
			if(left == right) r.push_back(x);
		}
		sort(r.begin(), r.end());
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << ' ';
		cout << endl;
	}
	return 0;
}
