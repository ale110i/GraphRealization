//
//  MatrixGraph.hpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef MatrixGraph_hpp
#define MatrixGraph_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#include "IGraph.hpp"
#pragma once

class MatrixGraph: public IGraph{
private:
    int_fast32_t size;
    vector<pair<int_fast32_t, vector<bool>>> matrix;
    bool Check(int_fast32_t vertex);
public:
    void AddEdge(int_fast32_t from, int_fast32_t to) override;
    
    int_fast32_t VerticesCount() override;
    
    void GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) override;
    void GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) override;
};

#endif /* MatrixGraph_hpp */
