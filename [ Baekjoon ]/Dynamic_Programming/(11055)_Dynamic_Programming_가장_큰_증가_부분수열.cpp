#include <iostream>
using namespace std;

int arr[1001];
int sum[1001] = { 0, };

int Min(int a, int b) {
    return (a > b ? b : a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        sum[i] = arr[i];
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                if (sum[i] < arr[i] + sum[j])
                    sum[i] = arr[i] + sum[j];

        if (answer < sum[i])
            answer = sum[i];
    }
    cout << answer;
    return 0;
}
