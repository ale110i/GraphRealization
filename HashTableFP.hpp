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

using namespace std;

template<class T> int_fast64_t hasher(T& line, int_fast64_t& arr_size);

template <class T>
class HashTableFP{
private:
    
    vector<T> elements; //Угу
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
    HashTableFP& operator=(HashTableFP const& table) = delete; //Угу
    HashTableFP(const HashTableFP &table) = delete; //Угу
    HashTableFP(HashTableFP &&table)  = delete; //Угу
    
    bool insert_element(T element); //Угу
    bool check_element(T element); //Угу
    bool delete_element(T element); //Угу
    
    vector<T> list_all();
    
};

template<class T> int_fast64_t hasher(T& line, int_fast64_t& arr_size){
    /*int_fast64_t hash = line[0];
     for (int_fast64_t i = 1; i < line.size(); ++i){
     hash = (hash * (seed) + line[i]) % arr_size;
     }*/
    int_fast64_t hash = line;
    return hash % arr_size;
}

template<class T> HashTableFP<T>::HashTableFP(){
    null_element = 0;
    deleted_element = 0;
    inserted_elements = 0;
    size = default_size;
    elements.resize(size, null_element);
    g_hasher = &reserve_hasher;
}

template<class T> HashTableFP<T>::HashTableFP(T el_null, T el_del, int_fast64_t (*hasher)(T& element, int_fast64_t& arr_size)){
    inserted_elements = 0;
    null_element = el_null;
    deleted_element = el_del;
    g_hasher = hasher;
    size = default_size;
    elements.resize(size);
    for (int_fast64_t i = 0; i < size; ++i){
        elements[i] = null_element;
    }
}

template<class T> HashTableFP<T>::~HashTableFP(){
    elements.clear();
}

template<class T> void HashTableFP<T>::check_ratio(){
    if (static_cast<double>(inserted_elements) / size >= 0.75){
        rehash();
    }
}

template<class T> void HashTableFP<T>::rehash(){
    vector<T> external = elements;
    size = size * 2;
    elements.clear();
    elements.resize(size);
    for (int_fast64_t i = 0; i < size; ++i){
        elements[i] = null_element;
    }
    inserted_elements = 0;
    for (int_fast64_t i = 0; i < external.size(); ++i){
        if (external[i] != null_element && external[i] != deleted_element){
            insert_element(external[i]);
        }
    }
}

template<class T> bool HashTableFP<T>::insert_element(T element){
    int_fast64_t i = 0;
    int_fast64_t element_hash = g_hasher(element, size);
    while (elements[(element_hash + i*i) % size] != null_element && elements[(element_hash + i*i) % size] != element){
        element_hash += i*i;
        ++i;
    }
    if (elements[(element_hash + i*i) % size] != null_element){
        return false;
    }
    elements[(element_hash + i*i) % size] = element;
    ++inserted_elements;
    check_ratio();
    return true;
}

template<class T> bool HashTableFP<T>::T_comparator(T &element1, T &element2){
    if (element1 == null_element || element2 == null_element){
        return false;
    }
    if (element1.size() != element2.size()){
        return false;
    }
    bool p = true;
    for (int_fast64_t i = 0; i < element2.size(); ++i){
        if (element1[i] != element2[i]){
            p = false;
            break;
        }
    }
    return p;
}

template<class T> bool HashTableFP<T>::check_element(T element){
    bool p = false;
    int_fast64_t i = 0;
    int_fast64_t element_hash = g_hasher(element, size);
    while (elements[(element_hash + i*i) % size] != null_element){
        if (T_comparator(elements[(element_hash + i*i) % size], element)){
            p = true;
            break;
        }
        element_hash += i*i;
        ++i;
    }
    return p;
}

template<class T> bool HashTableFP<T>::delete_element(T element){
    int_fast64_t i = 0;
    int_fast64_t element_hash = g_hasher(element, size);
    while (elements[(element_hash + i*i) % size] != null_element && elements[(element_hash + i*i) % size] != element){
        element_hash += i*i;
        ++i;
    }
    if (elements[(element_hash + i*i) % size] == null_element){
        return false;
    }
    elements[(element_hash + i*i) % size] = deleted_element;
    check_ratio();
    return true;
}

template<class T> vector<T> HashTableFP<T>::list_all(){
    vector<T> anss;
    for (int_fast32_t i = 0; i < size; ++i){
        if (elements.at(i) != null_element && elements.at(i) != deleted_element){
            anss.push_back(elements.at(i));
        }
    }
    return anss;
}

#endif /* HashTableFP_hpp */
