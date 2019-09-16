/*
STL에는 100여 개의 알고리즘이 있으며 일곱 가지로 분류합니다.
1)nonmodifying algorithms
2)modifying algorithms
3)removing algorithms
4)mutating algorithms
5)sorting algorithms
6)sorted range algorithms
7)numeric algorithms
대부분의 알고리즘은 헤더<alogorithm>에 정의되며 수치관련 알고리즘은 <numeric>에 정의됩니다.

01 원소를 수정하지 않는 알고리즘
원소의 순서나 원소의 값을 변경하지 않고 원소를 읽기만 하는 알고리즘입니다.

p = adjacent_find(b, e)                 //p는 구간 [b, e)의 원소 중 *p == *(p+1)인 첫 원소를 가리키는 반복자.
p = adjacent_find(b, e, f)              //p는 구간 [b, e)의 원소 중 f(*p, *(p+1))이 참인 첫 원소를 가리키는 
                                          반복자.
n = count(b, e, x)                      //n은 구간 [b, e)의 원소 중 x 원소의 개수.
n = count_if(b, e, f)                   //n은 구간 [b, e)의 원소 중 f(*p)가 참인 원소의 개수.
equal(b, e, b2)                         //[b, e)와 [b2, b2+(e-b))의 모든 원소가 같은(==)가?
equal(b, e, b2, f)                      //[b, e)와 [b2, b2+(e-b))의 모든 원소가 f(*p, *q)가 참인가?
p = find(b, e, x)                       //p는 구간 [b, e)에서 x와 같은 첫 원소의 반복자.
p = find_end(b, e, b2, e2)              //p는 구간 [b, e)의 순차열 중 구간 [b2, e2)의 순차열과 일치하는 순차열
                                          첫 원소의 반복자. 단, [b2, e2)와 일치하는 순차열이 여러 개라면 
										  마지막 순차열 첫 원소의 반복자.
p = find_end(b, e, b2, e2, f)           //p는 구간 [b, e)의 순차열 중 구간 [b2, e2)의 순차열과 일치하는 순차열
										  첫 원소의 반복자. 단, [b2, e2)와 일치하는 순차열이 여러 개라면
										  마지막 순차열 첫 원소의 반복자. 이때 비교는 f를 사용.
p = find_if(b, e, f)                    //p는 구간 [b, e)의 모든 원소에 f(*p)가 참인 첫 원소를 가리키는 반복자.										  
f = for_each(b, e, f)                   //구간 [b, e)의 모든 원소에 f(*p) 동작을 적용한다. f를 다시 돌려줌.
lexicographical_compare(b, e, b2, e2)   //구간 [b, e)의 순차열이 구간 [b2, e2)의 순차열보다 작다면(less) ture,
                                          아니면 false를 반환한다. 이때 작음은 사전순이다.
lexicographical_compare(b, e, b2, e2, f)//구간 [b, e)의 순차열이 구간 [b2, e2)의 순차열보다 작다면(less) ture,
										  아니면 false를 반환한다. 이때 작음은 [b, e)의 반복자 p와 [b2, e2)의
										  반복자 q에 대해 f(*p, *q)가 참이다.
k = max(a, b)                           //k는 a와 b 중 더 큰 것.
k = max(a, b, f)                        //k는 a와 b 중 더 큰 것. 이때 큰 것은 f(a, b)를 사용.
p = max_element(b, e)                   //p는 구간 [b, e)에서 가장 큰 원소의 반복자.
p = max_element(b, e, f)                //p는 구간 [b, e)에서 가장 큰 원소의 반복자. 이때 비교는 f를 사용.
k = min(a, b)                           //k는 a와 b 중 더 작은 것.
k = min(a, b, f)                        //k는 a와 b 중 더 작은 것. 이때 작은 것은 f(a, b)를 사용.
p = min_element(b, e)                   //p는 구간 [b, e)에서 가장 작은 원소의 반복자.
p = min_element(b, e, f)                //p는 구간 [b, e)에서 가장 작은 원소의 반복자. 이때 비교는 f를 사용.
pair(p, q) = mismatch(b, e, b2)         //(p, q)는 구간 [b, e)와 [b2, b2+(e-b))에서 !(*p==*q)인 첫 원소를
										  가리키는 반복자의 쌍
pair(p, q) = mismatch(b, e, b2, f)      //(p, q)는 구간 [b, e)와 [b2, b2+(e-b))에서 !f(*p, *q)가 참인 첫 원소를
										  가리키는 반복자의 쌍
p = search(b, e, b2, e2)                //p는 구간 [b, e)의 순차열 중 구간 [b2, e2)의 순차열과 일치하는 
                                          순차열 첫 원소의 반복자(find_end()와 비슷하나 find_end()는 일치하는
										  순차열의 마지막 순차열의 반복자)
p = search(b, e, b2, e2, f)             //p는 구간 [b, e)의 순차열 중 구간 [b2, e2)의 순차열과 일치하는
										  순차열 첫 원소의 반복자. 이때 비교는 f를 사용.
p = search_n(b, e, n, x)                //p는 구간 [b, e)의 원소 중 x 값이 n개 연속한 첫 원소의 반복자.
p = search_n(b, e, n, x, f)             //p는 구간 [b, e)의 원소 중 f(*p, x)가 참인 값이 n개 연속한 첫 원소의 
                                          반복자.

8_1.cpp adjacent_find() 알고리즘
iter = adjacent_find(v.begin(), v.end()):iter는 구간 [v.begin(), v.end())의 순차열에서 현재 원소와
다음 원소가 같아지는 첫 원소의 반복자입니다.
만약 현재 원소와 다음 원소가 같은 원소가 없다면 구간의 끝인 v.end()를 반환합니다.
    v.begin()           v.end()
      ↓                    ↓
v    |10|20|30|30|40|40|50| N|
            ↑
		   iter
찾기 관련 알고리즘은 찾는 원소를 발견하지 못하면 찾는 구간의 끝 반복자를 반환합니다.
컨테이너의 끝 표시(past-the-end) 반복자가 아닙니다.
8_2.cpp adjacent_find() 알고리즘의 반환 반복자
iter_b가 v.begin()이고 iter_e가 v.begin()+2이므로 구간 [iter_b, iter_e)의 순차열은 10, 20.
이 구간에 adjacent_find()알고리즘을 수행하면 찾는 원소가 없으므로 구간의 끝인 iter_e를 반환합니다.
주의할 점은 v.end()가 아니라는 것.
    iter_b iter_e       v.end()
	  ↓     ↓              ↓
v    |10|20|30|30|40|40|50| N|
			↑
		   iter
구간 [iter_b, iter_e)의 순차열:10 20
순차열에서 인접한 원소가 특정 조건에 따라 인접한지 찾고자 한다면 adjacent_find(b, e, f)버전을 사용합니다.
f는 이항 조건자이며 현재 원소와 다음 원소를 가리키는 반복자 p와 p+1에 대해 f(*p, *(p+1))가 참인 첫 원소의
반복자를 반환합니다.
조건자는 bool 형식을 반환하는 함수류(함수자, 함수, 함수 포인터)입니다.
8_3.cpp adjacent_find() 조건자 버전
iter = adjacent_find(v.begin(), v.end(), Pred):iter는 두 인접 원소를 가리키는 반복자 p와 p+1에 대해
이항 조건자 Pred(*p, *(p+1))가 참인 첫 원소의 반복자입니다.
찾는 원소가 없다면 v.end()입니다.
    v.begin()  p        v.end()
	   ↓       ↓           ↓
v    | 10| 20| 30| 50| 90|  N|
	   └10┘└10┘└20┘└10┘	
			   ↑
		      iter
클라이언트
bool Pred(int a, int b) {
	return abs(b - a) > 10;
}
void main() {
	iter = adjacent_find(v.begin(), v.end(), Pred);
}
서버
Iterator adjacent_find(Iterator first, Iterator last, Func pred) {
	first부터 last까지...
		if(pred(*p, *(p+1)))
			return p;
}

순차열에서 원소의 개수를 구하려면 간단하게 count()알고리즘을 사용합니다.
8_4.cpp count()알고리즘
조건자 버전의 count_if(b, e, f)알고리즘을 사용하여 조건에 맞는 원소의 개수를 구할 수 있습니다.
f는 단항 조건자로 원소를 가리키는 반복자 p에 대해 f(*p)가 참인 원소의 개수를 반환합니다.
8_5.cpp 조건자 버전의 count_if()
n = count_if(v.begin(), v.end(), Pred):구간 [v.begin(), v.end())의 원소를 가리키는 반복자 p에 대해
단항 조건자 Pred(*p)가 참인 모든 원소의 개수를 반환합니다.
	v.begin()           v.end()
	   ↓                   ↓
v    | 10| 20| 30| 50| 90|  N|
       X   X   O   O   O
클라이언트
bool Pred(int n) {
	return 25 < n;
}
void main() {
	n = count_if(v.begin(), v.end(), Pred);
}
서버
Iter_traits::difference_type count_if(Iterator first, Iterator last, Func pred) {
	first부터 last까지...
		if(pred(*p)) 
			count++;
	return count;
}

equal()알고리즘을 사용하여 두 순차열의 원소가 모두 같은(==)지 판단할 수 있습니다.
equal(b, e, b2)는 구간 [b, e)의 순차열과 구간 [b2, b2+(e-b))의 순차열이 같은지 판단하는 알고리즘.
두 개의 순차열을 필요로하는 대부분의 알고리즘은 두 순차열의 길이(원소의 개수)가 같을 때 동작하므로
첫 번째 순차열은 구간 [b, e)을 필요로하지만, 두 번째 순차열은 시작 반복자인 b2만을 필요로 합니다.
8_6.cpp equal() 알고리즘
equal(v1.begin(), v1.end(), v2.begin()):구간 [v1.begin(), v1.end())의 원소의 개수가 3개이므로
두 구간 [v1.begin(), v1.end())와 [v2.begin(), v2.begin()+3)의 순차열을 비교합니다.
조건에 따라 두 순차열이 같은 지 비교하고자 한다면 equal(b, e, b2, f)버전을 사용합니다.
f는 이항 조건자로 각 순차열의 반복자 p와 q에 대해 f(*p, *q)가 모두 참이면 equal()알고리즘은 참을 반환.
8_7.cpp 조건자 버전 equal()알고리즘
equal(v1.begin(), v1.end(), v2.begin(), Pred):두 순차열의 반복자가 각각 p와 q라면 순차열의 모든 원소에 ㄷ해ㅐ
Pred(*p, *q)가 참이므로 참을 반환합니다.
                             p
                             ↓
[v1.begin(), v1.end())      |10|21|30| N|
                             0  1  3
[v2.begin(), v2.begin()+3)  |10|20|33| N|
                             ↑
							 q

find()는 특정 원소를 찾는 알고리즘이며, find_if()는 조건에 따라 원소를 찾는 알고리즘입니다.
8_8.cpp find()알고리즘
iter = find(v.begin(), v.end(), 20):iter는 구간 [v.begin(), v.end())에서 20값을 갖는 첫 원소의 반복자.
iter = find_if(v.begin(), v.end(), Pred):iter는 구간 [v.begin(), v.end())에서 단항조건자 Pred(*p)가
참인 첫 원소의 반복자.
	v.begin()    iter     v.end()
	   ↓           ↓       ↓
v    | 10| 20| 30| 40| 50|  N|
클라이언트
bool Pred(int n) {
	return 35 < n;
}
void main() {
	iter = find_if(v.begin(), v.end(), Pred);
}
서버
Iterator find_if(Itereator first, Iterator last, Func pred) {
	first부터 last까지...
		if(pred(*p)) 
			return p;
	return last;
}
순차열 하나에 포함하는 다른 순차열이 있는지 찾아야 한다면 find_end()와 search()알고리즘을 사용합니다.
find_end()는 일치하는 순차열이 여러 개라면 마지막 순차열의 반복자를 반환하며 
search()는 첫 번째 순차열의 반복자를 반환합니다.
8_9.cpp find_end()알고리즘 이용해 컨테이너 판단
iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end()):구간 [v1.begin(), v1.end())의 순차열에 구간
[v2.begin(), v2.end())의 순차열이 일치하는지 판단하여 일치하는 순차열 구간이 여러 개라면 마지막 순차열의
첫 원소 반복자를 반환합니다.
iter는 v1에 v2와 일치하는 순차열 구간은 두 곳이며 이중에서 마지막 순차열의 첫 원소의 반복자입니다.
    v1.begin()            iter     v1.end()
       ↓                    ↓        ↓
v1    |10|20|30|40|50|60|70|30|40|50| N|
             ────────       ────────
v2    |30|40|50| N|
       ↑         ↑
v2.begin()    v2.end()
조건자 버전의 find_end()알고리즘을 사용하면 원소의 비교를 사용자가 결정할 수 있습니다.
8_10.cpp find_end()알고리즘 조건자 버전
iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred):구간 [v1.begin(), v1.end())의 순차열과
구간 [v2.begin(), v2.end())의 순차열이 일치하는지 판단하고 일치하는 구간이 여러 개라면 마지막 순차열의 첫 원소
반복자를 반환합니다.
비교는 Pred(*p, *q)를 사용합니다.
p는 v1의 순차열 반복자이며 q는 v2의 순차열 반복자입니다.
[v2.begin(), v2.end())의 순차열이 [v1.begin(), v1.end())의 순차열의 원소보다 모두 크거나 같은 순차열 구간을
찾습니다.
마지막 순차열은 원소가 10,11,12인 순차열이므로 iter는 10을 가리키는 반복자가 됩니다.
	v1.begin()         iter       v1.end()
	   ↓                 ↓           ↓
v1    |10|15|20|40|50|60|10|11|12|80| N|
	   ────────          ────────
v2    |10|15|25| N|
	   ↑         ↑
v2.begin()    v2.end()
find_first_of()알고리즘은 두 순차열을 비교하여 모든 원소 중 같은 원소가 하나라도 발견되면 첫 원소의 반복자를 반환.
8_11.cpp find_first_of()알고리즘
iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end()):구간 [v1.begin(), v1.end())순차열에서
구간 [v2.begin(), v2.end())의 원소 중 같은 원소가 발견되면 첫 원소의 반복자를 반환합니다.
v1의 순차열에서 v2의 순차열 원소가 첫 번째로 발견되는 위치는 20이므로 20의 반복자를 반환합니다.
v1.begin() iter      v1.end()
	   ↓   ↓           ↓
v1    |10|20|30|40|50| N|
	      ──    ──
v2    |40|80|20| N|
	   ↑         ↑
v2.begin()    v2.end()
8_12.cpp find_first_of() 알고리즘
순차열 v1에서 v2의 순차열 원소 40,80,20보다 큰 수는 30이 처음으로 iter는 30원소의 반복자입니다.

순차열의 모든 원소에 사용자 동작을 적용하려면 일반적으로 for_each()알고리즘을 사용합니다.
for_each()알고리즘은 원소를 수정하지 않는 알고리즘과 원소를 수정하는 알고리즘 두 분류에 모두 포함됩니다.
for_each(b, e, f)는 구간 [b, e)의 반복자가 p라면 f(*p)를 호출합니다.
여기서는 f는 함수류(함수자, 함수, 함수 포인터)입니다.
8_13.cpp for_each()알고리즘
for_each(v.begin(), v.end(), Print():구간 [v.begin(), v.end())의 모든 원소에 대해 Print(*p)를 적용합니다.
p는 순차열의 반복을 의미합니다.
클라이언트
bool Print(int n) {
	cout << n << " ";
}
void main() {
	for_each(v.begin(), v.end(), Print);
}
서버
Func for_each(Iterator first, Iterator last, Func fun) {
	for(Iterator p = first; p != last; ++p)
		fun(*p);
	return fun;
}
사용자 정책을 반영하려고 for_each()알고리즘의 함수류를 함수가 아닌 함수자로 변경하면 다양한 출력 패턴을 구현할
수 있습니다.
일반 함수는 부가적인 정보를 전달할 수 없지만 함수자는 객체이므로 상태 변수를 사용하여 부가적인 정보를 전달하고
변경할 수 있기 때문입니다.
8_14.cpp for_each()알고리즘과 함수자
PrintFunctor():fmt가 ' '인 함수 객체를 생성합니다.
PrintFunctor(','):fmt가 '.'인 함수 객체를 생성합니다.
PrintFunctor('\n'):fmt가 '\n'인 함수 객체를 생성합니다.

문자열 비교처럼 순차열의 사전순 비교(less)가 필요하다면 lexicographical_compare()알고리즘을 사용합니다.
lexicographical_compare(b, e, b2, e2)알고리즘은 순차열 [b, e)와 [b2, e2)의 모든 원소를 문자열처럼
비교하여 참과 거짓을 반환합니다.
8_15.cpp lexicographical_compare()알고리즘
v1과 v2의 순차열 비교에서 10과 20원소는 같지만 v1의 30과 v2의 50원소에서 20 < 50이므로 
lexicographical_compare()알고리즘은 true를 반환합니다.
또한, v1과 v3의 순차열 비교에서 두 순차열이 같으므로 lexicographical_compare()알고리즘은 false를 반환.
 v3     v1     v2
|10| = |10| = |10|
|20| = |20| = |20|
|30| = |30| < |50|
| N|   | N|   | N|
  v1<v3   v1<v2
  false    true
순차열을 비교할 때 사용자가 직접 비교 기준을 설정하려면 조건자 버전의 lexicographical_compare(b, e, b2, e2, f)
알고리즘을 사용합니다.
f는 비교 기준으로 사용될 조건자입니다.
8_16.cpp 조건자 버전의 lexicographical_compare()알고리즘
일반 버전의 lexicographical_comapre()알고리즘이 기본 비교 기준으로 less조건자를 사용한다.

max(),min() 알고리즘으로 크거나 작은 정수를 출력한다.
8_17.cpp max(), min()알고리즘
p3 = max(pt1, pt2, XCompare):pt1과 pt2는 Point객체로 비교 연산자가 없어 크기 비교가 불가능합니다.
따라서 XCompare라는 이항 조건자를 사용하여 Point객체의 x값으로 크기를 비교합니다.
조건자가 참인 Point객체를 반환합니다.
p3 = max(pt1, pt2, YCompare):조건자가 YCompare로 Point객체의 y값으로 크기를 비교합니다.
max_element(b, e)와 max_element(b, e, f)알고리즘은 구간 [b, e)에서 가장 큰 원소의 반복자를 반환합니다.
min_element(b, e)와 min_element(b, e, f)알고리즘은 구간 [b, e)에서 가장 작은 원소의 반복자를 반환합니다.
f는 비교 기준으로 사용될 이항 조건자입니다.
8_18.cpp max_element(), min_element()알고리즘
가장 큰 원소는 50이며 가장 작은 원소는 10이므로 iter는 각각의 원소를 가리키는 반복자입니다.
조건자 버전의 min_element(b, e, f), max_element(b, e, f)알고리즘을 사용하면 사용자가 직접 비교 기준을
설정할 수 있습니다.
8_19.cpp 조건자 버전 max_element()알고리즘
정렬 기준 Compare는 이항 조건자로 Point객체의 x값을 먼저 비교하고 x값이 같으면 y값을 비교하여 가장 큰 Point
객체를 찾아 출력합니다.
Point(3,3)객체가 x값이 3으로 가장크고 y값 3으로 가장 큰 객체입니다.
반복자는 가리키는 객체의 멤버를 ->연산자로 쉽게 접근할 수 있습니다.

두 순차열을 비교하여 원소의 값이 서로 다른 위치를 찾고자 한다면 mismatch()알고리즘을 사용합니다.
mismatch(b, e, b2)는 구간 [b, e)과 구간 [b2, b2+(e-b))의 모든 원소를 하나씩 비교하여 원소 값이 서로 다른
첫 원소의 반복자 쌍을 반환합니다.
(p, q)가 구간 [b, e)과 구간 [b2, b2+(e-b))의 반복자일 때 !(*p==*q)인 첫 원소의 반복자 쌍 (p, q)을 반환합니다.
8_20.cpp mismatch() 알고리즘
mismatch()알고리즘은 서로 다른 원소가 발견되는 첫 원소의 반복자 쌍을 반환하므로 pair객체는 first와 second는
모두 vector의 반복자로 구성됩니다.             
               first ───────────┐   
                ↓               │
v1    |10|20|30|40|50| N|       │
       =  =  =  !=          iter_pair
v2    |10|20|30|80|90| N|       │
                ↑               │
             second ────────────┘
사용자가 직접 조건을 지정할 수 있는 조건자 버전의 mismatch(b, e, b2, f)알고리즘도 있습니다.
조건자 버전의 mismatch()알고리즘은 f에 이항 조건자를 지정하면 !f(*p, *q)가 참인 첫 원소의 반복자를 반환합니다.
8_21.cpp 조건자 버전의 mismatch()알고리즘
두 순차열 원소의 차가 5보다 큰(!Pred(*p, *q)가 참인) 첫 번째 위치는 v1의 40과 v2의 46이므로
iter_pair의 first와 second는 각각 40,46의 반복자입니다.
	          p	      first ───────────┐
	          ↓	       ↓               │
          v1 |10|20|30|40|50| N|       │
!Pred(*p, *q) F  F  F  T          iter_pair
          v2 |11|25|33|46|50| N|       │
	          ↑		   ↑               │
	          q	    second ────────────┘

search()알고리즘이 find_end()와 다른 점은 일치하는 순차열이 여러 개라면 find_end()는 마지막 순차열의 반복자를
반환하지만, search()는 첫 번째 순차열의 반복자를 반환합니다.
8_22.cpp search() 알고리즘
iter = search(v1.begin(), v1.end(), v2.begin(), v2.end()):구간 [v1.begin(), v1.end())의 순차열에
구간 [v2.begin(), v2.end())의 순차열이 일치하는지 판단하여 일치하는 순차열 구간이 여러 개라면
첫 번째 순차열의 첫 원소 반복자를 반환합니다.
iter는 v1에 v2와 일치하는 순차열 구간은 두 곳이며 이 중에서 첫 번째 순차열의 첫 원소의 반복자입니다.
 v1.begin()  iter                v1.end()
	   ↓      ↓                      ↓
v1    |10|20|30|40|50|60|70|30|40|50| N|
			 ────────       ────────
v2    |30|40|50| N|
	   ↑         ↑
v2.begin()    v2.end()
조건자 버전 search()알고리즘도 있습니다.
순차열에서 원소의 값이 n번 연속하게 반복되는지 찾고 싶다면 search_n()알고리즘을 사용합니다.
search_n(b, e, n, x)알고리즘은 구간 [b, e)의 순차열에서 원소 x가 n번 연속한 첫 원소의 반복자를 반환합니다.
8_23.cpp search_n() 알고리즘
iter = search_n(v.begin(), v.end(), 3, 30):iter는 구간 [v.begin(), v.end())순차열에 30원소가
3번 이상 연속한 첫 원소의 반복자입니다.
    begin()  iter         end()
	  ↓      ↓             ↓
v    |10|20|30|30|30|40|50| N|
		    ────────    
search_n(b, e, n, x, f)는 구간 [b, e)의 반복자가 p라면 조건자 f(*p, x)가 참인 값이 n개 연속한 첫 원소의
반복자를 반환합니다.
8_24.cpp 조건자 버전 search_n()알고리즘
iter = search_n(v.begin(), v.end(), 3, 30, Pred):iter는 구간 [v.begin(), v.end())순차열에 30과의 차가
5이하(Pred(*p, 30))인 원소가 3번 이상 연속한 첫 원소의 반복자입니다.
	 begin()  iter                end()
	   ↓       ↓                   ↓
v    | 10| 20| 32| 28| 33| 40| 50|  N|
|v-30| 20  10   2   2   3  10  20
			  ─────────── 

02 원소를 수정하는 알고리즘
원소의 값을 변경하거나 목적지 순차열로 원소를 복사하는 알고리즘입니다.

p = copy(b, e, t)                       //구간 [b, e)의 원소를 [t, p)로 모두 복사한다.
p = copy_backward(b, e, t)              //구간 [b, e)의 원소를 마지막 원소부터 [p, t)로 모두 복사한다.
fill(b, e, x)                           //구간 [b, e)의 모든 원소를 x로 채운다.
fill_n(b, n, x)                         //구간 [b, b+n)의 모든 원소를 x로 채운다.
f = for_each(b, e, f)                   //구간 [b, e)의 모든 원소에 f(*p) 동작을 허용한다. f를 다시 되돌려줌.
generate(b, e, f)                       //구간 [b, e)의 모든 원소를 f()로 채운다.
generate_n(b, n, f)                     //구간 [b, b+n)의 모든 원소를 f()로 채운다.
iter_swap(p, q)                         //반복자 p, q가 가리키는 *p, *q의 원소를 교환한다.
p = merge(b, e, b2, e2, t)              //정렬된 순차열 [b, e)과 [b2, e2)를 [t, p)로 합병 정렬한다.
p = merge(b, e, b2, e2, f)              //정렬된 순차열 [b, e)과 [b2, e2)를 [t, p)로 합병 정렬한다.
                                          이 때 비교는 f를 사용한다.
replace(b, e, x, x2)                    //구간 [b, e)의 x인 원소를 x2로 수정한다.
replace_if(b, e, f, x2)                 //구간 [b, e)의 f(*p)가 참인 원소를 x2로 수정한다.
p = replace_copy(b, e, t, x, x2)        //구간 [b, e)의 x인 원소를 x2로 수정하여 [t, p)로 복사한다.
p = replace_copy_if(b, e, t, f, x2)     //구간 [b, e)의 f(*p)가 참인 원소를 x2로 수정하여 [t, p)로 복사한다.
swap(a, b)                              //a와 b를 교환한다.
wap_ranges(b, e, b2)                    //구간 [b, e)의 원소와 구간 [b2, b2+(e-b))의 원소를 교환한다.
p = transform(b, e, t, f)               //구간 [b, e)의 모든 원소를 f(*p)하여 [t, t+(e-b))에 저장한다.
                                          p는 저장된 마지막 원소의 반복자(t+(e-b))이다.
p = transfrom(b, e, b2, t, f)           //구간 [b, e)과 [b2, b2+(e-b))의 두 순차열의 반복자 p, q일 때
                                          모든 원소를 f(*p,*q)하여 [t, t+(e-b))에 저장한다.
										  p는 저장된 마지막 원소의 반복자(t+(e-b))이다.

순차열에서 다른 순차열로 원소를 복사해야 한다면 copy()알고리즘을 사용합니다.
copy(b, e, t)알고리즘은 구간 [b, e)의 순차열을 구간 [t, t+(e-b))의 순차열로 모두 복사합니다.
주목할 점은 목적지 순차열로 복사 동작을 수행할 때 두 가지 모드의 복사 동작이 있습니다.
하나는 덮어쓰기(overwrite)모드이고, 하나는 삽입(insert)모드입니다.
모든 알고리즘의 기본 동작은 덮어쓰기 모드이며 반복자 어댑터(insert_iterator) 등을 사용하여 알고리즘을
삽입 모드로 동작하게 할 수 있습니다.
8_25.cpp copy() 알고리즘
iter = copy(v1.begin(), v1.end(), v2.begin()):구간 [v1.begin(), v1.end())의 순차열을
[v2.begin(), v2.begin()+(v1.end()-v1.begin())의 순차열로 복사합니다.
copy()알고리즘은 목적지 끝 반환자를 반환하므로 목적지 순차열은 [v2.begin(), iter)가 됩니다.
주의할 점은 copy()알고리즘이 덮어쓰기 모드로 복사 동작을 수행하므로 [v2.begin(), v2.end())의 순차열은
구간 [v1.begin(), v1.end())순차열 이상의 원소를 가져야 합니다.
v1    |10|20|30|40|50| N|   복사 후   |10|20|30|40|50| N|
                            ----->    -----------------> 복사 방향
v2    | 0| 0| 0| 0| 0| N|             |10|20|30|40|50| N|
                                                       ↑
													  iter
원소의 복사를 순차열의 마지막 원소부터 복사하고자 한다면 copy_backward() 알고리즘을 사용합니다.
copy_backward(b, e, t)알고리즘은 구간 [b, e)의 모든 원소를 [t-(e-b),t)의 순차열로 마지막 원소부터 복사.
8_26.cpp copy_backward() 알고리즘
iter = copy_backward(v1.begin(), v1.end(), v2.end()):구간 [v1.begin(), v1.end())의 순차열을
[v2.end()-(v1.end()-v1.begin()), v2.end())의 순차열로 마지막 원소부터 복사합니다.
copy_backward()알고리즘은 목적지 시작 반복자를 반환하므로 목적지 순차열은 [iter, v2.end())가 됩니다.
v1                   |10|20|30|40|50| N|   복사 후                  |10|20|30|40|50| N|
							               ----->         복사 방향  <----------------- 
v2    | 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| N|             | 0| 0| 0| 0| 0|10|20|30|40|50| N|
													                 ↑
													               iter

순차열을 특정 값으로 채우고자 한다면 fill(), fill_n()알고리즘을 사용합니다.
fill(b, e, x)알고리즘은 구간 [b, e)의 원소를 x로 채우며 fill_n(b, n, x)알고리즘은 구간 [b, b+n)의 원소를 x로 채움.
8_27.cpp fill(), fill_n()알고리즘
fill(v.begin(), v.end(), 0):구간 [v.begin(), v.end())의 원소를 모두 0으로 채웁니다.
fill_n(v.begin(), 3, 55):구간 [v.begin(), v.begin()+3)의 원소를 모두 55로 채웁니다.

for_each()알고리즘은 원소를 수정하는 알고리즘으로도 사용됩니다.
for_each(b, e, f)는 구간 [b, e)의 반복자가 p라면 모든 원소 f(*p)를 적용합니다.
f는 함수류(함수자, 함수, 함수 포인터)입니다.
이렇게 사용자 함수류를 순차열 모든 원소에 적용하는 알고리즘은 for_each()와 transform()이 잇으며
for_each()알고리즘은 출력 매개변수(out parameter)를 사용하고 transform()은 함수의 반환값을 사용하여
사용자의 동작(함수)을 원소에 적용합니다.
8_28.cpp for_each() 알고리즘을 사용한 원소의 수정
void Func(int& r):사용자 함수의 매개변수는 출력 매개변수로 사용되어야 하므로 꼭 레퍼런스를 사용해야 합니다.
for_each(v.begin(), v.end(), Func):구간 [v.begin(), v.end())의 모든 원소에 Func(*p)를 적용합니다.
  v.begin() p       v.end()
      ↓     ↓        ↓
v    |15|25|35|40|50| N|
클라이언트
void Func(int& r) {
	r += 5;
}
void main() {
	for_each(v.begin(), v.end(), Func);
}
서버
Function for_each(Iterator first, Iterator last, Function fun) {
	for(Iterator p = first;p != last;++p)
		fun(*p);
	return fun;
}
for_each()알고리즘의 사용자 함수류를 함수자(함수 객체)로 구현하면 객체는 상태 변수를 가질 수 있으므로 
함수를 사용하는 것보다 더 다양한 작업을 순차열에 적용할 수 있습니다.
8_29.cpp 함수자를 사용한 for_each() 알고리즘
for_each(v.begin(), v.end(), Accumulation(0)):Accumulation(0) 객체는 total 상태 변수를 사용하여 이전
원소의 누적 값을 저장하고 현재 원소(*p)에 이전 원소(*(p-1))와의 누적을 적용합니다.
시작값 ┐
v     0|  1|  2|  3|  4|  5|  N|
      └+=┘
v      |  1|  2|  3|  4|  5|  N|
	      └+=┘
v      |  1|  3|  3|  4|  5|  N|
		      └+=┘
v      |  1|  3|  6|  4|  5|  N|
			      └+=┘
v      |  1|  3|  6| 10|  5|  N|
				      └+=┘
v      |  1|  3|  6| 10| 15|  N|

순차열의 모든 원소를 단순한 동작의 값으로 수정하고자 한다면 generate()알고리즘을 사용합니다.
generate(b, e, f)알고리즘은 구간 [b, e)의 모든 원소를 f()로 채웁니다.
generate_n(b, n, f)알고리즘은 구간 [b, b+n)의 모든 원소를 f()로 채웁니다.
8_30.cpp generate(), generate_n()알고리즘
generate(v.begin(), v.end(), Integer(1)):구간 [v.begin(), v.end())의 원소를 Integer(1)함수자로
정수를 1씩 증가하며 채웁니다.
Integer(1) 함수자의 상태 변수 data의 초깃값은 1입니다.
generate_n(v.begin(), 3, Integer(1)):구간 [v.begin(), v.begin()+3))의 원소를 Integer(1)함수자로
정수를 1씩 증가하며 채웁니다.
Integer(1) 함수자의 상태 변수 data의 초깃값은 1입니다.
generate()알고리즘과 for_each(), transform()알고리즘의 큰 차이점은 함수자의 매개변수로 순차열의 원소를
전달받지 않기 때문에 원소가 가지고 있는 원값을 활용할 수 없고, 단순히 일정한 값으로 채울 뿐입니다.

단순히 값을 교환하거나 반복자가 가리키는 값을 교환하고자 한다면 swap()과 iter_swap()알고리즘을 사용합니다.
swap(a, b)알고리즘은 a와 b를 교환합니다.
iter_swap(p, q)알고리즘은 반복자가 가리키는 *p와 *q를 교환합니다.
8_31.cpp swap(), iter_swap()알고리즘

정렬된 두 순차열을 하나의 정렬된 순차열로 합병하려면 merge()알고리즘을 사용합니다.
merge(b, e, b2, e2, t)알고리즘은 정렬된 구간 [b, e)의 순차열과 구간 [b2, e2)의 순차열을 
[t, t+(e-b)+(e2-b2))의 순차열로 합병 정렬한다.
8_32.cpp merge() 알고리즘
iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()):구간 [v1.begin(), v1.end())의
순차열과 구간 [v2.begin(), v2.end())의 순차열을 합병 정렬하여 
[v3.begin(), v3.begin()+(v1.end()-v1.begin())+(v2.end()-v2.begin()))에 합병 정렬합니다.
merge()알고리즘의 목적지 끝 반복자를 반환하므로 iter_end는 목적지 끝 반복자이며 결론적으로
구간 [v3.begin(), iter_end)로 합병 정렬하는 것입니다.
merge()는 정렬된 구간에서 동작한다는 점에 주의해야 합니다.
v1 size:5  |10|30|50|60|80| N|                합병 후    |10|30|50|60|80| N|    iter_end
v1 size:3  |20|40|70| N|                       ----->    |20|40|70| N|             ↓
v1 size:10 | 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| N|            |10|20|30|40|50|60|70|80| 0| 0| N|
만약 합병하려는 두 순차열이 특정 정렬 기준에 의해 정렬된 상태라면 일반 버전의 merge()알고리즘을 사용할 수 없습니다.
merge()는 기본적으로 오름차순 정렬 기준(less)을 전체로 동작하기 때문입니다.
이런 경우 조건자 버전 merge(b, e, b2, e2, t, f)알고리즘을 사용하여 특정 정렬 기준을 설정할 수 있습니다.
여기서 f는 이항 조건자로 두 순차열([b, e)와 [b2, e2))의 특정 정렬 기준입니다.
8_33.cpp merge()알고리즘의 정렬 기준으로 greater를 사용한 예
iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), Greater<int>()):모두 일반 버전의
merge()와 같고 v1과 v2 순차열이 greater 정렬 기준으로 정렬되어 있으므로 합병 정렬 기준을 사용자 Greater조건자를
만들고 설정합니다.

순차열의 특정 원소를 다른 값으로 수정하고자 한다면 replace() 알고리즘을 사용합니다.
replace(b, e, x, x2)알고리즘은 구간 [b, e)의 x인 원소를 x2로 수정합니다.
8_34.cpp replace() 알고리즘
구간 [v.begin(), v.end())의 원소 30을 0으로 수정합니다.
사용자가 지정한 조건에 맞는 원소를 수정하려면 replace_if() 알고리즘을 사용합니다.
replace_if(b, e, f, x2)알고리즘은 구간 [b,e)의 원소 중 f(*p)가 참인 원소를 모두 x2로 변경합니다.
f는 단항 조건자입니다.
8_35.cpp replace_if() 알고리즘
replace_if(v.begin(), v.end(), Pred, 0):구간 [v.begin(), v.end())의 원소 중 Pred(*p)가 참인(30이상 50이하)
모든 원소를 0으로 수정합니다.
사용자의 조건에 맞는 원소를 수정하여 목적지 순차열로 복사하려면 replace_copy()와 replace_copy_if()알고리즘 사용.
8_36.cpp replace_copy(), replace_copy_if()알고리즘
iter_end = replace_copy(v1.begin(), v1.end(), v2.begin(), 30, 0):구간 [v1.begin(), v1.end())의 원소 중
30인 원소를 0으로 수정하여 순차열 [v2.begin(), iter_end)로 복사합니다.
iter_end = replace_copy_if(v1.begin(), v1.end(), v3.begin(), Pred, 0):구간 [v1.begin(), v1.end())의 원소 중
Pred(*p)가 참(30이하)인 원소를 0으로 수정하여 순차열 [v3.begin(), iter_end)로 복사합니다.

순차열과 순차열의 모든 원소를 교환하려면 swap_ranges()알고리즘을 사용합니다.
swap_ranges(b, e, b2)알고리즘은 구간 [b, e)의 순차열과 구간 [b2, b2+(e-b))의 모든 원소를 교환합니다.
8_37.cpp swap_ranges() 알고리즘

순차열의 모든 원소에 사용자의 정책(동작)을 반영(적용)하려면 일반적으로 for_each(), transform()알고리즘을 사용.
transform()알고리즘이 for_each()알고리즘과 다른 것은 원본의 순차열의 변화 없이 목적지의 순차열로 저장한다는 점.
물론 덮어쓰기 모드로 동작합니다.
transform(b, e, t, f)는 구간 [b, e)의 반복자가 p라면 f(*p)를 호출하여 반환값을 순차열 [t, t+(e-b))로 저장.
여기서는 f는 단항  함수류(함수자, 함수, 함수 포인터)입니다.
8_38.cpp transform() 알고리즘
int Func(int n):transform()알고리즘의 사용자 정책 함수는 반환값을 사용하므로 for_each()알고리즘과
다르게 반환 타입을 가집니다.
transform(v.begin(), v.end(), v.begin(), Func):for_each()알고리즘 결과를 같게 하기 위해 목적지 순차열을
[v.begin(), v.begin()+(v.end()-v.begin()))로 원본의 순차열과 같게 지정했다.
  v.begin() p       v.end()
	  ↓     ↓        ↓
v    |15|25|35|40|50| N|
클라이언트
int Func(int n) {
	return n + 5;
}
void main() {
	transform(v.begin(), v.end(), v.begin(), Func);
}
서버
Iterator transform(Iterator first, Iterator last, Iterator target, Function fun) {
	for(Iterator p = first;p != last;++p)
		*target++ = fun(*p);
	return target;
}
transform()알고리즘은 목적지의 끝 반복자를 반환하므로 iter_end = transform(b, e, t, f)는 구간 [b, e)의
원소에 f(*p)를 적용하여 반환 값을 목적지 순차열 [t, iter_end)에 저장합니다.
8_39.cpp transform() 알고리즘의 반환 반복자
iter_end = transform(v1.begin(), v1.end(), v2.begin(), Func):구간 [v1.begin(), v1.end())의 원소를
Func(*p)에 적용하여 반환값을 [v2.begin(), iter_end)에 저장합니다.
사용자 연산(함수류 적용)을 두 순차열의 원소에 적용하고자 한다면 transform(b, e, b2, t, f)알고리즘 버전을
사용합니다.
구간 [b, e)의 순차열과 [b2, b2+(e-b))의 순차열의 반복자를 p, q라 하면 f(*p, *q)한 값을
순차열 [t, t+(e-b))에 저장합니다.
8_40.cpp 두 순차열의 연산이 가능한 transform() 알고리즘
iter_end = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>()):구간 [v1.begin(), v1.end())의
순차열과 [v2.begin(), v2.begin()+(v1.end()-v1.begin()))의 순차열의 합(plus<int> 조건자)을
[v3.begin(), v3.begin()+(v1.end()-v1.begin()))의 순차열에 저장합니다.
이 때 iter_end는 목적지 순차열의 끝 반복자이므로 [v3.begin(), iter_end) 순차열이 목적지 순차열이 됩니다.
plus<int>()는 두 원소의 합을 반환하는 STL제공 조건자입니다.
                 p
                 ↓                                                   iter_end
v1 size:5 |10|20|30|40|50| N|    Plus(*p, *q)                            ↓
                                  ------>      v3 size:5 |11|22|33|44|55| N|
v2 size:5 | 1| 2| 3| 4| 5| N|                  
                 ↑        
                 q          

주의점은 알고리즘 모두가 덮어쓰기(overwrite)모드로 동작합니다.
그래서 목적지 순차열은 원본 이상의 원소를 가지고 있어야 합니다.
알고리즘이 삽입(insert)모드로 동작하려면 insert_iterator를 사용해야 합니다.

03 제거 알고리즘
'원소를 수정하는 알고리즘'의 특수한 형태.
원소를 실제로 제거하지 않고 논리적으로 제거(다음 원소로 덮어쓰기)하기 때문에 순차열의 size는 실제로는 변경하지 않음.
실제 size를 변경하려면 컨테이너의 erase()멤버 함수를 이용하면 됩니다.

p = remove(b, e, x)                     //구간 [b, e)의 순차열을 x원소가 남지 않도록 덮어쓰기로 이동한다.
                                          알고리즘 수행 후 순차열은 [b, p)가 된다.
p = remove(b, e, f)                     //구간 [b, e)의 순차열을 f(*p)가 참인 원소가 남지 않도록 덮어쓰기로
                                          이동한다. 알고리즘 수행 후 순차열은 [b, p)가 된다.
p = remove_copy(b, e, t, x)             //구간 [b, e)의 순차열에서 *p==x가 아닌 원소만 순차열 [t, p)에 복사.
p = remove_copy_if(b, e, t, f)          //구간 [b, e)의 순차열에서 f(*p)가 참이 아닌 원소만 순차열 [t, p)에 복사.
p = unique(b, e)                        //구간 [b, e)의 순차열을 인접한 중복 원소(값이 같은 원소:==)가 남지
                                          않게 덮어쓰기로 이동한다. 알고리즘 수행 후 순차열은 [b, p)가 된다.
p = unique(b, e, f)                     //구간 [b, e)의 순차열을 f(*p)가 참인 인접한 중복 원소가 남지 않게
                                          덮어쓰기로 이동한다. 알고리즘 수행 후 순차열은 [b, p)가 된다.
p = unique_copy(b, e, t)                //구간 [b, e)의 순차열에서 인접한 중복 원소(값이 같은 원소:==)가 아닌
                                          원소를 순차열 [t, p)에 복사한다.
p = unique_copy(b, e, t, f)             //구간 [b, e)의 순차열에서 f(*p)가 참인 인접한 중복 원소가 아닌
                                          원소를 순차열 [t, p)에 복사한다.

p = remove(b, e, x)는 구간 [b, e)의 순차열에서 x인 원소가 남지 않게 합니다.
이 때 remove는 실제 원소를 제거하지 않습니다.
단지 다음 원소를 앞으로 이동합니다.
size에는 변동이 없으며 remove()알고리즘 후의 순차열은 [b, p)가 됩니다.
8_41.cpp remove()알고리즘
iter_end = remove(v.begin(), v.end(), 30):구간 [v.begin(), v.end())의 순차열에서 30원소를 남지 않게 합니다.
알고리즘 수행 후의 순차열은 [v.begin(), iter_end)가 됩니다.
remove()알고리즘 수행 후 v의 size는 5라는 것을 알 수 있습니다.
또한, iter_end가 remove()알고리즘을 수행한 후의 끝 반복자이므로 결과 순차열을 [v.begin(), iter_end)가 됩니다.
                 덮어쓰기                                              iter_end
                 ┌─┐┌─┐             제거 후                               ↓
v size:5 |10|20|30|40|50| N|        ----->      v size:5 |10|20|40|50|50| N|
remove()알고리즘은 순차열의 원소를 논리적으로 제거할 뿐 실제 제거하지는 않습니다.
만약 실제 컨테이너의 size까지 변경하려면 컨테이너의 erase()멤버 함수를 사용합니다.
8_42.cpp remove() 후의 erase()멤버 함수 사용
v.erase(iter_end, v.end()):구간 [iter_end, v.end())의 원소를 v에서 제거합니다.
실제 size는 4가 됩니다.
                  덮어쓰기
                 ┌─┐┌────┐       remove() 후
v size:6 |10|20|30|40|30|50| N|     ----->
       v.begin()   iter_end
          ↓           ↓           erase() 후
v size:6 |10|20|40|50|30|50| N|     ----->


v size:4 |10|20|40|50| N|
조건에 따라 원소를 제거하고자 한다면 조건자 remove_if()알고리즘을 사용합니다.
p = remove_if(b, e, f)는 구간 [b, e)의 순차열에서 f(*p)가 참인 원소를 논리적으로 제거합니다.
제거 후의 순차열은 [b, p)가 됩니다.
8_43.cpp remove_if() 알고리즘
iter_end = remove_if(v.begin(), v.end(), Pred):구간 [v.begin(), v.end())의 순차열에서 Pred(*q)가 참인 원소를
논리적으로 제거합니다.
remove_if()알고리즘 수행 후의 순차열은 [v.begin(), iter_end)입니다.
여기서는 size는 변경하지 않으므로 실제로 제거하려면 erase()멤버 함수를 사용해야 합니다.

순차열의 원본을 변경하지 않고 특정 원소를 제거하여 목적지 순차열로 복사하고자 한다면 remove_copy()알고리즘 사용.
p = remove_copy(b, e, t, x)는 구간 [b, e) 순차열에서 *p == x인 원소를 제외한 원소를 순차열 [t, p)에 복사합니다.
원소 복사는 당연히 덮어쓰기 모드로 동작합니다.
8_44.cpp remove_copy() 알고리즘
iter_end = remove_copy(v1.begin(), v1.end(), v2.begin(), 30):구간 [v1.begin(), v1.end())의 순차열에서
30원소를 제외한 모든 원소를 목적지 순차열 [v2.begin(), iter_end))에 복사합니다.
remove_copy_if() 알고리즘은 조건자 버전으로 조건자가 참이 아닌 우너소만 목적지 순차열에 복사합니다.

순차열의 인접 원소를 유일하게 만들고자 한다면 unique()알고리즘을 사용합니다.
p = unique(b, e)는 구간 [b, e)의 순차열을 인접한 중복 원소가 남지 않게 합니다.
알고리즘 수행 후 순차열은 [b, p)가 됩니다.
remove()알고리즘처럼 unique()알고리즘도 원소를 논리적으로만 제거합니다.
정렬한 상태에서 unique()알고리즘을 수행한다면 모든 원소를 유일하게 만들 수 있습니다.
8_45.cpp unique()알고리즘
unique()알고리즘에서 주의할 점은 인접한 중복 원소를 제거하기 때문에 결과에서 인접하지 않는 중복 원소는
남게 된다는 사실입니다.
중복 원소도 제거하려면 정렬 후 unique()알고리즘을 수행하면 됩니다.
또한, remove()알고리즘처럼 중복 원소를 논리적으로 제거합니다.
                  인접 중복                                                  iter_end
                 ┌─┐   ┌─┐              unique()                               ↓
v size:8 |10|20|30|30|40|40|30|50| N|    ----->    v size:8 |10|20|30|40|30|50|30|50| N|
사용자 조건에 따라 중복 인접 원소를 제거하려면 조건자 버전 unique()알고리즘을 사용합니다.
p = unique(b, e, f)알고리즘은 구간 [b, e)의 반복자를 p라 하면 f(*p)가 참인 인접한 원소를 논리적으로 제거합니다.
알고리즘 수행 후의 순차열은 [b, p)가 됩니다.
8_46.cpp 조건자 버전 unique() 알고리즘
인접 원소의 차가 10이하라면 덮어쓰기로 원소를 이동합니다.
remove()알고리즘처럼 논리적으로 원소가 제거되므로 size의 변화는 없습니다.
               이동
               ┌──┐
v size:6 | 10| 11| 30| 32| 40| 50|  N|
            └ 1┘:인접 중복
			         이동
			       ┌──────┐
v size:6 | 10| 30| 30| 32| 40| 50|  N|
			    └──── 2┘:인접 중복
					     이동
				       ┌──────┐
v size:6 | 10| 30| 40| 32| 40| 50|  N|
						iter_end
					       ↓
v size:6 | 10| 30| 40| 50| 40| 50|  N|
unique_copy()알고리즘과 조건자 버전 unique_copy()알고리즘은 인접한 중복 원소를 제거하여 목적지
순차열로 복사할 뿐이고 사용 방법이 같습니다.

04 변경 알고리즘
순차열의 원소를 서로 교환하거나 이동하영 순차열 원소의 '순서'를 변경하는 알고리즘입니다.

bool = next_permutation(b, e)           //구간 [b, e)의 순차열을 사전순 다음 순열이 되게 한다. 
                                          더 이상 다음 순열이 없는 마지막 순열이라면 bool은 false이다.
bool = next_permutation(b, e, f)        //구간 [b, e)의 순차열을 사전순 다음 순열이 되게 한다. 비교에 f를 사용.
										  더 이상 다음 순열이 없는 마지막 순열이라면 bool은 false이다.
bool = prev_permutation(b, e)           //구간 [b, e)의 순차열을 사전순 이전 순열이 되게 한다.
                                          더 이상 이전 순열이 없는 첫 순열이라면 bool은 false이다.
bool = prev_permutation(b, e, f)        //구간 [b, e)의 순차열을 사전순 이전 순열이 되게 한다. 비교에 f를 사용.
										  더 이상 이전 순열이 없는 첫 순열이라면 bool은 false이다.
p = partition(b, e, f)                  //구간 [b, e)의 순차열 중 f(*p)가 참인 원소는 [b, p)의 순차열에
                                          거짓인 원소는 [p, e)의 순차열로 분류한다.
random_shuffle(b, e)                    //구간 [b, e)의 순차열을 랜덤(기본 랜덤기)으로 뒤섞는다.
random_shuffle(b, e, f)                 //구간 [b, e)의 순차열을 f를 랜덤기로 사용하여 뒤섞는다.
reverse(b, e)                           //구간 [b, e)의 순차열을 뒤집는다.
p = reverse_copy(b, e, t)               //구간 [b, e)의 순차열을 뒤집어 목적지 순차열 [t, p)에 복사한다.
rotate(b, m, e)                         //구간 [b, e)의 순차열을 왼쪽으로 회전시킨다. 첫 원소와 마지막
                                          원소가 연결된 것처럼 모든 원소가 왼쪽으로 (m-b)만큼씩 이동한다.
p = rotate_copy(b, m, e, t)             //구간 [b, e)의 순차열을 회전하여 목적지 순차열 [t, p)에 복사한다.
stable_partition(b, e, f)               //partition() 알고리즘과 같고 원소의 상대적인 순서를 유지한다.

원소의 순서를 변경하는 알고리즘입니다.
원소의 순서를 순열처럼 변경할 때 next_permutation()과 prev_permutation()알고리즘을 사용합니다.
next_permutation(b, e)는 구간 [b, e)의 순차열을 다음 순열(사전순)의 순차열이 되게 합니다.
마지막 순열이라면 false를 반환하며 아니면 true를 반환합니다.
8_47.cpp next_permutation() 알고리즘
순차열 v는 원소가 10,20,30인 3개의 원소로 6가지의 순열을 만들어냅니다.
순열은 10,20,30 -> 10,30,20 -> 20,10,30 -> 20,30,10 -> 30,10,20 -> 30,20,10입니다.
30,20,10순열이 마지막 순열이므로 next_permutation() 알고리즘은 false를 반환합니다.
v    |10|20|30| N| 사전순 첫 순열
v    |10|30|20| N|
v    |20|10|30| N|
v    |20|30|10| N|
v    |30|10|20| N|
v    |30|20|10| N| 사전순 마지막 순열
사용자 조건으로 순열을 생성하려면 next_permutation()알고리즘을 사용합니다.
next_permutation(b, e, f)는 구간 [b, e)의 순차열을 다음 순열의 순차열이 되게 합니다.
f는 이항 조건자이며 순열을 만드는 기준이 됩니다.
8_48.cpp 조건자 버전 next_permutation() 알고리즘
v의 순차열은 Point원소가 (5,1)(7,2)(5,3) 3개로 Point의 y값을 기준으로 6개의 순열을 만들어 냅니다.
(5,3)(7,2)(5,1)이 마지막 순열이므로 next_permutation()알고리즘은 false를 반환합니다.
prev_permutation()알고리즘의 사용법은 순차열의 이전 순열을 만들어내며 첫 순열일 때 false를 반환할 뿐.

순차열의 원소를 특정 조건에 따라 분류하고자 한다면 partition()알고리즘을 사용합니다.
p = partition(b, e, f)알고리즘은 구간 [b, e)의 반복자가 p일 때 f(*p)가 참인 원소는 [b, p)의 순차열에
거짓인 원소는 [p, e)의 순차열로 분류합니다.
f는 단항 조건자입니다.
8_49.cpp partition() 알고리즘
iter_sep = partition(v.begin(), v.end(), Pred):구간 [v.begin(), v.end())의 순차열을 Pred(*p)가 참인(40미만)
원소는 [v.begin(), iter_sep) 순차열에 거짓(40이상)인 원소는 [iter_sep, v.end())의 순차열로 분류합니다.
partition()알고리즘은 퀵소트에서 pivot값을 기준으로 큰 값과 작은 값을 분류하듯 f(*p)값을 기준으로 참인
원소와 거짓인 원소를 분류합니다.
             p1       p2
          -->↓        ↓<--
v size:6 |30|40|50|10|20|60| N|
              └──교환──┘
			   p1  p2
		     -->↓   ↓<--
v size:6 |30|20|50|10|40|60| N|
			    └교환┘
			      p1 
			       ↓
v size:6 |30|20|10|50|40|60| N|
				   ↑
				iter_sep
순차열의 원소를 특정 기준으로 분류하되 원소의 상대적인 순서는 변경하지 않게 하려면 stable_partition()알고리즘.
stable_partition()알고리즘이 partition()과 다른 점은 원소의 상대적인 순서를 유지한다는 것.
그래서 성능은 조금 떨어지지만 원소의 상대적인 순서를 유지하며 원소를 분류해야 한다면 stable_partition()알고리즘.
8_50.cpp stable_partition()알고리즘
단지 stable_partition()알고리즘은 원소의 상대적인 순서가 유지되어 결과가 partition()과 다르다.
v의 원 순차열이 30,40,50,10,20,60이므로 40미만의 원소는 30원소 다음에 10이 있고 10원소 다음에 20이 있으므로
원소의 상대적인 순서가 유지되며 40이상의 원소는 40원소 다음에 50이 있고, 50원소 다음에 60이 있으므로
이 상대적인 순서를 유지하며 원소를 분류합니다.
대부분의 stable_partition()알고리즘이 버퍼(buffer)를 사용하여 구현됩니다.
			 p1     p2
		  -->↓   -->↓
v size:6 |30|40|50|10|20|60| N|
			  └교환┘
			   p1      p2
			 -->↓   -->↓
v size:6 |30|10|50|40|20|60| N|
				└─교환─┘
				  p1
				   ↓
v size:6 |30|10|20|40|50|60| N|
				   ↑
				iter_sep

순차열 원소의 순서를 랜덤으로 뒤섞고자 한다면 random_shuffle()알고리즘을 사용합니다.
random_shuffle(b, e)알고리즘은 구간 [b, e)의 순차열을 랜덤으로 뒤섞습니다.
초기화는 <cstdlib>헤더의 srand()를 사용합니다.
8_51.cpp random_shuffle()알고리즘
실행 결과가 같게 나오는 것은 기본 랜덤기의 시작값(seed)이 srand(1)이기 때문입니다.
출력 결과를 바꾸고 싶다면 srand()를 이용합니다.
사용자 랜덤기를 사용하여 랜덤으로 순차열을 뒤섞고자 한다면 함수류 버전 random_shuffle()알고리즘을 사용.
random_shuffle(b, e, f)알고리즘은 기본 랜덤ㅁ기 대신 사용자 랜덤기 f를 사용합니다.

reverse()알고리즘을 사용하면 순차열을 뒤집을 수 있습니다.
reverse(b, e)알고리즘은 구간 [b, e)의 순차열을 역순으로 뒤집습니다.
8_52.cpp reverse() 알고리즘
reverse(v.begin(), v.end()):구간 [v.begin(), v.end())의 순차열을 역순으로 뒤집습니다.
뒤집힌 순차열을 목적지 순차열로 복사하고자 한다면 reverse_copy()알고리즘을 사용합니다.
p = reverse_copy(b, e, t)는 구간 [b, e)의 순차열을 뒤집어 목적지 순차열 [t, p)에 저장합니다.
8_53.cpp reverse_copy()알고리즘
목적지 순차열 v2에 복사할 때 덮어쓰기 모드로 동작하므로 v2는 v1의 원소 이상의 size를 가져야 합니다.

순차열을 회전시키려면 rotate() 알고리즘을 사용합니다.
rotate(b, m, e) 알고리즘은 첫 원소와 마지막 원소가 연결된 것처럼 왼쪽으로 m-e만큼씩 회전합니다.
8_54.cpp rotate() 알고리즘
rotate(v.begin(), middle, v.end()):구간 [v.begin(), v.end())의 순차열을 왼쪽으로 middle-v.begin()만큼(2)
회전합니다.
 v.begin() middle   v.end()
       ↓     ↓        ↓
v     |10|20|30|40|50| N|
1회전 |20|30|40|50|10| N|
2회전 |30|40|50|10|20| N|
순차열을 회전하여 목적지 순차열에 복사하려면 rotate_copy()알고리즘을 사용합니다.
p = rotate_copy(b, m, e, t)알고리즘은 구간 [b, e)의 순차열을 회전(m-b만큼)하여 목적지 순차열 [t, p)에 저장.
8_55.cpp rotate_copy()알고리즘
iter_end = rotate_copy(v1.begin(), middle, v1.end(), v2.begin()):구간 [v1.begin(), v1.end())의 순차열을
middle-v1.begin()만큼(2) 왼쪽으로 회전하여 목적지 순차열 [v2.begin(), iter_end)에 복사합니다.

05 정렬 알고리즘
'변경 알고리즘'의 특수한 형태로 특정 정렬 기준으로 원소의 순서를 변경하며 정렬합니다.

p = partition(b, e, f)                  //구간 [b, e)의 순차열 중 f(*p)가 참인 원소는 [b, p)의 순차열에
                                          거짓인 원소는 [p, e)의 순차열로 분류한다.
stable_partition(b, e, f)               //partition() 알고리즘과 같고 원소의 상대적인 순서를 유지한다.
make_heap(b, e)                         //힙을 생성한다. 구간 [b, e)의 순차열을 힙 구조로 변경한다.
make_heap(b, e, f)                      //힙을 생성한다. 구간 [b, e)의 순차열을 힙 구조로 변경한다.
                                          f는 조건자로 비교에 사용한다.
push_heap(b, e)                         //힙에 원소를 추가한다. 보통 push_back() 멤버 함수와 같이 사용되며,
                                          구간 [b, e)의 순차열을 다시 힙 구조가 되게 한다.
push_heap(b, e, f)                      //힙에 원소를 추가한다. 보통 push_back() 멤버 함수와 같이 사용되며,
										  구간 [b, e)의 순차열을 다시 힙 구조가 되게 한다. f는 조건자로
										  비교에 사용한다.
pop_heap(b, e)                          //힙에서 원소를 제거한다. 구간 [b, e) 순차열의 가장 큰 원소(첫)를 제거.
pop_heap(b, e, f)                       //힙에서 원소를 제거한다. 구간 [b, e) 순차열의 가장 큰 원소(첫)를 제거.
                                          f는 조건자로 비교에 사용한다.
sort_heap(b, e)                         //힙을 정렬한다. 구간 [b, e)의 순차열을 힙 구조를 이용해 정렬한다.
sort_heap(b, e, f)                      //힙을 정렬한다. 구간 [b, e)의 순차열을 힙 구조를 이용해 정렬한다.
                                          f는 조건자로 비교에 사용한다.
nth_element(b, m, e)                    //구간 [b, e)의 원소 중 m-b개 만큼 선별된 원소를 [b, m) 순차열에 
                                          놓이게 한다.
nth_element(b, m, e, f)                 //구간 [b, e)의 원소 중 m-b개 만큼 선별된 원소를 [b, m) 순차열에
										  놓이게 한다. f는 조건자로 비교에 사용한다.
sort(b, e)                              //퀵 정렬을 기반으로 정렬한다. 구간 [b, e)를 정렬한다.
sort(b, e)                              //퀵 정렬을 기반으로 정렬한다. 구간 [b, e)를 조건자 f를 사용해 정렬.
stable_sort(b, e)                       //머지 정렬을 기반으로 정렬한다. 구간 [b, e)를 정렬하되 값이 같은 원소의
                                          상대적인 순서를 유지한다.
stable_sort(b, e, f)                    //머지 정렬을 기반으로 정렬한다. 구간 [b, e)를 정렬하되 값이 같은 원소의
                                          상대적인 순서를 유지한다. f는 조건자로 비교에 사용한다.
partial_sort(b, m, e)                   //힙 정렬을 기반으로 정렬한다. 구간 [b, e)의 원소 중 m-b개 만큼의 상위
                                          원소를 정렬하여 [b, m) 순차열에 놓는다.
partial_sort(b, m, e, f)                //힙 정렬을 기반으로 정렬한다. 구간 [b, e)의 원소 중 m-b개 만큼의 상위
										  원소를 정렬하여 [b, m) 순차열에 놓는다. f는 조건자로 비교에 사용.
partial_sort_copy(b, e, b2, e2)         //힙 정렬을 기반으로 정렬한다. 구간 [b, e)의 원소 중 상위 e2-b2개의
                                          원소 정도만 정렬하여 [b2, e2)로 복사한다.
partial_sort_copy(b, e, b2, e2, f)      //힙 정렬을 기반으로 정렬한다. 구간 [b, e)의 원소 중 상위 e2-b2개의
										  원소 정도만 정렬하여 [b2, e2)로 복사한다. f는 조건자로 비교에 사용.

정렬 알고리즘은 힙 관련 알고리즘으로 시작합니다.
힙 관련 알고리즘은 make_heap(), push_heap(), pop_heap(), sort_heap()이 있습니다.
이 알고리즘을 이해하려면 힙 자료구조를 알고 있어야 합니다.
자료구조 힙은 '트리 내의 모든 원소가 부모 노드보다 큰 값(혹은 작은 값)을 갖는 완전 이진 트리'라 정의됩니다.
그러므로 힙에서 루트(root)노드는 항상 가장 작은 값(혹은 가장 큰 값)을 갖습니다.
또한, 힙의 연산은 크게 두 가지 추가와 제거 연산입니다.
추가 연산은 완전 이진 트리 가장 끝에 원소를 추가한 후 힙의 규칙을 깨지 않게 힙을 유지하며 삭제는 힙의 규칙을 
깨지 않고 루트를 제거합니다.
항상 루트 노드가 가장 작은 값(혹은 가장 큰 값)이기 때문에 힙은 우선순위 큐나 정렬 등의 알고리즘에 유용하게
사용되는 자료구조 입니다.
순차열 순서: 0  1  2  3  4  5
        v1 |60|50|40|10|30|20| N|
	  0	60
	   1/\2
	  50  40
	 3/\4 /5
	10 30 20

make_heap(b, e)알고리즘은 구간 [b, e)의 순차열을 힙 구조로 만들어냅니다.
8_56.cpp make_heap() 알고리즘
[v.begin(), v.end())순차열의 첫 원소인 루트는 60으로 가장 큰 정수이며 모든 자식 노드는 부모 노드보다 작습니다.
순차열 순서: 0  1  2  3  4  5         힙구조    순차열 순서: 0  1  2  3  4  5
		v1 |10|20|30|40|50|60| N|    ----->            v1 |60|50|30|40|20|10| N|
		                                               	  0	60
														   1/\2
														  50  30
														 3/\4 /5
														40 20 10

push_heap(b, e)알고리즘은 구간 [b, e)의 힙에 원소를 추가하는 알고리즘입니다.
push_heap()알고리즘은 일반적으로 멤버 함수 push_back()과 함께 사용됩니다.
push_heap(b, e)알고리즘은 구간 [b, e)의 가장 마지막 원소를 부모 노드와 비교해가며 힙 연산을 수행하기 때문.
8_57.cpp push_heap()알고리즘
vector의 멤버 함수 push_back()을 사용하여 완전 이진 트리의 가장 끝에 원소를 추가합니다.
그리고 push_heap()알고리즘으로 힙 추가 연산을 수행하여 힙 구조를 유지합니다.
순차열 순서: 0  1  2  3  4  5
         v |60|50|30|40|20|10| N|
	  0	60
	   1/\2                             순차열에 35추가
	  50  30                             ---------->
	 3/\4 /5
	40 20 10
순차열 순서: 0  1  2  3  4  5  6
		 v |60|50|30|40|20|10|35| N|
	  0	60
	   1/\2                             push_heap() 알고리즘 힙 유지
	  50  30                             ---------->
	 3/\45/\6
	40 2010 35
순차열 순서: 0  1  2  3  4  5  6
		 v |60|50|35|40|20|10|30| N|
	  0	60
	   1/\2                             
	  50  35   ┐                          
	 3/\45/\6  | 부모 노드와 교환했다.
	40 2010 30 ┘
pop_heap()알고리즘은 힙에서 루트(가장 큰 원소)노드를 제거합니다.
pop_heap(b, e)알고리즘은 구간 [b, e)의 첫 원소(가장 큰 원소)를 가장 끝 원소와 교환한 후 힙이 유지되게 연산을 수행.
8_58.cpp pop_heap() 알고리즘
구간 [v.begin(), v.end())의 힙에서 루트(60)을 제거합니다(루트 원소가 가장 끝으로 이동했으며 나머지 원소는 힙 유지)
	  0	60                                  0 10
	   1/\2   1. 루트와 마지막 노드를 교환     1/\2       2. 자식 노드 중 큰 노드와 교환             
	  50  30             ----->             50  30                  ----->
	 3/\4 /5                               3/\4 /5
	40 20 10                              40 20 60

	  0	50    3. 힙 유지까지 반복.            0 5
	   1/\2    자식 노드 중 큰 노드와 교환     1/\2
	  10  30             ----->             40  30 
	 3/\4 /5                               3/\4 /5
	40 20 (60)                            10 20 (60)
순차열 순서: 0  1  2  3  4  5
		 v |50|40|30|10|20|60| N|

힙을 정렬하려면 sort_heap()알고리즘을 사용합니다.
8_59.cpp sort_heap()알고리즘
구간 [v.begin(), v.end())의 힙을 정렬합니다.
힙 알고리즘은 모두 힙 구조인(make_heap()으로 생성) 순차열에만 동작합니다.
make_heap(b, e, f), push_heap(b, e, f), pop_heap(b, e, f), sort_heap(b, e, f)알고리즘은 모두 조건자 버전
힙 알고리즘으로 f를 조건자로 사용하여 힙 연산을 수행합니다.
8_60.cpp 조건자 버전 힙 알고리즘
make_heap(v.begin(), v.end(), greater<int>()):[v.begin(), v.end()) 구간의 순차열에 greater<int>를 사용하여
힙을 생성합니다.
push_heap(v.begin(), v.end(), greater<int>()):[v.begin(), v.end()) 구간의 순차열에 greater<int>를 사용하여
힙 원소를 추가합니다.
sort_heap(v.begin(), v.end(), greater<int>()):[v.begin(), v.end()) 구간의 순차열에 greater<int>를 사용하여
내림차순 정렬을 수행합니다.

순차열의 원소 중 n개의 원소를 선별하고자 한다면 nth_element()알고리즘을 사용합니다.
nth_element(b, m, e)알고리즘은 구간 [b, e)의 원소 중 m-b개 만큼의 원소를 선별하여(사전순)[b, m)의 순차열에
놓이게 합니다.
8_61.cpp nth_element() 알고리즘
nth_element(v.begin(), v.begin()+20, v.end()):구간 [v.begin(), v.end())의 원소 중 상위 
20개(v.begin()+20)-v.begin())를 [v.begin(), v.begin()+20)의 순차열에 놓이게 합니다.
조건자 버전 nth_element(b, m, e, f) 알고리즘은 원소 비교에 f를 사용할 뿐이다.

순차열의 원소를 정렬하려면 sort()와 stable_sort(), partial_sort()알고리즘을 사용합니다.
sort()알고리즘은 퀵정렬을 기반으로 하며 stable_sort()알고리즘은 머지정렬을 기반으로 partial_sort()알고리즘은
힙정렬을 기반으로 합니다.
그래서 sort()알고리즘의 경우 평균적으로 O(Nlog2N)의 복잡도를 보장하며 최악의 경우 O(N2)의 복잡도를 가집니다.
stable_sort()알고리즘은 메모리만 넉넉하다면 O(Nlog2N)의 복잡도를 보장하면 그렇지 않다면 O(Nlog2Nlog2N)의 복잡도.
stable_sort()알고리즘은 머지정렬을 기반으로 하므로 같은 원소의 정렬에서 원소의 상대적인 순서가 유지됩니다.
parital_sort()알고리즘은 힙정렬을 기반으로하므로 언제든지 O(Nlog2N)의 복잡도를 보장합니다.
하지만, 일반적으로 매번 다운힙을 실행해야 하기 때문에 퀵정렬보다는 성능이 떨어집니다.
특징을 고려하여 순차열에 따라 적정한 알고리즘을 선택하여 정렬하면 됩니다.
8_62.cpp sort()알고리즘
sort(v.begin(), v.end()):구간 [v.begin(), v.end())의 순차열을 기본 정렬 규칙 less(오름차순)정렬합니다.
sort(v.begin(), v.end()), Greater):구간 [v.begin(), v.end())의 순차열을 Greater정렬 규칙을 사용하여
내림 차순 정렬합니다.
Greater는 비교에 사용될 이항 조건자입니다.
순차열을 정렬할 때 같은 원소의 상대적인 순서를 유지해야 한다면 stable_sort()알고리즘을 사용합니다.
stable_sort(b, e)알고리즘은 구간 [b, e)의 순차열을 정렬하며 같은 원소의 상대적인 순서를 유지합니다.
8_63.cpp stable_sort() 알고리즘
stable_sort(v.begin(), v.end()):구간 [v.begin(), v.end())의 순차열을 기본 정렬 규칙(less)을 사용해 정렬.
stable_sort(v.begin(), v.end(), Greater):구간 [v.begin(), v.end())의 순차열을 Greater 정렬 규칙(내림차순)으로
정렬합니다.
순차열의 같은 원소는 30과 40입니다.
이 때 앞쪽의 30을 30A라 하고 뒤쪽 30을 30B라 한다면 정렬될 때 항상 30A 30B 순으로 정렬돼 원소의 상대적인 순서가
유지됩니다.
                                        정렬 전 v |30A| 50|30B| 20|40A| 10|40B| N |
                stable_sort(v.begin(), v.end()) v | 10| 20|30A|30B|40A|40B| 50| N |
stable_sort(v.begin(), v.end(), greater<int>()) v | 50|40A|40B|30A|30B| 20| 10| N |
순차열의 상위 구간만을 정렬하거나 힙정렬의 특징이 필요하다면 partial_sort()알고리즘을 사용합니다.
partial_sort(b, m, e)알고리즘은 구간 [b, e)의 원소를 [b, m)의 순차열에 원소를 정렬합니다.
8_64.cpp partial_sort() 알고리즘
partial_sort(b, m, e)알고리즘에서 m을 e와 같게 한다면 순차열의 모든 원소를 정렬할 수 있습니다.
조건자 버전 partial_sort(b, m, e, f)알고리즘은 f를 정렬 규칙으로 사용한 정렬을 수행합니다.

순차열의 상위 구간만을 정렬하여 목적지 순차열로 복사하려면 partial_sort_copy()알고리즘을 사용합니다.
partial_sort_copy(b, e, b2, e2)알고리즘은 구간 [b, e)의 원소 e2-b2개의 상위 원소를 정렬하여 [b2, e2)의
순차열로 복사합니다.
조건자 버전은 f를 정렬 규칙에 사용합니다.
8_65.cpp partial_sort_copy() 알고리즘
partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end()):구간 [v1.begin(), v1.end())의 원소 중
상위 20개(v2.end()-v2.begin())를 정렬하여 [v2.begin(), v2.end())의 순차열로 복사합니다.
partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()):정렬 규칙만 greater<int>를
사용하여 내림차순으로 정렬합니다.

06 정렬된 범위 알고리즘
정렬된 구간에서만 동작하는 알고리즘입니다.
정렬된 범위 알고리즘은 입력 순차열이 반드시 정렬돼 있어야 합니다.
또한, 원소가 같음을 비교할 때 연관 컨테이너처럼 두 원소 a, b에 대해 a==b연산(equality)을 사용하지 않고
!(a<b) && !(b<a) 연산(equivalence)를 사용합니다.

binary_search(b, e, x)                  //구간 [b, e)의 순차열에 x와 같은 원소가 있는가?
binary_search(b, e, x, f)               //구간 [b, e)의 순차열에 x와 같은 원소가 있는가? f를 비교에 사용.
includes(b, e, ,b2, e2)                 //구간 [b2, e2)의 모든 원소가 구간 [b, e)에도 있는가?
includes(b, e, ,b2, e2, f)              //구간 [b2, e2)의 모든 원소가 구간 [b, e)에도 있는가? f를 비교에 사용.
p = lower_bound(b, e, x)                //p는 구간 [b, e)의 순차열에서 x와 같은 첫 원소의 반복자다.
p = lower_bound(b, e, x, f)             //p는 구간 [b, e)의 순차열에서 x와 같은 첫 원소의 반복자다. 
                                          f를 비교에 사용.
p = upper_bound(b, e, x)                //p는 구간 [b, e)의 순차열에서 x보다 큰 첫 원소의 반복자다.
p = upper_bound(b, e, x, f)             //p는 구간 [b, e)의 순차열에서 x보다 큰 첫 원소의 반복자다.
									      f를 비교에 사용.
pair(p1, p2) = equal_range(b, e, x)     //구간 [p1, p2)의 순차열은 구간 [b, e)의 순차열에서 x와 같은 원소의
                                          구간(순차열)이다. [lower_bound(), upper_bound())의 순차열과 같다.
pair(p1, p2) = equal_range(b, e, x, f)  //구간 [p1, p2)의 순차열은 구간 [b, e)의 순차열에서 x와 같은 원소의
										  구간(순차열)이다. [lower_bound(), upper_bound())의 순차열과 같다.
										  f를 비교에 사용.
p = merge(b, e, b2, e2, t)              //구간 [b, e)의 순차열과 구간 [b2, e2)의 순차열을 합병해 [t, p)에 저장.
p = merge(b, e, b2, e2, t, f)           //구간 [b, e)의 순차열과 구간 [b2, e2)의 순차열을 합병해 [t, p)에 저장.
                                          f를 비교에 사용.
inplace_merge(b, m, e)                  //정렬된 [b, m) 순차열과 [m, e) 순차열을 [b, e)순차열로 합병한다.
inplace_merge(b, m, e, f)               //정렬된 [b, m) 순차열과 [m, e) 순차열을 [b, e)순차열로 합병한다.
                                          f를 비교에 사용.
p = set_union(b, e, b2, e2, t)          //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 합집합으로 [t, p)에
                                          저장.
p = set_union(b, e, b2, e2, t, f)       //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 합집합으로 [t, p)에
										  저장. f를 비교에 사용.
p = set_intersction(b, e, b2, e2, t)    //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 교집합으로 [t, p)에
                                          저장.
p = set_intersction(b, e, b2, e2, t, f) //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 교집합으로 [t, p)에
										  저장. f를 비교에 사용한다.
p = set_difference(b, e, b2, e2, t)     //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 차집합으로 [t, p)에
                                          저장.
p = set_difference(b, e, b2, e2, t, f)  //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 차집합으로 [t, p)에
										  저장. f를 비교에 사용한다.
p = set_symmetric_difference(b, e, b2, e2, t)
                                        //구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 대칭 차집합으로
										  [t, p)에 저장한다.
p = set_symmetric_difference(b, e, b2, e2, t, f)
										//구간 [b, e)의 순차열과 [b2, e2)의 순차열을 정렬된 대칭 차집합으로
										  [t, p)에 저장한다. f를 비교에 사용한다.

binary_search(b, e, x)는 구간 [b, e)의 순차열에서 x와 같은 원소가 있으면 true를 반환하고 없으면 false반환.
8_66.cpp binary_search() 알고리즘
binary_seach()알고리즘은 순차열의 원소가 기본 정렬 기준인 less(<)로 정렬돼 있다는 전제 하에 동작합니다.
정렬된 범위 알고리즘은 정렬된 순차열에서만 동작하며 정렬은 원소의 순서가 아주 중요합니다.
'정렬'은 특정 정렬 기준에 따라 원소에 순서가 있다는 의미.
기본 정렬 기준은 <연산인 조건자 less(오름차순 정렬)입니다.
binary_search()알고리즘은 원소를 찾기 위해 두 원소 a, b에 대해 a==b 연산을 사용하지 않고 !(a<b) && !(b<a)연산을
사용합니다.
!(a<b) && !(b<a)연산은 'a도 b보다 앞서 위치하지 않고 b도 a보다 앞서 위치하지 않으면 같은 원소로 판단한다'
binary_search(b, e, x, f)는 구간 [b, e)의 원소 중 x원소와 같은 원소가 있다면 true, 아니면 false를 반환.
f는 비교(정렬 기준)에 사용되는 이항 조건자입니다.
8_67.cpp 조건자 버전 binary_search() 알고리즘
정렬기준 Pred에 따라 12은 10의 다음 원소가 아니기 때문에 12가 10보다 앞에 놓인다.
검색에서 32의 검색은 같음 연산 !Pred(30, 32) && !Pred(32, 30)이 true이므로 30과 같은 순차열에 있는 원소.
35는 !Pred(*p, 35) && !Pred(35, *p)의 연산이 true인 원소가 없으므로 순차열에 같은 원소가 없습니다.
원본의 순차열
v    |40|46|12|80|10|47|30|55|90|53| N|
sort() 두 원소의 차가 3보다 크면 다음 원소로 정렬
v    |12|10|30|40|46|47|55|53|80|90| N|
      ───── ── ── ───── ───── ── ──
binary_search() 두 원소의 차가 3이하면 같은 원소
v    |12|10|30|40|46|47|55|53|80|90| N|
      ───── ── ── ───── ───── ── ──
	        ↑
!Pred(30,32) && !Pred(32,30) = 30과 32가 서로 앞서 있지 않다. true(32가 있음)

정렬된 범위 알고리즘은 정렬된 순차열에서 동작하므로 모든 알고리즘이 조건자 버전의 알고리즘이 제공되며 정렬 기준과
동일한 조건자를 지정해야 알고리즘이 올바르게 동작합니다.
8_68.cpp binary_search() 알고리즘의 조건자
less로 정렬된 순차열은 binary_search()알고리즘의 조건자를 less로 지정하고 greater로 정렬된 순차열은
binary_search()알고리즘의 조건자를 greater로 지정합니다.

한 순차열의 다른 순차열의 부분 집합인지 판단하려면 includes() 알고리즘을 사용합니다.
includes(b, e, b2, e2)알고리즘은 구간 [b2, e2)의 원소가 구간 [b, e)의 원소에 포함되면(부분집합) true,
아니면 false입니다.
조건자 버전은 f를 비교에 사용합니다.
8_69.cpp includes() 알고리즘
v2의 모든 원소가 v1에 포함되므로 includes()는 true를 반환합니다.
v3의 원소 60이 v1에 포함되지 않으므로 includes()는 false를 반환합니다.
정렬 기준이 기본 정렬 기준 less가 아니라면 조건자 버전 includes()조건자로 비교 기준을 설정해야 합니다.
v1─────────────┐                 ┌────────────v2
│ v2─────────┐ │      v1─────────┼───────┐    │
│ │ 10 20 40 │ │      │ 30 40 50 │ 10 20 │ 60 │
│ └──────────┘ │      └──────────┼───────┘    │
│ 30 50        │                 └────────────┘
└──────────────┘
      true                      false

순차열에서 같은 원소를 찾기 위해 연관 컨테이너의 lower_bound(), upper_bound()멤버 함수와 비슷한 알고리즘이
필요하다면 lower_bound(), upper_bound()알고리즘을 사용합니다.
p = lower_bound(b, e, x)는 구간 [b, e)의 순차열에서 x원소와 같은 첫 원소의 반복자(p)를 반환합니다.
p = upper_bound(b, e, x)는 구간 [b, e)의 순차열에서 x원소와 같은 마지막 원소의 다음 원소(x보다 큰 첫 원소)의
반복자(p)를 반환합니다.
8_70.cpp lower_bound(), upper_bound() 알고리즘
v순차열에 30원소가 3개이며 30의 시작원소는 iter_lower가 30의 다음 원소는 iter_upper가 가리킵니다.
       iter_lower iter_upper
            ↓        ↓
v    |10|20|30|30|30|40|50| N|
            ────────
[iter_lower, iter_upper)순차열:30 30 30
원소를 찾고자하는 순차열이 기본 정렬 기준 less가 아니라면 조건자 버전의 lower_bound(), upper_bound()알고리즘을
사용합니다.

순차열에서 찾은 원소의 반복자 쌍(구간)을 얻고자 한다면 equal_range()알고리즘을 사용합니다.
pair(p1, p2) = equal_range(b, e, x)는 구간 [b, e)의 순차열에서 x와 같은 원소의 반복자 쌍(p1, p2)을 반환합니다.
8_71.cpp equal_range() 알고리즘
결과는 lower_bound(), upper_bound()알고리즘과 같지만 equal_range()알고리즘은 찾은 원소의 반복자 쌍을 반환.
             iter_pair
          first    second
            ↓        ↓  
v    |10|20|30|30|30|40|50| N|
[iter_pair.first, iter_pair.second)순차열:30 30 30

정렬된 두 순차열을 하나의 순차열로 합병하려면 merge()알고리즘을 사용합니다.
p = merge(b, e, b2, e2, t)알고리즘은 구간 [b, e)의 순차열과 구간 [b2, e2)의 순차열을 목적지 순차열 [t, p)로 합병.
8_72.cpp merge() 알고리즘
[v1.begin(), v1.end())의 순차열과 [v2.begin(), v2.end())의 순차열을 [v3.begin(), iter_end)의 순차열로 합병.
원본의 순차열
v3    | 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| N|
merge()
     v3.begin()             iter_end
       ↓                       ↓
v3    |10|20|20|30|30|40|50|60| 0| 0| N|

하나의 순차열이 두 구간으로 정렬돼 있다면 inplace_merge()알고리즘을 사용하여 하나의 구간으로 정렬할 수 있다.
inplace_merge(b, m, e)알고리즘은 정렬된 [b, m)의 순차열과 정렬된 [m, e)의 순차열을 정렬된 [b, e)순차열로 합병.
8_73.cpp inplace_merge() 알고리즘

정렬된 두 순차열의 합집합을 구하려면 set_union()을 사용합니다.
p = set_union(b, e, b2, e2, t)알고리즘은 구간 [b, e)와 구간 [b2, e2)의 순차열을 합집합하여 목적지 순차열 [t, p)에
저장합니다.
8_74.cpp set_union() 알고리즘
[v1.begin(), v1.end())의 순차열과 [v2.begin(), v2.end())의 순차열을 [v3.begin(), iter_end)의 순차열로
합집합하여 저장합니다.
v1───────────────┐        v2─────────┐
│ 10 20 30 40 50 │   U    │ 20 30 60 │
└────────────────┘        └──────────┘  
v3──────────────────┐ 
│ 10 20 30 40 50 60 │ 
└───────────────────┘
 v3.begin()        iter_end
    ↓                 ↓
v3 |10|20|30|40|50|60| 0| 0| 0| 0| N|

정렬된 두 순차열의 교집합을 구하려면 set_intersection()을 사용합니다.
p = set_intersection(b, e, b2, e2, t)알고리즘은 구간 [b, e)와 구간 [b2, e2)의 순차열을 교집합하여 목적지
순차열 [t, p)에 저장합니다.
정렬된 두 순차열의 차집합을 구하려면 set_difference()을 사용합니다.
또한, 정렬된 두 순차열의 대칭 차집합을 구하려면 set_symmetric_difference()알고리즘을 사용합니다.
8_75.cpp set_intersection(), set_difference(), set_symmetric_difference()알고리즘
v1과 v2의 교집합은 20,30이며 차집합은 10,40,50입니다.
v1과 v2의 대칭차집합은 10,40,50,60입니다.
이 원소를 [v3.begin(), iter_end)순차열에 저장합니다.
           ┌────────────v2
v1─────────┼───────┐    │
│ 10 40 50 │ 20 30 │ 60 │
└──────────┼───────┘    │
           └────────────┘
 v1∪v2         v1 - v2      (v1 - v2)∪(v2 - v1)
v3──────┐    v3─────────┐    v3────────────┐
│ 20 30 │    │ 10 40 50 │    │ 10 40 50 60 │
└───────┘    └──────────┘    └─────────────┘

07 수치 알고리즘
변경 알고리즘은 수치관련 원소를 다루는 알고리즘입니다.
수치 알고리즘은 다른 알고리즘과 달리 <numeric>헤더에 정의됩니다.

x2 = accumulate(b, e, x)                //x2는 x를 초깃값으로 시작한 구간 [b, e) 순차열 원소의 합이다.
x2 = accumulate(b, e, x, f)             //x2는 x를 초깃값으로 시작한 구간 [b, e) 순차열 원소의 누적이다.
                                          f를 누적에 사용한다.
x2 = inner_product(b, e, b2, x)         //x2는 x를 초깃값으로 시작한 구간 [b, e)와 구간 [b2, b2+e-b)의 내적
                                          (두 순차열의 곱의 합)이다.
x2 = inner_product(b, e, b2, x, f1, f2) //x2는 x를 초깃값으로 시작한 구간 [b, e)와 구간 [b2, b2+e-b)의 모든
                                          원소끼리 f2연산 후 f1연산으로 총 연산한 결과다.
p = adjacent_difference(b, e, t)        //구간 [b, e)의 인접 원소와의 차를 순차열 [t, p)에 저장한다.
p = adjacent_difference(b, e, t, f)     //구간 [b, e)의 인접 원소와의 연산을 순차열 [t, p)에 저장한다.
                                          f를 연산에 사용한다.
p = partial_sum(b, e, t)                //구간 [b, e)의 현재 원소까지의 합을 순차열 [t, p)에 저장한다.
p = partial_sum(b, e, t, f)             //구간 [b, e)의 현재 원소까지의 연산을 순차열 [t, p)에 저장한다.
                                          f를 연산에 사용한다.

순차열의 모든 원소를 누적하려면 for_each()나 transform()알고리즘을 사용할 수 있지만 누적값(상태값)을 기억하기 위해
함수자(functor)를 사용해야 하는 등 조금 복잡하다.
순차열의 모든 원소에 대해 누적을 구하거나 순서대로 원소에 연산을 적용해야 한다면 '수치 알고리즘'을 사용하여
좀 더 간단하게 처리할 수 있다.
순차열 모든 원소의 합을 구하려면 accumulate()알고리즘을 사용합니다.
accumulate(b, e, x)알고리즘은 x를 초깃값으로 한 구간 [b, e)의 모든 원소 합을 반환합니다.
8_76.cpp accumulate() 알고리즘
accumulate(v.begin(), v.end(), 0):0+10+20+30+40+50의 합을 반환합니다.
accumulate(v.begin(), v.end(), 100):100+10+20+30+40+50의 합을 반환합니다.
함수류 버전인 accumulate()알고리즘은 더 다양한 작업을 수행할 수 있습니다.
accumulate(b, e, x, f)알고리즘은 x를 초깃값으로 구간 [b, e)의 모든 원소를 f연산하여 반환합니다.
8_77.cpp 함수류 버전 accumulate() 알고리즘
accumulate(b, e, x, f)알고리즘의 f를 사용하면 순차열 모든 원소에 사용자가 정의한 연산을 수행할 수 있습니다.
f에 plus<int>()를 지정하면 모든 원소의 합을 출력하며 f에 multiplies<int>()를 지정하면 모든 원소의 곱을 출력.
클라이언트
int operator()(const int& left, const int& right) {
	return left + right;
}
void main() {
	accumulate(v.begin(), v.end(), 0, Plus<int>());
}
서버
Type accumulate(Iterator first, Iterator last, Type x, Function fun) {
	Type ret = x;
	for(Iterator p = first;p != last;++p)
		ret = fun(ret, *p);
	return ret;
}

두 순차열의 내적(모든 원소의 곱의 합)을 구하려면 inner_product()알고리즘을 사용합니다.
inner_product(b, e, b2, x)알고리즘은 x를 초깃값으로 구간 [b, e)의 원소와 구간 [b2, b2+e-b)의 원소내적을 반환.
8_78.cpp inner_product() 알고리즘
inner_prodect(v1.begin(), v1.end(), v2.begin(), 0):0을 초깃값으로 두 순차열의 내적 0 + 1*2 + 2*2 + 3*2 + 
4*2 + 5*2을 반환합니다.
inner_prodect(v1.begin(), v1.end(), v2.begin(), 100):100을 초깃값으로 두 순차열의 내적 100 + 1*2 + 2*2 + 3*2 +
4*2 + 5*2을 반환합니다.
함수류 버전의 inner_product()알고리즘을 사용하면 다양한 원소 간의 연산과 누적 연산을 수행할 수 있습니다.
inner_product(b, e, b2, x, f1, f2)알고리즘은 f1이 +연산이고 f2가 *연산이라면 구간 [b, e)의 원소 a1, a2, a3,
구간 [b2, b2+e-b)의 원소 b1, b2, b3에 대해 x + a1*b1 + a2*b2 + a3*b3입니다.
8_79.cpp 함수류 버전 inner_product() 알고리즘
inner_product(v1.begin(), v1.end(), v2.begin(), 0, Plus, Minus):0을 초깃값으로 이항함수 Plus, Minus를
사용하여 두 순차열의 연산을 수행합니다.
inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(), minus<int>()):0을 초깃값으로 STL이항 함수자
plus<int>(), minus<int>()을 사용하여 두 순차열의 연산을 수행합니다.
클라이언트
int Plus(int left, int right) {
	return left + right;
}
void main() {
	inner_product(v1.begin(), v1.end(), v2.begin(), 0, Plus, Minus);
}
서버
Type inner_product(Iter first, Iter last, Iter first2, Type x, Func1 fun1, Func2 fun2) {
	Type ret = x;
	for(Iter p = first, q = first2;p != last;++p, ++q)
		ret = fun1(ret, fun2(*p, *q));
	return ret;
}

순차열에서 원소 간의 차를 구하려면 adjacent_difference()알고리즘을 사용합니다.
p = adjacent_difference(b, e, t)알고리즘은 구간 [b, e)의 반복자가 p일 때 (*p - *(p-1))연산을 목적지
순차열 [t, p)에 저장합니다.
8_80.cpp adjacent_difference() 알고리즘
iter_end = adjacent_difference(v1.begin(), v1.end(), v2.begin()):구간 [v1.begin(), v1.end())순차열 인접
원소 간의 차를 목적지 순차열 [v2.begin(), iter_end)에 저장합니다.
            p-1 p
             ↓  ↓
v1 | 10| 20| 30| 40| 50|  N|
     |└10┘└10┘└10┘└10┘:*p-*(p-1)
	 ↓   ↘   ↘   ↘   ↘
v2 | 10| 10| 10| 10| 10|  N|
     ↑                   ↑
  v2.begin()         iter_end
순차열에서 인접 원소와의 사용자 정의 연산을 수행하려면 함수류 버전 adjacent_difference()알고리즘을 사용합니다.
p = adjacent_difference(b, e, t, f)알고리즘은 구간 [b, e)의 반복자가 p라면 f(*p, *(p-1))연산을 목적지
순차열 [t, p)에 저장합니다.
8_81.cpp 함수류 버전 adjacent_difference() 알고리즘
iter_end = adjacent_difference(v1.begin(), v1.end(), v2.begin(), Plus):구간 [v1.begin(), v1.end())의
인접 원소의 합(Plus(*p, *(p-1))을 목적지 순차열 [v2.begin(), iter_end)에 저장합니다.
			     p-1 p
			      ↓  ↓
v1 | 10| 20| 30| 40| 50|  N|
	 |└30┘└50┘└70┘└90┘:Plus(*p, *(p-1))
	 ↓   ↘   ↘   ↘   ↘
v2 | 10| 30| 50| 70| 90|  N|
	 ↑                   ↑
  v2.begin()         iter_end
클라이언트
int Plus(int left, int right) {
	return left + right;
}
void main() {
	adjacent_difference(v1.begin(), v1.end(), v2.begin(), Plus);
}
서버
Iter adjacent_difference(Iter first, Iter last, Iter target, Func fun) {
	*target++ = *first;
	for(Iter p = first + 1;p != last;++p)
		*target++ = fun(*p, *(p - 1));
	return target;
}

순차열에서 현재 원소까지의 합을 구하고자 한다면 partial_sum()알고리즘을 사용합니다.
p = partial_sum(b, e, t)알고리즘은 구간 [b, e)의 현재 원소까지의 합(누적)을 목적지 순차열 [t, p)에 저장합니다.
8_82.cpp partial_sum() 알고리즘
iter_end = partial_sum(v1.begin(), v1.end(), v2.begin()):구간 [v1.begin(), v1.end())의 각 원소까지의 합을
[v2.begin(), iter_end)에 저장합니다.
				     p
				     ↓
v1 | 10| 20| 30| 40| 50|  N|
	 10─┘30─┘60─┘100┘150:val+=*p
	 ↓   ↓   ↓   ↓    ↓  
v2 | 10| 30| 60|100|150|  N|
	 ↑                   ↑
  v2.begin()         iter_end
순차열에서 현재 원소까지의 합(누적)뿐만 아니라 사용자 연산을 수행하려면 함수류 버전의 partial_sum()알고리즘을 사용.
p = partial_sum(b, e, t, f)알고리즘은 구간 [b, e)의 현재 원소까지의 f연산의 값을 목적지 순차열 [t, p)에 저장.
8_83.cpp 함수류 버전 partial_sum 알고리즘
partial_sum(b, e, t, f)알고리즘의 f가 multiplies<int>()로 곱이기 때문에 v1의 원소 10을 v2[0]에 저장하고,
10*20을 v2[1]에, 10*20*30을 v2[2]에, 10*20*30*40을 v2[3]에, 10*20*30*40*50을 v2[4]에 저장합니다.
					       p
					       ↓
v1 | 10| 20|  30|    40|      50|  N|
	 10─┘200─┘6000─┘240000┘12000000:val*=*p
	 ↓   ↓    ↓      ↓       ↓
v2 | 10|200|6000|240000|12000000|  N|
	 ↑                            ↑
  v2.begin()                   iter_end
클라이언트
int Multi(int left, int right) {
	return left * right;
}
void main() {
	partial_sum(v1.begin(), v1.end(), v2.begin(), Multi);
}
서버
Type partial_sum(Iter first, Iter last, Iter target, Func fun) {
	Type val = *target++ = *first;
	for(Iter p = first + 1;p != last;++p)
		*target++ = val = fun(val, *p);
	return target;
}

*/