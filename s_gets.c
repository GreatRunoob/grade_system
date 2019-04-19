#include<stdio.h>
#include<stdlib.h>
#include"students_info.h"

char*s_gets(char*str)
{
	char*real_var;
	int i=0;
	
	real_var=fgets(str,LIMIT,stdin);
	
	if(real_var)
	{
		while(str[i]!='\n'&&str!='\0')
			i++;
		
		if(str[i]=='\n')
			str[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	else
	{
		printf("×Ö·û¶ÁÈ¡Ê§°Ü£¡´íÎó´úÂë000\n");
		exit(EXIT_FAILURE);
	}
	
	return real_var;
}
