
public class DoublyLinkedList<V>{

	private static class Node<V>{
		
		Node prev;
		Node next;
		V value;
		
		public Node(V value){
			this.value = value;
			this.prev = null;
			this.next = null;
		}
		
		public V getValue(){return this.value;}
		public Node getNext(){return this.next;}
		public Node getPrev(){return this.prev;}
		public void setNext(Node<V> n){this.next = n;}
		public void setPrev(Node<V> n){this.prev = n;}
	}
	
	Node<V> head;
	Node<V> tail;
	
	public DoublyLinkedList(V value){
		Node<V> n = new Node<V>(value);
		head = n;
		tail = n;
	}
	
	public void insert(V value){
		Node<V> n = new Node<V>(value);
		n.setNext(head);
		n.setPrev(null);
		head = n;
	}
	
	public boolean contains(V value){
		
		Node<V> ptr = head;
		while(ptr != null){
			if(ptr.getValue() == value)
				return true;
			ptr = ptr.getNext();
		}
		
		return false;
	}
	
	public boolean remove(V value){

		Node<V> ptr = head;
		
		while(ptr != null){
			if(ptr.getValue() == value){
				System.out.println("found!");
				System.out.println(ptr.getNext());
				System.out.println(ptr.getPrev());
				break;
			}
			ptr = ptr.getNext();
			if(ptr == null){
				return false;
			}
		}
		
		// CASE 1: Only item in list
		if(ptr.getNext() == null && ptr.getPrev() == null){
			System.out.println("case1");
			ptr = null;
		}
		// CASE 2: Head of list
		else if (ptr.getPrev() == null){
			System.out.println("case2");
			head = ptr.getNext();
			ptr = null;
		}
		// CASE 3: Tail of list
		else if (ptr.getNext() == null){
			System.out.println("case3");
			tail = ptr.getPrev();
			tail.setNext(null);
		}
		// CASE 4: Middle of list
		else{
			System.out.println("case4");
			ptr.getPrev().setNext(ptr.getNext());
			ptr.getNext().setPrev(ptr.getPrev());
		}
		
		return true;
	}
	
	public void printList(){
		Node<V> ptr = head;
		while(ptr != null){
			System.out.print(ptr.getValue() + " ");
			ptr = ptr.getNext();
		}
		System.out.println();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		DoublyLinkedList<Integer> dll = new DoublyLinkedList<Integer>(0);
		dll.insert(1);
		dll.insert(2);
		dll.insert(3);
		dll.insert(4);
		dll.insert(5);
		dll.printList();
		System.out.println(dll.contains(6));
		System.out.println(dll.contains(0));
		dll.remove(5);
		dll.printList();
		dll.remove(0);
		dll.printList();
//		dll.remove(3);
//		dll.printList();
	}

}
