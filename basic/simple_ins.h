// 基本整列法
// その３　単純挿入法
// 整列済みのならびを徐々に拡張する
#include "sortbase.h"

template <typename T>
class SimpleIns: public SortBase<T>
{
public:
  SimpleIns() {}

  void exec(); 
  // これがないとm_elem を使うときは this-> をつけなくてはならなくなる
  using SortBase<T>::m_elem;

};

// ソートの処理
// 一番右端の要素は整列済みとみなす
// 未整列の並びを左へ見ていき、整列済みの並びの正しい位置に挿入する
template <typename T>
void SimpleIns<T>::exec()
{
	int sz = static_cast<int>(m_elem.size());
	// 整列済みでない部分を走査
	for (int i= sz-2; i>= 0; i--) {
		// 整列済みの並びの正しい位置に挿入
		for (int j=i; j<sz-1 && m_elem[j]< m_elem[j+1]; j++) {
			T temp = m_elem[j];
			m_elem[j] = m_elem[j+1];
			m_elem[j+1] = temp;
		}
	}
}

