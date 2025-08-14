#include <iostream>
#include <QFile>
#include <QDebug>
#include <QVector>


using namespace std;


int main()
{


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
    for (int i = 0; i < p.length(); i++)
    {
        inverse_ext(joint, poses[i], joint);
        qDebug() << rad_to_deg(joint[0]) << "," << rad_to_deg(joint[1]) << "," << rad_to_deg(joint[2]) << ","
                 << rad_to_deg(joint[3]) << "," << rad_to_deg(joint[4]) << "," << rad_to_deg(joint[5]) << ","
                 << rad_to_deg(joint[6]);

        memcpy(joints[i], joint, 56);
    }






    cout << "Hello World!" << endl;
    return 0;
}
