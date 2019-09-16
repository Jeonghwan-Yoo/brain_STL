/*
�����̳� ����ʹ� �ٸ� �����̳��� �������̽��� ������ �����̳��Դϴ�.
STL���� stack, queue, priority_queue �� ���� �����̳� ����Ͱ� �ֽ��ϴ�.
stack�� LIFO(Last-In First-Out)����� �����̳��̸�, queue�� FIFO(First-In First-Out)����� �����̳�.
priority_queue�� ���Ҹ� �켱������ ���� �����Ǵ� ť�Դϴ�.
priority_queue�� Ư�� ���� �������� ������ �켱������ �����Ǹ� �⺻ ���� ������ less(<)�Դϴ�.

01 stack �����̳�
LIFO����� �����̳ʸ� ������ ���ø� Ŭ�����Դϴ�.
stack�����̳ʿ� ������ �⺻ �����̳ʴ� deque �����̳��Դϴ�.

���ø� ����
template<typename T, typename Container = deque<T>> //T�� ������ �����̸�, Container�� stack���� ����
                                                      �����̳� �����̸�, �⺻ �����̳ʴ� deque<T>
class stack

��� ����
value_type                                     //Container::value_type���� T�����̴�.
size_type                                      //Container::size_type���� ÷��(index)�� ���� ���� ���� ����.
container_type                                 //Container�����̸�, �⺻ ������ deque<T>�̴�.

������
explicit stack(const Container& = Container()) //�����̳��� �⺻ �����ڸ� ȣ���� stack�� �����ϰų� ���ڷ� �޾�
                                                 stack�� �����Ѵ�.

��� �Լ�
bool empty() const                             //���Ұ� ���°�?
size_type size() const                         //������ ������.
void push(const vlaue_type& x)                 //���Ҹ� �߰��Ѵ�.
void pop()                                     //���Ҹ� �����Ѵ�.
value_type& top()                              //Top���Ҹ� �����Ѵ�.
const value_type& top() const                  //const��ü Top���Ҹ� �����Ѵ�.

������
s1 == s2                                       //s1�� s2�� ������?
s1 != s2                                       //s1�� s2�� �ٸ���?
s1 < s2                                        //s1���� s2�� ū��?
s1 <= s2                                       //s1���� s2�� ũ�ų� ������?
s1 > s2                                        //s2���� s1�� ū��?
s1 >= s2                                       //s2���� s1�� ũ�ų� ������?

stack�� Container���ø� ���ڷ� �޴� �����̳ʴ� empty(), size(), push_back(), pop_back(), back() ����
�������̽��� �����ؾ� �մϴ�.
�׷��� stack�� Container�� vector, deque, list�� ����� �� ������, �� �������̽����� �����Ѵٸ� �����
�����̳ʸ� ����� �� �ֽ��ϴ�.
	    ��top():����
stack����������������������������������������������������������������
��                                   ��
��       ��back()                     ��
��deque������������������                     ��
��  ��          ����push_back()         ����push():�Է�
��  �� |30|     ����pop_back()          ����pop():���
��  �� |20|     ��                     ��
��  �� |10|     ��                     ��
��  ������������������������                     ��
��������������������������������������������������������������������������
11_1.cpp stack �����̳�
push()�� ���Ҹ� �߰��ϰ�, top()���� ���� �ʰ� ����� ���Ҹ� �����ϰ� pop()���� ���Ҹ� �����մϴ�.

02 queue �����̳�
FIFO����� �����̳ʸ� ������ ���ø� Ŭ�����Դϴ�.
queue�����̳ʿ� ������ �⺻ �����̳ʴ� deque �����̳��Դϴ�.

���ø� ����
template<typename T, typename Container = deque<T>> //T�� ������ �����̸�, Container�� queue���� ����
													  �����̳� �����̸�, �⺻ �����̳ʴ� deque<T>
class queue

��� ����
value_type                                     //Container::value_type���� T�����̴�.
size_type                                      //Container::size_type���� ÷��(index)�� ���� ���� ���� ����.
container_type                                 //Container�����̸�, �⺻ ������ deque<T>�̴�.

������
explicit queue(const Container& = Container()) //�����̳��� �⺻ �����ڸ� ȣ���� queue�� �����ϰų� ���ڷ� �޾�
												 queue�� �����Ѵ�.

��� �Լ�
bool empty() const                             //���Ұ� ���°�?
size_type size() const                         //������ ������.
void push(const vlaue_type& x)                 //���Ҹ� �߰��Ѵ�.
void pop()                                     //���Ҹ� �����Ѵ�.
value_type& front()                            //ù ���Ҹ� �����Ѵ�.
const value_type& front() const                //const��ü ù ���Ҹ� �����Ѵ�.
value_type& back()                             //������ ���Ҹ� �����Ѵ�.
const value_type& back() const                 //const��ü ������ ���Ҹ� �����Ѵ�.

������
s1 == s2                                       //s1�� s2�� ������?
s1 != s2                                       //s1�� s2�� �ٸ���?
s1 < s2                                        //s1���� s2�� ū��?
s1 <= s2                                       //s1���� s2�� ũ�ų� ������?
s1 > s2                                        //s2���� s1�� ū��?
s1 >= s2                                       //s2���� s1�� ũ�ų� ������?

queue�� Container ���ø� ���ڷ� �޴� �����̳ʴ� empty(), size(), push_back(), pop_front(), front()����
�������̽��� �����ؾ� �մϴ�.
�׷��� queue�� Container�� vector�� ����� �� ������, deque, list�� �� �������̽��� �����ϴ� ����� �����̳ʸ�
����� �� �ֽ��ϴ�.
queue����������������������������������������������������������������
��deque������������������                     ��
��  ��          ����push_back()         ����push():�Է�
��  �� |30|     ��                     ��
��  �� |20|     ��                     ��
��  �� |10|     ����pop_front()         ����pop():���                    
��  ������������������������                     ��
��       ��front()                    ��
��                                   ��
��������������������������������������������������������������������������
		��front():����
11_2.cpp queue �����̳�
queue<int ,list<int>> q:queue�� �����̳� �������� list<int>�� ����ϰ� int������ ���Ҹ� �����ϴ� 
queue�� �����մϴ�.
queue�� �ֿ� �������̽��� ���Ҹ� �߰��ϴ� push(), ���Ҹ� �����ϴ� pop(), ù ���Ҹ� �����ϴ� front()�Դϴ�.

03 priority_queue �����̳�
�켱���� queue�� ������ ���ø� Ŭ�����Դϴ�.
priority_queue�����̳ʿ� ������ �⺻ �����̳ʴ� vector�Դϴ�.

���ø� ����
template<
	typename T, 
	typename Container = vector<T>,
	typename Comp = less<typenamme Container::value_type>
> //T�� ������ �����̸�, Container�� priority_queue���� ���� �����̳� �����̸�, �⺻ �����̳ʴ� vector<T>.
//Comp�� �켱������ ������ ���� �����̸� �⺻ ���� ������ less<T>�̴�.
class priority_queue

��� ����
value_type                                     //Container::value_type���� T�����̴�.
size_type                                      //Container::size_type���� ÷��(index)�� ���� ���� ���� ����.
container_type                                 //Container�����̸�, �⺻ ������ vector<T>�̴�.

������
explicit priority_queue(const Comp& = Comp(), const Container& = Container()) 
                                               //�����̳��� �⺻ �����ڸ� ȣ���� priority_queue�� �����ϰų� 
											     ���ڷ� �޾� priority_queue�� �����Ѵ�.

��� �Լ�
bool empty() const                             //���Ұ� ���°�?
size_type size() const                         //������ ������.
void push(const vlaue_type& x)                 //���Ҹ� �߰��Ѵ�.
void pop()                                     //���Ҹ� �����Ѵ�.
value_type& top()                              //Top���Ҹ� �����Ѵ�.
const value_type& top() const                  //const��ü Top���Ҹ� �����Ѵ�.

priority_queue�� ���������� STL�� �� �˰����� make_heap(), push_heap(), pop_heap()�� ����Ͽ� ������
�����Ƿ� priority_queue�� Container���ø� ���ڷ� �޴� �����̳ʴ� ���� ���� �ݺ��ڸ� �����ϴ� �����̳�.
����, empty(), size(), push_back(), pop_back(), front() ���� �������̽��� �����ؾ� �մϴ�.
�׷��� vector�� deque�����̳ʸ� ����� �� �ֽ��ϴ�.
priority_queue����������������������������������������������
��vector����������������                     ��
��  ��          ����push_back()         ����push():�Է�
��  �� |30|     ��                     ��
��  �� |20|     ��                     ��
��  �� |10|     ����pop_back()          ����pop():���
��  ������������������������                     ��
��       ��front()                    ��
��                                   ��
��������������������������������������������������������������������������
		��top():����
11_3.cpp priority_queue �����̳�
pq1�� vector<int>�����̳ʸ� ����ϰ� less���� ������ ����� priority_queue�����̳�.
pq2�� deque<int>�����̳ʸ� ����ϰ� greater���� ������ ����� priority_queue�Դϴ�.
�������̽��� stack�� ����ϴ�.

*/