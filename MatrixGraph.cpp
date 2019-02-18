//
//  MatrixGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "MatrixGraph.hpp"

bool MatrixGraph::Check(int_fast32_t vertex){
    if (matrix.size() == 0){
        return false;
    }
    else {
        for (int i = 0; i < matrix.size(); ++i){
            if (matrix.at(i).first == vertex){
                return true;
            }
        }
    }
    return false;
}

void MatrixGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    if (!Check(from)){
        vector<bool> v_empty_connections(matrix.size() + 1, false);
        pair<int_fast32_t, vector<bool>> vtx;
        vtx.first = from;
        vtx.second = v_empty_connections;
        matrix.push_back(vtx);
        for(int_fast32_t i = 0; i < matrix.size(); ++i){
            matrix.at(i).second.push_back(false);
        }
        ++size;
    }
    if (!Check(to)){
        vector<bool> v_empty_connections(matrix.size() + 1, false);
        pair<int_fast32_t, vector<bool>> vtx;
        vtx.first = to;
        vtx.second = v_empty_connections;
        matrix.push_back(vtx);
        for(int_fast32_t i = 0; i < matrix.size(); ++i){
            matrix.at(i).second.push_back(false);
        }
        ++size;
    }
    matrix.at(from).second.at(to) = true;
}

int_fast32_t MatrixGraph::VerticesCount(){
    return size;
}

void MatrixGraph::GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    int_fast32_t i = 0;
    for (; i < size; ++i){
        if (matrix.at(i).first == vertex){
            break;
        }
    }
    for (int_fast32_t j = 0; j < size; ++j){
        if (matrix.at(i).second.at(j)){
            vertices.push_back(matrix.at(j).first);
        }
    }
}

void MatrixGraph::GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    for (int_fast32_t i = 0; i < size; ++i){
        if (matrix.at(i).second.at(vertex)){
            vertices.push_back(i);
        }
    }
}
