#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int loop;
	cin >> loop;
	while(loop--) {
		int schools;
		cin >> schools;
		string sch, result;
		int drink, max_drink = 0;
		while(schools--) {
			cin >> sch >> drink;
			if(drink > max_drink) {
				result = sch;
				max_drink = drink;
			}
		}
		cout << result << '\n';
	}
	
	return 0;
}