#include<stdio.h>
#include<string.h>
main()
{
	char s[50]="gauravgautamartiraman";
	int i,j,k=0;
	int m=0,ch;
	int max[26]={0},b[26];
	for(i=0;i<strlen(s);i++)
	{
		max[s[i]-'a']++;
	}
	
	for(i=0;i<strlen(s);i++)
	{
		if(m<max[s[i]-'a'])
		{
			 m=max[s[i]-'a'];
			 ch=s[i];
		}
		
		 
	}
	printf("%c %d",ch,m);
    
	
}
