#include"������.h"
//����n=8,ȨֵΪ{7��19��2��6,32,3,21,10}

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
	int m = 2 * n - 1;//���鹲2n-1��Ԫ��,n��Ԫ�ؾ���n-1�κϲ����ܹ�������n-1��Ԫ��
	HT = (HuffmanTree)(malloc)((m + 1) * sizeof(HTNode));//0��Ԫ��û��ʹ�ã����Զ࿪��һ���ռ�


	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].rch = 0;
		HT[i].lch = 0;
		HT[i].weight = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		//�������õ�Ȩֵ����ĵ�һ��Ԫ����0�����þ���Ȩ��
		int temp;
		scanf("%d", &temp);
		HT[i].weight = temp;
	}
	//��ʼ�����������濪ʼ�����������
	for (int i = n + 1; i <= m; i++)
	{
		if (i == m)
		{
			s1 = i - 2;
			s2 = i - 1;
		}
		else
		{
			select(HT, i - 1, &s1, &s2);//��HT[k](1<=k<=i-1)��ѡ��������˫��Ϊ0��Ȩֵ��С�Ľڵ㣬������������HT�е����s1,s2
			//printf("%d,%d\n", s1, s2);
		}
		HT[s1].parent = i;
		HT[s2].parent = i;//��ʾ���б���ɾ��s1��s2

		HT[i].lch = s1;//Ϊʲô������أ���Ϊ�ⲻ������洢��������洢������ʵ���ϵ������Ǵ洢��Ӧ���±�
		HT[i].rch = s2;

		HT[i].weight = HT[s1].weight + HT[s2].weight;//��i��ȨֵΪ���Һ���Ȩֵ֮��
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