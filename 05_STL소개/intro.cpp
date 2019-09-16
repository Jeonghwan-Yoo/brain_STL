/*
STL에 등장하는 각 구성 요소의 특징과 기능을 이해해보자.
STL을 사용할 때마다 등장하는 구성 요소가 있다.
이 구성 요소가 서로 맞물려 STL을 동작시키는 것이므로 하나하나의 구성 요소가 중요한 역할.
라이브러리는 도움말을 참조해가며 사용할 수 있지만, STL은 모든 구성 요소의 특징을 어느정도 이해하고
있어야만 효율적으로 사용할 수 있다.

01 STL이란
STL은 표준 C++라이브러리의 일부분으로 Standard Template Libary의 약자.
STL은 프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리입니다.
또한, 자료구조와 알고리즘은 서로 반복자라는 구성 요소를 통해 연결합니다.
STL의 구성요소
1)컨테이너(Container):객체를 저장하는 객체로 컬렉션 혹은 자료구조라고도 합니다.
2)반복자(Iterator):포인터와 비슷한 개념으로 컨테이너의 원소를 가리키고, 가리키는 원소에 접근하여
다음 원소를 가리키게 하는 기능.
3)알고리즘(Algorithm):정렬,삭제,검색,연산 등을 해결하는 일반화된 방법을 제공하는 함수 템플릿.
4)함수 객체(Function Object):함수처럼 동작하는 객체로 operator()연산자를 오버로딩한 객체.
컨테이너와 알고리즘 등에 클라이언트 정책에 반영하게 합니다.
5)어댑터(Adaptor):구성 요소의 인터페이스를 변경해 새로운 인터페이스를 갖는 구성요소로 변경합니다.
(새로운 구성 요소처럼 보입니다)
6)할당기(Allocator):컨테이너의 메모리 할당 정책을 캡슐화한 클래스 객체로 모든 컨테이너는 자신만의
기본 할당기를 가지고 있습니다.
프로그램 대부분은 STL에서 제공하는 기본 할당기로 충분하다.

함수객체     알고리즘  반복자  컨테이너
|less| ---> |정렬|    -----> |객체|
...          ...             ...

STL의 세 가지 특징은 효율성과 일반화 프로그램(재사용성), 확장성입니다.
STL은 이 세 특징에 중점을 두고 개발된 라이브러리입니다.
STL은 너무나 일반적이고 특정한 자료구조와 형식에 종속적이지 않습니다.
효율성도 다른 라이브러리에 뒤지지 않고 사용자가 작성한 구성요소와도 잘 동작하고 확장성도 뛰어남.

02 STL을 한눈에
컨테이너
컨테이너는 같은 타입을 저장, 관리할 목적으로 만들어진 클래스입니다.
컨테이너는 두 가지로 나눕니다. (총 7가지 컨테이너를 제공합니다.)
1)표준 시퀀스 컨테이너(standard sequence container):컨테이너 원소가 자신만의 삽입 위치(순서)를 가지는
컨테이너(vector, deque, list : 선형적)
2)표준 연관 컨테이너(standard associative container):저장 원소가 삽입 순서와 다르게 특정 정렬 기준에 의해
자동 정렬되는 컨테이너(set, multiset, map, multimap : 비선형적)
시퀀스 컨테이너는 삽입되는 순서에 따라 원소의 위치가 결정되고 바뀌지 않습니다.
하지만, 연관 컨테이너는 삽입 순서와 상관없이 정렬 기준(디폴트 less)에 따라 원소의 위치가 결정.

string 컨테이너
string컨테이너는 시퀀스 컨테이너의 일종이지만 문자만을 저장하는 컨테이너로 표준 컨테이너의 요구사항을
지키지 못합니다.
이런 컨테이너를 근사 컨테이너(alomost container)라 하며 내장 배열(arr[n] 형태)와 valarray도 근사 컨테이너.
STL을 '반복자를 가지고 동작하는 C++ 표준 라이브러리의 일부분'이라고 정의하고 string을 표준 시퀀스
컨테이너에 포함하는 경우도 있다.

컨테이너는 데이터를 하나의 연속한 메모리 단위로 저장하느냐에 따라 두 가지로 나눕니다.
1)배열 기반 컨테이너(array-based container):데이터 여러 개가 하나의 메모리 단위에 저장됩니다.
(vector, deque).
2)노드 기반 컨테이너(node-based container):데이터 하나를 하나의 메모리 단위에 저장합니다.
(list, set, multiset, map, multimap).
이런 컨테이너 종류는 성능이나 메모리 사용, 지원 인터페이스(알고리즘, 멤버함수) 등에 큰 차이를 보이며
컨테이너의 특징을 만들어 냅니다.
대표적인 컨테이너가 vector이고 시퀀스 컨테이며 배열 기반 컨테이너 입니다.
시퀀스 컨테이너는 컨테이너 끝에 데이터를 추가하고 제거하기 위한 push_back()과 pop_back() 멤버 함수.
또한, 배열 기반 컨테이너는 operator[] 연산자를 이용해 일반 배열처럼 컨테이너 원소에 접근할 수 있습니다.
모든 컨테이너는 원소의 개수를 반환하는 size() 멤버 함수를 가집니다.
5_1.cpp vector 컨테이너
vector는 시퀀스 컨테이너이므로 추가한 순서대로 출력됩니다.
또한, 배열 기반 컨테이너이므로 operator[] 연산자로 저장 원소에 접근할 수 있습니다.
컨테이너 v   
|10|
|20|
|30| 
|40|
|50|
size:5

반복자
반복자는 포인터와 비슷하게 동작합니다.
반복자는 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공합니다.
반복자는 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할을 합니다.
반복자 덕에 알고리즘은 특정 컨테이너에 종속적이지 않고 독립적이면서도 언제든지 컨테이너와 결합하여 동작할 수 있다.
1)반복자는 컨테이너 내부의 원소(객체)를 가리키고 접근할 수 있어야 합니다(*연산자 제공)
2)반복자는 다음 원소로 이동하고 컨테이너의 모든 원소를 순회할 수 있어야 합니다.(++, !=, ==연산자 제공.)

STL에서 컨테이너 원소(객체)의 집합을 순차열(sequence)라고 합니다
순차열 개념은 원소의 순서가 있는 집합을 의미합니다.
순차열은 하나의 시작과 하나의 끝을 가집니다.
여기서 반복자는 순차열의 한 원소를 가리킵니다.
STL의 모든 컨테이너는 자신만의 반복자를 제공합니다.
멤버 함수 begin()과 end()가 순차열의 시작과 끝을 가리키는 반복자를 반환합니다.
컨테이너───────────────────────────────────────┐
│ 반복자                                       │
│ begin()           iter                end() │
│    ↓               ↓                   ↓    │
│ 객체(A)-객체(B)-객체(C)-객체(D)-객체(E)-NULL  │
│   ─────────────────────────────────────>    │
│                   순차열                     │
└─────────────────────────────────────────────┘
주의할 점은 순차열의 시작과 끝에서 끝은 실제 원소가 아닌 끝을 표시(past-the-end)하는 원소입니다.
begin과 end를 구간(range)라고 하며, [begin,end)로 반개 구간.
순차열은 순서 있는 원소의 집합이므로 [begin,end), [begin,iter)와 [iter,end)도 모두 순차열.
[begin,end)구간의 원소는 A,B,C,D,E이고 [begin,iter)는 A,B입니다.
만약 [p,q)에서 p,q가 가리키는 원소가 같다면 순차열은 원소가 없습니다.
반복자는 순차열의 원소를 가리킵니다.
*연산자로 반복자가 가리키는 순차열의 원소에 접근하며 ++연산자로 다음 원소로 이동합니다.
==와 !=연산자로 순차열의 끝인지를 판단합니다.
5_2.cpp vector의 반복자
v.begin():컨테이너의 시작 원소를 가리키는 반복자를 반환합니다.
v.end():컨테이너의 끝 표시 반복자를 반환합니다.
++iter:반복자를 다음 원소를 가리키도록 이동합니다.
*iter:iter가 가리키는 원소(객체)를 반환합니다. (역참조)
vector<int>::iterator처럼 모든 컨테이너의 반복자 클래스는 내포 클래스나 typedef타입이며 자신만의 반복자를 가진다.
|10|-|20|-|30|-|40|-|50|-|N|
 ↑                        ↑
begin()                  end()

입력 반복자(input iterator):현 위치의 원소를 한 번만 읽을 수 있는 반복자
출력 반복자(output iterator):현 위치의 원소를 한 번만 쓸 수 있는 반복자
순방향 반복자(forward iterator):입력, 출력 반복자 기능에 순방향으로 이동(++)이 가능한 재할당될 수 있는 반복자
양방향 반복자(bidirectional iterator):순방향 반복자 기능에 역방향으로 이동(--)이 가능한 반복자
임의 접근 반복자(random access iterator):양방향 반복자 기능에 +,-,+=,-=,[] 연산이 가능한 반복자

반복자의 논리적인 관계
입력반복자<────┬────>출력반복자
istream       |      ostream
         순방향 반복자
              ↑
         양방향 반복자 list,set,multiset,map,multimap
			  ↑
         임의 접근 반복자 vector,deque
모든 컨테이너는 양방향 반복자 이상을 제공합니다.
배열 기반 컨테이너인 vector와 deque는 임의 접근 반복자를 제공합니다.
5_3.cpp vector의 임의 접근 반복자
iter[i]:iter+i번째 원소에 접근(역참조)합니다.
iter+=n:iter를 n만큼 이동합니다.
iter2=iter-n:iter위치에 -n한 위치의 반복자를 iter2에 대입합니다.
|10|-|20|-|30|-|40|-|50|-|N|
 ↑         ↑         ↑    ↑
begin()  iter      iter2  end()
deque도 배열 기반 컨테이너이므로 임의 접근 반복자를 지원합니다.
5_4.cpp deque의 임의 접근 반복자

알고리즘
STL은 순차열의 원소를 조사, 변경, 관리, 처리할 목적으로 알고리즘이라는 구성 요소를 제공합니다.
알고리즘은 한 쌍의 반복자([begin,end))를 필요로 하며 알고리즘 대부분은 순방향 반복자를 요구하지만,
몇몇 알고리즘은 임의 접근 반복자를 요구합니다.
STL알고리즘은 같은 기능을 수행하는 여러 가지 버전으로 오버로딩되며, 약 100개로 정의.
1)원소를 수정하지 않는 알고리즘(nonmodifying algorithms)
2)원소를 수정하는 알고리즘(modifying algorithms)
3)제거 알고리즘(removing algorithms)
4)변경 알고리즘(mutating algorithms)
5)정렬 알고리즘(sorting algorithms)
6)정렬된 범위 알고리즘(sorted range algorithms)
7)수치 알고리즘(numeric algorithms)
STL 알고리즘은 아주 일반적이어서 특정 컨테이너나 원소 타입에 종속적이지 않습니다.
find 알고리즘은 순방향 알고리즘을 요구하기 때문에 순방향 반복자만 지원하는 컨테이너라면 어떤 컨테이너가 와도
알고리즘을 수행할 수 있으며 컨테이너 원소가 정수, 실수, 문자열 혹은 사용자 정의 타입이어도 가능.
5_5.cpp find알고리즘
iter = find(v.begin(), v.end(), 20)은 [v.begin(), v.end())에서 20을 찾아 20원소를 가리키는 반복자를 반환.
찾지 못하면 v.end()와 같습니다.
begin()                  end()
 ↓                        ↓
|10|-|20|-|30|-|40|-|50|-|N|
       ↑                  ↑    
      iter               iter

순차열을 정렬하는 sort알고리즘은 임의 접근 반복자를 요구하므로 vector와 deque는 sort알고리즘을 수행할 수 있지만
다른 컨테이너는 불가능합니다.
연관 컨테이너는 컨테이너만의 정렬 기준을 가지고 있기 때문에 sort알고리즘 적용이 말이 안됨.
5_6.cpp vector와 list컨테이너의 반복자와 sort알고리즘

함수 객체
STL에서 함수 객체는 클라이언트가 정의한 동작을 다른 구성 요소에 반영하려 할 때 사용됩니다.
함수 객체를 사용하면 STL구성 요소를 더욱 유연하게 사용할 수 있습니다.
특히 많은 STL알고리즘이 함수 객체, 함수, 함수 포인터 등의 함수류를 인자로 받아 알고리즘을 유연하게 동작시킴.
5_7.cpp 함수 객체를 적용한 sort 알고리즘
sort(v.begin(), v.end(), less<int>()):less(<연산)를 기준으로 정렬합니다. 오름차순 정렬.
sort(v.begin(), v.end(), greater<int>()):greater(>연산)를 기준으로 정렬합니다. 내림차순 정렬.
sort(b,e,f)는 sort(b,e)와 버전이 다른 알고리즘으로 f를 정렬 기준으로 정렬합니다.
sort(b,e)는 기본 정렬 기준인 less(<연산)를 기준으로 정렬합니다.

어댑터
어댑터는 구성 요소의 인터페이스를 변경합니다.
1)컨테이너 어댑터(container adaptor):stack, queue, priority_queue
2)반복자 어댑터(iterator adaptor):reverse_iterator, back_insert_iterator, front_insert_iterator,
insert_iterator
3)함수 어댑터(functino adaptor):바인더(binder), 부정자(negator), 
함수 포인터 어댑터(adaptor for pointers to functions)
대표적인 컨테이너 어댑터는 stack이고 이것은 일반 컨테이너를 LIFO(Last In First Out)방식의 스택 컨테이너로 변환.
empty, size, push_back, pop_back, back 인터페이스(멤버 함수)를 지원하는 컨테이너는 모두 stack컨테이너
어댑터를 사용하여 LIFO방식의 스택으로 변환할 수 있습니다.
시퀀스 컨테이너는 모두 멤버 함수를 가지므로 stack컨테이너 어댑터의 컨테이너로 이용할 수 있습니다.
stack컨테이너 어댑터의 디폴트 컨테이너는 deque컨테이너입니다.
대표적인 반복자 어댑터는 reverse_iterator이고 일반 반복자의 동작 방식을 반대로 동작시키는
역방향 반복자(reverse iterator)로 변환합니다.
대표적인 함수 어댑터는 부정자 not2이고 조건자 함수 객체(이항)을 NOT(반대)로 변환합니다.
(조건자는 bool타입을 반환하는 함수류입니다)
5_8.cpp stack 컨테이너
stack<int> st:디폴트 컨테이너 deque<int>를 사용하여 stack컨테이너 객체를 생성합니다.
st.push(x):스택에 데이터 x를 입력합니다.
st.pop():스택의 데이터를 삭제합니다.
st.top():스택의 데이터를 반환합니다.
st.empty():스택이 비었는지를 판단합니다.

stack의 디폴트 컨테이너로 deque<int>를 사용합니다.
        ↕top()
stack───────────────────────────────┐
│                                   │
│       ↕back()                     │
│deque────────┐                     │
│  │          │←push_back()         │←push()
│  │ |30|     │→pop_back()          │→pop() 
│  │ |20|     │                     │
│  │ |10|     │                     │
│  └──────────┘                     │
└───────────────────────────────────┘

모든 시퀀스 컨테이너는 empty, size, push_back, pop_back, back 인터페이스(멤버 함수)를 가지므로
stack 컨테이너 어댑터의 컨테이너로 사용될 수 있습니다.
5_9.cpp vector컨테이너를 적용한 stack컨테이너
stack<int, vector<int>> st:vector컨테이너를 적용한 정수를 저장하는 stack 컨테이너를 생성합니다.

반복자 어댑터 reverse_iterator를 이용해 정방향 반복자를 역방향 반복자로 변환해보자
5_10.cpp 역방향 반복자 reverse_iterator
reverse_iterator<vector<int>::iterator> riter(v.end()):vector<int>::iterator타입 정방향 반복자(v.end())의
역방향 반복자를 생성합니다.
reverse_iterator<vector<int>::iterator> end_riter(v.begin()):vector<int>::iterator타입 정방향 
반복자(v.begin())의 역방향 반복자를 생성합니다.
++riter:iter와 반대로 이동합니다.
iter로 출력한 결과와 riter로 출력한 결과가 정반대.
주의할 점은 역방향 반복자는 반복자가 가리키는 원소와 실제 가리키는(참조) 값(value)가 다르다는 점.
반복자가 가리키는 원소 다음 원소의 값을 참조합니다.
정방향 반복자는 반복자가 가리키는 원소와 값이 모두 같지만, 역방향 반복자가 가리키는 원소의 실제 값은
가리키는 원소의 다음원소(++)가 됩니다.
	begin()      ----->      end() :정방향 반복자
	 ↓           ++이동       ↓
| |-|10|-|20|-|30|-|40|-|50|-|N|
  ↖	 ↑	         ++이동    ↖  ↑    ↖:value
  end_riter      <-----     riter :역방향 반복자
역방향 반복자를 이렇게 설계한 이유는 순차열의 구간(반복자 쌍)이 반개구간으로 알고리즘 수행시
정방향 반복자와 호환되도록 하기 위해서입니다.

STL컨테이너의 역방향 반복자가 필요한 경우라면 직접 생성하지 않고도 역방향 반복자를 얻을 수 있습니다.
모든 컨테이너는 자신의 역방향 반복자를 typedef 타입으로 정의하며 rbegin()와 rend()멤버함수로
순차열의 시작과 끝 원소를 가리키는 반복자 쌍을 반환합니다.
5_11.cpp vector의 역방향 반복자
vector<int>::reverse_iterator:vector에 정의되어 있는 reverse_iterator 어댑터의 typedef 타입.
v.rbegin():v의 첫 원소를 가리키는 역방향 반복자를 반환합니다.
v.rend():v의 마지막 원소를 가리키는 역방향 반복자를 반환합니다.
	begin()      ----->      end() :정방향 반복자
	 ↓           ++이동       ↓
| |-|10|-|20|-|30|-|40|-|50|-|N|
  ↖	 ↑	         ++이동    ↖  ↑    ↖:value
    rend()      <-----     rbegin() :역방향 반복자

역방향 반복자는 반복자가 가리키는 실제 원소의 값은 다음 원소입니다.
5_12.cpp 정방향 반복자와 역방향 반복자가 가리키는 값
normal_iter와 reverse_iter가 같은 위치를 가리키지만 실제 원소의 출력값은 다릅니다.
이렇게 설계된 반복자는 정방향의 순회 원소를 역방향으로 순회하고자 할 때 진가를 발휘합니다.
--연산자를 사용하지 않고 ++연산자만으로 정방향, 역방향의 순회가 모두 가능합니다.
대부분의 알고리즘이 ++ 연산자만으로 구현되어 있으며 이렇게 이미 구현된 알고리즘에 정방향과 역방향 순회가 모두 가능.
[v.begin(), normal_iter)까지 구간 출력은 10,20,30이며 여기서 역으로 출력하려면 normal_iter를 
역방향 반복자(reverse_iter)로 변환하여 [reverse_iter, v.rend())의 구간을 출력하면 30,20,10.
	iter        normal_iter :정방향 반복자
	 ↓              ↓
| |-|10|-|20|-|30|-|40|-|50|-|N|
  ↖	 ↑	         ↖  ↑    ↖:value
	rend()        riter :역방향 반복자

not2는 조건자 함수 객체를 반대 의미의 조건자 함수 객체로 변경하는 어댑터입니다.
not1은 단항 조건자에 not2는 이항 조건자에 사용됩니다.
5_13.cpp less 조건자와 not2
less<int>():임시 함수 객체를 생성합니다.
less<int>()(10,20):함수 객체의 operator()(10,20) 연산자 함수를 실행합니다.
not2(less<int>()):less<int>()의 반대 의미가 있는 함수 객체를 반환합니다.
less가 < 연산자이므로 >= 연산 기능의 함수 객체를 반환합니다.

할당기
할당기는 컨테이너의 메모리 할당 정보와 정책(메모리 할당 모델)을 캡슐화한 STL구성요소입니다.
할당기는 템플릿 클래스이며 모든 컨테이너는 기본 할당기를 사용합니다.
C++의 동적메모리 할당 연산자는 new와 delete를 사용자가 오버로딩(operator new(), operator delete())해서
사용할 수 있듯이 STL의 할당기도 사용자 직접 할당기를 정의하고 사용할 수 있습니다.
사용자 정의 할당기는 사용자가 직접 메모리 할당 방식을 제어할 수 있게 합니다.
다중 스레드에 최적화되고 안전한 사용자 메모리 할당 모델이 필요하거나 사용자가 컨테이너에 맞는 메모리 할당
모델을 설계하거나 특정 구현 환경(implementation)에서 최적화된 메모리할당 모델을 구축할 때 등에 사용합니다.
모든 컨테이너는 템플릿 매개변수에 할당기를 인자로 받습니다.
기본 할당기는 allocator<T>이며 컨테이너는 템플릿 매개변수에 디폴트 매개변수 값으로 기본 할당기를 지정합니다.
vector라면 vector<typename T, typename Alloc = allocator<T>>처럼
set이라면 set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>>처럼 지정됩니다.
5_14.cpp 컨테이너 기본 할당기 allocator<T>
vector<int, allocator<int>> v:vector의 두 번째 템플릿 매개변수가 할당기를 인자로 받습니다.
첫 번째 매개변수는 저장 객체 타입입니다.
set<int, less<int>, allocator<int>> s:set의 세 번째 템플릿 매개변수가 할당기를 인자로 받습니다.
첫 번째 매개변수는 저장 객체 타입, 두 번째 매개변수는 정렬 기준(조건자)입니다.

*/