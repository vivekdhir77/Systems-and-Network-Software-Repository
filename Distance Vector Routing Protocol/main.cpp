#include <iostream>
#include <vector>
#include <map>
#include <climits>

class DistanceVectorRouter {
public:
    DistanceVectorRouter(int id, int numRouters)
        : routerId(id), numRouters(numRouters), distanceVector(numRouters, INT_MAX) {
        distanceVector[id] = 0;
    }

    void addLink(int destRouter, int cost) {
        links[destRouter] = cost;
        distanceVector[destRouter] = cost;
        updateDistances();
    }

    void updateDistanceVector(int routerId, const std::vector<int>& distances) {
        bool updated = false;
        for (int i = 0; i < numRouters; ++i) {
            if (distanceVector[i] > distances[i] + links[routerId]) {
                distanceVector[i] = distances[i] + links[routerId];
                updated = true;
            }
        }
        if (updated) {
            updateDistances();
        }
    }

    void updateDistances() {
        // Placeholder for actual distance update logic
    }

    void printDistanceVector() const {
        std::cout << "Router " << routerId << " Distance Vector: ";
        for (int i = 0; i < numRouters; ++i) {
            if (distanceVector[i] == INT_MAX)
                std::cout << "INF ";
            else
                std::cout << distanceVector[i] << " ";
        }
        std::cout << std::endl;
    }

    const std::vector<int>& getDistanceVector() const {
        return distanceVector;
    }

    const std::map<int, int>& getLinks() const {
        return links;
    }

private:
    int routerId;
    int numRouters;
    std::vector<int> distanceVector;
    std::map<int, int> links; // destination router ID to cost
};

int main() {
    int numRouters;
    std::cout << "Enter the number of routers: ";
    std::cin >> numRouters;
    
    std::vector<DistanceVectorRouter> routers;
    for (int i = 0; i < numRouters; ++i) {
        routers.push_back(DistanceVectorRouter(i, numRouters));
    }

    std::cout << "Enter links in the format: <source> <destination> <cost> (enter -1 -1 -1 to finish):" << std::endl;

    int src, dest, cost;
    while (true) {
        std::cin >> src >> dest >> cost;
        if (src == -1 && dest == -1 && cost == -1) {
            break;
        }
        routers[src].addLink(dest, cost);
    }

    std::cout << "Initial Distance Vectors:" << std::endl;
    for (int i = 0; i < numRouters; ++i) {
        routers[i].printDistanceVector();
    }

    // Simulate distance vector exchanges
    for (int i = 0; i < numRouters; ++i) {
        const std::vector<int>& distances = routers[i].getDistanceVector();
        const std::map<int, int>& links = routers[i].getLinks();
        for (std::map<int, int>::const_iterator it = links.begin(); it != links.end(); ++it) {
            int neighborId = it->first;
            routers[neighborId].updateDistanceVector(i, distances);
        }
    }

    std::cout << "Updated Distance Vectors:" << std::endl;
    for (int i = 0; i < numRouters; ++i) {
        routers[i].printDistanceVector();
    }

    return 0;
}
