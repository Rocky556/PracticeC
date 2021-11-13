#include<Stack.h>
#include<Queue.h>

using namespace std;

void display(int a) {
	cout << a << endl;
}

int main() {
	cout << "Õ»:" << endl;
	Stack<int> p;
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	p.forNext(display);

	cout << "¶ÓÁÐ:" << endl;
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.forNext(display);
	system("pause");
}