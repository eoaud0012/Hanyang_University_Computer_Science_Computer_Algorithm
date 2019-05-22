#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

/* TODO: Implement your own node and hash table if needed */
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next; 
    //
} HashNode;

typedef struct HashTable {
    int size;
    int* count;
    struct HashNode** table;
    struct HashNode** list;
    //

} HashTable;

/* Support those below interfaces (used in main.c) */
HashTable* makeHashTable(int size);
void insertHashNode(HashTable* ht, int key, int value);
void countingInsertHashNode(HashTable* ht, int key);
void makeSecondHashNodeList(HashTable* ht);
HashNode* findHashNode(HashTable* ht, int key);
void deleteHashNode(HashTable* ht, int key);
int hash(int size, int key);
#endif /* __HASHTABLE_H__ */
