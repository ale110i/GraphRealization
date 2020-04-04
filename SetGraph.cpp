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

bool leCmp(pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>>& vtx1, pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>>& vtx2){
    if (vtx1.first < vtx2.first){
        return true;
    }
    else {
        return false;
    }
}

void SetGraph::Insert_Vertex(pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>> vtx){
    int left = 0;
    int right = (int)links.size() - 1;
    if (links.size() == 0){
        links.push_back(vtx);
        return;
    }
    if (vtx.first < links[left].first){
        links.insert(links.begin(), vtx);
    }
    if (vtx.first > links[right].first){
        links.push_back(vtx);
    }
    while (right - left > 2){
        if (links[(right + left) / 2] > vtx){
            right = (right + left) / 2;
        }
        else {
            left = (right + left) / 2;
        }
    }
    if (links[(right + left) / 2] > vtx){
        links.insert(links.begin() + (right + left) / 2, vtx);
    }
    else {
        links.insert(links.begin() + right, vtx);
    }
}

bool SetGraph::Check(int_fast32_t vertex){
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

void SetGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    sort(links.begin(), links.end(), leCmp);
    if (!Check(from)){
        pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>> vtx;
        HashTableFP<int_fast32_t>* ht_ptr = new HashTableFP<int_fast32_t>(empty_el, deleted_el, &hasher<int_fast32_t>);
        HashTableFP<int_fast32_t>* ht2_ptr = new HashTableFP<int_fast32_t>(empty_el, deleted_el, &hasher<int_fast32_t>);;
        vtx.first = from;
        vtx.second.first = ht_ptr;
        vtx.second.second = ht2_ptr;
        Insert_Vertex(vtx);
    }
    if (!Check(to)){
        pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>> vtx;
        HashTableFP<int_fast32_t>* ht_ptr = new HashTableFP<int_fast32_t>(empty_el, deleted_el, &hasher<int_fast32_t>);
        HashTableFP<int_fast32_t>* ht2_ptr = new HashTableFP<int_fast32_t>(empty_el, deleted_el, &hasher<int_fast32_t>);;
        vtx.first = to;
        vtx.second.first = ht_ptr;
        vtx.second.second = ht2_ptr;
        Insert_Vertex(vtx);
    }
    int_fast32_t i = 0;
    for(; i < links.size(); ++i){
        if (links.at(i).first == from){
            break;
        }
    }
    links.at(i).second.second->insert_element(to);
    i = 0;
    for(; i < links.size(); ++i){
        if (links.at(i).first == to){
            break;
        }
    }
    links.at(i).second.first->insert_element(from);
}

int_fast32_t SetGraph::VerticesCount(){
    return (int_fast32_t)links.size();
}

void SetGraph::GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    vector<int_fast32_t> anss = links.at(vertex).second.second->list_all();
    for (int_fast32_t i = 0; i < anss.size(); ++i){
        vertices.push_back(anss[i]);
    }
}
void SetGraph::GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices){
    vector<int_fast32_t> anss = links.at(vertex).second.first->list_all();
    for (int_fast32_t i = 0; i < anss.size(); ++i){
        vertices.push_back(anss[i]);
    }
}
