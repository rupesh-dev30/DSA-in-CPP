#include <bits/stdc++.h>
using namespace std;

class Car {
public:
  int index;
  int distanceSquare;

  Car(int index, int distanceSquare) {
    this->index = index;
    this->distanceSquare = distanceSquare;
  }

  bool operator < (const Car &obj) const {
    return this->distanceSquare > obj.distanceSquare;  // minHeap
  }
};

void nearByCars(vector<pair<int, int>> &pos, int k) {
  vector<Car> cars;

  for (int i = 0; i < pos.size(); i++) { // O(n)
    int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
    cars.push_back(Car(i, distSq));
  }

  priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

  // for (int i = 0; i < cars.size(); i++) { // O(nlogn)
  //   pq.push(cars[i]);
  // }

  for(int i=0; i<k; i++) { // O(k)
    cout << "Car : " << pq.top().index << endl;
    pq.pop();
  }
}

int main() {
  // code here
  vector<pair<int, int>> pos;
  pos.push_back(make_pair(3, 3));
  pos.push_back(make_pair(5, -1));
  pos.push_back(make_pair(-2, 4));

  int k = 2;
  nearByCars(pos, k);

  return 0;
}

/*
    Based on car locations (cx, cy), find nearest K cars

    C0 (3,3)
    C1 (5,-1)
    C2 (-2,4)

    K = 2
*/