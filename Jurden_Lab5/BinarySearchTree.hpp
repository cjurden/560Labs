#include "Node.h"
#include <iostream>
#include <queue>
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	if(other.m_root == nullptr)
	{
		return;
	}
	else
	{
		this->m_root = new Node<T>(*other.m_root);
	}
}
//delete / deconstruct
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	if(subtree == nullptr)
	{
		return;
	}	

	deleteTree(subtree->getRight());
	deleteTree(subtree->getLeft());
	delete subtree;
}

template <typename T>
void BinarySearchTree<T>::deleteTree()
{
	deleteTree(m_root);
	m_root = nullptr;
}
//add
template <typename T>
void BinarySearchTree<T>::add(T value)
{
	if(m_root == nullptr)
	{
		Node<T>* node = new Node<T>();
		node->setValue(value);
		m_root = node;
	}	
	else
	{	
		add(value, m_root);
	}
}

template <typename T>
void BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	
	
	if(value < (subtree->getValue()))
	{
				
		if(subtree->getLeft() == nullptr)
		{	
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			subtree->setLeft(temp);
		}
		else
		{						
			add(value, subtree->getLeft());
		}
		
	}
	
	else if(value > (subtree->getValue()))
	{
		
		if(subtree->getRight() == nullptr)
		{	
			Node<T>* temp = new Node<T>();
			temp->setValue(value);	
			subtree->setRight(temp);
		}
		else
		{
			add(value, subtree->getRight());
		}
		
	}
}
//print
template <typename T>
void BinarySearchTree<T>::printTree(Order order)
{
	
	if(order == PRE_ORDER)
	{
		printTree(m_root, PRE_ORDER);				
	}
	else if(order == IN_ORDER)
	{
		printTree(m_root, IN_ORDER);
	}
	else if(order == POST_ORDER)
	{
		printTree(m_root, POST_ORDER);
	}
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order)
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order == PRE_ORDER)
	{
		std::cout<<subtree->getValue()<<", ";
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
	}
	if(order == POST_ORDER)
	{
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
		std::cout<<subtree->getValue()<<", ";
	}
	if(order == IN_ORDER)
	{
		printTree(subtree->getLeft(), order);
		std::cout<<subtree->getValue()<<", ";
		printTree(subtree->getRight(), order );
	}
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRoot()
{
	return m_root;
}
//search
template <typename T>
Node<T>* BinarySearchTree<T>::search(T value)
{

	search(value, m_root);	
	
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>* subtree)
{
	if(subtree == nullptr)
	{
		return nullptr;
	}	
	else if(value == subtree->getValue())
	{
		return subtree;
	}
	else if(value < subtree->getValue())
	{
		return search(value, subtree->getLeft());
	}
	else if(value > subtree->getValue())
	{
		return search(value, subtree->getRight());
	}

}




