#ifndef _HSORT_H_
#define _HSORT_H_

/* 高度な整列法 マージソート
 * 応用情報技術者試験対策2019の第６章の問題２を
 * 元にアルゴリズムを作成
 */
#include "sortbase.h"

// 単方向リスト
template <typename T>
struct OnewayList
{
public:
	T val;
	OnewayList *next;
};

// ソートのクラス
template <typename T>
class MSort: public SortBase<T>
{
public:
	MSort() {}

	void exec(); 
	// これがないとm_elem を使うときは this-> をつけなくてはならなくなる
	using SortBase<T>::m_elem;
private:
	OnewayList<T> *divide(OnewayList<T> *list);
	OnewayList<T> *merge(OnewayList<T> *p1, OnewayList<T> *p2);
	OnewayList<T> *get_sorted(OnewayList<T> *list);
};

/* リストを２つに分ける
 * 引数に分けるリストの先頭アドレス
 * 戻り値は分けたもう片方のリストの先頭アドレス
 */
template <typename T>
OnewayList<T>* MSort<T>::divide(OnewayList<T> *list)
{
	OnewayList<T> *p1 = list;
	OnewayList<T> *p2 = list->next;
#if 0
	if (p2 != nullptr) p2= p2->next;
	while (p2 != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
		if (p2 != nullptr) p2= p2->next;
	}
#else
	// こちらのほうがスッキリしてよかろう
	while (p2!= nullptr && (p2=p2->next) != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}
#endif
	// リストを分割する
	OnewayList<T> *listEx= p1->next;
	p1->next = nullptr;
	// もう片方のリストの先頭を返す
	return listEx;
}

/* リスト１とリスト２を併合する。つまり２つのリスト同士でポインタのつなぎ替えを行う
 * 引数にリスト１とリスト２の先頭アドレス。どちらも nullptr は不可
 * 戻り値は統合されたリストの先頭ポインタ
*/
template <typename T>
OnewayList<T> *MSort<T>::merge(OnewayList<T> *p1, OnewayList<T> *p2)
{
	// ダミーヘッダ
	OnewayList<T> dhead;
	// p はこれより後はリスト１か２のどちらかの要素を指す
	OnewayList<T> *p = &dhead;

	while (p1 != nullptr && p2 != nullptr) {
		if (p2->val < p1->val) {
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
		else {
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
	}
	if (p1 == nullptr) {
		p->next = p2;
	}
	else {
		p->next = p1;
	}
	return dhead.next;
}

/* 未ソートリストを渡し、ソート済リストを取得する
 * 引数に未ソートリストの先頭アドレス
 * 戻り値はソート済リストの先頭アドレス
 */
template <typename T>
OnewayList<T> *MSort<T>::get_sorted(OnewayList<T> *list)
{
	OnewayList<T> *listEx = divide(list);
	if (listEx == nullptr)
		// リストがこれ以上分割できないのでソートしない
		return list;
	OnewayList<T> *p1= get_sorted(list);
	OnewayList<T> *p2= get_sorted(listEx);
	// 分割したものをマージしてそれを返す
	return merge(p1, p2);
}

/* マージソートの実行
 * 単方向リストにデータを一時的に移し替えて処理を実行
 */
template <typename T>
void MSort<T>::exec()
{
	int sz = static_cast<int>(m_elem.size());
	if (sz == 0) return;

	// 単方向リストを構成
	OnewayList<T> *ol = new OnewayList<T>[sz];
	for (int i= 0; i< sz-1; i++) {
		ol[i].val = m_elem[i];
		ol[i].next = &ol[i+1];
	}
	ol[sz-1].val  =m_elem[sz-1];
	ol[sz-1].next =nullptr;

	// ソートを実行
	OnewayList<T> *p = get_sorted(ol);

	// 結果を格納
	int i = 0;
	for (; p!= nullptr; p=p->next) {
		m_elem[i++] = p->val;
	}
	//delete [] ol;
}

#endif // _HSORT_H_

