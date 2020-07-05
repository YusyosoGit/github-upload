#ifndef _QSORT_H_
#define _QOSRT_H_

// 高速な整列法
// クイックソート
// プログラミング言語Ｃ[第２版]のp134を参考
#include "sortbase.h"

template <typename T>
class QSort: public SortBase<T>
{
public:
	QSort() {}

	void exec(); 
	// これがないとm_elem を使うときは this-> をつけなくてはならなくなる
	using SortBase<T>::m_elem;
private:
	void div(int left, int right);
};

// 右端から最小値が埋まっていく
template <typename T>
void QSort<T>::exec()
{
	int sz = static_cast<int>(m_elem.size());
	div(0, sz-1);
}

// 何を基準値とするかの目安は特にないが、できるだけサイズを半分にする値であるほうが望ましい
// この関数の場合は単に各並びの中央に位置するものを基準値とする
template<typename T>
void QSort<T>::div(int left, int right)
{
	// 要素数が２以上が並び替え対象
	if (left >= right) return;
#if 1
	// 基準値を一旦左端に退避
	Swap<T>(m_elem[left], m_elem[(left+right) / 2]);
	T &std_val = m_elem[left];
	// 基準値より小さい／大きい値を左側に集める
	int mid = left;
	for (int i = left + 1; i <= right; i++) {
		if (std_val < m_elem[i]) {
			Swap<T>(m_elem[i], m_elem[++mid]);
		}
	}
	// 退避した基準値を集めた並びの末尾へ（その並びの最大値／最小値にあたる）
	Swap<T>(m_elem[left], m_elem[mid]);
#else
	// 基準値を退避しなくてもいい方法・・・あるかな？
	T mid_val= m_elem[(left+right)/2];
	int mid = left;
	for (i = left+1; i<= right; i++) {
		if (m_elem[i] < mid_val) {
			Swap<T>(m_elem[mid++], m_elem[i]);
		}
	}
#endif
	// ２分した区画のそれぞれで更にソートを繰り返す
	div(left, mid-1);
	div(mid+1,right);
}


#endif // _QSORT_H_


