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

func ( _bt *BinaryTree ) makeNode( _value int ) *Node {
	return &Node{ _value, nil, nil, nil }
}

func ( _bt *BinaryTree ) insert( _value int ) (bool, error) {
	if _bt.root == nil {
		_bt.root = _bt.makeNode( _value )
		return true, nil
	} else {
		parent := _bt.root
		node := _bt.root
		for node != nil {
			if node.value >= _value {
				parent = node
				node = node.leftchild
			} else {
				parent = node
				node = node.rightchild
			}
		}
		node = _bt.makeNode( _value )
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
	return false, fmt.Errorf("Failed to insert: %v", _value)
}

func ( _bt *BinaryTree ) remove( _value int ) (bool, error) {
	parent := _bt.root
	node := _bt.root
	for node != nil {
		if node.value > _value {
			parent = node
			node = node.leftchild
		} else if node.value < _value {
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
					temp, err := _bt.minNode(node.rightchild)
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
					temp, err := _bt.minNode(node.rightchild)
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
	return false, fmt.Errorf("Failed. Value does not exist: %v", _value)
}

func ( _bt *BinaryTree ) minNode( _root *Node ) (*Node, error) {
	if _root == nil {
		return nil, fmt.Errorf("Failed. Nil tree you fool.")
	}
	result := _root
	for result.leftchild != nil {
		result = result.leftchild
	}
	return result, nil
}

func ( _bt *BinaryTree ) has( _value int ) bool {
	node := _bt.root
	for node != nil {
		if node.value > _value {
			node = node.leftchild
		} else if node.value < _value {
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





