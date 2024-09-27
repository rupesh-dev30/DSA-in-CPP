#include <bits/stdc++.h>
using namespace std;

void stockSpan(vector<int> stock, vector<int>& span){
    stack<int> s;
    span[0] = 1;
    s.push(0);

    for(int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];

        while(!s.empty() && stock[s.top()] <= currPrice){
            s.pop();
        }

        if(s.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - s.top();
        }

        s.push(i);
    }

    for(int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0);

    stockSpan(stock, span);

    return 0;
}
