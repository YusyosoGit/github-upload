// 基本整列法
// その２　単純選択法
// 最小値を見つけ、端から未整列の要素と入れ替え
#include "sortbase.h"

template <typename T>
class SimpleSel: public SortBase<T>
{
public:
  SimpleSel() {}

  void exec(); 
  // これがないとm_elem を使うときは this-> をつけなくてはならなくなる
  using SortBase<T>::m_elem;

};

// ソートの処理
// 右端から最小値を入れ替えて整列済みにしていく
template <typename T>
void SimpleSel<T>::exec()
{
  int sz = static_cast<int>(m_elem.size());
#if 1 // メソッド１・・・最小値をその都度入れ替える
	for (int i= sz-1; i> 0; i--) {
		for (int j=0; j<= i-1; j++) {
			if (m_elem[j] < m_elem[i]) {
				T temp = m_elem[i];
				m_elem[i] = m_elem[j];
				m_elem[j] = temp;
			}
		}
	}
#else // メソッド２・・・最小値とその場所を記憶する
	for (int i= sz-1; i> 0; i--) {
		T min=m_elem[i];
		int pos = i;
		for (int j=0; j<i; j++) {
			if (m_elem[j] < min) {
				min=m_elem[j];
				pos = j;
			}
		}
		// 最小値と未整列の値を入れ替える
		m_elem[pos] = m_elem[i];
		m_elem[i] = min;
	}
#endif
}




