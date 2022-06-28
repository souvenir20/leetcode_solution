#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define maxsize 26 

typedef struct hush_node
{
	int flag;
	int value;
	char key;
}hush_node;


hush_node* init_hush()
{
	hush_node* hush =(hush_node*) malloc (sizeof(hush_node)*maxsize);
	int i =0;
	for(i=0;i<maxsize;i++)
	{
		hush[i].key = '0';
		hush[i].value = 0;
		hush[i].flag = -1;
	}
	return hush;
}

// 看 字符s 对应的哈希表的键值对是否在前面已经找到； 
int find_this_key(char s,hush_node* hush)
{
	int index = s - 'a' ;
	if(hush[index].key == '0') // 此时是第一次出现字符s 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



int firstUniqChar(char * s){
	int i = 0;
    int pt1 = 0;
    int pt2 = 0;
    int flag = 0;                    // 用来标志 有没有找到 第一个不重复的字符；
	int index = -1; 
    hush_node *hush1 = init_hush();
    for(pt1=0;pt1<strlen(s);pt1++)
    {
    	int index = s[pt1] - 'a';       // 该字符在 hush 表对应键值对的下标位置；  
    	if(find_this_key(s[pt1],hush1))  // 在哈希中找到则进入：  
    	{
    		hush1[index].value++;
		}
		else                            // 哈希表中没有找到，则将其初始化； 
		{
			hush1[index].key = s[pt1];
			hush1[index].flag = pt1;
			hush1[index].value = 1;
		}
	}
	i = 0;
	index = s[i++] - 'a';
	while(hush1[index].value!=1)
	{
		if(i>=strlen(s))
		{
			return -1;
		}
		index = s[i++] - 'a';
	}
	return hush1[index].flag;
}

int main()
{
	char *s = "leetcode";
	int index = firstUniqChar(s);
	printf("%d",index);
	return 0;
}
