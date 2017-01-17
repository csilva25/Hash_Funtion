/**
 * @file hash_function.cpp   Sort functions using hashtable.
 *
 * @brief
 *    I will implement a hashtable sort. In addition,
 *    due to the nature of hashtable, there will be
 *    collisions. Therefore, I will use chainning in
 *    solution for this issue.
 *
 * @author Cristian Silva
 * @reference cplusplus.com and algolist.net
 * @date 10/18/16
 */

#include <string>
#include <iostream>
#include <fstream>
#include "hash.h"
using namespace std;
Hash::Hash(){
   collisions = 0;
   longestList = 0;
   runningAvgListLength = 0;
}

/*
 This function calculates the average of the list length.
 It does this by traversing through the array and the
 list of key, adding one to a variable which we then
 divide by the size of the hash table. At this point,
 we can add that variable to the runnung average then
 divide by two to have the new running average list length.
 */
double Hash::averege(){
   double average =0;
   for (int i=0;i<HASH_TABLE_SIZE;i++)
      for (list<string>::iterator j = hashTable[i].begin();
           j != hashTable[i].end();j++)
         average++;
   average/=HASH_TABLE_SIZE;
   return runningAvgListLength = (runningAvgListLength + average)/2;
}

/*
 this function passes in a string from the file inputed
 and takes each string and makes it into a c style array
 which is the same characters in the string and places
 them into an array of that size including its
 terminator. in addition, this function creates a
 doubly linked list of one of more if the keys match.
 I check to make sure it was inserted properly and 
 calculate the avereage when finished.
 
 @param string name
         this is the word thats being created into 
         the c-style string.
 */
void Hash::processFile(string name){
   string input;
   unsigned int key,size =0;
   ifstream fin(name.c_str());
   while (fin >> input){
      key = hf(input);
      if (hashTable[key].empty() != true)
         collisions++;
      hashTable[key].push_back(input);
      if(search(input)){
         size = hashTable[key].size();
         if(size > longestList)
            longestList = hashTable[key].size();
         averege();
      }
   }
}
/*
 @param string name
 this is the word thats being created into
 the c-style string.
 */
void Hash::output(string name){
   ofstream fout(name.c_str());
   for(int i =0; i < HASH_TABLE_SIZE ; i++){
      fout << i << ":         ";
      for (list<string>::iterator j = hashTable[i].begin();
           j != hashTable[i].end();j++)
         fout << *j << ",";
      fout <<endl;
   }
}
/*
 this function prints all the strings in the hash table.
 */
void Hash::print(){
   for (int i=0;i<HASH_TABLE_SIZE;i++)
      for (list<string>::iterator j = hashTable[i].begin();
           j != hashTable[i].end();j++)
         cout << *j << ",";
   cout << endl;
}
/*
 this function prints the amount of collisions, longest 
 in the list, and the current running averege list 
 length. 
 */
void Hash::printStats(){
   cout <<"Total collisions = " << collisions <<endl;
   cout << "Longest list = " << longestList <<endl;
   cout << "Average list length = "<<runningAvgListLength<<endl;
}
/*
 this function traverses throught the linked list
 looking to the word passed in by the parameter
 then if it finds it, it returns true and if not 
 it returns false.
 
 @param string name
 this is the word thats being created into
 the c-style string.
 */
bool Hash::search(string word){
   int key = hf(word);
   for (list<string>::iterator i = hashTable[key].begin();
        i != hashTable[key].end();i++)
      if (*i == word)
         return true;
   return false;
}
/*
 this function searches for the word in the hash table 
 then it removes it and calculates the new average.
 
 @param string name
 this is the word thats being created into
 the c-style string.
 */
void Hash::remove(string word){
   if(search(word)){
      hashTable[hf(word)].remove(word);
      averege();
   }
}
