/*
컨테이너 어댑터는 다른 컨테이너의 인터페이스를 변경한 컨테이너입니다.
STL에는 stack, queue, priority_queue 세 가지 컨테이너 어댑터가 있습니다.
stack은 LIFO(Last-In First-Out)방식의 컨테이너이며, queue는 FIFO(First-In First-Out)방식의 컨테이너.
priority_queue는 원소를 우선순위에 의해 관리되는 큐입니다.
priority_queue는 특정 정렬 기준으로 원소의 우선순위가 결정되며 기본 정렬 기준은 less(<)입니다.

01 stack 컨테이너
LIFO방식의 컨테이너를 구현한 템플릿 클래스입니다.
stack컨테이너에 설정된 기본 컨테이너는 deque 컨테이너입니다.

템플릿 형식
template<typename T, typename Container = deque<T>> //T는 원소의 형식이며, Container는 stack에서 사용될
                                                      컨테이너 형식이며, 기본 컨테이너는 deque<T>
class stack

멤버 형식
value_type                                     //Container::value_type으로 T형식이다.
size_type                                      //Container::size_type으로 첨자(index)나 원소 개수 등의 형식.
container_type                                 //Container형식이며, 기본 형식은 deque<T>이다.

생성자
explicit stack(const Container& = Container()) //컨테이너의 기본 생성자를 호출해 stack을 생성하거나 인자로 받아
                                                 stack을 생성한다.

멤버 함수
bool empty() const                             //원소가 없는가?
size_type size() const                         //원수의 개수다.
void push(const vlaue_type& x)                 //원소를 추가한다.
void pop()                                     //원소를 제거한다.
value_type& top()                              //Top원소를 참조한다.
const value_type& top() const                  //const객체 Top원소를 참조한다.

연산자
s1 == s2                                       //s1과 s2가 같은가?
s1 != s2                                       //s1과 s2가 다른가?
s1 < s2                                        //s1보다 s2가 큰가?
s1 <= s2                                       //s1보다 s2가 크거나 같은가?
s1 > s2                                        //s2보다 s1이 큰가?
s1 >= s2                                       //s2보다 s1이 크거나 같은가?

stack의 Container템플릿 인자로 받는 컨테이너는 empty(), size(), push_back(), pop_back(), back() 등의
인터페이스를 제공해야 합니다.
그래서 stack의 Container는 vector, deque, list를 사용할 수 있으며, 이 인터페이스들을 지원한다면 사용자
컨테이너를 사용할 수 있습니다.
	    ↕top():참조
stack───────────────────────────────┐
│                                   │
│       ↕back()                     │
│deque────────┐                     │
│  │          │←push_back()         │←push():입력
│  │ |30|     │→pop_back()          │→pop():출력
│  │ |20|     │                     │
│  │ |10|     │                     │
│  └──────────┘                     │
└───────────────────────────────────┘
11_1.cpp stack 컨테이너
push()로 원소를 추가하고, top()으로 가장 늦게 저장된 원소를 참조하고 pop()으로 원소를 제거합니다.

02 queue 컨테이너
FIFO방식의 컨테이너를 구현한 템플릿 클래스입니다.
queue컨테이너에 설정된 기본 컨테이너는 deque 컨테이너입니다.

템플릿 형식
template<typename T, typename Container = deque<T>> //T는 원소의 형식이며, Container는 queue에서 사용될
													  컨테이너 형식이며, 기본 컨테이너는 deque<T>
class queue

멤버 형식
value_type                                     //Container::value_type으로 T형식이다.
size_type                                      //Container::size_type으로 첨자(index)나 원소 개수 등의 형식.
container_type                                 //Container형식이며, 기본 형식은 deque<T>이다.

생성자
explicit queue(const Container& = Container()) //컨테이너의 기본 생성자를 호출해 queue을 생성하거나 인자로 받아
												 queue을 생성한다.

멤버 함수
bool empty() const                             //원소가 없는가?
size_type size() const                         //원수의 개수다.
void push(const vlaue_type& x)                 //원소를 추가한다.
void pop()                                     //원소를 제거한다.
value_type& front()                            //첫 원소를 참조한다.
const value_type& front() const                //const객체 첫 원소를 참조한다.
value_type& back()                             //마지막 원소를 참조한다.
const value_type& back() const                 //const객체 마지막 원소를 참조한다.

연산자
s1 == s2                                       //s1과 s2가 같은가?
s1 != s2                                       //s1과 s2가 다른가?
s1 < s2                                        //s1보다 s2가 큰가?
s1 <= s2                                       //s1보다 s2가 크거나 같은가?
s1 > s2                                        //s2보다 s1이 큰가?
s1 >= s2                                       //s2보다 s1이 크거나 같은가?

queue의 Container 템플릿 인자로 받는 컨테이너는 empty(), size(), push_back(), pop_front(), front()등의
인터페이스를 제공해야 합니다.
그래서 queue의 Container는 vector를 사용할 수 없으며, deque, list와 이 인터페이스를 지원하는 사용자 컨테이너를
사용할 수 있습니다.
queue───────────────────────────────┐
│deque────────┐                     │
│  │          │←push_back()         │←push():입력
│  │ |30|     │                     │
│  │ |20|     │                     │
│  │ |10|     │→pop_front()         │→pop():출력                    
│  └──────────┘                     │
│       ↕front()                    │
│                                   │
└───────────────────────────────────┘
		↕front():참조
11_2.cpp queue 컨테이너
queue<int ,list<int>> q:queue의 컨테이너 형식으로 list<int>를 사용하고 int형식의 원소를 저장하는 
queue를 생성합니다.
queue의 주요 인터페이스는 원소를 추가하는 push(), 원소를 제거하는 pop(), 첫 원소를 참조하는 front()입니다.

03 priority_queue 컨테이너
우선순위 queue를 구현한 템플릿 클래스입니다.
priority_queue컨테이너에 설정된 기본 컨테이너는 vector입니다.

템플릿 형식
template<
	typename T, 
	typename Container = vector<T>,
	typename Comp = less<typenamme Container::value_type>
> //T는 원소의 형식이며, Container는 priority_queue에서 사용될 컨테이너 형식이며, 기본 컨테이너는 vector<T>.
//Comp는 우선순위를 결정할 정렬 기준이며 기본 정렬 기준은 less<T>이다.
class priority_queue

멤버 형식
value_type                                     //Container::value_type으로 T형식이다.
size_type                                      //Container::size_type으로 첨자(index)나 원소 개수 등의 형식.
container_type                                 //Container형식이며, 기본 형식은 vector<T>이다.

생성자
explicit priority_queue(const Comp& = Comp(), const Container& = Container()) 
                                               //컨테이너의 기본 생성자를 호출해 priority_queue을 생성하거나 
											     인자로 받아 priority_queue을 생성한다.

멤버 함수
bool empty() const                             //원소가 없는가?
size_type size() const                         //원수의 개수다.
void push(const vlaue_type& x)                 //원소를 추가한다.
void pop()                                     //원소를 제거한다.
value_type& top()                              //Top원소를 참조한다.
const value_type& top() const                  //const객체 Top원소를 참조한다.

priority_queue는 내부적으로 STL의 힙 알고리즘인 make_heap(), push_heap(), pop_heap()을 사용하여 구현돼
있으므로 priority_queue의 Container템플릿 인자로 받는 컨테이너는 임의 접근 반복자를 제공하는 컨테이너.
또한, empty(), size(), push_back(), pop_back(), front() 등의 인터페이스를 제공해야 합니다.
그래서 vector와 deque컨테이너를 사용할 수 있습니다.
priority_queue──────────────────────┐
│vector───────┐                     │
│  │          │←push_back()         │←push():입력
│  │ |30|     │                     │
│  │ |20|     │                     │
│  │ |10|     │→pop_back()          │→pop():출력
│  └──────────┘                     │
│       ↕front()                    │
│                                   │
└───────────────────────────────────┘
		↕top():참조
11_3.cpp priority_queue 컨테이너
pq1은 vector<int>컨테이너를 사용하고 less정렬 기준을 사용한 priority_queue컨테이너.
pq2은 deque<int>컨테이너를 사용하고 greater정렬 기준을 사용한 priority_queue입니다.
인터페이스는 stack과 비슷하다.

*/