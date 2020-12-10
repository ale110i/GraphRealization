//
//  MatrixGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(IGraph*& another_graph){
    vertices_count = another_graph->VerticesCount();
    matrix.resize(vertices_count);
    for (int_fast32_t j = 0; j < another_graph->VerticesCount(); ++j){
        std::vector<int_fast32_t> nv;
        std::vector<int_fast32_t> pv;
        another_graph->GetNextVertices(j, nv);
        another_graph->GetPrevVertices(j, pv);
        for (int_fast32_t i = 0; i < pv.size(); ++i){
            matrix[pv[i]][j] = true;
        }
        for (int_fast32_t i = 0; i < nv.size(); ++i){
            matrix[j][nv[i]] = true;
        }
    }
}

MatrixGraph::MatrixGraph(int_fast32_t vt_count){
    vertices_count = vt_count;
    matrix.resize(vertices_count);
    for (int_fast32_t j = 0; j < vt_count; ++j){
        matrix[j].resize(vt_count);
    }
}

void MatrixGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    matrix.at(from).at(to) = true;
}

int_fast32_t MatrixGraph::VerticesCount() const {
    return vertices_count;
}

void MatrixGraph::GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t j = 0; j < vertices_count; ++j){
        if (matrix.at(vertex).at(j)){
            vertices.push_back(j);
        }
    }
}

void MatrixGraph::GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t j = 0; j < vertices_count; ++j){
        if (matrix.at(j).at(vertex)){
            vertices.push_back(j);
        }
    }
}
