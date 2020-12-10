//
//  ArcGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "ArcGraph.hpp"

ArcGraph::ArcGraph(IGraph*& another_graph){
    vertices_count = another_graph->VerticesCount();
    std::pair<int_fast32_t, int_fast32_t> connection;
    for (int_fast32_t j = 0; j < vertices_count; ++j){
        std::vector<int_fast32_t> nv;
        std::vector<int_fast32_t> pv;
        another_graph->GetNextVertices(j, nv);
        another_graph->GetPrevVertices(j, pv);
        for (int_fast32_t i = 0; i < nv.size(); ++i){
            connection.first = j;
            connection.second = nv[i];
            links.push_back(connection);
        }
        for (int_fast32_t i = 0; i < pv.size(); ++i){
            connection.second = j;
            connection.first = nv[i];
            links.push_back(connection);
        }
    }
}

ArcGraph::ArcGraph(int_fast32_t vt_count){
    vertices_count = vt_count;
}

void ArcGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    std::pair<int_fast32_t, int_fast32_t> connection;
    connection.first = from;
    connection.second = to;
    links.push_back(connection);
}

int_fast32_t ArcGraph::VerticesCount() const {
    return vertices_count;
}

void ArcGraph::GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t i = 0; i < links.size(); ++i){
        if (links[i].first == vertex){
            vertices.push_back(links[i].second);
        }
    }
}

void ArcGraph::GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t i = 0; i < links.size(); ++i){
        if (links[i].second == vertex){
            vertices.push_back(links[i].first);
        }
    }
}
