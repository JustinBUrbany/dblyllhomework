#ifndef NODE_H
#define NODE_H

template<typename T>
class List;

template<typename T>
class Node
{
	friend List<T>;
public:

	Node(const Node & copy);
	Node & operator =(const Node & rhs);
	~Node();
	//Node * getNext()const;
	//void setNext(Node * next);
	//void SetPrev(Node * Prev);
	//Node * getPrev()const;
	//T getData()const;
private:

	Node();
	Node(T Data);
	T	m_Data;
	Node * m_Next;
	Node * m_Previous;
};


#endif

template<typename T>
inline Node<T>::Node() :m_Next(nullptr), m_Previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(T Data) :m_Data(Data)
{
}

template<typename T>
inline Node<T>::Node(const Node & copy)
{
	*this = copy;
}

template<typename T>
inline Node<T> & Node<T>::operator=(const Node & rhs)
{
	if (this != &rhs)
	{
		m_Data = rhs.m_Data;
	}
	return *this;
}

template<typename T>
inline Node<T>::~Node()
{
}

//template<typename T>
//inline Node<T> * Node<T>::getNext() const
//{
//	return m_Next;
//}
//
//template<typename T>
//inline void Node<T>::setNext(Node * next)
//{
//	assert(next != nullptr);
//
//	m_Next = next;
//}

//template<typename T>
//inline void Node<T>::SetPrev(Node * Prev)
//{
//	assert(next != nullptr);
//
//	m_Previous = Prev;
//}
//
//template<typename T>
//inline Node<T> * Node<T>::getPrev() const
//{
//	return m_Previous;
//}


//
//template<typename T>
//inline T Node<T>::getData() const
//{
//	return m_Data;
//}
