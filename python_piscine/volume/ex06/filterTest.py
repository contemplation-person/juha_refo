from ft_filter import juhaFilter
# Part 2: 프로그램
# 시작하기
# 두 개의 인자를 받는 프로그램을 작성하시오: 문자열(S)과 정수(N).
# 프로그램은 S에서 길이가 N보다 큰 단어들의 리스트를 출력해야 한다.
# • 	단어들은 공백 문자로 서로 구분된다.
# • 	문자열에는 어떤 특수 문자(구두점이나 보이지 않는 문자)도 포함되지 않는다.
# • 	프로그램은 최소한 하나의 리스트 컴프리헨션 표현식과 하나의 람다를 포함해야 한다.
# • 	인자의 개수가 2개와 다르거나, 인자의 타입이 잘못되면 프로그램은 를 출력한다.


## doc 기능
# print(ft_filter.__doc__)

def test_case(description, test_func, test_data):
    """테스트 실행 및 결과 비교"""
    print(f"\n{'='*60}")
    print(f"테스트: {description}")
    print(f"{'='*60}")
    # 테스트 데이터가 호출 가능하면(예: 제너레이터 공급자) 호출해서 각각 새 iterable 생성
    if callable(test_data):
        data_for_real = test_data()
        data_for_your = test_data()
    else:
        data_for_real = test_data
        data_for_your = test_data

    # 실제 filter
    real_result = list(filter(test_func, data_for_real))
    print(f"filter 결과:    {real_result}")

    # 당신의 juhaFilter
    your_result = list(juhaFilter(test_func, data_for_your))
    print(f"juhaFilter 결과: {your_result}")
    
    # 비교
    if real_result == your_result:
        print("✅ PASS")
    else:
        print("❌ FAIL")
    
    return real_result == your_result


# 테스트 케이스들
print("\n" + "🔥 FILTER 함수 테스트 시작 🔥".center(60))

# 테스트 1: 양수 필터링
test_case(
    "양수만 필터링",
    lambda x: x > 0,
    [1, -2, 3, -4, 5, -6, 7]
)

# 테스트 2: 짝수 필터링
test_case(
    "짝수만 필터링",
    lambda x: x % 2 == 0,
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
)

# 테스트 3: 문자열 길이 필터링
test_case(
    "5글자 초과 단어만 필터링",
    lambda s: len(s) > 5,
    ["cat", "elephant", "dog", "butterfly", "ant"]
)

# 테스트 4: None을 함수로 사용 (truthy 값만 필터링)
test_case(
    "function=None (truthy 값만)",
    None,
    [0, 1, False, True, "", "hello", None, [], [1, 2]]
)

# 테스트 5: 빈 리스트
test_case(
    "빈 리스트",
    lambda x: x > 0,
    []
)

# 테스트 6: 모두 False
test_case(
    "모두 조건 불만족",
    lambda x: x > 100,
    [1, 2, 3, 4, 5]
)

# 테스트 7: 모두 True
test_case(
    "모두 조건 만족",
    lambda x: x > 0,
    [1, 2, 3, 4, 5]
)

# 테스트 8: 복잡한 조건
test_case(
    "10보다 크고 20보다 작은 수",
    lambda x: 10 < x < 20,
    [5, 12, 8, 15, 25, 18, 3, 19]
)

# 테스트 9: 문자열에서 모음 포함 여부
test_case(
    "모음이 포함된 단어만",
    lambda s: any(c in 'aeiou' for c in s.lower()),
    ["sky", "fly", "cat", "dog", "try"]
)

# 테스트 10: None 함수 + 숫자
test_case(
    "function=None + 숫자 리스트",
    None,
    [0, 1, 2, 0, 3, 0, 4]
)

# 테스트 11: 딕셔너리 리스트
test_case(
    "나이가 18 이상인 사람",
    lambda person: person["age"] >= 18,
    [
        {"name": "Alice", "age": 25},
        {"name": "Bob", "age": 17},
        {"name": "Charlie", "age": 30}
    ]
)

# 테스트 12: iterator 여부 확인
print(f"\n{'='*60}")
print("iterator 타입 테스트")
print(f"{'='*60}")

real_filter = filter(lambda x: x > 0, [1, 2, 3])
your_filter = juhaFilter(lambda x: x > 0, [1, 2, 3])

print(f"filter 타입:    {type(real_filter)}")
print(f"juhaFilter 타입: {type(your_filter)}")

# iterator는 한 번만 사용 가능한지 확인
print("\niterator 소진 테스트:")
print(f"첫 번째 list(): {list(real_filter)}")
print(f"두 번째 list(): {list(real_filter)}")

your_filter2 = juhaFilter(lambda x: x > 0, [1, 2, 3])
print(f"juhaFilter 첫 번째: {list(your_filter2)}")
print(f"juhaFilter 두 번째: {list(your_filter2)}")

# 추가 테스트들: 제너레이터, 튜플/셋/딕셔너리, non-callable 함수 타입, 지연성(laziness)
# 테스트 13: 제너레이터 공급자
test_case(
    "제너레이터 입력 테스트",
    lambda x: x % 2 == 1,
    lambda: (i for i in range(10))
)

# 테스트 14: 튜플, 셋, 딕셔너리
test_case(
    "튜플 입력",
    lambda x: x > 3,
    (1, 2, 3, 4, 5, 6)
)

test_case(
    "셋 입력",
    lambda x: x % 2 == 0,
    {1, 2, 3, 4, 5, 6}
)

test_case(
    "딕셔너리 (키) 입력",
    lambda k: k in {1, 3, 5},
    {1: 'a', 2: 'b', 3: 'c', 4: 'd', 5: 'e'}
)

# 테스트 15: non-callable 함수 전달 -> TypeError 기대
print(f"\n{'='*60}")
print("non-callable function 테스트")
print(f"{'='*60}")
try:
    _ = list(juhaFilter(123, [1, 2, 3]))
    print("❌ FAIL: expected TypeError for non-callable function")
except TypeError:
    print("✅ PASS: TypeError raised for non-callable function")

# 테스트 16: 지연성(laziness) 확인
print(f"\n{'='*60}")
print("지연성(laziness) 테스트")
print(f"{'='*60}")
def boom():
    yield 1
    raise RuntimeError("boom")

try:
    f = filter(lambda x: True, boom())
    print("built-in filter 생성 성공 (지연)")
except Exception as e:
    print(f"built-in filter 생성 시 예외: {e}")

try:
    jf = juhaFilter(lambda x: True, boom())
    print("juhaFilter 생성 성공")
except Exception as e:
    print(f"juhaFilter 생성 시 예외: {e}")

print("\n" + "🎉 테스트 완료! 🎉".center(60) + "\n")