//100 interview question..
// 1. print duplicate character in string..
#include<stdio.h>
#include<string.h>
#include<limits.h>
/*
main()
{

	char a[50]="gauravverma";
	int n=strlen(a);
	int i,j,v=1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				if(v==1&&a[j]!='\0')
				{
					 printf("%c ",a[i]);
				}			     
			    a[j]='\0';
			    v++;
			}
		
		}
		v=1;
	}

	
}
*/
//2 check two string anagram or not..
/*
main()
{
char a[50]="test";
char b[50]="ttw";
int i,j,count1[26]={0},count2[26]={0};
int n1,n2;
n1=strlen(a);
n2=strlen(b);
int found=0;
for(i=0;i<n1;i++)
{
	count1[a[i]-'a']++;
}
for(i=0;i<n2;i++)
{
	count2[b[i]-'a']++;
}
for(i=0;i<26;i++)
{
	if(count1[i]!=count2[i])
	{
		found=1;
		break;
	}
}

if(found==1)
{
	printf("not anagram");
}
else
{
	printf("anagram");
}

}

*/
/* first non repeating char
main()
{
	char a[40]="swiss";
	int count[26]={0},i;
	for(i=0;i<strlen(a);i++)
	{
		count[a[i]-'a']++;
	}
	int m=1;
	for(i=0;i<strlen(a);i++)
	{
		if(count[a[i]-'a']==m)
		{
			printf("%c",a[i]);
			break;
		}
	}
}
*/
/*
void main()
{
    char str[50]="3749838485012509059asdf3";
    int i,len,count = 0;
    len = strlen(str);
    for(i=0;i<len;i++)
    {
            if(str[i] >= 48 && str[i] <= 57)    
            {
                 count++;
            }
            
    }
    if(count==len)
    printf("yes string contain digit only:");
    else
    printf("no string contain digit and more other character:");
}
*/

/*
main()
{
	char s[60]="how many vowels in this string";
	int i,j,c,count=0;
	for(c=0;c<strlen(s);c++)
	{
		  if (s[c] == 'a' || s[c] == 'e'||s[c] == 'i' || s[c] == 'o'|| s[c] == 'u')
            count++;
	}
    printf("%d",count);
}
*/

/*count occurance of char
main()
{
	char a[50]="gauravverma";
	char temp='a';
	int i,cnt=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==temp)
		cnt++;
	}
	printf("%d",cnt);
}

*/
/* perutation of given string
void swap(char* a,char*b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void permutation(char s[],int a,int n)
{
	int j;
	if(a==n)
	{
		printf("%s\n",s);
	}
	else
	{
		for(j=a;j<=n;j++)
		{
			swap((s+a),(s+j));
			permutation(s,a+1,n);
			swap((s+a),(s+j));
		}
	}
}
main()
{
	char a[50]="abc";
	int n=strlen(a);
	permutation(a,0,n-1);
	
}

*/

// find duplicate number in array

/*
main()
{

	int a[50]={1,2,1,2,3,4,5,6,5,4,7};
	int n=11;
	int i,j,v=1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				if(v==1&&a[j]!=0)
				{
					 printf("%d ",a[i]);
				}			     
			    a[j]=0;
			    v++;
			}
		
		}
		v=1;
	}	
}

*/

//find largest and smallest number in array

main()
{

	int a[50]={10,23,5,60,33,70,100,65,2};
	int n=9,i;
	int max=a[0];
	int min=a[1];
    for(i=1;i<n;i++)
    {
    	if(a[i]>max)
    	{
    		max=a[i];
		}
		else if(a[i]<min)
		{
			min=a[i];
		}
		
	}
	printf("%d %d",min,max);
}








