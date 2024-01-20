#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"Header.h"
#include<cmath>
/*	question # 02*/

class Transport_Cost_Calculator {
public:
	Node* MetroHead;
	Node* BusHead;
	Node* WalkHead;
	int totalLocations;
	int UpDownCost;
	Transport_Cost_Calculator();
	void HelperForReadFile(Node* Head, int* stations, int size);
	void HelperForUpandDown(Node* up, Node* down);
	void ReadFile(string fileName);
	int GetMinCost(int start, int end);
	int manhattanDistance(int currnet , int destination) {
		return abs(destination - currnet);
	}
	int RecursizeHelper(Node* current, int end,bool upCheck, bool downCheck,int layer,int**&dpArray);
};
Transport_Cost_Calculator::Transport_Cost_Calculator() {
	MetroHead = nullptr;
	BusHead = nullptr;
	WalkHead = nullptr;
	UpDownCost = 5;
}
void Transport_Cost_Calculator::HelperForReadFile(Node* Head, int* stations, int size) {
	Node* temp = Head;
	temp->location = stations[0];
	for (int i = 1; i < size; i++) {
		temp->next = new Node;
		temp->next->location = stations[i];
		temp->next->prev = temp;
		temp = temp->next;
	}
}
void Transport_Cost_Calculator::HelperForUpandDown(Node* up, Node* down) {
	while (up && down) {
		while (down->location <= up->location) {
			if (down->location == up->location) {
				up->down = down;
				down->up = up;
			}
			else {
				up->down = nullptr;
				down->up = nullptr;
			}
			down = down->next;
			if (!down)
				break;

		}
		up = up->next;

	}
}
void Transport_Cost_Calculator::ReadFile(string fileName) {

	ifstream fin;
	fin.open(fileName);
	int n;
	fin >> n;
	totalLocations = n;
	int* Station = new int[n];	
	for (int i = 0; i < n; i++) {
		Station[i] = i+1;
	}	
	MetroHead = new Node;
	Node* temp = MetroHead;
	BusHead = new Node;
	HelperForReadFile(temp, Station, n);
	temp = BusHead;
	HelperForReadFile(temp, Station, n);
	WalkHead = new Node;
	temp = WalkHead;
	HelperForReadFile(temp, Station, n);

	for (int i = 0; i < 3; i++) {
		if (i == 0)
			temp = MetroHead;
		else if (i == 1)
			temp = BusHead;
		else
			temp = WalkHead;
		for (int j = 0; j < n-1; j++) {
			fin >> temp->actualCost;
			temp = temp->next;
		}
	}
	/*code to link up down*/
	temp = MetroHead;
	HelperForUpandDown(MetroHead, BusHead);
	HelperForUpandDown(BusHead, WalkHead);
	//print();
	fin.close();
}
int Transport_Cost_Calculator::RecursizeHelper(Node* current, int end,bool upCheck, bool downCheck,int layer,int**& dpArray) {
	
	int cost1 = -1;
	int cost2 = -1;
	int cost3 = -1;
	
	if (current->next) {
		if (current->next->location == end) {
			cost1 = current->actualCost;
			int c2;
			if (current->up) {
				c2 = current->up->actualCost + UpDownCost;
				if (cost1 > c2) {
					cost1 = c2;
				}
			}
			if (current->down) {
				c2 = current->down->actualCost + UpDownCost;
				if (cost1 > c2) {
					cost1 = c2;
				}
			}

		}
	}
	if (current->next) {
		if (current->next->location < end) {
			if (dpArray[layer - 1][current->next->location - 1] != -1) {
				cost1 = current->actualCost + dpArray[layer - 1][current->next->location - 1];
			}
			else {
				dpArray[layer - 1][current->next->location - 1] = RecursizeHelper(current->next, end, 1, 1, layer, dpArray);
				cost1 = current->actualCost + dpArray[layer - 1][current->next->location - 1];
			}
		}
	}
	if (current->down && downCheck) {
		if (dpArray[layer][current->down->location - 1] != -1) {
			cost2 = UpDownCost + dpArray[layer][current->down->location - 1];
		}
		else {
			dpArray[layer][current->down->location - 1] = RecursizeHelper(current->down, end, 0, 1, layer + 1, dpArray);
			cost2 = UpDownCost + dpArray[layer][current->down->location - 1];
		}
	}
	if (current->up && upCheck) {
		if (dpArray[layer-2][current->up->location - 1] != -1){
			cost3 = UpDownCost + dpArray[layer-2][current->up->location - 1];
		}
		else {
			dpArray[layer - 2][current->up->location - 1] = RecursizeHelper(current->up, end, 1, 0, layer - 1, dpArray);
			cost3 = UpDownCost+ dpArray[layer - 2][current->up->location - 1];
		}
	}
	int minCost = cost1;
	if ((minCost > cost2 || minCost == -1) && cost2 != -1)
		minCost = cost2;
	if ((minCost > cost3 || minCost == -1) && cost3 != -1)
		minCost = cost3;
	return minCost;

}
int Transport_Cost_Calculator::GetMinCost(int start, int end) {
	Node* currentLocation = MetroHead;
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	
	}
	while (currentLocation->next) {
		if (currentLocation->location == start)
		break;
		currentLocation = currentLocation->next;
	}
	int layer = 1;
	int** dpArray = new int* [3];
	for (int i = 0; i < 3; i++) {
		dpArray[i] = new int[totalLocations];
		for (int j = 0; j < totalLocations; j++) {
			dpArray[i][j] = -1;
		}
	}

	int cost1 = RecursizeHelper(currentLocation, end, 1, 1, layer, dpArray);
	currentLocation = currentLocation->down;
	layer++;
	int cost2 =  RecursizeHelper(currentLocation, end, 1, 1, layer, dpArray);
	currentLocation = currentLocation->down;
	layer++;
	int cost3 = RecursizeHelper(currentLocation, end,1,1,layer,dpArray);
	/*cout << "\n\n\\n\n\t\tHere is the dp\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < end; j++)
			cout << j + 1 << "-" << i + 1 << " " << dpArray[i][j] << "\n";
		cout << endl << endl;;
	}*/
	int minCost = cost1;
	if (minCost > cost2)
		minCost = cost2;
	if (minCost > cost3)
		minCost = cost3;
	cout << cost1 << " " << cost2<<" " << cost3<<" "<<minCost << endl;
	
	return minCost;
}
