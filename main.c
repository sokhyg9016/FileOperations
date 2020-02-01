#pragma warning (disable :4996)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = NULL, * out = NULL;
	char str[60], tmp;

	in = fopen("src.txt", "r");
	out = fopen("dst.txt", "w");


	//Modified and write contents to 'dst.txt'
	fputs("+----+----+----+----+----+----+----+----+----+----+\n", out);
	while (fgets(str, 60, in) != NULL)
	{
		for (int i = 0; i < (int)strlen(str); i++)
		{
			tmp = 0;
			
			//if 11, str[0] = '1', str[1] = '1', str[2] = ',' so,
			//In order to get entire value, we need to get actual ten position.
			//e.g.s.,
			//(str[0] - '0') * 10 + (str[0] - '0') = 1*10 + 1 = 11
			while (isdigit(str[i]))
			{
				tmp = tmp * 10 + str[i] - '0';
				i++;
			}
			fprintf(out, "| %02d ", tmp);
		}
		fputs("|\n", out);
		fputs("+----+----+----+----+----+----+----+----+----+----+\n", out);
	}

	fclose(in);
	fclose(out);
	

	//Print to console.
	out = fopen("dst.txt", "r");

	while (fgets(str, 60, out) != NULL)
	{
		for (int i = 0; i < (int)strlen(str); i++)
		{
			printf("%c", str[i]);
		}
	}
	fclose(out);

	return 0;
}
//
//int main(void)
//{
//	char c = 10;
//	char tmp;
//
//	tmp = ~c;
//	printf("row: %#x\n", ~c);
//	printf("tmp: %#x\n\n", tmp);
//
//	tmp = c ^ -1;
//	printf("row: %#x\n", c ^ -1);
//	printf("tmp: %#x\n\n", tmp);
//
//	tmp = c ^ 0xff;
//	printf("row: %#x\n", c ^ 0xff);
//	printf("tmp: %#x\n\n", tmp);
//
//
//	return 0;
//}


//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<string.h>
//#include<memory.h>
//
//int GetSize()
//{
//	int i = 0;
//	while (getchar() != '\n')
//	{
//		i++;
//	}
//	return i;
//}
//
//
//int main()
//{
//	FILE* fp = stdin;
//	char* fptr = NULL;
//
//	getchar();
//	fptr = *((char**)&fp->_Placeholder + 1);
//
//	fptr[GetSize()] = '\0';
//
//	printf("fptr = \"%s\"\n", fptr);
//
//	return 0;
//}