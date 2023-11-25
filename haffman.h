#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include<string.h>
#define ERROR 0
typedef int HaType;
typedef struct
{
    int weight;
    int parent, lch, rch;
}HTNode, * HuffmanTree;


typedef char* HuffmanCode;



void select(HuffmanTree HT, int n, int* s1, int* s2);

int InitHuffmanTree(HuffmanTree HT, int n);



// 定义哈夫曼树节点结构
typedef struct Node {
    char data;             // 节点存储的字符数据
    int frequency;         // 节点的频率
    struct Node* left, * right; // 左子树和右子树
} Node;

// 创建一个新的节点
Node* newNode(char data, int frequency);
void freeQueue(Node* queue);
// 构建哈夫曼树
Node* buildHuffmanTree(char data[], int frequency[], int size);
// 打印哈夫曼树的编码
void printHuffmanCodes(Node* root, int arr[], int top);
