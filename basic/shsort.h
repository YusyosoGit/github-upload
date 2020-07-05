// 基本整列法
// シェルソート（改良挿入法）
// 一定間隔おきに単純挿入法を行う
/*
間隔の決定方法については下記を参照のこと
https://web.archive.org/web/20170212072405/http://www.programming-magic.com/20100507074241/
*/

#include "sortbase.h"

template <typename T>
class ShellSort: public SortBase<T>
{
public:
  ShellSort() {}

  void exec(); 
  // これがないとm_elem を使うときは this-> をつけなくてはならなくなる
  using SortBase<T>::m_elem;

};

// ソートの処理
// 各グループごと一番右端の要素は整列済みとみなす。
// 未整列の並びを左へ見ていき、整列済みの並びの正しい位置に挿入する
template <typename T>
void ShellSort<T>::exec()
{
	int sz = static_cast<int>(m_elem.size());

	// グループ間隔hを集合のサイズから自動で決定
	int hn;
	int hnp1 = 1;

	do {
		hn = hnp1;
		hnp1 = 3 * hn + 1;
	} while (hnp1 < sz/2);

	int h = hn;
	while (h >=1 ) {
		// 1~h までのグループごとに挿入ソートを行う
		for (int k= 1; k<=h; k++) {
			// 整列済みでない部分を走査
			for (int i= sz-h-k; i>= 0; i-= h) {
				// 整列済みの並びの正しい位置に挿入
				for (int j=i; j<sz-h && m_elem[j]< m_elem[j+h]; j+=h) {
					T temp = m_elem[j];
					m_elem[j] = m_elem[j+h];
					m_elem[j+h] = temp;
				}
			}
		}
		h = (h - 1)/ 3;
	}
}

