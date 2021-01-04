#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int max(int a, int b) {
    return (a > b ? a : b);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge, in_time;
    bridge.push(truck_weights[0]);
    in_time.push(1);
    int temp_weight = truck_weights[0];
    for (int i = 1; i < truck_weights.size(); i++) {
        if (truck_weights[i] + temp_weight <= weight) {
            if (bridge.size() == bridge_length) {
                temp_weight -= bridge.front();
                bridge.pop();
                in_time.pop();
            }
            temp_weight += truck_weights[i];
            bridge.push(truck_weights[i]);
            in_time.push(in_time.back() + 1);
        }
        else {
            while (temp_weight - bridge.front() + truck_weights[i] > weight) {
                if (bridge.size() == 1)
                    break;
                temp_weight -= bridge.front();
                bridge.pop();
                in_time.pop();
            }
            in_time.push(max(in_time.front() + bridge_length, in_time.back() + 1));
            in_time.pop();
            temp_weight -= bridge.front();
            bridge.pop();
            bridge.push(truck_weights[i]);
            temp_weight += truck_weights[i];
        }
    }
    return in_time.back() + bridge_length;
}