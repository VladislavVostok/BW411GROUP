#include <iostream>
#include "Board.h"

int main()
{

    setlocale(LC_ALL, "");

    Board board;


    /*Test test;
    test.Hello();*/

    board.setMarks(1);
    board.setMarks(2);
    board.setMarks(3);
    board.setMarks(4);
    board.setName("Игрока 1");
    std::cout << "Оценки" << std::endl;
    std::cout << board.getName() << std::endl;
    
    for (auto& a : board.getMarks()) {
        std::cout << a << std::endl;
    }

    std::cout << "Средняя оценка: " << board.getAver() << std::endl;



    Board board2;
    board2.setMarks(11);
    board2.setMarks(22);
    board2.setMarks(33);
    board2.setMarks(44);
    board2.setName("Игрока 2");
    std::cout << "Оценки" << std::endl;
    std::cout << board2.getName() << std::endl;
    for (auto& a : board2.getMarks()) {
        std::cout << a << std::endl;
    }
    std::cout << "Средняя оценка: " << board2.getAver() << std::endl;
}