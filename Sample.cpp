#include "DataStorage.h"
#include <iostream>
using namespace std;

int main()
{
	CDataStorage<int> dataStorate;	// 데이터 스토리지 선언

	dataStorate.AddFirst(1);	// 중복 허용 데이터 추가
	dataStorate.AddFirst(2);	// 중복 허용 데이터 추가
	if (!dataStorate.AddFirstnOverlap(1))	// 중복 비허용 데이터 추가
	{
		cout << "중복된 데이터입니다." << endl;
		cout << "데이터수 :: " << dataStorate.GetDataCount() << endl;	// 저장된 데이터 수 반환
	}

	dataStorate.AddLast(3);
	dataStorate.AddLast(4);
	if (!dataStorate.AddLastnOverlap(3))	// 중복 비허용 데이터 추가
	{
		cout << "중복된 데이터입니다." << endl;
		cout << "데이터수 :: " << dataStorate.GetDataCount() << endl;	// 저장된 데이터 수 반환
	}

	// 데이터 저장소에 대한 외부 순회 방법
	for (auto data = dataStorate.ExternalTour(); data != nullptr; data = dataStorate.ExternalTour())
	{
		cout << data->GetData() << " ";
	}
	dataStorate.ExternalTourEnd();	// 순회 종료
	cout << endl;

	dataStorate.DeleteFirst();
	dataStorate.DeleteLast();

	// 데이터 저장소에 대한 외부 순회 방법
	for (auto data = dataStorate.ExternalTour(); data != nullptr; data = dataStorate.ExternalTour())
	{
		cout << data->GetData() << " ";
	}
	dataStorate.ExternalTourEnd();	// 순회 종료
	cout << endl;

	if (dataStorate.Find(1))
	{
		cout << "1은 DataStorage 안에 존재합니다." << endl;
	}
	else
	{
		cout << "1은 DataStorage 안에 존재하지 않습니다." << endl;
	}

	dataStorate.
}