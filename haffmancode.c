#include"������.h"
void creatHuffmanCode(HuffmanTree HT, HuffmanCode* HC, int n)
//��Ҷ�ӵ���������ÿһ���ַ��Ĺ��������룬�洢�ڱ����HC��
{
	//����ָ��
	HC = (char**)malloc((n + 1) * sizeof(char*));//����n���ַ������ͷָ��ʸ��
	char* cd = (char*)malloc(n * sizeof(char));//������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\0';//���������
	for (int i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0)//��Ҷ�ӽڵ㿪ʼ���ݣ�֪�����ڵ�
		{
			--start;
			if (HT[f].lch == c)//�ڵ������ӣ������ɴ���0
				cd[start] = '0';
			else
				cd[start] = '1';//�ڵ����Һ��ӣ������ɴ���1
			c = f;
			f = HT[i].parent;
		}//�����i���ַ��ı���
		HC[i] = (char*)malloc((n - start) * sizeof(char));//Ϊ��i���ַ����������ռ�
		strcpy(HC[i], &cd[start]);//����õı������ʱ�ռ临�Ƶ�HC������
	}
	free(cd);//�ͷ���ʱ�ռ�

}
