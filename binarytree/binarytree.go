package main

import (
	"log"
	"fmt"
)

type Node struct {
	value int
	rightchild *Node
	leftchild *Node
	parent *Node
}

type BinaryTree struct {
	root *Node
}

func ( bt *BinaryTree ) makeNode( paramValue int ) *Node {
	return &Node{ paramValue, nil, nil, nil }
}

func ( bt *BinaryTree ) insert( paramValue int ) (bool, error) {
	if bt.root == nil {
		bt.root = bt.makeNode( paramValue )
		return true, nil
	} else {
		parent := bt.root
		node := bt.root
		for node != nil {
			if node.value >= paramValue {
				parent = node
				node = node.leftchild
			} else {
				parent = node
				node = node.rightchild
			}
		}
		node = bt.makeNode( paramValue )
		if node.value <= parent.value {
			parent.leftchild = node
			node.parent = parent
			return true, nil
		} else {
			parent.rightchild = node
			node.parent = parent
			return true, nil
		}
	}
	return false, fmt.Errorf("Failed to insert: %v", paramValue)
}

func ( bt *BinaryTree ) remove( paramValue int ) (bool, error) {
	parent := bt.root
	node := bt.root
	for node != nil {
		if node.value > paramValue {
			parent = node
			node = node.leftchild
		} else if node.value < paramValue {
			parent = node
			node = node.rightchild
		} else {
			if node == parent.leftchild {
				if node.leftchild == nil && node.rightchild == nil {
					parent.leftchild = nil
					return true, nil
				} else if node.leftchild != nil && node.rightchild == nil {
					parent.leftchild = node.leftchild
					return true, nil
				} else if node.leftchild == nil && node.rightchild != nil {
					parent.leftchild = node.rightchild
					return true, nil
				} else {
					temp, err := bt.minNode(node.rightchild)
					parent.leftchild.value = temp.value
					if temp == temp.parent.leftchild {
						temp.parent.leftchild = nil
					} else {
						temp.parent.rightchild = nil
					}
					return true, err
				}
			} else {
				if node.leftchild == nil && node.rightchild == nil {
					parent.rightchild = nil
					return true, nil
				} else if node.leftchild != nil && node.rightchild == nil {
					parent.rightchild = node.leftchild
					return true, nil
				} else if node.leftchild == nil && node.rightchild != nil {
					parent.rightchild = node.rightchild
					return true, nil
				} else {
					temp, err := bt.minNode(node.rightchild)
					parent.rightchild.value = temp.value
					if temp == temp.parent.leftchild {
						temp.parent.leftchild = nil
					} else {
						temp.parent.rightchild = nil
					}
					return true, err
				}
			}
		}
	}
	return false, fmt.Errorf("Failed. Value does not exist: %v", paramValue)
}

func ( bt *BinaryTree ) minNode( paramRoot *Node ) (*Node, error) {
	if paramRoot == nil {
		return nil, fmt.Errorf("Failed. Nil tree you fool.")
	}
	result := paramRoot
	for result.leftchild != nil {
		result = result.leftchild
	}
	return result, nil
}

func ( bt *BinaryTree ) has( paramValue int ) bool {
	node := bt.root
	for node != nil {
		if node.value > paramValue {
			node = node.leftchild
		} else if node.value < paramValue {
			node = node.rightchild
		} else {
			return true
		}
	}
	return false
}

func main() {
	var binaryTree BinaryTree

	for i := 0 ; i < 10 ; i++ {
		_, ok := binaryTree.insert(i)
		if ok != nil {
			log.Println(ok)
		}
		for j := 20 ; j >10 ; j-- {
			_, ok = binaryTree.insert(j)
			if ok != nil {
				log.Println(ok)
			}
		}
	}

	for i := 0 ; i < 10 ; i++ {
		_, ok := binaryTree.remove(i)
		if ok != nil {
			log.Println(ok)
		}
		/*
		for j := 20 ; j > 10 ; j-- {
			_, ok = binaryTree.remove(j)
			if ok != nil {
				log.Println(ok)
			}
		}
		*/
	}

	for k := 0 ; k <= 20 ; k++ {
		log.Println(binaryTree.has(k))
	}
}





