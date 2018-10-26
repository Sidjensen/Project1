// LinkedList.cpp
// Taken from lab 2, with some modifications by me
// Sidney Jensen
// 10/26/18
// COSC 2030

// Definition of methods for the List class.
#include "stdafx.h"
#include "LinkedList.h"

#include <utility>

List::List()
	: first_(NULL), size_(0), sum_(0), max_(0), min_(2147483647)//min_(0)
{
}


List::List(const List & other)
	: first_(clone(other.first_)), size_(other.size_), sum_(other.sum_), max_(other.max_), min_(other.min_)
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
	size_ = 0;
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
		size_ = other.size_;/*maybe set size_ here to something else? */
		sum_ = other.sum_;
		max_ = other.max_;
		min_ = other.min_;
	}

	return *this;
}

bool List::empty() const
{
	return first_ == NULL;
}

int List::size() const
{
	return size_;
}

int List::sum()
{
	return sum_;
}

int List::max()
{
	return max_;
}

int List::min()
{
	return min_;
}

//void List::initializeMin(int min)
//{
//	min_ = min;
//}

void List::insertAsFirst(int x)
{
	size_ = size_ + 1;/*maybe change size_ here ? */
	sum_ = sum_ + x;
	if (x > max_) {
		max_ = x;
	}
	if (x < min_) {
		min_ = x;
	}

	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	size_ = size_ - 1; /*maybe change size_ here ? */
	sum_ = sum_ - item;
	delete tempPtr;
	return item;
}

void List::insertAsLast(int x)
{
	Node * tempPtr = first_; // pointer to first location in the list
	Node * last = new Node(x); //Creates a new node with value wanting to add
	Node * secondLast = tempPtr;
	if (tempPtr == NULL)
	{
		first_ = new Node(x, first_); // if nothing in the list, makes a node with value
	}
	else
	{
		tempPtr = tempPtr->next_; // moves to next pointer in the list
		while (tempPtr != NULL)
		{
			secondLast = tempPtr;
			tempPtr = tempPtr->next_; // if not last item move to next until it is.
		}
		secondLast->next_ = last; // when last item, change NUll to the location to the new node
	}
	size_ = size_ + 1; // changes size
	sum_ = sum_ + x; // changes sum
	if (x > max_) {
		max_ = x;
	}
	if (x < min_) {
		min_ = x;
	}
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

