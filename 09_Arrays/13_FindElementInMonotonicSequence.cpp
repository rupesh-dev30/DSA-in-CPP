#include <bits/stdc++.h>
using namespace std;

#define SMALL_N 1000000
#define LARGE_N 1000000000000000

typedef long long ll;

ll func(ll a, ll b, ll c, ll n) {
  ll res = a * n;
  ll logValue = floor(log2(n));
  res += b * n * logValue;
  res += c * (n * n * n);
  return res;
}

ll getPositionInSeries(ll a, ll b, ll c, ll k) {
  ll start = 1, end = SMALL_N;

  // if c is 0, then value of n can be in order of 10^15.
  // if c!=0, then n^3 value has to be in order of 10^18
  // so maximum value of n can be 10^6.
  if (c == 0) {
    end = LARGE_N;
  }

  long long ans = 0;

  while (start <= end) {
    ll mid = (start + end) / 2;
    ll val = func(a, b, c, mid);
    if (val == k) {
      ans = mid;
      break;
    } else if (val > k) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  // code here
  long long a = 2, b = 1, c = 1;
  long long k = 12168587437017;

  cout << getPositionInSeries(a, b, c, k);

  return 0;
}