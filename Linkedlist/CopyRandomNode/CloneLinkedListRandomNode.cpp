// myds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include<iostream>
using namespace std;

struct node
{
	int m_data;
	int m_randomcount;
	node * link,*random;
	node(int val)
	{m_randomcount=0;
		m_data = val;
		link=NULL;
		random=NULL;
	}
}*start,*cloned;

void insert(int va)
{
	node * ptr  = new node(va);
	if(start != NULL)
	{
		ptr->link = start;
	}
	start = ptr;

}

node* GetNode(int counter)
{
	node * ptr =start;
	int i=0;
	
	while(ptr != NULL )
	{
		if(counter == i )
		break;
		i++;
		ptr = ptr->link;
		
	}
	return ptr;
}

void display(node *ptr =start)
{
	//node * ptr =start;
	while(ptr!=NULL)
	{
		std::cout<<"=========================================================="<<std::endl;
		std::cout<<"data is "<<ptr->m_data<<std::endl;
		if(ptr->link!=NULL)
		std::cout<<"value of link node is "<<ptr->link->m_data<<std::endl;
		std::cout<<"value of random node is "<<ptr->random->m_data<<std::endl;
		ptr=ptr->link;
		
	}
}
node *clone()
{
	node*ptr = start;

	while(ptr!=NULL)
	{
		node*temp = ptr->link;

		ptr->link = new node(ptr->m_data);
		ptr->link->link = temp;
		ptr=  temp;//this is done otherwise it would now pick the new inserted node

	}



	ptr = start;


	while(ptr)
	{
		ptr->link->random = ptr->random->link;
		ptr = ptr->link->link;
	}


	ptr = start;
	cloned = start->link;
	node *temp =cloned;
	while(ptr!=NULL && temp !=NULL)
	{
		ptr->link = ptr->link?ptr->link->link:ptr->link;
		temp->link =temp->link? temp->link->link:temp->link;
		
		ptr = ptr->link;
		temp = temp->link;
	}

	return cloned;
}


int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0 ;i < 10;i++)
		insert(i+1);
	for(int i = 0;i < 10 ;i++)
	{
		node * item =  GetNode(i);
		int val =  (rand() % 10);
		item->m_randomcount = val;
		item->random = GetNode(val);
	}

	display();
	
	node * newone = clone();
	std::cout<<"now cloned list starts"<<std::endl<<std::endl;;
	display(newone);
	return 0;
}

