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
#include <ostream>
#include <string>
#include <iomanip>

//생성자
PhoneBook::PhoneBook() : _saveIndex(0) {};
// 한줄함수
void    PhoneBook::increaseSaveIndex() { _saveIndex++; }

void    PhoneBook::setContact() {
    std::string str;

    print("name : ");
    std::getline(std::cin, str);
    if (isCinErr("plz input the correct cmd")) return;
    _contact[_saveIndex % 8].setName(str);
    print("nick name : ");
    std::getline(std::cin, str);
    if (isCinErr("plz input the correct cmd")) return;
    _contact[_saveIndex % 8].setNickName(str);
    print("first name : ");
    std::getline(std::cin, str);
    if (isCinErr("plz input the correct cmd")) return;
    _contact[_saveIndex % 8].setFirstName(str);
    print("phone number : ");
    std::getline(std::cin, str);
    if (isCinErr("plz input the correct cmd")) return;
    _contact[_saveIndex % 8].setPhoneNumber(str);
    print("secret memo : ");
    std::getline(std::cin, str);
    if (isCinErr("plz input the correct cmd")) return;
    _contact[_saveIndex % 8].setSecretMemo(str);
    if (_saveIndex < 8)
        _contact[_saveIndex % 8].setNum(_saveIndex + 1);
    else {
        for (int i = 0; i < 8; i++)
            _contact[i].setNum(_contact[i].getNum() - 1);
        _contact[_saveIndex % 8].setNum(8);
    }
    increaseSaveIndex();
}

void    PhoneBook::displayContactOne(int num) {
    if (num < 0 || num > 7) {
        printEndl("Wrong input");
        return ;
    }
    if (_contact[num].getNum() == 0) return ;
    std::cout << "index : " << _contact[num].getNum() << std::endl;
    std::cout << "Frist Name : " << _contact[num].getFirstName() << std::endl;
    std::cout << "Name : " << _contact[num].getName() << std::endl;
    std::cout << "Nickname : " << _contact[num].getNickName() << std::endl;
    std::cout << "secret memo: " << _contact[num].getSecretMemo() << std::endl;
};

static std::string strForm(std::string str) {
    if (str.size() > 10) {
        str.erase(10);
        str[9] = '.';
    }
    return (str);
}

static void displayContact(Contact contact) {
    if (contact.getNum() == 0) return ;
    std::cout << std::setw(10) << contact.getNum() << "|";
    std::cout << std::setw(10) << strForm(contact.getFirstName()) << "|";
    std::cout << std::setw(10) << strForm(contact.getName()) << "|";
    std::cout << std::setw(10) << strForm(contact.getNickName()) << "|" << std::endl;
}

void    PhoneBook::displayContactList() {
    for (int i = 0; i < 8; i++) {
        displayContact(_contact[(i + _saveIndex) % 8]);
    }
};
