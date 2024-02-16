#include "UninformedSearch.h"

#include "SetFunctions.h"

#include <set>
#include <map>
#include <queue>

std::vector<grapph::edge_t> cppai::breadthFirstSearch (
    grapph::Graph &graph,
    grapph::vertex_t start,
    grapph:vertex_t finish
) {
    // Initialize set of visited vertices
    std::set<grapph::vertex_t> visited;

    // Initialize cache for dynamic tracking of path
    std::map<grapph::vertex_t, grapph::edge_t> cache;

    // Initialize queue with start vertex
    std::queue<grapph::vertex_t> bfs;
    bfs.push_back(start);

    // Traverse and find path
    while (!queue.empty() && !visited.contains(finish)) {
        // Pop front of queue
        grapph::vertex_t front = queue.front(); queue.pop_front();

        // Skip if visited, otherwise mark as visited
        if (visited.count(front) != 0) { continue; }
        visited.insert(front);

        // Enqueue each non-visited neighbor and add to cache
        for (grapph::vertex_t neighbor : grapph::setDifference(
                graph.getNeighbors(front), visited)) {
            // enqueue
            queue.push_back(neighbor);
            
            // ensure correct neighbor order
            edge_t edge = {front, neighbor};
            if (edge.first > edge.second) {
                edge = {neighbor, front};
            }

            // add to cache
            cache[neighbor] = edge;
        }
    }

    // Throw exception if no path
    if (cache.count(finish) == 0) {
        std::stringstream ss;
        ss << "No path found between vertices " << start << " and "
            << finish;
        throw std::invalid_argument(ss.str());
    }

    // Otherwise, reverse-engineer path from cache
    std::vector<grapph::edge_t> path;
    grapph::vertex_t curr = finish;
    while (curr != start) {
        path.insert(path.begin(), cache[curr]);
        curr = curr == cache[curr].first
            ? cache[curr].second
            : cache[curr].first;
    }

    return path;
}