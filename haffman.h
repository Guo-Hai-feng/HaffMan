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



// ������������ڵ�ṹ
typedef struct Node {
    char data;             // �ڵ�洢���ַ�����
    int frequency;         // �ڵ��Ƶ��
    struct Node* left, * right; // ��������������
} Node;

// ����һ���µĽڵ�
Node* newNode(char data, int frequency);
void freeQueue(Node* queue);
// ������������
Node* buildHuffmanTree(char data[], int frequency[], int size);
// ��ӡ���������ı���
void printHuffmanCodes(Node* root, int arr[], int top);
