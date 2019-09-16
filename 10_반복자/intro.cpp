/*
반복자는 컨테이너의 원소를 순회하고 접근하는 일반화된 방법을 제공합니다.
컨테이너와 알고리즘은 반복자를 통해 서로 통신(인터페이스)합니다.

01 반복자의 종류
반복자는 포인터를 추상화한 클래스 객체입니다.
그래서 포인터가 하지 못하는 더 많은 동작을 수행할 수 있습니다.
자료 형식이 있어 자료의 효율적인 연산이 가능하듯이 반복자도 각 반복자만의 특징을 가지는 다섯 가지의 반복자.
1)입력 반복자(input iterator):전방향 읽기(istream)
2)출력 반복자(output iterator):전방향 쓰기(ostream)
3)순방향 반복자(forward iterator):전방향 읽기, 쓰기
4)양방향 반복자(bidirectional iterator):양방향 읽기, 쓰기(list, set, multiset, map, multimap)
5)임의 접근 반복자(random access iterator):랜덤 읽기, 쓰기(vector, deque)

입력 반복자는 *iter(읽기), ->(멤버 읽기), ++(전방향 이동), ==(비교), !=(비교), iterator(iter)연산을 제공.
출력 반복자는 *iter=x(쓰기), ++, iterator(iter)(복사 생성자)연산을 제공합니다.
순방향 반복자는 *iter, ->, ++, ==, !=, =(대입), iterator()(기본 생성자), iterator(iter) 연산을 제공.
양방향 반복자는 순방향 반복자 기능에 --(역방향 이동) 연산을 제공합니다.
임의 접근 반복자는 양방향 반복자 기능에 반복자의 랜덤 연산인 [], +=, -=, +, -, <, >, <=, >=연산을 제공.

반복자에서 순차열(sequence)과 구간(range)는 중요한 개념입니다.
순차열은 순서있는 원소의 집합입니다.
순차열은 하나의 시작과 끝을 나타내는 반복자의 쌍으로 표현되며 구간(range)이라 합니다.
순차열의 시작 원소를 가리키는 반복자를 begin이라 하고 순차열의 끝을 가리키는 반복자를 end라 하면 이 순차열은
[begin, end)라는 구간으로 표현합니다.
[begin, end)는 반개 구간이라 하여 반복자 begin이 가리키는 원소는 순차열 원소에 포함되지만 반복자 end가
가리키는 원소는 순차열 원소에 포함되지 않습니다.
begin          end
 ↓              ↓
|10|20|30|40|50|60|
 ---------↑------->         
		 iter
구간 [begin, end)의 순차열:10 20 30 40 50
구간 [begin, iter)의 순차열:10 20 30
구간 [iter, end)의 순차열:40 50
구간은 반개 구간으로 표현되므로 end가 가리키는 60원소는 순차열에 포함되지 않습니다.

02 X::iterator와 X::const_iterator
STL의 모든 컨테이너는 정방향 반복자의 형식 X::iterator와 X::const_iterator를 정의합니다.
또한, 역방향 반복자 형식 X::reverse_iterator와 X::const_reverse_iterator를 정의합ㄴ디ㅏ.
1)X::iterator:정방향 반복자의 내장 형식. 반복자가 가리키는 원소 읽기, 쓰기 가능.
2)X::const_iterator:정방향 반복자의 내장 형식. 반복자가 가리키는 원소의 읽기 가능

list, set, multiset, map, multimap컨테이너의 X::iterator와 X::const_iterator는 양방향 반복자입니다.
vector, deque컨테이너의 X::iterator와 X::const_iterator는 임의 접근 반복자입니다.
컨테이너의 begin()멤버 함수는 컨테이너 순차열의 첫 원소를 가리키는 반복자를 반환하며 end()멤버 함수는
순차열의 끝 표시(past-the-end)반복자를 반환합니다.
모두 X::iterator형식이며 포인터처럼 X::iterator 형식은 X::const_iterator형식으로 자동변환됩니다.
10_1.cpp iterator와 const_iterator
iter는 iterator반복자로 가리키는 원소의 읽기, 쓰기가 가능한 반복자이며 citer는 const_iterator반복자로
가리키는 원소의 읽기만 가능한 반복자입니다.
반복자가 가리키는 원소의 위치를 변경하지 않으려면 const키워드를 사용하여 반복자를 const화 할 수 있습니다.
10_2.cpp X::iterator, X::const_iterator, const X::iterator, const X::const_iterator 반복자 비교
const X::iterator는 반복자 자체가 const객체이며 X::const_iterator는 반복자가 가리키는 원소가 const객체입니다.
       (const_iter) (const_citer)
     iter citer  |    | 
       ↓    ↓    ↓    ↓
v    | 10 |(20)| 30 |(40)| N |
()는 변경불가능(const)

vector, deque컨테이너는 배열 기반 컨테이너로 임의 접근 반복자를 지원하며 list, set, multiset, map, multimap은
양방향 반복자를 지원합니다.
10_3.cpp vector의 임의 접근 반복자와 list의 양방향 반복자
반복자는 *연산자로 가리키는 원소를 접근할 수 있으며 ->연산자로 가리키는 원소의 멤버를 접근합니다.
viter는 임의 접근 반복자이므로 viter += 2이 가능하지만, liter는 양방향 반복자이므로 liter += 2이 불가능.
임의 접근 반복자는 양방향 반복자 기능에 [], +=, -=, +, -, <, >, <=, >=연산 기능을 더 제공합니다.
정렬관련 알고리즘은 이 연산이 가능해야 하므로 임의 접근 반복자를 요구하며 vector와 deque컨테이너에 동작합니다.
  *viter                  *liter
v  |10|20|30| N|       lt  |10|20|30| N|
    ↑      ↑                ↑
  viter  viter+=2가능      liter  liter+=2불가능

03 X::reverse_iterator와 X::const_reverse_iterator
X::reverse_iterator와 X::const_reverse_iterator은 컨테이너에 정의된 역방향 반복자 형식입니다.
1)X::reverse_iterator:역방향 반복자의 내장 형식. 반복자가 가리키는 원소 읽기, 쓰기 가능
2)X::const_reverse_iterator:역방향 반복자의 내장 형식. 반복자가 가리키는 원소의 읽기 가능

list, set, multiset, map, multimap컨테이너의 X::reverse_iterator와 X::const_reverse_iterator는 양방향반복자.
vector, deque컨테이너의 X::reverse_iterator와 X::const_reverse_iterator는 임의 접근 반복자입니다.
컨테이너의 rbegin()멤버 함수는 컨테이너 순차열의 끝 표시(past-the-end)반복자입니다.
rend()멤버 함수는 순차열의 첫 원소를 가리키는 반복자를 반환합니다.
모두 X::reverse_iterator형식이며 포인터처럼 X::reverse_iterator형식은 X::const_iterator형식으로 자동 변환됩니다.
X::reverse_iterator반복자는 역방향 반복자로 X::iterator반복자와 반대로 동작.
10_4.cpp X::iterator와 X::reverse_iterator의 동작
iter는 ++하면 반복자가 순차열의 정방향으로 이동하지만 riter를 ++하면 반복자가 순차열의 역방향으로 이동합니다.
정방향 반복자는 가리키는 원소의 값(value)을 참조하지만, 역방향 반복자는 가리키는 다음 원소의 값(value)을 참조.
                       ++
정방향 반복자   begin() --> iter  end()
                 ↓    value↓     ↓ 
           v    |10|20|30|40|50| N|
		       ↖ ↑   ↖ ↑  value↖ ↑
역방향 반복자  rend() riter <-- rbegin()
                            ++
주의할 점은 역방향 반복자는 반복자가 가리키는 원소와 실제 값(value)가 다르다는 것.
역방향 반복자는 가리키는 다음 원소의 값(value)을 참조합니다.
왜냐하면 정방향 반복자로 표현한 순차열과 역방향 반복자로 표현한 순차열이 서로 같도록 하기 위해서입니다.
begin        end
  ↓           ↓ 
| 10| 20| 30| N |
↖ ↑    value↖ ↑
rend        rbegin
[begin, end)의 순차열:10 20 30
[rbegin, rend)의 순차열:30 20 10
두 순차열의 원소가 같다.

X::reverse_iterator와 X::const_reverse_iterator형식은 반복자 어댑터 reverse_iterator<T>를 사용해
X::iterator와 X::const_iterator를 반대로 동작하도록 변환한 형식입니다.
10_5.cpp 반복자 어댑터 reverse_iterator<T>
정방향 반복자 v.begin()과 v.end()를 역방향 반복자 rend, rbegin으로 변환하고 이 구간 ([rbegin, rend))의 순차열과
[rbegin(), rend())의 순차열을 출력합니다.
10_6.cpp 네 반복자 형식의 변환
포인터처럼 비const반복자는 const반복자로 형변환되며 정방향 반복자는 역방향 반복자로 암묵적 변환(생성자를 이용한).
역방향 반복자는 base()멤버 함수를 사용하여 정방향 반복자로 형변환할 수 있습니다.
     iter       
       ↓      
   |10|20|30|40|50|N |
value↖ ↑    
     riter
const_iterator <----- const_reverse_iterator
     ^          base()           ^
	 |                           |
  iterator     ─────>     reverse_iterator
               <-----
			   base()

04 삽입 반복자
삽입 반복자는 순차열에 원소를 삽입(insert)할 수 있게 반복자를 변환하는 반복자 어댑터입니다.
모든 알고리즘은 기본적으로 덮어쓰기 모드로 동작합니다.
삽입 반복자를 사용하면 알고리즘이 삽입 모드로 동작하게 할 수 있습니다.
1)inserter():insert_iterator객체를 생성합니다. insert_iterator객체는 컨테이너의 insert()멤버 함수를 호출해
삽입 모드로 동작하게 됩니다.
2)back_inserter():back_insert_iterator객체를 생성합니다. back_insert_iterator 객체는 컨테이너의 push_back()
멤버 함수를 호출해 뒤쪽에 추가(삽입)하도록 합니다.
3)front_inserter():front_insert_iterator객체를 생성합니다. front_insert_iterator 객체는 컨테이너의 push_front()
멤버 함수를 호출해 앞쪽에 추가(삽입)하도록 합니다.

모든 컨테이너는 insert()멤버 함수를 제공하므로 inserter()사용할 수 있지만 시퀀스 컨테이너인 vector, deque,
list만이 back_inserter()를 사용할 수 있고, deque, list만이 front_insert_iterator()를 사용할 수 있다.
덮어쓰기 모드는 원소의 개수가 변하지 않지만 삽입 모드는 원소의 개수가 늘어납니다.
덮어쓰기 모드
            iter                                    iter
             ↓                                       ↓
v size:3 |10|20|30| N|      ----->      v size:3 |10|50|30| N|
삽입 모드
			iter                                    iter
			 ↓                                       ↓
v size:3 |10|20|30| N|      ----->      v size:4 |10|50|20|30| N|
10_7.cpp 삽입 반복자 어댑터 inserter()
inserter<vector<int>>(v2, v2.begin()):v2.begin()반복자를 v2의 insert()멤버 함수를 호출하는 삽입 반복자로
변환합니다.
copy()알고리즘은 덮어쓰기 모드로 동작하므로 inserter()를 사용하지 않는다면 v2의 size가 0이므로 실행 오류가 발생.

list는 push_back()멤버 함수와 push_front()멤버 함수를 제공하므로 back_inserter, front_inserter반복자
어댑터를 사용할 수 있습니다.
10_8.cpp back_inserter(), front_inserter()
back_inserter<list<int>>(lt1):lt1의 push_back()멤버 함수를 호출하는 반복자를 생성합니다.
front_inserter<list<int>>(lt2):lt2의 push_front()멤버 함수를 호출하는 반복자를 생성합니다.
push_back()사용
                             lt1.end()
                                 ↓
lt1  |N | 1| 2| 3|10|20|30|40|50| N|
push_front()사용
	 lt2.begin()
		 ↓
lt2  |N |50|40|30|20|10| 1| 2| 3| N|

05 입/출력 스트림 반복자
입/출력 스트림 반복자는 스트림과 연결된 반복자로 알고리즘이 스트림에 읽고 쓸 수 있게 하는 반복자 어댑터입니다.
1)istream_iterator<T>:입력 스트림과 연결된 반복자로 T형식의 값을 스트림에서 읽을 수 있습니다.
2)ostream_iterator<T>:출력 스트림과 연결된 반복자로 T형식의 값을 스트림에 쓸 수 있습니다.

10_9.cpp ostream_iterator 출력 스트림 반복자
ostream_iterator<int>(cout):cout과 연결된 정수(int)를 출력하는 반복자를 생성합니다.
ostream_iterator<int>(cout, ", "):cout과 연결된 반복자를 생성하되 출력 끝 패턴을 ", "로 합니다.
transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plus<int>()):lt원소(3개)와
v원소(3개)의 합을 화면에 출력합니다.

istream_iterator를 사용하면 입력 스트림과 연결된 반복자를 생성할 수 있습니다.
입력의 끝은 끝 스트림 반복자(end-of-stream iterator)를 사용하며 istream_iterator<T>()처럼 기본 생성자로 생성.
10_10.cpp istream_iterator 입력 스트림 반복자
istream_iterator<int>(cin):표준 입력 스트림과 연결된 반복자를 생성합니다.
istream_iterator<int>():입력 스트림의 끝 반복자를 생성합니다.
back_inserter<vector<int>>(v):v의 push_back()멤버 함수를 호출하는 삽입 반복자를 생성합니다.
표준 입력 스트림의 끝이 Ctrl-D(end-of-file)이므로 정수를 입력하고 Ctrl-D를 입력하면 화면에 입력한 정수를 출력.

06 반복자 특성과 보조 함수
반복자는 반복자의 효율적인 사용을 위해 다섯 가지 반복자(입력, 출력 순방향, 양방향, 임의 접근 반복자)로 분류.
각 반복자는 자신만의 특징을 가지며 이 특징을 저장하는 템플릿 클래스를 가리켜 반복자 특성(iterator traits).
또한, 반복자를 지원하는 두 함수 advance()와 distance()함수로 임의 접근 반복자만이 가지고 있는 연산(+, -, +=, -=)을
다른 반복자도 가능하게 지원합니다.
1)advance(p, n):p반복자를 p+=n의 위치로 이동시킵니다.
2)n = distance(p1, p2):n은 p2-p1입니다.
10_11.cpp advance() 보조 함수
viter는 임의 접근 반복자이므로 +=연산이나 -=연산을 사용할 수 있지만 liter는 양방향 반복자이므로
advance()함수를 사용해야 합니다.

10_12.cpp distance() 보조 함수
vector는 임의 접근 반복자를 제공하므로 v.end()-v.begin()이 가능하지만, list는 양방향 반복자를 제공하므로
lt.end()-lt.begin()은 불가능합니다.
대부분 distance()함수의 반환 형식은 unsigned int나 int이지만 반복자마다 다릅니다.
정확히 말하면 반복자 특성의 difference_type형식입니다.
그래서 distance()함수는 다음과 같이 사용합니다.
iterator_traits<vector<int>::iterator>::difference_type n = distance(v.begin(), v.end());

사용자 알고리즘을 구현할 때 STL알고리즘처럼 일반화하면서도 반복자 종류의 특징에 따라 효율적인 동작을 하는
알고리즘을 구현하려면 STL이 제공하는 반복자 특성을 활용해야 합니다.
iterator_traits은 모든 반복자가 제공하는 다섯가지 정보인 iterator_category, value_type, difference_type,
pointer, reference를 하나의 템플릿 클래스로 제공하는 반복자의 공통된 인터페이스입니다.
template<class Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};
반복자의 다섯 가지 정보를 정의하며 템플릿의 인자로 반복자를 지정하면 이 반복자의 정보를 확인할 수 있습니다.

또한, STL은 반복자의 종류를 구분할 수 있게 다섯 개의 반복자 태그를 제공합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag:public input_iterator_tag {};
struct bidirectional_iterator_tag:public forward_iterator_tag {};
struct random_access_iterator_tag:public bidirectional_iterator_tag {};
사용자 Advance()함수를 구현한다고하면 iterator_traits을 이용해 반복자가 지원하는 정보를 확인(태그)하여
반복자에 맞춰 알고리즘을 효율적으로 구현할 수 있습니다.
Advance()함수가 임의 접근 반복자를 인자로 받는다면 임의 접근 반복자는 +, -, +=, -=등이 가능하므로 바로
반복자를 이동시킬 수 있지만 양방향 반복자를 인자로 받는다면 ++연산자만을 지원하므로 이동 위치까지 하나씩
이동시켜야 합니다.
이 때 Advance()함수는 iterator_traits를 이용해 반복자가 지원하는 반복자 태그(iterator_tag)를 확인하고 각
반복자마다 동작하는 오버로딩 _Advance()함수를 호출할 수 있습니다.
10_13.cpp 사용자 iterator_tag와 iterator_traits클래스
Advance(viter, 2)는 viter가 임의 접근 반복자를 지원하므로 +=연산을 수행하며,
Advance(liter, 2)는 liter가 양방향 반복자를 지원하므로 하나씩 ++연산을 수행합니다.

*/