#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    cin >> N;

    vector<pair<int, int>> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int max = -1;

    for(int i = 0; i < N; i++) {
        if(max < A[i].second - i) max = A[i].second - i;
    }

    cout << max + 1;

    return 0;
}
