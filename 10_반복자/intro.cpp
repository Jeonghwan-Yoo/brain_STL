/*
�ݺ��ڴ� �����̳��� ���Ҹ� ��ȸ�ϰ� �����ϴ� �Ϲ�ȭ�� ����� �����մϴ�.
�����̳ʿ� �˰����� �ݺ��ڸ� ���� ���� ���(�������̽�)�մϴ�.

01 �ݺ����� ����
�ݺ��ڴ� �����͸� �߻�ȭ�� Ŭ���� ��ü�Դϴ�.
�׷��� �����Ͱ� ���� ���ϴ� �� ���� ������ ������ �� �ֽ��ϴ�.
�ڷ� ������ �־� �ڷ��� ȿ������ ������ �����ϵ��� �ݺ��ڵ� �� �ݺ��ڸ��� Ư¡�� ������ �ټ� ������ �ݺ���.
1)�Է� �ݺ���(input iterator):������ �б�(istream)
2)��� �ݺ���(output iterator):������ ����(ostream)
3)������ �ݺ���(forward iterator):������ �б�, ����
4)����� �ݺ���(bidirectional iterator):����� �б�, ����(list, set, multiset, map, multimap)
5)���� ���� �ݺ���(random access iterator):���� �б�, ����(vector, deque)

�Է� �ݺ��ڴ� *iter(�б�), ->(��� �б�), ++(������ �̵�), ==(��), !=(��), iterator(iter)������ ����.
��� �ݺ��ڴ� *iter=x(����), ++, iterator(iter)(���� ������)������ �����մϴ�.
������ �ݺ��ڴ� *iter, ->, ++, ==, !=, =(����), iterator()(�⺻ ������), iterator(iter) ������ ����.
����� �ݺ��ڴ� ������ �ݺ��� ��ɿ� --(������ �̵�) ������ �����մϴ�.
���� ���� �ݺ��ڴ� ����� �ݺ��� ��ɿ� �ݺ����� ���� ������ [], +=, -=, +, -, <, >, <=, >=������ ����.

�ݺ��ڿ��� ������(sequence)�� ����(range)�� �߿��� �����Դϴ�.
�������� �����ִ� ������ �����Դϴ�.
�������� �ϳ��� ���۰� ���� ��Ÿ���� �ݺ����� ������ ǥ���Ǹ� ����(range)�̶� �մϴ�.
�������� ���� ���Ҹ� ����Ű�� �ݺ��ڸ� begin�̶� �ϰ� �������� ���� ����Ű�� �ݺ��ڸ� end�� �ϸ� �� ��������
[begin, end)��� �������� ǥ���մϴ�.
[begin, end)�� �ݰ� �����̶� �Ͽ� �ݺ��� begin�� ����Ű�� ���Ҵ� ������ ���ҿ� ���Ե����� �ݺ��� end��
����Ű�� ���Ҵ� ������ ���ҿ� ���Ե��� �ʽ��ϴ�.
begin          end
 ��              ��
|10|20|30|40|50|60|
 ---------��------->         
		 iter
���� [begin, end)�� ������:10 20 30 40 50
���� [begin, iter)�� ������:10 20 30
���� [iter, end)�� ������:40 50
������ �ݰ� �������� ǥ���ǹǷ� end�� ����Ű�� 60���Ҵ� �������� ���Ե��� �ʽ��ϴ�.

02 X::iterator�� X::const_iterator
STL�� ��� �����̳ʴ� ������ �ݺ����� ���� X::iterator�� X::const_iterator�� �����մϴ�.
����, ������ �ݺ��� ���� X::reverse_iterator�� X::const_reverse_iterator�� �����դ���.
1)X::iterator:������ �ݺ����� ���� ����. �ݺ��ڰ� ����Ű�� ���� �б�, ���� ����.
2)X::const_iterator:������ �ݺ����� ���� ����. �ݺ��ڰ� ����Ű�� ������ �б� ����

list, set, multiset, map, multimap�����̳��� X::iterator�� X::const_iterator�� ����� �ݺ����Դϴ�.
vector, deque�����̳��� X::iterator�� X::const_iterator�� ���� ���� �ݺ����Դϴ�.
�����̳��� begin()��� �Լ��� �����̳� �������� ù ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�ϸ� end()��� �Լ���
�������� �� ǥ��(past-the-end)�ݺ��ڸ� ��ȯ�մϴ�.
��� X::iterator�����̸� ������ó�� X::iterator ������ X::const_iterator�������� �ڵ���ȯ�˴ϴ�.
10_1.cpp iterator�� const_iterator
iter�� iterator�ݺ��ڷ� ����Ű�� ������ �б�, ���Ⱑ ������ �ݺ����̸� citer�� const_iterator�ݺ��ڷ�
����Ű�� ������ �б⸸ ������ �ݺ����Դϴ�.
�ݺ��ڰ� ����Ű�� ������ ��ġ�� �������� �������� constŰ���带 ����Ͽ� �ݺ��ڸ� constȭ �� �� �ֽ��ϴ�.
10_2.cpp X::iterator, X::const_iterator, const X::iterator, const X::const_iterator �ݺ��� ��
const X::iterator�� �ݺ��� ��ü�� const��ü�̸� X::const_iterator�� �ݺ��ڰ� ����Ű�� ���Ұ� const��ü�Դϴ�.
       (const_iter) (const_citer)
     iter citer  |    | 
       ��    ��    ��    ��
v    | 10 |(20)| 30 |(40)| N |
()�� ����Ұ���(const)

vector, deque�����̳ʴ� �迭 ��� �����̳ʷ� ���� ���� �ݺ��ڸ� �����ϸ� list, set, multiset, map, multimap��
����� �ݺ��ڸ� �����մϴ�.
10_3.cpp vector�� ���� ���� �ݺ��ڿ� list�� ����� �ݺ���
�ݺ��ڴ� *�����ڷ� ����Ű�� ���Ҹ� ������ �� ������ ->�����ڷ� ����Ű�� ������ ����� �����մϴ�.
viter�� ���� ���� �ݺ����̹Ƿ� viter += 2�� ����������, liter�� ����� �ݺ����̹Ƿ� liter += 2�� �Ұ���.
���� ���� �ݺ��ڴ� ����� �ݺ��� ��ɿ� [], +=, -=, +, -, <, >, <=, >=���� ����� �� �����մϴ�.
���İ��� �˰����� �� ������ �����ؾ� �ϹǷ� ���� ���� �ݺ��ڸ� �䱸�ϸ� vector�� deque�����̳ʿ� �����մϴ�.
  *viter                  *liter
v  |10|20|30| N|       lt  |10|20|30| N|
    ��      ��                ��
  viter  viter+=2����      liter  liter+=2�Ұ���

03 X::reverse_iterator�� X::const_reverse_iterator
X::reverse_iterator�� X::const_reverse_iterator�� �����̳ʿ� ���ǵ� ������ �ݺ��� �����Դϴ�.
1)X::reverse_iterator:������ �ݺ����� ���� ����. �ݺ��ڰ� ����Ű�� ���� �б�, ���� ����
2)X::const_reverse_iterator:������ �ݺ����� ���� ����. �ݺ��ڰ� ����Ű�� ������ �б� ����

list, set, multiset, map, multimap�����̳��� X::reverse_iterator�� X::const_reverse_iterator�� �����ݺ���.
vector, deque�����̳��� X::reverse_iterator�� X::const_reverse_iterator�� ���� ���� �ݺ����Դϴ�.
�����̳��� rbegin()��� �Լ��� �����̳� �������� �� ǥ��(past-the-end)�ݺ����Դϴ�.
rend()��� �Լ��� �������� ù ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�մϴ�.
��� X::reverse_iterator�����̸� ������ó�� X::reverse_iterator������ X::const_iterator�������� �ڵ� ��ȯ�˴ϴ�.
X::reverse_iterator�ݺ��ڴ� ������ �ݺ��ڷ� X::iterator�ݺ��ڿ� �ݴ�� ����.
10_4.cpp X::iterator�� X::reverse_iterator�� ����
iter�� ++�ϸ� �ݺ��ڰ� �������� ���������� �̵������� riter�� ++�ϸ� �ݺ��ڰ� �������� ���������� �̵��մϴ�.
������ �ݺ��ڴ� ����Ű�� ������ ��(value)�� ����������, ������ �ݺ��ڴ� ����Ű�� ���� ������ ��(value)�� ����.
                       ++
������ �ݺ���   begin() --> iter  end()
                 ��    value��     �� 
           v    |10|20|30|40|50| N|
		       �� ��   �� ��  value�� ��
������ �ݺ���  rend() riter <-- rbegin()
                            ++
������ ���� ������ �ݺ��ڴ� �ݺ��ڰ� ����Ű�� ���ҿ� ���� ��(value)�� �ٸ��ٴ� ��.
������ �ݺ��ڴ� ����Ű�� ���� ������ ��(value)�� �����մϴ�.
�ֳ��ϸ� ������ �ݺ��ڷ� ǥ���� �������� ������ �ݺ��ڷ� ǥ���� �������� ���� ������ �ϱ� ���ؼ��Դϴ�.
begin        end
  ��           �� 
| 10| 20| 30| N |
�� ��    value�� ��
rend        rbegin
[begin, end)�� ������:10 20 30
[rbegin, rend)�� ������:30 20 10
�� �������� ���Ұ� ����.

X::reverse_iterator�� X::const_reverse_iterator������ �ݺ��� ����� reverse_iterator<T>�� �����
X::iterator�� X::const_iterator�� �ݴ�� �����ϵ��� ��ȯ�� �����Դϴ�.
10_5.cpp �ݺ��� ����� reverse_iterator<T>
������ �ݺ��� v.begin()�� v.end()�� ������ �ݺ��� rend, rbegin���� ��ȯ�ϰ� �� ���� ([rbegin, rend))�� ��������
[rbegin(), rend())�� �������� ����մϴ�.
10_6.cpp �� �ݺ��� ������ ��ȯ
������ó�� ��const�ݺ��ڴ� const�ݺ��ڷ� ����ȯ�Ǹ� ������ �ݺ��ڴ� ������ �ݺ��ڷ� �Ϲ��� ��ȯ(�����ڸ� �̿���).
������ �ݺ��ڴ� base()��� �Լ��� ����Ͽ� ������ �ݺ��ڷ� ����ȯ�� �� �ֽ��ϴ�.
     iter       
       ��      
   |10|20|30|40|50|N |
value�� ��    
     riter
const_iterator <----- const_reverse_iterator
     ^          base()           ^
	 |                           |
  iterator     ����������>     reverse_iterator
               <-----
			   base()

04 ���� �ݺ���
���� �ݺ��ڴ� �������� ���Ҹ� ����(insert)�� �� �ְ� �ݺ��ڸ� ��ȯ�ϴ� �ݺ��� ������Դϴ�.
��� �˰����� �⺻������ ����� ���� �����մϴ�.
���� �ݺ��ڸ� ����ϸ� �˰����� ���� ���� �����ϰ� �� �� �ֽ��ϴ�.
1)inserter():insert_iterator��ü�� �����մϴ�. insert_iterator��ü�� �����̳��� insert()��� �Լ��� ȣ����
���� ���� �����ϰ� �˴ϴ�.
2)back_inserter():back_insert_iterator��ü�� �����մϴ�. back_insert_iterator ��ü�� �����̳��� push_back()
��� �Լ��� ȣ���� ���ʿ� �߰�(����)�ϵ��� �մϴ�.
3)front_inserter():front_insert_iterator��ü�� �����մϴ�. front_insert_iterator ��ü�� �����̳��� push_front()
��� �Լ��� ȣ���� ���ʿ� �߰�(����)�ϵ��� �մϴ�.

��� �����̳ʴ� insert()��� �Լ��� �����ϹǷ� inserter()����� �� ������ ������ �����̳��� vector, deque,
list���� back_inserter()�� ����� �� �ְ�, deque, list���� front_insert_iterator()�� ����� �� �ִ�.
����� ���� ������ ������ ������ ������ ���� ���� ������ ������ �þ�ϴ�.
����� ���
            iter                                    iter
             ��                                       ��
v size:3 |10|20|30| N|      ----->      v size:3 |10|50|30| N|
���� ���
			iter                                    iter
			 ��                                       ��
v size:3 |10|20|30| N|      ----->      v size:4 |10|50|20|30| N|
10_7.cpp ���� �ݺ��� ����� inserter()
inserter<vector<int>>(v2, v2.begin()):v2.begin()�ݺ��ڸ� v2�� insert()��� �Լ��� ȣ���ϴ� ���� �ݺ��ڷ�
��ȯ�մϴ�.
copy()�˰����� ����� ���� �����ϹǷ� inserter()�� ������� �ʴ´ٸ� v2�� size�� 0�̹Ƿ� ���� ������ �߻�.

list�� push_back()��� �Լ��� push_front()��� �Լ��� �����ϹǷ� back_inserter, front_inserter�ݺ���
����͸� ����� �� �ֽ��ϴ�.
10_8.cpp back_inserter(), front_inserter()
back_inserter<list<int>>(lt1):lt1�� push_back()��� �Լ��� ȣ���ϴ� �ݺ��ڸ� �����մϴ�.
front_inserter<list<int>>(lt2):lt2�� push_front()��� �Լ��� ȣ���ϴ� �ݺ��ڸ� �����մϴ�.
push_back()���
                             lt1.end()
                                 ��
lt1  |N | 1| 2| 3|10|20|30|40|50| N|
push_front()���
	 lt2.begin()
		 ��
lt2  |N |50|40|30|20|10| 1| 2| 3| N|

05 ��/��� ��Ʈ�� �ݺ���
��/��� ��Ʈ�� �ݺ��ڴ� ��Ʈ���� ����� �ݺ��ڷ� �˰����� ��Ʈ���� �а� �� �� �ְ� �ϴ� �ݺ��� ������Դϴ�.
1)istream_iterator<T>:�Է� ��Ʈ���� ����� �ݺ��ڷ� T������ ���� ��Ʈ������ ���� �� �ֽ��ϴ�.
2)ostream_iterator<T>:��� ��Ʈ���� ����� �ݺ��ڷ� T������ ���� ��Ʈ���� �� �� �ֽ��ϴ�.

10_9.cpp ostream_iterator ��� ��Ʈ�� �ݺ���
ostream_iterator<int>(cout):cout�� ����� ����(int)�� ����ϴ� �ݺ��ڸ� �����մϴ�.
ostream_iterator<int>(cout, ", "):cout�� ����� �ݺ��ڸ� �����ϵ� ��� �� ������ ", "�� �մϴ�.
transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plus<int>()):lt����(3��)��
v����(3��)�� ���� ȭ�鿡 ����մϴ�.

istream_iterator�� ����ϸ� �Է� ��Ʈ���� ����� �ݺ��ڸ� ������ �� �ֽ��ϴ�.
�Է��� ���� �� ��Ʈ�� �ݺ���(end-of-stream iterator)�� ����ϸ� istream_iterator<T>()ó�� �⺻ �����ڷ� ����.
10_10.cpp istream_iterator �Է� ��Ʈ�� �ݺ���
istream_iterator<int>(cin):ǥ�� �Է� ��Ʈ���� ����� �ݺ��ڸ� �����մϴ�.
istream_iterator<int>():�Է� ��Ʈ���� �� �ݺ��ڸ� �����մϴ�.
back_inserter<vector<int>>(v):v�� push_back()��� �Լ��� ȣ���ϴ� ���� �ݺ��ڸ� �����մϴ�.
ǥ�� �Է� ��Ʈ���� ���� Ctrl-D(end-of-file)�̹Ƿ� ������ �Է��ϰ� Ctrl-D�� �Է��ϸ� ȭ�鿡 �Է��� ������ ���.

06 �ݺ��� Ư���� ���� �Լ�
�ݺ��ڴ� �ݺ����� ȿ������ ����� ���� �ټ� ���� �ݺ���(�Է�, ��� ������, �����, ���� ���� �ݺ���)�� �з�.
�� �ݺ��ڴ� �ڽŸ��� Ư¡�� ������ �� Ư¡�� �����ϴ� ���ø� Ŭ������ ������ �ݺ��� Ư��(iterator traits).
����, �ݺ��ڸ� �����ϴ� �� �Լ� advance()�� distance()�Լ��� ���� ���� �ݺ��ڸ��� ������ �ִ� ����(+, -, +=, -=)��
�ٸ� �ݺ��ڵ� �����ϰ� �����մϴ�.
1)advance(p, n):p�ݺ��ڸ� p+=n�� ��ġ�� �̵���ŵ�ϴ�.
2)n = distance(p1, p2):n�� p2-p1�Դϴ�.
10_11.cpp advance() ���� �Լ�
viter�� ���� ���� �ݺ����̹Ƿ� +=�����̳� -=������ ����� �� ������ liter�� ����� �ݺ����̹Ƿ�
advance()�Լ��� ����ؾ� �մϴ�.

10_12.cpp distance() ���� �Լ�
vector�� ���� ���� �ݺ��ڸ� �����ϹǷ� v.end()-v.begin()�� ����������, list�� ����� �ݺ��ڸ� �����ϹǷ�
lt.end()-lt.begin()�� �Ұ����մϴ�.
��κ� distance()�Լ��� ��ȯ ������ unsigned int�� int������ �ݺ��ڸ��� �ٸ��ϴ�.
��Ȯ�� ���ϸ� �ݺ��� Ư���� difference_type�����Դϴ�.
�׷��� distance()�Լ��� ������ ���� ����մϴ�.
iterator_traits<vector<int>::iterator>::difference_type n = distance(v.begin(), v.end());

����� �˰����� ������ �� STL�˰���ó�� �Ϲ�ȭ�ϸ鼭�� �ݺ��� ������ Ư¡�� ���� ȿ������ ������ �ϴ�
�˰����� �����Ϸ��� STL�� �����ϴ� �ݺ��� Ư���� Ȱ���ؾ� �մϴ�.
iterator_traits�� ��� �ݺ��ڰ� �����ϴ� �ټ����� ������ iterator_category, value_type, difference_type,
pointer, reference�� �ϳ��� ���ø� Ŭ������ �����ϴ� �ݺ����� ����� �������̽��Դϴ�.
template<class Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};
�ݺ����� �ټ� ���� ������ �����ϸ� ���ø��� ���ڷ� �ݺ��ڸ� �����ϸ� �� �ݺ����� ������ Ȯ���� �� �ֽ��ϴ�.

����, STL�� �ݺ����� ������ ������ �� �ְ� �ټ� ���� �ݺ��� �±׸� �����մϴ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag:public input_iterator_tag {};
struct bidirectional_iterator_tag:public forward_iterator_tag {};
struct random_access_iterator_tag:public bidirectional_iterator_tag {};
����� Advance()�Լ��� �����Ѵٰ��ϸ� iterator_traits�� �̿��� �ݺ��ڰ� �����ϴ� ������ Ȯ��(�±�)�Ͽ�
�ݺ��ڿ� ���� �˰����� ȿ�������� ������ �� �ֽ��ϴ�.
Advance()�Լ��� ���� ���� �ݺ��ڸ� ���ڷ� �޴´ٸ� ���� ���� �ݺ��ڴ� +, -, +=, -=���� �����ϹǷ� �ٷ�
�ݺ��ڸ� �̵���ų �� ������ ����� �ݺ��ڸ� ���ڷ� �޴´ٸ� ++�����ڸ��� �����ϹǷ� �̵� ��ġ���� �ϳ���
�̵����Ѿ� �մϴ�.
�� �� Advance()�Լ��� iterator_traits�� �̿��� �ݺ��ڰ� �����ϴ� �ݺ��� �±�(iterator_tag)�� Ȯ���ϰ� ��
�ݺ��ڸ��� �����ϴ� �����ε� _Advance()�Լ��� ȣ���� �� �ֽ��ϴ�.
10_13.cpp ����� iterator_tag�� iterator_traitsŬ����
Advance(viter, 2)�� viter�� ���� ���� �ݺ��ڸ� �����ϹǷ� +=������ �����ϸ�,
Advance(liter, 2)�� liter�� ����� �ݺ��ڸ� �����ϹǷ� �ϳ��� ++������ �����մϴ�.

*/