#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> seg;

// Build segment tree storing maximum value in each segment.
void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

// Query: find the first index in [ql, qr] with A[index] >= T.
// Returns -1 if no such index exists.
int query(int idx, int l, int r, int ql, int qr, int T) {
    if (ql > r || qr < l) return -1;  // out of range
    if (ql <= l && r <= qr) {
        if(seg[idx] < T) return -1;  // no element in this segment qualifies
        // Otherwise, drill down to find the first index.
        while(l < r) {
            int mid = (l + r) / 2;
            if(seg[2 * idx] >= T) {
                idx = 2 * idx;
                r = mid;
            } else {
                idx = 2 * idx + 1;
                l = mid + 1;
            }
        }
        return l;
    }
    int mid = (l + r) / 2;
    int leftAns = query(2 * idx, l, mid, ql, qr, T);
    if(leftAns != -1) return leftAns;
    return query(2 * idx + 1, mid + 1, r, ql, qr, T);
}

vector<int> solve(int n, int X, vector<int> A_in) {
    A = A_in;
    N = n;
    seg.assign(4 * N, 0);
    build(1, 0, N - 1);
    
    vector<int> result(N, -1);
    
    // For each index, perform two queries with threshold = A[i] + X.
    for (int i = 0; i < N; i++) {
        int threshold = A[i] + X;
        // Find first index j > i with A[j] >= threshold.
        int firstIdx = query(1, 0, N - 1, i + 1, N - 1, threshold);
        if(firstIdx == -1) {
            result[i] = -1;
            continue;
        }
        // Find next index k > firstIdx with A[k] >= threshold.
        int secondIdx = query(1, 0, N - 1, firstIdx + 1, N - 1, threshold);
        if(secondIdx == -1)
            result[i] = -1;
        else
            result[i] = A[secondIdx];
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X;
    cin >> N >> X;
    vector<int> A_in(N);
    for (int i = 0; i < N; i++){
        cin >> A_in[i];
    }
    vector<int> ans = solve(N, X, A_in);
    for (int num : ans) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}
