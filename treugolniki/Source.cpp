#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

//������� ������������ �� ���� �����������
double squar(double x1, double x2, double x3, double y1, double y2, double y3) {
    double p;
    p = ((x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3)) / 2;
    if (p < 0) 
    {
        p = -1 * p;
    }
    return p;
}

double dlina(double x, double y, double x1, double y1)
{
    double p = x * x - x1 * x1 + y * y - y1 * y1;
    if (p < 0) 
    {
        p = -1 * p;
    }
    return sqrt(p);
}

int main() 
{
    ifstream f1;
    f1.open("input.txt"); //������� ����
    double max = 0; //������������ �������
    double ko[3]; //����� ������� 

    if (!f1.is_open())  //�������� �������� �����
    {
        cout << "input not founded" << endl; //���� �� ����� ������
    }
    else
    {
        string xy[100]; //������ ��� : ������ 
        int k = 0; //���������� �����

        getline(f1, xy[k]); //��������� ������ ������
        while (xy[k] != "") // ���� ������ ������� �� ��������� �� ������
        {
            k++;
            getline(f1, xy[k]); //��������� ������

        }
 
        string* x1 = new string[k];  //������� ������� ������ ��� ��� ��� �������
        string* y1 = new string[k]; 

        float* x = new float[k]; // ����� �������� � �������,  ��������� � �������, � �� �����,���� ���� �������
        float* y = new float[k];

        for (int i = 0; i < k; i++) //����� ������ �� � � �
        {
            int pos = 0;
            pos = xy[i].find(" ");
            
            if (pos == -1) //���� ������ ������� �� ������ ����� (������ ���� ���������� �)
            {
                x1[i] = xy[i];
                y1[i] = "0";
            }
            else //���� ������ �������� � � � y
            {
                x1[i] = xy[i].substr(0, pos);
                y1[i] = xy[i].substr(pos, xy[i].length());
            }  
          
        }
        for (int i = 0; i < k; i++) //��������� �� ������� � ��� 
        {
            x[i] = stof(x1[i]);
            y[i] = stof(y1[i]);       
        }

        delete[] x1; //������ �� ����������
        delete[] y1;

        for (int i = 0; i < k; i++)  //����� ����� (������ �������) ----------------------------------------
        {
            cout << x[i] << " " << y[i] << endl;
        }
        double a;

        for (int i1 = 1; i1 < k; i1++) 
        {
            for (int i2 = i1+1; i2 < k; i2++) 
            {
                for (int i3 = i2+1; i3 < k; i3++)
                {
                    a = squar(x[i1], x[i2], x[i3], y[i1], y[i2], y[i3]);
                    if ((a > max) && ((x[i2] != x[i3]) && (y[i2] != y[i3])))
                    {
                        max = a;

                        ko[0] = i1;
                        ko[1] = i2;
                        ko[2] = i3;
                    }
                }
            }
        }  
        delete[] x; // ������ �� ����������
        delete[] y;
    }
    f1.close();

    ofstream f2;
    f2.open("output.txt");
    f2 << max << endl;
    for (int i = 0; i < 3; i++) {
        f2 << ko[i] << " ";
    }
    f2.close();

}
    

   