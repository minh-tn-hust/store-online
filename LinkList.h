#pragma once
	#include <bits/stdc++.h>
	#include "StudentInfo.h"

using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node *next;

		Node(T data){
			this->data = data;
			this->next = NULL;
		}
};


template <class T>
class LinkedList{
	public:
		Node<T> *head;

		LinkedList(){
			this->head = NULL;
		}


		void addANode(T data){
			Node<T> *node = (Node<T>*) malloc(sizeof(Node<T>));
			node->data = data;
			node->next = NULL;
			if (this->head == NULL){
				this->head = node;
			} else {
				node->next = head;
				this->head = node;
			}

		}

		void printLinkedList(){
			Node<T> *head = this->head;
			while(head != NULL){
				cout << head->data;
				head = head->next;
			}
		}

		void printNodeWithBorder(string bottomBorder){
			Node<T> *head = this->head;
			while(head != NULL){
				cout << head->data;
				head = head->next;
			}
			cout << bottomBorder;
		}

		void addNodeWithOrder(T data, bool (*compare) (const T, const T)){
			Node<T> *node = (Node<T>*) malloc(sizeof(Node<T>));
			node->data = data;
			node->next = NULL;
			if (this->head == NULL){
				this->head = node;
			} else {
				Node<T> *head = this->head;
				Node<T> *last;
				Node<T> *prev = NULL;

				/* Find node in linkedlist that approve compare function */
				while(head != NULL && !compare(head->data, data)){
					if (head->next == NULL){
						last = head;
					}
					prev = head;
					head = head->next;
				}

				/* Add node into linkedList, have 3 case:
					- new node is head node
					- new node is last node
					- new node is middle node */
				if (head == NULL){
					node->next = NULL;
					last->next = node;
				} else if (prev != NULL){
					node->next = prev->next;
					prev->next = node;
				} else {
					node->next = this->head;
					this->head = node;
				}
			}
		}

};
