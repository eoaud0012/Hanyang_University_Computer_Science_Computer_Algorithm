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

/*
int hash2(int size, int key)
{
return (key + 31) * 
}
*/

void makeSecondHashNodeList(HashTable* ht) {
    int i = 0;
    int j = 0;
    while(i < ht->size) {
         if(ht->count[i] >= 1) {
            int newsize = (ht->count[i]) * (ht->count[i]);
            ht->list[i] = (HashNode*)malloc(sizeof(HashNode)*newsize);
            if(!ht->list[i]) {
               printf("Out of Memrory!");
               return;
            } 

            for(j = 0; j < newsize; j++) {
                 ht->list[i][j].key = -1;
                 ht->list[i][j].value = -1;
                 ht->list[i][j].next = NULL;
             }
         }  
        i++;
    }
    
}
void insertHashNode(HashTable* ht, int key, int value)
{
    int i = 0;
    int address = hash(ht->size, key);
    int second_size = (ht->count[address])*(ht->count[address]);
    int second_address = hash(second_size, key);
    int a;
    a = second_address;

    // second_table 에서 collision 발생 시, Linear Probing 수행
   if(ht->list[address][second_address].key != -1 && ht->list[address][second_address].value != -1) {
        a++;
        while(ht->list[address][a].key != -1 && ht->list[address][a].value != -1) {
            a++;
            a %= second_size;
        }
        ht->list[address][a].key = key;
        ht->list[address][a].value = value;
   }

   // second_table 에서 collision 발생하지 않을 때
    else if(ht->list[address][second_address].key == -1 && ht->list[address][second_address].value == -1) {
        ht->list[address][second_address].key = key;
        ht->list[address][second_address].value = value;
    }

    ht->table[address]->next = ht->list[address];
}    
HashNode* findHashNode(HashTable* ht, int key)
{
    int address = 0;
    int second_address = 0;
    int second_size = 0;
    int a;
    address = hash(ht->size, key);
    second_size = (ht->count[address]) * (ht->count[address]);
    second_address = hash(second_size, key);
    HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
    a = second_address;
    // second table에서 찾고자 하는 값이 바로 있을 때
    if(ht->list[address][second_address].key == key) {
        temp->key = ht->list[address][second_address].key;
        temp->value = ht->list[address][second_address].value;
    }
    // second table에서 그 자리에는 없으나, Linear Probing으로 인해 다른 slot에 있거나, 아예 없을 때
    else {
        a++;
        while(ht->list[address][a].key != key) {
            a++;
            a %= second_size;
            if(a = second_address - 1) return NULL;
        }
        temp->key = ht->list[address][second_address].key;
        temp->value = ht->list[address][second_address].value;   
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

    if(findHashNode(ht, key)) {
        ht->list[address][second_address].key = -1;
        ht->list[address][second_address].value = -1;
    }
    else return;
}
