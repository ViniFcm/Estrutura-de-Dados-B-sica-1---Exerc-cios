//
//  Set.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef Set_h
#define Set_h

#include <unordered_set>

template <typename K>
class Set {
private:
    std::unordered_set<K> data;
    
public:
    Set();
    
    ~Set();
    
    bool contains(const K key);
    
    bool insert(const K key);
    
    bool remove(const K key);
    
    int getQuantity();
    
    bool isEmpty();
    
    void print();
};

template <typename K>
Set<K>::Set()
{
}

template <typename K>
Set<K>::~Set()
{
}

template <typename K>
bool Set<K>::contains(const K key)
{
    return data.find(key) != data.end();
}

template <typename K>
bool Set<K>::insert(const K key)
{
    data.insert( key );    
    return true;
}

template <typename K>
bool Set<K>::remove(const K key)
{
    if( !this->contains(key) )
    {
        return false;
    }
    
    data.erase( key );
    return true;
}

template <typename K>
int Set<K>::getQuantity()
{
    return data.size();
}

template <typename K>
bool Set<K>::isEmpty()
{
    return data.empty();
}

template <typename K>
void Set<K>::print()
{
    std::cout << "{";
    for ( auto it = data.begin(); it != data.end(); ++it )
    {
        std::cout << " " << it->first << ":" << it->second;
    }
    std::cout << " }\n";
}

#endif /* Set_h */
