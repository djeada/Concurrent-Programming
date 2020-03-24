#include <iostream>
#include <thread>
using namespace std;

void function_1(){
	cout << "Das bist du, mein wunderkeit." << endl;
}

int main(){
	thread t1(function_1);
	//main thead waits for t1 to finish
	t1.join();
	
	//t1 will freely on it own --daemon process
	//t1.detach();
	
	//you can join and detach only onc
	if(t1.joinable())
		t1.join();
	
	return 0;
}
