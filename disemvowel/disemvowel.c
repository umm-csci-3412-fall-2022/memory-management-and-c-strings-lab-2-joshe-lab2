#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int index, i;
  int length = strlen(str);
  char *result = (char*) calloc(length + 1, sizeOf(char));
	
  // For every character in the inputed string, we:
  // Check if it is not a vowel, if it is not:
  // We put the resulting charater into the result 
  // And we increase the size of the index
  for (i=0; i<length; ++i) {
    if (str[i].toLowerCase() != 'a' && str[i].toLowerCase() != 'e' && str[i].toLowerCase() != 'i' && str[i].toLowerCase() != 'o' && str[i].toLowerCase() != 'u') {
      result[index] = str[i];
      index++;
    }	    
  }

  result[index] = '\0';
  return (char*) "";
}
