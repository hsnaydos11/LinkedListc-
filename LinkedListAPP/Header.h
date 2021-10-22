#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <iomanip>

#define MAX_LEVEL 6
const float P = 0.5;
#define CRT_SECURE_NO_WARNINGS

class Node  //Created linked list node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node* xnode;
    Node* npx;
};

using namespace std;
using namespace std::chrono;
//*********SINGLE LINKED LIST**********
void InsertSingle(Node** head_ref, int data);
void InsertSingleEnd(Node* prev_node, int new_data);
void InsertSingleSpecific(Node** head_ref, int new_data);


void Singlepush(Node** head_ref, int new_data);
void SingleDelete(Node** head_ref, int position);
void SinglePrintList(Node* node);
int SingleLength(Node* head);

bool SingleSearch(Node* head, int x);
void SingleList(Node* n);

void SingleMemory();
void SingleINSERT();
void SingleDELETE();
void SingleLIST();
void SingleSEARCH();
void SingleLENGTH();

//*********CIRCULAR LINKED LIST*********
struct Node* InsertCircularBegin(struct Node* last, int data);
struct Node* InsertCircularEnd(struct Node* last, int data);
struct Node* InsertCircularAfter(struct Node* last, int data, int item);

void CircularPrint(Node* node);
void DeleteCircular(Node** head, int key);
void CircularPush(Node** head_ref, int data);

bool CircularSearch(Node* head, int x);
int CircularLength(Node* head);
void CircularList(Node* n);
void CircularMemory();

void InsertCIRCULAR();
void DeleteCIRCULAR();
void ListCIRCULAR();
void SearchCIRCULAR();
void LengthCIRCULAR();
//************DOUBLE LINKED LIST********
void InsertDoubleBegin(Node** head_ref, int new_data);
void InsertDoubleAfter(Node* prev_node, int new_data);
void InsertDoubleEnd(Node** head_ref, int new_data);
void DoublePrint(Node* node);
void DeleteDouble(Node** head_ref, Node* del);


void InsertDOUBLE();
void DeleteDOUBLE();
void DoubleLENGTH();
void DoubleMemory();
void DoubleSEARCH();
void DoubleLIST();

//*********XOR LINKED LIST********
Node* Xor(Node* x, Node* y);
void XORPush(Node** head_ref, int new_data);
void XORPush1(Node** head_ref, int new_data);
void InsertXOR(Node** head_ref, int data);
void XORPrint(Node* head);
void DeleteXOR(Node** head_ref, int key);

void XORLength(struct Node* node);
bool XORSearch(Node* head, int x);
void XORList(struct Node* node);

void INSERTXOR();
void XORLENGTH();
void XORLIST();
void DELETEXOR();
void XORMemory();
void XORSEARCH();
//********SKIP LINKED LIST********
struct snode;
struct skiplist;
float frand();
int random_level();
void InsertSkip(int& value);
void DeleteSkip(int& value);
void SkipList();
bool SkipSearch(int& s_value);
int SkipLength(Node* head);

void SkipMemory();
void InsertSKIP();
void DeleteSKIP();
void SkipSEARCH();
void ListSKIP();
void SkipLENGHT();
