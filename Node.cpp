// Node.cpp
// Taken from lab 2, no changes made execpt commmit out the couts
// Sidney Jensen
// 10/26/18
// COSC 2030

// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods

#include "stdafx.h"
#include "Node.h"


Node::Node(double entry)
	: entry_(entry), next_(NULL)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) created at " << this << endl;
}

Node::Node(double entry, Node * next)
	: entry_(entry), next_(next)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) created at " << this << endl;
}

Node::~Node()
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) at " << this << " destroyed" << endl;
}
