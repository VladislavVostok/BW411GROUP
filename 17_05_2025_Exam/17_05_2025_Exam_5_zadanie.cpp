//#include <iostream>
//#include <string>
//#include <fstream>
//#include <ctime>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <cctype>
//
//
//using namespace std;
//
//void text_analizer(const string&);
//string to_low(string&);
//
//int main()
//{
//    setlocale(LC_ALL, "");
//    text_analizer("text.txt");
//}
//
//void text_analizer(const string& filename) {
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла!" << endl;
//        return;
//    }
//
//    unordered_map<string, int> words_count_map;
//    string word;
//
//    while (file >> word) {
//        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
//        if (!word.empty()) {
//            words_count_map[to_low(word)]++;
//        }
//    }
//
//    vector<pair<string, int>> sorted_words(words_count_map.begin(), words_count_map.end());
//    sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
//        return a.second > b.second; 
//    });
//        
//
//    cout << "Топ 5 слов!" << endl;
//
//    for (int i = 0; i < min(20, (int)sorted_words.size()); ++i) {
//        cout << sorted_words[i].first << " - " << sorted_words[i].second << endl;
//    }    
//    
//    //for (int i = 0; i < sorted_words.size(); ++i) {
//    //    cout << sorted_words[i].first << " - " << sorted_words[i].second << endl;
//    //}
//
//}
//
//string to_low(string& str) {
//    string res;
//    for (char c : str) {
//        res += tolower(c);
//    }
//    return res;
//}