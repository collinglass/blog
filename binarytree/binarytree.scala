// binarytree.scala

 sealed abstract class Tree {
   def insert(paramValue: Int) : Node
   def search(paramValue: Int) : Boolean
   def remove(paramValue: Int) : Tree
   def minimumValue() : Int
   def minimumRemove() : Tree
 }
 
 case class Node(var value: Int, left: Tree, right: Tree) extends Tree {
   def insert(paramValue: Int) =
      if (paramValue < value) Node(value, left.insert(paramValue), right)
      else Node(value, left, right.insert(paramValue))

   def search(paramValue: Int) =
      if ( paramValue < value ) left.search(paramValue)
      else if ( paramValue > value ) right.search(paramValue)
      else true

   def remove(paramValue: Int) =
      if (paramValue < value) Node(value, left.remove(paramValue), right)
      else if ( paramValue > value ) Node(value, left, right.remove(paramValue))
      else this match {
         case (Node(paramValue, End, End)) => End
         case (Node(paramValue, left, End)) => left
         case (Node(paramValue, End, right)) => right
         case (Node(paramValue, left, right)) => Node(right.minimumValue(), left, right.minimumRemove())
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
   def insert(paramValue: Int) = Node(paramValue)
   def search(paramValue: Int) = false
   def remove(paramValue: Int) = End
   def minimumValue() = 0
   def minimumRemove() = End
 }

 object Node {
   def apply(paramValue: Int): Node = Node(paramValue, End, End)
 }



var bt = Node( 10, Node(5, Node(4, End, End), Node(6, End , End )), End)
bt = bt.insert(21)
println(bt.search(6))
println(bt.remove(5))

