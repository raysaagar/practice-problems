import java.util.ArrayList;

/*******************************************************************************************
 * Binary Search Tree
 * Problem to solve:
 * - http://codercareer.blogspot.com/2011/09/interview-question-no-1-binary-search.html
 * Converts BST to Doubly LL via ArrayList
 *******************************************************************************************/
public class BinarySearchTree {

	/**
	 * Node object class for use in BST and doubly linked list
	 */
	private static class Node{
		Integer value;
		Node left;
		Node right;
		
		private Node(){
			this.value = null;
			this.left = null;
			this.right = null;
		}
		
		private Node(int value){
			this.value = value;
			this.left = null;
			this.right = null;
		}
		
		private Node(int value, Node left, Node right){
			this.value = value;
			this.left = left;
			this.right = right;
		}
		
		private void setValue(int value){this.value = value;}
		private void setLeft(Node left){this.left = left;}
		private void setRight(Node right){this.right = right;}
		private int getValue(){return value;}
		private Node getLeft(){return this.left;}
		private Node getRight(){return this.right;}
	}
	
	Node head;
	
	Node ll_head;
	Node ptr;
	
	public BinarySearchTree(){
		head = null;
		ll_head = null;
	}
	
	public BinarySearchTree(int value){
		head = new Node(value);
		ll_head = null;
	}
	
	public void insert(int value){
		insertNode(new Node(value));
	}
	
	public void insertNode(Node n){
		
		// if head is null, start new tree
		if (this.head == null){
			this.head = n;
			return;
		}
		// else recursively insert item
		insertHelper(this.head, n);
	}
	
	// recursively insert item
	private void insertHelper(Node root, Node n){
		if(root.value == n.value){
			System.out.println("Duplicates are not allowed!");
			return;
		}
		else if(root.value > n.value){
			if (root.left == null)
				root.setLeft(n);
			else
				insertHelper(root.left, n);
			return;
		}
		else{
			if (root.right == null){
				root.setRight(n);
			}
			else
				insertHelper(root.right, n);
			return;
		}
	}
	
	public boolean search(int value){
		
		if(this.head == null)
			return false;
		
		return searchHelper(this.head, value);
	}
	
	private boolean searchHelper(Node root, int value){
		if(root.value == value)
			return true;
		else if (root.left == null && root.right == null)
			return false;
		else if (root.value > value)
			return searchHelper(root.left, value);
		else
			return searchHelper(root.right, value);
	}
	
	public ArrayList<ArrayList<String>> treeToList(){
		ArrayList<ArrayList<String>> list = new ArrayList<ArrayList<String>>();
		list = toListHelper(this.head, 0, list);
		System.out.println(list.toString());
		return list;
	}
	
	private ArrayList<ArrayList<String>> toListHelper(Node n, int level, ArrayList<ArrayList<String>> list){
		ArrayList<String> x = null;
		// check if we have a list for this level
		try{x = list.get(level);} catch(Exception e){/* do nothing */}
		
		// make the initial list for the level
		if (x == null){
			x = new ArrayList<String>();
			list.add(x);
		}
		// if item is null, blank item
		if(n == null){
			x.add("");
		}
		else {
			x.add(n.value.toString());
			// if node has a left or right child, then recurse, else ignore (don't want a list of empty strings)
			if(n.left != null || n.right != null){
				toListHelper(n.left, level+1,list);
				toListHelper(n.right, level+1,list);
			}
		}
		
		return list;
	}
	
	public void drawTree(){
		ArrayList<ArrayList<String>> list = this.treeToList();
		int level = 1;
		for(ArrayList<String> x: list){
			System.out.printf("Level %3d: ", level);
			for(int i = 0; i < x.size(); i++){
				String s = x.get(i);
				if (s.equals(""))
					System.out.printf("%3s ", "\" \"");
				else
					System.out.printf("%3s ", x.get(i));
				if((i+1) % 2 == 0)
					System.out.print("| ");
			}
			System.out.println();
			level++;
		}
	}
	
	// root, left, right
	public void preOrderTraversal(){System.out.println("Pre-order: " + preOrderHelper(this.head));}
	// left, root, right 
	public void inOrderTraversal(){System.out.println("In-order: " + inOrderHelper(this.head));}
	// left, right, root
	public void postOrderTraversal(){System.out.println("Post-order: " + postOrderHelper(this.head));}
	
	private String preOrderHelper(Node n){
		if(n == null){return "";}
		return n.value.toString() + " " + preOrderHelper(n.left) + preOrderHelper(n.right);
	}
	
	private String inOrderHelper(Node n){
		if(n == null){return "";}
		return inOrderHelper(n.left) + n.value.toString() + " " + inOrderHelper(n.right);
	}
	
	private String postOrderHelper(Node n){
		if(n == null){return "";}
		return postOrderHelper(n.left) + postOrderHelper(n.right) + n.value.toString() + " ";
	}
	
	public Node toLinkedList(){
		ArrayList<Node> list = new ArrayList<Node>();
		
		// take all nodes and push them into arraylist using inorder traversal
		list = ll_helper(this.head,list);
		
		// print out the list
//		for(int i = 0; i < list.size(); i++){
//			System.out.print(list.get(i).value + " ");
//		}
//		System.out.println();
		
		// head of list
		Node head = new Node();
		Node ptr = head;
		// create the doubly linked list
		for(int i = 0; i < list.size(); i++){
			ptr.right = list.get(i);
			list.get(i).left = ptr;
			ptr = ptr.right;
		}
		
		ptr = head.right;
		System.out.print(ptr.value);
		while(ptr.right != null){
			ptr = ptr.right;
			System.out.print("->" + ptr.value);
			
		}
		
		return head;
	}
	
	// push all nodes into list using in order traversal (maintain order)
	private ArrayList<Node> ll_helper(Node n, ArrayList<Node> list){
		if(n == null){return list;}
		
		list = ll_helper(n.left,list);
		list.add(n);
		list = ll_helper(n.right,list);
		
		return list;
	}
	
	public static void main(String[] args) {
		
		BinarySearchTree bst = new BinarySearchTree();
		bst.insert(8);
		bst.insert(4);
		bst.insert(2);
		bst.insert(1);
		bst.insert(3);
		bst.insert(6);
		bst.insert(5);
		bst.insert(7);
		bst.insert(12);
		bst.insert(10);
		bst.insert(9);
		bst.insert(11);
		bst.insert(14);
		bst.insert(13);
		bst.insert(15);

//		bst.drawTree();
//		bst.preOrderTraversal();
		bst.inOrderTraversal();
//		bst.postOrderTraversal();
		bst.toLinkedList();
		
	}
}



