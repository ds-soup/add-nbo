#include<stdio.h>
#include <netinet/in.h>
#include<stdint.h>
#include<stdlib.h>


uint32_t buf[4];

uint32_t ReadFile(char * fileName) {
	uint32_t size = 4;
	FILE *pFile = fopen(fileName, "rb");
	for(uint32_t i=0; i<size; i++) {
		fread(&buf[i], sizeof(uint32_t), 1, pFile);
	}
	uint32_t result = (uint32_t)(buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3]);
	return  buf[0];
}


int main(int argc, char * argv[]) {

	if(argc <2) {
		printf("Usage[*] : ./add-nbo {arg1} [arg2]");
		exit(0);
	}
	uint32_t n1 = ReadFile(argv[1]);
	uint32_t n2 = ReadFile(argv[2]);

	n1 = htonl(n1);
	n2 = htonl(n2);
	printf("0x%x + 0x%x = ", n1, n2);
	uint32_t result = n1 + n2;
	printf("0x%x\n", result);
	//uint32_t n2 = ReadFile(argv[2]);


}
