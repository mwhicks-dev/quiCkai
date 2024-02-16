#ifndef CPPAI_UNINFORMED_SEARCH
#define CPPAI_UNINFORMED_SEARCH

#include "Graph.h"

namespace cppai {

    /**
     * Performs breadth-first search on a graph, taking an initial and final 
     * vertex for the search. Returns a path of edges that, if followed, 
     * represent the found path; throws std::invalid_argument if no path 
     * exists.
     */
    static std::vector<grapph::edge_t> breadthFirstSearch(
        grapph::Graph, grapph::vertex_t, grapph:vertex_t
    );

    /**
     * Performs depth-first search on a graph, taking an initial and final 
     * vertex for the search. Returns a path of edges that, if followed, 
     * represent the found path; throws std::invalid_argument if no path 
     * exists.
     */
    static std::vector<grapph::edge_t> depthFirstSearch(
        grapph::Graph, grapph::vertex_t, grapph:vertex_t
    );

    /**
     * Performs iterative search on a graph, taking an initial and final 
     * vertex for the search. Returns a path of edges that, if followed, 
     * represent the found path; throws std::invalid_argument if no path 
     * exists.
     */
    static std::vector<grapph::edge_t> iterativeSearch(
        grapph::Graph, grapph::vertex_t, grapph:vertex_t
    );

    /**
     * Performs bi-direction search on a graph, taking an initial and final 
     * vertex for the search, as well as the search algorithm to use. Returns 
     * a path of edges that, if followed, represent the found path; throws 
     * std::invalid_argument if no path exists.
     */
    static std::vector<grapph::edge_t> biDirectionSearch(
        grapph::Graph, grapph::vertex_t, grapph:vertex_t,
        std::vector<grapph::edge_t> (*)(
            grapph::Graph, grapph::vertex_t, grapph:vertex_t
        )
    );

}

#endif