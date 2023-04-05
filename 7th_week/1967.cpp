#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge{
	int c;
	int w;
};

vector<edge> arr[10001];
int most = 0;

int func(int cur){
	if(arr[cur].size() == 0) return 0;
	
	int first = 0;
	int second = 0;
	
	for(int i = 0; i < arr[cur].size(); i++){
		int temp = func(arr[cur][i].c) + arr[cur][i].w;
		
		if(first < temp){
			second = first;
			first = temp;
		}else if(second < temp) second = temp;
	}
	
	if(most < first + second) most = first + second;
	return first;
}

int main(){
	int n;
	cin >> n;
	int a, b, c;
	for(int i = 1; i <= n; i++)
		arr[i] = vector<edge>();
	for(int i = 1; i < n; i++){
		cin >> a >> b >> c;
		arr[a].push_back({b,c});
		most = max(most, c);
	}
	
	most = max(most, func(1));
	cout << most << endl;
	return 0;
}
