#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

#define HUFFMAN_DEFAULT 10000

int encoding(char *input_filename, char *output_filename)
{
	int input_byte_size, encoded_bit_size, huffman_table_str_size;
	char *input_str, *encoded_str, *huffman_table_str;
	struct huffman_table *table;

	// Open input and output file for encoding
	FILE *in = fopen(input_filename, "r");
	FILE *out = fopen(output_filename, "w");
	if (in == NULL || out == NULL)
	{
		fprintf(stderr, "fopen failed!\n");
		return -1;
	}

	// Get string size from file size
	fseek(in, 0L, SEEK_END);
	input_byte_size = ftell(in);
	fseek(in, 0L, SEEK_SET);

	// Allocate buffer space for string
	input_str = (char *)malloc(sizeof(char) * (input_byte_size + 1));
	encoded_str = (char *)malloc(sizeof(char) * (input_byte_size + 1));
	huffman_table_str = (char *)malloc(sizeof(char) * HUFFMAN_DEFAULT);
	table = (struct huffman_table *)malloc(sizeof(struct huffman_table));

	// Read string from the input file
	if (fread(input_str, 1, input_byte_size, in) != input_byte_size)
	{
		fprintf(stderr, "fread failed!\n");
		return -1;
	}
	fclose(in);

	// Encoding
	encoded_bit_size = encode_huffman(
		input_str,
		input_byte_size,
		table,
		encoded_str);

	// Convert huffman table to string
	huffman_table_str_size = huffman_table_to_str(
		table,
		huffman_table_str);

	// Make encoded File
	fwrite(&huffman_table_str_size, 4, 1, out);
	fwrite(huffman_table_str, 1, huffman_table_str_size, out);
	fwrite(&encoded_bit_size, 4, 1, out);
	fwrite(encoded_str, 1, (encoded_bit_size + 7) / 8, out);
	fclose(out);

	// free allocated memory
	free(input_str);
	free(encoded_str);
	free(huffman_table_str);

	return 1;
}

int decoding(char *input_filename, char *output_filename)
{

	int input_byte_size, encoded_bit_size, decoded_byte_size, huffman_table_str_size;
	char *input_str, *decoded_str, *huffman_table_str;
	struct huffman_table *table;

	// Open input and output file for encoding
	FILE *in = fopen(input_filename, "r");
	FILE *out = fopen(output_filename, "w");
	if (in == NULL || out == NULL)
	{
		fprintf(stderr, "fopen failed!\n");
		return -1;
	}

	// Get string size from file size
	fseek(in, 0L, SEEK_END);
	input_byte_size = ftell(in);
	fseek(in, 0L, SEEK_SET);

	// Allocate buffer space for string
	input_str = (char *)malloc(sizeof(char) * (input_byte_size + 1));
	decoded_str = (char *)malloc(sizeof(char) * (input_byte_size * 8));
	huffman_table_str = (char *)malloc(sizeof(char) * HUFFMAN_DEFAULT);
	table = (struct huffman_table *)malloc(sizeof(struct huffman_table));

	// Read string from the input file
	if (fread(input_str, 1, input_byte_size, in) != input_byte_size)
	{
		fprintf(stderr, "fread failed!\n");
		return -1;
	}
	fclose(in);

	// Pointer calculation
	huffman_table_str_size = *((int *)input_str);
	strncpy(huffman_table_str, input_str + 4, huffman_table_str_size);
	encoded_bit_size = *((int *)(input_str + huffman_table_str_size + 4));

	// Restore huffman table
	huffman_table_from_str(huffman_table_str, huffman_table_str_size, table);

	// Decoding
	decoded_byte_size = decode_huffman(
		input_str + (huffman_table_str_size + 8),
		encoded_bit_size,
		table,
		decoded_str);

	fwrite(decoded_str, 1, decoded_byte_size, out);
	fclose(out);

	// Free allocated memory
	free(input_str);
	free(decoded_str);
	free(huffman_table_str);

	return 1;
}

int main(int argc, char *argv[])
{
	// Check arguments of main
	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s <input-text-file>\n", argv[0]);
		return 1;
	}

	// Make filenames
	char input_filename[128], encoded_filename[128], decoded_filename[128];
	strcpy(input_filename, argv[1]);
	strcpy(encoded_filename, input_filename);
	strcat(encoded_filename, ".encoded");
	strcpy(decoded_filename, input_filename);
	strcat(decoded_filename, ".decoded");

	// Encoding input_file
	if (encoding(input_filename, encoded_filename) < 0)
	{
		fprintf(stderr, "encoding error!\n");
		return 1;
	}

	// Decoding encoded_file
	if (decoding(encoded_filename, decoded_filename) < 0)
	{
		fprintf(stderr, "decoding error!\n");
		return 1;
	}
	return 0;
}
