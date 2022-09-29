#include <stdlib.h>

#include "disemvowel.h"

#include <string.h>

char *disemvowel(char *str) {
  int i;
  int index = 0;
  int length = strlen(str);
  char *result = (char*) calloc(length + 1, sizeof(char));
	
  // For every character in the inputed string, we:
  // Check if it is not a vowel, if it is not:
  // We put the resulting charater into the result 
  // And we increase the size of the index
  for (i=0; i<length; ++i) {
    if (str[i] != 'A' && str[i] != 'a' && str[i] != 'E' && str[i] != 'e' && str[i] != 'I' && str[i] != 'i' && str[i] != 'O' && str[i] != 'o' && str[i] != 'U' && str[i] != 'u') {
      result[index] = str[i];
      index++;
    }	    
  }
 
  if (index == 0) {
    free((char*)result);
    return (char*) "";
  }

  result[index] = '\0';
  return result;
}
