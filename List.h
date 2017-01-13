#include "Exception.h"
#ifndef LIST_H
#define LIST_H

template<typename T>
class Node;

template<typename T>
class List
{
public:
	List();
	List(const List & copy);
	~List();
	List & operator =(const List & rhs);
	bool isEmpty();
	const T & First();
	const T & Last();
	void Prepend(T data);
	void Append(T data);
	void Purge();
	void Extract(T data);
	void InsertAfter(T lookfordata, T nndata);
	void InsertBefore(T lookfordata, T nndata);
	Node<T> * getHead() const;
	Node<T> * getTail() const;
	void PrintForwards();
	void PrintBackwards();

private:
	Node<T> * m_Head;
	Node<T> * m_Tail;
};


template<typename T>
inline List<T>::List() : m_Head(nullptr), m_Tail(nullptr)
{
}

template<typename T>
inline List<T>::~List()
{
	Purge();
}

template<typename T>
inline List<T> & List<T>::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		m_Head = rhs.m_Head;
		m_Tail = rhs.m_Tail;
	}

	return *this;
}

template<typename T>
inline bool List<T>::isEmpty()
{
	bool empty = true; 
	if (m_Head != nullptr)
	{
		empty = false; //if not empty return false
	}
	return empty;
}

template<typename T>
inline const T & List<T>::First()
{
	if (!isEmpty())
		return m_Head->m_Data;
	else
		throw Exception("No Data in First list is empty");
		
}

template<typename T>
inline const T & List<T>::Last()
{
	if (!isEmpty())
		return m_Tail->m_Data;
	else
		throw Exception("No Data in Last list is empty");
}

template<typename T>
inline void List<T>::Prepend(T data)
{
	Node<T> * NN = new Node<T>(data);

	if (!isEmpty())
	{
		NN->m_Previous = nullptr;
		NN->m_Next = m_Head;
		m_Head->m_Previous = NN;
		m_Head = NN;
	}
	else
	{
		m_Head = NN;
		m_Tail = m_Head;
	}

}

template<typename T>
inline void List<T>::Append(T data)
{
	Node<T> * NN = new Node<T>(data);

	if (!isEmpty())
	{
		NN->m_Next = nullptr;
		NN->m_Previous = m_Tail;
		m_Tail->m_Next = NN;
		m_Tail = NN;
	}
	else
	{
		m_Head = NN;
		m_Tail = m_Head;
	}

	
}

template<typename T>
inline void List<T>::Purge()
{
	Node<T> * travel = new Node<T>;
	travel = m_Head;
	while (travel)
	{
		m_Head = m_Head->m_Next;
		delete travel;
		travel = m_Head;
	}
}

template<typename T>
inline void List<T>::Extract(T data)
{
	if (!isEmpty())
	{
		Node<T> * travel=m_Head;
		while (travel != nullptr && travel->m_Data != data)
		{
			travel = travel->m_Next;
		}
		if (travel != nullptr)
		{
			if(travel->m_Data==m_Head->m_Data)
			{
				travel->m_Next->m_Previous = nullptr;
				m_Head = travel->m_Next;
			}
			else if(travel->m_Data==m_Tail->m_Data)
			{
				travel->m_Previous->m_Next = nullptr;
				m_Tail = travel->m_Previous;
			}
			else
			{
				travel->m_Next->m_Previous = travel->m_Previous;
				travel->m_Previous->m_Next = travel->m_Next;
			}

		}
		else
		{
			throw Exception("The data you were looking for wasn't in the list");
		}

	}
	else
	{
		throw Exception("The List was empty");
	}
}

template<typename T>
inline void List<T>::InsertAfter(T lookfordata, T nndata)
{
	Node<T> * NN = new Node<T>(nndata);
	Node<T> * temp = new Node<T>(lookfordata);
	Node<T> * travel = m_Head;
	if (travel != nullptr)
	{
		while (travel != nullptr && temp->m_Data !=travel->m_Data)
		{
			travel = travel->m_Next;
		}
		if(travel!=nullptr)
		{ 
			if(temp->m_Data==m_Head->m_Data)
			{
				m_Head->m_Next->m_Previous = NN;
				NN->m_Next = m_Head->m_Next;
				NN->m_Previous = m_Head;
				m_Head->m_Next = NN;
			}
			else if(temp->m_Data==m_Tail->m_Data)
			{
				m_Tail->m_Next = NN;
				NN->m_Previous = m_Tail;
				NN->m_Next = nullptr;
				m_Tail = NN;
			}
			else
			{
				travel->m_Next->m_Previous = NN;
				NN->m_Next = travel->m_Next;
				travel->m_Next = NN;
				NN->m_Previous = travel;
			}
		}
		else
		{
			throw Exception("Can't insertafter because data you were looking for wasn't in List");
		}
	}
	else
	{
		throw Exception("List is empty can insert After anything in Empty List");
	}
	delete temp;
}

template<typename T>
inline void List<T>::InsertBefore(T lookfordata, T nndata)
{
	Node<T> * NN = new Node<T>(nndata);
	Node<T> * temp = new Node<T>(lookfordata);
	Node<T> * travel = m_Head;
	if (travel !=nullptr)
	{
		while (travel != nullptr && temp->m_Data != travel->m_Data)
		{
			travel = travel->m_Next;
		}
		if (travel != nullptr)
		{
			if (temp->m_Data == m_Head->m_Data)
			{
				NN->m_Previous = nullptr;
				NN->m_Next = m_Head;
				m_Head->m_Previous = NN;
				m_Head = NN;
			}
			else if(temp->m_Data==m_Tail->m_Data)
			{
				m_Tail->m_Previous->m_Next = NN;
				NN->m_Previous = m_Tail->m_Previous;
				m_Tail->m_Previous = NN;
				NN->m_Next = m_Tail;
			}
			else
			{
				temp->m_Previous->m_Next = NN;
				NN->m_Previous = temp->m_Previous;
				NN->m_Next = temp;
				temp->m_Previous = NN;
			}
		}
		else
		{
			throw Exception("The data you were looking for wasn't in the list!");
		}
	}
	else
	{
		throw Exception("Your list is Empty!");
	}
	delete temp;
}

template<typename T>
inline Node<T> * List<T>::getHead() const
{
	return m_Head;
}

template<typename T>
inline Node<T> * List<T>::getTail() const
{
	return m_Tail;
}

template<typename T>
inline void List<T>::PrintForwards()
{
	Node<T> * travel = m_Head;
	while(travel!=nullptr)
	{
		cout << travel->m_Data<<' ';
		travel = travel->m_Next;
	}
}

template<typename T>
inline void List<T>::PrintBackwards()
{
	Node<T> * travel = travel = m_Tail;
	while (travel != nullptr)
	{
		cout << travel->m_Data<<' ';
		travel = travel->m_Previous;
	}
	delete travel;
}

#endif LIST_H