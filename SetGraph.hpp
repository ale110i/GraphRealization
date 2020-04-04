//
//  SetGraph.hpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef SetGraph_hpp
#define SetGraph_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#include "IGraph.hpp"
#include "HashTableFP.hpp"
#pragma once

class SetGraph: public IGraph{
private:
    void Insert_Vertex(pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>> vtx);
    bool Check(int_fast32_t vertex);
    vector<pair<int_fast32_t, pair<HashTableFP<int_fast32_t>*, HashTableFP<int_fast32_t>*>>> links;
public:
    SetGraph(){
        links.resize(0);
    }
    void AddEdge(int_fast32_t from, int_fast32_t to) override;
    
    int_fast32_t VerticesCount() override;
    
    void GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) override;
    void GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) override;
};

#endif /* SetGraph_hpp */
