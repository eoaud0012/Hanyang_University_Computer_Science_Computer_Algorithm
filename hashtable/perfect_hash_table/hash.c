#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
HashTable* makeHashTable(int size)
{
    int i;
    HashTable* HT;
    HT = (HashTable*)malloc(sizeof(HashTable));
    if(!HT) {
        printf("Out of Memory!");
        return NULL;
    }
    HT->size = size;
    HT->count = (int*)malloc(sizeof(int)*size);
    if(!HT->count) {
        printf("Out of Memrory!");
        return NULL;
    } 
    HT->table = (HashNode**)malloc(sizeof(HashNode*)*size);
    if(!HT->table) {
        printf("Out of Memrory!");
        return NULL;
    } 
    for(i = 0; i < size; i++) {
        HT->table[i] = (HashNode*)malloc(sizeof(HashNode));
        if(!HT->table[i]) {
            printf("Out of Memory!");
            return NULL;
        }
    }
    HT->list = (HashNode***)malloc(sizeof(HashNode**)*size);
    if(!HT->list) {
        printf("Out of Memrory!");
        return NULL;
    } 
   
return HT;
}
int hash(int size, int key)
{
return key % size;
}

void makeSecondHashNodeList(HashTable* ht) {
    int i = 0;
    int j = 0;
    for(i = 0; i < ht->size; i++) {
         if(ht->count[i] >= 1) {
            int newsize = (ht->count[i]) * (ht->count[i]);
            ht->list[i] = (HashNode**)malloc(sizeof(HashNode*));
            if(!ht->list[i]) {
               printf("Out of Memrory!");
               return;
            } 

            ht->list[i][j] = (HashNode*)malloc(sizeof(HashNode)*newsize);
            
            for(j = 0; j < newsize; j++) {
                 ht->list[i][j]->key = -1;
                 ht->list[i][j]->value = -1;
            }
         }  
    }
}
void insertHashNode(HashTable* ht, int key, int value)
{
    int i = 0;
    int address = hash(ht->size, key);
    int second_size = (ht->count[address])*(ht->count[address]);
    int second_address = hash(second_size, key);
    int second_address_pointer;

    second_address_pointer = second_address;
    
    // second_table 에서 collision 이 일어나지 않을 경우 
    if(ht->list[address][second_address]->key == -1) {
        ht->list[address][second_address]->key = key;
        ht->list[address][second_address]->value = value;
    }

    // second_table 에서 collision 일어날 경우, Linear Probing 수행 
   if(ht->list[address][second_address]->key != -1) {
        second_address_pointer++;
        while(ht->list[address][second_address_pointer]->key != -1) {
            second_address_pointer++;
            second_address_pointer %= second_size;
        }
        ht->list[address][second_address_pointer]->key = key;
        ht->list[address][second_address_pointer]->value = value;
   }
   }    
HashNode* findHashNode(HashTable* ht, int key)
{
    int address = 0;
    int second_address = 0;
    int second_size = 0;
    int second_address_pointer;

    address = hash(ht->size, key);
    second_size = (ht->count[address]) * (ht->count[address]);
    second_address = hash(second_size, key);
    HashNode* temp;
    second_address_pointer = second_address;

    // second table 에서 그 자리에 바로 값이 있는 경우 
    if(ht->list[address][second_address]->key == key) {
        temp = ht->list[address][second_address];
    }
    // second table 에서 그 자리에 바로 값이 없는 경우, Linear Probing 수행.
    else {
        second_address_pointer++;
        while(ht->list[address][second_address_pointer]->key != key) {
            second_address_pointer++;
            second_address_pointer %= second_size;
        }
        temp = ht->list[address][second_address_pointer];   
    }
return temp;
}
void deleteHashNode(HashTable* ht, int key)
{
    int address = 0;
    int second_address = 0;
    address = hash(ht->size, key);
    int second_size = 0;
    second_size = (ht->count[address]) * (ht->count[address]);
    second_address = hash(second_size, key);
    HashNode* temp;
    temp = findHashNode(ht, key);
    if(temp) {
        ht->list[address][second_address]->key = -1;
        ht->list[address][second_address]->value = -1;
    }
    else return;
}
