//
//  main.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#include <string>
#include <unordered_set>
#include "IGraph.hpp"
#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"
#include "HashTableFP.hpp"


using namespace std;

enum vtx_color{
    white,
    gray,
    black,
};

bool is_full_black(vector<vtx_color> vt_c){
    for (int_fast32_t i = 0; i < vt_c.size(); ++i){
        if (vt_c.at(i) != black){
            return false;
        }
    }
    return true;
}

void dfs_plus_fc(IGraph*& graph,
                 vector<vtx_color>& vt_c,
                 vector<int_fast32_t>& cycles,
                 deque<int_fast32_t>& lv,
                 int_fast32_t curr_vtx)
{
    if (vt_c.at(curr_vtx) == gray){
        int_fast32_t i = 0;
        while (lv.at(i) != curr_vtx){
            ++i;
        }
        cycles.push_back(i + 1);
        return;
    }
    if (vt_c.at(curr_vtx) == black){
        return;
    }
    else {
        vt_c.at(curr_vtx) = gray;
        vector<int_fast32_t> nv;
        graph->GetNextVertices(curr_vtx, nv);
        if (!nv.empty()){
            lv.push_front(curr_vtx);
            for (int_fast32_t i = 0; i < nv.size(); ++i){
                if (lv.size() >= 2){
                    if (lv[1] != nv.at(i)){
                        if (vt_c.at(nv.at(i)) == black){
                            vt_c.at(nv.at(i)) = white;
                        }
                        dfs_plus_fc(graph, vt_c, cycles, lv, nv.at(i));
                    }
                }
                else {
                    dfs_plus_fc(graph, vt_c, cycles, lv, nv.at(i));
                }
            }
            lv.pop_front();
        }
        vt_c.at(curr_vtx) = black;
        if (lv.empty() && !is_full_black(vt_c)){
            for (int_fast32_t i = 0; i < vt_c.size(); ++i){
                if (vt_c.at(i) == white){
                    dfs_plus_fc(graph, vt_c, cycles, lv, i);
                }
            }
        }
    }
}

int full_find_min(IGraph*& graph, vector<vtx_color>& vt_c){
    vector<int_fast32_t> cycles;
    deque<int_fast32_t> lv;
    dfs_plus_fc(graph, vt_c, cycles, lv, 0);
    if (cycles.empty()){
        return -1;
    }
    else {
        int_fast32_t min_cycle = cycles.at(0);
        for (int_fast32_t i = 0; i < cycles.size(); ++i){
            if (cycles.at(i) < min_cycle){
                min_cycle = cycles.at(i);
            }
        }
        return min_cycle;
    }
}

int main(){
    
    int_fast32_t edges_count;
    int_fast32_t vertex_count;
    
    scanf("%i", &vertex_count);
    scanf("%i", &edges_count);
    
    [[maybe_unused]] IGraph* l = new ListGraph(vertex_count);
    [[maybe_unused]] IGraph* m = new MatrixGraph(vertex_count);
    [[maybe_unused]] IGraph* s = new SetGraph(vertex_count);
    [[maybe_unused]] IGraph* a = new ArcGraph(vertex_count);
    
    int_fast32_t from;
    int_fast32_t to;
    
    for (int_fast32_t i = 0; i < edges_count; ++i){
        scanf("%i", &from);
        scanf("%i", &to);
        
        l->AddEdge(from, to);
        m->AddEdge(from, to);
        s->AddEdge(from, to);
        a->AddEdge(from, to);
        
        l->AddEdge(to, from);
        m->AddEdge(to, from);
        s->AddEdge(to, from);
        a->AddEdge(to, from);
    }
    
    [[maybe_unused]] vector<vtx_color> l_cs(l->VerticesCount(), white);
    [[maybe_unused]] vector<vtx_color> m_cs(m->VerticesCount(), white);
    [[maybe_unused]] vector<vtx_color> s_cs(s->VerticesCount(), white);
    [[maybe_unused]] vector<vtx_color> a_cs(a->VerticesCount(), white);
    
    [[maybe_unused]] int_fast32_t l_mc = full_find_min(l, l_cs);
    [[maybe_unused]] int_fast32_t m_mc = full_find_min(m, m_cs);
    [[maybe_unused]] int_fast32_t s_mc = full_find_min(s, s_cs);
    [[maybe_unused]] int_fast32_t a_mc = full_find_min(a, a_cs);
    
    //printf("%i%s", l_mc, "\n");
    //printf("%i%s", m_mc, "\n");
    printf("%i%s", s_mc, "\n");
    //printf("%i%s", a_mc, "\n");
    
    return 0;
}
