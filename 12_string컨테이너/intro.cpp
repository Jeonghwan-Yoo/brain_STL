/*
string컨테이너는 C++표준 라이브러리지만 일반적으로 STL에는 포함시키지 않습니다.
string컨테이너는 문자만을 원소로 저장하고 문자열을 조작할 목적으로 만들어진 컨테이너입니다.
string처럼 C++표준 컨테이너의 요구사항을 모두 만족하지 않는 컨테이너를 유사 컨테이너(alomost container).

01 string의 주요 인터페이스와 특징
string은 vector컨테이너와 비슷한 컨테이너이다.
시퀀스 컨테이너이며 배열 기반 컨테이너의 범주에 속합니다.
표준 C++라이브러리는 문서와 관련된 두 컨테이너(string, wstring)을 제공합니다.
string은 char형식의 문자를 관리하기 위한 basic_string<char>컨테이너의 typedef형식이며
wstring은 유니코드 문자(wchar_t)를 관리하기 위한 basic_string<wchar_t>컨테이너의 typedef형식입니다.

멤버 정의 형식
allocator_type                                 //메모리 관리자 형식
const_iterator                                 //const 반복자 형식
const_pointer                                  //const value_type* 형식
const_reference                                //const value_type& 형식
const_reverse_iterator                         //const 역 반복자 형식
difference_type                                //두 반복자 차이의 형식
iterator                                       //반복자 형식
npos                                           //찾기 관련 '실패'정의 값이며, 일반적으로 npos는 -1이다.
pointer                                        //value_type* 형식
reference                                      //value_type& 형식
reverse_iterator                               //역 반복자 형식
size_type                                      //첨자(index)나 원소의 개수 등의 형식
traits_type                                    //문자의 특성 형식
value_type                                     //원소의 형식

생성자
string s                                       //기본 생성자로 s를 생성
string s(sz)                                   //sz문자열로 s를 생성
string s(sz, n)                                //sz문자열에서 n개의 문자로 s를 생성
string s(n, c)                                 //n개의 c문자로 s를 생성
string s(iter1, iter2)                         //반복자 구간 [iter1, iter2)의 문자로 s를 생성
string s(p1, p2)                               //포인터 구간 [p1, p2)의 문자로 s를 생성

멤버 함수
s.append(sz)외 여러 버전                        //s에 sz를 붙임
s.assign(sz)외 여러 버전                        //s에 sz문자열을 할당
s.at(i)                                        //s의 i번째 문자를 참조
                                                 (const, 비const버전이 있으며 범위 점검을 포함)
p = s.begin()                                  //p는 s의 첫 문자를 가리키는 반복자(const, 비const버전)
s.c_str()                                      //C스타일(널문자를 포함한)의 문자열의 주소 반환
n = s.capacity()                               //n은 s에 할당된 메모리 공간의 크기
s.clear()                                      //s를 비움
s.compare(s2)외 여러 버전                       //s와 s2를 비교
s.copy(buf, n)                                 //buf로 n개의 문자를 복사
s.data()                                       //문자열의 배열 주소를 반환
s.empty()                                      //s가 비었는지 조사
p = s.end()                                    //p는 s의 끝을 표식하는 반복자(const, 비const버전)
q = s.erase(p)                                 //p가 가리키는 문자를 제거. q는 다음 원소를 가리킴
q = s.erase(b, e)                              //반복자 구간 [b, e)의 모든 문자를 제거. q는 다음 원소
s.find(c)외 여러 버전                           //c문자를 검색
s.insert(n, sz)외 여러 버전                     //n의 위치에 sz를 삽입
s.length()                                     //문자의 개수
n = s.max_size()                               //n는 s가 담을 수 있는 최대 문자의 개수(메모리의 크기)
s.push_back(c)                                 //s의 끝에 c를 추가
p = s.rbegin()                                 //p는 s의 역 순차열의 첫 원소를 가리키는 반복자
                                                 (const, 비const버전)
p = s.rend()                                   //p는 s의 역 순차열의 끝을 표식하는 반복자(const, 비const버전)
s.replace(pos, n, sz)외 여러 버전               //pos위치에 n개의 문자를 sz로 바꿈
s.reserve(n)                                   //n개의 문자를 저장할 공간을 예약
s.resize(n)                                    //s의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화
s.resize(n, c)                                 //s의 크기를 n으로 변경하고 확장되는 공간의 값을 c로 초기화
s.rfind(c)외 여러 버전                          //c문자를 끝부터 찾음
s.size()                                       //s원소의 개수
s2 = s.substr(pos)                             //s2는 pos부터의 s의 문자열
s.swap(s2)                                     //s와 s2를 swap

연산자
s[i]                                           //i번째 위치의 문자
s += s2                                        //s와 s2의 합을 s에 할당
s + s2                                         //s와 s2를 합한 새로운 string 객체
s = s2                                         //s2를 s에 할당
out << s                                       //s를 스트림에 씀
in >> s                                        //스트림에서 s로 읽음
getline(in, s)                                 //스트림에서 s로 한 줄을 읽음
그외 비교 연산                                  //==, !=, <, >, <=, >=

at(), begin(), capacity(), clear(), empty(), end(), erase(), max_size(), push_bakc(), rbegin(), rend(),
reserve(), resize(), size(), swap(), []연산, 비교 연산 등은 vector컨테이너와 비슷하다.
12_1.cpp string 생성자
주요 생성자의 초기화 방법을 확인할 수 있습니다.
string도 문자를 원소로 취하는 시퀀스 컨테이너이므로 반복자로 초기화할 수 있습니다.
또한, string클래스는 출력 스트림 <<연산자를 함수 오버로딩하여 스트림에 문자열을 출력할 수 있습니다.
string컨테이너는 배열 기반의 시퀀스 컨테이너이며, C,C++처럼 문자열에 '\0'문자를 포함할 요구사항은 없다.
       s.begin()     s.end()
          ↓           ↓
s size:6 |H|e|l|l|o|!|N|
STL string객체는 '\0'문자 포함을 요구하지 않음!

12_2.cpp append(), +=, push_back()
+=연산자는 일반적으로 전체 문자열을 덧붙일 때 사용하며, append()멤버 함수는 부분 문자열을 덧붙일 때 사용.
12_3.cpp =, assign() 멤버 함수
assign()멤버 함수의 사용 방법은 append()와 비슷합니다.
=연산자는 전체 문자열을 할당할 때 사용하며, assign()멤버 함수는 부분 문자열을 할당할 때 사용합니다.

string객체가 가지고 있는 문자열을 C-Style('\0'문자를 포함한)의 문자열로 변환하려면 c_str()멤버 함수를 사용.
비슷한 함수로 data()멤버 함수가 있고, data()멤버 함수는 '\0'문자를 포함하지 않는 문자의 배열을 반환합니다.
두가지 버전이 존재하는 이유는 STL string컨테이너가 문자열을 관리할 때 '\0'문자 포함이 필수 요구사항이 아니며
클라이언트의 문자열 요청 시 효율적인 문자열 반환을 위한 것.
대부분의 컴파일러는 c_str()과 data()멤버 함수의 구현이 같습니다.
12_4.cpp c_str(), data() 멤버 함수
두 멤버 함수 모두 const char*형식을 반환합니다.
대부분의 컴파일러에서 두 멤버 함수의 실행 결과가 같더라도 꼭 구분해서 사용해야 하며 '\0'문자를 포함한 문자열이
필요하다면 c_str()멤버 함수를 사용합니다.

12_5.cpp compare() 멤버 함수
문자열 비교 연산(!=, ==, >, <, >=, <=)은 전체 문자열을 비교하지만 compare()멤버 함수는 부분 문자열을 비교.
s1.compare(s2)에서 s1>s2면 1, s1<s2면 -1, s1==s2면 0을 반환.

복사 멤버 함수 copy().
length()는 size()와 같습니다.
단지, 더 직관적으로 문자열의 길이를 나타냅니다.
12_6.cpp copy()멤버 함수
copy()알고리즘은 '\0'문자 없는 문자열을 복사합니다.
s.copy(buf, n, off)는 s의 문자열을 buf로 off위치부터 n개 복사합니다.

find()와 rfind()멤버 함수는 문자나 부분 문자열의 위치를 반환하는 함수입니다.
만약 찾는 문자가 없으면 string::npos정의값을 반환합니다.
string::npos는 string(basic_string<>)의 멤버 정의 함수이며 일반적으로 -1입니다.
rfind()는 find()의 역방향을 검색하며 버전은 같습니다.
12_7.cpp find(), rfind() 멤버 함수
s.find('I')는 문자열의 시작 위치부터 검색하지만 s.find('I', 250는 문자열의 250위치부터 검색합니다.
string::npos는 -1이며 검색하는 문자나 문자열이 없으면 이 값을 반환합니다.

insert()멤버 함수는 index위치나 반복자가 가리키는 위치에 문자나 문자열을 삽입할 수 있습니다.
다른 컨테이너처럼 삽입 위치는 가리키는 원소의 앞쪽에 삽입됩니다.
12_8.cpp insert()멤버 함수
pos는 삽입 index이며 positer는 반복자입니다.
s2.insert(1, "ABC")는 s2의 index1에 "ABC"를 삽입합니다.
insert()멤버 함수처럼 지정한 위치 앞쪽으로 삽입합니다.
          pos:1
            ↓           s.insert(1, "ABC")
s size:6 |H|e|l|l|o|!|N|     ----->     s size:9 |H|A|B|C|e|l|l|o|!|N|

replace()멤버 함수를 사용하면 문자나 문자열을 교체할 수 있습니다.
위치(index)를 지정하는 버전과 반복자를 지정하는 버전이 있으며 사용방법은 insert()와 유사.
12_9.cpp replace() 멤버 함수
s1.replace(pos, n, sz, n2)버전은 s1의 문자열 pos(index)위치의 n개의 문자열을 sz의 n2개의 문자열로 교체합니다.
s1.replace(iterb, itere, iterb2, itere2)버전은 s1의 구간 [iterb, itere)의 문자열을 [iterb2, itere)의 문자열로
교체합니다.

substr()멤버 함수는 string객체의 일부 문자열을 추출하고자 할 때 사용합니다.
substr(pos, n)은 pos(indx)의 위치부터 n개 만큼의 문자열을 반환합니다.
만약 n을 string::npos로 지정하면 문자열의 마지막 문자까지가 됩니다.
12_10.cpp substr() 멤버 함수
t.substr(0)과 t.substr(0, string::npos)는 t문자열의 처음부터 마지막 문자까지의 부분문자열과 같습니다.
t.substr(2, string::npos)는 t문자열의 2(indx)위치부터 마지막 문자까지의 부분문자열입니다.

스트림으로부터 string객체로 문자열을 입력받으려면 입력 스트림 연산자 >>와 getline()함수를 사용합니다.
입력 스트림 연산자는 cin>>buf처럼 공백 문자를 구분자로 사용하며 getline()함수는 cin.getline()처럼 공백 문자도
포함하여 한 줄을 입력받는 함수입니다.
12_11.cpp 입력 스트림 연산자와 getline()전역 함수
getline(in, s)는 스트림이 in으로부터 s로 문자열을 한 줄 입력받습니다.
cin.getline()처럼 세 번째 인자에 종료 문자를 지정할 수 있습니다.

02 string의 주요 멤버 함수 정리
string은 문자열 조작을 목적으로 만들어진 시퀀스 컨테이너이자 배열 기반 컨테이너입니다.
그래서 string은 임의 접근 반복자를 지원하며 컨테이너에 문자를 연속하게 저장합니다.
vector처럼 메모리 공간을 예약(reserve())하고 사용할 수 있으며, capacity()로 예약(할당)된 메모리 공간을 확인.
reserve()를 사용하면 메모리 재할당으로 발생하는 비효율성을 줄일 수 있습니다.
string
reserve():메모리 예약 할당
string::npos:실패 정의 값(-1)
capacity():메모리의 크기
find():참조           at(i) s[i]:참조    rfind():참조
|       |       |       |       |       |       |... ↔ append(), +=, push_back():추가
    ↓					                    ↑                                 
c_str():문자열 반환('\0')		        replace():교체
data():문자열 배열 반환		            insert():삽입
copy():문자열 복사    		            erase():제거
substr():부분 문자열  		            assign():할당

c_str()은 C-style의 문자열을 반환합니다.
문자열을 복사하려면 copy()를 사용합니다.
주요 찾기 관련 함수는 find(), rfind()가 있으며, replace(), assign()을 사용해 문자열을 수정할 수 있습니다.
또한, insert(), erase()를 사용해 문자열을 삽입하거나 제거할 수 있습니다.
만약 찾기 관련 함수가 실패한다면 string::npos값을 반환합니다.
append()는 문자열을 덧붙일 때 아주 유용하게 사용할 수 있습니다.
+=연산자는 전체 문자열만을 덧붙일 수 있지만 append()는 부분 문자열도 덧붙일 수 있습니다.
string은 begin(), end(), rbegin(), rend()로 정방향과 역방향 임의 접근 반복자를 제공하며 대부분의 주요 멤버 함수는
반복자 버전이 있으므로 반복자를 사용한다면 조금 더 쉬운 문자열 처리가 가능합니다.

*/