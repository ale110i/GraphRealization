//
//  ArcGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "ArcGraph.hpp"

bool leCmp(pair<int_fast32_t, int_fast32_t>& first, pair<int_fast32_t, int_fast32_t>& second){
    if (first.first < second.first){
        return true;
    }
    if (first.first == second.first && first.second < second.second){
        return true;
    }
    else {
        return false;
    }
}

void ArcGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    pair<int_fast32_t, int_fast32_t> connection;
    connection.first = from;
    connection.second = to;
    links.push_back(connection);
}

int_fast32_t ArcGraph::VerticesCount(){
    if (size != 0){
        return size;
    }
    vector<int_fast32_t> vertices;
    bool p1, p2;
    for (int_fast32_t i = 0; i < links.size(); ++i){
        p1 = false;
        p2 = false;
        for (int_fast32_t j = 0; j < vertices.size(); ++j){
            if (vertices[j] == links[i].first){
                p1 = true;
            }
            if (vertices[j] == links[i].second){
                p2 = true;
            }
        }
        if (!p1){
            vertices.push_back(links[i].first);
        }
        if (!p2){
            vertices.push_back(links[i].second);
        }
    }
    //size = (int_fast32_t)(vertices.size());
    //sort(links.begin(), links.end(), leCmp);
    return (int_fast32_t)vertices.size();
}

void ArcGraph::GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    if (!is_sorted(links.begin(), links.end(), leCmp)){
        sort(links.begin(), links.end(), leCmp);
    }
    int i = 0;
    for (; i < links.size(); ++i){
        if (links[i].first == vertex){
            break;
        }
    }
    if (links[i].first != vertex){
        return;
    }
    else {
        while (links[i].first == vertex){
            vertices.push_back(links[i].second);
            ++i;
        }
    }
}

void ArcGraph::GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    for (int_fast32_t i = 0; i < links.size(); ++i){
        if (links[i].second == vertex){
            vertices.push_back(links[i].first);
        }
    }
}
