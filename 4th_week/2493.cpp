#include <iostream>
#include <stack>
#include <utility>

using namespace std;


int main(){
	stack<pair<int, int>> s;
	int n;
	cin >> n;
	int temp;
	cin >> temp;
	s.push({1, temp});
	cout << 0 << ' ';

	for(int i = 2; i <= n; i++){
		cin >> temp;
		while(!s.empty() && s.top().second < temp){
			s.pop();
		}
		if(s.empty()) cout << 0 << ' ';
		else cout << s.top().first << ' ';
		s.push({i, temp});
	}
	cout << endl;
	return 0;
}
