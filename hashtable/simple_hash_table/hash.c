#include <stdio.h>
#include <stdlib.h>
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
//    memset(HT->table, 0, sizeof(HashNode)*size);
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
        HT->table[i]->next = NULL;
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
    HashNode* node = (HashNode*)malloc(sizeof(struct HashNode));
    HashNode* temp;
    node->key = address;
    node->value = value;
    node->next = NULL;
    // 비어있다면
    if(ht->table[address]->key == -1 && ht->table[address]->value == -1)
        ht->table[address] = node;

    // 비어있지 않다면,
    else if(ht->table[address]->key != -1 && ht->table[address]->value != -1) {
        while(ht->table[address]->key != -1 && ht->table[address]->value != -1) {
            ++address;
            address %= ht->size;
    }
        ht->table[address]->key = address;
        ht->table[address]->value = value;
        ht->table[address]->next = NULL;
}
}
HashNode* findHashNode(HashTable* ht, int key)
{
    int address;
    address = hash(ht, key);

    if(ht->table[address]->key == address)
       return ht->table[address];
return NULL;
}
void deleteHashNode(HashTable* ht, int key) {
    int address = hash(ht, key);
    if(ht->table[address]->key == address) {
        free(ht->table[address]);
        return;
    }
}
