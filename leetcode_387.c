int firstUniqChar(char * s){  // s = "dadadsfas"
	int pt1 = 0;
	int pt2 = 0;
	int num = strlen(s);
	int* visit = (int*) malloc (sizeof(int)*num);
	for(i=0;i<num;i++)
	{
		visit[i] = 0;            // visit���� ������¼��ǰ ָ����ַ�ǰ���Ƿ����ظ������Լ��ٺ������Ĵ����� 
	}
	if(num==1)  
	{
		return 0;
	}
	for(pt1=0;pt1<num;pt1++)    // ��ǰ����ǰ������ num-1��ͬ��pt1 Ӧ�ñ��������һ���� 
	{
		if(visit[pt1]==0)     // visit[pt1] Ϊ 0����ʾ��ʱ���ַ�����ʱû���ظ����ַ������� �� 
		{
			for(pt2=pt1+1;pt2<num;pt2++)
			{
				if(visir[pt2]==0)    // visit[pt2] ������Щ��ʱû���ظ����ַ��� 
				{
					if(s[pt2]==s[pt1])
					{
						visit[pt1] = 1;   // ǰ�������ظ��� �ı�� ����Ϊ�����ظ��� 
						visit[pt2] = 1;
					}
				}
			}
		}
		if(visit[pt1] == 0)
		{
			return pt1;
		}
	}
	return -1;
}
