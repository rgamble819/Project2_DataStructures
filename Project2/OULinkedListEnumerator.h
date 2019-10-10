#ifndef OU_LINKED_LIST_ENUMERATOR
#define OU_LINKED_LIST_ENUMERATOR

#include "Enumerator.h"
#include "OULink.h"

template <typename T>
class OULinkedListEnumerator : public Enumerator<T>
{
private:
	OULink<T>* current;
public:
	OULinkedListEnumerator(OULink<T>* first);
	bool hasNext() const;
	T next();			// throws ExceptionEnumerationBeyondEnd if no next item is available
	T peek() const;		// throws ExceptionEnumerationBeyondEnd if no next item is available
};

// Add your implementation below this line. Do not add or modify anything above this line.


template<typename T>
OULinkedListEnumerator<T>::OULinkedListEnumerator(OULink<T>* first)
{
	// Set current link to first link upon creation.
	current = first;
}

template<typename T>
bool OULinkedListEnumerator<T>::hasNext() const
{
	if (current->next != NULL)
	{
		return true;
	}
	return false;
}

template<typename T>
T OULinkedListEnumerator<T>::next()
{
	OULink<int>* nextElement = current->next;
	if (nextElement == NULL) throw new ExceptionEnumerationBeyondEnd();
	
	// Set current to the next of the current element.
	current = nextElement;
	return current->data;
}

template<typename T>
T OULinkedListEnumerator<T>::peek() const
{
	if (current->next == NULL)
	{
		throw new ExceptionEnumerationBeyondEnd();
	}
	return current->next->data;
}




#endif // !OU_LINKED_LIST_ENUMERATOR
