//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <map>
//#include <vector>
//#include <array>
//#include <algorithm>
//#include <numeric>
//#include <utility>
//#include <list>
//#include <queue>
//#include <functional>
//#include <time.h>
//#include <random>
//#include <unordered_map>
//#include <cstring>
//#include <tr1/functional>
//
//
//namespace STLtest {
//
////lambda表达式 输出vector
//    auto printVec = [](const std::vector<int> &_vec) {
//        int index = 0;
//        std::for_each(_vec.begin(), _vec.end(),
//                      [&index](int value) {
//                          printf("--- index:%d, value:%d\n", index, value);
//                          index++;
//                      });
//        printf("\n");
//    };
//
//    auto printMap = [](const std::map<int, std::string> &_map) {
//        for (auto iter = _map.begin(); iter != _map.end(); iter++)
//            printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//        printf("\n");
//    };
//
//    class Person {
//    public:
//        Person(int _age, std::string _name) : mName(""), mAge(0) {
//            mAge = _age;
//            mName = _name;
//        }
//
//        virtual ~Person() {}
//
//        //重写==操作符
//        bool operator==(const Person &ps) const {
//            return ps.mAge == mAge ? true : false;
//        }
//
//        bool operator<(const Person &ps) const {
//            return mAge > ps.mAge ? true : false;
//        }
//
//        void operator()() const {
//            printf("------------ operator(), name:%s\n", mName.c_str());
//        }
//
//        void ShowName() const { printf("--- name:%s, age:%d\n", mName.c_str(), mAge); }
//
//    public:
//        std::string mName;
//        int mAge;
//    };
//
//    void testSTLVec() {
//        //lambda表达式 输出vector
//        auto printVec = [](std::vector<int> &_vec) {
//            int index = 0;
//            std::for_each(_vec.begin(), _vec.end(),
//                          [&index](int value) {
//                              printf("--- index:%d, value:%d\n", index, value);
//                              index++;
//                          });
//        };
//
//        std::vector<int> vec = {100, 2, 30, 4, 5, 6, 17, 8, 39};
//
//        printVec(vec);
//        printf("--- \n");
//
//        //std::stable_sort使用
//        //std::sort()与std::stable_sort() ,原理都是快速排序,
//        //区别是stable_sort函数遇到两个数相等时，不对其交换顺序，也就是是稳定排序
//        std::stable_sort(std::begin(vec), std::end(vec));
//
//        printVec(vec);
//        printf("--- \n");
//
//        //std::find使用 vec中是基础数据int
//        auto iter = std::find(vec.begin(), vec.end(), 101);
//        if (iter != vec.end())
//            printf("--- find dest num:%d\n", *iter);
//        else
//            printf("--- not find\n");
//
//        printf("--- \n");
//
//        //lambda表达式 输出vector
//        auto printVecPs = [](std::vector<Person> &_vec) {
//            int index = 0;
//            std::for_each(_vec.begin(), _vec.end(),
//                          [&index](Person &value) {
//                              printf("--- index:%d, name:%s, age:%d\n", index, value.mName.c_str(), value.mAge);
//                              index++;
//                          });
//        };
//
//        //std::find使用 vec中是自动义类
//        Person p1(12, "aaa");
//        Person p2(65, "bbb");
//        Person p3(78, "ccc");
//        Person p4(26, "ddd");
//        Person p5(34, "eee");
//        std::vector<Person> vecPs = {p1, p2, p3, p4, p5};
//
//        printVecPs(vecPs);
//        printf("--- \n");
//
//        Person p6(78, "www");
//
//        //std::find使用 vec中是类
//        auto iterPs = std::find(vecPs.begin(), vecPs.end(), p6);
//        if (iterPs != vecPs.end())
//            printf("--- find dest Pserson name:%s, age:%d\n", (*iterPs).mName.c_str(), (*iterPs).mAge);
//        else
//            printf("--- not find\n");
//
//        printf("--- \n");
//
//        //排序一下 lambda版
//        //std::stable_sort(std::begin(vecPs), std::end(vecPs),
//        //	[](const Person& _a,const Person& _b)
//        //{
//        //	if (_a.mAge > _b.mAge)
//        //		return true;
//        //	else
//        //		return false;
//        //}
//        //	);
//        //	printVecPs(vecPs);
//
//        //排序一下 重写<操作符版
//        std::stable_sort(std::begin(vecPs), std::end(vecPs));
//        printVecPs(vecPs);
//    }
//
//    void testSTLMap() {
//        //lambda表达式 输出map
//        auto printMap = [](std::map<int, std::string> &_map) {
//            for (auto iter = _map.begin(); iter != _map.end(); iter++)
//                printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//        };
//
//        //std::make_pair 在头文件<utility>中
//        std::map<int, std::string> myMap;
//        myMap.insert(std::make_pair(3, "aaa"));
//        myMap.insert(std::make_pair(2, "bbb"));
//        myMap.insert(std::make_pair(5, "ccc"));
//        myMap.insert(std::make_pair(8, "ddd"));
//
//        printMap(myMap);
//    }
//
//    void testVecDel() {
//        std::vector<int> vec = {};
//        for (size_t i = 0; i < 10; i++)
//            vec.push_back(i);
//
//        printVec(vec);
//        printf("--- \n");
//
//        //删除元素
//        for (auto iter = vec.begin(); iter != vec.end();) {
//            if (*iter > 4 && *iter < 8)
//                iter = vec.erase(iter);
//            else
//                ++iter;
//        }
//
//        printVec(vec);
//        printf("--- \n");
//    }
//
//    void testMapDel() {
//        //lambda表达式 输出map
//        auto printMap = [](std::map<int, int> &_map) {
//            for (auto iter = _map.begin(); iter != _map.end(); iter++)
//                printf("--- key:%d, value:%d\n", iter->first, iter->second);
//        };
//
//        std::map<int, int> tmpMap;
//        tmpMap.clear();
//        for (size_t i = 0; i < 10; i++)
//            tmpMap.insert(std::make_pair(i, i));
//
//        printMap(tmpMap);
//        printf("--- \n");
//
//        for (auto iter = tmpMap.begin(); iter != tmpMap.end();) {
//            if (iter->first > 4 && iter->first < 8)
//                iter = tmpMap.erase(iter);
//            else
//                ++iter;
//        }
//
//        printMap(tmpMap);
//    }
//
//    void testInsertVector() {
//        std::vector<int> numVec = {};
//        numVec.push_back(1);
//        numVec.push_back(2);
//        numVec.push_back(3);
//        printVec(numVec);
//        printf("\n");
//
//        auto iter = numVec.begin();
//        numVec.insert(iter + 0, 99); //插入单个元素
//        iter = numVec.begin();
//        numVec.insert(iter + 3, 88);//插入单个元素
//        printVec(numVec);
//        printf("\n");
//
//        std::vector<int> tmp = {-1, -2, -3};
//        numVec.insert(numVec.begin() + 3, tmp.begin(), tmp.end()); //插入区间
//        printVec(numVec);
//    }
//
//    void testList() {
//        auto func = [](const std::list<int> &_list) {
//            for (auto iter = _list.begin(); iter != _list.end(); iter++)
//                printf("%d ", (*iter));
//            printf("\n");
//        };
//
//        std::list<int> tmplist = {5, 7, 2, 4, 9, 7};
//        func(tmplist);
//        printf("--- list size:%d\n", tmplist.size());
//
//        //tmplist.remove(7); //list在标准容器比较特殊，remove后不需要erase，实际大小也会变更
//        //func(tmplist);
//        //printf("--- list size:%d\n", tmplist.size());
//
//        //删除符合条件的元素
//        //tmplist.remove_if([](const int& _src)->bool{ return _src == 7 ? true : false; });
//        //func(tmplist);
//        //printf("--- list size:%d\n", tmplist.size());
//
//        //只会找到第一个iter
//        //auto iter = std::find_if(tmplist.begin(), tmplist.end(), [](const int& _src)->bool{ return _src == 7 ? true : false; });
//        //tmplist.erase(iter);
//        //func(tmplist);
//        //printf("--- list size:%d\n", tmplist.size());
//
//        std::stable_sort(tmplist.begin(), tmplist.end(),
//                         [](const int &_a, const int &_b) { return _a > _b ? true : false; });
//        func(tmplist);
//        printf("--- list size:%d\n", tmplist.size());
//    }
//
//    void testVecInsert() {
//        int data[5] = {1, 2, 3, 4, 5};
//        std::vector<int> vec;
//        vec.insert(vec.begin(), data, data + 5);
//        printVec(vec);
//
//        std::vector<int> vec2;
//        vec2.insert(vec2.begin(), vec.begin(), vec.end()); //插入一个区间
//        vec2.insert(vec2.begin() + 2, 100); //插入单个元素
//        printVec(vec2);
//
//        bool b = std::binary_search(vec.begin(), vec.end(), 0);
//        std::cout << "--- find result : " << b << std::endl;
//    }
//
//    void testPartialSort() {
//        std::vector<int> values = {5, 6, 2, 7, 4, 1, 8, 9, 0, 3};
//        printVec(values);
//
//        std::partial_sort(values.begin(), // 把队列中最好的3个元素
//                          values.begin() + 3, // （按顺序）放在values的前端
//                          values.end(),
//                          [](const int &_a, const int &_b) -> bool //数组中两个元素的判断，传两个参数
//                          {
//                              return _a > _b ? true : false;
//                          });
//
//        printVec(values);
//    }
//
//    void testNth_element() {
//        std::vector<int> values = {5, 6, 2, 7, 4, 1, 8, 9, 0, 3};
//        printVec(values);
//
//        std::nth_element(values.begin(), // 把队列中最好的3个元素
//                         values.begin() + 3, // （不按顺序）放在values的前端
//                         values.end(),
//                         [](const int &_a, const int &_b) -> bool //数组中两个元素的判断，传两个参数
//                         {
//                             return _a > _b ? true : false;
//                         });
//
//        printVec(values);
//    }
//
//
//    void testPartition() {
//        std::vector<int> values = {5, 6, 2, 7, 4, 1, 8, 9, 0, 3};
//        printVec(values);
//
//        //把所有满足>3的排到队列前端，返回 iter 是不满足>3的第一个迭代器，所以遍历时遍历到 != iter即可
//        auto iter = std::partition(values.begin(), //
//                                   values.end(),
//                                   [](const int &_a) -> bool //数组中单个元素对特别判断，只传一个参数
//                                   {
//                                       return _a > 3 ? true : false;
//                                   });
//
//        for (auto iter2 = values.begin(); iter2 != iter; iter2++)
//            printf("--- value:%d\n", *iter2);
//    }
//
//    void testRemoveAndErase() {
//        std::vector<int> values = {5, 6, 2, 7, 4, 1, 8, 9, 0, 3};
//        printVec(values);
//        printf("--- size:%d\n", values.size());
//
//        int beDelNum = 99;
//        values[3] = values[5] = values[8] = beDelNum;
//        auto iter = std::remove(values.begin(), values.end(), beDelNum);
//
//        values.erase(iter, values.end());
//        printVec(values);
//        printf("--- size:%d\n", values.size());
//    }
//
//    void testSearch() {
//        auto cmpFunc = [](const int &a, const int &b) -> bool {
//            return a < b ? true : false;
//        };
//
//        auto printIter = [](const std::vector<int> &_vec, const std::vector<int>::iterator &_iter) {
//            for (auto iter = _vec.begin(); iter != _iter; iter++)
//                printf("--- value:%d\n", (*iter));
//        };
//
//        std::vector<int> values = {5, 6, 2, 7, 4, 1, 8, 4, 4, 9, 4, 0, 3, 4};
//        std::stable_sort(values.begin(), values.end(), cmpFunc);
//        printVec(values); //先进行升序排序
//
//        //lower_bound 返回第一个不符合条件的迭代器， 指向4
//        auto iter = std::lower_bound(values.begin(), values.end(), 4, cmpFunc);
//        printf("----- *iter value:%d\n", *iter);
//        printIter(values, iter);
//        printf("\n");
//
//        //upper_bound 返回最后一个符合条件的迭代器的下一个迭代器，指向 5
//        auto iter2 = std::upper_bound(values.begin(), values.end(), 4, cmpFunc);
//        printf("----- *iter2 value:%d\n", *iter2);
//        printIter(values, iter2);
//        printf("\n");
//
//        //equal_range 返回 lower_bound 和 upper_bound 的迭代器
//        auto aaapair = std::equal_range(values.begin(), values.end(), 4, cmpFunc);
//        int dist = distance(aaapair.first, aaapair.second);
//        std::for_each(aaapair.first, aaapair.second,
//                      [](const int &num) {
//                          printf("--- num:%d\n", num);
//                      });
//        printf("\n");
//
//        bool exist = std::binary_search(values.begin(), values.end(), 4, cmpFunc);
//        if (exist)
//            printf("--- exist\n");
//        else
//            printf("--- not exist\n");
//        printf("\n");
//
//        printf("--- erase some date\n");
//        //values.erase(values.begin(), iter);
//        values.erase(values.begin(), iter2);
//        printVec(values);
//    }
//
//    void testSearchForMap() {
//        std::map<int, std::string> datas;
//        datas.insert(std::make_pair(5, "aaa"));
//        datas.insert(std::make_pair(3, "bbb"));
//        datas.insert(std::make_pair(8, "ccc"));
//        datas.insert(std::make_pair(7, "ddd"));
//        datas.insert(std::make_pair(1, "eee"));
//
//        std::for_each(datas.begin(), datas.end(),
//                      [](const std::pair<int, std::string> &iter) {
//                          std::cout << iter.first << "\t" << iter.second << std::endl;
//                      });
//        printf("\n");
//
//        printf("--- map lower_bound 3\n");
//        auto iter1 = datas.lower_bound(3); // 指向3
//        printf("--- iter1.first:%d\n", iter1->first);
//        for (auto iter = datas.begin(); iter != iter1; iter++)
//            std::cout << iter->first << "\t" << iter->second << std::endl;
//        printf("\n");
//
//        printf("--- map upper_bound 7\n");
//        auto iter2 = datas.upper_bound(7); //指向7
//        for (auto iter = datas.begin(); iter != iter2; iter++)
//            std::cout << iter->first << "\t" << iter->second << std::endl;
//        printf("\n");
//
//        printf("--- map lower_bound 3 upper_bound 7\n");
//        for (auto iter = iter1; iter != iter2; iter++)
//            std::cout << iter->first << "\t" << iter->second << std::endl;
//        printf("\n");
//    }
//
////有序序列归并
//    void testMerge() {
//        auto cmpFunc = [](const int &a, const int &b) -> bool {
//            return a < b ? true : false;
//        };
//
//        std::vector<int> v1 = {7, 5, 9};
//        std::vector<int> v2 = {4, 8, 6};
//        std::stable_sort(v1.begin(), v1.end(), cmpFunc);
//        std::stable_sort(v2.begin(), v2.end(), cmpFunc);
//
//        std::vector<int> v3(v1.size() + v2.size());
//        std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//        printVec(v3);
//    }
//
//    void ppfunctest(const Person *_p) {
//        _p->ShowName();
//    }
//
//    void testMemFun() {
//        Person *p1 = new Person(111, "aaa");
//        Person *p2 = new Person(222, "bbb");
//        Person *p3 = new Person(333, "ccc");
//
//        //需要include <functional>
//        std::vector<Person *> perVec = {p1, p2, p3};
//
//        //ptr_fun
//        std::for_each(perVec.begin(), perVec.end(), std::ptr_fun(ppfunctest));
//        printf("\n");
//
//        //vec中是指针对象时使用mem_fun
//        std::for_each(perVec.begin(), perVec.end(), std::mem_fun(&Person::ShowName));
//        printf("\n");
//
//        //vec中是实体对象时使用mem_fun_ref
//        std::vector<Person> perVec2 = {*p1, *p2, *p3};
//        std::for_each(perVec2.begin(), perVec2.end(), std::mem_fun_ref(&Person::ShowName));
//    }
//
//    void testbind1stAndBind2nd() {
//        std::vector<int> coll;
//        for (int i = 1; i <= 10; ++i)
//            coll.push_back(i);
//
//        /*
//        简单的说，bind1st(const Operation& op, const T& x)就是这么一个操作：value op x，
//        而bind2nd(const Operation& op, const T& x)就是这么一个操作：x op value，
//        其中value是被应用bind的对象。这两个配接器都用于将一个二元算子转换成一个一元算子。
//        */
//
//        //查找元素值大于10的元素的个数
//        //也就是使得10 < elem成立的元素个数
//        int res = std::count_if(coll.begin(), coll.end(), std::bind1st(std::less<int>(), 10));
//        printf("--- res:%d\n", res); //0
//
//        //查找元素值小于10的元素的个数
//        //也就是使得elem < 10成立的元素个数
//        res = std::count_if(coll.begin(), coll.end(), std::bind2nd(std::less<int>(), 10));
//        printf("--- res:%d\n", res);  //9
//
//        //还不如自己实现的lambda表达式来的清晰
//        res = std::count_if(coll.begin(), coll.end(), [&](const int &a) -> bool { return 10 > a ? true : false; });
//        printf("--- res:%d\n", res);  //9
//    }
//
//    void testTransform() {
//        std::vector<int> src = {1, 2, 3, 4, 5}; // 建立本地数组，
//        std::vector<int> d = {10, 11, 12};
//
//        //把data中头五个元素移到d前段，并且data中的所有元素都 + 41
//
//        std::transform(src.begin(), src.begin() + 5,
//                       std::inserter(d, d.begin() + 1),//插入到d指定位置
//                //std::back_inserter(d), //插入到d尾部
//                       std::bind2nd(std::plus<int>(), 40));  //需要include <functional>
//        printVec(d);
//    }
//
//    void testFindIfRemoveIfReplaceIf() {
//        //但凡带_if的都是可以指定自定义的函数，大部分情况下都是比较函数，return true or false
//
//        int findNum = 6;
//        std::vector<int> values = {2, 6, 2, 7, 4, 1, 8, 9, 0, 2};
//        printf("--- size:%d\n", values.size());
//
//        //查找第一个符合条件的对象
//        auto iter = std::find_if(values.begin(), values.end(),
//                                 [&](const int &_src) -> bool { return _src == findNum ? true : false; });
//        if (iter != values.end())
//            printf("--- find:%d\n", *iter);
//        else
//            printf("--- not find\n");
//        printf("\n");
//
//        int srcNum = 2;
//        int dstNum = 99; //把符合条件的都替换掉
//        std::replace_if(values.begin(), values.end(),
//                        [&](const int &_src) -> bool { return _src == srcNum ? true : false; }, dstNum);
//        printVec(values);
//        printf("\n");
//
//        int delNum = dstNum; //把符合条件的都删除掉
//        auto iter2 = std::remove_if(values.begin(), values.end(),
//                                    [&](const int &_src) -> bool { return _src == delNum ? true : false; });
//        values.erase(iter2, values.end());
//        printf("--- size:%d\n", values.size());
//        printVec(values);
//    }
//
//    void testBinarysearch() {
//        auto printPer = [](const Person *_p) { _p->ShowName(); };
//        auto sortFunc = [](const Person *_p1, const Person *_p2) -> bool {
//            return _p1->mAge > _p2->mAge ? true : false;
//        };
//
//        Person *p0 = new Person(5, "aaa");
//        Person *p1 = new Person(3, "bbb");
//        Person *p2 = new Person(1, "ccc");
//        Person *p3 = new Person(0, "ddd");
//        Person *p4 = new Person(6, "eee");
//        Person *p5 = new Person(2, "fff");
//        Person *p6 = new Person(7, "ggg");
//        Person *p7 = new Person(4, "hhh");
//        Person *p8 = new Person(9, "iii");
//        Person *p9 = new Person(8, "jjj");
//        Person *p10 = new Person(100, "zzz");
//        std::vector<Person *> perVec = {p0, p1, p2, p3, p4, p5, p6, p7, p8, p9};
//
//        std::for_each(perVec.begin(), perVec.end(), printPer);
//        printf("\n");
//        std::stable_sort(perVec.begin(), perVec.end(), sortFunc); //按指定比较函数排序
//        std::for_each(perVec.begin(), perVec.end(), printPer);
//        printf("\n");
//
//        bool b = std::binary_search(perVec.begin(), perVec.end(), p10, sortFunc); //指定函数必须与排序的函数一致
//        if (b)
//            printf("--- find\n");
//        else
//            printf("--- not find\n");
//
//        (*p10)();//调用重写操作符()
//    }
//
//    void testShinkToFit() {
//        std::vector<int> vec3;
//        vec3.reserve(100);
//        printf("--- vec3 size1:%d\n", vec3.capacity());
//        vec3.push_back(1);
//        vec3.push_back(1);
//        vec3.push_back(1);
//        std::vector<int>(vec3).swap(vec3); //给容器容量瘦身到size大小
//        printf("--- vec3 size2:%d\n", vec3.capacity());
//    }
//
//    void testArr() {
//        //std::array<int, 5> arr1; //全部值未初始化
//        //std::array<int, 5> arr1 = { 1 }; //第一个初始化为1，其余全部为0
//        std::array<int, 5> arr1 = {20, 1, 1, 10, 1}; //全部初始化为1
//        printf("--- arr1 size : %d, addr:0x%x\n", sizeof(arr1), &arr1);
//        printf("--- arr1 first element:%d\n", arr1);
//        printf("--- arr1[3] element:%d\n", arr1[3]);
//
//        //std::for_each(arr1.begin(), arr1.end(),
//        //	[](const int& num)
//        //{
//        //	printf("--- value:%d\n", num);
//        //});
//
//        std::array<int, 5> arr2 = arr1; //全部初始化为1
//        printf("--- arr2 size : %d, addr:0x%x\n", sizeof(arr2), &arr2);
//    }
//
////队列中元素累计
//    void testAccumulate() {
//        std::vector<int> values = {5, 6, 2};
//        //int sum = accumulate(values.begin(), values.end(), 3, std::multiplies<int>());
//        int sum = std::accumulate(values.begin(), values.end(), 0, //ps: accumulate在<numeric>头文件中
//                                  [](const int &_a, const int &_b) -> int {
//                                      return _a + _b;
//                                  });
//        printf("--- sum:%d\n", sum);
//    }
//
//    void testInnerProduct() {
//        auto myaccumulator = [](int x, int y) -> int { return x - y; };
//        auto myproduct = [](int x, int y) -> int { return x + y; };
//
//        int init = 100;
//        std::vector<int> series1 = {10, 20, 30};
//        std::vector<int> series2 = {1, 2, 3};
//
//        //  操作前:[beg1,end1)和[beg2,...)标示输入序列.init是第一个参与运算的值.
//        //  操作后:计算init依次加两个输入序列各自对应元素的乘积.
//        //  返回值:计算所得的值.
//        //  备注:     init是第一个参与运算的元素.init的类型决定返回值的类型.
//        //                  [beg2,...)序列至少同[beg1,end1)序列一样大.否则将抛出异常.
//        //                  [beg2,...)中超出[beg1,end1)长度的序列不参与运算.
//        //10*1 + 20*2 + 30*3 + 100 = 240;
//        std::cout << "--- using default inner_product: ";
//        std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init);
//        std::cout << '\n'; //240
//
//        //  inner_product (beg1, end1, beg2, init, minus<int> (), divides<int> ()) ;
//        //  操作前:[beg1,end1)和[beg2,...)标示输入序列.init是第一个参与运算的值.minus<int> ()和divides<int> ()是二元函数对象.
//        //  操作后:计算init依次加两个输入序列各自对应元素的乘积.
//        //  返回值:计算所得的值.
//        //  备注:     init是第一个参与运算的元素.init的类型决定返回值的类型.
//        //                  [beg2,...)序列至少同[beg1,end1)序列一样大.否则将抛出异常.
//        //                  [beg2,...)中超出[beg1,end1)长度的序列不参与运算.
//        //                  minus<int> ()所在位置用来替换不带此参数版本算法的加.
//        //                  divides<int> ()所在位置用来替换不带此参数版本算法的乘.
//        //100-(10/1) = 90
//        //90-(20/2) = 80
//        //80-(30/3) = 70
//        std::cout << "--- using functional operations: ";
//        std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init,
//                                        std::minus<int>(), std::divides<int>());
//        std::cout << '\n'; //70
//
//        //100-(10+1) = 89
//        //89-(20+2) = 67
//        //67-(30+3) = 34
//        std::cout << "--- using custom functions: ";
//        std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init,
//                                        myaccumulator, myproduct);
//        std::cout << '\n'; //34
//    }
//
//    void testPartialSum() {
//        auto myop = [](int x, int y) { return x + y + 1; };
//
//        std::vector<int> val = {1, 2, 3, 4, 5};
//        std::vector<int> result(5);
//
//        //默认累加
//        std::partial_sum(val.begin(), val.end(), result.begin());
//        std::cout << "using default partial_sum: \n";
//        printVec(result);
//
//        //result里面对应的5个元素
//        //1=1
//        //1*2=2
//        //2*3=6
//        //6*4=24
//        //24*5=120
//        std::partial_sum(val.begin(), val.end(), result.begin(), std::multiplies<int>());
//        std::cout << "using functional operation multiplies: \n";
//        printVec(result);
//
//        //result里面对应的5个元素
//        //1=1
//        //1+2+1 = 4
//        //4+3+1 = 8
//        //8+4+1 = 13
//        //13+5+1 = 19
//        std::partial_sum(val.begin(), val.end(), result.begin(), myop);
//        std::cout << "using custom function: \n";
//        printVec(result);
//    }
//
//    void testAdjacentDifference() {
//        std::array<int, 6> ia = {1, 1, 2, 3, 5, 8};
//        std::list<int> ilist(ia.begin(), ia.end());
//        std::list<int> ilist_result(ilist.size());
//        std::adjacent_difference(ilist.begin(), ilist.end(), ilist_result.begin());
//        std::for_each(ilist_result.begin(), ilist_result.end(), [](const int &num) { printf("--- num:%d\n", num); });
//        printf("\n"); //1 0 1 1 2 3
//
//
//        //1	2	3	5	8
//        //1	1	2	3	5
////1 1	2	6	15 40 //ilist_result
//        std::adjacent_difference(ilist.begin(), ilist.end(), ilist_result.begin(), std::multiplies<int>());
//        std::for_each(ilist_result.begin(), ilist_result.end(), [](const int &num) { printf("--- num:%d\n", num); });
//        printf("\n"); //1 1 2 6 15 40
//    }
//
//    void testMinMaxElement() {
//        int val1 = 2;
//        int val2 = 5;
//        const int &c = std::min(val2, val1, [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        const int &d = std::max(val1, val2, [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        printf("--- val1:0x%x, val2:0x%x\n", &val1, &val2);
//        printf("--- min val:%d, 0x%x\n", c, &c);
//        printf("--- max val:%d, 0x%x\n", d, &d);
//
//        auto e = std::minmax(val1, val2, [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        printf("--- min:%d, max:%d\n", e.first, e.second);
//        printf("\n");
//
//        std::array<int, 6> ia = {1, 1, 2, 3, 5, 8};
//        // 根据给定的比较函数，找出最小元素
//        auto ret1 = std::min_element(ia.begin(), ia.end(),
//                                     [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        printf("--- min:%d\n", *ret1);
//
//        // 根据给定的比较函数，找出最大元素
//        auto ret2 = std::max_element(ia.begin(), ia.end(),
//                                     [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        printf("--- max:%d\n", *ret2);
//
//        // 根据给定的比较函数，找出最大和最小元素
//        auto ret3 = std::minmax_element(ia.begin(), ia.end(),
//                                        [](const int &_a, const int &_b) { return _a < _b ? true : false; });
//        printf("--- min:%d, max:%d\n", *ret3.first, *ret3.second);
//    }
//
//    void testShuffle() {
//        //正真的洗牌，根据随机数
//        std::default_random_engine generator1(time(NULL)); //随机数生产器
//        std::vector<int> datas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::shuffle(datas.begin(), datas.end(), generator1); //
//        printVec(datas);
//
//        //每次运行都是一样的结果
//        auto myrandom = [](int i) { return std::rand() % i; };
//        std::vector<int> datas2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        //std::random_shuffle(datas2.begin(), datas2.end());
//        std::random_shuffle(datas2.begin(), datas2.end(), myrandom);
//        printVec(datas2);
//    }
//
//    void testHeap() {
//        //大顶堆
//        auto cmpFunc = [](const int &_a, const int &_b) -> bool { return _a < _b ? true : false; };
//        std::vector<int> datas = {5, 1, 9, 4, 3, 6, 2, 7, 8, 0};
//
//        printf("--- 堆化数组\n");
//        std::make_heap(datas.begin(), datas.end(), cmpFunc);
//        printVec(datas); //
//
//        printf("--- 移除堆顶元素\n");
//        std::pop_heap(datas.begin(), datas.end(), cmpFunc);
//        datas.pop_back();//删除该节点，因为只是把堆顶元素移动到了堆尾
//        printVec(datas);
//
//        printf("--- 移除堆顶元素\n");
//        std::pop_heap(datas.begin(), datas.end(), cmpFunc);
//        datas.pop_back();//删除该节点，因为只是把堆顶元素移动到了堆尾
//        printVec(datas);
//
//        printf("--- 堆尾添加元素5\n");
//        datas.push_back(5);
//        std::push_heap(datas.begin(), datas.end(), cmpFunc);
//        printVec(datas);
//
//        printf("--- 将堆变成有序数组\n");
//        std::sort(datas.begin(), datas.end(), cmpFunc);
//        printVec(datas);
//    }
//
//    void testNextPermutation() {
//        /*
//        在《STL源码解析》中找到了这个函数，在此也简单叙述一下原理：
//        在STL中，除了next_permutation外，还有一个函数prev_permutation，
//        两者都是用来计算排列组合的函数。前者是求出下一个排列组合，而后者是求出上一个排列组合。
//        所谓“下一个”和“上一个”，书中举了一个简单的例子：
//        对序列 {a, b, c}，每一个元素都比后面的小，按照字典序列，固定a之后，a比bc都小，c比b大，
//        它的下一个序列即为{a, c, b}，而{a, c, b}的上一个序列即为{a, b, c}，
//        同理可以推出所有的六个序列为：{a, b, c}、{a, c, b}、{b, a, c}、{b, c, a}、{c, a, b}、{c, b, a}，
//        其中{a, b, c}没有上一个元素，{c, b, a}没有下一个元素。
//        */
//
//        auto cmpFunc = [](const int &_a, const int &_b) -> bool { return _a < _b ? true : false; };
//        std::vector<int> datas = {1, 2, 3};
//        printVec(datas);
//        std::next_permutation(datas.begin(), datas.end(), cmpFunc);
//        printVec(datas);
//        std::next_permutation(datas.begin(), datas.end(), cmpFunc);
//        printVec(datas);
//
//        //std::prev_permutation(datas.begin(), datas.end(), cmpFunc);
//
//    }
//
//    void testMismatch() {
//        auto cmpFunc = [](const int &_a, const int &_b) -> bool { return _a == _b ? true : false; };
//        std::vector<int> datas1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::vector<int> datas2 = {0, 1, 2, 3, 4, 0, 6, 7, 8, 9};
//
//        //返回两个vec的不同相同的值的迭代器
//        auto ret = std::mismatch(datas1.begin(), datas1.end(), datas2.begin(), cmpFunc);
//        if (ret.first == datas1.end() && ret.second == datas2.end())
//            printf("完全相同\n");
//        else {
//            printf("--- ret.first:%d, ret.second:%d \n", *ret.first, *ret.second);
//        }
//    }
//
//    void testCopy() {
//        std::vector<int> datas1 = {0, 1, 2, 3, 4, 0, 2, 7, 8, 2};
//        std::vector<int> datas2(datas1.size());
//        std::copy(datas1.begin(), datas1.end(), datas2.begin());
//        printVec(datas2);
//
//        int dstNum = 2;
//        auto cmpFunc = [&](const int &val) -> bool { return val == dstNum ? true : false; };
//        std::vector<int> datas3(datas1.size());
//        std::copy_if(datas1.begin(), datas1.end(), datas3.begin(), cmpFunc); // 相等的才拷过去
//        printVec(datas3);
//    }
//
//    void testUnorderMap() {
//        auto printMap = [](const std::unordered_map<int, std::string> &datas) {
//            for (auto iter = datas.begin(); iter != datas.end(); iter++)
//                printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//            printf("\n");
//        };
//
//        std::unordered_map<int, std::string> datas;
//        datas.insert(std::pair<int, std::string>(1, "aaa"));
//        datas.insert(std::pair<int, std::string>(9, "bbb"));
//        datas.insert(std::pair<int, std::string>(5, "ccc"));
//        datas.insert(std::pair<int, std::string>(2, "ddd"));
//        datas.insert(std::pair<int, std::string>(7, "eee"));
//        datas.insert(std::pair<int, std::string>(9, "fff"));
//        datas.insert(std::pair<int, std::string>(6, "ggg"));
//        datas.insert(std::pair<int, std::string>(3, "hhh"));
//        datas.insert(std::pair<int, std::string>(4, "iii"));
//        datas.insert(std::pair<int, std::string>(0, "jjj"));
//        printMap(datas);
//
//
//        std::map<int, int> datas2;
//    }
//
//    void testMapWithCmpFunc1() {
//        //-------------按key值排序 ------------------
//        //自定义key比较类，重写()操作符，map插入时则会按顺序插入到合适的位置
//        struct CmpByKey {
//            bool operator()(const int &k1, const int &k2) {
//                return k1 < k2 ? true : false;
//            }
//        };
//
//        // 有序map
//        printf("--------- 有序map 按key值排序\n");
//        std::map<int, std::string, CmpByKey> datas;
//        datas.insert(std::pair<int, std::string>(1, "aaa"));
//        datas.insert(std::pair<int, std::string>(9, "bbb"));
//        datas.insert(std::pair<int, std::string>(5, "ccc"));
//        datas.insert(std::pair<int, std::string>(2, "ddd"));
//        datas.insert(std::pair<int, std::string>(7, "eee"));
//        datas.insert(std::pair<int, std::string>(9, "fff"));
//        datas.insert(std::pair<int, std::string>(6, "ggg"));
//        datas.insert(std::pair<int, std::string>(3, "hhh"));
//        datas.insert(std::pair<int, std::string>(4, "iii"));
//        datas.insert(std::pair<int, std::string>(0, "jjj"));
//
//        for (auto iter = datas.begin(); iter != datas.end(); iter++)
//            printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//        printf("\n");
//
//        //-------------按value值排序 ------------------
//        printf("--------- 有序map 按value值排序\n");
//        typedef std::pair<int, std::string> PAIR;
//        std::map<int, std::string> datas2;
//        datas2.insert(std::pair<int, std::string>(1, "a"));
//        datas2.insert(std::pair<int, std::string>(9, "bb"));
//        datas2.insert(std::pair<int, std::string>(5, "ccc"));
//        datas2.insert(std::pair<int, std::string>(5, "zzzzzzzzzzz")); //已经有个5的key，所以不会被插入
//        datas2.insert(std::pair<int, std::string>(2, "ddd"));
//        datas2[2] = "yyyyyyyyyyy"; //有则替换，无则插入
//        datas2.insert(std::pair<int, std::string>(7, "eeee"));
//        datas2.insert(std::pair<int, std::string>(9, "fff"));
//        datas2.insert(std::pair<int, std::string>(6, "g"));
//        datas2.insert(std::pair<int, std::string>(3, "hh"));
//        datas2.insert(std::pair<int, std::string>(4, "iiiiii"));
//        datas2.insert(std::pair<int, std::string>(0, "j"));
//
//        auto cmpFunc = [](const PAIR &_a, PAIR &_b) { return _a.second.length() < _b.second.length() ? true : false; };
//        struct CmpByValue { //也可以用类的形式
//            bool operator()(const PAIR &_a, const PAIR &_b) {
//                return _a.second.length() < _b.second.length() ? true : false;
//            }
//        };
//
//        std::vector<PAIR> vecData(datas2.begin(), datas2.end()); //将所有的pair对象存储到vec中，
//        std::sort(vecData.begin(), vecData.end(), cmpFunc); //然后指定排序方法排序
//        //std::sort(vecData.begin(), vecData.end(), CmpByValue()); //然后指定排序方法排序
//        for (int i = 0; i != vecData.size(); ++i)
//            printf("--- key:%d, value:%s\n", vecData[i].first, vecData[i].second.c_str());
//        printf("\n");
//
//        //大多数情况下都是要用value值排序，无序列map
//        printf("--------- 无序unorder_map 按value值排序\n");
//        std::unordered_map<int, std::string> data5;
//        data5.insert(std::pair<int, std::string>(1, "a"));
//        data5.insert(std::pair<int, std::string>(9, "bb"));
//        data5.insert(std::pair<int, std::string>(5, "ccc"));
//        data5.insert(std::pair<int, std::string>(5, "zzzzzzzzzzz")); //已经有个5的key，所以不会被插入
//        data5.insert(std::pair<int, std::string>(2, "ddd"));
//        data5[2] = "yyyyyyyyyyy"; //有则替换，无则插入
//        data5.insert(std::pair<int, std::string>(7, "eeee"));
//        data5.insert(std::pair<int, std::string>(9, "fff"));
//        data5.insert(std::pair<int, std::string>(6, "g"));
//        data5.insert(std::pair<int, std::string>(3, "hh"));
//        data5.insert(std::pair<int, std::string>(4, "iiiiii"));
//        data5.insert(std::pair<int, std::string>(0, "j"));
//
//        std::for_each(data5.begin(), data5.end(),
//                      [](const PAIR &iter) { printf("--- key:%d, value:%s\n", iter.first, iter.second.c_str()); });
//        printf("\n");
//
//        std::vector<PAIR> vecData2(data5.begin(), data5.end()); //将所有的pair对象存储到vec中，
//        std::sort(vecData2.begin(), vecData2.end(), cmpFunc); //然后指定排序方法排序
//        for (int i = 0; i != vecData2.size(); ++i)
//            printf("--- key:%d, value:%s\n", vecData2[i].first, vecData2[i].second.c_str());
//        printf("\n");
//
//        auto iter5 = data5.find(9);
//        if (iter5 != data5.end())
//            printf("--- key:%d, value:%s\n", iter5->first, iter5->second.c_str());
//        else
//            printf("--- not find\n");
//
//    }
//
//    struct person {
//        std::string name;
//        int age;
//
//        person(std::string name, int age) {
//            this->name = name;
//            this->age = age;
//        }
//
//        //bool operator== (const person& p) const
//        //{
//        //	return name == p.name && age == p.age;
//        //}
//
//        bool operator<(const person &p) const {
//            return age < p.age ? true : false;
//        }
//    };
//
//    void testMapWithCmpFunc2() {
//        /*
//        用法的区别就是，stl::map 的key需要定义operator< 。
//        而boost::unordered_map需要定义hash_value、equal函数。
//        对于内置类型，如string，这些都不用操心。
//        对于自定义的类型做key，就需要自己重载operator< 或者hash_value()了。
//        */
//        typedef std::pair<person, int> PAIR;
//        std::map<person, int> m;
//        person p1("Tom1", 20);
//        person p2("Tom2", 22);
//        person p3("Tom3", 22);
//        person p4("Tom4", 23);
//        person p5("Tom5", 24);
//        m.insert(std::make_pair(p3, 100));
//        m.insert(std::make_pair(p4, 100));
//        m.insert(std::make_pair(p5, 100));
//        m.insert(std::make_pair(p1, 100));
//        m.insert(std::make_pair(p2, 100));
//
//        //map的另一种遍历方式1 (c++11)
//        printf("--- std::for_each(m.begin(), m.end(), \n");
//        std::for_each(m.begin(), m.end(),
//                      [](const PAIR &iter) {
//                          std::cout << iter.first.name << "\t" << iter.first.age << std::endl;
//                      });
//        printf("\n");
//
//        //map的另一种遍历方式2 (c++11)
//        printf("--- for (auto iter : m) \n");
//        for (auto iter : m)
//            std::cout << iter.first.name << "\t" << iter.first.age << std::endl;
//        printf("\n");
//
//        //map的另一种遍历方式3
//        printf("--- for (auto iter = m.begin(); iter != m.end(); iter++) \n");
//        for (auto iter = m.begin(); iter != m.end(); iter++)
//            std::cout << iter->first.name << "\t" << iter->first.age << std::endl;
//    }
//
//
////--------------------------- unorder_map 重写hash、equal函数 begin ----------
////都是对key值而言
////如果你希望利用系统定义的字符串hash函数，你可以这样写：
//
//    struct str_hash {
//        size_t operator()(const std::string &str) const {
//            std::tr1::hash<std::string> hash_value;
//            return hash_value(str.c_str());
//        }
//    };
//
////struct str_hash{      //自写hash函数
////	size_t operator()(const std::string& str) const
////	{
////		unsigned long __h = 0;
////		for (size_t i = 0; i < str.size(); i++)
////		{
////			__h = 51 * __h + str[i];
////		}
////		return size_t(__h);
////	}
////};
//
//    struct str_equal {      //string 判断相等函数
//        bool operator()(const std::string &s1, const std::string &s2) const {
//            return strcmp(s1.c_str(), s2.c_str()) == 0;
//        }
//    };
//
//    class Plane {
//    public:
//        Plane(int _speed) { mSpeed = _speed; }
//
//        bool operator==(const Plane &p) const {
//            return mSpeed == p.mSpeed ? true : false;
//        }
//
//    public:
//        int mSpeed;
//    };
//
//    struct plane_hash {
//        size_t operator()(const Plane &p) const {
//            return p.mSpeed >> 1;
//        }
//    };
//
//    void testUnorderHashKey() {
//        std::unordered_map<std::string, int, str_hash, str_equal> myMap;
//        myMap.insert(std::make_pair("hello", 123));
//        myMap.insert(std::make_pair("world", 456));
//        myMap.insert(std::make_pair("I", 555));
//        myMap.insert(std::make_pair("am", 333));
//        myMap.insert(std::make_pair("Test", 888));
//
//        std::for_each(myMap.begin(), myMap.end(),
//                      [](const std::pair<std::string, int> &iter) {
//                          printf("--- key:%s, value:%d\n", iter.first.c_str(), iter.second);
//                      });
//        printf("\n");
//
//        printf("--- 对于自定的key，可以重写==操作符替代str_equal类\n");
//        //对于自定的key，可以重写==操作符替代str_equal类
//        //旨在用来在key值的hash值相同时，进一步判断是否相同，如果相同则不插入进去
//        //还有查找时相同的hash值时，进一步判断是否相同，如果相同则返回改迭代器；
//        std::unordered_map<Plane, int, plane_hash> myPlane;
//        myPlane.insert(std::make_pair(Plane(123), 123));
//        myPlane.insert(std::make_pair(Plane(456), 456));
//        myPlane.insert(std::make_pair(Plane(789), 789));
//        std::for_each(myPlane.begin(), myPlane.end(),
//                      [](const std::pair<Plane, int> &iter) {
//                          printf("--- speed:%d, value:%d\n", iter.first.mSpeed, iter.second);
//                      });
//
//        auto iter = myPlane.find(Plane(123));
//        if (iter != myPlane.end())
//            printf("--- find\n");
//        else
//            printf("--- not find\n");
//    }
////--------------------------- unorder_map 重写hash函数 end ----------
//
//    void main() {
//        //testSTLVec();
//        //testSTLMap();
//        //testVecDel();
//        //testMapDel();
//        //testInsertVector();
//        //testList();
//        //testVecInsert();
//        //testPartialSort();
//        //testNth_element();
//        testPartition();
//        //testRemoveAndErase();
//        //testSearch();
//        //testSearchForMap();
//        //testMerge();
//        //testMemFun();
//        //testbind1stAndBind2nd();
//        //testTransform();
//        //testFindIfRemoveIfReplaceIf();
//        //testBinarysearch();
//        //testShinkToFit();
//        //testArr();
//
//        //---- #include <numeric> begin ---
//        //testAccumulate();
//        //testInnerProduct();
//        //testPartialSum();
//        //testAdjacentDifference();
//        //---- #include <numeric> end ---
//
//        //testMinMaxElement();
//        //testShuffle();
//        //testHeap();
//        //testNextPermutation();
//        //testMismatch();
//        //testCopy();
//        //testUnorderMap();
//        //testMapWithCmpFunc1();
//        //testMapWithCmpFunc2();
//        //testUnorderHashKey();
//    }
//
///*
//消耗资源越少的排在前面：
//1. partition
//2. stable_partition
//3. nth_element
//4. partial_sort
//5. sort
//6. stable_sort
//*/
//} // STLtest
