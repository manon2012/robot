#include <iostream>
#include <thread>
#include <future>
#include <vector>

// 定义一个简单的任务类
class Task
{
public:
    Task(int id) : id(id) {}

    int operator()()
    {
        // 执行一些异步操作
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return result = id * 2; // 计算结果
    }

    int getResult() const
    {
        return result;
    }

private:
    int id;     // 任务的标识符
    int result; // 计算结果
};

int main()
{
    // 创建一个包含4个任务的向量
    std::vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4)};

    // 创建一个线程池，并提交任务到线程池
    std::vector<std::future<int>> futures;
    for (auto &task : tasks)
    {
        futures.push_back(std::async(std::launch::async, task));
    }

    // 遍历未来的结果，并打印出来
    for (auto &future : futures)
    {
        std::cout << "Result: " << future.get() << std::endl; // 阻塞等待结果并获取
    }

    return 0;
}
