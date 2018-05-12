// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

struct node{

	int data;
	node* right;
	node* left;
	node(){
		right = NULL;
		left = NULL;
	}
	node(int d) :data(d), right(NULL), left(NULL){}
};

class dlist{
private:
	node* head;
	int count = 0;
public:
	dlist() :head(NULL){}

	dlist(node* nptr){
		head = nptr;
		head->left = head;
		head->right = NULL;
		count++;


	}
	dlist(int n){
		node* nptr = new node(n);
		head = nptr;
		head->left = head;
		head->right = NULL;
		count++;


	}


	int len(){
		node* nptr = head;
		int i;
		for (i = 0; nptr; nptr = nptr->right){
			i++;
		}
		return i;
	}

	void inserR(node* nptr){
		if (!head){
			head = nptr;
			head->left = head;
			head->right = NULL;
			count++;
		}

		else{
			nptr->left = head->left;
			head->left->right = nptr;
			head->left = nptr;
		}
	}
	void inserL(node* nptr){
		if (!head){
			head = nptr;
			head->left = head;
			head->right = NULL;
			count++;
		}
		else{
			nptr->left = head->left;
			nptr->right = head;
			head->left = nptr;
			head = nptr;
			count++;
		}

	}
	void inserL(int n){
		node* nptr = new node(n);
		if (!head){
			head = nptr;
			head->left = head;
			head->right = NULL;
			count++;
		}
		else{
			nptr->left = head->left;
			nptr->right = head;
			head->left = nptr;
			head = nptr;
			count++;
		}

	}
	void inserR(int n){
		node* nptr = new node(n);
		if (!head){
			head = nptr;
			head->left = head;
			head->right = NULL;
			count++;
		}

		else{
			nptr->left = head->left;
			head->left->right = nptr;
			head->left = nptr;
		}
	}

	void print(){
		node* nptr = head;
		while (nptr){
			cout << nptr->data << " ";
			nptr = nptr->right;
		}
	}
	
	void insertAt(int index,int n){
		node* nptr = new node(n);
		if (index >= this->len()){
			index = this->len();
			this->inserR(nptr);
		}else if (index <= 0){
			this->inserR(nptr);
		}
		else
		{
			node* rptr = head;
			for (int i = 0; i < index-1; i++){
				rptr = rptr->right;
			}
			nptr->right = rptr->right;
			nptr->left = rptr;
			rptr->right->left = nptr;
			rptr->right = nptr;
		}

	}

	int search(int n){
		node* rptr = head;
		for (int i = 0; rptr; rptr = rptr->right)
		{
			if (rptr->data == n){
				return i;
			}
			i++;
		}
		return -404;
	}

	void deleteR(){
		if (this->len()>1){
			node* nptr = head->left;
			head->left = head->left->left;
			head->left->right = NULL;
			nptr->left = NULL;
			delete nptr;
		}
		else
		{
			node* nptr = head;
			head = NULL;
			delete nptr;
		}
		
	}

	void deleteL(){
		if (this->len()>1){
			node* nptr = head;
			head = head->right;
			head->left = nptr->left;
			delete nptr;
		}
		else
		{
			node* nptr = head;
			head = NULL;
			delete nptr;
				 
		}
		
	}
	void deleteIndex(int index){
		index = abs(index);
		node* rptr = head;
		if ((index < this->len() - 1)){
			if (index != 0){
				for (int i = 0; i < index; i++){
					rptr = rptr->right;

				}
				rptr->right->left = rptr->left;
				rptr->left->right = rptr->right;
				rptr->left = rptr->right = NULL;
				delete rptr;
			}
			else
			{
				this->deleteL();
			}
			
		}
		else if (index>=this->len()-1){
			this->deleteR();
		}		
	}

};


int main()
{
 node* n=new node(1);
 node* m = new node(2);
 node* o=new node(3);
 node* p=new node(4);
 dlist* dl=new dlist();
 for (int i = 0; i < 10; i++){
	 dl->inserR(i);
 }





	system("pause");







	return 0;
}
