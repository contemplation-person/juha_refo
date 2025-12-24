import sys
from string import punctuation


def parse_str(input_str):
    """
    문자열 안에 있는 대문자, 소문자, 구두점 숫자, 공백을 구분하여 반환한다.
    """
    char_set = {
        "upperCase": 0,
        "lowerCase": 0,
        "space": 0,
        "punctuation": 0,
        "total_count": 0,
        "digit": 0
    }

    for i in input_str:
        if i.isspace():
            char_set["space"] += 1
        elif i.isupper():
            char_set["upperCase"] += 1
        elif i.islower():
            char_set["lowerCase"] += 1
        elif i.isdigit():
            char_set["digit"] += 1
        elif i in punctuation:
            char_set["punctuation"] += 1
        char_set["total_count"] += 1

    sentence = f"""\
The text contains {char_set['total_count']} characters:
    {char_set['upperCase']} upper letters,
    {char_set['lowerCase']} lower letters,
    {char_set['punctuation']} punctuation marks,
    {char_set['space']} spaces,
    {char_set['digit']} digits\
"""

    return sentence


def main():
    """
    - 인자가 없거나 아무 것도 제공되지 않으면, 사용자에게 문자열 입력을 요청
    - 인자가 두 개 이상 제공되면 AssertionError를 출력
    """
    argc = len(sys.argv)

    if argc > 2:
        raise AssertionError("more than one argument is provided")
    if argc == 2:
        print(parse_str(sys.argv[1]))
    else:
        print("What is the text to count?")
        input_string = sys.stdin.read()
        print(parse_str(input_string))


if __name__ == "__main__":
    try:
        main()
    except AssertionError as e:
        print("AssertionError:", e)
