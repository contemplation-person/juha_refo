/*
    • 전화번호부
    ◦ 연락처 배열이 있습니다.
    ◦ 최대 8개의 연락처를 저장할 수 있습니다. 사용자가 9번째 연락처를 추가하려고 하면, 가장 오래된 것을 새 것으로 바꾸세요.
    ◦ 동적 할당은 금지되어 있습니다.

    • content 
    ◦ 전화번호부 연락처를 나타냅니다.
    코드에서 phonebook는 PhoneBook class의 인스턴스로 인스턴스화되어야 합니다.
    연락처도 마찬가지입니다. 
    각 인스턴스는 Contact class의 인스턴스로 인스턴스화되어야 합니다.
    원하는 대로 classes을 설계할 수 있지만 
    class 내부에서 항상 사용되는 모든 것은 비공개이며 class 외부에서 사용할 수 있는 모든 것은 공개된다는 것을 명심하십시오
    프로그램을 시작할 때 전화번호부가 비어 있고 사용자에게 전화번호부를 입력하라는 메시지가 표시됩니다
    3개의 명령 중 하나입니다.
    이 프로그램은 ADD, SEARCH와 EXIT만 받습니다.

    • ADD: 새 연락처를 저장합니다
    ◦ 사용자가 이 명령을 입력하면 새 연락처 정보를 한 번에 한 필드씩 입력하라는 메시지가 나타납니다. 
    모든 필드가 완료되면 연락처를 전화번호부에 추가합니다.
    ◦ 연락처 필드는 이름, 성, 별명, 전화 번호 및 가장 어두운 비밀입니다. 저장된 연락처의 필드는 비워둘 수 없습니다.

    • SEARCH: 특정 연락처를 표시합니다
    ◦ 저장된 연락처를 색인, 이름, 성 및 닉네임의 4개 열 목록으로 표시합니다.
    ◦ 각 열의 너비는 10자여야 합니다. 파이프 문자('|')는 파이프 문자를 구분합니다. 
        텍스트는 오른쪽으로 정렬되어야 합니다. 
        텍스트가 열보다 긴 경우 텍스트를 잘라내고 표시 가능한 마지막 문자를 다음 문자로 대체해야 합니다
        점('.')을 찍습니다.
    ◦ 그런 다음 표시할 항목의 색인을 다시 입력하라는 메시지를 표시합니다. 
    인덱스가 범위를 벗어나거나 잘못된 경우 관련 동작을 정의합니다. 
    그렇지 않은 경우, 연락처 정보를 한 줄에 한 필드씩 표시합니다

    • EXIT입니다
    ◦ 프로그램이 종료되고 연락처가 영원히 끊어집니다!
    • 다른 모든 입력은 삭제됩니다.
    명령이 올바르게 실행되면 프로그램은 다른 명령을 기다립니다. 사용자가 EX를 입력하면 중지됩니다IT입니다.
    실행 파일에 관련 이름을 지정합니다.
 */
#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

int findArrayNum() {
    int i = 0;

    while (i < 8) {
        if (this->phoneBook[i].num == 0) return (i);
        i++;
    }
    return (-1);
}

void addPhoneBook() {
    if (cnt == 8) {
        for (int i = 0; i < 8; i++) {
            this->phoneBook[i].num--;
        }
    }
    int emptyArrayNum = findArrayNum();

    print("Name : ");
    std::cin >> this->phoneBook[emptyArrayNum].name;
    if (std::cin.eof()) exit(0);
    print("first_name : ");
    std::cin >> this->phoneBook[emptyArrayNum].firstName;
    if (std::cin.eof()) exit(0);
    print("nick_name : ");
    std::cin >> this->phoneBook[emptyArrayNum].nickName;
    if (std::cin.eof()) exit(0);
    print("phone_number : ");
    std::cin >> this->phoneBook[emptyArrayNum].phoneNumber;
    if (std::cin.eof()) exit(0);
    print("secreat_memo : ");
    std::cin >> this->phoneBook[emptyArrayNum].secreatMemo;
    if (std::cin.eof()) exit(0);
    if (cnt < 8)
        cnt++;
    this->phoneBook[emptyArrayNum].num = this->cnt;
}

void printPhoneBook(int idx) {
    std::cout << std::setw(10); 
    print(phoneBook[idx].num);
    print("|");
    print(phoneBook[idx].name);
    print("|");
    print(phoneBook[idx].firstName);
    print("|");
    print(phoneBook[idx].phoneNumber);
    print("|");
    return ;       
}

void searchPhoneBook() {
    if (this->cnt == 0) {
        printEndl("empty phoneBook");
        return ;
    }
    int searchNumber;
    print("search number : ");
    std::cin >> searchNumber;
    if (std::cin.eof()) exit(0);
    if (searchNumber > this->cnt) {
        printEndl ("too large");
    } else if (searchNumber < 1) {
        printEndl("too small");
    } else {
        for (int i = 0; i < 8; i++) {
            if (this->phoneBook[i].num == searchNumber) printPhoneBook(i);
        }
    }
}

static void exitPhoneBook() {
    printEndl("EXIT");
    exit(0);
}

void _setCmd() {
    print("get cmd : ");
    std::cin >> _cmd;
    if (std::cin.eof()) exit(0);
    if (std::cin.eof()) {
        printEndl("EOF");
        exit(1);
    }
}

void doCmd() {
    if (!_cmd.compare("ADD")) addPhoneBook();
    else if (!_cmd.compare("SEARCH")) searchPhoneBook();
    else if (!_cmd.compare ("EXIT")) exitPhoneBook();
    else { printEndl("wrong cmd"); }
}

