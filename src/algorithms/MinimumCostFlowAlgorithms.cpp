#include "MinimumCostFlowAlgorithms.h"

#include "MaximumFlowAlgorithms.h"
#include "GraphBaseAlgorithms.h"
#include "utils/GraphUtils.h"

#include <iostream>

namespace algorithms {
    std::shared_ptr<dto::FlowResult> MinimumCostFlowAlgorithms::CycleCancelling(std::shared_ptr<data_structures::graph> graph) {
        int source {};
        int sink { graph->getNumNodes() - 1 };

        // get the maximum flow using Edmonds-Karp (feasible flow)
        auto edmonds_karps_result = MaximumFlowAlgorithms::EdmondsKarp(graph, source, sink);
        auto residual_graph = edmonds_karps_result->getGraph();

        // get the negative cycle using Bellman-Ford
        auto bellman_ford_result = GraphBaseAlgorithms::BellmanFord(residual_graph, source);

        // while there is a negative cycle in the residual graph augment the flow
        while (bellman_ford_result->hasNegativeCycle()) {
            auto negative_cycle = bellman_ford_result->getNegativeCycle();
            int residual_capacity = utils::GraphUtils::GetResidualCapacity(residual_graph, negative_cycle);

            // update the residual capacities and the current flow (augment flow)
            utils::GraphUtils::SendFlowInPath(residual_graph, negative_cycle, residual_capacity);

            bellman_ford_result = GraphBaseAlgorithms::BellmanFord(residual_graph, source);
        }

        std::cout << residual_graph->toString() << std::endl;

        // get minimum cost
        int minimum_cost {};
        for (int u = 0; u < residual_graph->getNumNodes(); u++) {
            for (auto edge: *residual_graph->getNodeAdjList(u)) {
                if (edge.getWeight() < 0) {
                    minimum_cost +=  -edge.getWeight() * edge.getCapacity();
                }
            }
        }

        return std::make_shared<dto::FlowResult>(residual_graph, minimum_cost);
    }

}