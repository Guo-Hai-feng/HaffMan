#include"哈夫曼.h"
//例，n=8,权值为{7，19，2，6,32,3,21,10}

void select(HuffmanTree HT, int n, int* s1, int* s2)
{
	int min1, min2;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			min1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i != min1 && HT[i].parent == 0)
		{
			min2 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight < HT[min1].weight)
		{
			min2 = min1;
			min1 = i;
		}
		else if (HT[i].parent == 0 && HT[i].weight < HT[min2].weight)
		{
			min2 = i;
		}
	}

	*s1 = min1;
	*s2 = min2;

}
int InitHuffmanTree(HuffmanTree HT, int n)
{
	int s1, s2;
	if (n <= 1)
		return ERROR;
	int m = 2 * n - 1;//数组共2n-1个元素,n个元素经过n-1次合并，总共增加了n-1个元素
	HT = (HuffmanTree)(malloc)((m + 1) * sizeof(HTNode));//0号元素没有使用，所以多开辟一个空间


	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].rch = 0;
		HT[i].lch = 0;
		HT[i].weight = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		//这里设置的权值数组的第一个元素是0，设置具体权重
		int temp;
		scanf("%d", &temp);
		HT[i].weight = temp;
	}
	//初始化结束，下面开始构造哈夫曼树
	for (int i = n + 1; i <= m; i++)
	{
		if (i == m)
		{
			s1 = i - 2;
			s2 = i - 1;
		}
		else
		{
			select(HT, i - 1, &s1, &s2);//在HT[k](1<=k<=i-1)中选择两个其双亲为0且权值最小的节点，并返回它们在HT中的序号s1,s2
			//printf("%d,%d\n", s1, s2);
		}
		HT[s1].parent = i;
		HT[s2].parent = i;//表示从列表中删除s1，s2

		HT[i].lch = s1;//为什么是序号呢，因为这不是链序存储，是数组存储，所以实际上的连接是存储对应的下标
		HT[i].rch = s2;

		HT[i].weight = HT[s1].weight + HT[s2].weight;//将i的权值为左右孩子权值之和
		printf("%d\n", HT[i].weight);
	}


	free(HT);
	HT = NULL;

}

int main()
{
	HuffmanTree HT = NULL;
	InitHuffmanTree(&HT, 8);

	return 0;

}