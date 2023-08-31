#include <iostream>
#include <vector>

using namespace std;

int trappedWater(const vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) {
        return 0;  // Cannot trap water with less than 3 blocks
    }

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return trappedWater;
}

int main() {
    int N;
    cout << "Enter the number of blocks: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the height of each block: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int waterTrapped = trappedWater(arr);
    cout << "The amount of water trapped is: " << waterTrapped << endl;

    return 0;
}
