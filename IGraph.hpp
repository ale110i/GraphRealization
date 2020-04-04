//
//  IGraph.hpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef IGraph_hpp
#define IGraph_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#pragma once

using namespace std;

struct IGraph{
    virtual ~IGraph(){}
    
    //Добавление ребра от from к to:
    virtual void AddEdge(int_fast32_t from, int_fast32_t to) = 0;
    
    virtual int_fast32_t VerticesCount() = 0;
    
    virtual void GetNextVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) = 0;
    virtual void GetPrevVertices(int_fast32_t vertex, vector<int_fast32_t>& vertices) = 0;
};

#endif /* IGraph_hpp */
