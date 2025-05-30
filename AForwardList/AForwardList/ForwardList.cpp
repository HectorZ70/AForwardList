#include "ForwardList.h"

ForwardList::ForwardList() : m_first(nullptr), m_last(nullptr), m_size(0){}

ForwardList::~ForwardList()
{
	Node* current = m_first;
	while (current != nullptr) {
		Node* next = current->m_next;
		delete current;
		current = next;
	}
	m_first = m_last = nullptr;
	m_size = 0;
}

void ForwardList::PushBack(int value)
{
	Node* newNode = new Node(value, nullptr);
	if (m_first == nullptr)
		m_first = m_last = newNode;

	else 
	{
		m_last->m_next = newNode;
		m_last = newNode;
	}
	m_size++;
}

void ForwardList::PopBack()
{
	if (m_first == nullptr)
	{
		return;
	}

	if (m_first == m_last)
	{
		delete m_first;
		m_first = m_last = nullptr;
	}

	else 
	{
		Node* current = m_first;
		while (current->m_next != m_last)
		{
			current = current->m_next;
		}

		delete m_last;
		m_last = current;
		m_last->m_next = nullptr;
	}

	m_size--;
}

void ForwardList::PushFront(int value)
{
	Node* newNode = new Node(value, m_first);

	m_first = newNode;

	if (m_last == nullptr)
	{
		m_last = newNode;
	}
	
	m_size++;
}

void ForwardList::PopFront()
{
	if (IsEmpty())
	{
		return;
	}

	Node* temp = m_first;
	m_first = m_first->m_next; 
	delete temp;

	--m_size;

	if (IsEmpty())
	{
		m_last = nullptr;
	}
}

bool ForwardList::IsEmpty() const
{
	return m_first == nullptr;
}

int ForwardList::Front() const
{
	if (!IsEmpty())
		return m_first->m_value;
}

int ForwardList::Back() const
{
	if (!IsEmpty())
		return m_last->m_value;
}

int ForwardList::Size() const
{
	return m_size;
}

void ForwardList::Erase(int value)
{
	if (!IsEmpty())
	{
		Node* current = m_first;
		while (current != nullptr) 
		{
			Node* next = current->m_next;
			delete current;
			current = next;
		}

		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
	}
}

void ForwardList::Insert(int value, int position)
{
	if (position <= 0) {
		PushFront(value);
		return;
	}
	if (position >= m_size) {
		PushBack(value);
		return;
	}

	Node* current = m_first;
	for (int i = 0; i < position - 1; ++i) {
		current = current->m_next;
	}

	Node* newNode = new Node(value, current->m_next);
	current->m_next = newNode;
	m_size++;
}

void ForwardList::PushBackAverageNode()
{
	if (IsEmpty()) return;

	int sum = 0;
	Node* current = m_first;
	while (current != nullptr) {
		sum += current->m_value;
		current = current->m_next;
	}
	int average = sum / m_size;
	PushBack(average);
}

bool operator==(const ForwardList& l1, const ForwardList& l2)
{
	ForwardList::Node* nodeA = l1.m_first;
	ForwardList::Node* nodeB = l2.m_first;

	while (nodeA != nullptr && nodeB != nullptr) {
		if (nodeA->m_value != nodeB->m_value) {
			return false;
		}
		nodeA = nodeA->m_next;
		nodeB = nodeB->m_next;
	}

	return nodeA == nullptr && nodeB == nullptr;
}

ForwardList operator+(const ForwardList& l)
{
	ForwardList result;
	ForwardList::Node* current = l.m_first;
	while (current != nullptr)
	{
		result.PushBack(current->m_value);
		current = current->m_next;
	}
	return result;
}

std::ostream& operator<<(std::ostream& o, const ForwardList& l)
{
	ForwardList::Node* current = l.m_first;
	o << "[";
	while(current != nullptr)
	{
		o << current->m_value;
		if(current->m_next != nullptr)
		{
			o << " -> ";
		}
		current = current->m_next;
	}
	o << "]";
	return o;
}

