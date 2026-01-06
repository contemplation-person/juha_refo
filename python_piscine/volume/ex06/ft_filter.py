# Part 1: 필터 함수 다시 작성하기
# 자신만의 ft_filter를 다시 작성하시오. 그것은 원래 내장 함수처럼 동작해야 한다.  (즉 filter 와 같은 결과를 반환해야 한다.)
# 리스트 컴프리헨션을 사용하여 flter 를 다시 작성해야 한다.
# 물론 원래의 내장 flter를 사용하는 것은 금지된다.
# 여기서 모듈을 검증할 수 있지만, 우리는 여러분이 계속 진행하기를 권장한다.
# 왜냐하면 이후 프로젝트에서 알아야 할 것들이 있기 때문이다.

# filter(function, iterable, /)
# iterable의 요소들 중에서 function이 참인 요소들로부터 이터레이터를 구성한다.  
# iterable은 시퀀스, 반복을 지원하는 컨테이너, 또는 이터레이터일 수 있다.  

# 만약 function이 None이면, identity 함수가 가정되며, 즉 iterable의 모든 거짓인 요소들이 제거된다.  
# filter(function, iterable)은 function이 None이 아닐 때  
# (item for item in iterable if function(item)) 제너레이터 표현식과 동일하다.  
# function이 None일 때는 (item for item in iterable if item) 제너레이터 표현식과 동일하다.  
# 보완적인 함수로, function이 거짓인 iterable의 요소들을 반환하는 itertools.filterfalse()를 참고하라.

class juhaFilter:
    """\
filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true.\
    """

    def __init__(self, function, obj):
        self.index = 0
        if function is None:
            self.data = [filterObj for filterObj in obj if filterObj]
        else:
            self.data = [filterObj for filterObj in obj if function(filterObj)]


    def __iter__(self):
        return self

    def __next__(self):
        if self.index < len(self.data):
            val = self.data[self.index]
            self.index += 1
            return val
        raise StopIteration
        