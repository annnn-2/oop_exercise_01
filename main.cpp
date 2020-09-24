//Ермакова Анна
//М80-201Б-19
//Создать класс Long для работы с целыми беззнаковыми числами из 64 бит. Число должно быть представлено двумя полями unsigned int. Должны быть реализованы арифметические операции, присутствующие в С++, и сравнения.

#include "Long.hpp"

enum Options {
    PRINT,
    PRINTINT,
    ENTERNUMBER,
    INCREMENT,
    DECREMENT,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MOD,
    EQUAL,
    MORE,
    LESS
};

Long menu(Options option, Long a){
    
    //реализация вынесена в отдельный блок, для большего удобства, switch перключается в зависимости от тебуемой операции
    
    switch(option){
    
        case PRINT:
            a.Print();
        break;
        
        case PRINTINT:
            a.PrintINT();
        break;
        
        case ENTERNUMBER:
        {
            unsigned long int x = 0;
            int high = 0, low = 0;
            cin >> x;
            
        //для того чтобы разбить long на два int используем побитовый сдвиг на 32 (тк поделить надо пополам, а в Long 64)
            high = x >> 32;
            low = (x << 32) >> 32;
            
            a.EqualInt(high, low);
            return a;
        }
        
        case INCREMENT:
        {
            a = a.Increment();
            return a;
        }
        
        case DECREMENT:
        {
            a = a.Decrement();
            return a;
        }
        
        case ADD:
        {
            Long b;
            cout << "Enter the nember to add:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Add(b);
            return a;
        }
        
        
        case SUBTRACT:
        {
            Long b;
            cout << "Enter the nember to subtract:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Subtract(b);
            return a;
        }
        
        case MULTIPLY:
        {
            Long b;
            cout << "Enter the nember to multiply:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Multiply(b);
            return a;
        }
        break;
        
        case DIVIDE:
        {
            Long b;
            cout << "Enter the nember to divide:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Divide(b);
            return a;
        }
        break;
        
        case MOD:
        {
            Long b;
            cout << "Enter the nember to see mod:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Mod(b);
            return a;
        }
        break;
        
        case EQUAL:
        {
            Long b;
            cout << "Enter the nember to compare:" << endl;
            b = menu(ENTERNUMBER, b);
            if(a.EqualLong(b))
            cout << "Equal" << endl;
            else
            cout << "Not equal" << endl;
            return a;
        }
        
        case MORE:
        {
            Long b;
            cout << "Enter the nember to compare:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.More(b);
            cout << "answer: ";
            return a;
        }
        
        case LESS:
        {
            Long b;
            cout << "Enter the nember to compare:" << endl;
            b = menu(ENTERNUMBER, b);
            a = a.Less(b);
            cout << "answer: ";
            return a;
        }
    }
    
    return a;
}

int main() {
    int c = 1;
    Long a;
    
    while(c == 1){
    //цикл для неоднокраного использования меню в ходе работы программы
        int t;
        a.Print();

        cout << "Choose the option: 1. Print 2. Print in two ints 3. Enter the number 4. Increment 5. Decrement 6. Add 7. Subtract 8. Multiply 9. Divide 10. Mod 11. Equal 12. More 13. Less 14. Finish" << endl;
        cin >> t;
        
        switch(t){
            //меню в соответсвии с введенным пользователем числом
            
            case 1:
            menu(PRINT, a);
            break;
            
            case 2:
            menu(PRINTINT, a);
            break;
            
            case 3:
            a = menu(ENTERNUMBER, a);
            break;
            
            case 4:
            a = menu(INCREMENT, a);
            break;
            
            case 5:
            a = menu(DECREMENT, a);
            break;
            
            case 6:
            a = menu(ADD, a);
            break;
            
            case 7:
            a = menu(SUBTRACT, a);
            break;
            
            case 8:
            a = menu(MULTIPLY, a);
            break;
            
            case 9:
            a = menu(DIVIDE, a);
            break;
            
            case 10:
            a = menu(MOD, a);
            break;
            
            case 11:
            a = menu(EQUAL, a);
            break;
            
            case 12:
            a = menu(MORE, a);
            break;
            
            case 13:
            a = menu(LESS, a);
            break;
            
            case 14:
            c = 0;
            break;
            
            default:
            cout << "Try again" << endl;
            break;
            
        }
        
    }
    
    return 0;
}
