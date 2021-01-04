#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> Deck;
    int size;
    cin >> size;
    for (int i = 1; i <= size; i++)
        Deck.push(i);
    int idx = 0;
    while (Deck.size() > 1) {
        cout << Deck.front() << ' ';
        Deck.pop();
        Deck.push(Deck.front());
        Deck.pop();
    }
    cout << Deck.front();
    return 0;
}