#include <stdio.h>
#include <string.h>
#define MIN 6
#define MAX 20


int main(char s[]) {
  char *s0 = s[];

  if (s0 == null || strcmp(s0, "") != 0) {
    reuturn 6;
  }

  int add = 0;
  int del = 0;
  int rep = 0;

  int length = strlen(s0);

  int lower_cnt = 0;
  int upper_cnt = 0;
  int num_cnt = 0;

  for (int i = 0; i < length; i++) {
    if (s0[i] >= 'a' && s0[i] <= 'z') ++lower_cnt;
    if (s0[i] >= 'A' && s0[i] <= 'Z') ++upper_cnt;
    if (s0[i] >= '0' && s0[i] <= '9') ++num_cnt;
  }

/*
  status count
  000 including all requirement
  001 missing lowercase
  010 missing uppercase
  011 missing lowercase and uppercase
  100 missing numeric
  101 missing lowercase and numeric
  111 not including any requirement
*/
  int status = 0;
  if (lower_cnt == 0) status += 1;
  if (upper_cnt == 0) status += 10;
  if (num_cnt == 0) status += 100;

  //TODO attach repeatDetector function to this sector.

  if (length < MIN) {
    //return MIN - length when 000, 001, 010, 100
  }else if(length > MAX) {
    if (status == 0) {
      return (length - MAX);
    }else if (status == 1 || status == 10 || status == 100) {
      return (length - MAX + 1);
    }else if (status == 11 || status == 101) {
      return (length - MAX + 2);
    }else if (status == 111) {
      return (length - MAX + 3);
    }
  }
}

// return 1 when detect three continuous character
int repeatDetector(char s[]) {
  int length = strlen(s);
  char prevChar = "";
  int continuousCnt = 0;
  for (int i = 0; i < length; i++) {
    if (s[i] == prevChar) {
      ++continuousCnt;
    }else{
      continuousCnt = 0;
    }
    if (continuousCnt == 3) return 1;
    prevChar = s[i];
  }
  return 0;
}
