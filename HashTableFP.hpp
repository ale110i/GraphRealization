//
//  HashTableFP.hpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef HashTableFP_hpp
#define HashTableFP_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <deque>
#pragma once

const size_t default_size = 57;


template<class T> int_fast64_t hasher(T& line, int_fast64_t& arr_size);

template <class T>
class HashTableFP{
private:
    
    std::vector<T> elements; //Угу
    T null_element;
    T deleted_element;
    
    int_fast64_t inserted_elements; //Угу
    int_fast64_t size; //Угу
    int_fast64_t (*g_hasher)(T& element, int_fast64_t& arr_size); //Угу
    int_fast64_t reserve_hasher(T& element, int_fast64_t& arr_size){
        return 1;
    }
    
    void check_ratio(); //Угу
    bool T_comparator(T &element1, T &element2); //Угу
    void rehash(); //Угу
    
public:
    
    HashTableFP();
    HashTableFP(T el_null, T el_del, int_fast64_t (*hasher)(T& element, int_fast64_t& arr_size)); //Угу
    ~HashTableFP(); //Угу
    //HashTableFP& operator=(HashTableFP const& table) = delete; //Угу
    //HashTableFP(const HashTableFP &table) = delete; //Угу
    //HashTableFP(HashTableFP &&table)  = delete; //Угу
    
    bool insert_element(T element); //Угу
    bool check_element(T element); //Угу
    bool delete_element(T element); //Угу
    
    std::vector<T> list_all();
    std::vector<T> list_all2() const;
    
};



#endif /* HashTableFP_hpp */
