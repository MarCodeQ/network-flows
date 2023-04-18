#ifndef MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H
#define MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H

#include "data_structures/graph/Graph.h"
#include "dto/EdmondsKarp/EdmondsKarpResult.h"

namespace algorithms {
    /**
     * Class containing the following maximum flow algorithms:
     * - Edmonds-Karp
     */
    class MaximumFlowAlgorithms {
        public:
            /**
             * Edmonds-Karp algorithm
             * Edmonds–Karp algorithm is an implementation of the Ford–Fulkerson method
             * for computing the maximum flow in a flow network.
             *
             * Time complexity: O(VE^2)
             * Space complexity: O(V+E)
             *
             * https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm
             *
             * @param graph the graph to solve
             * @param source the source node
             * @param sink the sink node
             * @return the graph and the maximum flow
             */
            static  shared_ptr<dto::EdmondsKarpResult> EdmondsKarp(std::shared_ptr<data_structures::Graph> graph, int source, int sink);
    };
}

#endif //MINIMUM_COST_FLOWS_PROBLEM_MAXIMUMFLOWALGORITHMS_H
