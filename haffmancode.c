#include"哈夫曼.h"
void creatHuffmanCode(HuffmanTree HT, HuffmanCode* HC, int n)
//从叶子到根逆向求每一个字符的哈夫曼编码，存储在编码表HC中
{
	//二级指针
	HC = (char**)malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针矢量
	char* cd = (char*)malloc(n * sizeof(char));//分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';//编码结束符
	for (int i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0)//从叶子节点开始回溯，知道根节点
		{
			--start;
			if (HT[f].lch == c)//节点是左孩子，则生成代码0
				cd[start] = '0';
			else
				cd[start] = '1';//节点是右孩子，则生成代码1
			c = f;
			f = HT[i].parent;
		}//求出第i个字符的编码
		HC[i] = (char*)malloc((n - start) * sizeof(char));//为第i个字符串编码分配空间
		strcpy(HC[i], &cd[start]);//将求得的编码从临时空间复制到HC行列中
	}
	free(cd);//释放临时空间

}
