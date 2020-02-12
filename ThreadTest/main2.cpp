//#include <iostream>
//#include <utility>
//#include <thread>
//#include <chrono>
//#include <functional>
//#include <atomic>
//#include <string>
//
//void f1(int n, std::string str)
//{
//	for (int i = 0; i < 5; ++i) {
//		std::cout << "Thread1 " << n << " - "<<str << " executing\n";
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}
//}
//
//void f2(int& n, std::string& str)
//{
//	for (int i = 0; i < 5; ++i) {
//		std::cout << "Thread2 " << n << " - " << str << " executing\n";
//		++n;
//		str.append("x");
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}
//}
//
//int main()
//{
//	int n = 0;
//	std::thread t1; // t1 is not a thread
//	std::thread t2(f1, n + 1, "aaa"); // pass by value
//	std::string str("bbb");
//	std::thread t3(f2, std::ref(n), std::ref(str)); // pass by reference
//	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
//	t2.join();
//	t4.join();
//	std::cout << "Final value of n is " << n << '\n';
//	std::cout << "Final value of str is " << str << '\n';
//	system("pause");
//}