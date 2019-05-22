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
        HT->table[i]->key = -1;
        HT->table[i]->value = -1;
        HT->table[i]->next = NULL;
    }
    HT->list = (HashNode**)malloc(sizeof(HashNode*)*size);
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
    while(i < ht->size) {
         if(ht->count[i] >= 1) {
            ht->list[i] = (HashNode*)malloc(sizeof(HashNode)*ht->count[i]);
            if(!ht->list[i]) {
               printf("Out of Memrory!");
               return;
            } 
         }
         for(j = 0; j < ht->count[i]; j++) {
             ht->list[i][j].key = -1;
             ht->list[i][j].value = -1;
             ht->list[i][j].next = NULL;
         } 
        i++;
    }
    
}
void insertHashNode(HashTable* ht, int key, int value)
{
    int i = 0;
    int address = hash(ht->size, key);
    int second_size = (ht->count[address])*(ht->count[address]);
    int second_address = hash(second_size, address);
/*    HashNode* node = (HashNode*)malloc(sizeof(struct HashNode));
    HashNode* temp;
    node->key = address;
    node->value = value;
    node->next = NULL;
*/
    ht->list[address][second_address].key = second_address;
    ht->list[address][second_address].value = value;
    ht->list[address][second_address].next = NULL;
    ht->table[address]->next = ht->list[address];
}    
HashNode* findHashNode(HashTable* ht, int key)
{
    int address = 0;
    int second_address = 0;
    int second_size = 0;
    address = hash(ht->size, key);
    second_size = (ht->count[address]) * (ht->count[address]);
    second_address = hash(second_size, address);
    HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
    temp->key = ht->list[address][second_address].key;
    temp->value = ht->list[address][second_address].value;
    temp->next = ht->list[address][second_address].next;
    if(temp->key == -1 || temp->value == -1)
        return NULL;
return temp;
}

void deleteHashNode(HashTable* ht, int key)
{
    int address = 0;
    int second_address = 0;
    address = hash(ht->size, key);
    int second_size = 0;
    second_size = (ht->count[address]) * (ht->count[address]);
    second_address = hash(second_size, (ht->count[address])*(ht->count[address]));
    ht->list[address][second_address].key = -1;
    ht->list[address][second_address].value = -1;
    ht->list[address][second_address].next = NULL;
//    ht->count[address]--;
}
