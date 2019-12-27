/**
 * @file lphashtable.cpp
 * Implementation of the LPHashTable class.
 */
#include "lphashtable.h"

template <class K, class V>
LPHashTable<K, V>::LPHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new std::pair<K, V>*[size];
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = NULL;
        should_probe[i] = false;
    }
    elems = 0;
}

template <class K, class V>
LPHashTable<K, V>::~LPHashTable()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
}

template <class K, class V>
LPHashTable<K, V> const& LPHashTable<K, V>::operator=(LPHashTable const& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < size; i++)
            delete table[i];
        delete[] table;
        delete[] should_probe;

        table = new std::pair<K, V>*[rhs.size];
        should_probe = new bool[rhs.size];
        for (size_t i = 0; i < rhs.size; i++) {
            should_probe[i] = rhs.should_probe[i];
            if (rhs.table[i] == NULL)
                table[i] = NULL;
            else
                table[i] = new std::pair<K, V>(*(rhs.table[i]));
        }
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
LPHashTable<K, V>::LPHashTable(LPHashTable<K, V> const& other)
{
    table = new std::pair<K, V>*[other.size];
    should_probe = new bool[other.size];
    for (size_t i = 0; i < other.size; i++) {
        should_probe[i] = other.should_probe[i];
        if (other.table[i] == NULL)
            table[i] = NULL;
        else
            table[i] = new std::pair<K, V>(*(other.table[i]));
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void LPHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >= 0.7).
     * **Do this check *after* increasing elems (but before inserting)!!**
     * Also, don't forget to mark the cell for probing with should_probe!
     */
     elems++;
     if(shouldResize()) {resizeTable();}
     unsigned int hashCode=hashes::hash(key,size);
     //find the available slot and place it in the table, update the should_probe
     while(table[hashCode]!=NULL){
     hashCode=(hashCode+1)%size;}
     table[hashCode]=new std::pair<K,V>(key,value);
     should_probe[hashCode]=true;

    (void) key;   // prevent warnings... When you implement this function, remove this line.
    (void) value; // prevent warnings... When you implement this function, remove this line.
}

template <class K, class V>
void LPHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo: implement this function
     */

     //remove the elem, and don't do anything with the should_probe array
    int index=findIndex(key);
    if(index==-1){
      return;
    }
    delete table[index];
    table[index]=NULL;
    // should_probe[index]=false;  YOU should't do that
    elems--;
}

template <class K, class V>
int LPHashTable<K, V>::findIndex(const K& key) const
{
    // Firstly check the should_probe array, and then the table
    unsigned int hashCode=hashes::hash(key,size);
    for(size_t i=0;i<size;i++){
      if(should_probe[hashCode]==true){
        if(table[hashCode]!=NULL&&table[hashCode]->first==key){
          return hashCode;
        }
        else{ hashCode=(hashCode+1)%size; }
      }
      else{ return -1;}
    }
    return -1;

    /**
     * @todo Implement this function
     *
     * Be careful in determining when the key is not in the table!
     */

    // unsigned int hashCode=hashes::hash(key,size);
    // for(size_t j=0;j<size;j++){
    //   if(table[hashCode]==NULL){
    //     continue;
    //   }
    //   if(table[hashCode]->first==key){
    //     return hashCode;
    //   }
    //   hashCode=(hashCode+1)%size;
    // }
    // return -1;

}

template <class K, class V>
V LPHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& LPHashTable<K, V>::operator[](K const& key)
{
    // First, attempt to find the key and return its value by reference
    int idx = findIndex(key);
    if (idx == -1) {
        // otherwise, insert the default value and return it
        insert(key, V());
        idx = findIndex(key);
    }
    return table[idx]->second;
}

template <class K, class V>
bool LPHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void LPHashTable<K, V>::clear()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
    table = new std::pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void LPHashTable<K, V>::resizeTable()
{
    size_t nextSize=findPrime(2*size);
    std::pair<K, V>** newTable = new std::pair<K, V>*[nextSize];
    bool* new_should_probe = new bool[nextSize];
    for (size_t i = 0; i < nextSize; i++) {
        newTable[i] = NULL;
        new_should_probe[i] = false;
    }
    for(size_t i=0;i<size;i++){
      if(table[i]==NULL){continue;}
      unsigned int hashCode=hashes::hash(table[i]->first,nextSize);
      while(newTable[hashCode]!=NULL){
      hashCode=(hashCode+1)%size;}
      newTable[hashCode]=new std::pair<K,V>(table[i]->first,table[i]->second);
      new_should_probe[hashCode]=true;
      }
    for (size_t i = 0; i < size; i++)
          delete table[i];
    delete[] table;
    delete[] should_probe;
    table=newTable;
    should_probe=new_should_probe;
    size=nextSize;




    /**
     * @todo Implement this function
     *
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
}
