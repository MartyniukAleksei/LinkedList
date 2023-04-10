#include <iostream>
using namespace std;


template<class T>
class LinkedList
{
private:
	class Node 
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) 
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;

public:
	LinkedList();
	~LinkedList();

	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void inseart(T data, int index);
	void remove_at(int index);
	void clear();
	const int get_size() { return size; }
	bool empty() { return get_size() == 0; }

	Node* begin() { return head; };
	Node* end() 
	{
		Node* current = head;
		for (int i = 0; i < get_size() - 1; i++)
			current = current->pNext;

		return current;
	};

	T& operator[](const int index);
	LinkedList<T>& operator=(LinkedList<T>& object);
};


template<class T>
LinkedList<T>::LinkedList()
{
	this->size = 0;
	this->head = nullptr;
}


template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
}


template<class T>
void LinkedList<T>::push_back(T data)
{
	if(this->head == nullptr)
	{
		this->head = new Node(data);
	}
	else 
	{
		Node* current = this->head;

		while (current->pNext != nullptr) 
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	++size;
}


template<class T>
void LinkedList<T>::push_front(T data)
{
	head = new Node(data, head);
	size++;
}


template<class T>
void LinkedList<T>::pop_back()
{
	remove_at(this->get_size() - 1);
}


template<class T>
void LinkedList<T>::pop_front()
{
	Node* front = head;

	head = head->pNext;
	delete front;

	size--;
}


template<class T>
void LinkedList<T>::inseart(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		
		Node* NewItem = new Node(data, previous->pNext);
		previous->pNext = NewItem;

		size++;
	}
}


template<class T>
void LinkedList<T>::remove_at(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;
		delete toDelete;
		
		size--;
	}
}


template<class T>
void LinkedList<T>::clear()
{
	while (size)
		pop_front();
}


template<class T>
T& LinkedList<T>::operator[](const int index)
{
	int count = 0;
	Node* current = this->head;

	while (current != nullptr) 
	{
		if (count == index)
			return current->data;
		
		count++;
		current = current->pNext;
	}
}


template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& object) 
{
	this->clear();
	for (int i = 0; i < object.get_size(); i++)
		this->push_back(object[i]);
	return *this;
}


int main()
{
	LinkedList<int> lst;
	lst.push_back(5);
	lst.push_front(11);
	
	cout << "Cin value and index" << endl;
	int value, index;
	cin >> value >> index;
	lst.inseart(value, index);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}
	
	system("Pause");
	return 0;
}
