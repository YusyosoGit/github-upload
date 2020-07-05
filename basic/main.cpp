#include "Element.h"
#include "sortpattern.h"
#include <iostream>
#include <string>
#define ELEM_TYPE int

using namespace std;
typedef Element<ELEM_TYPE> etype;


int main(int argc, char* argv[])
{
	SortBase<etype> *sort= new MSort<etype>();

	if (argc > 1) {
		for (int i=1; i<argc; i++) {
			string s(argv[i]);
			if (s == "-d" || s== "--desc") {
				etype::setLess();
			}
			else if (s== "-a" || s== "--asc") {
				etype::setGreat();
			}
			else {
				cout << "Wrong Argument " << s;
				exit(1);
			}
		}
	}

	// 要素をキーボード、またはファイルからリダイレクトして読む
	// 要素数を最初に入力
	int nElems;
	cin >> nElems;
	cout << "要素数：" << nElems << endl;

	for (int i=0; i<nElems; i++) {
		etype e;
		cin >> e.get();
		sort->add(e);
	}
	// ソートを実行
	sort->exec();

	// 結果を表示
	cout << "結果：";
	for (sort->printInit(); !sort->isPrintEnd(); ) {
		etype e = sort->getElem();
		cout << e.get() << (sort->isPrintEnd()? "\n": " ");
	}

	return 0;
}


