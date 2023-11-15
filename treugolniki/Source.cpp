#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

//площадь треугольника по трем координатам
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
    f1.open("input.txt"); //находим файл
    double max = 0; //максимальеая площадь
    double ko[3]; //номер вершины 

    if (!f1.is_open())  //проверка открытия файла
    {
        cout << "input not founded" << endl; //если не нашел ошибка
    }
    else
    {
        string xy[100]; //скажем так : буффер 
        int k = 0; //количество точек

        getline(f1, xy[k]); //считываем первую строку
        while (xy[k] != "") // пока строка которую мы прочитали не пустая
        {
            k++;
            getline(f1, xy[k]); //считываем строку

        }
 
        string* x1 = new string[k];  //создаем сначала стринг так как так удобнее
        string* y1 = new string[k]; 

        float* x = new float[k]; // чтобы работать с числами,  переведем с стринга, а не сразу,чтоб было удобнее
        float* y = new float[k];

        for (int i = 0; i < k; i++) //делим строку на х и у
        {
            int pos = 0;
            pos = xy[i].find(" ");
            
            if (pos == -1) //если строка состоит из одного числа (тобишь онли координата х)
            {
                x1[i] = xy[i];
                y1[i] = "0";
            }
            else //если строка содержит и х и y
            {
                x1[i] = xy[i].substr(0, pos);
                y1[i] = xy[i].substr(pos, xy[i].length());
            }  
          
        }
        for (int i = 0; i < k; i++) //переводим из стринга в инт 
        {
            x[i] = stof(x1[i]);
            y[i] = stof(y1[i]);       
        }

        delete[] x1; //больше не используем
        delete[] y1;

        for (int i = 0; i < k; i++)  //вывод точек (можешь удалить) ----------------------------------------
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
        delete[] x; // больше не используем
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
    

   
