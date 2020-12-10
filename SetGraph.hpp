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
#include "HashTableFP.cpp"
#pragma once

class SetGraph: public IGraph{
private:
    std::vector<std::pair<HashTableFP<int_fast32_t>, HashTableFP<int_fast32_t>>> links;
    int_fast32_t vertices_count = 0;
public:
    SetGraph(IGraph*& another_graph);
    SetGraph(int_fast32_t vt_count);
    void AddEdge(int_fast32_t from, int_fast32_t to) override;
    
    int_fast32_t VerticesCount() const override;
    
    void GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const override;
    void GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const override;
};

#endif /* SetGraph_hpp */
