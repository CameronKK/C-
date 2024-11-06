#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Hero
{
	int power;
public:
	Hero(): power(100){}
	int getPower() { return power; }
	void kougeki_suru(int n);
	void kougeki_sareru(int n);
};

void Hero::kougeki_suru(int n)
{
	cout << "悪党め。正義の攻撃を受けてみよ。" << endl;
	cout << "どか～ん！！！！" << endl;
	power -= n;

	if (power >= 0) {
		cout << "（現在のパワーは" << power << "になった。）" << endl;
	}
	else {
		cout << "しまった！パワーを使いすぎた。" << endl;
		cout << "もうおしまいだ！！がくっ…" << endl;
	}
}

void Hero::kougeki_sareru(int n)
{
	cout << "くそっ。悪党の攻撃も当たることがあるのか。" << endl;
	power -= n;

	if (power >= 0) {
		cout << "（現在のパワーは" << power << "になった。）" << endl;
	}
	else {
		cout << "やられた。がくっ…" << endl;
	}
}

class Daimao
{
	int power;
public:
	Daimao() : power(100) {}
	int getPower() { return power; }
	void kougeki_suru(int n);
	void kougeki_sareru(int n);
};

void Daimao::kougeki_suru(int n)
{
	cout << "大魔王様の一撃を受けてみよ。" << endl;
	cout << "どか～ん！！！！" << endl;
	power -= n;

	if (power < 0) {
		cout << "しまった！！！パワーを使いすぎた！！" << endl;
		cout << "む、む、む。無念だ。がくっ…" << endl;
	}
}

void Daimao::kougeki_sareru(int n)
{
	cout << "くそっ。正義の味方の攻撃も当たることがあるのか。" << endl;
	power -= n;

	if (power < 0) {
		cout << "やられた！！！がくっ…" << endl;
	}
}

class Taiketu_basho
{
	Daimao bu;
	Hero you;
	int bu_no_basho;
	int you_no_basho;

public:
	Taiketu_basho();
	void taiketu();
	void kurikaeshi_taiketu();
};

Taiketu_basho::Taiketu_basho()
{
	srand((unsigned)time(NULL));
	bu_no_basho = rand() % 5 + 1;

	cout << "あなたと大魔王ブーとの決戦です。\n" << endl;
	cout << "大魔王ブーは座標１～５のどこかに潜んでいます。" << endl;
	cout << "あなたもどこかに身をひそめてください。" << endl;
	cout << "身をひそめる座標（１～５の数値）を入力してください。" << endl;

	cin >> you_no_basho;
}

void Taiketu_basho::taiketu()
{
	int iti, kougeki;

	cout << "さあ、あなたの攻撃です。" << endl;
	cout << "攻撃の位置（１～５）を入力してください。>> ";
	cin >> iti;

	cout << "攻撃に使うパワー（" << you.getPower() << "以下の数値）を入力してください。>>";
	cin >> kougeki;
	cout << endl;

	you.kougeki_suru(kougeki);

	if (you.getPower() < 0) {
		return;
	}

	if (bu_no_basho == iti) {
		bu.kougeki_sareru(kougeki * 2);

		if (bu.getPower() < 0) {
			return;
		}
	}
	else {
		cout << "あなたの攻撃は外れたようです。" << endl;
	}
	cout << endl;
	cout << "大魔王の攻撃です。" << endl;
	cout << "（エンターキーを押してください。）" << endl;
	
	cin.sync();
	cin.get();

	iti = rand() % 5 + 1;
	kougeki = rand() % 100 + 1;
	bu.kougeki_suru(kougeki);

	if (bu.getPower() < 0) {
		return;
	}
	
	if (you_no_basho == iti) {
		you.kougeki_sareru(kougeki * 2);
	}
	else {
		cout << "大魔王ブーの攻撃は外れたようです。" << endl;
	}
}

void Taiketu_basho::kurikaeshi_taiketu()
{
	while (1) {
		taiketu();
		if (you.getPower() < 0) {
			cout << "\n大魔王の前に正義のヒーローは敗れました。" << endl;
			break;
		}

		if (bu.getPower() < 0) {
			cout << "\n正義のヒーローの前に大魔王は敗れました。" << endl;
				break;
		}
	}
}

int main()
{
	Taiketu_basho dokoka;

	dokoka.kurikaeshi_taiketu();
}