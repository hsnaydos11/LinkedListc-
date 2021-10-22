// LinkedListConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\LinkedListAPP\Header.h"

int main()
{
	int choice, choice1, choice2, choice3, choice4, choice5;
	int x = 1;
	while (1) {
		printf("\n\n*****MAINMENU*****\n1. Single Linked List\n2. Circular Linked List\n3. Double Linked List\n4. XOR Linked List\n5. Skip Linked List\n\n****************\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("\n\n*****SUBMENU*****\n1. Insert\n2. Delete\n3. List\n4. Search\n5. Length\n6. Allocate Memory\n");
			scanf_s("%d", &choice1);
			switch (choice1) {
			case 1:
				SingleINSERT();
				return choice1;
				break;
			case 2:
				SingleDELETE();
				return choice1;
				break;
			case 3:
				SingleLIST();
				return choice1;
				break;
			case 4:
				SingleSEARCH();
				return choice1;
				break;
			case 5:
				SingleLENGTH();
				return choice1;
				break;
			case 6:
				SingleMemory();
				return choice1;
				break;
			}
			break;
		case 2:
			printf("\n\n*****SUBMENU*****\n1. Insert\n2. Delete\n3. List\n4. Search\n5. Length\n6. Allocate Memory\n");
			scanf_s("%d", &choice2);
			switch (choice2) {
			case 1:
				InsertCIRCULAR();
				return choice2;
				break;
			case 2:
				DeleteCIRCULAR();
				return choice2;
				break;
			case 3:
				ListCIRCULAR();
				return choice2;
				break;
			case 4:
				SearchCIRCULAR();
				return choice2;
				break;
			case 5:
				LengthCIRCULAR();
				return choice2;
				break;
			case 6:
				CircularMemory();
				return choice2;
				break;
			}
			break;
		case 3:
			printf("\n\n*****SUBMENU*****\n1. Insert\n2. Delete\n3. List\n4. Search\n5. Length\n6. Allocate Memory\n");
			scanf_s("%d", &choice3);
			switch (choice3) {
			case 1:
				InsertDOUBLE();
				return choice3;
				break;
			case 2:
				DeleteDOUBLE();
				return choice3;
				break;
			case 3:
				DoubleLIST();
				return choice3;
				break;
			case 4:
				DoubleSEARCH();
				return choice3;
				break;
			case 5:
				DoubleLENGTH();
				return choice3;
				break;
			case 6:
				DoubleMemory();
				return choice3;
				break;
			}
			break;
		case 4:
			printf("\n\n*****SUBMENU*****\n1. Insert\n2. Delete\n3. List\n4. Search\n5. Length\n6. Allocate Memory\n********\n");
			scanf_s("%d",&choice4);
			switch (choice4) {
			case 1:
				INSERTXOR();
				return choice4;
				break;
			case 2:
				DELETEXOR(); 
				return choice4;
				break;
			case 3:
				XORLIST();
				return choice4;
				break;
			case 4:
				XORSEARCH();
				break;
			case 5:
				XORLENGTH();
				return choice4;
				break;
			case 6:
				XORMemory();
				return choice4;
				break;
			}
			break;
		case 5:
			printf("\n\n*****SUBMENU*****\n1. Insert\n2. Delete\n3. List\n4. Search\n5. Length\n6. Allocate Memory\n********\n");
			scanf_s("%d", &choice5);
			switch (choice5) {
			case 1:
				InsertSKIP();
				return choice5;
				break;
			case 2:
				DeleteSKIP();
				return choice5;
				break;
			case 3:
				ListSKIP();
				return choice5;
				break;
			case 4:
				SkipSEARCH();
				return choice5;
				break;
			case 5:
				SkipLENGHT();
				return choice5;
				break;
			case 6:
				SkipMemory();
				break;
			}
			break;
		}
	}
}


