//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock
//
//std::mutex mtx;           // mutex for critical section
//
//void print_thread_id(int id) {
//	mtx.lock();
//	std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
//	std::cout << "thread #" << id << '\n';
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(print_thread_id, i + 1);
//
//	for (auto& th : threads) th.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::lock_guard
//#include <stdexcept>      // std::logic_error
//
//std::mutex mtx;
//
//void print_even(int x) {
//	if (x % 2 == 0) std::cout << x << " is even\n";
//	else throw (std::logic_error("not even"));
//}
//
//void print_thread_id(int id) {
//	try {
//		// using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
//		std::lock_guard<std::mutex> lck(mtx);
//		print_even(id);
//	}
//	catch (std::logic_error& str) {
//		std::cout << str.what()  << " - [exception caught]\n";
//	}
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(print_thread_id, i + 1);
//
//	for (auto& th : threads) th.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::lock, std::unique_lock
//// std::adopt_lock, std::defer_lock
//std::mutex foo, bar;
//
//void task_a() {
//	std::lock(foo, bar);         // simultaneous lock (prevents deadlock)
//	std::unique_lock<std::mutex> lck1(foo, std::adopt_lock);
//	std::unique_lock<std::mutex> lck2(bar, std::adopt_lock);
//	for (size_t i = 0; i < 5; i++)
//	{
//		std::cout << i << " - task aaa\n";
//	}
//	// (unlocked automatically on destruction of lck1 and lck2)
//}
//
//void task_b() {
//	// foo.lock(); bar.lock(); // replaced by:
//	std::unique_lock<std::mutex> lck1, lck2;
//	lck1 = std::unique_lock<std::mutex>(bar, std::defer_lock);
//	lck2 = std::unique_lock<std::mutex>(foo, std::defer_lock);
//	std::lock(lck1, lck2);       // simultaneous lock (prevents deadlock)
//	for (size_t i = 0; i < 5; i++)
//	{
//		std::cout << i <<" - task bbb\n";
//	}
//	// (unlocked automatically on destruction of lck1 and lck2)
//}
//
//
//int main()
//{
//	std::thread th1(task_a);
//	std::thread th2(task_b);
//
//	th1.join();
//	th2.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::unique_lock
//
//std::mutex mtx;           // mutex for critical section
//
//void print_fifty(char c) {
//	std::unique_lock<std::mutex> lck;         // default-constructed
//	lck = std::unique_lock<std::mutex>(mtx);  // move-assigned
//	for (int i = 0; i < 50; ++i) { std::cout << c; }
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::thread th1(print_fifty, '*');
//	std::thread th2(print_fifty, '$');
//
//	th1.join();
//	th2.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//// unique_lock::lock/unlock
//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock
//
//std::mutex mtx;           // mutex for critical section
//
//void print_thread_id(int id) {
//	std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
//	// critical section (exclusive access to std::cout signaled by locking lck):
//	lck.lock();
//	std::cout << "thread #" << id << '\n';
//	lck.unlock();
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(print_thread_id, i + 1);
//
//	for (auto& th : threads) th.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <vector>         // std::vector
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock
//
//std::mutex mtx;           // mutex for critical section
//
//void print_star() {
//	std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
//	// print '*' if successfully locked, 'x' otherwise: 
//	if (lck.try_lock())
//		std::cout << '*';
//	else
//		std::cout << 'x';
//}
//
//int main()
//{
//	std::vector<std::thread> threads;
//	for (int i = 0; i < 500; ++i)
//		threads.emplace_back(print_star);
//
//	for (auto& x : threads) x.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <chrono>         // std::chrono::milliseconds
//#include <thread>         // std::thread
//#include <mutex>          // std::timed_mutex, std::unique_lock, std::defer_lock
//
//std::timed_mutex mtx;
//
//void fireworks() {
//	std::unique_lock<std::timed_mutex> lck(mtx, std::defer_lock);
//	// waiting to get a lock: each thread prints "-" every 200ms:
//	while (!lck.try_lock_for(std::chrono::milliseconds(200))) {
//		std::cout << "-";
//	}
//	// got a lock! - wait for 1s, then this thread prints "*"
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	std::cout << "*\n";
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(fireworks);
//
//	for (auto& th : threads) th.join();
//
//	system("pause");
//	return 0;
//}