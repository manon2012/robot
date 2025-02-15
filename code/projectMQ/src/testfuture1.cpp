#include <iostream>
#include <thread>
#include <future>
#include <vector>

// class Task
// {
// public:
//     Task(int id) : m_id(id) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         result = m_id * 2;
//         return result;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {

//     std::vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3)};

//     std::vector<std::future<int>> futures;
//     for (auto &task : tasks)
//     {

//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {

//         std::cout << "Result: " << fur.get() << std::endl;
//     }

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {
//     std::vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3)};
//     std::vector<std::future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "Result: " << fur.get() << std::endl;
//     }
//     return 0;
// }

// class Task

// {
// public:
//     int operator()(int x, int y) const
//     {
//         return x + y;
//     }
// };

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {

//     std::vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3)};

//     std::vector<std::future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }
//     std::cout << "begin waiting..." << std::endl;
//     std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

//     for (auto &fur : futures)
//     {
//         std::cout << "result is: " << fur.get() << std::endl;
//     }
//     auto end = std::chrono::system_clock::now();
//     auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
//     std::cout << "Total Time taken= " << diff << " Seconds" << std::endl;

//     // std::future<int> result = std::async([]()
//     //                                      {
//     // std::this_thread::sleep_for(std::chrono::seconds(3));
//     // return 2024; });

//     // std::cout << "the future result:" << result.get() << std::endl;
//     // std::cout << "the future status:" << result.valid() << std::endl;

//     // try
//     // {
//     //     /* code */
//     //     result.get();
//     // }
//     // catch (const std::exception &e)
//     // {
//     //     std::cout << "get error..." << std::endl;
//     //     std::cerr << e.what() << '\n';
//     // }

//     // std::cout
//     //     << Task()(1, 1) << std::endl;

//     // Task task;
//     // std::cout << task(1, 2) << std::endl;

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         return result = m_id * 2;
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//     }

// private:
//     int m_id;
//     int result;
// };
// using namespace std;
// int main()
// {
//     std::vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};

//     std::vector<std::future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "Result is: " << fur.get() << std::endl;
//     }

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {
//     std::vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};
//     std::vector<std::future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "resulut:" << fur.get() << std::endl;
//     }

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };
// using namespace std;
// #include <cstring>
// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};

//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << "result:" << future.get() << std::endl;
//     }
//     std::cout << "this after all result" << std::endl;

//     string t1 = "hello world";
//     const char *t2 = t1.data();
//     std::cout << t1 << t1.size() << std::endl;
//     std::cout << t2 << std::endl;
//     std::cout << strlen(t2) << std::endl;

//     return 0;
// }

// using namespace std;
// class Task
// {

// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         // return m_id = m_id * 2;
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {

//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }
//     std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
//     for (auto &fur : futures)
//     {
//         std::cout << "result: " << fur.get() << std::endl;
//     }

//     auto end = std::chrono::system_clock::now();
//     auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
//     std::cout << "Total Time taken= " << diff << " Seconds" << std::endl;

//     return 0;
// }

// using namespace std;
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// class test
// {
// public:
//     int operator()(int x, int y) const
//     {
//         return x + y;
//     }
// };
// int main()
// {
//     struct TEST_DATA_NODE
//     {
//         unsigned int id = 0;
//         char data[1024];
//     };

//     std::cout << "sizeof(TEST_DATA_NODE):" << sizeof(TEST_DATA_NODE) << std::endl;

//     return 0;

//     test t1;
//     cout << t1(1, 1) << endl;
//     cout << test()(1, 1) << endl;

//     return 0;
//     vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3)};
//     vector<future<int>> futures;

//     for (auto task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "result: " << fur.get() << std::endl;
//     }
//     return 0;
// }

// using namespace std;

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};

//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "result: " << fur.get() << std::endl;
//         if (fur.valid())
//         {
//             std::cout << "result: " << fur.get() << std::endl;
//         }
//         try
//         {
//             fur.get();
//         }
//         catch (exception &e)
//         {
//             std::cout << e.what() << std::endl;
//         }
//     }
//     return 0;
// }

// using namespace std;

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}

//     int operator()()
//     {
//         this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return result = m_id * 2;
//     }

// private:
//     int m_id;
//     int result;
// };

// int main()
// {

//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         cout << "get result: " << fur.get() << endl;

//         if (fur.valid())
//         {

//             cout << "get result: " << fur.get() << endl;
//         }

//         try
//         {
//             fur.get();
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }
// }

// #include <cmath>
// #include <functional>
// #include <future>
// #include <iostream>
// #include <thread>

// // unique function to avoid disambiguating the std::pow overload set
// int f(int x, int y) { return std::pow(x, y); }

// void task_lambda()
// {
//     std::packaged_task<int(int, int)> task([](int a, int b)
//                                            { return std::pow(a, b); });
//     std::future<int> result = task.get_future();

//     task(2, 9);

//     std::cout << "task_lambda:\t" << result.get() << '\n';
// }

// void task_bind()
// {
//     std::packaged_task<int()> task(std::bind(f, 2, 11));
//     std::future<int> result = task.get_future();

//     task();

//     std::cout << "task_bind:\t" << result.get() << '\n';
// }

// void task_thread()
// {
//     std::packaged_task<int(int, int)> task(f);
//     std::future<int> result = task.get_future();

//     std::thread task_td(std::move(task), 2, 10);
//     task_td.join();

//     std::cout << "task_thread:\t" << result.get() << '\n';
// }

// int main()
// {
//     task_lambda();
//     task_bind();
//     task_thread();
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     std::vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     std::vector<std::future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "result: " << fur.get() << std::endl;
//     }

//     return 0;
// // }
// using namespace std;
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         cout << "result is: " << fur.get() << endl;
//         try
//         {
//             /* code */
//             cout << "result is: " << fur.get() << endl;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }

//     return 0;
// // }
// #include <string>
// #include <iostream>
// using namespace std;
// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// pfunc p1 = test;

// class Caller
// {
// public:
//     void setFunc(pfunc pf)
//     {
//         m_func = pf;
//     }

//     void letRun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     // Caller c1;
//     // c1.setFunc(test);
//     // c1.letRun(3, "helloworld");

//     p1(3, "123");

//     return 0;
// }

// #include <string>
// using namespace std;

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setFunc(pfunc pf)
//     {
//         m_func = pf;
//     }

//     void letRun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setFunc(test);
//     c1.letRun(1, "helloworld");
// }

// #include <string>
// using namespace std;

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setFunc(pfunc pf)
//     {
//         m_func = pf;
//     }

//     void letRun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     int abc = 100;
// #if 1
//     cout << 1111 << endl;

// #endif

//     return 0;
//     caller c1;
//     c1.setFunc(test);
//     c1.letRun(10, "helloworld");
// }

// #include <iostream>
// #include <utility>
// #include <vector>
// #include <string>

// int main()
// {
//     std::string str = "Hello";
//     std::vector<std::string> v;

//     // uses the push_back(const T&) overload, which means
//     // we'll incur the cost of copying str
//     v.push_back(str);
//     std::cout << "After copy, str is \"" << str << "\"\n";

//     // uses the rvalue reference push_back(T&&) overload,
//     // which means no strings will be copied; instead, the contents
//     // of str will be moved into the vector.  This is less
//     // expensive, but also means str might now be empty.
//     v.push_back(std::move(str));
//     std::cout << "After move, str is \"" << str << "\"\n";

//     std::cout << "The contents of the vector are \"" << v[0]
//               << "\", \"" << v[1] << "\"\n";
// // }
// #include <iostream>
// #include <string>
// using namespace std;

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "good");
// // }
// using namespace std;
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << "result: " << fur.get() << std::endl;
//     }
//     return 0;
// }

// using namespace std;

// class Task
// {

// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         this_thread::sleep_for(std::chrono::seconds(6));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {

//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         try
//         {
//             cout << "result is: " << fur.get() << endl;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }

//     return 0;
// }

// using namespace std;

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello world");
//     return 0;
// }

// int main()
// {
//     int a[] = {0,
//                0,
//                0,
//                0,
//                0,
//                0,
//                0};
//     for (int n : a)
//     {
//         std::cout << n << " ";
//     }
//     std::cout << "\n";

//     for (int n : a)
//     {
//         std::cout << 1 << " ";
//     }
//     return 0;
// }
// #include <string>
// #include <iostream>
// using namespace std;
// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class call
// {
// public:
//     void setfun(pfunc fp)
//     {
//         m_func = fp;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     call c1;
//     c1.setfun(test);
//     c1.letrun(2, "helloworld");

//     return 0;
// }

// #include <vector>

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };
// using namespace std;
// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     try
//     {
//         for (auto &fur : futures)
//         {
//             cout << "result is: " << fur.get() << endl;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// }

// using namespace std;
// void test(int n, string m)
// {
//     while (n-- > 0)
//     {
//         cout << m << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "hello");

//     return 0;
// }

// using namespace std;

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(async(launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         try
//         {
//             cout << fur.get() << endl;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }

//     return 0;
// }

// void del(void (*)())
// {
//     std::cout << "del" << std::endl;
// }

// void fun()
// {
//     std::cout << "fun" << std::endl;
// }
// int main()
// {
//     std::shared_ptr<void()> ee(fun, del);
//     (*ee)();
// }
using namespace std;
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()

//     {
//         this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << fur.get() << std::endl;
//     }

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc fp)
//     {
//         m_func = fp;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "test");
//     return 0;
// }

// #include <string>
// #include <iterator>
// #include <iostream>
// #include <algorithm>
// #include <array>

// int main()
// {
//     // construction uses aggregate initialization
//     std::array<int, 3> a1{{1, 2, 3}};  // double-braces required in C++11 prior to the CWG 1270 revision
//                                        // (not needed in C++11 after the revision and in C++14 and beyond)
//     std::array<int, 3> a2 = {1, 2, 3}; // never required after =
//     std::array<std::string, 2> a3 = {std::string("a"), "b"};

//     // container operations are supported
//     std::sort(a1.begin(), a1.end());
//     std::reverse_copy(a2.begin(), a2.end(),
//                       std::ostream_iterator<int>(std::cout, " "));

//     std::cout << '\n';

//     // ranged for loop is supported
//     for (const auto &s : a3)
//         std::cout << s << ' ';
// }

// #include <iostream>
// #include <string>
// #include <unordered_map>

// int main()
// {
//     // Create an unordered_map of three strings (that map to strings)
//     std::unordered_map<std::string, std::string> u = {
//         {"RED", "#FF0000"},
//         {"GREEN", "#00FF00"},
//         {"BLUE", "#0000FF"}};

//     // Iterate and print keys and values of unordered_map
//     for (const auto &n : u)
//     {
//         std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
//     }

//     // Add two new entries to the unordered_map
//     u["BLACK"] = "#000000";
//     u["WHITE"] = "#FFFFFF";

//     // Output values by key
//     std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
//     std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";

//     return 0;
// }

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

// template <typename T>
// void print_queue(T &q)
// {
//     while (!q.empty())
//     {
//         std::cout << q.top() << " ";
//         q.pop();
//     }
//     std::cout << '\n';
// }

// int main()
// {
//     std::priority_queue<int> q;

//     for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
//         q.push(n);

//     print_queue(q);

//     std::priority_queue<int, std::vector<int>, std::greater<int>> q2;

//     for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
//         q2.push(n);

//     print_queue(q2);

//     // Using lambda to compare elements.
//     auto cmp = [](int left, int right)
//     { return (left ^ 1) < (right ^ 1); };
//     std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

//     for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
//         q3.push(n);

//     print_queue(q3);
// }

// struct node
// {
//     int x, y;
//     bool operator<(const node &b) const
//     {
//         return this->x < b.x;
//     }
// };

// int main()
// {

//     priority_queue<node> que;
//     que.push((node){1, 5});
//     que.push((node){2, 3});
//     while (!que.empty())
//     {
//         std::cout << que.top().x << std::endl;
//         que.pop();
//     }
//     std::cout << '\n';
//     cout << endl;

//     return 0;
// // }
// struct node
// {
//     int x, y;
// };

// ostream &operator<<(ostream &os, const node &t)
// {
//     os << t.x << "";
//     return os;
// }
// template <typename T>
// void print_queue(T const &xs)
// {
//     cout << "[" << " ";
//     for (auto &x : xs)
//     {
//         cout << x << " ";
//     }
//     cout << "]" << '\n';
// }

// int main()
// {
//     vector<int> xs;
//     print_queue(xs);

//     xs.push_back(1);
//     xs.push_back(2);

//     print_queue(xs);

//     xs.pop_back();
//     print_queue(xs);

//     vector<node> xr;
//     xr.push_back((node){1, 2});
//     xr.push_back((node){3, 4});

//     print_queue(xr);

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "test");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}

//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << fur.get() << " ";
//         ;
//     }
//     cout << endl;

//     return 0;
// }

// class Task
// {
// public:
//     Task(int id) : m_id(id) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_result;

//     int m_id;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &x : futures)
//     {
//         std::cout << x.get() << std::endl;
//     }
// }

// void Test(string abc, int x)
// {
//     while (x-- > 0)
//     {
//         std::cout << x << std::endl;
//     }
// }

// typedef void (*pfunc)(string, int);

// class caller
// {
// public:
//     void setFunc(pfunc func)
//     {
//         m_func = func;
//     }
//     void letRun(string abc, int x)
//     {
//         m_func(abc, x);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setFunc(Test);
//     c1.letRun("helloworld", 3);
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks= {Task(1),Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//        futures.push_back(std::async(std::launch::async, task));
//     }

//     for(auto & fur: futures)
//     {
//         std::cout << fur.get() << std::endl;
//     }
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }
// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc x)
//     {
//         m_func = x;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };
// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "hello");
//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {

// public:
//     void setfunc(pfunc x)
//     {
//         m_func = x;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "hello world");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main()
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << fur.get() << std::endl;
//     }

//     return 0;
// // }
// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             // strcpy(m_data, '\0');
//             // m_data = '\0';
//             m_data[0] = '\0';
//         }
//     }
//     CATString(const CATString &p)
//     {
//         m_data = new char[strlen(p.m_data) + 1];
//         strcpy(m_data, p.m_data);
//     }
//     CATString &operator=(const CATString &p)
//     {
//         if (this == &p)
//         {
//             return *this;
//         }
//         delete this->m_data;
//         m_data = new char[strlen(p.m_data) + 1];
//         strcpy(m_data, p.m_data);
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }
//     friend ostream &operator<<(ostream &os, const CATString &string);

// private:
//     char *m_data;
// };
// ostream &operator<<(ostream &os, const CATString &string)
// {
//     os << string.m_data;
//     return os;
// }

// #ifndef _COMPLEX
// #define _COMPLEX

// class Complex;
// Complex &__doapl(Complex *ths, const Complex &p)
// {
//     ths->real += p.real;
//     ths->imag += p.imag;
//     return *ths;
// }

// class Complex
// {
// public:
//     Complex(int x, int y) : real(x), imag(y) {}
//     Complex(const Complex &p)
//     {
//         this->real = p.real;
//         this->imag = p.imag;
//     }

//     Complex &operator=(const Complex &p)
//     {
//     }
//     Complex &operator+=(const Complex &p)
//     {
//         return __doapl(this, p);
//     }

// private:
//     double real, imag;
//     friend Complex &__doapl(Complex *x, const Complex &p);
// };

// #endif

// int main()
// {
//     // CATString s1;
//     // CATString s2("s2");
//     // CATString s3("s3");
//     // CATString s4;
//     // s4 = s3;
//     // cout << s1 << endl;
//     // cout << s2 << endl;
//     // cout << s3 << endl;
//     // cout << s4 << endl;

//     return 0;
// }

// #include <string.h>

// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             m_data[0] = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete this->m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
// };

// int main()
// {
//     return 0;
// }

// #ifndef __COMPLEX__
// #define __COMPLEX__
// class Complex;
// Complex &__doapl(Complex *ths, const Complex &p);

// class Complex
// {
// public:
//     Complex(double x, double y) : real(x), imag(y) {}

//     Complex &operator+=(const Complex &p)
//     {
//         return __doapl(this, p);
//     }
//     double const Real()
//     {
//         return real;
//     }
//     double const Imag()
//     {
//         return imag;
//     }

// private:
//     double real;
//     double imag;

//     friend Complex &__doapl(Complex *ths, const Complex &p);
// };

// Complex &__doapl(Complex *ths, const Complex &p)
// {
//     ths->real += p.real;
//     ths->imag += p.imag;
//     return *ths;
// }

// #endif

// int main()
// {
//     Complex c1(1.1, 2.2);
//     Complex c2(1.1, 2.2);
//     c2 += c1;
//     std::cout << c2.Real() << std::endl;
//     std::cout << c2.Imag() << std::endl;

//     return 0;
// }

// Here's a basic implementation of a C++ `String` class:
// ```cpp

// #ifndef STRING_H
// #define STRING_H

// #include <cstring>
// #include <memory>

// class String
// {
// public:
//     String() : data_(nullptr), length_(0) {}
//     String(const char *str) : data_(nullptr), length_(0)
//     {
//         append(str);
//     }
//     ~String()
//     {
//         freeMemory();
//     }
//     String(const String &other) : data_(nullptr), length_(0)
//     {
//         append(other.data_, other.length_);
//     }
//     String &operator=(const String &other)
//     {
//         freeMemory();
//         length_ = other.length_;
//         data_ = new char[length_ + 1];
//         std::copy(other.data_, other.data_ + length_, data_);
//         data_[length_] = '\0';
//         return *this;
//     }
//     ~String()
//     {
//         freeMemory();
//     }
//     char &operator[](size_t index)
//     {
//         return data_[index];
//     }
//     const char &operator[](size_t index) const
//     {
//         return data_[index];
//     }
//     size_t length() const { return length_; }
//     String &operator+=(const String &other)
//     {
//         resize_(length_ + other.length_);
//         std::copy(other.data_, other.data_ + other.length_, data_ + length_);
//         length_ += other.length_;
//         return *this;
//     }
//     String operator+(const String &other) const
//     {
//         String result = *this;
//         result += other;
//         return result;
//     }

// private:
//     char *data_;
//     size_t length_;
//     void freeMemory()
//     {
//         if (data_)
//         {
//             delete[] data_;
//             data_ = nullptr;
//             length_ = 0;
//         }
//     }
//     void resize_(size_t newLength)
//     {
//         if (newLength > length_)
//         {
//             char *newData = new char[newLength + 1];
//             std::copy(data_, data_ + length_, newData);
//             delete[] data_;
//             data_ = newData;
//             length_ = newLength;
//         }
//     }
//     void append(char *data, int length)
//     {
//     }
//     void append(const char *data)
//     {
//     }
// };

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             m_data[0] = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &string);
// };

// ostream &operator<<(ostream &os, const CATString &string)
// {
//     os << string.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     CATString s1;
//     CATString s2("hello");
//     CATString s3;
//     s3 = s2;

//     CATString s4(s3);
//     CATString s5("");

//     std::cout << s1 << std::endl;
//     std::cout << s2 << std::endl;
//     std::cout << s3 << std::endl;
//     std::cout << s4 << std::endl;
//     std::cout << s5 << std::endl;

//     return 0;
// // }
// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete this->m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
// };

// #include <string.h>

// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main()
// {
//     CATString c1;
//     CATString c2("c2");
//     CATString c3;
//     c3 = c2;
//     CATString c4(c3);
//     cout << c1 << endl;
//     cout << c2 << endl;
//     cout << c3 << endl;
//     cout << c4 << endl;

//     return 0;
// }

// #ifndef __COMPLEX__
// #define __COMPLEX__
// class Complex
// {

// public:
//     Complex(const double real = 0, const double imag = 0) : m_real(real), m_imag(imag) {}

//     Complex &operator+=(const Complex &other);
//     // Complex &operator+(const Complex &other);

// private:
//     double m_real, m_imag;
//     friend Complex &__doapl(Complex *ths, const Complex &r);
//     friend ostream &operator<<(ostream &os, const Complex &other);
//     friend Complex operator+(const Complex ths, const Complex &other);
// };

// Complex &__doapl(Complex *ths, const Complex &r)
// {
//     ths->m_real += r.m_real;
//     ths->m_imag += r.m_imag;
//     return *ths;
// }

// Complex &
// Complex::operator+=(const Complex &other)
// {
//     return __doapl(this, other);
// }

// Complex
// operator+(const Complex ths, const Complex &other)
// {
//     return Complex(ths.m_real + other.m_real, ths.m_imag + other.m_imag);
// }

// ostream &operator<<(ostream &os, const Complex &other)
// {
//     os << other.m_real << " " << other.m_imag;
//     return os;
// }

// #endif

// int main(int argc, char const *argv[])
// {

//     Complex c1(1, 1);
//     Complex c2(c1);
//     Complex c3;
//     c3 = c2;
//     Complex c4(c3);

//     c4 += c1;

//     cout << c1 << endl;
//     cout << c2 << endl;
//     cout << c3 << endl;
//     cout << c4 << endl;

//     c4 = c4 + c3;
//     cout << c4 << endl;

//     return 0;
// // }
// #include <list>
// class Observer
// {
// public:
//     virtual void update(int x)
//     {
//         cout << "Observer update on: " << x << endl;
//     }
// };

// class ObserverCar : public Observer
// {
// public:
//     void update(int x)
//     {
//         cout << "ObserverCar update on: " << x << endl;
//     }
// };

// class Subject
// {
// public:
//     Subject(int x) : m_value(x) {}
//     void addobj(Observer *obs)
//     {
//         m_list.push_back(obs);
//     }

//     void deleteobj(Observer *obs)
//     {
//         m_list.remove(obs);
//         move(obs);
//     }

//     void changevalue(int x)
//     {
//         m_value = x;
//         for (auto &obs : m_list)
//         {
//             obs->update(x);
//         }
//     }

// private:
//     list<Observer *> m_list;
//     int m_value;
// };

// int main(int argc, char const *argv[])
// {
//     Observer *obs1 = new Observer;
//     Observer *obs2 = new Observer;
//     Subject s(1);
//     s.addobj(obs1);
//     s.addobj(obs2);
//     s.changevalue(100);

//     s.deleteobj(obs1);
//     s.changevalue(10);

//     Observer *car1 = new ObserverCar;
//     s.addobj(car1);
//     s.changevalue(100);

//     return 0;
// // }
// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         // else
//         // {
//         //     m_data = new char[1];
//         //     *m_data = '\0';
//         // }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &string);
// };

// ostream &operator<<(ostream &os, const CATString &string)
// {
//     os << string.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     // CATString c2("hello");
//     // CATString c3(c2);
//     // CATString c4;
//     // c4 = c2;
//     // cout << c1 << endl;
//     // cout << c2 << endl;
//     // cout << c2 << endl;
//     // cout << c3 << endl;

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &str);
// };

// ostream &operator<<(ostream &os, const CATString &str)
// {
//     os << str.m_data;
//     return os;
// }
// int main(int argc, char const *argv[])
// {
//     CATString c1;
//     CATString c2("c2");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }
// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void set_func(pfunc func)
//     {
//         m_func = func;
//     }
//     void let_run(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     caller c1;
//     c1.set_func(test);
//     c1.let_run(3, "hello world");

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_int(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_int * 2;
//     }

// private:
//     int m_result;
//     int m_int;
// };

// int main(int argc, char const *argv[])
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << fur.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>

// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &out, const CATString &other);
// };

// ostream &operator<<(ostream &out, const CATString &other)
// {
//     out << other.m_data;
//     return out;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString s1;
//     CATString s2("hello");
//     CATString s3(s2);
//     CATString s4;
//     s4 = s3;

//     cout << s1 << endl;
//     cout << s2 << endl;
//     cout << s3 << endl;
//     cout << s4 << endl;

//     return 0;
// }

// class complex
// {
// public:
//     complex(int x = 0, int y = 0) : real(x), imag(y) {}
//     complex(const complex &other)
//     {
//         this->real = other.real;
//         this->imag = other.imag;
//     }
//     complex operator+(const complex &other);

// private:
//     double real;
//     double imag;
//     friend complex __doapl(complex *ths, const complex &r);
//     friend ostream &operator<<(ostream &os, const complex &r);
// };

// complex __doapl(complex *ths, const complex &r)
// {
//     return complex(ths->real + r.real, ths->imag + r.imag);
// }

// complex complex::operator+(const complex &r)
// {
//     return __doapl(this, r);
// }

// ostream &operator<<(ostream &os, const complex &r)
// {
//     os << r.real << " " << r.imag << endl;
//     return os;
// }
// int main(int argc, char const *argv[])
// {
//     complex c1(1, 1);
//     complex c2(c1);
//     complex c3;
//     c3 = c2;

//     complex c4;
//     c4 = c2 + c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(3, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_result;
//     int m_id;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {

//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &fur : futures)
//     {
//         std::cout << fur.get() << std::endl;
//     }
//     return 0;
// }

// #include <list>
// class observer
// {
// public:
//     void update()
//     {
//         std::cout << "observer update" << std::endl;
//     }
// };

// class subject
// {
// public:
//     subject(int x) : m_id(x) {}
//     void add(observer *obs)
//     {
//         m_list.push_back(obs);
//     }
//     void remove(observer *obs)
//     {
//         m_list.remove(obs);
//     }
//     void changevalue(int value)
//     {
//         m_id = value;
//         for (auto &obs : m_list)
//         {
//             obs->update();
//         }
//     }

// private:
//     list<observer *> m_list;
//     int m_id;
// };

// int main()
// {
//     subject s1(100);
//     observer *ob1 = new observer;
//     observer *ob2 = new observer;
//     s1.add(ob1);
//     s1.add(ob2);
//     s1.changevalue(10);

//     return 0;
// }

// class Animal
// {
// public:
//     virtual void talk()
//     {
//         std::cout << "Animal talk..." << std::endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     void talk()
//     {
//         std::cout << "Dog talk..." << std::endl;
//     }
// };

// void test(Animal *obj)
// {
//     obj->talk();
// }

// int main()
// {
//     Animal *obj = new Dog;
//     test(obj);

//     return 0;
// }

// class CDocument
// {
// public:
//     void onFileOpen()
//     {
//         open();
//         serialize();
//         close();
//     }

// private:
//     void open()
//     {
//         std::cout << "open" << std::endl;
//     }

//     virtual void serialize() = 0;
//     void close()
//     {
//         std::cout << "close" << std::endl;
//     }
// };

// class MyDoc : public CDocument
// {
// public:
//     void serialize()
//     {
//         std::cout << "mydoc serialize" << std::endl;
//     }
// };

// int main()
// {
//     MyDoc md1;
//     md1.onFileOpen();
// }

// class Business
// {
// public:
//     void docharge(int x)
//     {
//         std::cout << "charge " << x << std::endl;
//     }
// };

// class CMCC : public Business
// {
// public:
//     void docharge(int x)
//     {
//         if (x < 50)
//         {
//             std::cout << "need >50" << std::endl;
//             return;
//         }
//         m_cmcc = new Business;
//         m_cmcc->docharge(x);
//         delete m_cmcc;
//     }

// private:
//     Business *m_cmcc;
// };

// int main(int argc, const char **argv)
// {
//     // CMCC c1;  这个逻辑不对
//     // c1.docharge(10);
//     // c1.docharge(100);
//     // CMCC *c1 = new CMCC;
//     // c1->docharge(10);
//     // c1->docharge(100);

//     Business * obj = new CMCC;

//     return 0;
// }

// class Fruit
// {
// public:
//     virtual void show()
//     {
//         std::cout << "this is Fruit" << std::endl;
//     }

// private:
//     string name;
// };

// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         std::cout << "this is Apple" << std::endl;
//     }
// };

// class Factory
// {
// public:
//     Fruit CreateFruit()
//     {
//     }

// private:
//     Fruit *f;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };
// int main(int argc, char const *argv[])
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(3, "t");
//     return 0;
// }
// ;

// #include <iostream>
// using namespace std;
// template <class T1, class T2>
// class Fruit
// {
// public:
//     // 声明成员变量
//     T1 name;
//     T2 price;
//     // 定义构造函数
//     Fruit(T1 n, T2 p)
//     {
//         name = n;
//         price = p;
//     }
//     // 声明成员函数，并在类外部定义
//     void introduce();
// };

// template <class T1, class T2>
// void Fruit<T1, T2>::introduce()
// {
//     cout << "名称为：" << name << endl;
//     cout << "价格为：" << price << endl;
// }

// int main()
// {

//     // 实例化一个Fruit对象
//     Fruit<string, int> apple("苹果", 6);
//     // 调用成员函数
//     apple.introduce();
//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller1
// {
// public:
//     void setfunc(pfunc f)
//     {
//         m_func = f;
//     }
//     void letfunc(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {

//     caller1 c1;
//     c1.setfunc(test);
//     c1.letfunc(10, "helloworld");

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//         // std::cout << m_result << std::endl;
//     }

// private:
//     int m_id;
//     int m_result;
// };
// // #include <future>
// int main(int argc, char const *argv[])
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

//     vector<std::future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc func)
//     {
//         m_func = func;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(Test);
//     c1.letrun(3, "hello world");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_result;
//     int m_id;
// };

// int main(int argc, char const *argv[])
// {
//     vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <cstring>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             // strcpy(*m_data, '\0');
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = NULL;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = NULL;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString s1;
//     CATString s2("hello");
//     CATString s3(s2);
//     CATString s4 = s3;

//     CATString s5;
//     s5 = s4;

//     std::cout << s1 << std::endl;
//     std::cout << s2 << std::endl;
//     std::cout << s3 << std::endl;
//     std::cout << s4 << std::endl;
//     std::cout << s5 << std::endl;

//     return 0;
// }

// shared_ptr
// #include <iostream>
// #include <memory>
// #include <thread>
// #include <chrono>
// #include <mutex>

// struct Base
// {
//     Base() { std::cout << "  Base::Base()\n"; }
//     // Note: non-virtual destructor is OK here
//     ~Base() { std::cout << "  Base::~Base()\n"; }
// };

// struct Derived : public Base
// {
//     Derived() { std::cout << "  Derived::Derived()\n"; }
//     ~Derived() { std::cout << "  Derived::~Derived()\n"; }
// };

// void thr(std::shared_ptr<Base> p)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::shared_ptr<Base> lp = p; // thread-safe, even though the
//                                   // shared use_count is incremented
//     {
//         static std::mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "local pointer in a thread:\n"
//                   << "  lp.get() = " << lp.get()
//                   << ", lp.use_count() = " << lp.use_count() << '\n';
//     }
// }

// int main()
// {
//     std::shared_ptr<Base> p = std::make_shared<Derived>();

//     std::cout << "Created a shared Derived (as a pointer to Base)\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     std::thread t1(thr, p), t2(thr, p), t3(thr, p);
//     p.reset(); // release ownership from main
//     std::cout << "Shared ownership between 3 threads and released\n"
//               << "ownership from main:\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     t1.join();
//     t2.join();
//     t3.join();
//     std::cout << "All threads completed, the last one deleted Derived\n";
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         // std::this_thread::sleep_for(std::chrono::seconds(2));
//         cout << y << '\n'
//              << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setFunc(pfunc func)
//     {
//         m_func = func;
//     }
//     void letRun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, const char **argv)
// {
//     caller c1;
//     c1.setFunc(test);
//     c1.letRun(6, "million");

//     return 0;
// }

// class CATString
// {
// public:
// private:
//     char *m_data;
// };

// void test(int n, string y)
// {
//     while (n-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letRun(int n, string m)
//     {
//         m_func(n, m);
//     }

// private:
//     pfunc m_func;
// };

// int main()
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letRun(6, "helloworld");
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}

//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */

//     vector<Task> tasks{Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &x : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, x));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &p)
//     {
//         if (this != &p)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(p.m_data) + 1];
//             strcpy(m_data, p.m_data);
//         }
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &p);
// };

// ostream &operator<<(ostream &os, const CATString &p)
// {
//     os << p.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {

//     CATString c1;
//     CATString c2("helloc2");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "helloworld");

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &t : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, t));
//     }

//     for (auto &t : futures)
//     {
//         std::cout << t.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     CATString c1;
//     CATString c2("hello");
//     CATString c3;
//     c3 = c2;

//     CATString c4(c3);
//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {

//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_data(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_data * 2;
//     }

// private:
//     int m_data;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &f : futures)
//     {
//         std::cout << f.get() << std::endl;
//     }

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &out, const CATString &other);
// };

// ostream &operator<<(ostream &out, const CATString &other)
// {
//     out << other.m_data;
//     return out;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     shared_ptr<int> sp(new int(1));
//     std::cout << std::boolalpha
//               << sp.unique() << std::endl;
//     std::cout << sp.use_count() << std::endl;

//     shared_ptr<int> sp2(sp);
//     std::cout << sp.unique() << std::endl;
//     std::cout << sp.use_count() << std::endl;

//     // sp.reset();
//     // std::cout << sp.unique() << std::endl;
//     // std::cout << sp.use_count() << std::endl;

//     std::cout << sp.get() << std::endl;
//     std::cout << *sp.get() << std::endl;

//     return 0;
// }

// class Fruit
// {
// public:
//     virtual void show() {}

// private:
// };

// class Apple : public Fruit
// {

// public:
//     void show()
//     {
//         cout << "Apple show" << endl;
//     }
// };

// class FruitFactory
// {

// public:
//     Fruit *CreateFruit(string Fruit)
//     {
//         fruit = new Fruit;
//         return fruit;
//     }

// private:
//     Fruit *fruit;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     FruitFactory ff;
//     Fruit *f = ff.CreateFruit("Apple");
//     f->show();

//     return 0;
// }

// class Animal
// {
// public:
//     virtual void show() { std::cout << "Animal." << std::endl; }

// private:
// };

// class Dog : public Animal
// {
// public:
//     virtual void show() { std::cout << "Dog." << std::endl; }
// };

// class Cat : public Animal
// {
// public:
//     virtual void show() { std::cout << "Cat." << std::endl; }
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     Animal *obj = new Dog();
//     obj->show();
//     std::cout << "obj:" << obj << std::endl;

//     delete obj;
//     obj = new Cat();
//     obj->show();
//     std::cout << "obj:" << obj << std::endl;

//     return 0;
// }

// #include <list>
// class subject;

// class observer
// {
// public:
//     void update()
//     {
//         std::cout << "obs update." << std::endl;
//     }
// };

// class subject
// {
// public:
//     subject(int x) : m_data(x) {}
//     void addobs(observer *obs)
//     {
//         m_list.push_back(obs);
//     }

//     void deleteobs(observer *obs)
//     {
//         m_list.remove(obs);
//     }

//     void changedata(int x)
//     {
//         m_data = x;
//         for (auto &x : m_list)
//         {
//             x->update();
//         }
//     }

// private:
//     list<observer *> m_list;
//     int m_data;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     observer *obs1 = new observer;
//     observer *obs2 = new observer;
//     observer *obs3 = new observer;

//     subject *sub = new subject(10);
//     sub->addobs(obs1);
//     sub->addobs(obs2);
//     sub->addobs(obs3);
//     sub->changedata(100);

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     shared_ptr<int> sp(new int(10));
//     std::cout << sp.use_count() << std::endl;

//     {
//         shared_ptr<int> sp2(sp);
//         std::cout << sp2.use_count() << std::endl;
//         std::cout << sp2 << std::endl;
//     }
//     std::cout << sp.use_count() << std::endl;

//     std::cout << sp << std::endl;
//     // std::cout << sp2 << std::endl;

//     // sp.reset(new int(1));
//     // std::cout << sp << std::endl;
//     // std::cout << sp2 << std::endl;

//     // std::shared_ptr<int> sp1 = std::make_shared<int>();
//     // *sp1 = 100;
//     // std::cout << *sp1 << std::endl;

//     // typedef pair<int, int> my_pair;
//     // shared_ptr<my_pair> mp(new my_pair(10, 10));
//     // std::cout << mp->first << std::endl;
//     // std::cout << mp->second << std::endl;

//     // std::cout << sp.use_count() << std::endl;
//     // std::cout << sp2.use_count() << std::endl;

//     // std::cout << *sp << std::endl;

//     // sp.reset();
//     // sp2.reset();
//     // sp.reset(new int(1));

//     // std::cout << sp.use_count() << std::endl;

//     // typedef std::pair<int, int> my_pair;
//     // shared_ptr<my_pair> pp(new my_pair(10, 20));
//     // std::cout << pp->first << std::endl;
//     // std::cout << pp->second << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &str)
//     {
//         m_data = new char[strlen(str.m_data) + 1];
//         strcpy(m_data, str.m_data);
//     }

//     CATString &operator=(const CATString &str)
//     {
//         if (this != &str)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(str.m_data) + 1];
//             strcpy(m_data, str.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &str);
// };

// ostream &operator<<(ostream &os, const CATString &str)
// {
//     os << str.m_data;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3 = c2;
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };
// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {

// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     std::shared_ptr<int> sp(new int(10));
//     std::cout << sp.unique() << std::endl;
//     std::cout << sp.use_count() << std::endl;

//     std::shared_ptr<int> sp2(sp);
//     std::cout << sp.unique() << std::endl;
//     std::cout << sp.use_count() << std::endl;

//     sp.reset(new int(1));
//     std::cout << sp.unique() << std::endl;
//     std::cout << sp.use_count() << std::endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     shared_ptr<int> sp(new int(10));

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }
// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//     std:
//         this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;
//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &f : futures)
//     {
//         std::cout << f.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data + 1)];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <memory>
// #include <thread>
// #include <chrono>
// #include <mutex>

// struct Base
// {
//     Base() { std::cout << "  Base::Base()\n"; }
//     // Note: non-virtual destructor is OK here
//     ~Base() { std::cout << "  Base::~Base()\n"; }
// };

// struct Derived : public Base
// {
//     Derived() { std::cout << "  Derived::Derived()\n"; }
//     ~Derived() { std::cout << "  Derived::~Derived()\n"; }
// };

// void thr(std::shared_ptr<Base> p)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::shared_ptr<Base> lp = p; // thread-safe, even though the
//                                   // shared use_count is incremented
//     {
//         static std::mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "local pointer in a thread:\n"
//                   << "  lp.get() = " << lp.get()
//                   << ", lp.use_count() = " << lp.use_count() << '\n';
//     }
// }

// int main()
// {
//     std::shared_ptr<Base> p = std::make_shared<Derived>();

//     std::cout << "Created a shared Derived (as a pointer to Base)\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     std::thread t1(thr, p), t2(thr, p), t3(thr, p);
//     p.reset(); // release ownership from main
//     std::cout << "Shared ownership between 3 threads and released\n"
//               << "ownership from main:\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     t1.join();
//     t2.join();
//     t3.join();
//     std::cout << "All threads completed, the last one deleted Derived\n";
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }
//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &string);
// };

// ostream &operator<<(ostream &os, const CATString &string)
// {
//     os << string.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// class Base
// {

// public:
//     Base()
//     {
//         std::cout << "Base ctor" << std::endl;
//     }
//     ~Base()
//     {
//         std::cout << "Base dtor" << std::endl;
//     }
// };

// class Derived : public Base
// {
// public:
//     Derived()
//     {
//         std::cout << "Derived ctor" << std::endl;
//     }
//     ~Derived()
//     {
//         std::cout << "Derived dtor" << std::endl;
//     }
// };

// void thr(shared_ptr<Base> sp)
// {
//     std::cout << "in thr" << std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     shared_ptr<Base> pp = sp;
//     {

//         static std::mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "local pointer in a thread:\n"
//                   << "  lp.get() = " << pp.get()
//                   << ", lp.use_count() = " << pp.use_count() << '\n';
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     shared_ptr<Base> sp = make_shared<Derived>();

//     std::cout << "sp.get(): " << sp.get() << std::endl;
//     std::cout << "sp.use_count(): " << sp.use_count() << std::endl;

//     thread t1(thr, sp);
//     thread t2(thr, sp);
//     thread t3(thr, sp);

//     sp.reset();

//     std::cout << "sp.get(): " << sp.get() << std::endl;
//     std::cout << "sp.use_count(): " << sp.use_count() << std::endl;

//     t1.join();
//     t2.join();
//     t3.join();

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }
// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &t : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, t));
//     }

//     for (auto &f : futures)
//     {
//         std::cout << f.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp = std::make_shared(new int(10));

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)

//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &f : futures)
//     {
//         std::cout << f.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");

//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp(new int(1));
//     std::cout << *sp << std::endl;
//     std::cout << sp << std::endl;
//     std::cout << sp.use_count() << std::endl;
//     std::cout << sp.get() << std::endl;

//     sp.reset();

//     std::cout << sp.use_count() << std::endl;
//     sp.reset(new int(1));
//     std::cout << sp.use_count() << std::endl;
//     sp.reset();
//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
// Task(int x =0): m_id(x){}
// int operator()()
// {
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     return m_result = m_id * 2;
// }

// private:
//    int m_id;
//    int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks ={Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }
//     for(auto & future: futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>

// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;
//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp(new int(2024));
//     std::cout << *sp << std::endl;

//     std::shared_ptr<int> sp1 = std::make_shared<int>() return 0;
// }

// int addit(int x, int y)
// {
//     return x + y;
// }

// typedef int (*pfunc)(int, int);

// int main(int argc, char const *argv[])
// {
//     /* code */

//     pfunc p1 = addit;
//     std::cout << p1(1, 1) << std::endl;
//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {

//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc pf)
//     {
//         m_func = pf;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));

//     }
//     for(auto & future: futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);

//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void foo(const shared_ptr<int> &i)
// {
//     (*i)++;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp = std::make_shared<int>(1);
//     std::cout << sp << std::endl;
//     std::cout << *sp << std::endl;

//     auto sp1 = new int(2);
//     std::cout << sp1 << std::endl;
//     std::cout << *sp1 << std::endl;

//     auto sp2 = std::make_shared<int>(12);
//     foo(sp2);
//     std::cout << *sp2 << std::endl;

//     return 0;
// }

// class Base
// {
// public:
//     Base()
//     {
//         std::cout << "Base ctor" << std::endl;
//     }
//     ~Base()
//     {
//         std::cout << "Base dtor" << std::endl;
//     }
// };

// class Derived : public Base
// {

// public:
//     Derived()
//     {
//         std::cout << "Derived ctor" << std::endl;
//     }
//     ~Derived()
//     {
//         std::cout << "Derived dtor" << std::endl;
//     }
// };

// void thr(std::shared_ptr<Base> p)
// {
//     std::shared_ptr<Base> lp = p;
//     // std::cout << p << std::endl;

//     {
//         mutex io_mutex;
//         std::lock_guard<mutex> lk(io_mutex);
//         std::cout << "lp.usecount: " << lp.use_count() << std::endl;
//         std::cout << "lp.get: " << lp.get() << std::endl;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<Base> p = std::make_shared<Derived>();

//     std::cout << "p.usecount: " << p.use_count() << std::endl;
//     std::cout << "p.get: " << p.get() << std::endl;

//     thread t1(thr, p);
//     thread t2(thr, p);
//     thread t3(thr, p);

//     p.reset();

//     t1.join();
//     t2.join();
//     t3.join();

//     // Base b;
//     // Derived d;
//     return 0;
// }

// class Base
// {
// public:
//     Base()
//     {
//         std::cout << "Base ctor" << std::endl;
//     }
//     ~Base()
//     {
//         std::cout << "Base dtor" << std::endl;
//     }
// };

// class Derived : public Base
// {

// public:
//     Derived()
//     {
//         std::cout << "Derived ctor" << std::endl;
//     }
//     ~Derived()
//     {
//         std::cout << "Derived dtor" << std::endl;
//     }
// };

// void thr(shared_ptr<Base> p)
// {
//     shared_ptr<Base> lp = p;
//     {
//         std::mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "lock.get():" << lp.get() << std::endl;
//         std::cout << "lock.usecount():" << lp.use_count() << std::endl;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     std::shared_ptr<Base> p = std::make_shared<Derived>();

//     thread t1(thr, p);
//     thread t2(thr, p);
//     thread t3(thr, p);

//     std::cout << "p.get():" << p.get() << std::endl;
//     std::cout << "p.usecount():" << p.use_count() << std::endl;

//     p.reset();
//     t1.join();
//     t2.join();
//     t3.join();

//     // std::shared_ptr<Base> p = std::make_shared<Derived>();

//     // std::cout << "p.usecount: " << p.use_count() << std::endl;
//     // std::cout << "p.get: " << p.get() << std::endl;

//     // thread t1(thr, p);
//     // thread t2(thr, p);
//     // thread t3(thr, p);

//     // p.reset();

//     // t1.join();
//     // t2.join();
//     // t3.join();

//     std::cout << "p.get():" << p.get() << std::endl;
//     std::cout << "p.usecount():" << p.use_count() << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello world");
//     return 0;
// }

// class Task
// {
//     public:
//     Task(int x):m_id(x){}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

//     private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */

//     vector<Task> tasks ={Task(1), Task(2), Task(3), Task(4), Task(5),Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for(auto& future: futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }

//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// class Base
// {
// public:
//     Base()
//     {
//         std::cout << "Base ctor" << std::endl;
//     }

//     ~Base()
//     {
//         std::cout << "Base dtor" << std::endl;
//     }
// };

// class Derived : public Base
// {
// public:
//     Derived()
//     {
//         std::cout << "Derived ctor" << std::endl;
//     }

//     ~Derived()
//     {
//         std::cout << "Derived dtor" << std::endl;
//     }
// };

// void thr(std::shared_ptr<Base> p)
// {

//     shared_ptr<Base> lp = p;

//     {
//         mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "lp.get(): " << lp.get() << std::endl;
//         std::cout << "lp.use_count(): " << lp.use_count() << std::endl;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<Base> p = std::make_shared<Derived>();
//     std::cout << "p.get(): " << p.get() << std::endl;
//     std::cout << "lp.use_count(): " << p.use_count() << std::endl;

//     thread t1(thr, p);
//     thread t2(thr, p);
//     thread t3(thr, p);

//     std::cout << "p.get(): " << p.get() << std::endl;
//     std::cout << "lp.use_count(): " << p.use_count() << std::endl;

//     p.reset();

//     std::cout << "after reset" << std::endl;
//     std::cout << "p.get(): " << p.get() << std::endl;
//     std::cout << "lp.use_count(): " << p.use_count() << std::endl;

//     t1.join();
//     t2.join();
//     t3.join();

//     std::cout << "p.get(): " << p.get() << std::endl;
//     std::cout << "lp.use_count(): " << p.use_count() << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {

// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };
// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for(auto &future: futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)

//         {

//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {

//     os << obj.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);

//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// class Base
// {
// public:
//     Base()
//     {
//         std::cout << "Base ctor" << std::endl;
//     }
//     ~Base()
//     {
//         std::cout << "Base dtor" << std::endl;
//     }
// };

// class Derived : public Base
// {

// public:
//     Derived()
//     {
//         std::cout << "Derived ctor" << std::endl;
//     }
//     ~Derived()
//     {
//         std::cout << "Derived dtor" << std::endl;
//     }
// };

// void thr(std::shared_ptr<Base> p)
// {
//     std::shared_ptr<Base> lp = p;

//     {
//         std::mutex mutex_io;
//         std::lock_guard<std::mutex> lk(mutex_io);
//         std::cout << lp.get() << std::endl;
//         std::cout << lp.use_count() << std::endl;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<Base> p = std::make_shared<Derived>();
//     std::cout << p.get() << std::endl;
//     std::cout << p.use_count() << std::endl;

//     thread t1(thr, p);
//     thread t2(thr, p);
//     thread t3(thr, p);
//     thread t4(thr, p);

//     p.reset();
//     std::cout << p.get() << std::endl;
//     std::cout << p.use_count() << std::endl;

//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();

//     std::cout << p.get() << std::endl;
//     std::cout << p.use_count() << std::endl;

//     return 0;
// // }

// #include <iostream>
// #include <memory>
// #include <thread>
// #include <chrono>
// #include <mutex>

// struct Base
// {
//     Base() { std::cout << "  Base::Base()\n"; }
//     // Note: non-virtual destructor is OK here
//     ~Base() { std::cout << "  Base::~Base()\n"; }
// };

// struct Derived : public Base
// {
//     Derived() { std::cout << "  Derived::Derived()\n"; }
//     ~Derived() { std::cout << "  Derived::~Derived()\n"; }
// };

// void thr(std::shared_ptr<Base> p)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::shared_ptr<Base> lp = p; // thread-safe, even though the
//     // shared use_count is incremented
//     {
//         static std::mutex io_mutex;
//         std::lock_guard<std::mutex> lk(io_mutex);
//         std::cout << "local pointer in a thread:\n"
//                   << "  lp.get() = " << lp.get()
//                   << ", lp.use_count() = " << lp.use_count() << '\n';
//         std::cout << "thread_id------> " << this_thread::get_id() << std::endl;
//     }
// }

// int main()
// {
//     std::shared_ptr<Base> p = std::make_shared<Derived>();

//     std::cout << "Created a shared Derived (as a pointer to Base)\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     std::thread t1(thr, p), t2(thr, p), t3(thr, p);
//     p.reset(); // release ownership from main
//     std::cout << "Shared ownership between 3 threads and released\n"
//               << "ownership from main:\n"
//               << "  p.get() = " << p.get()
//               << ", p.use_count() = " << p.use_count() << '\n';
//     t1.join();
//     t2.join();
//     t3.join();

//     std::cout << "All threads completed, the last one deleted Derived\n";
// }

// void addone(int *n)
// {
//     mutex mtx;
//     mtx.lock();
//     for (int i = 0; i < 100000; i++)
//     {

//         *n += 1;
//     }
//     mtx.unlock();
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     int n = 0;
//     thread t1(addone, &n);
//     thread t2(addone, &n);
//     // thread t2(addone, 100);
//     t1.join();
//     t2.join();
//     std::cout << n << std::endl;

//     return 0;
// }

// mutex mtx;
// int count = 0;

// void addit()
// {
//     for (int i = 0; i < 100000; i++)
//     {
//         unique_lock<mutex> lk(mtx);
//         count++;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     thread t1(addit);
//     thread t2(addit);

//     t1.join();
//     t2.join();

//     std::cout << "count: " << count << std::endl;

//     return 0;
// }

mutex mtx;
int ticketcount = 200;

void sellticketold()
{

    while (ticketcount > 0)
    {
        unique_lock<mutex> lk(mtx);
        if (ticketcount > 0)
        {
            std::cout << "sell ticket: " << std::this_thread::get_id() << ": " << ticketcount << std::endl;
            ticketcount--;
            // std::this_thread::sleep_for(std::chrono::microseconds(1));
        }

        // if (ticketcount == 0)
        // {
        //     break;
        // }
    }

    // while (ticketcount > 0)
    // {
    //     unique_lock<mutex> lock(mtx);
    //     if (ticketcount > 0)
    //     {

    //         cout << "sell ticket: " << std::this_thread::get_id() << ": " << ticketcount << endl;
    //         ticketcount--;
    //         // usleep(1);
    //         // std::this_thread::sleep_for(std::chrono::microseconds(1));
    //     }
    // }
}

// bool Aready = true;
// bool Bready = false;

// condition_variable cv;
// void sellticketA()
// {
//     while (ticketcount > 0)
//     {
//         unique_lock<mutex> lock(mtx);
//         cv.wait(lock, []
//                 { return Aready; });
//         if (ticketcount > 0)
//         {

//             cout << "sell ticket: " << std::this_thread::get_id() << ": " << ticketcount << endl;
//             ticketcount--;
//             // usleep(1);
//             // std::this_thread::sleep_for(std::chrono::microseconds(1));
//         }
//     }
// }

// void sellticketB()
// {
//     while (ticketcount > 0)
//     {
//         unique_lock<mutex> lock(mtx);
//         if (ticketcount > 0)
//         {

//             cout << "sell ticket: " << std::this_thread::get_id() << ": " << ticketcount << endl;
//             ticketcount--;
//             // usleep(1);
//             // std::this_thread::sleep_for(std::chrono::microseconds(1));
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     thread t1(sellticketA);
//     thread t2(sellticketB);
//     t1.join();
//     t2.join();

//     return 0;
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {

//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc y)
//     {
//         m_func = y;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };
// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(Test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */

//     vector<Task> tasks = {Task(0), Task(1), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std ::endl;
//     }

//     return 0;
// // }

// #include <string.h>

// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &p)
//     {
//         m_data = new char[strlen(p.m_data) + 1];
//         strcpy(m_data, p.m_data);
//     }

//     CATString &operator=(const CATString &p)
//     {
//         if (this != &p)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(p.m_data) + 1];
//             strcpy(m_data, p.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &p);
// };

// ostream &operator<<(ostream &os, const CATString &p)
// {
//     os << p.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp(new int(2024));
//     std::cout << *sp << std::endl;

//     std::shared_ptr<int> sp1 = std::make_shared<int>(2024);
//     std::cout << *sp1 << std::endl;

//     return 0;
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfun(Test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data + 1)];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     std::shared_ptr<int> sp(new int(2024));
//     std::cout << *sp << std::endl;

//     std::shared_ptr<int> sp1 = std::make_shared<int>(2024);
//     std::cout << *sp1 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     std::shared_ptr<int> sp(new int(2024));
//     std::cout << *sp << std::endl;
//     std::cout << sp << std::endl;

//     return 0;
// // }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(Test);
//     c1.letrun(6, "hello");

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()

//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks ={Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto &task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future: futures){

//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &out, const CATString &obj);
// };

// ostream &operator<<(ostream &out, const CATString &obj)
// {
//     out << obj.m_data;
//     return out;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);

//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     string str ="hello";
//     vector<string> v;

//     v.push_back(str);
//     std::cout << "str after push_back: " << str << std::endl;

//     v.push_back(std::move(str));

//     std::cout << "str after move: " << str << std::endl;

//     std::cout << v[0] << v[1] << std::endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */

//     std::shared_ptr<int> sp = std::make_shared<int>(2024);
//     std::cout << *sp << std::endl;

//     std::shared_ptr<int> sp1(new int(2024));
//     std::cout << *sp1 << std::endl;

//     return 0;
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(6, "hello");
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(Test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
//     public:
//     Task(int x=0):m_id(x){}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

//     private:

//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks ={ Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task: tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for(auto & future: futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {

// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else

//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         // return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <memory>
// #include <utility>

// struct A
// {
//     A(int &&n) { std::cout << "rvalue overload, n=" << n << "\n"; }
//     A(int &n) { std::cout << "lvalue overload, n=" << n << "\n"; }
// };

// class B
// {
// public:
//     template <class T1, class T2, class T3>
//     B(T1 &&t1, T2 &&t2, T3 &&t3) : a1_{std::forward<T1>(t1)},
//                                    a2_{std::forward<T2>(t2)},
//                                    a3_{std::forward<T3>(t3)}
//     {
//     }

// private:
//     A a1_, a2_, a3_;
// };

// template <class T, class U>
// std::unique_ptr<T> make_unique1(U &&u)
// {
//     return std::unique_ptr<T>(new T(std::forward<U>(u)));
// }

// template <class T, class... U>
// std::unique_ptr<T> make_unique2(U &&...u)
// {
//     return std::unique_ptr<T>(new T(std::forward<U>(u)...));
// }

// int main()
// {
//     auto p1 = make_unique1<A>(2); // rvalue
//     int i = 1;
//     auto p2 = make_unique1<A>(i); // lvalue

//     std::cout << "B\n";
//     auto t = make_unique2<B>(2, i, 3);
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class Caller
// {
// public:
//     void setfunc(pfunc y)
//     {

//         m_func = y;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     Caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         // tasks.push_back(std::async(std::launch::async, task));
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }
//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &out, const CATString &string);
// };

// ostream &operator<<(ostream &out, const CATString &string)
// {
//     out << string.m_data;
//     return out;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc func)
//     {
//         m_func = func;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");

//     return 0;
// }

// class Task
// {
// public:
//     Task(int x = 0) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */

//     vector<Task> tasks = {Task(0), Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for (auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &other)
//     {
//         m_data = new char[strlen(other.m_data) + 1];
//         strcpy(m_data, other.m_data);
//     }
//     CATString &operator=(const CATString &other)
//     {
//         if (this != &other)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(other.m_data) + 1];
//             strcpy(m_data, other.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &other);
// };

// ostream &operator<<(ostream &os, const CATString &other)
// {
//     os << other.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class Caller
// {
// public:
//     void setfun(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     Caller c1;
//     c1.setfun(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for(auto & task:tasks)
//     {
//         futures.push_back(std::async(std::launch::async,  task));
//     }

//     for(auto & future:futures)
//     {
//         std::cout << future.get() << std::endl;
//     }
//     return 0;
// }

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }

//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(std::ostream &os, const CATString &is_object);
// };

// ostream &operator<<(std::ostream &os, const CATString &is_object)
// {
//     os << is_object.m_data;
//     return os;
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     CATString c1;
//     CATString c2("hello");
//     CATString c3(c2);
//     CATString c4;
//     c4 = c3;

//     std::cout << c1 << std::endl;
//     std::cout << c2 << std::endl;
//     std::cout << c3 << std::endl;
//     std::cout << c4 << std::endl;

//     return 0;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class Caller
// {
// public:
//     void setfunc(pfunc func)
//     {
//         m_func = func;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     Caller c1;
//     c1.setfunc(test);
//     c1.letrun(6, "hello");
//     return 0;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
//     vector<future<int>> futures;

//     for (auto &task : tasks)
//     {
//         futures.push_back(std::async(std::launch::async, task));
//     }

//     for(auto &future : futures)
//     {
//         std::cout << future.get() << std::endl;
//     }

//     return 0;
// }

#include <string.h>
class CATString
{
public:
    CATString(const char *str = 0)
    {
        if (str)
        {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }
    CATString(const CATString &obj)
    {
        m_data = new char[strlen(obj.m_data) + 1];
        strcpy(m_data, obj.m_data);
    }
    CATString &operator=(const CATString &obj)
    {
        if (this != &obj)
        {
            delete[] m_data;
            m_data = new char[strlen(obj.m_data) + 1];
            strcpy(m_data, obj.m_data);
        }
        return *this;
    }
    ~CATString()
    {
        if (m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }

private:
    char *m_data;
    friend ostream &operator<<(ostream &os, const CATString &obj);
};

ostream &operator<<(ostream &os, const CATString &obj)
{
    os << obj.m_data;
    return os;
}

int main(int argc, char const *argv[])
{
    /* code */
    CATString c1;
    CATString c2("hello");
    CATString c3(c2);
    CATString c4;
    c4 = c3;

    std::cout << c1 << std::endl;

    std::cout << c2 << std::endl;

    std::cout << c3 << std::endl;

    std::cout << c4 << std::endl;

    return 0;
}
