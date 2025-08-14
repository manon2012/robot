#include "thread"
#include "iostream"
#include "queue"
#include "condition_variable"
#include <mutex>

using namespace std;
class ProducerAndConsumerDemo
{
public:
  void producerNumber(); // 生产数据
  void consumerNumber(); // 消费数据
private:
  const int dataSize = 10;           // 总数据量
  queue<int> listBuffer;             // 数据缓存区
  const int bufferSize = 5;          // 缓存区大小
  condition_variable bufferNotEmpty; // 信号量--缓存区有数据了
  condition_variable bufferNotFull;  // 信号量--缓存区不满了
  mutex m_mutex;                     // 互斥量
};
void ProducerAndConsumerDemo::producerNumber()
{
  for (int i = 0; i < dataSize; ++i)
  {
    {
      unique_lock<mutex> locker(m_mutex);
      bufferNotFull.wait(locker, [&]()
                         { return listBuffer.size() < bufferSize; }); // 缓存区满了则阻塞
      listBuffer.push(i);
      cout << "生产者---生产了数字：" << i << ",当前 bufferSize:" << listBuffer.size() << endl;
    } // 解锁互斥量
    bufferNotEmpty.notify_one();
    this_thread::sleep_for(chrono::milliseconds(1000)); // 模拟生产耗时
  }
}
void ProducerAndConsumerDemo::consumerNumber()
{
  while (true)
  {
    {
      unique_lock<mutex> locker(m_mutex);
      bufferNotEmpty.wait(locker, [&]()
                          { return listBuffer.size() > 0; }); // 缓冲区为空则阻塞
      int i = listBuffer.front();
      listBuffer.pop();
      cout << "消费者---消费了数字：" << i << ",当前 bufferSize:" << listBuffer.size() << endl;
    } // 解锁互斥量
    bufferNotFull.notify_one();
    this_thread::sleep_for(chrono::milliseconds(2000)); // 模拟消费耗时
    if (listBuffer.empty())
      break;
  }
}
// 消费者---消费了数字：29,当前 bufferSize:0  这里hang住了  //TODO：
int main()
{
  ProducerAndConsumerDemo pcDemo;
  thread consumerThread(&ProducerAndConsumerDemo::producerNumber, &pcDemo);
  thread producerThread(&ProducerAndConsumerDemo::consumerNumber, &pcDemo);

  producerThread.join();
  consumerThread.join();

  return 0;
}