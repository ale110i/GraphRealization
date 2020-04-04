//
//  ListGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "ListGraph.hpp"

bool ListGraph::Check(int_fast32_t vertex){
    if (links.size() == 0){
        return false;
    }
    else {
        for (int i = 0; i < links.size(); ++i){
            if (links.at(i).first == vertex){
                return true;
            }
        }
    }
    return false;
}

void ListGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    if (!Check(from)){
        deque<int_fast32_t> empty_deck;
        pair<deque<int_fast32_t>, deque<int_fast32_t>> empty_connections_pair;
        pair<int_fast32_t, pair<deque<int_fast32_t>, deque<int_fast32_t>>> vtx;
        vtx.first = from;
        empty_connections_pair.first = empty_deck;
        empty_connections_pair.second = empty_deck;
        vtx.second = empty_connections_pair;
        links.push_back(vtx);
    }
    if (!Check(to)){
        deque<int_fast32_t> empty_deck;
        pair<deque<int_fast32_t>, deque<int_fast32_t>> empty_connections_pair;
        pair<int_fast32_t, pair<deque<int_fast32_t>, deque<int_fast32_t>>> vtx;
        vtx.first = to;
        empty_connections_pair.first = empty_deck;
        empty_connections_pair.second = empty_deck;
        vtx.second = empty_connections_pair;
        links.push_back(vtx);
    }
    int_fast32_t i = (int_fast32_t)links.size() - 1;
    for (; i > -1; --i){
        if (links.at(i).first == from){
            break;
        }
    }
    links.at(i).second.second.push_back(to); //Указываем дитя
    i = (int_fast32_t)links.size() - 1;
    for (; i > -1; --i){
        if (links.at(i).first == to){
            break;
        }
    }
    links.at(i).second.first.push_back(from); //Указываем предка
}

int_fast32_t ListGraph::VerticesCount(){
    return (int_fast32_t)links.size();
}

void ListGraph::GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    int_fast32_t i = (int_fast32_t)links.size() - 1;
    for (; i > -1; --i){
        if (links.at(i).first == vertex){
            break;
        }
    }
    for (int_fast32_t j = 0; j < links.at(i).second.second.size(); ++j){
        vertices.push_back(links.at(i).second.second.at(j));
    }
}

void ListGraph::GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    int_fast32_t i = (int_fast32_t)links.size() - 1;
    for (; i > -1; --i){
        if (links.at(i).first == vertex){
            break;
        }
    }
    for (int_fast32_t j = 0; j < links.at(i).second.first.size(); ++j){
        vertices.push_back(links.at(i).second.first.at(j));
    }
}

