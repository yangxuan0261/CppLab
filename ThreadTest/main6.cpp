//#include <iostream>     // std::cout
//#include <future>       // std::packaged_task, std::future
//#include <chrono>       // std::chrono::seconds
//#include <thread>       // std::thread, std::this_thread::sleep_for
//
//// count down taking a second for each value:
//int countdown(int from, int to) {
//	for (int i = from; i != to; --i) {
//		std::cout << i << '\n';
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	}
//	std::cout << "Finished!\n";
//	return from - to;
//}
//
//int main()
//{
//	std::packaged_task<int(int, int)> task(countdown); // 设置 packaged_task
//	std::future<int> ret = task.get_future(); // 获得与 packaged_task 共享状态相关联的 future 对象.
//
//	std::thread th(std::move(task), 10, 0);   //创建一个新线程完成计数任务.
//
//	int value = ret.get();                    // 等待任务完成并获取结果.
//
//	std::cout << "The countdown lasted for " << value << " seconds.\n";
//
//	th.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//int main()
//{
//	std::packaged_task<int(int)> foo; // 默认构造函数.
//
//	// 使用 lambda 表达式初始化一个 packaged_task 对象.
//	std::packaged_task<int(int)> bar([](int x){return x * 2; });
//
//	foo = std::move(bar); // move-赋值操作，也是 C++11 中的新特性.
//
//	// 获取与 packaged_task 共享状态相关联的 future 对象.
//	std::future<int> ret = foo.get_future();
//
//	std::thread(std::move(foo), 10).detach(); // 产生线程，调用被包装的任务.
//
//	int value = ret.get(); // 等待任务完成并获取结果.
//	std::cout << "The double of 10 is " << value << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//// 在新线程中启动一个 int(int) packaged_task.
//std::future<int> launcher(std::packaged_task<int(int)>& tsk, int arg)
//{
//	if (tsk.valid()) {
//		std::future<int> ret = tsk.get_future();
//		std::thread(std::move(tsk), arg).detach();
//		return ret;
//	}
//	else return std::future<int>();
//}
//
//int main()
//{
//	std::packaged_task<int(int)> tsk([](int x){return x * 2; });
//
//	std::future<int> fut = launcher(tsk, 25);
//
//	std::cout << "The double of 25 is " << fut.get() << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//int main()
//{
//	std::packaged_task<int(int)> tsk([](int x) { return x * 3; }); // package task
//
//	std::future<int> fut = tsk.get_future();   // 获取 future 对象.
//
//	std::thread(std::move(tsk), 100).detach();   // 生成新线程并调用packaged_task.
//
//	int value = fut.get();                     // 等待任务完成, 并获取结果.
//
//	std::cout << "The triple of 100 is " << value << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//// a simple task:
//int triple(int x) { return x * 3; }
//
//int main()
//{
//	std::packaged_task<int(int)> tsk(triple); // package task
//
//
//	std::future<int> fut = tsk.get_future();
//	std::thread(std::move(tsk), 100).detach();
//	std::cout << "The triple of 100 is " << fut.get() << ".\n";
//
//
//	// re-use same task object:
//	//tsk.reset();
//	//fut = tsk.get_future();
//	//std::thread(std::move(tsk), 200).detach();
//	//std::cout << "Thre triple of 200 is " << fut.get() << ".\n";
//
//	system("pause");
//	return 0;
//}