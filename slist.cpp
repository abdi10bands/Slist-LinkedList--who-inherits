// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl;}


// positions always start at 1

int slist::search(el_t key)
{
  int counter = 1;
  Node*P;
  P = Front;
  while(P!=NULL) 
    {

       if(P->Elem == key)
      	{
      	  return counter;
      	}
       counter++;
       P=P->Next;
    }
    return 0;
}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos)
{
 
  if(( pos > Count)||( pos<1)) 
    throw OutOfRange();
  else
    {
      Node *P; //created a node to pass 
      moveTo(pos,P);//passed the node to move function
      P->Elem = element; // basically overwrote the element that was there
      
    }
      
	  

}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  // if the same lengths,
  // check each node to see if the elements are the same
  if (Count == OtherOne.Count) // check if one list is the same size as the other
    {
      Node *Ptr = OtherOne.Front;//Sets pointer to front of one
      
      Node *Ptr2 = this -> Front;//sets pointer to front of the otherone
      
      while (Ptr != NULL && Ptr2 != NULL)// Loop through both list
	{
	  if (Ptr -> Elem != Ptr2 -> Elem)//  if the elements of the nodes are equal
	    {
	      return false; //not return false
	    }
	  
	  Ptr = Ptr -> Next;// moves through each node
	  
	  Ptr2 = Ptr2 -> Next; //moves through each node of the other one
	}
      return true; //if they equal returns true 
    }
  return false;//Return false 

}
