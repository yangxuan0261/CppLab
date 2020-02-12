//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex
//
//volatile int counter(0); // non-atomic counter
//std::mutex mtx;           // locks access to counter
//
//void attempt_10k_increases() {
//	for (int i = 1; i <= 100; ++i) {
//		if (mtx.try_lock()) {   // only increase if currently not locked:
//			++counter;
//			mtx.unlock();
//		}
//	}
//}
//
//int main(int argc, const char* argv[]) {
//	std::thread threads[10];
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(attempt_10k_increases);
//
//	for (auto& th : threads) th.join();
//	std::cout << counter << " successful increases of the counter.\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <chrono>         // std::chrono::milliseconds
//#include <thread>         // std::thread
//#include <mutex>          // std::timed_mutex
//
//std::timed_mutex mtx;
//volatile int count(0);
//
//void fireworks() {
//	// waiting to get a lock: each thread prints "-" every 200ms:
//	while (!mtx.try_lock_for(std::chrono::milliseconds(200))) {
//		std::cout << "-";
//	}
//	// got a lock! - wait for 1s, then this thread prints "*"
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	count++;
//	std::cout << "* " << count << "\n";
//	mtx.unlock();
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

////#########################################################
//
//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::unique_lock
//
//std::mutex mtx;           // mutex for critical section
//
//void print_block(int n, char c) {
//	// critical section (exclusive access to std::cout signaled by lifetime of lck):
//	std::unique_lock<std::mutex> lck(mtx);
//	for (int i = 0; i < n; ++i) {
//		std::cout << c;
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::thread th1(print_block, 50, '*');
//	std::thread th2(print_block, 50, '$');
//
//	th1.join();
//	th2.join();
//
//	system("pause");
//	return 0;
//}