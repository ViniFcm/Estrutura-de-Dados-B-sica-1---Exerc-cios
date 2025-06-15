//
//  HashTable.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef HashTable_h
#define HashTable_h

#include "HashEntry.h"
#include <string>

static const int TABLE_SIZE = 17;
static const float MIN_ALPHA = 0.125f;
static const float MAX_ALPHA = 0.5f;

class HashTable {
    
public:
    unsigned long size;
    
    unsigned long quantity;
    
    void init();
    
    unsigned long preHash(const std::string);
    
    unsigned long hash(const std::string);
    
    HashEntry<std::string, std::string> **data;
    
    HashTable();
    
    HashTable(const unsigned long size);
    
    ~HashTable();
    
    bool put(const std::string key, const std::string value);
    
    bool remove(const std::string k);
    
    unsigned long getSize();
    
    unsigned long getQuantity();
    
    bool isEmpty();
    
    bool isFull();
    
    void print();
};


#endif /* HashTable_h */
