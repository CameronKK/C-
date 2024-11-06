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
	cout << "���}�߁B���`�̍U�����󂯂Ă݂�B" << endl;
	cout << "�ǂ��`��I�I�I�I" << endl;
	power -= n;

	if (power >= 0) {
		cout << "�i���݂̃p���[��" << power << "�ɂȂ����B�j" << endl;
	}
	else {
		cout << "���܂����I�p���[���g���������B" << endl;
		cout << "���������܂����I�I�������c" << endl;
	}
}

void Hero::kougeki_sareru(int n)
{
	cout << "�������B���}�̍U���������邱�Ƃ�����̂��B" << endl;
	power -= n;

	if (power >= 0) {
		cout << "�i���݂̃p���[��" << power << "�ɂȂ����B�j" << endl;
	}
	else {
		cout << "���ꂽ�B�������c" << endl;
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
	cout << "�喂���l�̈ꌂ���󂯂Ă݂�B" << endl;
	cout << "�ǂ��`��I�I�I�I" << endl;
	power -= n;

	if (power < 0) {
		cout << "���܂����I�I�I�p���[���g���������I�I" << endl;
		cout << "�ށA�ށA�ށB���O���B�������c" << endl;
	}
}

void Daimao::kougeki_sareru(int n)
{
	cout << "�������B���`�̖����̍U���������邱�Ƃ�����̂��B" << endl;
	power -= n;

	if (power < 0) {
		cout << "���ꂽ�I�I�I�������c" << endl;
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

	cout << "���Ȃ��Ƒ喂���u�[�Ƃ̌���ł��B\n" << endl;
	cout << "�喂���u�[�͍��W�P�`�T�̂ǂ����ɐ���ł��܂��B" << endl;
	cout << "���Ȃ����ǂ����ɐg���Ђ��߂Ă��������B" << endl;
	cout << "�g���Ђ��߂���W�i�P�`�T�̐��l�j����͂��Ă��������B" << endl;

	cin >> you_no_basho;
}

void Taiketu_basho::taiketu()
{
	int iti, kougeki;

	cout << "�����A���Ȃ��̍U���ł��B" << endl;
	cout << "�U���̈ʒu�i�P�`�T�j����͂��Ă��������B>> ";
	cin >> iti;

	cout << "�U���Ɏg���p���[�i" << you.getPower() << "�ȉ��̐��l�j����͂��Ă��������B>>";
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
		cout << "���Ȃ��̍U���͊O�ꂽ�悤�ł��B" << endl;
	}
	cout << endl;
	cout << "�喂���̍U���ł��B" << endl;
	cout << "�i�G���^�[�L�[�������Ă��������B�j" << endl;
	
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
		cout << "�喂���u�[�̍U���͊O�ꂽ�悤�ł��B" << endl;
	}
}

void Taiketu_basho::kurikaeshi_taiketu()
{
	while (1) {
		taiketu();
		if (you.getPower() < 0) {
			cout << "\n�喂���̑O�ɐ��`�̃q�[���[�͔s��܂����B" << endl;
			break;
		}

		if (bu.getPower() < 0) {
			cout << "\n���`�̃q�[���[�̑O�ɑ喂���͔s��܂����B" << endl;
				break;
		}
	}
}

int main()
{
	Taiketu_basho dokoka;

	dokoka.kurikaeshi_taiketu();
}