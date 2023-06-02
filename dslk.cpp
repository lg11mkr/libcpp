#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct NODE {
	int data;
	NODE* next;
};

struct List {
	NODE* head = NULL;
	NODE* tail = NULL;
};

int Length(List l)
{
	int count = 0;
	NODE* NODE = l.head;
	while (NODE != NULL)
	{
		count++;
		NODE = NODE->next;
	}
	return count;
}
// -----------------co-ban------------------------------------------
NODE* createNode(int val) {
	NODE* nod = new NODE;
	nod->data = val;
	nod->next = NULL;
	return nod;
}
void addTail(List& l, int val)
{
	NODE* NODE = createNode(val);
	if (l.head == NULL)
	{
		l.head = NODE;
		l.tail = NODE;
	}
	else
	{
		l.tail->next = NODE;
		l.tail = NODE;
	}
}
void addHead(List& l, int val)
{
	NODE* NODE = createNode(val);
	if (l.head == NULL)
	{
		l.head = NODE;
		l.tail = NODE;
	}
	else
	{
		NODE->next = l.head;
		l.head = NODE;
	}
}
void Print(List l) {
	NODE* NODE = l.head;
	cout << "Linked list: \t";
	while (NODE != NULL) {
		cout << NODE->data << " ";
		NODE = NODE->next;
	}
	cout << endl;
}
void del(List& l) {
    NODE* p = l.head;
    while (p != NULL) {
        NODE* temp = p;
        l.head = p->next;
        p = l.head;
        delete temp;  // Giải phóng bộ nhớ của node hiện tại
    }
    l.tail = NULL;  // Không cần gán l.head = NULL nếu đã gán l.tail = NULL
}
void insertAfter(List& l, NODE* des, int val) {
    if (des == NULL) {
        // Nếu des là NULL, không thể chèn sau một node không tồn tại
        return;
    }

    NODE* newNode = createNode(val);
    newNode->next = des->next;
    des->next = newNode;

    if (des == l.tail) {
        l.tail = newNode;
    }
}


void removeNode(List& l, int a) {
    NODE* curr = l.head;
    NODE* pre = NULL;

    while (curr != NULL) {
        if (curr->data == a) {
            if (pre == NULL) {
                l.head = curr->next;
                if (l.tail == curr) {
                    l.tail = NULL;
                }
            } else {
                pre->next = curr->next;
                if (l.tail == curr) {
                    l.tail = pre;
                }
            }
            NODE* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
}

void insertNode(List& l, int a, int k) {
    if (k == 0) {
        NODE* newNode = createNode(a);
        newNode->next = l.head;
        l.head = newNode;
        if (l.tail == NULL) {
            l.tail = newNode;
        }
    } else {
        NODE* curr = l.head;
        for (int i = 0; i < k - 1 && curr != NULL; i++) {
            curr = curr->next;
        }
        if (curr != NULL) {
            NODE* newNode = createNode(a);
            newNode->next = curr->next;
            curr->next = newNode;
            if (curr == l.tail) {
                l.tail = newNode;
            }
        }
    }
}


int main() {
	int k;
	List l;

	return 0;
}
