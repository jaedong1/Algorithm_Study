#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& A, int S, int E, int K);
int partition(vector<int>& A, int S, int E);
void swap(vector<int>& A, int S, int E);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    quick_sort(A, 0, N - 1, K - 1);

    cout << A[K - 1];
}

void quick_sort(vector<int>& A, int S, int E, int K) {
    int pivot = partition(A, S, E);

    if(pivot == K) return;
    else if(pivot > K) {
        quick_sort(A, S, pivot - 1, K);
    } else {
        quick_sort(A, pivot + 1, E, K);
    }
}

int partition(vector<int>& A, int S, int E) {
    if(S + 1 == E) {
        if(A[S] > A[E]) swap(A, S, E);
        return E;
    }

    int i = S + 1, j = E;
    int M = (S + E) / 2;

    int pivot = A[M];
    swap(A, S, M);

    while(i <= j) {
        while((A[i] < pivot) && (i < E)) i++;
        while((A[j] > pivot) && (j > S)) j--;

        if(i < j) {
            swap(A, i++, j--);
        } else {
            break;
        }
    }

    swap(A, S, j);
    return j;
}

void swap(vector<int>& A, int S, int E) {
    int temp = A[S];
    A[S] = A[E];
    A[E] = temp;
}
