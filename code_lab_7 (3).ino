#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

volatile unsigned char* port_b = (unsigned char*) 0x25;
volatile unsigned char* ddr_b = (unsigned char*) 0x24;
volatile unsigned char* pin_b = (unsigned char*) 0x23;
volatile unsigned char* port_k = (unsigned char*) 0x108;
volatile unsigned char* ddr_k = (unsigned char*) 0x107;
unsigned int pin1, pin2, pin3, pin0, total = 0; 

#define SIZE 20

struct DataItem {
   unsigned int data;
   unsigned int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(unsigned int key) {
   return key % SIZE;
}

struct DataItem *search(unsigned int key) {
   //get the hash 
   int hashIndex = hashCode(key);  
  
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
  
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
      
      //go to next cell
      ++hashIndex;
    
      //wrap around the table
      hashIndex %= SIZE;
   }        
  
   return NULL;        
}

void insert(unsigned int key,unsigned int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
    
      //wrap around the table
      hashIndex %= SIZE;
   }
  
   hashArray[hashIndex] = item;
}

struct DataItem *delete_item(struct DataItem* item) {
   unsigned int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
  
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
      
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
    
      //go to next cell
      ++hashIndex;
    
      //wrap around the table
      hashIndex %= SIZE;
   }      
  
   return NULL;        
}

void setup() {
  // put your setup code here, to run once:
   *ddr_b &= 0xF8; // Enables our input PB0-3 (4 inputs)
   *ddr_k |= 0x7F; //Enables our output PK0-6 (7 outputs)
   insert(0, 0b00111111);
   insert(1, 0b00000110);
   insert(2, 0b01011011);
   insert(3, 0b01001111);
   insert(4, 0b01100110);
   insert(5, 0b01101101);
   insert(6, 0b01111101);
   insert(7, 0b00000111);
   insert(8, 0b01111111);
   insert(9, 0b01100111);
   insert(10, 0b01110111);
   insert(11, 0b01111100);
   insert(12, 0b00111001);
   insert(13, 0b01011110);
   insert(14, 0b01111001);
   insert(15, 0b01110001);

}

void loop() {
  // put your main code here, to run repeatedly:

  pin0 = (*pin_b &= 0b00000001);
  pin1 = (*pin_b &= 0b00000010);
  pin2 = (*pin_b &= 0b00000100);
  pin3 = (*pin_b &= 0b00001000);
  total = pin0 + pin1 + pin2 + pin3;

  item = search(total);
  *port_k &= item->data;
  
}
