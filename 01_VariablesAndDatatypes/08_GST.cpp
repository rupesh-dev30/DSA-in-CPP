#include <bits/stdc++.h>
using namespace std;

int main()
{
  // code here
  float item1, item2, item3;
  cout << "Enter the price of 3 items: " << endl;
  cin >> item1 >> item2 >> item3;

  float totalPrice = item1 + item2 + item3;

  float gstAmount = 0.18 * totalPrice;
  float totalPriceAfterGST = totalPrice + gstAmount;

  cout << "Total price before GST is: " << totalPrice << endl;
  cout << "GST amount is: " << gstAmount << endl;
  cout << "Total price after GST is: " << totalPriceAfterGST << endl;

  return 0;
}