#include <stdio.h>
#include <unistd.h>
void Usage(char* msg)
{
	printf("Usage: %s fileName",msg);
}
int main(int argc,char* argv[])//   ./cat filename
{
	if(argc != 2)
	{
		Usage(argv[0]);
		return 2;
	}

	FILE* fp = fopen(argv[1],"r"); // 模拟cat
	
	if(fp == NULL)
	{
		perror("fopen error");
		return 1;
	}

	char buffer[64];
	while(fgets(buffer,sizeof(buffer),fp) != NULL)
	{
		printf("echo:%s",buffer);
	}

	fclose(fp);
	return 0;
}