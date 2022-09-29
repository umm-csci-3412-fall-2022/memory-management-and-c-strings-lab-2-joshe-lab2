#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *output = disemvowel((char*) "");
  ASSERT_STREQ("", output);
  free ((char*) output);
}

TEST(Disemvowel, HandleNoVowels) {
  char *output = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", output);
  free ((char*) output);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *output = disemvowel((char*) "aeiouAEIUOIEAuoiea");
  ASSERT_STREQ("", output);
  free ((char*) output);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *output = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", output);
  free ((char*) output);
}

TEST(Disemvowel, HandlePunctuation) {
  char *output = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", output);
  free ((char*) output);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char *output = disemvowel((char*) "str");
  ASSERT_STREQ("xyz", output);
  free(str);
  free ((char*) output);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
