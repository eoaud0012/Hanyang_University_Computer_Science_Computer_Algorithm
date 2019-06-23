#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
struct huffman_node* delete_min(min_heap* minheap) {
    int i = 0;
    int Child = 0;
}

struct min_heap* build_minheap(char* data, int* freq, int size) {
    int i = 0;
    min_heap* minheap = (min_heap*)malloc(sizeof(min_heap));

    for(i = 0; i < size; i++)
        minheap->array[i] = (huffman_node*)malloc(sizeof(huffman_node));

    minheap->size = 0;
    minheap->capacity = ASCII_SIZE;

    for(i = ++minheap->size; minheap->array[i/2]->frequency > freq[i]; i/=2) {
       minheap->array[i] = minheap->array[i/2]; 
    }
    minheap->array[i]->alphabet = data[i];
    minheap->array[i]->frequency = freq[i];
return minheap;
}

struct huffman_node** build_huffman_tree(huffman_node** huffman_tree, char* data, int* freq, int size) {
    huffman_node* right, left, first_node, second_node;

    min_heap* minheap;

    minheap = build_minheap(data, freq, size);

    first_node = delete_min(minheap);
    second_node = delete_min(minheap); 
}

/**
  Encode string to bit array using huffman coding algorithm

  @param[in]	src				Source raw string
  @param[in]	src_byte_size	Length of source string, in bytes
  @param[out]	table			Huffman table
  @param[out]	dst				Destination encoded bit array
  @return Length of encoded bit array, in bits (e.g. 0100 => 4)
*/

int encode_huffman(char *src, int src_byte_size,
				   struct huffman_table *table, char *dst)
{
  // TODO: Implement Me
   fprintf(stderr, "encode_huffman is not implemented
                    죄송합니다 교수님. 시험 공부에 치중하느라 코드를 다 작성하지 못했습니다. 방학동안 미비한 부분 채우겠습니다.\n");
   exit(1);
  int i = 0;
  int ascii = 0;
  int count = 0;
  huffman_node** huffman_tree;

  char* letter = (char*)malloc(sizeof(char)*ASCII_SIZE);
  int* freq_arr = (int*)malloc(sizeof(int)*ASCII_SIZE);

  for(i = 0; i < src_byte_size; i++) {
    ascii = src[i];
    letter[ascii] = src[i];
    freq_arr[i]++;
  } 

  huffman_tree = (huffman_node**)malloc(sizeof(huffman_node*)*ASCII_SIZE);
  build_huffman_tree(huffman_tree, letter, freq_arr, src_byte_size);
}

/**
  Decode bit array to string using huffman coding algorithm

  @param[in]	src				Source bit array
  @param[in]	src_bit_size	Length of bit array, in bits
  @param[out]	table			Huffman table
  @param[out]	dst				Destination string
  @return Length of decoded string, in bytes
*/
int decode_huffman(char *src, int src_bit_size,
				   struct huffman_table *table, char *dst)
{
	// TODO: Implement Me
    fprintf(stderr, "decode_huffman is not implemented\죄송합니다 교수님. 시험 공부에 치중하느라 코드를 다 작성하지 못했습니다. 방학동안 미비한 부분 채우겠습니다.\n");
	exit(1);
}

/**
  Make huffman table from huffman tree

  @param[in]	table			Huffman table
  @param[out]	dst				Destination string
  @return Length of huffman table string, in bytes
*/

int huffman_table_to_str(struct huffman_table *table, char *dst)
{
	// TODO: Implement Me
    fprintf(stderr, "decode_huffman is not implemented\죄송합니다 교수님. 시험 공부에 치중하느라 코드를 다 작성하지 못했습니다. 방학동안 미비한 부분 채우겠습니다.\n");
	exit(1);
}

/**
  Restore huffman tree from huffman table

  @param[in]	src				Source char array
  @param[in]	src_byte_size	Length of source string, in bytes
  @param[out]	table			Huffman table
  @return Success 1, Fail 0
*/
int huffman_table_from_str(char *src, int src_byte_size, struct huffman_table *table)
{
	// TODO: Implement Me
    fprintf(stderr, "decode_huffman is not implemented\죄송합니다 교수님. 시험 공부에 치중하느라 코드를 다 작성하지 못했습니다. 방학동안 미비한 부분 채우겠습니다.\n");
	exit(1);
}
