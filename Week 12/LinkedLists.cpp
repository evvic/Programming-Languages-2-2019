#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class list {
private:
	node* head, * tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}

	void createnode(int value) {
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;


		try {
			if (head == NULL) {
				//in this case the entire list is empty so head = tail = temp (of first created node)
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else {
			tail->next = temp->next; //added the ->next to temp
			tail = temp;
			
			}
		}
		catch (int param) {
			cout << "\nERROR createnode()\n";
		}
	}

	void display() {
		//loops through list till tail pointing to NULL is found, NULL terminates loop
		node* temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	//insert value at head
	void insert_start(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	//inserts value into linked list at any position between head to tail
	void insert_position(int pos, int val) {
		node* pre = new node;
		node* cur = new node;
		node* temp = new node;

		cur = head;

		try {
			for (int i = 0; i < pos; i++) {
				if (cur == NULL) {
					throw 66;
				}
				pre = cur;
				cur = cur->next;
			}
		}
		catch (int p) {
			cout << "\nERROR: " << p << "   insert_position() list.\n";
			cout << "\nCannot insert value to linked list\n";
		}

		temp->data = val;
		pre->next = temp;
		temp->next = cur;
	}

	void delete_first() {
		node* temp = new node;
		temp = head;

		head = head->next;

		delete temp;
	}

	void delete_last() {
		node* cur = new node;
		node* pre = new node;

		cur = head;

		while (cur->next != NULL) {
			pre = cur; //previous = current
			cur = cur->next;
		}

		tail = pre;
		pre->next = NULL;
		delete cur;
	}

	void delete_position(int pos) {
		node* cur = new node;
		node* pre = new node;

		cur = head;

		for (int i = 0; i < pos; i++) {
			pre = cur;
			cur = cur->next;
		}

		pre->next = cur->next;
	}
};

char DisplayMenu();
void PrintTitle(); //holds the text art for title


char AddOptions(list& nums);
char DeleteOptions(list & nums);

int main() {
	list nums;

	char choice;

	PrintTitle();

	do {
		choice = DisplayMenu();

		system("CLS");


		switch (choice) {
		case 'A': //add
			AddOptions(nums);
			break;
		case 'D': //delete
			DeleteOptions(nums);
			break;
		case 'P': //print
			//make prettier with other stuff
			cout << "\n************************************************************";
			cout << "\n*** ";
			nums.display();
			cout << " ***";
			cout << "\n************************************************************\n";
			break;
		case 'Q': //quit
			cout << "\nExiting Program...\n";
			break;
		default:
			cout << "\nSwitch case error.\n";
		}

	} while (choice != 'Q');
}

char DeleteOptions(list & nums) {
	char c;
	int pos = 0;

	do {
		system("CLS");

		cout << "\n\n\tDeleting an integer from the list.";
		cout << "\n\t\t-'h' Head"
			<< "\n\t\t-'t' Tail"
			<< "\n\t\t-'i' Insert"
			<< "\n\t\t-'q' Quit"
			<< "\n\n\t\t> ";
		cin >> c;

		c = toupper(c);
	} while (c != 'H' && c != 'T' && c != 'I' && c != 'Q');

	switch (c) {
	case 'H': //head
		nums.delete_first();
		cout << "\n\tDeleted the first on list.";
		break;
	case 'T': //tail
		nums.delete_last();
		cout << "\n\tDeleted the last on list.";
		break;
	case 'I': //insert

		try {
			do {
				while (cout << "\n\tPosition in list: " && !(cin >> pos)) {
					cin.clear();
					cin.ignore();
					throw 'e';
				}
			} while (false); //user entered val should be anything they want as long as its an int
		}
		catch (char param) {
			cout << "\nDeleteOptions error. Can only enter an integer data type.\n";
			cout << "throw " << param << endl;
		}
		nums.delete_position(pos);
		cout << "\n\tDeleted a value in list at position " << pos << '.';
		break;
	case 'Q':
		cout << "\nBack to main menu...\n";
		break;
	default:
		cout << "Error with switch in AddOptions()";
		break;
	}

	return c;	return c;
}

char AddOptions(list & nums) {
	char c;
	int val, pos = 0;

	do {
		system("CLS");

		cout << "\n\n\tAdding an integer to the list.";
		cout << "\n\t\t-'h' Head"
			<< "\n\t\t-'t' Tail"
			<< "\n\t\t-'i' Insert"
			<< "\n\t\t-'q' Quit"
			<< "\n\n\t\t> ";
		cin >> c;

		c = toupper(c);
	} while (c != 'H' && c != 'T' && c != 'I' && c != 'Q');
	
	try {
		do {
			while (cout << "\n\n\tInteger value: " && !(cin >> val)) {
				cin.clear();
				cin.ignore();
				throw 'e';
			}
		} while (false); //user entered val should be anything they want as long as its an int
	}
	catch (char p) {
		cout << "\nAddOptions error. Can only enter an integer data type.\n";
		cout << "throw " << p << endl;
	}

	switch (c) {
	case 'H': //head
		nums.insert_start(val);
		cout << "\n\tInserted " << val << " into start of list.";
		break;
	case 'T': //tail
		nums.createnode(val);
		cout << "\n\tInserted " << val << " into end of list.";
		break;
	case 'I': //insert

		try {
			do {
				while (cout << "\n\tPosition in list: " && !(cin >> pos)) {
					cin.clear();
					cin.ignore();
					throw 'e';
				}
			} while (false); //user entered val should be anything they want as long as its an int
		}
		catch (char param) {
			cout << "\nAddOptions error. Can only enter an integer data type.\n";
			cout << "throw " << param << endl;
		}
		nums.insert_position(pos, val);
		cout << "\n\tInserted " << val << " into list at position " << pos << '.';
		break;
	case 'Q': 
		cout << "\nBack to main menu...\n";
		break;
	default:
		cout << "Error with switch in AddOptions()";
		break;
	}

	return c;
}

char DisplayMenu() {

	char choice;

	cout << endl << endl;
	cout << "\n\tEdit keys: ";
	cout << "\n\t\t-'a' add";
	cout << "\n\t\t-'d' delete";
	cout << "\n\t\t-'p' print list";
	cout << "\n\t\t-'q' quit";
	cout << "\n\n\t\t> ";
	do {
		cin >> choice;
		choice = toupper(choice);

	} while (choice != 'A' && choice != 'D' && choice != 'P' && choice != 'Q');

	return choice;

}

void PrintTitle() {
	string title[] = {
"		 _     _       _            _   _     _     _",
"| |   (_)     | |          | | | |   (_)   | |",
"| |    _ _ __ | | _____  __| | | |    _ ___| |_ ___",
"| |   | | '_ \\| |/ / _ \\/ _` | | |   | / __| __/ __|",
"| |___| | | | | < __ / (_| | | |___ | \\__ \\ | _\\__ \\",
"\\_____ / _ | _| |_ | _ | \\_\\___ | \\__,_ | \\_____ / _ | ___ / \\__ | ___ /",
""
	};

	for (int i = 0; title[i] != ""; i++) {
		cout << title[i] << endl;
	}
}