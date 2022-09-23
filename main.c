#include <stdio.h>
#include <stdlib.h>

int encrypt(int x, int key){
  return x+key;
}

int unencrypt(int x, int key){
  return x-key;
}

int main(int argn,char** args){
  int a = 1;
  int y;
  char b = 'n';
  char text[] = "VICTOR";
  char encrypt_txt[7];
  char original_txt[7];
  int key = 2;
  
  //y = f(b); 
  //printf("n + 1 = %i\n",y);
  //printf("%i\n",b);

  printf("original= %s\n",text);
  printf("encriptada= ");
  for(int i=0; i < 6; i++ ){
    encrypt_txt[i] = encrypt(text[i],key);
    printf("%c",encrypt_txt[i]);
  }
  printf("\n");
  printf("desencriptada= ");
  for(int i=0; i < 6; i++ ){
    original_txt[i] = unencrypt(encrypt_txt[i],key);
    printf("%c",original_txt[i]);
  }
  printf("\n");  
  //printf("%s\n",text);
  return 0;
}
