#include <bits/stdc++.h> 
using namespace std;

bool binary_search(const vector<int>& A, int X) {
    int low = 0, high = A.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == X) {
            return true;
        } else if (A[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < Q; ++i) {
        int X;
        cin >> X;
        if (binary_search(A, X)) {
            cout << "found" << endl;
        } else {
            cout << "not found" << endl;
        }
    }
    return 0;
}

// vector<long long> prefix_sum_array(const vector<int>& A) {
//     int N = A.size();
//     vector<long long> prefix_sum(N);
//     prefix_sum[0] = A[0];
//     for (int i = 1; i < N; ++i) {
//         prefix_sum[i] = prefix_sum[i - 1] + A[i];
//     }
//     return prefix_sum;
// }

// vector<long long> range_sum_queries(const vector<int>& A, const vector<pair<int, int>>& queries) {
//     vector<long long> prefix_sum = prefix_sum_array(A);
//     vector<long long> results;
//     for (const auto& query : queries) {
//         int L = query.first;
//         int R = query.second;
//         if (L > 1) {
//             results.push_back(prefix_sum[R - 1] - prefix_sum[L - 2]);
//         } else {
//             results.push_back(prefix_sum[R - 1]);
//         }
//     }
//     return results;
// }

// int main() {
//     int N, Q;
//     cin >> N >> Q;
//     vector<int> A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }
//     vector<pair<int, int>> queries(Q);
//     for (int i = 0; i < Q; ++i) {
//         cin >> queries[i].first >> queries[i].second;
//     }
//     vector<long long> results = range_sum_queries(A, queries);
//     for (const auto& result : results) {
//         cout << result << endl;
//     }
//     return 0;
// }
