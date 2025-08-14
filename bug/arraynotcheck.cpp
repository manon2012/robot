#include <iostream>
using namespace std;

int tcp[2] = {0};
bool flag = true;
int n = 99;
int i = 0;
void test03()
{
   while (1)
   {

      if (n < 100)
      {
         cout << "<100" << endl;
         n++;
      }
      else if (n < 110)
      {
         cout << "<110" << endl;
         n++;
         
         tcp[i]=n;
         std::cout <<"n:"<<n<<endl;
         std::cout <<"tcp["<<i<<"] = " << tcp[i] << endl;
         i++;
      }
      else
      {
         cout << "110" << endl;

         //flag = false;
          cout <<"flag:"<< flag << endl;
         break;
      }
   }
}
int main()
{
   test03();
   cout << "hello,world! tempalte2013" << endl;

   return 0;
}


/*
<100
<110
n:101
tcp[0] = 101
<110
n:102
tcp[1] = 102
<110
n:103
tcp[103] = 0  //数组越界后，第一次赋值为0, 为什么没有数组下标检查呢？
n:104
tcp[104] = 104
<110
n:105
tcp[105] = 105
<110
n:106
tcp[106] = 106
<110
n:107
tcp[107] = 107
<110
n:108
tcp[108] = 108
<110
n:109
tcp[109] = 109
<110
n:110
tcp[110] = 110
110
flag:1

*/