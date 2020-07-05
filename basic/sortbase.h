#ifndef _SORT_BASE_H_
#define _SORT_BASE_H_
// ソートのベースクラス
#include <vector>

// 汎用スワップ関数
template <typename T>
void Swap(T &e1, T &e2)
{
	T temp = e1;
	e1 = e2;
	e2 = temp;
}

using namespace std;

template <typename T>
class SortBase
{
public:  
  SortBase();
  virtual ~SortBase() {}
  virtual void exec() = 0;
  void add(T t) {m_elem.push_back(t);}
  void printInit() {it = m_elem.begin();}
  T getElem() {return *it++;}
  bool isPrintEnd() const {return it== m_elem.end();}
protected:
  vector<T> m_elem;
  typename vector<T>::iterator it;                 // vector<T>はネストされた(::に先行する）識別子であるので、タイプ名とコンパイラに通知する必要があるため、typename識別子を用いる
  //bool m_bDesc;                                   // 降順かどうかのフラグ
};

// コンストラクタ
template <typename T>
SortBase<T>::SortBase()
{
  m_elem.clear();
}

#endif // _SORT_BASE_H_


