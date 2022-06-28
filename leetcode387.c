#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define maxsize 26 //�˴��ַ�ֻ��26�֣�����һ��26���ȵĹ�ϣ���ɣ� 

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

// �� �ַ�s ��Ӧ�Ĺ�ϣ��ļ�ֵ���Ƿ���ǰ���Ѿ��ҵ��� 
int find_this_key(char s,hush_node* hush)
{
	int index = s - 'a' ;
	if(hush[index].key == '0') // ��ʱ�ǵ�һ�γ����ַ�s 
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
    int flag = 0;                    // ������־ ��û���ҵ� ��һ�����ظ����ַ���
	int index = -1; 
    hush_node *hush1 = init_hush();
    for(pt1=0;pt1<strlen(s);pt1++)
    {
    	int index = s[pt1] - 'a';       // ���ַ��� hush ���Ӧ��ֵ�Ե��±�λ�ã�  
    	if(find_this_key(s[pt1],hush1))  // �ڹ�ϣ���ҵ�����룺  
    	{
    		hush1[index].value++;
		}
		else                            // ��ϣ����û���ҵ��������ʼ���� 
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
