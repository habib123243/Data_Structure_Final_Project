

////////////bst object base///////////////

#include<iostream>
#include<string>
using namespace std;

class medicine
{
public:
	int price;
	int quantity;
	int date;
	string name;
	medicine(string hh, int a, int b, int c)
	{
		name = hh;
		price = a;
		quantity = b;
		date = c;

	}
	medicine()
	{

	}
	void setprice(int v)
	{
		price = v;
	}
	void setquantity(int vv)
	{
		quantity = vv;
	}
	int getquantity()
	{
		return quantity;
	}
	string getstring()
	{
		return name;
	}
	int getprice()
	{
		return price;
	}
	void setdate(int d)
	{
		date = d;
	}
	int getdate()
	{
		return date;
	}
	void displaymedicine()
	{
		cout << "Medicine information" << endl;
		cout << "Name = " << name << endl;
		cout << "Price = " << price << endl;
		cout << "Quantity = " << quantity << endl;
		cout << "Date = " << date << endl;
		cout << endl << endl << endl;
	}
};
class Node
{
public:
	//medicine *mm;
	//int data
	medicine k;
	Node* left;
	Node* right;
	string data;
	Node* next;

	Node()
	{
		left = right = NULL;



	}
	Node(string s)
	{
		data = s;
		next = NULL;
	}

};
/////////////////stack//////////////
class Node2                                 ///For stack////////////////////////
{
public:
	medicine data1;
	// data1;
	Node2* next1;

	Node2(medicine v)
	{
		data1 = v;
		next1 = NULL;

	}

};
class Tree
{
public:
	medicine mbbs;
	Node* root;
	Node* ttt;
	Node* first;
	Node* last;
	Node2* first1;
	Node2* last1;
	int* array;
	int size;
	int front;
	int rear;
	Tree()
	{
		root = NULL;
		first = last = NULL;
		first1 = last1 = NULL;
		front = 0;
		rear = 0;
	
	}
	//Tree(int sz)
	//{
	//	size = sz;
	//	array = new int[sz];
	//	front = 0;
	//	rear = 0;
	//}
	////////////////////////////////sorting and linklists////////////////
	bool isempty()
	{
		if (first == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isempty1()                  /////stack
	{
		if (first1 == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void inserttreetolinklist(string v)
	{
		Node* node = new Node(v);
		if (isempty())
		{
			first = node;
			last = node;
		}
		else
		{
			last->next = node;
			last = node;
		}
	}
	void BUBBLESORTING()
	{
		Node* h;
		Node* temp = first;
		string tt;
		while (temp->next != NULL)
		{
			h = temp->next;
			while (h != NULL)
			{
				if (temp->data > h->data)
				{
					tt = temp->data;
					temp->data = h->data;
					h->data = tt;
				}
				h = h->next;
			}
			temp = temp->next;
		}

	}
	void SELECTIONSORT()
	{
		Node* temp = first;
		string tt;

		while (temp->next != NULL)
		{
			Node* min = temp;
			Node* r = temp->next;

			while (r != NULL)
			{
				if (min->data > r->data)
				{
					min = r;
				}
				r = r->next;
			}
			tt = temp->data;
			temp->data = min->data;
			min->data = tt;
			temp = temp->next;
		}

	}
	void DISPLAYLINKLIST()
	{
		Node* temp = first;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
//////////////////////////////Stack implementation/////////////////////////
	void push(medicine m)
	{
		Node2* node = new Node2(m);
		if (isempty1())
		{
			first1 = node;
			last1 = node;
		}
		else
		{
			node->next1 = first1;
			first1 = node;
		}
	}


	void pop()
	{
		Node2* temp = first1;
		while (temp != NULL)
		{
			temp->data1.displaymedicine();
			temp = temp->next1;
		}
	}
	void inorder_display2(Node* t)
	{
		if (t == NULL)
		{
			return;
		}
		else
		{
			inorder_display2(t->left);
			push(t->k);
			inorder_display2(t->right);
		}
	}
	void rev()
	{

		inorder_display2(root);
		for (int i = 0; i < 1; i++)
		{
			pop();
		}

	}





	void insert(medicine mb, Node *node)
	{
		if (mb.name < node->k.name)
		{
			if (node->left == NULL)
			{
				Node* leaf = new Node();
				leaf->k.name = mb.name;
				leaf->k.price = mb.price;
				leaf->k.quantity = mb.quantity;
				leaf->k.date = mb.date;
				node->left = leaf;
			}
			else
			{
				insert(mb, node->left);
			}
		}
		else if (mb.name > node->k.name)
		{
			if (node->right == NULL)
			{
				Node* leaf = new Node();
				leaf->k.name = mb.name;
				leaf->k.price = mb.price;
				leaf->k.quantity = mb.quantity;
				leaf->k.date = mb.date;
				node->right = leaf;
			}
			else
			{
				insert(mb, node->right);
			}
		}
		else
		{
			cout << "Duplicate value found in tree " << endl;
		}
	}
	void insert(medicine mt)
	{
		if (root == NULL)
		{
			Node* leaf = new Node();
			///leaf->data = mt;
		   leaf->k.name = mt.name;
			leaf->k.price = mt.price;
			leaf->k.quantity = mt.quantity;
			leaf->k.date = mt.date;
			root = leaf;
			inserttreetolinklist(mt.name);
		}
		else
		{
			inserttreetolinklist(mt.name);
			insert(mt, root);
		}
	}

	void inorder_display(Node* subroot)
	{
		if (subroot != NULL)
		{
			inorder_display(subroot->left);
			 subroot->k.displaymedicine();
			inorder_display(subroot->right);
		}
	}

	///////////delete function/////////////
	


	void remove(Node*& nn)
	{
		Node* temp;
		if (nn == NULL)
		{
			cout << "cannot delete empty node " << endl;
		}
		else if (nn->right == NULL)
		{
			temp = nn;
			nn = nn->left;
			delete temp;
		}
		else if (nn->left == NULL)
		{
			temp = nn;
			nn = nn->right;
			delete temp;
		}
		else
		{
			temp = nn->right;
			while (temp->left)
			{
				temp = temp->left;
			}
			temp->left = nn->left;
			temp = nn;
			nn = nn->right;
			delete temp;
		}

	}
	void deletenode(string d, Node*& n)
	{
		if (n != NULL)
		{

			if (d < n->k.name)
			{
				deletenode(d, n->left);
			}
			else if (d > n->k.name)
			{
				deletenode(d, n->right);
			}
			else
			{
				remove(n);
				/*if (n->k.date <= 2015)
				{

					
				}
				else
				{
					cout << "CANNOT DELETE BECAUSE DATE WAS EXPIRED NOT:: " << endl;
				}*/
			}
		}
	}
	void delete1(string d)
	{
		deletenode(d, root);
	}
	////////////////////search for just seller/////////////
	void searchseller1(string d, Node* n)

	{

		if (n != NULL)
		{
			if (d < n->k.name)
			{
				searchseller1(d, n->left);
			}
			else if (d > n->k.name)
			{
				searchseller1(d, n->right);
			}
			else
			{

				cout << "FOUND" << endl;
				n->k.displaymedicine();
			}
		}
		else
		{
			cout << "INVALID SEARCH " << endl;
		}

	}
	void searchseller(string s)
	{
		searchseller1(s, root);
	}
	///////////////////////search/////////////////////

	void search1(string d, Node* n)

	{

		if (n != NULL)
		{
			if (d < n->k.name)
			{
				search1(d, n->left);
			}
			else if (d > n->k.name)
			{
				search1(d, n->right);
			}
			else
			{
		
				cout << "FOUND" << endl;
				n->k.displaymedicine();
				cout << endl;
				cout << "=================================================" << endl;
				cout << "AS PRICE OF SINGLE QUANTITY OF THIS MEDICINE :: " << n->k.price << endl;
				cout << "AS THE AVAILABLE QUANTITY OF THIS MEDICINE :: " << n->k.quantity << endl;
				cout << endl;
				cout << "ENTER A QUANTITY OF THIS MEDICINE YOU WANT TO BUY :: " << endl;
				int quan;
				cin >> quan;
			    int a=n->k.price* quan;
			    int final_quantity;
				final_quantity = n->k.quantity - quan;
				cout <<"NOW THE REMIANING QUANTITY OF THIS MEDICINE :: " <<final_quantity<< endl;
				balance(a);
				cout << "=======================" << endl;
				n->k.setquantity(final_quantity);
				if (n->k.getquantity() == 0)
				{
					cout << "NOW THIS MEDICINE ALL STOCK SOLD OUT:: " << endl;
					delete1(n->k.name);
				}
				else
				{
					n->k.displaymedicine();
				}
			}
		}
		else
		{
			cout << "INVALID SEARCH " << endl;
		}

	}
	void search(string s)
	{
		search1(s, root);
	}
	////////////update function//////////////

	void update1(string d, Node* n)
	{
		Node* temp = NULL;
		if (n != NULL)
		{
			if (d < n->k.name)
			{
				update1(d, n->left);
			}
			else if (d > n->k.name)
			{
				update1(d, n->right);
			}
			else
			{
				int a, b, c;
				string nn;
				cout << "Enter the name of updated medicine " << endl;
				cin >> nn;
				cout << "Enter the price of updated medicine " << endl;
				cin >> a;
				cout << "Enter the quantity of updated medicine " << endl;
				cin >> b;
				cout << "Enter the date of updated medicine " << endl;
				cin >> c;
				//string gg;
				n->k.name = nn;
				//gg = n->k.name;
				n->k.price = a;
				n->k.quantity = b;
				n->k.date = c;
				//ttt = n;

				
			/*	delete1(n->k.name);
				insert(ttt->k);*/


			}
		}
		else
		{
			cout << "INVALID REPALCEMENT " << endl;
		}

	}
	void update(string s)
	{
		update1(s, root);
	}
	void inorder_display()
	{
		inorder_display(root);
	}
	////////////////////////////QUEUE//////////////////////
	void enqueue(int v)
	{
		array[rear] = v;
		rear++;

	}
	void  dequeue()
	{
		cout << "A person of id  " << array[front] << " receive medicine firstly " << endl;
		front++;
	}
	void balance(int b)
	{
		int x = 20000;
		cout << "Before buying a medicine your balace is " << x << endl;
		cout << endl;
		cout << "After buying balance " << x - b << endl;

	}
	void customer(int s)
	{
		size = s;
		array = new int[s];
		for (int i = 0; i < s; i++)
		{
			int s;
			cout << "Enter id of customer " << i + 1 << " = ";
			cin >> s;
			enqueue(s);
			cout << "WELCOME TO PHARAMACY ::" << endl;
			cout << endl;
			cout << "FIRST ENTER THE CORRECT ID TO ENTER IN A PHARMACY :: " <<endl;
			int h;
			cin >> h;
			if (h == array[i])
			{
			string ss;
			cout << "Enter a name of medicine you want to buy :: " << endl;
			cout << endl;
			cin >> ss;
			search(ss);


			}
			else
			{
				cout << "invalid id :: " << endl;
			}
		}
			/*string ss;
			cout << "Enter a name of medicine you want to buy :: " << endl;
			cout << endl;
			cin >> ss;
			search(ss);if
			if (a == 1)
			{
				int a, b, c;
				medicine mm(2, 3, 5);
				mm.displaymedicine();

			}*/

		//}
		cout << endl;
		for (int i = 0; i < s; i++)
		{
			dequeue();
		}
	}

};
int main()
{


	int terminator;
	cout << "                                            || **************************************************||" << endl;
	cout << "                                            || **************************************************||" << endl;
	cout << "                                            ||         WELCOME TO PHARMACY MANAGEMENT SYSTEM     || " << endl;
	cout << "                                            || **************************************************||" << endl;
	cout << "                                            || **************************************************||" << endl;
	cout << endl << endl;
	cout << "THE AVAILABLE MEDICINE IN OUR PHARMACY " << endl;
	Tree t;
	medicine m("panadol", 12, 43, 2012);
	t.insert(m);
	medicine m1("dicloran", 12, 43, 2020);
	t.insert(m1);
	medicine m2("nabrol", 12, 43, 2017);
	t.insert(m2);
	medicine m3("desprine", 12, 43, 2005);
	t.insert(m3);
	medicine m4("painkiller", 12, 32, 2021);
	t.insert(m4);
	medicine m5("zameer", 12, 32, 2022);
	t.insert(m5);
	medicine m6("fahad", 12, 32, 2015);
	t.insert(m6);
	t.inorder_display();
	cout << endl << endl;
	cout << "THESE MEDICINES ACCORDING TO BST STRUCTURE " << endl;
	cout << endl << endl;

	cout << endl;
	int algorithm;
	cout << "ENTER 1 IF YOU WANT TO SEE A SELECTION SORT ALGORITHM " << endl;
	cout << "ENTER 2 IF YOU WANT TO SEE A BUUBLE  SORT ALGORITHM " << endl;
	cout << "ENTER 3 IF YOU WANT TO SEE A SORTING OF IN-ORDER IN DESCENDING THROUGH STACK STRUCTURE " << endl;
	cin >> algorithm;
	cout << endl;

	if (algorithm == 1)
	{
		cout << endl;
		cout << "THE DATA OF BST IN A LINK LIST AND THE LIST BEFORE SORTING :: " << endl;
		cout << endl;
		cout << endl;
		t.DISPLAYLINKLIST();
		cout << endl;
		cout << endl;
		cout << "AFTER SELECTION SORTING ::" << endl;
		cout << endl;
		t.SELECTIONSORT();
		t.DISPLAYLINKLIST();
	}
	else if (algorithm == 2)
	{
		cout << endl;
		cout << "THE DATA OF BST IN A LINK LIST AND THE LIST BEFORE SORTING :: " << endl;
		cout << endl;
		cout << endl;
		t.DISPLAYLINKLIST();
		cout << endl;
		cout << endl;
		cout << "AFTER BUBBLE SORTING ::" << endl;
		cout << endl;
		t.BUBBLESORTING();
		t.DISPLAYLINKLIST();
	}
	else if (algorithm == 3)
	{
		cout << endl;
		cout << "BEFORE SORTING::" << endl;
		cout << endl;
		t.inorder_display();
		cout << endl;
		cout << "AFTER SORTING IN A DESCENDING ORDER ::: " << endl;
		t.rev();
		cout << endl;
		cout << endl;
	}
	do {
		cout << endl << endl;
		cout << "ENTER 1 FOR SELLER :: " << endl;
		cout << "ENTER 2 FOR BUYER :: " << endl;
		cout << endl;
		int buyer;
		cin >> buyer;
		cout << endl;
		if (buyer == 2)
		{
			cout << endl;
			cout << endl;
			cout << "======queue =========" << endl;
			int cus;
			cout << endl << endl;
			cout << "How many customer you want to allow " << endl;
			cin >> cus;
			cout << endl;
			t.customer(cus);
			cout << endl;
			cout << endl;
			cout << endl;

		}
		else if (buyer == 1)
		{
			cout << endl;
		cout << endl;
		string del;
		string upd;
		string sea;
		string uppd;
		int a, b, c;
		string nn;
		cout << endl;

		cout << "Enter 1 for delete " << endl;
		cout << "Enter 2 for search " << endl;
		cout << "Enter 3 for update " << endl;
		cout << "Enter 4 for insertion " << endl;
		cout << "Enter 5 to exit " << endl;
		cout << "Enter 6 to display" << endl;

		//int a = 0;
		int at;
		cin >> at;

		switch (at)
		{
		case 5:
			break;
		case 1:
			//cout << "=================================" << t.mbbs.date << endl;
			cout << "Enter a node you want to delete " << endl;
			cin >> del;
		
				t.delete1(del);
				cout << "AFTER DELETION of " << del << " ::" << endl;
				t.inorder_display();
				cout << endl;
			break;
		case 2:


			cout << "Enter a node you want to search " << endl;
			cin >> sea;
			t.searchseller(sea);
			cout << endl;
			break;

		case 6:
			t.inorder_display();
			break;
		case 3:


			cout << "Enter a node you want to update " << endl;
			cin >> upd;
			t.update(upd);
			cout << endl;
			cout << "Now the updated stock is :: " << endl;
			t.inorder_display();
			cout << endl << endl;
			break;


		case 4:


			cout << "Enter a node you want to insert " << endl;
			cout << endl << endl;
			cout << "Enter the name of updated medicine " << endl;
			cin >> nn;
			cout << "Enter the price of updated medicine " << endl;
			cin >> a;
			cout << "Enter the quantity of updated medicine " << endl;
			cin >> b;
			cout << "Enter the date of updated medicine " << endl;
			cin >> c;
			medicine mq(nn, a, b, c);
			t.insert(mq);
			cout << endl;
			cout << "Now the updated stock is :: " << endl;
			t.inorder_display();
			cout << endl << endl;
			break;


		}
	}
		//break;
		cout << endl;
		cout << "Enter -1 to exit " << endl;
		cin >> terminator;
		if (terminator == -1)
		{
			break;
		}
	} while (1);
}




















