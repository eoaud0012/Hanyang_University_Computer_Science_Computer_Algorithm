#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "hash.h"

HashTable* makeHashTable(int size)
{ 
    int i = 0;
    HashTable* HT;
    HT = (HashTable*)malloc(sizeof(HashTable));
    if(!HT) {
        printf("Out of Memory!");
        return NULL;
    }
    HT->table = (HashNode**)malloc(sizeof(HashNode*)*size);
    HT->size = size;

    if(!HT->table) {
        printf("Out of Memory!");
        return NULL;
    }

    for(i = 0; i < size; i++) {
        HT->table[i] = (HashNode*)malloc(sizeof(HashNode));
        if(!HT->table[i]) {
            printf("Out of Memory!");
            return NULL;
        }
        HT->table[i]->key = -1;
        HT->table[i]->value = -1;
    }

return HT;
}

int hash(HashTable* ht, int key) 
{
    return key % (ht->size);
}
void insertHashNode(HashTable* ht, int key, int value)
{
    int address;
    address = hash(ht, key);
    // 비어있다면
    if(ht->table[address]->key == -1) {
        ht->table[address]->key = key;
        ht->table[address]->value = value;
    }
    // 비어있지 않다면,
    else {
        address++;
        while(ht->table[address]->key != -1) {
            ++address;
            address %= ht->size;
        }
        ht->table[address]->key = key;
        ht->table[address]->value = value;
    }
}
HashNode* findHashNode(HashTable* ht, int key)
{
    int address = 0;
    int address_pointer = 0;
    address = hash(ht, key);
    address_pointer = address;
    // 찾고자 하는 값이 바로 있을 때
    if(ht->table[address]->key == key)
       return ht->table[address];

    // 바로 없을 때(한바퀴 돌고)
    else {
        address_pointer++;
        while(ht->table[address_pointer]->key != key && address_pointer+1 != address) {
            address_pointer++;
            address_pointer %= ht->size;
        }
        
        if(address_pointer+1 == address) return NULL;
        else return ht->table[address_pointer];
    }
}

void deleteHashNode(HashTable* ht, int key) {
    int address = 0;
    HashNode* temp;
    temp = findHashNode(ht, key);
    // 찾고자 하는 값이 바로 있을 때, 해당 slot에는 없으나 Linear Probing으로 인해 다른 slot에 있을 때 모두 포함하여 수행, 각 값 0 대입 진행.
    if(temp) {   
        temp->key = -1;
        temp->value = -1;
    } 
    else return;
}
