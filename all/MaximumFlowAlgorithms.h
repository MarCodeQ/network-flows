#ifndef MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H
#define MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H

#include "Graph.h"
#include "FlowResult.h"

namespace algorithms
{
    /**
     * Class containing the following maximum flow algorithms:
     * - Edmonds-Karp
     */
    class MaximumFlowAlgorithms
    {
    public:
        /**
         * Edmonds-Karp algorithm.
         * Edmonds–Karp algorithm is an implementation of the Ford–Fulkerson method
         * for computing the maximum flow in a flow network.
         * Return the graph and the maximum flow.
         *
         * (see: https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm)
         *
         * V: number of nodes
         * E: number of edges
         * Time complexity: O(V * E^2)
         *
         * @param graph  the graph to solve
         * @param source the source node
         * @param sink   the sink node
         *
         * @return the residual graph and the maximum flow
         */
        static std::shared_ptr<dto::FlowResult> EdmondsKarp(const std::shared_ptr<data_structures::Graph> &graph, int source, int sink);
    };
}

#endif // MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H
