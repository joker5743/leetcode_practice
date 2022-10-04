// 640. 求解方程
#include<string>

using namespace std;

class SolveEquation{
public:
    string solveEquation(string equation) {
        int factor = 0, val = 0;
        //factor:系数   val：常量
        int index = 0, n = equation.size(), sign1 = 1;
        //sign1:等式左侧系数，初始默认为正

        while (index < n)
        {
            if(equation[index] == '='){
                sign1 = -1;
                index++;
                continue;
            }

            int sign2 = sign1, number = 0;
            bool valid = false;     //记录number是否为有效数字
            if(equation[index] == '-' || equation[index] == '+'){
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }

            while(index < n && isdigit(equation[index])){
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }

            if(index < n && equation[index] == 'x'){
                factor += valid ? sign2 * number : sign2;
                index++;
            }
            else{
                val += sign2 * number;
            }
        }

        if(factor == 0){
            return val == 0 ? "Infinite solutions" : "No solutions";
        }
        
        return string("x = ") + to_string(-val/factor);
    }
};