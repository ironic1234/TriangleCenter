#include <array>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

map<string, array<double, 2>> incenter(array<double, 2> p1, array<double, 2> p2,
                                       array<double, 2> p3) {
  double x1 = p1[0], y1 = p1[1];
  double x2 = p2[0], y2 = p2[1];
  double x3 = p3[0], y3 = p3[1];

  double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
  double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
  double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

  double incenterX = (a * x1 + b * x2 + c * x3) / (a + b + c);
  double incenterY = (a * y1 + b * y2 + c * y3) / (a + b + c);

  array<double, 2> incenterPoint;
  incenterPoint[0] = incenterX;
  incenterPoint[1] = incenterY;

  map<string, array<double, 2>> returnMap = {{"Incenter", incenterPoint}};

  return returnMap;
}

map<string, array<double, 2>> centroid(array<double, 2> p1, array<double, 2> p2,
                                       array<double, 2> p3) {
  array<double, 2> centroidPoint;
  centroidPoint[0] = (p1[0] + p2[0] + p3[0]) / 3;
  centroidPoint[1] = (p1[1] + p2[1] + p3[1]) / 3;

  map<string, array<double, 2>> returnMap = {{"Centroid", centroidPoint}};

  return returnMap;
}

int main() {
  array<double, 2> p1;
  cout << "Enter coordinates of point 1 (x y): ";
  cin >> p1[0] >> p1[1];

  array<double, 2> p2;
  cout << "Enter coordinates of point 2 (x y): ";
  cin >> p2[0] >> p2[1];

  array<double, 2> p3;
  cout << "Enter coordinates of point 3 (x y): ";
  cin >> p3[0] >> p3[1];

  map<string, array<double, 2>> (*arr[2])(array<double, 2>, array<double, 2>,
                                          array<double, 2>) = {incenter,
                                                               centroid};

  int numCenters = sizeof(arr) / sizeof(arr[0]);

  map<string, array<double, 2>> centers;

  for (int i = 0; i < numCenters; i++) {
    map<string, array<double, 2>> center = arr[i](p1, p2, p3);
    cout << center.begin()->first << ": " << center.begin()->second[0] << " "
         << center.begin()->second[1] << "\n";
  }

  return 0;
}
