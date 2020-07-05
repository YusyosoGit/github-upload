#ifndef _HEAPSORT_H_
#define _HEAPOSRT_H_

// 高度な整列法
// ヒープソート
#include "sortbase.h"

template <typename T>
class HSort: public SortBase<T>
{
public:
	HSort() {}

	void exec(); 
	// これがないとm_elem を使うときは this-> をつけなくてはならなくなる
	using SortBase<T>::m_elem;
private:
	void pushdown(int top, int bottom);
};

// ヒープを構成（親＞＝子／親＜＝子）の関係を守る
// ＞親が子より小さ／大きければ位置を交換
template <typename T>
void HSort<T>::pushdown(int top, int bottom)
{
	int parent = top;
	int child = 2 * parent;
	while (child <= bottom) {
		// より大きい方と比較（昇順では親のほうが大きくなるため）
		if ((child < bottom) && (m_elem[child] < m_elem[child+1])) {
			child ++;
		}
		if (m_elem[child] <= m_elem[parent])
			// 交換不要なのでここで終了
			break;
		Swap<T>(m_elem[child], m_elem[parent]);
		parent = child;
		child = 2 * parent;
	}
}

// 右端から最小値が埋まっていく
template <typename T>
void HSort<T>::exec()
{
	int sz = static_cast<int>(m_elem.size());
	// 要素の先頭に無意味な値を挿入し、並び替えるべき配列の先頭のインデックスを１にする
	m_elem.insert(m_elem.begin(), T());

	// 整列した順序木を構成する
	for (int i= sz/2; i >= 1; i--) {
		pushdown(i, sz);
	}
	
	// 配列の右端から整列済みの要素を置いていく
	for (int i= sz; i >= 2; i--) {
		Swap<T>(m_elem[1], m_elem[i]);
		pushdown(1, i -1);
	}
	// 先頭の要素を除去する
	m_elem.erase(m_elem.begin());
}

#endif // _HEAPSORT_H_


