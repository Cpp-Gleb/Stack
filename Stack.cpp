#include <iostream>

using namespace std;


template <typename T>
class Node {
public:

	Node(T value, Node* next)
	{
		Value = value;
		Next = next;
	}


	Node* Next;
	T Value;

};


template <typename T>
class stack {
private:
	Node<T>* _last;
	int _size;
public:
	
	stack() {
		_last = nullptr;
		_size = 0;
	}
	stack(stack& right) = delete;
	stack(stack&& right) = delete;

	stack& operator=(stack& right) = delete;

	~stack() {
		Clear();
	}


	int Size()
	{
		return _size;
	}

	void push(T Value){

		Node<T>* newNode = new Node<T>(Value, _last);
		_last = newNode;
		_size++;
	}

	void pop(){
		if (_size == 0)
			return;
		Node<T>* preLast = _last->Next;
		delete _last;
		_last = preLast;
		_size--;
		
	}

	void Clear()
	{
		Node<T>* next = _last->Next;
		while (next)
		{
			delete _last;
			_last = next;
		}
	}

	T operator[](int index) const
	{
		index = _size - index;
		Node<T>* currentNode = _last;
		for (int i = 0; i < index; i++)
			currentNode = currentNode->Next;
		return currentNode->Value;
	}

	T top(){
		return _last->Value;
	}
};

int main() {
	stack<int> a;
	int input;
	while (cin >> input)
	{
		a.push(input);
	}
	for (int i = 0; i < a.Size(); i++)
	{
		cout << a.top();
		cout << endl;
		a.pop();
	}
}
