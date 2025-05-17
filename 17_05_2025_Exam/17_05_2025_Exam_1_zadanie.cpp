//#include <iostream>
//#include <string>
//#include <random>
//#include <ctime>
//#include <vector>
//
//using namespace std;
//
//class PassGenerator {
//private:
//    string rusSymbols = "йцукенгшщзхъфывапролджэячсмитьбюёЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮЁ";
//    string latSymbols = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
//    string specSymbols = "~!@#$%^&*()<>{}[]|;:?.,";
//    string digSymbols = "0123456789";
//
//    mt19937 generator;
//
//public:
//    PassGenerator() {
//        generator.seed(time(nullptr));
//    }
//
//    string gen_pass(int lendth, bool dig, bool let, bool spec, bool rusLet) {
//
//        string characters;
//        string pass;
//
//        if (dig) {
//            characters += digSymbols;
//        }
//
//        if (let) {
//            characters += latSymbols;
//        }
//        if (rusLet) {
//            characters += rusSymbols;
//        }
//
//        if (spec) {
//            characters += specSymbols;
//        }
//
//        if (characters.empty()) {
//            cout << "Нет выбора символов для построения пароля!";
//            return "";
//        }
//
//        uniform_int_distribution<> distibutions(0, characters.size() - 1);
//
//        for (int i = 0; i < lendth; ++i) {
//            pass += characters[distibutions(generator)];
//        }
//
//        return pass;
//
//    }
//
//    string genStrong() {
//        return gen_pass(12, true, true, true, true);
//    }    
//    
//    string genMedium() {
//        return gen_pass(12, false, true, true, false);
//    }    
//    
//    string genEasy() {
//        return gen_pass(12, false, false, false, true);
//    }
//
//};
//
//
//int main()
//{
//    //system("chcp 1251>null");
//    setlocale(LC_ALL, "");
//
//    PassGenerator generator;
//
//
//    //cout << gen_pass(15, true, true, true, false) << endl;
//    //cout << gen_pass(20, true, true, false, false) << endl;
//    //cout << gen_pass(50, true, false, false, false) << endl;
//    cout << generator.genEasy() << endl;
//    cout << generator.genMedium() << endl;
//    cout << generator.genStrong() << endl;
//    cout << generator.gen_pass(30, true, true, true, true) << endl;
//}
//
//
//
