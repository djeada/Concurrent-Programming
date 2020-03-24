#include <iostream>
#include <thread>
#include <future>
using namespace std;

void helloworld()
{
	cout << "hello world" << endl;
}

class Fctor {
public:
	void operator()(string msg) {
		for (int i = 0; i > -10; i--) {
			cout << msg << i << endl;
		}
	}

};

int main(){	
	Fctor fct;
	string msg = "Elo";
	thread t1((fct),msg);
	thread t2(helloworld);
	try {
	
		for (int i = 0; i < 10; i++) {
			cout << "this is main thread" << endl;
		}

	}
	catch (...) {
		t1.join();
		t2.join();
		throw;
	}
	t1.join();
	t2.join();
	
	return 0;
}
