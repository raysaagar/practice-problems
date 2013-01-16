/*************************************************************
 * Simple Hash Table for a Spell Checker (Hash Table Example)
 * Uses FNV32 Hash Function
 ************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h>

// FNV function values
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U

// Size of the hash table
#define ARRAYSIZE 10000

/* PROTOTYPES */
uint32_t FNV32(const char *s);
uint32_t hashword(const char *s); //wrapper function

/* GLOBAL VARIABLES */

// a way to store the word in the array
typedef struct node{
  char word[101];
  struct node* next;
} node;

// hash table 
node hashtable[ARRAYSIZE];

int main(int argc, char *argv[])
{

  if(argc < 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--h") == 0 || strcmp(argv[1],"-help") == 0){
    printf("Usage: pinshash dictionary wordlist\n");
    printf("pinshash -h gives this message\n");
    return 0;
  }

  // create the dictionary hashtable
  FILE *dict = fopen(argv[1], "r");
  // get the words from the dictionary and hash them
  if (dict != NULL){
    char buffer[101];
    while (fgets(buffer, sizeof(buffer), dict) != NULL){
      // hash the word
      uint32_t hash = hashword(buffer);
      // create a node to store the word
      node* m = malloc(sizeof(node));
      // push the buffer into the node
      for(int i = 0; i < sizeof(buffer); i++){
        m->word[i] = buffer[i];
      }
      m->next = NULL;
      // insert word into hashtable
      hashtable[hash] = *m;
      free(m);
      //TODO: hash collision
    }
  }
  fclose(dict);

  // check words!
  FILE *file = fopen(argv[2], "r"); 

  if (file != NULL){
    char buffer[101];
    while (fgets(buffer, sizeof(buffer), file) != NULL){
      // hash the word
      uint32_t hash = hashword(buffer);
      // get the node to compare
      node m = hashtable[hash];
      // check the word
      if(strcmp(buffer, m.word)!=0)
        printf("ERROR: %s", buffer);
    }
  }

  fclose(file);
  
  //TODO: free hash table memory?

  return 0;
}


// wrapper for FNV32 hash
uint32_t hashword(const char *s){return FNV32(s)%ARRAYSIZE;}

// hash function found at http://ctips.pbworks.com/w/page/7277591/FNV%20Hash
uint32_t FNV32(const char *s){

  uint32_t hash = FNV_OFFSET_32, i;
  for(i = 0; i < strlen(s); i++)
  {
    hash = hash ^ (s[i]); // xor next byte into the bottom of the hash
    hash = hash * FNV_PRIME_32; // Multiply by prime number found to work well
  }
  return hash;
}

