#ifndef _BSORT_H_
#define _BOSRT_H_

// 基本整列法
// その１　バブルソート
// またの名称を隣接交換法
#include "sortbase.h"

template <typename T>
class BSort: public SortBase<T>
{
public:
  BSort() {}

  void exec(); 
  // これがないとm_elem を使うときは this-> をつけなくてはならなくなる
  using SortBase<T>::m_elem;

};

// 右端から最小値が埋まっていく
template <typename T>
void BSort<T>::exec()
{
  int sz = static_cast<int>(m_elem.size());
  for (int i= sz-2; i>= 0; i--) {
    for (int j=0; j<= i; j++) {
       if (m_elem[j] < m_elem[j+1]) {
         T temp = m_elem[j];
         m_elem[j] = m_elem[j+1];
         m_elem[j+1] = temp;
       }
    }
  }
}

#endif // _BSORT_H_


