int firstUniqChar(char * s){  // s = "dadadsfas"
	int pt1 = 0;
	int pt2 = 0;
	int num = strlen(s);
	int* visit = (int*) malloc (sizeof(int)*num);
	for(i=0;i<num;i++)
	{
		visit[i] = 0;            // visit数组 用来记录当前 指向的字符前面是否有重复；可以减少后面进入的次数； 
	}
	if(num==1)  
	{
		return 0;
	}
	for(pt1=0;pt1<num;pt1++)    // 与前面以前排序中 num-1不同，pt1 应该遍历到最后一个； 
	{
		if(visit[pt1]==0)     // visit[pt1] 为 0，表示此时该字符是暂时没有重复的字符；进入 ； 
		{
			for(pt2=pt1+1;pt2<num;pt2++)
			{
				if(visir[pt2]==0)    // visit[pt2] 进入那些暂时没有重复的字符； 
				{
					if(s[pt2]==s[pt1])
					{
						visit[pt1] = 1;   // 前后两个重复的 改标记 ，记为有所重复； 
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
