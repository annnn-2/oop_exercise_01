#include "Long.hpp"

Long::Long() {//конструктор
    this->high = 0;
    this->low = 0;
}

void Long::Print() {//вывод число в 10-чной сс, поэтому используется побитовый сдвиг для преобразования элемента класса Long в unsigned long int
    unsigned long int x = 0;
    x = this->high;
    x = x << 32;
    x = x + this->low;
    cout << x << endl;
}

void Long::PrintINT() {//вывод элемента класса Long
    cout << high << "  " << low << endl;
}

Long Long::Eq(Long b) {//призваивание Long = Long
    this->high = b.high;
    this->low = b.low;
    return *this;
}

Long Long::EqualInt(int high, int low) {//призваивание Long = Long
    this->high = high;
    this->low = low;
    return *this;
}

bool Long::EqualLong(Long b) {//проверка на равенство
    if (this->high == b.high && this->low == b.low)
    return 1;
    else
    return 0;
}

Long Long::Increment() {//+1
    Long b;
    b.low = 1;
    this->Add(b);
    return *this;
}

Long Long::Decrement() {//-1
    Long a = *this;
    Long b;
    b.low = 1;
    return a.Subtract(b);
}

Long Long::Add(Long b)  {//сложение
    Long a = *this;
    this->low += b.low;
    this->high += b.high;
    //сложили верхнюю и нижнюю части
    if (this->low < a.low || this->low < b.low)
    //если часть low при сложении уменьшилась, значит произошло переполнение -> необходимо увеличить на 1 часть high
        this->high++;

    return *this;
}

Long Long::Subtract(Long b)  {//вычитание
    
    Long x = *this;
    Long y = b;
    
    //начинаем с части low как при вычитании в столбик
    if (x.low >= y.low)
    x.low -= y.low;
    else if (x.low < y.low)
    {//если уменьшаемое меньше вычитаемого занимаем 1 у части high (в этой сист счисл 1 = 2^32)
    x.low = MAX - y.low + x.low;
    x.high--;
    }
    
    x.high -= y.high;
    
    return x;
}

Long Long::Multiply(Long b)  {//умножение
    
    unsigned int alow = this->low;
    unsigned int ahigh = this->high;
    unsigned int blow = b.low;
    unsigned int bhigh = b.high;
    //отдельно обозначили high и low части множителей
    unsigned int p = 0;
    Long res;
    
    
    if(b.high != 0 || b.low !=0)//если умножение не на ноль
    {
        int k = 1;
        int c = 0; //счетчик переполнения
        
        //имитируем умножение в столбик
        //         ah        al
        //         bh        bl
        //-----------------------
        //        al*bh    al*bl
        //ah*bh   ah*bl
        //ah*bh уже не входит в Long
        //сначала a.low*b
        //для этого небходимо a.low*b и посчитать сколько раз произойтет переполнение ->
        //используем цикл -  умножение представим как увеличение на b а раз
        while (alow != k){
            p = blow;
            blow += b.low;
            if (blow < p)//если после очередного суммирования а уменьшилось-> произошло переполнение ->c++
            c++;
            k++;
        }
        
        res.low = blow;
        //чтобы досчитать осталось a.low*b.high
        res.high = alow * bhigh + c;
        
        //далее a.high*b.low
        blow = b.low;
        blow *= ahigh;
        res.high += blow;
        
    }
    //а если было умножение на 0 то res изначально и есть 0
    return res;
}

Long Long::Divide(Long b)  {//деление
    Long a = *this;
    Long p;
    Long res;
    
    if(a.EqualLong(b))
        res = res.Increment(); //необходимо, тк дальше программа приравных а и b пропустит один раз увеличение
    if(a.EqualLong(a.More(b)))// если делимое больше делителя
    {
        int c = 0;
        //деление придставим как вычитание делителя из делимого res раз
        while (c == 0){
            p = p.Eq(a);
            a = a.Subtract(b); //вычитаем из а b
            if (a.EqualLong(p.More(a)) || (a.low == 0 && a.high == 0)) //если после вычитания число увеличилость или стало 0 -> произошло переполнение или число поделилось нацело
            {c++; res = res.Decrement();}
            res = res.Increment();
        }
    }
    return res;
}

Long Long::Mod(Long b)  {//остаток от деления
    Long a = *this;
    Long p;
    
    if(a.EqualLong(a.Less(b)))//если делитель больше делимого то остаток равен делимому
    {
        return a;
    }
    
    if(a.EqualLong(a.More(b)))
    {
        int c = 0;
        //повтор алгоритма деления, только теперь ответом будет не счетчик, а то, что останется от делимого
        while (c == 0){
            p = p.Eq(a);
            a = a.Subtract(b);
            if (a.EqualLong(p.More(a)) || (a.low == 0 && a.high == 0))
            {c++; }
        }
        
        if(a.low == 0 && a.high == 0) return a;
    }
    return p;
}

Long Long::Less(Long b)  {//вернет меньшее из двух чисел
    if (this->high < b.high)
     return *this;
    
    else if (this->high == b.high && this->low < b.low)
     return *this;
    
    else  return b;
}

Long Long::More(Long b)  { //вернет большее из двух чисел
    if(b.EqualLong((*this).Less(b)))
        return *this;
    else return b;
}
