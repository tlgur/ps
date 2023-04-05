#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
	int n;
	int w;
};

vector<edge> arr[100001];
bool visit[100001] = {0,};
int most = 0;
int node[2][100001] ={0,};

int func(int cur){
	visit[cur] = 1;
	for(int i = 0; i < arr[cur].size(); i++){
		if(visit[arr[cur][i].n]) continue;
		int temp = func(arr[cur][i].n) + arr[cur][i].w;
		if(temp > node[0][cur]){
			node[1][cur] = node[0][cur];
			node[0][cur] = temp;
		}else if(temp > node[1][cur]) node[1][cur] = temp;
	}
	most = max(most, node[0][cur] + node[1][cur]);
	return node[0][cur];
}

int main(){
	int v;
	cin >> v;
	
	for(int i = 1; i <= v; i++){
		int index;
		cin >> index;
		arr[index] = vector<edge>();
		int temp = 0;
		int val = 0;
		while(1){
			cin >> temp;
			if(temp == -1) break;
			cin >> val;
			arr[index].push_back({temp, val});
		}
	}
	
	most = max(most, func(1));
	cout << most << endl;
	return 0;
}
