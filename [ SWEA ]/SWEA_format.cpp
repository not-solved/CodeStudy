#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string test1 = "123456";
	string test2 = test1.substr(0, 3);
	cout << test2;
	return 0;
}