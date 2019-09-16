/*
시퀀스 컨테이너는 저장 원소가 삽입 순서에 따라 상대적인 위치(순서)를 갖는 컨테이너이며,
연관 컨테이너는 특정 정렬 규칙에 따라 저장 원소가 정렬되는 컨테이너입니다.
표준 시퀀스 컨테이너는 vector, list, deque이며, 표준 연관 컨테이너는 set, map, multiset, multimap.

01 vector 컨테이너
vector컨테이너는 대표적인 시퀀스 컨테이너로 배열과 비슷하여 사용이 쉬우므로 자주 사용됩니다.

vector의 주요 인터페이스와 특징
1)vector의 템플릿 형식
템플릿 형식
template<typename T, typename Allocator = allocator<T>> //T는 vector 컨테이너 원소의 형식
class vector

2)vector의 인터페이스
생성자
vector v                 //v는 빈 컨테이너이다.
vector v(n)              //v는 기본값으로 초기화된 n개의 원소를 갖는다.
vector v(n, x)           //v는 x값으로 초기화된 n개의 원소를 갖는다.
vector v(v2)             //v는 v2 컨테이너의 복사본이다(복사 생성자 호출).
vector v(b, e)           //v는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.

멤버 함수
v.assign(n,x)            //v에 x값으로 n개의 원소를 할당한다.
v.assign(b,e)            //v를 반복자 구간 [b,e)로 할당한다.
v.at(i)                  //v의 i번째 원소를 참조한다(const, 비const버전이 있으며 범위 점검을 포함)
v.back()                 //v의 마지막 원소를 참조한다(const, 비const버전이 있음)
p = v.begin()            //p는 v의 첫 원소를 가리키는 반복자(const, 비const버전이 있음)
x = v.capacity()         //x는 v에 할당된 공간의 크기
v.clear()                //v의 모든 원소를 제거한다.
v.empty()                //v가 비었는지 조사한다.
p = v.end()              //p는 v의 끝을 표식하는 반복자다(const, 비const버전이 있음)
q = v.erase(p)           //p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
q = v.erase(b, e)        //반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소.
v.front()                //v의 첫 번째 원소를 참조한다.(const, 비const버전이 있음)
q = v.insert(p, x)       //p가 가리키는 위치에 x값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다.
v.insert(p, n, x)        //p가 가리키는 위치에 n개의 x값을 삽입한다.
v.insert(p, b, e)        //p가 가리키는 위치에 반복자 구간 [b, e)의 원소를 삽입한다.
x = v.max_size()         //x는 v가 담을 수 있는 최대 원소의 개수다(메모리의 크기).
v.pop_back()             //v의 마지막 원소를 제거한다.
v.push_back(x)           //v의 끝에 x를 추가한다.
p = v.rbegin()           //p는 v의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비const버전이 있음)
p = v.rend()             //p는 v의 역 순차열의 끝을 표식하는 반복자(const, 비const버전이 있음)
v.reserve(n)             //n개의 원소를 저장할 공간을 예약한다.
v.resize(n)              //v의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.
v.resize(n, x)           //v의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.
v.size()                 //v원소의 개수다.
v.swap(v2)               //v와 v2를 swap한다.

연산자
v1 == v2                 //v1과 v2의 모든 원소가 같은가?(bool형식)
v1 != v2                 //v1과 v2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool형식)
v1 < v2				     //문자열 비교처럼 v2가 v1보다 큰가?(bool형식)
v1 <= v2			     //문자열 비교처럼 v2가 v1보다 크거나 같은가?(bool형식)
v1 > v2					 //문자열 비교처럼 v1이 v2보다 큰가?(bool형식)
v1 >= v2				 //문자열 비교처럼 v1이 v2보다 크거나 같은가?(bool형식)
v[i]					 //v의 i번째 원소를 참조한다(const, 비const버전이 있으며 범위 점검이 없음).

3)vector의 템플릿 멤버 형식
멤버 형식
allocator_type           //메모리 관리자 형식
const_iterator           //const 반복자 형식
const_pointer            //const value_type* 형식
const_reference          //const value_type& 형식
const_reverse_iterator   //const 역 반복자 형식
difference_type          //두 반복자 차이의 형식
iterator                 //반복자 형식
pointer                  //value_type* 형식
reference                //value_type& 형식
reverse_iterator         //역 반복자 형식
size_type                //첨자(index)나 원소의 개수 등의 형식
value_type               //원소의 형식

vector는 시퀀스 컨테이너이므로 원소의 저장 위치(순서)가 정해지며 배열 기반 컨테이너이므로 원소가
하나의 메모리 블록에 할당됩니다.
vector
front                     back
|    |    |    |    |    |    |... ↔ push_back():추가
            ↑                        pop_back():제거
          insert():삽입
시퀀스 컨테이너는 차례차례 원소를 추가하고 제거하는 push_back()과 pop_back()을 가지며, 첫 원소와 마지막 원소를
참조하는 front()와 back()을 가집니다.
또한, 지정한 위치에 원소를 삽입할 수 있는 insert()를 가집니다.
vector는 앞쪽이 막혀 있는 형태로 앞쪽에는 원소를 추가/제거할 수 없으며 뒤쪽에만 추가/제거할 수 있습니다.
다른 시퀀스 컨테이너(list,deque)는 앞쪽의 원소를 추가/제거할 수 있는 push_front()와 pop_front()를 가진다.
6_1.cpp vector의 push_back()
vector<int> v:int 형식의 원소를 저장하는 컨테이너 v를 생성합니다.
v.push_back(x):v에 x를 추가합니다.
v.size():v의 원소의 개수를 반환합니다.
v[i]:v의 i번째 원소를 참조합니다.
시퀀스 컨테이너이므로 원소가 push_back()으로 저장한 순서대로 출력되는 것을 확인할 수 있다.
사실 i < v.size()에서 i는 int타입이지만 size()는 unsigned int타입을 반환해서 캄파일러 경고가 출력된다.
타입을 맞춰주는 것보다 좋은 코드는 vector내에 typedef된 멤버 형식을 사용하는 것입니다.
vector의 size_type은 원소의 개수나 []연산자 등의 index로 사용하는 형식의 typedef된 멤버 형식입니다.
vector<int>::size_type은 unsigned int 형식입니다.
vector<int>::size_type:vector의 크기, 첨자 형식을 위한 typedef 멤버 형식입니다.
typeid(T):T에 대한 typeinfo 객체를 리턴합니다.
 v size:5
|10| v[0]
|20| v[1]
|30| v[2]
|40| v[3]
|50| v[4]

참조(레퍼런스)
참조는 값을 복사하지 않고 같은 메모리 공간의 이름(참조)입니다.
int main() {
	int n = 10;
	int m = n;
	int& r = n;
	cout << n << ", " << m << ", " << r << endl;
}
m은 n의 복사본으로 독립적인 값을 갖습니다.
r은 n의 참조로 같은 메모리 공간의 이름입니다.
즉 n과 r은 동일한 값이며 n을 변경하면 r이 변경되고 r을 변경해도 n이 변경됩니다.
독립적인 메모리    같은 메모리
 ┌──|10| n           |10| n, r
복사	|  |             |  |
 └─>|10| m           |  |

vector는 크기를 반환하는 세 멤버 함수 size(), capacity(), max_size()를 가집니다.
size()는 저장 원소의 개수이며, capacity()는 실제 할당된 메모리 공간의 크기, 
max_size()는 컨테이너가 담을 수 있는 최대 원소의 개수입니다.
6_3.cpp vector의 size(), capacity(), max_size()
size()와 max_size()는 모든 컨테이너가 가지는 멤버 함수입니다.
하지만 capacity()는 유일하게 vector만이 가지는 멤버 함수입니다.
vector는 배열 기반 컨테이너이면서 원소를 컨테이너에 계속 추가할 수 있는 컨테이너입니다.
배열 기반 컨테이너이므로 연속한 메모리를 한 번에 할당하지만, 계속 원소가 추가될 수 있게 해야하므로
원소가 추가될 때마다 메모리가 자라나게 하려면 메모리를 재할당해야 합니다.
원소가 추가될 때마다 메모리를 재할당하고 이전 원소를 모두 복사해야 한다면 너무나 비효율적.
조금이나마 재할당에 드는 성능 문제를 보완하고자 만들어진 개념이 capacity입니다.
원소가 추가될 때마다 메모리를 재할당하지 않고 미리 넉넉한 메모리를 확보하면 재할당과 이전 원소를
복사하는데 드는 비용을 줄일 수 있습니다.
이것은 컨테이너 중 vector만이 가지고 있는 중요한 특징입니다.
6_4.cpp vector의 capacity()
출력 결과를 보면 미리 저장할 메모리의 크기(capacity)를 크게하면 원소가 추가되도 메모리의 크기가
변하지 않게 됩니다. 재할당되지 않습니다.
또한, 원소를 추가하려 할 때 메모리의 크기(capacity)가 원소의 개수(size)보다 크지 않다면 메모리 재할당을
수행하며 이전 메모리 크기의 1/2만큼을 더 할당하는 정책을 사용합니다.
이런 메모리 확장 정책(1.5*이전capacity)은 컴파일러마다 조금씩 다릅니다.
어떤 컴파일러는 두 배로 확장하는 컴파일러도 있습니다.
v size:0 capacity:0
v size:1 capacity:1 |10|                         최초 메모리 할당
v size:2 capacity:2 |10|20|                      메모리 재할당과 원소복사
v size:3 capacity:3 |10|20|30|                   메모리 재할당과 원소복사
v size:4 capacity:4 |10|20|30|40|                메모리 재할당과 원소복사
v size:5 capacity:6 |10|20|30|40|50|  |          메모리 재할당과 원소복사
v size:6 capacity:6 |10|20|30|40|50|60| 
v size:7 capacity:9 |10|20|30|40|50|60|70|  |  | 메모리 재할당과 원소복사
v size:8 capacity:9 |10|20|30|40|50|60|70|80|  |
v size:9 capacity:9 |10|20|30|40|50|60|70|80|90|

vector는 push_back()을 이용해 원소를 계속 추가할 수 있지만, 메모리 재할당과 이전 원소
복사 문제가 발생할 수 있습니다.
그래서 vector는 미리 메모리를 할당할 수 있는 메모리 예약 함수 reserve()를 제공합니다.
reserve()를 사용하면 미리 메모리를 할당해 capacity를 결정하고 vector에 원소가 추가되더라도
메모리를 재할당하지 않습니다.
6_5.cpp vector의 reserve()
v.reserve(8):v의 메모리 공간(capacity)을 8로 예약합니다.
size가 8이 될 때까지 메모리 재할당과 이전 원소의 복사는 일어나지 않습니다.
마지막 원소 90이 추가될 때 capacity는 8에서 12(1.5*8)로 재할당됩니다.
v size:0 capacity:8  |  |  |  |  |  |  |  |  |             최초 메모리 할당
v size:1 capacity:8  |10|  |  |  |  |  |  |  | 
v size:2 capacity:8  |10|20|  |  |  |  |  |  | 
v size:3 capacity:8  |10|20|30|  |  |  |  |  | 
v size:4 capacity:8  |10|20|30|40|  |  |  |  | 
v size:5 capacity:8  |10|20|30|40|50|  |  |  | 
v size:6 capacity:8  |10|20|30|40|50|60|  |  | 
v size:7 capacity:8  |10|20|30|40|50|60|70|  | 
v size:8 capacity:8  |10|20|30|40|50|60|70|80|
v size:9 capacity:12 |10|20|30|40|50|60|70|80|90|  |  |  | 메모리 재할당과 원소복사

size와 capacity는 잘 구분해서 사용해야 합니다.
size는 컨테이너에 저장된 원소의 개수이며 모든 컨테이너가 제공합니다.
capacity는 vector만이 제공하는 할당된 메모리의 크기입니다.
생성자를 사용하여 size를 미리 확보할 수 있습니다.
이때 원소의 값은 기본값(원소의 기본 생성자 호출 값)으로 초기화됩니다.
6_6.cpp vector의 생성자
vector<int> v(n):v는 n개의 size를 갖고 기본값(int())으로 초기화됩니다.
v[i]:i번째(index) 원소를 참조(기본 배열과 같음)합니다.
v1에 push_back()을 사용하면 기존 원소의 개수(size)에 원소가 추가됩니다.
size가 늘어납니다.
v2[0]는 원소의 참조이므로 v2[0] = 10은 원소를 수정합니다.
생성자의 두 번째 인자를 사용하여 원소의 초깃값을 지정할 수도 있습니다.
6_7.cpp vector 생성자의 초깃값 지정
vector<int> v2(5, 0):v2는 0으로 초기화된 size가 5인 컨테이너를 생성합니다.
vector<int> v3(5, 10):v3는 10으로 초기화된 size가 5인 컨테이너를 생성합니다.

생성자뿐만 아니라 resize()멤버 함수를 사용하여 컨테이너의 size를 변경할 수 있습니다.
주의할 점은 size를 키울 때 capacity도 늘어나지만, size를 줄일 때는 capacity가 줄지 않는다는 점.
6_8.cpp vector의 resize()
v.resize(n):v의 size를 n으로 확장하거나 축소합니다.
size가 5일 때 size를 10으로 확장하면 5개의 우너소가 뒤쪽에 추가된 형태로 size가 10이되며
size를 5로 축소하면 뒤쪽의 원소가 제거된 형태로 size가 5가 됩니다.
v size:5 capacity:5   |10|20|30|40|50|
v size:10 capacity:10 |10|20|30|40|50|0 |0 |0 |0 |0 |
v size:5  capacity:10 |10|20|30|40|50|  |  |  |  |  |
resize()멤버 함수의 두 번째 인자를 이용해 확장되는 원소에 초깃값을 지정할 수 있습니다.
v.resize(10, 100)은 size를 10으로 확장하고 추가되는 원소를 100으로 초기화하라는 문장.

vector뿐만 아니라 모든 컨테이너가 제공하는 clear()와 empty()는 각각 컨테이너의 모든 원소를 제거하고
컨테이너에 원소가 비었는지를 검사하는 멤버 함수입니다.
6_9.cpp vertor의 clear()와 empty()
v.clear():v를 비운다.
v.empty():v가 비었는지 검사한다.
v size:5 capacity:5   |10|20|30|40|50|
v size:0 capacity:5   |  |  |  |  |  |
size는 0이 되어도 메모리는 제거되지 않고 남아 있게 됩니다.
메모리가 부족한 상태라면 너무 비효율적입니다.
capacity를 0으로 만드는 함수는 존재하지 않지만 C++에서 권장하는 swap방법이 있습니다.
모든 컨테이너는 컨테이너 객체끼리 교환할 수 있는 swap()멤버 함수를 제공합니다.
swap()함수를 이용해 임시로 생성한(기본생성자에 의해 size,capacity가 0인) 컨테이너 객체와 서로 swap.
6_10.cpp swap을 사용한 할당 메모리 제거
vector<int>():기본 생성자를 사용하여 vector의 임시객체(capacity:0)을 생성합니다.
vector<int>().swap(v):생성된 임시 객체와 v를 swap합니다.
임시객체와 swap한 v는 size와 capacity가 0입니다.
swap()멤버 함수는 모든 컨테이너가 제공하며 두 컨테이너의 원소를 교환할 때 사용합니다.
6_11.cpp vector의 swap()
v1.swap(v2):v1의 멤버 함수 swap()을 호출해 두 컨테이너의 원소 v1과 v2를 교환합니다.

시퀀스 컨테이너는 삽입 위치(순서) 개념이 있으므로 모든 시퀀스 컨테이너 vector,list,deque는
첫 번째 원소의 참조와 마지막 원소의 참조인 front(), back()멤버 함수를 제공합니다.
6_12.cpp vector의 front()와 back()
v.front():첫 번째 원소를 참조합니다.
v.back():마지막 원소를 참조합니다.
v
front()    v[2]     back()
           v.at(2)
| 10 | 20 | 30 | 40 | 50 |
front(), back()은 첫 번째 원소와 마지막 원소의 참조이므로 이 멤버 함수를 이용해 원소의 값 수정할 수 있다.
6_13.cpp vector의 front()와 back() 참조
v의 첫 번째 원소와 마지막 원소를 각각 front()와 back()으로 수정합니다.

시퀀스 컨테이너 중 배열 기반 컨테이너인 vector와 deque는 일반 배열 처럼 임의 위치의 원소를 참조하는
두 인터페이스를 제공합니다. []와 at() 멤버 함수.
두 인터페이스의 기능은 같지만 []연산자는 범위 점검을 하지 않아 속도가 빠르며
at()멤버 함수는 범위를 점검하므로 속도는 느리지만 안전합니다.
6_14.cpp vector의 []연산자와 at()멤버 함수
[]연산자와 at()멤버 함수의 기능이나 결과는 같습니다.
차이점은 범위 점검을 하느냐 하지 않느냐의 차이.
[]연산자는 범위 점검 없이 동작하며 at()멤버 함수는 범위 점검을 하며 동작합니다.
v.at(i)는 i가 0 <= i < size이면 i index의 참조를 반환하며 아니면 out_of_range 예외가 발생합니다.
6_15.cpp at()의 out_of_range 예외
v.at(6):v의 size가 5이므로 0 <= i < 5의 범위를 확인하고 i가 6이므로 out_of_range예외가 발생.
at()멤버 함수를 []연산자로 바꾼다면 범위점검을 하지 않고 메모리 접근 오류가 발생합니다.

컨테이너 생성 후에도 assign()멤버 함수를 사용하면 일관적으로 값을 할당할 수 있습니다.
모든 시퀀스 컨테이너는 assign()멤버 함수를 제공하여 일관적으로 값을 할당할 수 있습니다.
6_16.cpp
v.assign(n, x):n개의 원소에 x값을 할당합니다.
반복자 버전의 assign()멤버 함수도 제공합니다.

STL의 모든 컨테이너는 양방향 반복자 이상의 기능을 제공합니다.
배열 기반 컨테이너는 vector와 deque는 임의 접근 반복자를 제공하며
노드 기반 컨테이너인 list, set, multiset, map, multimap은 양방향 반복자를 제공합니다.
또한, 컨테이너는 동작 방식이 조금씩 다른 iterator, const_iterator, reverse_iterator,
cont_reverse_iterator 등 네 개의 반복자를 내장하고 있습니다.
컨테이너는 모든 원소(순차열)의 시작과 끝을 가리키는 반복자 쌍(구간)을 begin()과 end()멤버 함수로
제공하며 컨테이너의 모든 원소는 구간 [begin(),end())로 표현할 수 있습니다.
6_17.cpp vector의 begin()과 end()
vector<int>::iterator:반복자 클래스입니다. vector내에 정의되있습니다.
vector<int>::iterator iter:iter라는 반복자 객체를 생성합니다.
v.begin():v의 첫 번째 원소를 가리키는 반복자를 반환합니다.
v.end():v의 끝을 표식하는 반복자를 반환합니다.
iter != v.end():iter가 끝을 표식하는 반복자가 아니면 참입니다.
++iter:반복자를 다음 원소를 가리키도록 이동합니다.
*iter:반복자가 가리키는 원소의 참조입니다.
iter는 반복자이며 ++연산자로 다음 원소로 이동하고 *연산자로 가리키는 원소를 참조합니다.
begin()                  end()
 ↓   *iter                ↓
|10|-|20|-|30|-|40|-|50|-|N|
	   ↑
	  iter
[begin(),iter)의 순차열:10

배열 기반 컨테이너는 임의 접근 반복자를 제공하며 접근 반복자는 +,-,+=,-=,[]연산이 가능합니다.
6_18.cpp vertor 반복자의 연산
iter = v.begin():시작 원소를 가리킵니다.
iter += 2:+2한 위치의 원소를 가리킵니다.
iter -= 1:-1한 위치의 원소를 가리킵니다.
*iter:가리키는 원소를 참조합니다.

만약 반복자가 가리키는 원소의 값을 변경하지 않는다면 상수 반복자를 사용하는 것이 좋다.
일반 반복자(iterator)는 포인터(int*)와 비슷하고 상수 반복자(const_iterator)는 상수포인터(const int*)와 비슷.
6_19.cpp 일반 반복자와 상수 반복자
*iter, *citer:iter와 citer가 가리키는 원소를 참조합니다.
++iter, ++citer:iter와 citer를 다음 원소로 이동합니다.
*iter = 100:*iter의 원소를 100으로 수정합니다.
*citer = 100:citer가 상수 반복자이므로 *citer의 원소를 100으로 수정하지 못합니다.
상수 반복자를 사용하면 const포인터처럼 데이터를 읽기 전용으로 안전하게 사용할 수 있습니다.
주의할 점은 const vector<int>::iterator는 int* const처럼 동작하여 반복자를 이동시킬 수 없다.
6_20.cpp const와 반복자
vector<int>::iterator iter:iter는 다음 원소로 이동 가능하고 원소의 변경이 가능한 반복자입니다.
vector<int>::const_iterator citer:citer는 다음 원소로 이동 가능하고 원소의 변경이 불가능한 반복자입니다.
const vector<int>::iterator iter_const:iter_const는 다음 원소로 이동 불가능하고 원소의 변경이 가능한 반복자입니다.
const vector<int>::const_iterator citer_const:citer_const는 다음 원소로 이동 불가능하고 
원소의 변경이 불가능한 반복자입니다.
사실 iterator와 const_iterator만을 주로 사용한다.
        v               v                      v                       v
iter → |10|   citer → |(10)|   (iter_const) → |10|   (citer_const) → |(10)|
       |20|           | 20 |                  |20|                   | 20 |
iter++;     O citer++;     O   iter_const++;     X   citer_const++;     X
*iter = 20; O *citer = 20; X   *iter_const = 20; O   *citer_const = 20; X
()는 상수로 고정.
iterator(정방향 반복자)와 반대로 동작하는 반복자가 필요하다면 reverse_iterator(역방향 반복자)를 사용합니다.
reverse_iterator는 vector에 반복자 어댑터로 typedef되어 있습니다.
원소의 역순차열은 rbegin()과 rend()가 반환하는 reverse_iterator로 표현할 수 있습니다.
[rbegin(),rend())는 컨테이너 모든 원소의 역순차열입니다.
6_21.cpp iterator와 reverse_iterator
vector<int>::iterator iter:정방향 반복자 iter를 생성합니다.
vector<int>::reverse_iterator riter:역방향 반복자 riter를 생성합니다.
v.rbegin():역방향 반복자의 첫 원소(정방향 반복자의 끝)를 가리키는 반복자입니다.
v.rend():역방향 반복자의 마지막 원소(정방향 반복자의 첫 원소)를 가리키는 반복자입니다.

insert()멤버 함수를 사용하면 반복자가 가리키는 위치에 원소(값)을 추가할 수 있으며
erase()멤버 함수는 반복자가 가리키는 위치의 원소를 제거할 수 있습니다.
6_22.cpp insert()멤버 함수의 사용
iter = v.begin() + 2:iter는 30원소를 가리키는 반복자.
iter2 = v.insert(iter, 100):iter가 가리키는 위치에 100을 삽입하고 삽입한 100의 위치를 가리키는 반복자를
반환하여 iter2에 대입합니다.
주의할 점은 원소를 '삽입'하면 반복자가 가리키는 위치의 원소 자리에 삽입됩니다.
삽입 위치부터 뒤에 있는 모든 원소는 뒤로 밀려납니다.
           iter                                            iter2
		    ↓                        ----->                  ↓
| 10 | 20 | 30 | 40 | 50 |NULL|                  | 10 | 20 | 100| 30 | 40 | 50 |NULL|
vector는 여러 개의 원소를 한 번에 삽입하는 버전의 insert()멤버 함수와 반복자 쌍을 사용하여
원소를 삽입할 수 있는 버전의 insert()멤버 함수를 제공합니다.
6_23.cpp 다른 버전의 insert()멤버 함수
v.insert(iter, 3, 100):iter가 가리키는 위치의 v컨테이너에 3개의 100값을 삽입합니다.
v2.insert(iter, v.begin(), v.end()):iter가 가리키는 위치의 v2컨테이너에 구간의 원소를 삽입합니다.

특정 위치의 원소를 제거하려면 erase멤버 함수를 사용합니다.
erase는 반복자를 사용하여 원소를 한 개 혹은 여러 개 제거할 수 있습니다.
6_24.cpp erase() 멤버 함수
v.erase(iter):iter가 가리키는 위치의 원소(30)을 제거합니다. 제거된 원소의 다음 원소를 가리키는 반복자를 반환.
v.erase(v.begin()+1, v.end()):구간[v.begin()+1, v.end())의 원소(20,40,50)를 제거합니다.
제거된 원소의 다음 원소를 가리키는 반복자를 반환합니다.
		   iter                                            iter2
			↓                        ----->                  ↓
| 10 | 20 | 30 | 40 | 50 |NULL|                  | 10 | 20 | 40 | 50 |NULL|
   v.begin()+1      v.end()                           iter2
	   ↓              ↓              ----->             ↓
| 10 | 20 | 40 | 50 |NULL|                       | 10 |NULL|
insert()와 erase()멤버 함수 말고도 반복자로 동작하는 vector의 인터페이스가 더 있습니다.

vector의 생성자는 반복자를 통해서 초기화될 수 있으며 assign()멤버 함수도 반복자를 통해 할당될 수 있습니다.
6_25.cpp 반복자로 동작하는 생성자와 assign()멤버 함수
vector<int> v2(v.begin(), v.end()):순차열 [v.begin(), v.end())로 v2를 초기화합니다.
v3.assign(v.begin(), v.end()):순차열 [v.begin(), v.end())로 v3를 할당합니다.

컨테이너 연산자는 컨테이너와 컨테이너를 비교하기 위해 제공하는 연산으로 vector뿐만 아니라 다른 컨테이너
모두 제공하는 연산입니다.
컨테이너 연산자로는 ==, !=, <, <=, >, >=가 있습니다.
6_26.cpp vector와 vector의 비교
v1 == v2:v1과 v2의 모든 원소가 같다면 참 아니면 거짓입니다.
v1 != v2:v1과 v2의 모든 원소가 같다면 거짓 아니면 참입니다.
v1 < v2:v1과 v2의 순차열의 원소를 하나씩 순서대로 비교하여 v2의 원소가 크다면 참 아니면 거짓입니다.
컨테이너 비교 연산은 문자열 비교처럼 원소를 하나씩 비교합니다.
 v1      v2
|10| == |10|
|20| == |20|
|30| <  |50|
|40|
|50|

vector의 주요 특징 정리
vector는 임의 접근 반복자를 지원하는 배열 기반 컨테이너입니다.
vector의 가장 큰 특징 중 하나는 원소가 하나의 메모리 블록에 연속(배열 기반 컨테이너)하게 저장된다는 것.
vector
front():참조           at(i) v[i]:참조                   back():참조
|          |          |          |          |          |          |... ↔ push_back():추가
									  ↕                                  pop_back():제거
reserve():메모리 예약할당		        insert():삽입
capacity():메모리 크기		        erase():제거
그렇다 보니 원소가 추가되거나 삽입될 때 메모리 재할당이 발생할 수 있고 상당한 비용을 지불하게 됩니다.
그래서 메모리 할당 크기를 알 수 있게 capacity() 멤버 함수를 제공하며, 한 번에 메모리를 예약(할당)하고
사용할 수 있는 reserve()멤버 함수를 제공합니다.
원소가 연속하게 저장되므로 원소에 접근하는 at()이나 v[i] 등의 연산은 속도가 빠르지만 insert(), erase(),
push_back() 등이 빈번하게 호출되어야 하는 프로그램이라면 다른 컨테이너의 선택을 고려해야 합니다.
또한, 시퀀스 기반 컨테이너로 원소가 서로 상대적인 위치(순서)를 유지하므로 가장 앞 요소와 가장 뒤 요소를 참조하는
front(), back()멤버 함수를 제공하며 컨테이너 끝에 추가하고 제거하는 push_back(), pop_back()멤버 함수들 제공.
vector가 시퀀스 기반 컨테이너지만 배열 기반 컨테이너이므로 push_front()와 pop_front() 멤버 함수는 제공하지 않음.
이 두 멤버 함수는 vector에서 매우 비효율적으로 동작하기 때문.
vector는 연속한 원소를 index정수로 빠르게 접근하도록 at()와 []연산자를 제공합니다.
at()와 []연산자는 같은 기능을 수행하지만, at()은 유효 범위를 점검하여 안전하게 원소에 접근하도록 하며,
[]연산자는 유효 범위를 점검하지 않아 원소 접근 속도를 조금 더 높입니다.

02 deque 컨테이너
deque컨테이너는 vector컨테이너와 기능과 동작이 비슷한 컨테이너로 vector의 단점을 보완하는 몇가지 특징을 갖음.
deque도 vector 컨테이너와 같이 시퀀스 컨테이너이며 배열 기반 컨테이너입니다.

deque의 주요 인터페이스와 특징
1)deque의 템플릿 형식
템플릿 형식
template<typename T, typename Allocator = allocator<T>> //T는 deque 컨테이너 원소의 형식
class deque

2)deque의 인터페이스
생성자
deque dq                 //dq는 빈 컨테이너이다.
deque dq(n)              //dq는 기본값으로 초기화된 n개의 원소를 갖는다.
deque dq(n, x)           //dq는 x값으로 초기화된 n개의 원소를 갖는다.
deque dq(dq2)            //dq는 dq2 컨테이너의 복사본이다(복사 생성자 호출).
deque dq(b, e)           //dq는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.

멤버 함수
dq.assign(n,x)           //dq에 x값으로 n개의 원소를 할당한다.
dq.assign(b,e)           //dq를 반복자 구간 [b,e)로 할당한다.
dq.at(i)                 //dq의 i번째 원소를 참조한다(const, 비const버전이 있으며 범위 점검을 포함)
dq.back()                //dq의 마지막 원소를 참조한다(const, 비const버전이 있음)
p = dq.begin()           //p는 dq의 첫 원소를 가리키는 반복자(const, 비const버전이 있음)
dq.clear()               //dq의 모든 원소를 제거한다.
dq.empty()               //dq가 비었는지 조사한다.
p = dq.end()             //p는 dq의 끝을 표식하는 반복자다(const, 비const버전이 있음)
q = dq.erase(p)          //p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
q = dq.erase(b, e)       //반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소.
dq.front()               //dq의 첫 번째 원소를 참조한다.(const, 비const버전이 있음)
q = dq.insert(p, x)      //p가 가리키는 위치에 x값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다.
dq.insert(p, n, x)       //p가 가리키는 위치에 n개의 x값을 삽입한다.
dq.insert(p, b, e)       //p가 가리키는 위치에 반복자 구간 [b, e)의 원소를 삽입한다.
x = dq.max_size()        //x는 dq가 담을 수 있는 최대 원소의 개수다(메모리의 크기).
dq.pop_back()            //dq의 마지막 원소를 제거한다.
dq.pop_front()           //dq의 첫 원소를 제거한다.
dq.push_back(x)          //dq의 끝에 x를 추가한다.
dq.push_front(x)         //dq의 앞쪽에 x를 추가한다.
p = dq.rbegin()          //p는 dq의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비const버전이 있음)
p = dq.rend()            //p는 dq의 역 순차열의 끝을 표식하는 반복자(const, 비const버전이 있음)
dq.resize(n)             //dq의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.
dq.resize(n, x)          //dq의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.
dq.size()                //dq원소의 개수다.
dq.swap(dq2)             //dq와 dq2를 swap한다.

연산자
dq1 == dq2               //dq1과 dq2의 모든 원소가 같은가?(bool형식)
dq1 != dq2               //dq1과 dq2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool형식)
dq1 < dq2				 //문자열 비교처럼 dq2가 dq1보다 큰가?(bool형식)
dq1 <= dq2			     //문자열 비교처럼 dq2가 dq1보다 크거나 같은가?(bool형식)
dq1 > dq2				 //문자열 비교처럼 dq1이 dq2보다 큰가?(bool형식)
dq1 >= dq2				 //문자열 비교처럼 dq1이 dq2보다 크거나 같은가?(bool형식)
dq[i]					 //dq의 i번째 원소를 참조한다(const, 비const버전이 있으며 범위 점검이 없음).

3)deque의 템플릿 멤버 형식
멤버 형식
allocator_type           //메모리 관리자 형식
const_iterator           //const 반복자 형식
const_pointer            //const value_type* 형식
const_reference          //const value_type& 형식
const_reverse_iterator   //const 역 반복자 형식
difference_type          //두 반복자 차이의 형식
iterator                 //반복자 형식
pointer                  //value_type* 형식
reference                //value_type& 형식
reverse_iterator         //역 반복자 형식
size_type                //첨자(index)나 원소의 개수 등의 형식
value_type               //원소의 형식

deque는 vector와 매우 유사한 컨테이너고 시퀀스컨테이너이며 배열 기반 컨테이너입니다.
deque          
                                             insert():삽입
                        front                     ↓
push_front():추가 ↔ ...|          |          |          |          |
pop_front():제거       |          |          |          |          |
		               |          |          |          |          |... ↔ push_back():추가
					                                        back          pop_back():제거
deque와 vector와 다른 점은 메모리 블록 할당 정책입니다.
vector는 하나의 메모리 블록 할당 정책은 배열처럼 정수 연산만으로 원소에 접근하고 빠르게 값을 읽고 쓸 수 있었다.
하지만 새로운 원소가 추가될 때 메모리 재할당과 이전 원소 복사 문제가 발생하여 성능이 저하될 수 있습니다.
deque는 vector의 단점을 해결하기 위해 여러 개의 메모리 블록을 할당하고 사용자에게는 하나의 블록처럼
보이게 하는 정책을 사용합니다.
원소의 추가시 메모리가 부족할 때마다 일정한 크기의 새로운 메모리 블록을 할당하여 이전 메모리를 제거하거나
이전 원소를 복사하는 등의 연산을 수행하지 않습니다.
6_27.cpp push_back 멤버 함수
dq.push_back(10):dq에 정수 10을 추가합니다.
dq[i]:i번째 원소의 참조입니다.
vector와 다른 점은 메모리 할당 정책입니다.
원소가 추가될 때 메모리가 부족하면 새로운 메모리 블록을 할당하여 원소를 추가합니다.
              dq size:0
push_back(10) dq size:1 |10|  |  |  | 메모리할당
push_back(20) dq size:2 |10|20|  |  |
push_back(30) dq size:3 |10|20|30|  |
push_back(40) dq size:4 |10|20|30|40|
push_back(50) dq size:5 |10|20|30|40|
                        |50|  |  |  | 메모리할당
push_back(60) dq size:6 |10|20|30|40|
		                |50|60|  |  |
6_28.cpp vector와 deque
결과는 같지만 새로운 원소가 추가되면 v는 메모리 블록을 재할당하고 이전 원소를 복사 후 새로운 원소를 추가합니다.
dq는 새로운 메모리 블록을 할당하고 새로운 원소를 추가합니다.
                        push_back(200)                  ┌───원소 복사───┐
 v size:4 |100|100|100|100| -----> 메모리 삭제 후 size:5 |100|100|100|100|200|   | 메모리 재할당
dq size:4 |100|100|100|100| -----> size:5 |100|100|100|100|
                                          |200|   |   |   | 메모리 할당

deque는 앞쪽뒤쪽에 원소를 추가/제거할 수 있으므로 push_front()멤버 함수와 push_back()멤버 함수를 제공합니다.
6_29.cpp deque의 push_front()
dq.push_front(100):dq의 앞쪽에 100을 추가합니다.
원소를 앞쪽에 추가하면 새로운 메모리 블록을 할당하고 원소를 저장해 나갑니다.
dq size:5 | 10| 20| 30| 40|
          | 50|   |   |   |
push_front(100)
		  |   |   |   |100| 메모리 할당
dq size:6 | 10| 20| 30| 40|
		  | 50|   |   |   |
push_front(200)
		  |   |   |200|100|
dq size:7 | 10| 20| 30| 40|
		  | 50|   |   |   |

deque의 반복자는 임의 접근 반복자가 제공하는 +,-,+=,-=,[]연산을 모두 수행할 수 있습니다.
6_30.cpp deque의 반복자
dq.begin() + 2:시작 원소(10)을 가리키는 반복자에 +2(30)합니다.
iter += 2:iter반복자(30)에 +2(50)합니다.
deque의 반복자는 vector의 반복자와 동일하게 동작합니다.
insert()멤버 함수를 사용하여 반복자가 가리키는 임의의 위치에 원소를 삽입할 수 있습니다.
하지만, deque의 inset()멤버 함수는 vector보다 효율적으로 동작합니다.
vector는 새로운 원소를 삽입할 때 할당된 메모리가 부족하면 이전 메모리 블록을 삭제하고 새로운 메모리 블록을
재할당하며 이전 원소를 모두 복사하지만, deque는 새로운 단위의 메모리 블록을 할당하고 원소를 삽입합니다.
또한, 새로운 원소를 순차열 중간에 삽입(insert), 제거(erase)하더라도 원소의 개수가 작은 쪽으로 밀어냅니다.
6_31.cpp deque의 insert()
iter = dq.begin() + 2:iter는 시작 원소를 가리키는 반복자에 +2한 반복자(30)입니다.
iter2 = dq.insert(iter, 500):iter2는 삽입된 원소를 가리키는 반복자입니다.
iter가 가리키는 위치보다 삽입할 원소(500)가 앞쪽에 삽입됩니다.
insert, erase 동작은 vector와 같습니다.
차이점은 vector보다 효율적으로 동작한다는 사실입니다.
dq에 500을 삽입하면 앞쪽 원소의 개수가 적기 때문에 앞쪽으로 밀어내며 삽입됩니다.
                    iter
                     ↓
dq size:10 | 10| 20| 30| 40|
           | 50| 60| 70| 80|
		   | 90|100|   |   |

			   iter2:insert()함수의 반환 반복자
			     |
		   |   | ↓ |   | 10| 앞쪽으로 밀려나서 메모리 할당
dq size:11 | 20|500| 30| 40|
		   | 50| 60| 70| 80|
		   | 90|100|   |   |

deque의 주요 특징 정리
시퀀스 컨테이너이며 배열 기반 컨테이너입니다. vector와 유사한 특징을 가지며 임의 접근 반복자를 지원합니다.
다른 점은 원소가 메모리 블록에 연속하게 저장되지만 하나의 메모리 블록이 아닌 여러 메모리 블록에 나뉘어 저장됨.
deque
											 insert():삽입
											 erase():제거
				       front():참조                ↕
push_front():추가 ↔ ...|          |          |          |          |
pop_front():제거       |          |          |          |          |
					   |          |          |          |          |... ↔ push_back():추가
					  at(i)	dq[i]:참조        			 back():참조       pop_back():제거
deque는 원소를 앞쪽과 뒤쪽에 모두 추가할 수 있으며 배열 기반 컨테이너의 특징을 가지면서도 vector보다 더 효율적.
앞뒤에 원소를 추가/제거하는 멤버 함수는 push_front(), pop_front(), push_back(), pop_back().
시퀀스 기반 컨테이너는 원소가 서로 상대적인 위치(순서)를 유지하므로 가장 앞 요소와 가장 뒤 요소를 참조하는
front(), back()멤버 함수를 제공합니다.
또한, 컨테이너 끝에 추가하고 제거하는 push_back(), pop_back() 멤버 함수를 제공합니다.
deque가 시퀀스 기반 컨테이너이므로 insert()나 erase()멤버 함수가 호출되면 삽입, 제거될 위치로부터 모든 
원소를 밀어내야 합니다.
상당히 비효율적으로 동작하지만 vector보다는 조금 더 효율적으로 동작.
vector는 모든 원소를 뒤쪽으로만 밀어낼 수 있지만 deque는 뒤쪽이나 앞쪽으로 밀어낼 수 있기 때문.
deque도 연속한 원소를 index정수로 빠르게 접근하도록 at()와 []연산자를 제공합니다.
at()과 []연산자는 같은 기능을 수행하지만, at()은 유효범위를 점검하여 안전하게 원소에 접근하도록 하며
[]연산자는 유효범위를 점검하지 않아 원소 접근 속도를 조금 더 높입니다.

03 list 컨테이너
list컨테이너는 시퀀스 컨테이너로 우너소가 상대적인 순서를 유지합니다.
하지만 list는 노드 기반 컨테이너로 원소가 노드 단위로 저장되며 list는 이중 연결 리스트로 구현됩니다.

list의 주요 인터페이스와 특징
1)list의 템플릿 형식
템플릿 형식
template<typename T, typename Allocator = allocator<T>> //T는 list 컨테이너 원소의 형식
class list

2)list의 인터페이스
생성자
list lt                  //lt는 빈 컨테이너이다.
list lt(n)               //lt는 기본값으로 초기화된 n개의 원소를 갖는다.
list lt(n, x)            //lt는 x값으로 초기화된 n개의 원소를 갖는다.
list lt(lt2)             //lt는 lt2 컨테이너의 복사본이다(복사 생성자 호출).
list lt(b, e)            //lt는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.

멤버 함수
lt.assign(n,x)           //lt에 x값으로 n개의 원소를 할당한다.
lt.assign(b,e)           //lt를 반복자 구간 [b,e)로 할당한다.
lt.back()                //lt의 마지막 원소를 참조한다(const, 비const버전이 있음)
p = lt.begin()           //p는 lt의 첫 원소를 가리키는 반복자(const, 비const버전이 있음)
lt.clear()               //lt의 모든 원소를 제거한다.
lt.empty()               //lt가 비었는지 조사한다.
p = lt.end()             //p는 lt의 끝을 표식하는 반복자다(const, 비const버전이 있음)
q = lt.erase(p)          //p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
q = lt.erase(b, e)       //반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소.
lt.front()               //lt의 첫 번째 원소를 참조한다.(const, 비const버전이 있음)
q = lt.insert(p, x)      //p가 가리키는 위치에 x값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다.
lt.insert(p, n, x)       //p가 가리키는 위치에 n개의 x값을 삽입한다.
lt.insert(p, b, e)       //p가 가리키는 위치에 반복자 구간 [b, e)의 원소를 삽입한다.
x = lt.max_size()        //x는 lt가 담을 수 있는 최대 원소의 개수다(메모리의 크기).
lt.merge(lt2)            //lt2를 lt로 합병 정렬한다(오름차순:less).
lt.merge(lt2, pred)      //lt2를 lt로 합병 정렬한다. pred(조건자)를 기준으로 합병한다(pred는 이항조건자).
lt.pop_back()            //lt의 마지막 원소를 제거한다.
lt.pop_front()           //lt의 첫 원소를 제거한다.
lt.push_back(x)          //lt의 끝에 x를 추가한다.
lt.push_front(x)         //lt의 앞쪽에 x를 추가한다.
p = lt.rbegin()          //p는 lt의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비const버전이 있음)
lt.remove(x)             //x원소를 모두 제거한다.
lt.remove_if(pred)       //pred(단항 조건자)가 '참'인 모든 원소를 제거한다.
p = lt.rend()            //p는 lt의 역 순차열의 끝을 표식하는 반복자(const, 비const버전이 있음)
lt.resize(n)             //lt의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.
lt.resize(n, x)          //lt의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.
lt.reverse()             //lt 순차열을 뒤집는다.
lt.size()                //lt원소의 개수다.
lt.sort()                //lt의 모든 원소를 오름차 순(less)으로 정렬한다.
lt.sort(pred)            //lt의 모든 원소를 pred(조건자)를 기준으로 정렬한다. pred는 이항 조건자.
lt.splice(p, lt2)        //p가 가리키는 위치에 lt2의 모든 원소를 잘라 붙인다.
lt.splice(p, lt2, q)     //p가 가리키는 위치에 lt2의 q가 가리키는 원소를 잘라 붙인다.
lt.splice(p, lt2, b, e)  //p가 가리키는 위치에 lt2의 순차열[b,e)을 잘라 붙인다.
lt.swap(lt2)             //lt와 lt2를 swap한다.
lt.unique()              //인접한 원소의 값이 같다면 유일한 원소의 순차열로 만든다.
lt.unique(pred)          //인접한 원소가 pred(이항 조건자)의 기준에 맞다면 유일한 원소의 순차열로 만든다.

연산자
lt1 == lt2               //lt1과 lt2의 모든 원소가 같은가?(bool형식)
lt1 != lt2               //lt1과 lt2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool형식)
lt1 < lt2				 //문자열 비교처럼 lt2가 lt1보다 큰가?(bool형식)
lt1 <= lt2			     //문자열 비교처럼 lt2가 lt1보다 크거나 같은가?(bool형식)
lt1 > lt2			     //문자열 비교처럼 lt1이 lt2보다 큰가?(bool형식)
lt1 >= lt2				 //문자열 비교처럼 lt1이 lt2보다 크거나 같은가?(bool형식)

3)list의 템플릿 멤버 형식
멤버 형식
allocator_type           //메모리 관리자 형식
const_iterator           //const 반복자 형식
const_pointer            //const value_type* 형식
const_reference          //const value_type& 형식
const_reverse_iterator   //const 역 반복자 형식
difference_type          //두 반복자 차이의 형식
iterator                 //반복자 형식
pointer                  //value_type* 형식
reference                //value_type& 형식
reverse_iterator         //역 반복자 형식
size_type                //첨자(index)나 원소의 개수 등의 형식
value_type               //원소의 형식
list는 시퀀스 컨테이너이므로 원소의 저장위치(순서)가 정해지며 노드 기반 컨테이너이므로 원소가 각각의 노드에 저장.
각 노드는 앞쪽, 뒤쪽 노드와 연결된 형태로 이중 연결 리스트입니다.
list                                
                                    insert():삽입
                          front        ↓                   back
push_front():추가 ↔ ... ←||    ||→ ←||    ||→ ←||    ||→ ←||    ||→ ... ↔ push_back():추가 
pop_front():제거                                                          pop_back():제거
list는 시퀀스 컨테이너의 모든 특징을 갖습니다.
컨테이너 앞쪽과 뒤쪽에 차례차례 원소를 추가하고 제거하는 push_front()와 pop_front(), push_back()과
pop_back()을 가지며 첫 원소와 마지막 원소를 참조하는 front()와 back()을 갖습니다.
또한, 지정한 위치에 원소를 삽입하고 제거하는 insert()와 erase()를 갖습니다.
list는 노드 기반 컨테이너로 at()와 []연산자가 없으며 양방향 반복자를 제공합니다.
그래서 모든 원소를 탐색하려면 양방향 반복자의 연산인 ++, --를 사용합니다.
6_32.cpp list의 push_back, push_front, 반복자
list는 원소를 앞쪽, 뒤쪽에 모두 추가할 수 있으며 양방향 반복자를 제공하므로 ++연산과 *연산 !=연산으로
list의 모든 원소를 출력할 수 있습니다.

list의 가장 큰 특징 중 하나는 순차열 중간에 insert, erase하더라도 상수 시간 복잡도의 수행성능.
원소를 밀어내지 않고 노드를 서로 연결하기만 하면 되기 때문.
또한, 노드 기반 컨테이너의 삽입과 제거 동작은 반복자를 무효화시키지 않습니다.
반복자가 가리키는 원소 자체가 제거되지 않는 한 반복자가 가리키는 원소를 그대로 존재합니다.
하지만, 배열 기반 컨테이너의 반복자는 원소의 삽입과 제거 동작이 발생하면 메모리가 재할당되거나 원소가 
이동할 수 있으므로 반복자가 무효화됩니다.
6_33.cpp list의 insert()와 erase()
iter = lt.begin():iter는 lt의 시작 원소를 기리킵니다.
++iter:list는 양방향 반복자를 지원하므로 +,- 연산이 불가능하여 ++연산으로 30원소의 위치로 이동합니다.
iter2 = lt.erase(iter):iter가 가리키는 원소(노드)를 제거합니다. iter2는 다음 원소를 가리키는 반복자.
iter2 = lt.insert(iter, 300):iter가 가리키는 위치에 300을 삽입합니다. iter2는 삽입한 원소를 가리키는 반복자.
삽입하는 원소의 위치는 반복자가 가리키는 원소의 앞쪽입니다.
lt는 list컨테이너이므로 300을 삽입한 후에도 iter, iter2반복자 모두 유효(가리키는 원소가 없어지거나
바뀌지 않습니다)합니다.
lt
                        iter                                  30제거 후
                          ↓                                  ---------->
|N| 10 ||→ ←|| 20 ||→ ←|| 30 ||→ ←|| 40 ||→ ←|| 50 |N|
						           iter2                      300삽입 후
						             ↓                       ---------->
|N| 10 ||→ ←|| 20 ||→            ←|| 40 ||→ ←|| 50 |N|
						 iter2	   iter                      
						   ↓     	 ↓                       
|N| 10 ||→ ←|| 20 ||→ ←|| 300||→ ←|| 40 ||→ ←|| 50 |N|
6_34.cpp list와 vector의 insert()
viter = v.insert(viter, 600):viter가 가리키는 위치에 600을 삽입하고 삽입한 원소의 반복자를 viter에 대입
liter = lt.insert(liter, 600):liter가 가리키는 위치에 600을 삽입하고 삽입한 원소의 반복자를 liter에 대입
v에 600을 삽입하면 다음 원소부터 모두 뒤로 밀려나며 할당된 메모리 공간이 부족하면 메모리 재할당이 발생합니다.
하지만, lt는 원소(노드) 하나만을 삽입하므로 속다가 빠르며 반복자들이 무효화되지 않습니다.
또한, erase()함수의 동작도 '삽입' 동작과 같은 특징을 보입니다.
v
| 10| 20| 30| 40| 50|
      ↑ 
     viter
| 10|600| 20| 30| 40| 50| 메모리 재할당될 수 있음
	  ↑   하나씩 밀려남
     viter:insert()함수의 반환 반복자
lt
|N| 10||→ ←|| 20||→ ←|| 30||→ ←|| 40||→ ←|| 50|N|
              ↑
			liter
|N| 10||→ ←||600||→ ←|| 20||→ ←|| 30||→ ←|| 40||→ ←|| 50|N|
			  ↑  밀려나지 않고 node 삽입만
			liter:insert() 함수의 반환 반복자

list는 반복자를 이용해 원소를 제거하는 erase()말고도 원소의 값으로 원소를 제거하는 remove()멤버함수가 있다.
remove()멤버 함수는 컨테이너의 모든 원소를 순차적으로 검색하며 해당 원소를 제거합니다.
6_35.cpp list의 remove()
lt.remove(10):10원소의 모든 노드를 제거합니다.
list의 remove()는 erase()처럼 해당 값의 노드만을 제거하므로 속도가 빠르며 유일하게 list만이 remove()멤버 함수를
가지므로 반복자가 아닌 원소의 값으로 컨테이너의 원소를 제거해야 한다면 list컨테이너를 선택하는 것이 좋습니다.
조건자를 이용해 원소를 제거해야 한다면 remove_if()버전의 멤버 함수를 사용합니다.
remove_if()멤버 함수는 단항 조건자(predicate)가 참인 모든 원소를 제거합니다.
조건자는 bool 형식을 반환하는 함수류(함수, 함수 객체, 함수 포인터)입니다.
6_36.cpp list의 remove_if()
lt.remove_if(Predicate):단항 조건자가 참인 모든 원소(10<=x<=30)을 제거합니다.

순서가 있는 노드 기반 컨테이너 list는 이런 특징을 잘 반영하듯 splice()라는 멤버 함수를 가집니다.
splice()는 다른 list 컨테이너의 순차열을 잘라붙일 수 있습니다.
6_37.cpp list의 splice()
lt1.splice(iter, lt2):lt2의 모든 원소를 iter가 가리키는 lt1에 잘라붙입니다.
splice() 동작은 상수 시간의 실행 동작을 보입니다.
lt1과 lt2의 노드들을 단지 연결하기 때문.
lt1                                                 lt2
|N| 10||→ ←|| 20||→ ←|| 30||→ ←|| 40||→ ←|| 50|N|   |N|100||→ ←||200||→ ←||300||→ ←||400||→ ←||500|N|
			            ↑
			          liter
lt1                                                                                                  lt2
|N| 10||→ ←|| 20||→ ←||100||→ ←||200||→ ←||300||→ ←||400||→ ←||500||→ ←|| 30||→ ←|| 40||→ ←|| 50|N|  (없음)
						                                                  ↑
					                                                    liter
반복자를 이용해 가리키는 원소의 노드만을 잘라붙이거나 반복자 하나의 순차열을 잘라붙이고자 한다면
다른 버전의 splice() 멤버 함수를 사용할 수 있습니다.
6_38.cpp list의 splice() 다른 버전
lt1.splice(iter1, lt2, iter2):iter1(30)이 가리키는 위치에 iter2가 가리키는 원소(200)을 잘라붙입니다.
lt1.splice(lt1.end(), lt2, lt2.begin(), lt2.end()):lt1.end()가 가리키는 위치에 구간 [lt2.begin(), lt2.end())의
순차열을 잘라붙입니다.

만약 모든 원소의 순차열을 반대로 뒤집어야 한다면 list의 reverse()멤버 함수를 사용합니다.
reverse()는 이중 연결 리스트의 탐색 경로를 서로 바꿈으로써 순차열을 리버스시킵니다.
6_39.cpp list의 reverse()
reverse()후에 모든 원소는 뒤집어 출력됩니다.

원소를 중복되지 않게 하나씩만 남기고 싶다면 unique()멤버 함수를 사용합니다.
주의할 점은 unique()멤버 함수는 인접한 원소를 하나만 남기므로 연속하지 않는 원소는 중복될 수 있습니다.
6_40.cpp list의 unique()
lt.unique():인접한 같은 원소를 유일하게 만듭니다.
lt
┌──같은 값 인접──┐         ┌───────같은 값 인접───────┐   
|N|10||→ ←||10||→ ←||20||→ ←||30||→ ←||30||→ ←||30||→ ←||40||→ ←||50||→ ←||10|N|
unique()실행 후
|N|10||→ ←||20||→ ←||30||→ ←||40||→ ←||50||→ ←||10|N|
unique()멤버 함수로 모든 원소를 유일하게 만들고자 한다면 원소를 정렬한 후 unique()를 수행하면 됩니다.
또한, list는 조건자 버전의 unique()멤버 함수도 제공합니다.
이항 조건자를 인자로 받는 이 버전의 함수는 연속한 두 원소를 인자로 받아 조건자가 참이면 원소를 제거합니다.
6_41.cpp list의 조건자 버전 unique()
lt.unique(Predicate):이항 조건자가 참이면 원소를 제거합니다.
second(다음 원소) - first(현재 원소) <= 0이면 조건자는 참을 반환하고 다음 원소를 제거합니다.
lt
Predicate:두 원소의 차가 0보다 작거나 같으면 true
    ┌─ true─┐┌─false─┐┌─false─┐┌─ true─┐┌─ true─┐┌─false─┐┌─false─┐┌─ true─┐
|N|10||→ ←||10||→ ←||20||→ ←||30||→ ←||30||→ ←||30||→ ←||40||→ ←||50||→ ←||10|N|
unique(Predicate)실행 후
|N|10||→ ←||20||→ ←||30||→ ←||40||→ ←||50|N|

list는 정렬을 위한 멤버 함수 sort()를 제공합니다.
정렬을 수행할 수 있는 컨테이너는 시퀀스 컨테이너입니다.
연관 컨테이너는 자체 정렬 기준에 의해 자동정렬됩니다.
시퀀스 컨테이너 중 vector와 deque는 sort()알고리즘을 사용하여 빠르게 정렬할 수 있지만,
list는 sort()알고리즘을 수행할 수 없습니다.
sort()알고리즘은 임의 접근 반복자(대부분 quick sort)를 지원하는 컨테이너만 사용할 수 있기 때문.
그래서 list는 자체 정렬 멤버 함수 sort()를 제공합니다.
6_42.cpp list의 sort()
lt.sort():lt의 모든 원소를 오름차순 정렬합니다.
정렬의 기준은 오름차순으로 < 연산한 결과입니다.
비교 대상인 두 원소를 < 연산하여 정렬을 수행합니다.
< 연산자는 less 조건자의 연산 결과와 같습니다.
sort()의 조건자 버전을 사용하면 정렬 기준을 바꿀 수 있습니다.
sort()는 이항 조건자를 사용하며 이항 조건자가 참이면 두 원소(left,right)를 바꾸지 않고 거짓이면 바꿔가며 정렬.
6_43.cpp list의 조건자 버전 sort()
lt.sort(greater<int>()):greater<int>()조건자를 이용해 lt의 원소를 정렬합니다.
lt.sort(less<int>()):less<int>()조건자를 이용해 lt의 원소를 정렬합니다.
lt.sort(Greater()):Greater() 조건자(사용자 정의 조건자)를 이용해 lt의 원소를 정렬합니다.
사용자 정의 조건자를 사용하면 다양한 원소의 정렬 기준을 만들고 정렬할 수 있습니다.
greater나 less 조건자는 <functional>헤더에 들어있지만 일반적으로 컨테이너 헤더에서 포함하므로 생략했다.

두 list를 합병해야 한다면 merge()멤버 함수를 사용합니다.
주의할 점은 합병은 정렬된 두 list를 하나의 정렬된 list로 합병하므로 합병할 두 list는 정렬되어 있어야 합니다.
slice()와 비교하여 알아두면 좋습니다.
6_44.cpp list의 merge()
lt1에 lt2를 합병해 정렬합니다.
lt의 원소는 합병되어 사라집니다.
merge()멤버 함수는 lt1과 lt2가 오름차순 정렬되어 있다는 가정하에 동작하며 결과도 오름차순 정렬됩니다.
lt1                                           lt2
|N|10||→ ←||20||→ ←||30||→ ←||40||→ ←||50|N|  |N|25||→ ←||35||→ ←||60|N|
merge()
lt1                                                                       lt2
|N|10||→ ←||20||→ ←||25||→ ←||30||→ ←||35||→ ←||40||→ ←||50||→ ←||60|N|   (없음)
list가 다른 정렬 기준을 사용하고 있다면 조건자 버전 merge()멤버 함수를 사용하여 합병해야 합니다.
만약 정렬 기준이 틀렸거나 합병할 list가 정렬돼 있지 않았다면 merge()멤버 함수는 실패하며 오류가 발생합니다.
6_45.cpp
lt1.merge(lt2, greater<int>()):lt1과 lt2가 내림차순으로 정렬돼 있으므로 정렬 기준을 greater로 지정.
lt1과 lt2를 합병 정렬할 때 정렬 기준을 lt1과 lt2와 같게 지정하지 않으면 오류가 발생합니다.

list의 주요 특징 정리
list는 시퀀스 컨테이너이며 노드 기반 컨테이너입니다.
그래서 순차열 중간에 삽입, 제거가 빈번하게 발생하며 원소의 상대적인 순서가 중요하다면 list컨테이너를 사용합니다.
list
									insert():삽입
									erase():제거
					   front():참조    ↕                   back():참조
push_front():추가 ↔ ... ←||    ||→ ←||    ||→ ←||    ||→ ←||    ||→ ... ↔ push_back():추가
pop_front():제거                             ↑                            pop_back():제거
                                        splice():잘라붙이기
										merge():합병 정렬
										unique():중복 원소 제거
										sort():정렬
										remove():원소 제거(값)
list는 이중 연결 리스트 구조로 원소를 앞, 뒤에 모두 추가할 수 있는 push_front(), pop_front(),
push_back(), pop_back()함수를 제공합니다.
또한 시퀀스 컨테이너이므로 가장 첫 원소와 마지막 원소의 참조를 반환하는 front()와 back()멤버 함수를 제공.
노드 기반 컨테이너이므로 []연산자나 at()멤버 함수는 제공하지 않습니다.
노드 기반이므로 insert()나 erase()는 배열 기반보다 효율적으로 동작하며 값의 비교로 원소를 제거하는
remove()와 remove_if()를 제공합니다.
또한 list는 다른 list와 결합할 때 좋은 컨테이너입니다.
splice()멤버 함수는 노드의 연결 연산만(상수 시간)으로 두 list를 하나의 리스트로 결합할 수 있으며,
merge()멤버 함수는 두 list를 하나의 list로 정렬하며 결합합니다.
또한, 다양한 기능을 수행하는 reverse(), sort(), unique() 등의 멤버 함수도 제공합니다.
list는 양방향 반복자를 지원합니다.
멤버 함수 begin(), end(), rbegin(), rend()는 순차열의 시작과 끝을 가리키는 반복자를 반환합니다.

*/