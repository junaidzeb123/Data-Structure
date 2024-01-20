/*
	Name: junaid Zeb
	Section: B
	Roll Number: 22i-8794
*/

#pragma once
#include<iostream>
using namespace std;

template<class t>
class Node {
public:
	t data;
	Node<t>* next;
	Node(t d) {
		next = nullptr;
		data = d;
	}
};
template<class t>
class Stack {
public:
	Node<t>* top;
	int size;
	Stack() {
		top = nullptr;
		size = 0;
	}
	void push(t d) {
		Node<t>* nNode = new Node<t>(d);
		nNode->next = top;
		top = nNode;
		size++;
	}
	t pop() {
		if (size == 0) {
			return -1;
		}
		t v = top->data;
		Node<t>* temp = top->next;
		delete top;
		top = temp;
		size--;
		return v;
	}
	t peek() {
		if (top)
			return top->data;
		return -1;
	}
	bool isEmpty() {
		return size == 0;
	}
	void clear() {
		while (!isEmpty()) {
			this->pop();
		}
	}
	~Stack() {
		while (!isEmpty()) {
			this->pop();
		}
	}
};
bool isAscending(string number) {
	for (int i = 0; i < number.length() - 1; i++) {
		if (number[i] > number[i + 1])
			return false;
	}
	return 1;
}
bool isDecending(string number) {
	for (int i = 0; i < number.length() - 1; i++) {
		if (number[i] < number[i + 1])
			return false;
	}
	return 1;
}
/*
	Time Complexity: O(n+k)
*/
string largestString(string str, int k){
	Stack<char> charStack;
	int j = 0;
	if (k == str.length())
		return "";
	for (int i = 0;i < str.length() ; i++) {
		if (charStack.isEmpty())
			charStack.push(str[i]);
		else {
			if (!charStack.isEmpty() &&(charStack.peek() < str[i]) && k > 0) {
				charStack.pop();				
				k--;
				i--;
				continue;
			}
			charStack.push(str[i]);
		}	
		
	}
	string ans = "";
	int s = charStack.size;
	if (isDecending(str)) {
		s = str.length() - k;
		k = 0;
		for (int i = 0; i < s; i++)
			ans = ans + str[i];
		return ans;
	}
	while (k > 0) {
		charStack.pop();
		k--;
		s--;
	}
	for (int i = 0; i < s-k; i++)
		ans = charStack.pop() + ans;
	cout << ans << endl;
	return ans;
}

/*
	Time Complexity: O(n+k)
*/
string solve(string number, int k) {

	Stack<char> charStack;
	int k2 = k;
	string ans = "";
	char first;
	for (int i = 0; i < number.length(); i++) {
		if (charStack.isEmpty() && number[i] != '0') {
			charStack.push(number[i]);
			first = number[i];
		}
		else {

			if (!charStack.isEmpty() && (charStack.peek() > number[i]) && k > 0 && (number[i] != '0' || charStack.size > 1)) {
				charStack.pop();
				k--;
				i--;
				continue;
			}
			if (number[i] != '0' || charStack.size != 0) {
				if (first > number[i] && k >= charStack.size && number[i] != '0') {
					int s = charStack.size;
					while (!charStack.isEmpty()) {
						charStack.pop();
						k--;
					}
				}
				charStack.push(number[i]);

			}
			else
				k--;
		}

	}
	int s = charStack.size;
	if (k < 0)
		k = 0;

	if (isAscending(number)) {
		s = number.length() - k;
		k = 0;
		for (int i = 0; i < s; i++)
			ans = ans + number[i];
		while (ans[0] == '0') {
			ans = ans.substr(1, ans.length() - 1);
		}
		cout << ans << endl;
		return ans;
	}
	if (k > 0 && charStack.size > number.length() - k2) {
		while (k > 0 && charStack.size > number.length() - k2) {
			charStack.pop();
			k--;

		}
	}
	s = charStack.size;
	for (int i = 0; i < s - k; i++)
		ans = charStack.pop() + ans;
	cout << ans << endl;
	while (ans[0] == '0') {
		ans = ans.substr(1, ans.length() - 1);
	}
	return ans;

}

/*
	Time Complexity: O(n+k)
*/
template<typename T>
class Queue {
public:
	Node<T>* front;
	Node<T>* rear;
	int size;
	Queue() {
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	bool is_empty() {
		return size == 0;
	}
	int sizes() {
		return size;
	}
	void enqueue(T d) {
		Node<T>* nNode = new Node<T>(d);
		if (is_empty()) {
			front = nNode;
			rear = nNode;
			size++;
			return;
		}
		rear->next = nNode;
		rear = nNode;
		size++;
	}
	T dequeue() {
		
		if (!is_empty()) {
			T v = front->data;
			Node<T>* temp = front->next;
			delete front;
			size--;
			front = temp;
			return v;
		}
		return -2;

	}

	T peek() {
		if(!is_empty())
		return front->data;
		return -1;
	}
	void clear() {
		while (!is_empty()) {
			dequeue();
		}

	}
	


};
int* maxSubsequence(int nums[], int size, int k) {
	Queue<int> myQueue;
	Queue<int> sums;
	int sum = 0;
	int n = 0;
	if (size == k)
		return nums;
	for (int i = 0; i < k; i++) {
		myQueue.enqueue(nums[i]);
		sum += nums[i];
	}
	sums.enqueue(sum);	
	for (int i = k; i < size; i++) {
		sum -= myQueue.dequeue();
		myQueue.enqueue(nums[i]);
		sum += nums[i];
		sums.enqueue(sum);		
	}
	int maxSum = sums.dequeue();
	int s = sums.sizes();
	int start = 0;
	int i = 0;
	while(!sums.is_empty()){
		if (maxSum < sums.peek()) {
			maxSum = sums.dequeue();
			start = start + i + 1;
			i = 0;
		}
		else {
			sums.dequeue();
			i++;
		}
	}
	int* result = new int[k];
	 i = 0;
	for (int j = start; j-start < k; j++) {		
		result[i++] = nums[j];
	}
	return result;
}



