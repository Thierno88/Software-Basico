#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS / 8];

/*
res = a + b 

void big_sum(BigInt res, BigInt a, BigInt b){
  
}
*/

void big_val(BigInt res, long val) {
  for (int i = 0; i < sizeof(long); i++) {
        res[i] = (val >> (i * 8)) & 0xFF;
    } 
  
  if( (res[7] & 1) == 0){
    for(int i =8;i<16;i++)
      res[i] = 0x00;
  }
    
  else if( (res[7] & 1) == 1){
    for(int i =8;i<16;i++)
      res[i] = 0xFF;
  }
  //testar valores negativos, 0 , positivos
}

void big_sum(BigInt res, BigInt a, BigInt b){
  int resto = 0;
	int soma;
  for (int i = 0; i < 16; i++) {
    soma = a[i] + b[i] + resto;
    res[i] = soma & 0xFF;
    resto = soma >> 8;
  }
  
  printf("Resultado da soma em hexadecimal: \n");
  for (int i = 0 ; i <= 15; i++) {
    printf("%02X ", (unsigned char) res[i]);
  }
  printf("\n");
}

int main(void) {
  BigInt vet;
  long value = -2;
  //char buffer[sizeof(long)];
  //longToByteArray(value, vet);
	printf("Vetor 1:\n");
  big_val(vet, value);
  for (int i = 0; i < sizeof(BigInt); i++) {
      printf("%02X ", (unsigned char) vet[i]);
     
  }
	printf("\n");

	BigInt vet2;
	long value2 = 20;
	BigInt vet3;
	long value3 = -30;

	big_val(vet2, value2);
	big_val(vet3, value3);
	printf("\nVetor 2: \n");
	for (int i = 0; i < sizeof(BigInt); i++) {
      printf("%02X ", (unsigned char) vet2[i]);
     
  }
	printf("\n");
	printf("\nVetor 3: \n");
	for (int i = 0; i < sizeof(BigInt); i++) {
      printf("%02X ", (unsigned char) vet3[i]);
     
  }

	BigInt res;
	printf("\n\n");
	big_sum(res, vet2, vet3);
  
  return 0;
}

