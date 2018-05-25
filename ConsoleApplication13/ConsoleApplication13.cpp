// ConsoleApplication13.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "stdio.h"
#include"stdlib.h"

static int all;
static int chose;

int input();
int input2();
void lottery(int all, int chose);

int main()
{
	all = input();
	chose = input2();

	lottery(all, chose);

    return 0;
}

//全体の数を入力する
int input() {
	printf("全体の数は何人ですか？\n");
	scanf_s("%d", &all);
	printf("%d人の中から", all);

	return all;
}

//抽選であたる数を入力する
int input2() {
	printf("当たりは何人ですか？\n");
	scanf_s("%d", &chose);
	//printf("%d人\n", chose);

	return chose;
}


/*誰が当たるかだけ知りたい場合(すべて同じ景品の場合)*/
/*void lottery(int all, int chose) {
	
	int i;
	int a[100] = { 0 };

	//配列の中に数を入れる
	
	for (i = 0; i < all; i++) {
		a[i] = i + 1;
		
	}
	

	//乱数を調べる
	for (i = 0; i < chose; ) {

		int num= rand() % all + 1;

		if (a[num-1] == num) {

			printf("%d番目の人が当たりです\n", num);
			//all = all - 1;
			a[num - 1] = 0;
			i++;
		}
		else {

		}
	}

}*/

/*順位をつけたい場合*/
void lottery(int all, int chose) {
	int i = 0;
	int win = 1; //当選者順位

	int a[100] = { 0 };

	for (i = 0; i < chose;i++ ) {

		int num = rand() % all + 1;

		if (a[num - 1] == 0) {
			a[num - 1] = num;
			printf("%d等　%d番\n", win, num);
			win += 1;
		}
	}
}