from ft_filter import juhaFilter
import sys
# Part 2: 프로그램
# 시작하기
# 두 개의 인자를 받는 프로그램을 작성하시오: 문자열(S)과 정수(N).
# 프로그램은 S에서 길이가 N보다 큰 단어들의 리스트를 출력해야 한다.
# • 	단어들은 공백 문자로 서로 구분된다.
# • 	문자열에는 어떤 특수 문자(구두점이나 보이지 않는 문자)도 포함되지 않는다.
# • 	프로그램은 최소한 하나의 리스트 컴프리헨션 표현식과 하나의 람다를 포함해야 한다.
# • 	인자의 개수가 2개와 다르거나, 인자의 타입이 잘못되면 프로그램은 를 AssertionError 출력한다.

try:
    if len(sys.argv) != 3:
        raise AssertionError("AssertionError: the arguments are bad")

    string_value = sys.argv[1]
    string_length = int(sys.argv[2])

    if type(string_value) is not str:
        raise AssertionError("AssertionError: the arguments are bad")

    if type(string_length) is not int:
        raise AssertionError("AssertionError: the arguments are bad")

    filteringList = juhaFilter(lambda x: len(x) > string_length, string_value.split())

    print([word for word in filteringList])

except AssertionError as e:
    print(e)
