#ifndef __huffman_h__
#define __huffman_h__
#define ASCII_SIZE 128
typedef struct huffman_table
{
	// TODO: Implement me
    char *table[ASCII_SIZE]; 
} huffman_table;

typedef struct huffman_node
{
	// TODO: Implement me
    char alphabet;
    char letter[ASCII_SIZE];
    int frequency;
    int freq[ASCII_SIZE];
    struct huffman_node* next[2];
} huffman_node;

typedef struct min_heap
{
    int size;
    int capacity;
    struct huffman_node* array[ASCII_SIZE];
} min_heap;

/**
  Bit manipulation macros.
*/

// Get y-th bit in the buffer pointed by x
#define GET_BIT(x, y) (((x)[(y)/8] & (1 << (7 - ((y)%8)))) != 0)
// Set y-th bit in the buffer pointed by x
#define SET_BIT(x, y) do{\
	(x)[(y)/8] |= (1 << (7 - ((y)%8)));\
}while(0)
// Reset y-th bit in the buffer pointed by x
#define RESET_BIT(x, y) do{\
	(x)[(y)/8] &= (~(1 << (7 - ((y)%8))));\
}while(0)

int encode_huffman(char *src, int src_byte_size, struct huffman_table *table, char *dst);
int decode_huffman(char *src, int src_bit_size, struct huffman_table *table, char *dst);
int huffman_table_to_str(struct huffman_table *table, char *dst);
int huffman_table_from_str(char *src, int src_byte_size, struct huffman_table *table);

#endif /* __huffman_h__ */
