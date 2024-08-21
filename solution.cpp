#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) { // std::vector to be explicit
        int numedges = edges.size();
        std::map<int, int> vertexCount;
        int result=0;
        
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            vertexCount[(*it)[0]]++;
            vertexCount[(*it)[1]]++;
        }
        // traverse the vertexCount
        for (const auto& entry : vertexCount) {
            if (entry.second == numedges) result= entry.first;
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}}; // Initialize the edges
    s.findCenter(edges); // Pass by reference, no need to pass &edges
    std::cout<< s.findCenter(edges) << std::endl;
}
