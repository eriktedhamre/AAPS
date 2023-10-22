#include <bits/stdc++.h>

using namespace std;

double epsilon = 1e-12;


struct Point {
  double x;
  double y;
};
 
struct line {
  Point p1;
  Point p2;
};

double cross_product(Point a, Point b) {
  return (a.x * b.y) - (a.y * b.x);
}

double dot_product(Point a, Point b) {
  return (a.x * b.x) + (a.y * b.y);
}

double dist(Point a, Point b) {
  Point ab = {a.x - b.x, a.y - b.y};
  return sqrt(dot_product(ab, ab));
}

bool parallel_segments(Point a, Point b, Point c, Point d) {
  Point ab = {a.x - b.x, a.y - b.y};
  Point cd = {c.x - d.x, c.y - d.y};
  return abs(cross_product(ab, cd)) < epsilon;
}

int checkInside2(vector<Point>& polygon, int size, Point& p) {
  int cnt = 0;

  line side;
  bool count = false;
  int i = 0;

  do
  {
    // Forming a line from two consecutive points of the polygon
    side = {polygon[i], polygon[(i + 1) % size]};

    if ((p.y < side.p1.y) != (p.y < side.p2.y) &&
       p.x < side.p1.x + ((p.y - side.p1.y)/(side.p2.y-side.p1.y))*(side.p2.x-side.p1.x))
    {
      count = !count;
    }
      
    i = (i + 1) % size;
  } while (i != 0);

  return count;
}

bool point_on_segment(vector<Point>& polygon, int size, Point& p) {


  line side;
  int i = 0;
  Point p1;
  Point p2;

  do
  {
    if (dist(p, polygon[i]) < epsilon) { return true;}
    if (dist(p, polygon[(i + 1) % size]) < epsilon) { return true;}
    
    p1 = {p.x - polygon[i].x, p.y - polygon[i].y};
    p2 = {p.x - polygon[(i + 1) % size].x, p.y - polygon[(i + 1) % size].y};

    if (parallel_segments(p, polygon[i], p, polygon[(i + 1) % size]) && dot_product(p1, p2) < 0) { return true;}

    i = (i + 1) % size;
  } while (i != 0);

  return false;

}


// duplicate points?
// Does it matter if the points are given in a clockwise or counter clockwise order
// n < 3 ????
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int m;

  int x;
  int y;

  int res;

  vector<Point> polygon(1000);

  Point p;

  while(cin >> n){
    if (n == 0) {break;}

    for (size_t i = 0; i < n; i++)
    {
      cin >> x >> y;
      polygon[i].x = x;
      polygon[i].y = y;
    }
    
    cin >> m;

    for (size_t i = 0; i < m; i++)
    {
      cin >> x >> y;

      p.x=x;
      p.y=y;

      if(point_on_segment(polygon, n, p)) {
        std::cout << "on\n";
      } else if ( checkInside2(polygon, n, p)) {
        std::cout << "in\n";
      } else
      {
        std::cout << "out\n";
      }
      
    }
    
  };
  

  return 0;
}
