#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QVector>
#include "DianaAPI.h"


double rad_to_deg(double x) { return ((x) * 180.0 / 3.1415926); }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     qDebug() << 123;



     QFile file("sssss.txt");
     QVector<double> offset;
     QVector<QVector<double>> p;

     if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         QTextStream in(&file);
         QString line;

         while (!in.atEnd())
         {
             line = in.readLine(); // 读取第lineNumber行
             QStringList dataList = line.split(','); // 使用逗号分割字符串
//             qDebug()<<dataList[4];
             for (const QString &str : dataList)
             {
                 offset.push_back(str.toDouble());
             }
             p.push_back(offset);
             offset.clear();
         }

         file.close();
     }
 //    qDebug() << p;
     double pose[6] = {0.0};
     double poses[396][6];
     for (int i = 0; i < p.length(); i++)
     {
         homogeneous2Pose(p[i].data(), pose);
         memcpy(poses[i], pose, 48);

     }



     double j[7] = {1.95477,-0.867603,0.097913,1.89857,0.618196,-0.603535,-0.449946};

     double joints[395][7] = {{0.0}};
     double joint[7] = {0.0};
     inverse_ext(j, poses[0], joint);
     qDebug()<<poses[0][0];
     qDebug()<<poses[0][1];
     qDebug()<<poses[0][2];
     qDebug()<<poses[0][3];
     qDebug()<<poses[0][4];
     qDebug()<<poses[0][5];

     qDebug()<<joint[0];
     qDebug()<<joint[1];
qDebug()<<joint[2];
qDebug()<<joint[3];
qDebug()<<joint[4];
qDebug()<<joint[5];
qDebug()<<joint[6];

     for (int i = 0; i < p.length(); i++)
     {
         inverse_ext(joint, poses[i], joint);
         qDebug() << rad_to_deg(joint[0]) << "," << rad_to_deg(joint[1]) << "," << rad_to_deg(joint[2]) << ","
                  << rad_to_deg(joint[3]) << "," << rad_to_deg(joint[4]) << "," << rad_to_deg(joint[5]) << ","
                  << rad_to_deg(joint[6]);

         memcpy(joints[i], joint, 56);
     }



        qDebug() << 321;
    return a.exec();
}
