// https://leetcode.com/problems/k-closest-points-to-origin/

#include "header.h"

class Solution {
private:
    struct Point {
        int x;
        int y;
        int distance;
        Point(int a, int b) : x(a), y(b) {distance = x * x + y * y;}
        bool operator<(const Point& p) {return distance < p.distance;}
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int count = points.size();
        vector<Point> pos;
        pos.reserve(count);
        for (auto& p : points) {
            pos.emplace_back(p[0], p[1]);
        }
        sort(pos.begin(), pos.end());
        
        vector<vector<int>> ret;
        ret.resize(k);
        for (int i = 0; i < k; i++) {
            vector<int> ele = {pos[i].x, pos[i].y};
            ret[i].swap(ele);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    Solution sol;
    sol.kClosest(points, 2);
}