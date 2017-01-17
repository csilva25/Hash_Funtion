/* This assignment originated at UC Riverside.*/

#include <string>
#include "hash.h"

using std::string;

// This is only a sample hash function (and a bad one at that). You will
// need to replace the contents of this hash function with your own
// hash function
/*
int
Hash::hf ( string ins ) {
   
   // place your hash function here....
   //return ( (int) ins[0] ) % HASH_TABLE_SIZE;
   unsigned h = 2166136261;
   unsigned long i;
   
   for (i = 0; i < ins.length(); i++)
   {
      h = (h * 16777619) ^ (int)ins[i];
   }
   
   return h%HASH_TABLE_SIZE;
}
*/


int
Hash::hf ( string ins ) {
   
   // place your hash function here....
   return ( (int) ins[0] ) % HASH_TABLE_SIZE;
   
}
