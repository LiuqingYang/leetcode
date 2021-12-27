// https://leetcode.com/problems/course-schedule-ii/

#include "header.h"

// 使用了拓扑排序方法，即一部分的深度优先算法步骤，简化后是可能在面试期间写出来的：顶点仅需记录颜色，边仅需记录终点
// 

class Solution {
private:
    struct GraphVertex {
        // int value;
        int parent = -1; // 可以去除
        int d = 0;  // 可以去除
        int f = 0; // 可以去除
        char color = 0;  // 0: black, 1: gray, 2: black
    };
    struct GraphEdge {
        // int start;
        int end;
        GraphEdge(int num) : end(num) {}
    };
    
    void dfs(int current) {
        GraphVertex& vertex = vertexs[current];
        vertex.color = 1;
        time++;
        vertex.d = time;
        vector<GraphEdge>& edges = adj[current];
        for (int i = 0; i < edges.size(); i++) {
            int next = edges[i].end;
            GraphVertex& next_vertex = vertexs[next];
            if (next_vertex.color == 0) {
                next_vertex.parent = current;
                dfs(next);
                if (have_loop) {
                    break;
                }
            } else if (next_vertex.color == 1) {
                have_loop = true;
                break;
            }
        }
        vertex.color = 2;
        time++;
        vertex.f = time;
        ret.push_back(current);
    }

    vector<GraphVertex> vertexs;
    vector<vector<GraphEdge>> adj;
    int time = 0; // 可以去除

    vector<int> ret;
    bool have_loop = false;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vertexs.clear();
        vertexs.resize(numCourses);
        adj.clear();
        adj.resize(numCourses);
        ret.clear();
        have_loop = false;
        
        for (auto& ele : prerequisites) {
            adj[ele[0]].emplace_back(ele[1]);
        }
        
        time = 0;
        for (int i = 0; i < numCourses; i++) {
            GraphVertex& vertex = vertexs[i];
            if (vertex.color == 0) {
                dfs(i);
            }
        }
        if (have_loop) {
            return {};
        } else {
            return ret;
        }
    }
};