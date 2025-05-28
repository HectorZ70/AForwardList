#include "ForwardList.h"

ForwardList::ForwardList()
{

}

ForwardList::~ForwardList()
{

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
	if (m_first == nullptr) 
	{
		return;
	}

	Node* temp = m_first;
	m_first = m_first->m_next; 
	delete temp;

	--m_size;

	if (m_first == nullptr)
	{
		m_last = nullptr;
	}
}

bool ForwardList::IsEmpty() const
{

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

}

void ForwardList::Insert(int value, int position)
{

}

void ForwardList::PushBackAverageNode()
{

}

bool operator==(const ForwardList& l1, const ForwardList& l2)
{

}

ForwardList operator+(const ForwardList& l1)
{

}

std::ostream& operator<<(std::ostream& o, const ForwardList& l)
{

}

