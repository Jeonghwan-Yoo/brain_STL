/*
연관 컨테이너는 특정 정렬 규칙에 따라 저장 원소가 컨테이너에 정렬됩니다.
STL의 표준 연관 컨테이너는 set, map, multiset, multimap이 있으며 균형 이전 트리로 구현됩니다.

01 set 컨테이너
연관 컨테이너 중 단순한 컨테이너로 key라 불리는 원소(value)의 집합으로 이뤄진 컨테이너입니다.
모든 연관 컨테이너는 노드 기반 컨테이너이며 균형 이전 트리로 구현되므로 균형 이진 트리의 모든 특징을 가진다.

set의 주요 인터페이스와 특징
시퀀스 컨테이너와 달리 모든 연관 컨테이너는 같은 인터페이스(생성자, 멤버함수, 연산자)를 제공한다.
1)set의 템플릿 형식
템플릿 형식
template<
	typename Key, 
	typename Pred = less<Key>,
	typename Allocator = allocator<Key>
> //Key는 set컨테이너 원소의 형식이며, Pred는 set의 정렬 기준인 조건자이다. 기본 조건자는 less이다.
class set

2)set의 인터페이스
생성자
set s                    //s는 빈 컨테이너이다.
set s(pred)              //s는 빈 컨테이너로 정렬 기준은 pred 조건자 사용한다.
set s(s2)                //s는 s2 컨테이너의 복사본이다(복사 생성자 호출).
set s(b, e)              //s는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.
set s(b, e, pred)        //s는 반복자 구간 [b,e)로 초기화된 원소를 갖는다. 정렬 기준은 pred 조건자를 사용한다.

멤버 함수
p = s.begin()            //p는 s의 첫 원소를 가리키는 반복자(const, 비const버전이 있음)
s.clear()                //s의 모든 원소를 제거한다.
n = s.count(k)           //원소 k의 개수를 반환한다.
s.empty()                //s가 비었는지 조사한다.
p = s.end()              //p는 s의 끝을 표식하는 반복자다(const, 비const버전이 있음)
pr = s.equal_range(k)    //pr는 k원소의 반복자 구간인 pair객체다. (const, 비const버전이 있음)
q = s.erase(p)           //p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
q = s.erase(b, e)        //반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소.
n = s.erase(k)           //k 원소를 모두 제거한다. n은 제거한 개수다.
p = s.find(k)            //p는 k 원소의 위치를 가리키는 반복자다(const, 비const버전이 있음)
pr = s.insert(k)         //s컨테이너에 k를 삽입한다. pr은 삽입한 원소를 가라키는 반복자와 성공여부 bool값인 pair.
q = s.insert(p, k)       //p가 가리키는 위치부터 빠르게 k를 삽입한다. q는 삽입한 원소를 가리키는 반복자다.
s.insert(b, e)           //반복자 구간 [b, e)의 원소를 삽입한다.
pred = s.key_comp()      //pred는 s의 key정렬 기준인 조건자다(key_compare타입)
p = s.lower_bound(k)     //p는 k의 시작 구간을 가리키는 반복자다(const, 비const버전이 있음)
n = s.max_size()         //n는 s가 담을 수 있는 최대 원소의 개수다(메모리의 크기).
p = s.rbegin()           //p는 s의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비const버전이 있음)
p = s.rend()             //p는 s의 역 순차열의 끝을 표식하는 반복자(const, 비const버전이 있음)
s.size()                 //s원소의 개수다.
s.swap(s2)               //s와 s2를 swap한다.
p = s.upper_bound(k)     //p는 k의 끝 구간을 가리키는 반복자다(const, 비const버전이 있음)
pred = s.value_comp()    //pred는 s의 value정렬 기준인 조건자다(value_compare타입)

연산자
s1 == s2                 //s1과 s2의 모든 원소가 같은가?(bool형식)
s1 != s2                 //s1과 s2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool형식)
s1 < s2				     //문자열 비교처럼 s2가 s1보다 큰가?(bool형식)
s1 <= s2			     //문자열 비교처럼 s2가 s1보다 크거나 같은가?(bool형식)
s1 > s2					 //문자열 비교처럼 s1이 s2보다 큰가?(bool형식)
s1 >= s2				 //문자열 비교처럼 s1이 s2보다 크거나 같은가?(bool형식)

3)set의 템플릿 멤버 형식
멤버 형식
allocator_type           //메모리 관리자 형식
const_iterator           //const 반복자 형식
const_pointer            //const value_type* 형식
const_reference          //const value_type& 형식
const_reverse_iterator   //const 역 반복자 형식
difference_type          //두 반복자 차이의 형식
iterator                 //반복자 형식
key_compare              //키(key) 조건자(비교) 형식(set은 key가 value이므로 value_compare와 같음)
key_type                 //키(key)의 형식(set은 key가 value이므로 value_type과 같음)
pointer                  //value_type* 형식
reference                //value_type& 형식
reverse_iterator         //역 반복자 형식
size_type                //첨자(index)나 원소의 개수 등의 형식
value_compare            //원소 조건자(비교) 형식
value_type               //원소의 형식

set은 컨테이너에 원소(key)를 저장(삽입)하는 유일한 멤버 함수 insert()를 제공합니다.
연관 컨테이너는 정렬 기준이 있으므로 insert()에 의해 삽입된 원소는 자동 정렬됩니다.
set에서 원소(10,30..)를 key라고 하며 키를 비교하여 내부 원소를 정렬합니다.
set은 모든(key)가 유일합니다.
원소의 중복을 허용해야 한다면 multiset을 사용해야 합니다.
set
기본 정렬 기준:less
       |  |50|  |
       ↙         ↘        ← insert():삽입
   ||30||      ||80||
   ↙    ↘      ↙    ↘
||10||||40||||70||||90||
연관 컨테이너는 특정 정렬 기준(조건자)에 따라 원소를 자동 정렬하는 컨테이너입니다.
정렬 기준은 템플릿 매개변수에 지정할 수 있으며, 기본 정렬 기준은 less조건자 입니다.
순서와 관련된 함수류인 push_back(), push_front(), pop_back(), pop_front()와 시작과 끝인 front(), back()이 없다.
연관 컨테이너는 균형 이진 트리를 사요하므로 찾기 연산(find(), lower_bound(), upper_bound(), equal_range(),
count())에 뛰어난 성능(로그 시간)을 보이며 insert()멤버 함수를 이용한 삽입도 로그 시간 복잡도를 보입니다.
7_1.cpp set의 insert()
s.insert(k):k를 s에 삽입합니다.
s는 자동 정렬되며 정렬 기준으로 less를 사용합니다.
less는 <연산의 결과로 모든 노드의 부모 노드는 왼쪽 자식 노드보다 크고 오른쪽 자식 노드보다 작습니다.
반복자의 탐색 순서는 inorder이진 트리 탐색을 사용합니다.
50이 이미 s에 있으므로 insert(50)은 모두 실패합니다.
s
기본 정렬 기준:less                     s.begin()            s.end()
	   |  |50|  |                        ↓                    ↓
	   ↙         ↘                       10 30 40 50 70 80 90 N
   ||30||      ||80||                    --------------------> 탐색 순서
   ↙    ↘      ↙    ↘
||10||||40||||70||||90||
set은 같은 원소(key)를 중복 저장할 수 없으므로 insert()멤버 함수 호출 시 반환값으로 실패를 확인할 수 있다.
반환값을 pair객체이며 first와 second는 각각 삽입된 원소(key)의 위치를 가리키는 반복자와 성공여부 bool값.
7_2.cpp insert()의 반환값(pair 객체)
pr = s.insert(50):50을 s에 삽입하고 결과를 pr에 저장합니다.
pr.first는 50원소를 가리키는 반복자이며 pr.second는 삽입성공, 삽입실패 결과입니다.
성공이면 pr.first는 삽입한 원소(50)를 가리키는 반복자이며, 실패면 이미 삽입된 원소를 가리키는 반복자.
실패했을 때 결과는
pr    first second
        ↓   false
s    40 50 80 N

연관 컨테이너는 삽입할 위치(반복자)를 지정하는 버전과 삽입할 구간(반복자쌍)을 지정하는 버전의 insert()도 제공.
단, 원소(key)의 삽입 위치를 지정하는 버전은 삽입 탐색을 시작할 위치로 삽입위치가 정렬 순서와 맞다면 바로 삽입되지만
아니라면 로그 시간이 걸립니다.
반복자로 탐색 시작 위치를 지정하면 빠르게 원소를 삽입할 수 있다.
7_3.cpp set의 탐색 위치 지정 insert()
s.insert(pr.first, 85):pr.first가 가리키는 위치부터 탐색을 시작하여 85를 삽입합니다.

기본 정렬 기준은 조건자 less를 사용하지만 템플릿 매개변수를 사용해 바꿀 수 있습니다.
7_4.cpp 정렬 기준 greater를 사용한 set
set<int, greater<int>> s:정렬 기준은 greater조건자를 사용하고 int형 원소를 저장하는 컨테이너 s입니다.
greater조건자는 >연산의 결과로 모든 노드의 부모 노드가 왼쪽 자식 노드보다 작고 오른쪽 자식 노드보다 큰 노드.
s
기본 정렬 기준:greater                  s.begin()            s.end()
	   |  |50|  |                        ↓                    ↓
	   ↙         ↘                       90 80 70 50 40 30 10 N
   ||80||      ||30||                    --------------------> 탐색 순서
   ↙    ↘      ↙    ↘
||90||||70||||40||||10||

set은 사용 중인 정렬 기준 조건자를 반환하는 멤버 함수 key_comp()와 value_comp()를 제공합니다.
정렬 기준 형식은 typedef내장 멤버 형식 key_compare와 value_compare로 제공합니다.
set은 저장 원소인 값(value)이 곧 비교로 사용되는 키(key)가 되며 set은 value와 key타입이 같습니다.
7_5.cpp set의 key_comp(), value_comp()멤버 함수
set<int, less<int>> s_less:명시적으로 less 조건자를 정렬 기준으로 한 s_less컨테이너를 생성.
set<int, greater<int>> s_greater:greater조건자를 정렬 기준으로 한 s_greater컨테이너를 생성합니다.
l_cmp(10, 20):10 < 20의 bool값을 반환합니다.
g_cmp(10, 20):10 > 20의 bool값을 반환합니다.
typeid(s_less.key_comp()).name():s_less.key_comp()타입을 문자열로 반환합니다.
typeid(s_less.value_comp()).name():s_less.value_comp()타입을 문자열로 반환합니다.
set은 원소가 key이므로 key_compare와 value_compare 두 타입이 같습니다.
필요하다면 사용자가 직접 조건자를 만들어 set의 정렬 기준으로 사용할 수 있습니다.

연관 컨테이너는 모두 같은 인터페이스의 멤버 함수를 제공합니다.
핵심 인터페이스는 찾기 관련 멤버 함수입니다.
찾기 관련 멤버 함수는 정렬기준으로 트리의 루트 노드부터 자식 노드로 검색을 진행하므로 로그 시간 복잡도에
실행되며 count(), find(), lower_bound(), upper_bound(), equal_range()멤버 함수입니다.
원소의 중복을 허용하지 않는 set컨테이너는 원소의 개수를 반환하는 count()멤버 함수는 굳이 필요는 없다.
7_6.cpp set의 count()
s.count(50)은 50원소가 s에 있으므로 1을 반환하고 s.count(100)은 100이 s에 없으므로 0을 반환.
실행 시간은 로그 시간 복잡도입니다.

find()는 key(원소)를 검색하여 key를 가리키는 반복자를 반환합니다.
만약 key(원소)가 없으면 끝 표시(past-the-end) 반복자를 반환합니다.
end()멤버 함수가 끝 표시 반복자를 반환하므로 end()멤버 함수와 비교해 검색의 성공여부를 판단합니다.
7_7.cpp set의 find()
s.find(30):key(30)의 반복자를 반환, 30이 없으면 s.end()와 같은 반복자(끝 표시 반복자)를 반환합니다.
iter != s.end():iter가 s.end()와 같으면 key가 없으며 같지 않다면 iter는 key를 가리키는 반복자입니다.
s
기본 정렬 기준:less                         iter            s.end()
   iter | | 50| |                           ↓                 ↓
	 ↓ ↙         ↘                       10 30 40 50 70 80 90 N
   ||30||      ||80||                    --------------------> 탐색 순서
   ↙    ↘      ↙    ↘
||10||||40||||70||||90||            !(*iter < 30) && !(30 < *iter)이 true이므로 찾음!
주의할 점은 연관 컨테이너의 찾기 관련 멤버 함수는 key(원소)를 찾을 때 ==연산을 사용하지 않습니다.
연관 컨테이너는 정렬 기준에 의해 key(원소)가 정렬되어 있으므로 컨테이너의 정렬 기준 조건자를 이용해 찾기 연산.
set의 정렬기준이 less라면 <연산을 수행하므로 비교하는 두 원소 a와 b가 !(a<b) && !(b<a)라면 두 원소는
같다(equivalence)라고 판단합니다.

s컨테이너의 정렬 기준을 반환하는 멤버 함수가 key_comp()이므로 비교하는 두 원소 a와 b가
!s.key_comp()(a,b) && !s.key_comp()(b,a)이면 두 원소는 같습니다.
즉 정렬 기준으로 a가 b보다 앞서 있지 않고 b도 a보다 앞서 있지 않다면 a와 b는 같다고 판단.
7_8.cpp
(!s.key_comp()(30,50) && !s.key_comp()(50,30)):30이 50보다 크지않고 50도 30보다 크지 않은가? false
(!s.key_comp()(30,30) && !s.key_comp()(30,30)):30이 30보다 크지않고 30도 30보다 크지 않은가? true

set의 멤버 함수 lower_bound()와 upper_bound()는 찾은 key(원소)를 순차열 구간(반복자쌍)으로 반환하는 멤버 함수.
lower_bound()는 찾은 원소의 시작 반복자를 반환하며 upper_bound()는 찾은 원소의 다음 원소를 가리키는 반복자.
그래서 찾은 원소는 [lower_bound(), upper_bound())로 표현할 수 있으며 두 반복자가 같다면 찾는 원소는 없습니다.
중복 key를 갖지 않는 set에서 두 멤버 함수는 큰 의미는 없지만 multi에서는 유용하게 사용됩니다.
7_9.cpp set의 lower_bound(), upper_bound()
iter_lower = s.lower_bound(30):iter_lower라는 30이 시작하는 구간의 반복자입니다.
iter_upper = s.upper_bound(30):iter_lower라는 30이 끝나는 구간의 반복자입니다.
iter_lower != iter_upper:구간 [iter_lower, iter_upper)에서 두 반복자가 같다면 찾는 원소가 없습니다.
     iter_lower iter_upper
         ↓       ↓
||10|| ||30|| ||40|| ||50|| ||70|| ||80|| ||90|| ||N||
         ↑       ↑ -------------> 탐색 순서
lower_bound()  upper_bound()
[iter_lower, iter_upper)의 순차열:30

equal_range()는 lower_bound()와 upper_bound()의 반복자 쌍을 pair 객체로 반환합니다.
7_10.cpp set의 equal_range()
pair<set<int>::iterator, set<int>::iterator> iter_pair:set의 반복자 쌍을 표현하는 iter_pair객체 생성.
iter_pair = s.equal_range(30):30원소의 구간(반복자 쌍)을 반환하여 iter_pair객체에 대입.
            iter_pair
          first   second
	   	    ↓       ↓
s  ||10|| ||30|| ||40|| ||50|| ||70|| ||80|| ||90|| ||N||
		    ↑       ↑ -------------> 탐색 순서
   lower_bound()  upper_bound()
[iter_lower, iter_upper)의 순차열:30

set의 주요 특징 정리
set은 대표적인 연관 컨테이너이자 노드 기반 컨테이너입니다.
연관 컨테이너는 특정 정렬 기준에 의해 원소가 자동 정렬되는 컨테이너입니다.
또한, 원소 찾기(검색)를 로그 시간 복잡도에 수행할 수 있도록 균형 이진 트리로 구현되며 여러 찾기 관련 함수를
제공하는 것이 특징입니다.
set
기본 정렬 기준:less
	   |  |50|  |
	   ↙         ↘        ↔ insert():삽입
   ||30||      ||80||       erase():제거
   ↙    ↘      ↙    ↘
||10||||40||||70||||90||  ← count():원소 개수
                            find():원소 찾기
							lower_bound():원소의 시작 구간
							upper_bound():원소의 끝 구간
							equal_range():원소의 구간
연관 컨테이너의 핵심은 빠른 원소 찾기이며 균형 이진 트리를 이용한 로그 시간 검색 복잡도를 보장합니다.
찾기 관련 멤버 함수는 count(), find(), lower_bound(), upper_bound(), equal_range()가 있으며
원소를 저장하기 위해 사용되는 멤버 함수는 insert()가 유일합니다.
set은 key라 불리는 원소를 정렬 기준에 맞춰 균형 이진 트리에 저장(insert)하며,
이 key(원소)가 연관 컨테이너 set을 구성하는 핵심 요소로, 삽입, 검색, 제거 등에 모두 이용됩니다.
그래서 set뿐만 아니라 모든 연관 컨테이너의 key는 변경할 수 없습니다.
연관 컨테이너는 양방향 반복자를 지원하며 begin(), end(), rbegin(), rend()는 순차열의 시작과 끝을 가리키는
반환자를 반환합니다.

02 multiset 컨테이너
multiset 컨테이너는 중복 원소를 컨테이너에 저장할 수 있다는 것 외에는 set과 다를 것이 없습니다.
set처럼 원소가 자동 정렬되는 연관 컨테이너에 노드 기반 컨테이너입니다.

multiset의 주요 인터페이스와 특징
템플릿 형식, 주요 인터페이스, 멤버의 형식이 모두 set과 같습니다.
multiset
기본 정렬 기준:less
	    | | 50| |
	   ↙         ↘        ← insert():삽입
   ||30||      ||80||
   ↙    ↘      ↙    ↘
||10||||30||||60||||80||
multiset의 insert()는 key(원소)가 중복 저장될 수 있기 때문에 set처럼 저장 위치와 삽입 성공 여부의
bool값을 반환하는 pair객체가 아닌 저장된 위치만을 가리키는 반복자를 반환합니다.
7_11.cpp multiset의 insert()
50원소와 80원소가 중복 저장되며 insert()는 저장한 원소의 위치를 가리키는 반복자입니다.
ms
기본 정렬 기준:less                    ms.begin()           ms.end()
	    | | 50| |                        ↓                    ↓
	   ↙         ↘                       10 30 30 50 70 80 80 N
   ||30||      ||80||                    ↑  ------------> 탐색 순서
   ↙    ↘      ↙    ↘                   iter
||10||||30||||60||||80||

multiset은 count(), find(), lower_bound(), upper_bound(), equal_range() 멤버 함수를 제공.
이 멤버 함수들은 중복 원소를 찾는데 유용하게 사용됩니다.
7_12.cpp multiset의 찾기 관련 함수
ms.find(30)은 첫 번째 30원소의 반복자를 반환합니다.
ms.count(30)은 30원소의 개수를 반환하며 lower_iter와 upper_iter는 각각 30 원소의 시작 반복자와
끝 반복자로 30 원소의 순차열 [lower_iter, upper_iter)입니다.
		    iter
			 ↓       
ms  ||10|| ||30|| ||30|| ||50|| ||70|| ||80|| ||80|| ||N||
			 ↑             ↑         -------------> 탐색 순서
       lower_iter      upper_iter
[lower_iter, upper_iter)의 순차열:30, 30

equal_range()멤버 함수는 원소의 구간을 pair객체로 반환합니다.
lower_bound()와 upper_bound()가 반환하는 반복자 쌍입니다.
7_13.cpp multiset의 equal_range()
equal_range()는 찾은 원소의 시작 반복자와 끝 반복자 쌍을 반환합니다.
iter_pair.first와 iter_pair.second가 같다면 찾는 원소는 없습니다.
                iter_pair
           first         second
			 ↓             ↓
ms  ||10|| ||30|| ||30|| ||50|| ||70|| ||80|| ||80|| ||N||
	      ---------------------------------------> 탐색 순서
[iter_pair.first, iter_pair.second)의 순차열:30, 30
multiset은 중복 원소를 허용한다는 것 외에 set과 특징이 같다.

03 map 컨테이너
자주 사용하는 컨테이너로 원소를 key와 value의 쌍으로 저장합니다.
set은 원소로 key하나만을 저장하지만, map은 원소로 key와 value의 쌍(pair 객체)을 저장합니다.
원소의 key는 컨테이너에 중복 저장될 수 없으면 중복 key를 저장해야 한다면 multimap을 사용.

map의 주요 인터페이스와 특징
set과 같은 인터페이스 멤버 함수를 제공하며 템플릿 형식과 내장 멤버 형식만 조금 다르다.
map은 []연산자를 제공하여 key에 해당하는 원소의 value에 쉽게 접근하거나 변경할 수 있습니다.
1)map의 템플릿 형식
템플릿 형식
template<
	typename Key,
	typename Value,
	typename Pred = less<Key>,
	typename Allocator = allocator<pair<const key, Value>>
> //Key와 value는 map컨테이너 원소의 key와 value의 형식. Pred는 map의 정렬 기준인 조건자. 기본 조건자는 less이다.
class map

2)map의 인터페이스
생성자
map m                    //m는 빈 컨테이너이다.
map m(pred)              //m는 빈 컨테이너로 정렬 기준은 pred 조건자 사용한다.
map m(m2)                //m는 m2 컨테이너의 복사본이다(복사 생성자 호출).
map m(b, e)              //m는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.
map m(b, e, pred)        //m는 반복자 구간 [b,e)로 초기화된 원소를 갖는다. 정렬 기준은 pred 조건자를 사용한다.

멤버 함수
p = m.begin()            //p는 m의 첫 원소를 가리키는 반복자(const, 비const버전이 있음)
m.clear()                //m의 모든 원소를 제거한다.
n = m.count(k)           //원소 k의 개수를 반환한다.
m.empty()                //m가 비었는지 조사한다.
p = m.end()              //p는 m의 끝을 표식하는 반복자다(const, 비const버전이 있음)
pr = m.equal_range(k)    //pr는 k원소의 반복자 구간인 pair객체다. (const, 비const버전이 있음)
q = m.erase(p)           //p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
q = m.erase(b, e)        //반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소.
n = m.erase(k)           //k 원소를 모두 제거한다. n은 제거한 개수다.
p = m.find(k)            //p는 k 원소의 위치를 가리키는 반복자다(const, 비const버전이 있음)
pr = m.insert(k)         //m컨테이너에 k를 삽입한다. pr은 삽입한 원소를 가라키는 반복자와 성공여부 bool값인 pair.
q = m.insert(p, k)       //p가 가리키는 위치부터 빠르게 k를 삽입한다. q는 삽입한 원소를 가리키는 반복자다.
m.insert(b, e)           //반복자 구간 [b, e)의 원소를 삽입한다.
pred = m.key_comp()      //pred는 m의 key정렬 기준인 조건자다(key_compare타입)
p = m.lower_bound(k)     //p는 k의 시작 구간을 가리키는 반복자다(const, 비const버전이 있음)
n = m.max_size()         //n는 m가 담을 수 있는 최대 원소의 개수다(메모리의 크기).
p = m.rbegin()           //p는 m의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비const버전이 있음)
p = m.rend()             //p는 m의 역 순차열의 끝을 표식하는 반복자(const, 비const버전이 있음)
m.size()                 //m원소의 개수다.
m.swap(m2)               //m와 m2를 swap한다.
p = m.upper_bound(k)     //p는 k의 끝 구간을 가리키는 반복자다(const, 비const버전이 있음)
pred = m.value_comp()    //pred는 m의 value정렬 기준인 조건자다(value_compare타입)

연산자
m1 == m2                 //m1과 m2의 모든 원소가 같은가?(bool형식)
m1 != m2                 //m1과 m2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool형식)
m1 < m2				     //문자열 비교처럼 m2가 m1보다 큰가?(bool형식)
m1 <= m2			     //문자열 비교처럼 m2가 m1보다 크거나 같은가?(bool형식)
m1 > m2					 //문자열 비교처럼 m1이 m2보다 큰가?(bool형식)
m1 >= m2				 //문자열 비교처럼 m1이 m2보다 크거나 같은가?(bool형식)
m[k] = v                 //m 컨테이너에 원소(k, v)를 추가하거나 key에 해당하는 원소의 value를 v로 갱신.

3)map의 템플릿 멤버 형식
멤버 형식
allocator_type           //메모리 관리자 형식
const_iterator           //const 반복자 형식
const_pointer            //const value_type* 형식
const_reference          //const value_type& 형식
const_reverse_iterator   //const 역 반복자 형식
difference_type          //두 반복자 차이의 형식
iterator                 //반복자 형식
key_compare              //키(key) 조건자(비교) 형식(map은 key가 value이므로 value_compare와 같음)
key_type                 //키(key)의 형식(map은 key가 value이므로 value_type과 같음)
mapped_type              //값(value)의 형식
pointer                  //value_type* 형식
reference                //value_type& 형식
reverse_iterator         //역 반복자 형식
size_type                //첨자(index)나 원소의 개수 등의 형식
value_compare            //원소 조건자(비교) 형식
value_type               //원소의 형식
map은 set처럼 컨테이너에 원소(key, value의 쌍)을 삽입하는 유일한 멤버 함수 insert()를 제공.
기본 정렬 기준 less이며 컨테이너의 모든 key는 유일합니다.
원소의 중복을 허용해야 한다면 multimap을 사용해야 합니다.
map
기본 정렬 기준:less
              key value
		    | | 5|50| |
	        ↙         ↘        ← insert():삽입
     || 3|30||       || 8|80||
     ↙      ↘         ↙      ↘
|| 1|10||| 4|30|||| 7|60||| 9|80||
map의 원소는 pair객체로 저장되며 pair객체의 first멤버 변수는 key고 second멤버 변수는 value입니다.
원소를 저장하는 insert()멤버 함수는 pair객체를 인자로 받아 map의 원소인 key와 value의 쌍을 저장합니다.
map<int, int> m; //<key type, value type>
m.insert(pair<int, int>(5, 100)); //<key type, value type>(key, value)
7_14.cpp map의 insert()
map<int, int> m:기본 정렬 기준은 less를 사용하고 key와 value타입이 int인 컨테이너 m을 생성합니다.
m.insert(pair<int, int>(5, 100)):key 5와 value 100을 pair객체로 만들어 m컨테이너에 저장합니다.
pair<int, int> pr(9, 50):직접 pair 객체 pr을 생성합니다.
iter->first, iter->second:iter가 가리키는 원소가 멤버를 갖는다면 -> 연산자를 사용하여 멤버를 접근.
원소는 key와 value의 쌍으로 이루어진 pair 객체이며 컨테이너는 정렬 기준 less에 의해 key가 정렬돼 저장됩니다.
m
기본 정렬 기준:less
			  key value                                           pair
			| | 5|50| |               m.begin()          first(key)  second(value)                   m.end()
			↙         ↘                  ↓                        ↓   ↓                                 ↓                                                        
	 || 3|30||       || 8|80||       |  1| 70||  3|100||  4| 40||  5|100||  7|100||  8| 30||  9| 50||   |  N|
	 ↙      ↘         ↙      ↘                             ↑       ---------------> 탐색 순서   
|| 1|10||| 4|30|||| 7|60||| 9|80||                       iter
map의 insert()멤버 함수는 set처럼 저장한 원소의 위치를 가라키는 반복자와 삽입 성공 여부를 나타내는 bool과 
pair 객체로 반환합니다.
7_15.cpp map의 insert() 반환 값
pr = m.insert(pair<int, int>(9, 50)):pr.first는 저장 원소의 위치를 가리키는 반복자이며
pr.second는 저장 성공 여부의 bool값입니다.
key 9가 m에 없다면 pr.second는 true이며, 이미 존재한다면 false입니다.
             pr
        first  second(true)
          ↓ 
m ... |  9| 50|...
        ↑   ↑
     first  second

map은 []연산자를 사용하여 쉽게 원소(key, value)를 추가하거나 value 값을 갱신할 수 있습니다.
key에 해당하는 원소가 map에 없다면 추가 연산을 수행합니다.
key에 해당하는 원소가 있다면 key에 해당하는 원소의 value를 갱신하는 연산을 수행합니다.
map<int, int> m; //<key type, value type>
m[5] = 100; //m[key] = value으로 추가 or 갱신
7_16.cpp map의 []연산자
m[5] = 100:m에 key 5가 없으므로 원소(key:5, value:100)를 m에 추가합니다.
m[5] = 200:m에 key 5가 있으므로 원소(key:5, value:100)의 value를 200으로 갱신합니다.

map컨테이너의 기본 정렬 기준은 less입니다.
정렬 기준을 바꾸려면 템플릿 형식의 세 번째 인자를 이용합니다.
7_17.cpp map 컨테이너의 정렬 기준 조건자 greater
map<int, string, greater<int>> m:m은 정렬 기준 greater를 사용하고 int 타입 key와 string타입 value를
저장하는 컨테이너 입니다.
m[9]:key 9와 매핑된 value의 참조입니다.
[]연산자를 사용하여 key에 매핑된 value를 빠르게 찾을 수 있지만 map도 삽입, 제거, 찾기 관련 멤버 함수를 제공.
이 멤버 함수는 모두 로그 시간에 수행됩니다.
7_18.cpp map의 찾기 관련 멤버 함수
iter = m.find(5):key 5의 시작 반복자를 반환합니다.
lower_iter = m.lower_bound(5):key 5의 시작을 가리키는 반복자를 반환합니다. 순차열의 시작.
upper_iter = m.upper_bound(5):key 5의 다음 원소를 가리키는 반복자를 반환합니다. 순차열의 끝.
iter_pair = m.equal_range(5):key 5의 순차열 구간은 [iter_pair.first, iter_pair.second).
                                     iter_pair
      m.begin()                   first    second                     m.end()
         ↓                          ↓        ↓                          ↓
m    |  1| 70||  3|100||  4| 40||  5|100||  7|100||  8| 30||  9| 50||   |  N|
                                    ↑        ↑      --------------> 탐색 순서
                              lower_iter   upper_iter
구간 [lower_iter, upper_iter)의 순차열:(5, 100)
구간 [iter_pair.first, iter_pair.second)의 순차열:(5, 100)

map의 주요 특징 정리
map은 대표적인 연관 컨테이너이자 노드 기반 컨테이너입니다.
그래서 특정 정렬 기준으로 원소(key)가 자동 정렬되며 연관 컨테이너는 모두 같은 인터페이스의 멤버 함수를 제공합니다.
map의 원소는 key와 value의 쌍으로 이뤄집니다.
map
기본 정렬 기준:less
			  key value
			| | 5|50| |
			↙         ↘        ↔ insert():삽입
	 || 3|30||       || 8|80||   erase():제거
	 ↙      ↘         ↙      ↘
|| 1|10||| 4|30|||| 7|60||| 9|80||   ← []연산자 오버로딩 지원. m[key] = value:원소 추가 or 갱신
                                       찾기 관련 멤버 함수
map은 []연산자를 이용해 원소(key, value)를 추가하거나 key에 매핑된 value의 참조를 반환할 수 있습니다.
컨테이너 앞,뒤에 추가하거나 제거하는 멤버 함수가 없으며 front()와 back()멤버 함수도 제공하지 않습니다.
연관 컨테이너의 핵심은 빠른 원소 찾기(검색)이며 균형 이진 트리를 이용한 로그 시간 검색 복잡도를 보장합니다.
[]연산자를 사용해 원소를 추가할 수도 있지만, insert()멤버 함수로 원소를 추가할 수 있습니다.

04 multimap 컨테이너
map 컨테이너에 중복 원소(key)를 허용해야 한다면 multimap 컨테이너를 사용합니다.
multimap은 여러 key를 중복해서 저장할 수 있습니다.
이것이 map과 다른 유일한 차이점입니다.

multimap의 주요 인터페이스와 특징
map과 같은 인터페이스, 템플릿 형식, 내장 멤버 형식을 제공합니다.
하지만 []연산자를 제공하지 않습니다.
multimap
기본 정렬 기준:less
			     key value
			  | |  5|100| |
	       ↙                  ↘        ← insert():삽입
	 ||  3|100||          ||  8| 30||
	  ↙       ↘            ↙       ↘
||  1| 70|||  3| 40||||  7|100|||  8| 50||

7_20.cpp multimap의 count()와 find()
mm.count(3):key 3의 개수가 2개이므로 결과는 2입니다.
iter = mm.find(3):iter는 key 3의 첫 번째 반복자입니다. key 3이 없다면 iter는 mm.end()입니다.

multimap이 중복 키를 허용하므로 중복 키를 검색함수 lower_bound(), upper_bound(), equal_range()는
multimap에서 유용하게 사용됩니다.
7_21.cpp multimap의 lower_bound(), upper_bound(), equal_range()
lower_iter = mm.lower_bound(3):lower_iter는 key 3의 시작 반복자입니다.
upper_iter = mm.upper_bound(3):upper_iter는 key 3의 끝 반복자입니다.
iter_pair = mm.equal_range(3):iter_pair는 key 3의 순차열 구간([iter_pair.first, iter_pair.second))을
first와 second 멤버로 갖는 pair 객체입니다.
	                    iter_pair
	   mm.begin() first           second                             mm.end()
		  ↓        ↓                 ↓                                   ↓
mm    |  1| 70||  3|100||  3| 40||  5|100||  7|100||  8| 30||  8| 50||   |  N|
			       ↑                 ↑      --------------> 탐색 순서
               lower_iter        upper_iter
구간 [lower_iter, upper_iter)의 순차열:(3, 100)(3, 40)
구간 [iter_pair.first, iter_pair.second)의 순차열:(3, 100)(3, 40)
multimap은 중복 원소(key)를 허용한다는 것 외에 amp과 특징이 같다.
									
*/