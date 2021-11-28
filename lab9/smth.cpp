    #include <iostream>
    #include <cstring>
    using namespace std;
     
    int strPeriod(char *str){
        int period;
        period = strlen(str); // 
        for(int i=1; i<=(strlen(str)/2); i++){ /* разбиваем строку                    
                                                 на подстроки*/
                int j;
            for(j=0; j<strlen(str)-i; ){ /* ограничение номера символа,
                                              чтобы не выйти за границы строки*/
                if(str[j] == str[j+i]){
                    j++;
                }
                else{
                    break;
                }
            }
        if(j == (strlen(str) - i)){  /* если цикл дошел до конца 
                                        строки - период найден*/
                    period = i;
                    break;
            }
        }
     
        return period;
    }
     
    int main() {
        const int n = 81;
        int tests;
        cin >> tests;
        cin.ignore(1, ' '); /* пропуск символа перехода на новую строку*/
        char *str = new char[n];
        for(int j=0; j<tests; j++){
            cin.getline(str, n);
            cout << strPeriod(str);
            if(j != tests - 1){
                cout << endl << endl;
            }
        }
        return 0;
    }