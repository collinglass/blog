// binarytree.scala

 sealed abstract class Tree {
   def insert(_value: Int) : Node
   def search(_value: Int) : Boolean
   def remove(_value: Int) : Tree
   def minimumValue() : Int
   def minimumRemove() : Tree
 }
 
 case class Node(var value: Int, left: Tree, right: Tree) extends Tree {
   def insert(_value: Int) =
      if (_value < value) Node(value, left.insert(_value), right)
      else Node(value, left, right.insert(_value))

   def search(_value: Int) =
      if ( _value < value ) left.search(_value)
      else if ( _value > value ) right.search(_value)
      else true

   def remove(_value: Int) =
      if (_value < value) Node(value, left.remove(_value), right)
      else if ( _value > value ) Node(value, left, right.remove(_value))
      else this match {
         case (Node(_value, End, End)) => End
         case (Node(_value, left, End)) => left
         case (Node(_value, End, right)) => right
         case (Node(_value, left, right)) => Node(right.minimumValue(), left, right.minimumRemove())
      }

   def minimumValue() =
      left match {
         case (End) => this.value
         case (Node(_,_,_)) => left.minimumValue()
      }

   def minimumRemove() =
      left match {
         case (End) => End
         case (Node(_,_,_)) => left.minimumRemove()
      }
 }

 case object End extends Tree {
   def insert(_value: Int) = Node(_value)
   def search(_value: Int) = false
   def remove(_value: Int) = End
   def minimumValue() = 0
   def minimumRemove() = End
 }

 object Node {
   def apply(_value: Int): Node = Node(_value, End, End)
 }



var bt = Node( 10, Node(5, Node(4, End, End), Node(6, End , End )), End)
bt = bt.insert(21)
println(bt.search(6))
println(bt.remove(5))

