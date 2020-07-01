#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <algorithm>
#include <iostream>

int main()
{
    enum { Netherlands, Belgium, France, Germany, Switzerland, Austria, Italy };
    const char *countries[] = { "Netherlands", "Belgium", "France", "Germany", "Switzerland", "Austria", "Italy" };

    std::array<std::pair<int, int>, 12> edges{{
        std::make_pair(Netherlands, Belgium),
        std::make_pair(Netherlands, Germany),
        std::make_pair(Belgium, Germany),
        std::make_pair(Belgium, France),
        std::make_pair(France, Germany),
        std::make_pair(France, Switzerland),
        std::make_pair(France, Italy),
        std::make_pair(Germany, Switzerland),
        std::make_pair(Germany, Austria),
        std::make_pair(Switzerland, Austria),
        std::make_pair(Switzerland, Italy),
        std::make_pair(Italy, Austria)
    }};

    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> graph;
    graph g{ edges.begin(), edges.end(), 7 };

    boost::array<int, 7> predecessors;
    predecessors[Netherlands] = Netherlands;

    boost::breadth_first_search(g, Netherlands,
        boost::visitor(
            boost::make_bfs_visitor(
                boost::record_predecessors(predecessors.begin(),
                    boost::on_tree_edge{}))));

    int p = Italy;
    while (p != Netherlands)
    {
        std::cout << countries[p] << '\n';
        p = predecessors[p];
    }
    std::cout << countries[p] << '\n';
}
