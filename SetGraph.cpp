//
//  SetGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "SetGraph.hpp"

const int_fast32_t empty_el = -1;
const int_fast32_t deleted_el = -2;

SetGraph::SetGraph(IGraph*& another_graph){
    vertices_count = another_graph->VerticesCount();
    HashTableFP<int_fast32_t> empty_HTFP(empty_el, deleted_el, hasher);
    std::pair<HashTableFP<int_fast32_t>, HashTableFP<int_fast32_t>> empty_pair;
    empty_pair.first = empty_HTFP;
    empty_pair.second = empty_HTFP;
    links.resize(vertices_count, empty_pair);
    for (int_fast32_t j = 0; j < another_graph->VerticesCount(); ++j){
        std::vector<int_fast32_t> nv;
        std::vector<int_fast32_t> pv;
        another_graph->GetNextVertices(j, nv);
        another_graph->GetPrevVertices(j, pv);
        for (int_fast32_t i = 0; i < pv.size(); ++i){
            links[j].first.insert_element(pv[i]);
        }
        for (int_fast32_t i = 0; i < nv.size(); ++i){
            links[j].second.insert_element(nv[i]);
        }
    }
}

SetGraph::SetGraph(int_fast32_t vt_count){
    vertices_count = vt_count;
    HashTableFP<int_fast32_t> empty_HTFP(empty_el, deleted_el, hasher);
    std::pair<HashTableFP<int_fast32_t>, HashTableFP<int_fast32_t>> empty_pair;
    empty_pair.first = empty_HTFP;
    empty_pair.second = empty_HTFP;
    links.resize(vertices_count, empty_pair);
}

void SetGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    links.at(from).second.insert_element(to);
    links.at(to).first.insert_element(from);
}

int_fast32_t SetGraph::VerticesCount() const {
    return vertices_count;
}

void SetGraph::GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    std::vector<int_fast32_t> anss = links.at(vertex).second.list_all2();
    for (int_fast32_t i = 0; i < anss.size(); ++i){
        vertices.push_back(anss[i]);
    }
}
void SetGraph::GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    std::vector<int_fast32_t> anss = links.at(vertex).first.list_all2();
    for (int_fast32_t i = 0; i < anss.size(); ++i){
        vertices.push_back(anss[i]);
    }
}
