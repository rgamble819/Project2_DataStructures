#include <iostream>
#include "OULink.h"
#include "OULinkedList.h"
#include "OULinkedListEnumerator.h"
#include "OULink.h"
#include "TestComparator.h";

using namespace std;


void testAppend();
void testGetFirst();
void testRemoveFirst();
void testPullFirst();
void testContains();

void success(string test);
void fail(string test);


int main()
{	
	testAppend();
	testGetFirst();
	testRemoveFirst();
	testPullFirst();
	testContains();


	return -1;
}

template<typename T>
bool assert(T item1, T item2)
{
	if (item1 == item2)
	{
		return true;
	}

	return false;
}

void testAppend() 
{
	// Create linked list structure.
	TestComparator* comparator = new TestComparator();
	OULinkedList<int>* list = new OULinkedList<int>(comparator);

	// Add an item to the list
	list->append(5);

	// Check if the item was added successfully.
	try 
	{
		if (assert(list->getFirst(), 5))
		{
			list->append(10);
			if(list->contains(10))
			{
				success("append");
			}
		}
		else 
		{
			fail("append");
		}
	}
	catch (ExceptionLinkedListAccess* exc)
	{
		delete exc;
		exc = nullptr;
		fail("append");
	}
}

void testGetFirst() 
{
	// Create linked list structure.
	TestComparator* comparator = new TestComparator();
	OULinkedList<int>* list = new OULinkedList<int>(comparator);

	// Add an item to the list
	list->append(5);

	if (assert(list->getFirst(), 5)) 
	{
		success("getFirst");
	}
	else 
	{
		fail("getFirst");
	}
}

void testRemoveFirst() 
{
	// Create linked list structure.
	TestComparator* comparator = new TestComparator();
	OULinkedList<int>* list = new OULinkedList<int>(comparator);

	// Add an item to the list
	list->append(5);

	list->removeFirst();

	try {
		if (list->getFirst())
		{
			fail("removeFirst");
		}
	}
	catch(ExceptionLinkedListAccess* exc)
	{
		delete exc;
		exc = NULL;

		success("removeFirst");
	}
}

void testPullFirst()
{
	// Create linked list structure.
	TestComparator* comparator = new TestComparator();
	OULinkedList<int>* list = new OULinkedList<int>(comparator);

	// Add an item to the list
	list->append(5);

	if(assert(list->pullFirst(), 5))
	{
		try 
		{
			list->getFirst();
			fail("pillFirst");
		}
		catch (ExceptionLinkedListAccess* exc) 
		{
			delete exc;
			exc = NULL;
			success("pullFirst");
		}
	}
	else 
	{
		fail("pullFirst");
	}
}

void testContains()
{
	// Create linked list structure.
	TestComparator* comparator = new TestComparator();
	OULinkedList<int>* list = new OULinkedList<int>(comparator);

	list->append(5);
	list->append(10);

	if (assert(list->contains(5), true) 
		&& assert(list->contains(10), true) 
		&& assert(list->contains(7), false)) 
	{
		success("contains");
	}
}

void success(string test)
{
	cout << test << " was successful!\n";
}

void fail(string test)
{
	cout << test << " failed!\n";
}
