//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

//
//  Updated by Ngoc Lam-Miller for CSC340.02 Fall 2021
//

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include "iostream"


template<class ItemType>
class LinkedList : public ListInterface<ItemType> {

template<class friendItemType>
friend std::ostream& operator<<(std::ostream& outStream,
  const LinkedList<friendItemType>& outputList);

public:
  LinkedList();
  LinkedList(const LinkedList<ItemType>& aList);  ///TODO
  virtual ~LinkedList();

  // overloaded function
  LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rhs);  ///TODO
  LinkedList<ItemType>& operator+(const LinkedList<ItemType>& rhs) const;  ///TODO
  bool operator==(const LinkedList<ItemType>& rhs) const;  ///TODO

  bool isEmpty() const;
  int getLength() const;
  bool insert(int newPosition, const ItemType& newEntry);
  bool remove(int position);
  void clear();

  /** @throw PrecondViolatedExcept if
   *    position < 1 or position > getLength(). */
  ItemType getEntry(int position) const throw(PrecondViolatedExcept);

  /** @throw PrecondViolatedExcept if
   *    position < 1 or position > getLength(). */
  ItemType replace(int position, const ItemType& newEntry)
    throw(PrecondViolatedExcept);  ///TODO

private:
  Node<ItemType>* headPtr; // Pointer to first node in the chain;
                           // (contains the first entry in the list)
  int itemCount;           // Current count of list items

  // Locates a specified node in this linked list.
  // @pre  position is the number of the desired node;
  //       position >= 1 and position <= itemCount.
  // @post  The node is found and a pointer to it is returned.
  // @param position  The number of the node to locate.
  // @return  A pointer to the node at the given position.
  Node<ItemType>* getNodeAt(int position) const;

}; // end LinkedList

#endif


//-------------------------------------------------------------------
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor


///TODO: your implementation of copy constructor

///TODO: your implementation of assignment operator

///TODO: your implementation of operator+

///TODO: your implementation of operator==

///TODO: your implementation of replace function


template<class friendItemType>
std::ostream& operator<<(std::ostream& outStream,
  const LinkedList<friendItemType>& outputList)
{
  int position = 1;
  Node<friendItemType>* curPtr = outputList.headPtr;
  while (curPtr != nullptr) {
    outStream << curPtr->getItem() << "(" << position << ") -> ";
    curPtr = curPtr->getNext();
    position++;
  }
  outStream << "nullptr";
  return outStream;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
} // end destructor

//---------------------------------------------------


template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
  return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
  return (itemCount == 0);
}


//--------------------------
template<class ItemType>
void LinkedList<ItemType>::clear()
{
  while (!isEmpty())
    remove(1);
} // end clear


template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
  bool ableToRemove = (position >= 1) && (position <= itemCount);
  if (ableToRemove) {
     Node<ItemType>* curPtr = nullptr;
     if (position == 1) {
       // Remove the first node in the chain
       curPtr = headPtr; // Save pointer to node
       headPtr = headPtr->getNext();
     }
     else {
       // Find node that is before the one to remove
       Node<ItemType>* prevPtr = getNodeAt(position - 1);

       // Point to node to remove
       curPtr = prevPtr->getNext();

       // Disconnect indicated node from chain by connecting the
       // prior node with the one after
       prevPtr->setNext(curPtr->getNext());
     }

     // Return node to system
     curPtr->setNext(nullptr);
     delete curPtr;
     curPtr = nullptr;
     itemCount--; // Decrease count of entries
  }

  return ableToRemove;
} // end remove



template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
    throw(PrecondViolatedExcept)
{
  // Enforce precondition
  bool ableToGet = (position >= 1) && (position <= itemCount);
  if (ableToGet) {
     Node<ItemType>* nodePtr = getNodeAt(position);
     return nodePtr->getItem();
  }
  else {
     std::string message = "getEntry() called with an empty list or ";
     message = message + "invalid position.";
     throw(PrecondViolatedExcept(message));
  }
} // end getEntry


template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
  // Debugging check of precondition
  assert( (position >= 1) && (position <= itemCount) );

  // Count from the beginning of the chain
  Node<ItemType>* curPtr = headPtr;
  for (int skip = 1; skip < position; skip++)
    curPtr = curPtr->getNext();

  return curPtr;
}  // end getNodeAt


template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }

      itemCount++;
      }

   return ableToInsert;
}  // end insert
