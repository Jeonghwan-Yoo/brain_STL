/*
STL은 다양한 함수 객체를 제공합니다.
STL의 함수 객체는 클라이언트가 정의한 동작을 다른 구성 요소에 반영하기 위해 사용됩니다.
특히 많은 알고리즘은 STL함수 객체를 알고리즘의 인자로 받아 유연하게 동작할 수 있게 합니다.
함수 객체는 <functional>헤더에 정의되어 있습니다.

01 함수 객체의 종류
function object는 함수자(functor)라고도 하며, operator()연산자를 오버로딩한 클래스 객체입니다.
STL의 함수 객체는 두 가지로 분류할 수 있습니다.
1)일반 함수 객체:특정 기능을 수행하는 함수 객체
1-1)산술 연산 함수 객체:산술 연산 기능을 수행(plus, minus, multiplies, divides, modulus, negate)
1-2)비교 연산 함수 객체 조건자:비교 조건자(equal_to, not_equal_to, less, greater, greater_equal, less_equal)
1-3)논리 연산 함수 객체 조건자:논리 조건자(logical_and, logical_or, logical_not)
2)함수 어댑터(function adaptor):함수류(함수 객체, 함수, 함수 포인터)를 인자로 받아 다른 함수 객체로 변환
2-1)바인더(binder):이항 함수 객체를 단항 함수 객체로 변환(bind1st, bind2nd)
2-2)부정자(negator):함수 객체 조건자를 반대로 변환(not1, not2)
2-3)함수 포인터 어댑터:함수 포인터를 STL이 요구하는 함수 객체로 변환(ptr_fun)
2-4)멤버 함수 포인터 어댑터:멤버 함수 포인터를 STL이 요구하는 함수 객체로 변환(mem_fun, mem_fun_ref)

조건자는 bool형식을 반환하는 함수류(함수객체, 함수, 함수포인터)입니다.
많은 알고리즘에 이런 함수류를 사용자 조건으로 지정하여 알고리즘이 유연하게 동작하도록 합니다.
9_1.cpp 세 가지 조건자
STL에서 제공하는 조건자는 모두 함수 객체 조건자입니다.
bool형식을 반환하는 함수 객체라고 해서 모두 함수 객체 조건자(function object predicate)는 아니며 조건자는 객체의
상태값을 변경할 수 없다는 '요구조건'을 만족해야 합니다.
그래서 함수 객체 조건자의 operator()연산자 오버로딩 함수는 모두 const함수입니다.
이유는 조건자를 사용하는 많은 알고리즘에서 조건자가 변경되지 않는다는 전제 하에 조건자를 내부적으로 복사하며,
이 때 조건자의 상태값이 변경되면 예기치 못한 동작이 발생하기 때문입니다.
그래서 STL조건자는 '내부 상태가 변경되지 않는 bool 형식을 반환하는 함수 객체'입니다.

또한, 어댑터의 인자로 사용되는 함수 객체는 다음 요구사항을 지켜야 합니다.
1)단항 함수 객체는 반드시 argument_type, result_type이 정의돼 있어야 합니다.
각각은 함수의 인자 형식과 리턴 형식입니다.
2)이항 함수 객체는 반드시 first_argument_type, second_argument_type, result_type이 정의돼 있어야 합니다.
각각은 함수의 첫 번째 인자 형식과 두 번째 인자 형식, 리턴 형식입니다.
Adator는 함수 객체를 다른 함수 객체로 변환할 때 위 정의 형식을 이용해 변환을 수행합니다.
이러한 정의를 쉽게하려고 STL은 기본 클래스 unary_function가 binary_function을 제공합니다.
따라서 위 형식들을 직접 정의할 필요는 없으며, 함수 객체는 위 기본 클래스를 상속받아 만들면 됩니다.
9_2.cpp transform()알고리즘의 plus<int>연산
이항 함수자(함수 객체)를 사용하는 transform()알고리즘입니다.
두 순차열의 원소를 더하기 위해 STL함수 객체 plus<int>와 사용자가 직접 정의한 함수 객체 Plus<int>를 사용했습니다.

순차열을 더하지 않고 v1의 모든 원소에 100을 더하려 합니다.
사용자가 정의한 함수 객체 Plus<int>를 이용하려면 이항 함수 객체인 Plus<int>의 한 인자를 100으로 고정하고,
또한 다른 인자는 v1의 원소를 인자로 받게 합니다.
즉, 이항 함수 객체 Plus<int>를 단항 함수 객체(한 항을 100으로 고정)로 변환하면 됩니다.
이 때 어댑터 binder1st<int>를 사용할 수 있습니다.
9_3.cpp 어댑터를 사용한 transform() 알고리즘
transform()알고리즘은 단항 함수자 버전을 사용합니다.
STL plus<int>함수자는 잘 실행되지만 Plus<int>는 엄청난 에러가 발생합니다.
이유는 어댑터 binder1st<int>가 이항 함수자를 단항 함수자로 변환하기 위해 first_argument_type,
second_argument_type, result_type 형식 정의를 필요로 하기 때문입니다.
9_4.cpp first_argument_type, second_argument_type, result_type 형식 정의
이렇게 직접 함수자에 first_argument_type, second_argument_type, result_type형식을 정의할 수 있지만,
기본 클래스 unary_function과 binary_function을 상속받아 구현하는 것이 더 일반적이고 쉽습니다.
9_5.cpp 기본클래스 binary_function 상속
사용자 함수 객체(함수자)를 구현할 때 단항 함수자는 기본 클래스 unary_function을 상속받아 만들고
이항 함수자는 binary_function을 상속받아 만들면 됩니다.
그래야 함수자를 언제든지 어댑터와 결합해서 사용할 수 있습니다.

02 산술 연산 함수 객체
STL은 여섯 가지 산술 연산 객체(함수자)를 제공합니다.
1)plus<T>:이항 연산 함수자로 +연산
2)minus<T>:이항 연산 함수자로 -연산
3)multiplies<T>:이항 연산 함수자로 *연산
4)divides<T>:이항 연산 함수자로 /연산
5)modulus<T>:이항 연산 함수자로 %연산
6)negate<T>:단항 연산 함수자로 -연산

9_6.cpp plus<T>의 사용
함수자는 대부분 실행 문장에서만 사용되므로 3번째 호출 방법이 일반적.
함수자이므로 함수처럼 호출가능하며 멤버 함수 operator()연산자를 호출합니다.
9_7.cpp 사용자 Plus<T>
모든 산순 연산 함수자는 Plus<T>처럼 구현됩니다.
9_8.cpp 산술 연산 함수자와 알고리즘
transform(b, e, t, f)알고리즘에 사용된 f(negate<T>)만 단항 연산자이며 나머지는 모두 이항 연산자를 필요로 한다.

03 비교 연산 조건자
STL는 여섯 가지 비교 연산 함수 객체 조건자를 제공.
1)equal_to<T>:이항 조건자로 ==연산
2)not_equal_to<T>:이항 조건자로 !=연산
3)less<T>:이항 조건자로 <연산
4)less_equal<T>:이항 조건자로 <=연산
5)greater<T>:이항 조건자로 >연산
6)greater_equal<T>:이항 조건자로 >=연산

조건자(predicate)는 조건을 판단해야 하는 대부분의 알고리즘에 사용됩니다.
특정 정렬 기준으로 정렬되어야 하는 컨테이너인 연관 컨테이너 set, map, multiset, multimap에도 사용됨.
비교(조건자)가 사용되어야 하는 STL구성 요소의 기본 조건자는 less<T>입니다.
9_9.cpp 조건자 less<T>
조건자도 대부분 한 문장 내에서 사용되므로 3번째 호출 방법이 일반적으로 사용되는 방법.
사용자 조건자가 이항 조건자이면 어댑터 적용이 가능하게 binary_function기본 클래스를 상속받아 구현.
9_10.cpp 사용자 Less<T>
조건자는 상태가 변경될 수 없으므로 bool 형식을 반환하는 operator()연산자 함수를 꼭 const함수로 구현해야 합니다.
9_11.cpp 비교 연산 조건자
cout_if()알고리즘은 순차열의 원소를 인자로 받는 단항 조건자를 요구하므로 bind2nd<T>어댑터를 사용하여 이항
비교 연산자를 단항 조건자로 변환합니다.
즉 bind2nd<TT><TT(), 20)은 순차열의 모든 원소를 20과 비교하여 참이나 거짓을 반환하는 단항 조건자입니다.

04 논리 연산 조건자
STL은 세 가지 논리 연산 함수 객체 조건자를 제공.
1)logical_and<T>:이항 조건자로 &&연산
2)logical_or<T>:이항 조건자로 ||연산
3)logical_not<T>:단항 조건자로 !연산

논리 조건자는 일반적으로 T에 bool형식을 지정합니다.
일반적으로 피연산자의 논리 조건을 비교하기 때문.
9_12.cpp 논리 조건자 logical_and<T>
10 < n을 표현하려고 greater<int>()(n, 10)를 사용했으며, n < 50을 표현하려고 less<int>()(10, n)를 사용했으며,
마지막 두 조건 모두가 참인지를 판단하려고 logical_and<bool>()를 사용했습니다.
이항 조건자 logical_or<T>, 단항 조건자 logical_not<T>도 비슷하게 동작합니다.

05 바인더
binder는 이항 함수자를 단항 함수자로 변환합니다.
STL은 두 가지 바인더를 제공합니다.
1)bind1st:이항 함수자의 첫 번째 인자를 고정하여 단항 함수자로 변환
2)bind2nd:이항 함수자의 두 번째 인자를 고정하여 단항 함수자로 변환

9_13.cpp bind1st 바인더
binder(5)는 less<int>()(10, 5)와 같으므로 false입니다.
bind1st(less<int>(), 10)(20)은 less<int>()(10, 20)과 같으므로 true입니다.
bind1st()는 이항 함수자를 단항 함수자로 변환하는 함수이며 실제 단항 함수자 클래스는 binder1st입니다.
9_14.cpp bind2nd 바인더
binder(5)는 less<int>()(5, 10)와 같으므로 true입니다.
bind2nd(less<int>(), 10)(20)은 less<int>()(20, 10)과 같으므로 false입니다.
bind2nd()는 이항 함수자를 단항 함수자로 변환하는 함수이며 실제 단항 함수자 클래스는 binder2nd입니다.

06 부정자
negator는 조건자를 반대의 조건자로 변환합니다.
STL은 두 가지 부정자를 제공합니다.
1)not1:단항 조건자를 반대의 조건자로 변환
2)not2:이항 조건자를 반대의 조건자로 변환

9_15.cpp not2부정자
less의 반대인 이항 조건자이므로 negate(5, 10)은 5>=10 연산으로 false입니다.
negate(10, 10)은 10>=10연산으로 true입니다.
negate(20, 10)은 20>=10연산으로 true입니다.
binary_negate<>는 not2()부정자로 변환된 반대 이항 조건자 클래스입니다.
일반적으로 객체를 생성하지 않고 임시적으로 객체를 만들어 사용하는 not2(less<int>())(5, 10)등을 사용합니다.
9_16.cpp not1 부정자
binder는 less의 단항 조건자입니다.
negate는 단항 조건자의 반대 단항 조건자입니다.
그래서 negate(5)는 5<10의 반대인 5>=10이 되어 false입니다.
negate(10)은 10<10의 반대인 10>=10이 되어 true입니다.
negate(20)은 20<10의 반대인 20>=10이 되어 true입니다.

07 함수 포인터 어댑터
함수 포인터 어댑터는 일반 함수를 어댑터 적용이 가능한 함수 객체로 변환합니다.
STL은 ptr_fun()이라는 함수 포인터 어댑터를 제공합니다.
9_17.cpp 일반 함수에 부정자 어댑터 not1를 사용한 count_if() 알고리즘
not1(Pred)에서 Pred가 단항 함수 객체가 아닌 일반 함수이므로 argument_type과 result_type이 정의되어 있지 않기
때문에 어댑터인 no1()적용이 불가능합니다.
9_18.cpp ptr_fun에 부정자 어댑터 not1을 사용한 count_if() 알고리즘
일반 함수 Pred는 ptr_fun()어댑터로 argument_type과 result_type가 정의된 함수 객체로 변환합니다.
그래서 not1(ptr_fun(Pred))는 30이상 40이하가 아닌 원소의 단항 조건자가 됩니다.
9_19.cpp 사용자 ptr_fun()의 구현
Ptr_fun_class 클래스가 일반 함수(Pred)의 주소를 저장하는 함수 포인터 멤버 변수를 가집니다.
이 클래스는 unary_function클래스를 상속받아 이 클래스의 객체는 어댑터 적용이 가능하게 합니다.
Ptr_fun()함수로 일반 함수의 주소(Pred)를 인자로 받아 Ptr_func_class함수 객체를 생성(변환)하고 반환합니다.
Ptr_fun()어댑터 함수가 반환한 객체는 어댑터 적용이 가능한 함수 객체.

08 멤버 함수 포인터 어댑터
멤버 함수를 함수 객체로 변환하여 알고리즘이 객체 원소의 멤버 함수를 호출할 수 있게 합니다.
STL은 다음 두 가지 멤버 함수 포인터 어댑터를 제공합니다.
1)mem_fun_ref():객체로 멤버 함수를 호출합니다.
2)mem_fun():객체의 주소로 멤버 함수를 호출합니다.
9_20.cpp mem_fun_ref() 어댑터
for_each(v.begin(), v.end(), &Point::Print)문장이 실행되지 않는 이유는 for_each()알고리즘이 함수를 
fun(Point객체)와 같이 호출하기 때문입니다.
멤버 함수는 Point객체.Print()처럼 호출되어야 합니다.
이와 같이 호출될 수 있게 함수 객체를 생성(변환)해주는 어댑터가 mem_fun_ref()입니다.
클라이언트
class Point {
	void Print() const {
	}
}
void main() {
	for_each(v.begin(), v.end(), &Point::Print);
}
서버
Function for_each(Iterator first, Iterator last, Function fun) {
	for(Iterator p = first;p != last;++p)
		fun(*p);
	return fun;
}
STL의 mem_fun_ref는 const버전, 비const버전으로 구현되어 있지만 Print함수가 const버전이므로 const버전.
9_21.cpp 사용자 Mem_fun_ref() 어댑터
for_each()알고리즘의 fun(*p)는 fun이 Mem_fun_ref_class 객체이므로 fun.operator()(*p)를 호출하며,
*p가 Point객체이므로 ((*p),*pf)()를 호출해 실제 (*p).Print()를 호출합니다.

for_each()알고리즘의 원소가 객체가 아닌 객체의 주소라면 mem_fun_ref()어댑터가 아닌 mem_fun()어댑터를 사용.
이유는 객체로 멤버 함수 포인터를 호출할 때는 (o.*pf)()로 호출하지만, 객체의 주소로 멤버 함수 포인터를 호출할 때는
(p->*pf)()로 호출하기 때문입니다.
9_22.cpp 사용자 Mem_fun() 어댑터
달라진 부분은 순차열(v)에 저장된 원소가 객체가 아닌 객체의 주소이므로 Mem_fun_class의 operator()함수의
매개변수가 Point의 포인터이며 Point의 멤버 함수를 호출하기 위해 (p->*pf)()를 사용합니다.
for_each()알고리즘의 fun(*p)는 fun이 Mem_fun_class객체이므로 fun.operator()(*p)를 호출하며, *p가 Point객체의
주소이므로 ((*p)->*pf)()를 호출해 실제 (*p)->Print()를 호출합니다.

*/