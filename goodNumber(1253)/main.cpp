#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;

    vector<long> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        long now = A[i];
        int left = 0;
        int right = N - 1;

        while(left < right) {   //투 포인터 알고리즘
            if(A[left] + A[right] == now) {
                if((i != left) && (i != right)) {
                    count++;
                    break;
                } else if(i == left) {
                    left++;
                } else if(i == right) {
                    right--;
                }
            } else if (A[left] + A[right] < now) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << count;

    return 0;
}
