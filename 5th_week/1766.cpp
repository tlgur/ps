#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int available[32001] = {0,};;
priority_queue<int, vector<int>, greater<int>> pq[32001];

void p(int index){
	cout << index << ' ';
	available[index] = 200000;
	while(!pq[index].empty()){
		int i = pq[index].top();
		pq[index].pop();
		available[i]--;
	}
}

void print(priority_queue<int, vector<int>, greater<int>> q){
	while(!q.empty()){
		cout << q.top() << ' ';
		q.pop();
	}
}

void printA(int n){
	for(int i = 1; i <= n; i++)
		cout << available[i] << ' ';
	cout << endl;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		pq[i] = priority_queue<int, vector<int>, greater<int>>();

	for(int a, b, i = 0; i < m; i++){
		cin >> a >> b;
		if(a == b) continue;
		pq[a].push(b);
		available[b]++;
	}

	printA(n);

	for(int i = 1; i <= n; i++){
		if(available[i]) continue;
		else{
			p(i);
			i = 0;
		}
	}
	cout << endl;
	return 0;
}
