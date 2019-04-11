#include "DataStorage.h"
#include <iostream>
using namespace std;

int main()
{
	CDataStorage<int> dataStorate;	// ������ ���丮�� ����

	dataStorate.AddFirst(1);	// �ߺ� ��� ������ �߰�
	dataStorate.AddFirst(2);	// �ߺ� ��� ������ �߰�
	if (!dataStorate.AddFirstnOverlap(1))	// �ߺ� ����� ������ �߰�
	{
		cout << "�ߺ��� �������Դϴ�." << endl;
		cout << "�����ͼ� :: " << dataStorate.GetDataCount() << endl;	// ����� ������ �� ��ȯ
	}

	dataStorate.AddLast(3);
	dataStorate.AddLast(4);
	if (!dataStorate.AddLastnOverlap(3))	// �ߺ� ����� ������ �߰�
	{
		cout << "�ߺ��� �������Դϴ�." << endl;
		cout << "�����ͼ� :: " << dataStorate.GetDataCount() << endl;	// ����� ������ �� ��ȯ
	}

	// ������ ����ҿ� ���� �ܺ� ��ȸ ���
	for (auto data = dataStorate.ExternalTour(); data != nullptr; data = dataStorate.ExternalTour())
	{
		cout << data->GetData() << " ";
	}
	dataStorate.ExternalTourEnd();	// ��ȸ ����
	cout << endl;

	dataStorate.DeleteFirst();
	dataStorate.DeleteLast();

	// ������ ����ҿ� ���� �ܺ� ��ȸ ���
	for (auto data = dataStorate.ExternalTour(); data != nullptr; data = dataStorate.ExternalTour())
	{
		cout << data->GetData() << " ";
	}
	dataStorate.ExternalTourEnd();	// ��ȸ ����
	cout << endl;

	if (dataStorate.Find(1))
	{
		cout << "1�� DataStorage �ȿ� �����մϴ�." << endl;
	}
	else
	{
		cout << "1�� DataStorage �ȿ� �������� �ʽ��ϴ�." << endl;
	}

	dataStorate.
}