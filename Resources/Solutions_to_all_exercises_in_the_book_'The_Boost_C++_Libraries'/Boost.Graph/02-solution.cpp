#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iostream>

int main()
{
    enum { Netherlands, Belgium, France, Germany, Switzerland, Austria, Italy };
    const char *countries[] = { "Netherlands", "Belgium", "France", "Germany", "Switzerland", "Austria", "Italy" };

    std::array<std::pair<int, int>, 24> edges{{
        std::make_pair(Netherlands, Belgium),
        std::make_pair(Belgium, Netherlands),
        std::make_pair(Germany, Netherlands),
        std::make_pair(Netherlands, Germany),
        std::make_pair(Belgium, Germany),
        std::make_pair(Germany, Belgium),
        std::make_pair(Belgium, France),
        std::make_pair(France, Belgium),
        std::make_pair(France, Germany),
        std::make_pair(Germany, France),
        std::make_pair(France, Switzerland),
        std::make_pair(Switzerland, France),
        std::make_pair(France, Italy),
        std::make_pair(Italy, France),
        std::make_pair(Germany, Switzerland),
        std::make_pair(Switzerland, Germany),
        std::make_pair(Germany, Austria),
        std::make_pair(Austria, Germany),
        std::make_pair(Switzerland, Austria),
        std::make_pair(Austria, Switzerland),
        std::make_pair(Switzerland, Italy),
        std::make_pair(Italy, Switzerland),
        std::make_pair(Italy, Austria),
        std::make_pair(Austria, Italy)
    }};

    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
        boost::no_property, boost::property<boost::edge_weight_t, int>> graph;

    std::array<int, 24> weights{{ 15, 0, 0, 20, 20, 15, 10, 15, 20, 10, 0, 10, 0, 10, 0, 20, 0, 20, 0, 0, 0, 0, 0, 0 }};
    graph g{ edges.begin(), edges.end(), weights.begin(), 7 };

    boost::array<int, 7> predecessors;
    boost::dijkstra_shortest_paths(g, Netherlands, boost::predecessor_map(predecessors.begin()));

    int p = Italy;
    while (p != Netherlands)
    {
        std::cout << countries[p] << '\n';
        p = predecessors[p];
    }
    std::cout << countries[p] << '\n';
}
