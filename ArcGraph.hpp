//
//  ArcGraph.hpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef ArcGraph_hpp
#define ArcGraph_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#include "IGraph.hpp"
#pragma once

class ArcGraph: public IGraph{
private:
    int_fast32_t vertices_count = 0;
    std::vector<std::pair<int_fast32_t, int_fast32_t>> links;
public:
    ArcGraph(IGraph*& another_graph);
    ArcGraph(int_fast32_t vt_count);
    void AddEdge(int_fast32_t from, int_fast32_t to) override;
    
    int_fast32_t VerticesCount() const override;
    
    void GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const override;
    void GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const override;
};

#endif /* ArcGraph_hpp */
