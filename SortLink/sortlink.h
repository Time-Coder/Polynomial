// Copyright(c): 2017 Bing-Hui WANG
//
// Author: Bing-Hui WANG
//
// Date: 2017-10-3
//
// Description: This code has build a sorted link list class named "SortLink"
//
// See usage in "./README.md"
// See examples in "./example/"

#ifndef SORTLINK_H
#define SORTLINK_H

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <stdio.h>

using namespace std;

// Define SortLink's node "LinkNode".
template<typename DataType>
class LinkNode
{
public:
	DataType  data;
	LinkNode<DataType>* link = NULL;

public:
	LinkNode<DataType>();
};

// Define SortLink's iterator(read only).
template<typename DataType>
class SortLinkIterator : public iterator< input_iterator_tag, LinkNode<DataType> >
{
public:
    LinkNode<DataType>* _ptr = NULL;

public:
	SortLinkIterator();
    SortLinkIterator(LinkNode<DataType>* p);
    SortLinkIterator& operator =(const SortLinkIterator& iter);
    bool operator !=(const SortLinkIterator& iter)const;
    bool operator ==(const SortLinkIterator& iter)const;
    SortLinkIterator& operator ++();
    SortLinkIterator operator ++(int);
    DataType operator *()const;
    bool empty()const;
};

// Define Sorted Link List class "SortLink"
template<typename DataType>
class SortLink
{
	friend ostream & operator <<(ostream &o, const SortLink<DataType>& X)
	{
		o << endl << endl;

		for(const_iterator it = X.begin(); it != X.end(); it++)
		{
			o << *it << endl;
		}

		return o;
	}

private:
	LinkNode<DataType>* head;
	
public:
	// Define it's read only iterator.
	typedef SortLinkIterator<DataType> const_iterator;

	// SortLink's constructor without initial value.
	SortLink<DataType>();

	// SortLink's copy constructor
	SortLink<DataType>(const SortLink<DataType>& X);

	// SortLink's destructor
	~SortLink<DataType>();

	// Reload SortLiks's operator "=".
	// Make it possible to clone a SortLink to anther by just use "=".
	SortLink<DataType>& operator =(const SortLink<DataType>& X);

	// To judge if 2 SortLink is equal or not.
	bool operator ==(const SortLink<DataType>& X)const;
	bool operator !=(const SortLink<DataType>& X)const;

	// Clear the memory of SortLink
	void clear();

	// Return the const_iterator that points to SortLiks begin element.
	const_iterator begin()const;

	// Return the const_iterator that points to SortLinks end element's next position(NULL).
	// Be aware the difference between the begin() and end().
	const_iterator end()const;

	// Insert an element to correct position of SortLink
	// This movement didn't destroy the order structrue of SortLink.
	void insert(const DataType& x);

	// Erase the element in SortLink at position that const_iterator point to.
	void erase(const const_iterator& it);

	// Erase the i-position(count from 0) element in SortLink.
	void erase(const int& i);

	// Return the number of elements in current SortLink.
	int  length()const;

	// To judge if current SortLink is empty or not.
	bool empty()const;

	// To find out if the passed in element is in the SortLink.
	// If yes, return it's location in type "const_iterator".
	const_iterator find(const DataType& x)const;

	// Return position i's iterator.
	const_iterator locate(const int& i)const;

	// Return iterator's position index in type "int".
	int locate(const const_iterator& it)const;

	// Merge 2 SortLink into one.
	SortLink<DataType> merge(const SortLink<DataType>& X);
};

//--------------------------------- Implementation ------------------------------------------

template<typename DataType>
LinkNode<DataType>::LinkNode()
{
	link = NULL;
}

template<typename DataType>
SortLink<DataType>::SortLink()
{
	head = new LinkNode<DataType>;
}

template<typename DataType>
SortLink<DataType>::SortLink(const SortLink<DataType>& X)
{
	head = new LinkNode<DataType>;
	
	LinkNode<DataType>* p = X.head;
	while(p->link != NULL)
	{
		DataType value = (p->link)->data;
		insert(value);
		p = p->link;
	}
}

template<typename DataType>
SortLink<DataType>::~SortLink<DataType>()
{
	LinkNode<DataType>* p;
	while( head->link != NULL )
	{
		p = head->link;
		head->link = p->link;
		delete p;
	}
}

template<typename DataType>
SortLink<DataType>& SortLink<DataType>::operator =(const SortLink<DataType>& X)
{
	clear();
	LinkNode<DataType>* p = X.head;
	while(p->link != NULL)
	{
		DataType value = (p->link)->data;
		insert(value);
		p = p->link;
	}
	return (*this);
}

template<typename DataType>
bool SortLink<DataType>::operator ==(const SortLink<DataType>& X)const
{
	if(length() != X.length())
	{
		return false;
	}

	const_iterator it2 = X.begin();
	for(const_iterator it1 = begin(); it1 != end(); it1++)
	{
		if(*it1 != *it2)
		{
			return false;
		}
		it2++;
	}

	return true;
}

template<typename DataType>
bool SortLink<DataType>::operator !=(const SortLink<DataType>& X)const
{
	return !(*this == X);
}

template<typename DataType>
void SortLink<DataType>::clear()
{
	LinkNode<DataType>* p;
	while( head->link != NULL )
	{
		p = head->link;
		head->link = p->link;
		delete p;
	}
}

template<typename DataType>
typename SortLink<DataType>::const_iterator SortLink<DataType>::begin()const
{
	return const_iterator(head->link);
}

template<typename DataType>
typename SortLink<DataType>::const_iterator SortLink<DataType>::end()const
{
	return const_iterator();
}

template<typename DataType>
void SortLink<DataType>::insert(const DataType& x)
{
	LinkNode<DataType>* newNode = new LinkNode<DataType>;
	newNode->data = x;
	LinkNode<DataType>* p;
	p = head;
	while( p->link != NULL && (p->link)->data > x )
	{
		p = p->link;
	}
	newNode->link = p->link;
	p->link = newNode;
}

template<typename DataType>
void SortLink<DataType>::erase(const int& i)
{
	int n = length();
	if( i < 0 || i >= n )
	{
		return;
	}
	LinkNode<DataType>* p = head;
	for(int index = 0; index < i; index++)
	{
		p = p->link;
	}
	LinkNode<DataType>* q = p->link;
	p->link = (p->link)->link;
	delete q;
}

template<typename DataType>
void SortLink<DataType>::erase(const const_iterator& it)
{
	LinkNode<DataType>* p = head;
	LinkNode<DataType>* q = it._ptr;

	while( p->link != NULL && p->link != q )
	{
		p = p->link;
	}

	if(p->link == q)
	{
		p->link = q->link;
		delete q;
	}
}

template<typename DataType>
int SortLink<DataType>::length()const
{
	int n = 0;
	LinkNode<DataType>* p = head;
	while(p->link != NULL)
	{
		p = p->link;
		n++;
	}
	return n;
}

template<typename DataType>
bool SortLink<DataType>::empty()const
{
	return ( head->link == NULL );
}

template<typename DataType>
typename SortLink<DataType>::const_iterator SortLink<DataType>::find(const DataType& x)const
{
	LinkNode<DataType>* index = NULL;
	const_iterator it = begin();
	LinkNode<DataType>* p = it._ptr;
	
	while(p != NULL)
	{
		if(p->data == x)
		{
			index = p;
			break;
		}
		p = p->link;
	}
	return const_iterator(index);
}

template<typename DataType>
typename SortLink<DataType>::const_iterator SortLink<DataType>::locate(const int& i)const
{
	int n = length();
	if( i < 0 || i > n )
	{
		return NULL;
	}
	LinkNode<DataType>* p = head;
	for(int index = 1; index <= i; index++)
	{
		p = p->link;
	}
	return const_iterator(p);
}

template<typename DataType>
int SortLink<DataType>::locate(const const_iterator& it)const
{
	int i = 0;
	LinkNode<DataType>* p = head;
	LinkNode<DataType>* q = it._ptr;
	while( p->link != NULL && p != q )
	{
		p = p->link;
		i++;
	}

	if(p != q)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

template<typename DataType>
SortLink<DataType> SortLink<DataType>::merge(const SortLink<DataType>& X)
{
	for(const_iterator it = X.begin(); it != X.end(); it++)
	{
		insert(*it);
	}
	return (*this);
}

template<typename DataType>
SortLinkIterator<DataType>::SortLinkIterator()
{
	_ptr = NULL;
}

template<typename DataType>
SortLinkIterator<DataType>::SortLinkIterator(LinkNode<DataType>* p)
{
    _ptr = p;
}

template<typename DataType>
SortLinkIterator<DataType>& SortLinkIterator<DataType>::operator =(const SortLinkIterator& iter)
{
    _ptr = iter._ptr;
}

template<typename DataType>
bool SortLinkIterator<DataType>::operator !=(const SortLinkIterator& iter)const
{
    return _ptr != iter._ptr;
}

template<typename DataType>
bool SortLinkIterator<DataType>::operator ==(const SortLinkIterator& iter)const
{
    return _ptr == iter._ptr;
}

template<typename DataType>
SortLinkIterator<DataType>& SortLinkIterator<DataType>::operator ++()
{
    if(_ptr)
    {
    	_ptr = _ptr->link;
    }
    return *this;
}

template<typename DataType>
SortLinkIterator<DataType> SortLinkIterator<DataType>::operator ++(int)
{
    SortLinkIterator<DataType> tmp = *this;
    if(_ptr)
    {
    	_ptr = _ptr->link;
    }

    return tmp;
}

template<typename DataType>
DataType SortLinkIterator<DataType>::operator *()const
{
	if(_ptr)
	{
    	return _ptr->data;
	}
	else
	{
		cout << "Error in *it!" << endl;
		exit(-1);
	}
}

template<typename DataType>
bool SortLinkIterator<DataType>::empty()const
{
	return !_ptr;
}

#endif