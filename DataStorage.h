//--------------------------------------------------------------------
//  Programed by G_rida
//  wwer20001@naver.com
//  Data Storage
//  Version 1.08
//  - 양방향 연결 리스트형의 데이터 저장소
//  - 모든 타입에 대응 가능하게 템플릿으로 구성되었음
//--------------------------------------------------------------------
/*  2016-10-27  Version 1.08
//  - 함수 이름 변경 
//  Head -> First
//  Tail -> Last
//  - AddFirstnOverlap() 함수와 AddLastnOverlap() 함수가 작업에 성공한
//  이후에 명시적으로 true 값을 반환하지 않던 문제 해결.
//  - 함수 삭제
//  void ShowAllData(); - 콘솔 기반의 함수라 삭제함.
//
//--------------------------------------------------------------------*/
/*  2016-03-24  Version 1.07
//  - 기존의 헤더 포함 방식에서 정적 라이브러리 방식으로 변경
//
//--------------------------------------------------------------------*/
/*  2015-09-17  Version 1.06
//  - 데이터 저장소 외부에서 iterator를 이용해 내부를 순회하는 함수
//  외부에서 CNode<T>* 타입의 변수를 만들어서 iterator로 활용해야 함
//  반환되는 노드를 통해서 기존 클래스의 연산자 오버로딩 없이 저장소의
//  외부에서 필요한 조건에 따라 내용을 검색하고 수정할 수 있음
//  CNode<T>* ExternalTour();
//
//  Version 1.06a
//  - CNode<T>* ExternalTour(); 함수의 종료 후 m_nNow가 NULL값으로
//  재초기화되지 않음으로서 발생하는 버그를 제거하기 위해 ExternalTour가
//  종료되었음을 알리고 재초기화 하는 함수 추가
//  void ExternalTourEnd();
//
//--------------------------------------------------------------------*/
/*	2015-04-12	Version 1.05
//	- 데이터 저장소 내부에서 값을 검색하여 삭제하는 함수 추가
//	bool SearchDelete(const T &d);
//
//--------------------------------------------------------------------*/
/*	2015-04-11	Version 1.04a
//	- 헤더 파일과 소스 파일의 복잡한 포함관계를 해결하기 위해 템플릿 멤버
//	함수의 구현부를 헤더파일로 옮겨옴
//	- 불필요해진 DataStorage.cpp와 DataStoragePack.h를 삭제함
//
//	Version 1.04b
//	- 데이터를 검색하여 꺼내고 삭제하는 함수 추가
//	bool SearchTake(T &d);
//	- 저장소 내부에 해당 값이 존재하는지 검색하는 함수 추가
//	bool Search(const T &d);
//	- 중복되지 않은 값만 저장소 내부에 저장하는 함수 추가
//	bool AddHeadnOverlap(const T &d);
//	bool AddTailnOverlap(const T &d);
//
//--------------------------------------------------------------------*/
/*	2015-04-07	Version 1.03
//	- AddHead, AddTail 함수의 매개변수에서 원본 정보의 변조가 없음을 알리기
//	위해 매개변수에 const 선언을 추가함
//
//--------------------------------------------------------------------*/

#pragma once

#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class CDataStorage
{
private:
	CNode<T> *m_nNow;
	CNode<T> *m_nHead;
	CNode<T> *m_nTail;
	int m_iDataCount;
public:	// Constructor & Destructor
	CDataStorage() : m_nNow(nullptr), m_nHead(nullptr), m_nTail(nullptr), m_iDataCount(0) {}
public:	// Basic member function

	// 데이터 저장소가 비었는지 검사한다.
	// return(bool) :: 데이터 저장소가 비어있다면 true, 아니라면 false 반환 
	bool IsEmpty() const
	{
		if (m_nHead == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 데이터 저장소 내부의 데이터 수를 반환한다.
	// return(int) :: 데이터 저장소 내부의 데이터 개수 
	int GetDataCount() const
	{
		return m_iDataCount;
	}

	// 데이터 저장소 앞부분에 노드를 추가한다.
	// Param
	// const T &data :: 노드에 입력될 데이터
	void AddFirst(const T &data)
	{
		CNode<T> *newNode = new CNode<T>;

		newNode->SetData(data);

		if (IsEmpty())
		{
			m_nHead = newNode;
			m_nTail = newNode;
		}
		else
		{
			m_nHead->SetPrev(newNode);
			newNode->SetNext(m_nHead);
			m_nHead = newNode;
		}
		m_iDataCount++;
	}
	
	// 데이터 저장소 뒷부분에 노드를 추가한다.
	// Param
	// const T &data :: 노드에 입력될 데이터
	void AddLast(const T &data)
	{
		CNode<T> *newNode = new CNode<T>;

		newNode->SetData(data);

		if (IsEmpty())
		{
			m_nHead = newNode;
			m_nTail = newNode;
		}
		else
		{
			m_nTail->SetNext(newNode);
			newNode->SetPrev(m_nTail);
			m_nTail = newNode;
		}
		m_iDataCount++;
	}

	// 데이터 저장소 앞부분에 노드를 중복되지 않게 추가한다.
	// Param
	// const T &data :: 노드에 입력될 데이터
	// return(bool) :: 삽입의 성공 여부
	// - 삽입에 성공한 경우 true, 실패한 경우 false 반환
	bool AddFirstnOverlap(const T &data)
	{
		if (Find(data))
		{
			return false;
		}

		CNode<T> *newNode = new CNode<T>;

		newNode->SetData(data);

		if (IsEmpty())
		{
			m_nHead = newNode;
			m_nTail = newNode;
		}
		else
		{
			m_nHead->SetPrev(newNode);
			newNode->SetNext(m_nHead);
			m_nHead = newNode;
		}
		m_iDataCount++;

		return true;
	}

	// 데이터 저장소 뒷부분에 노드를 중복되지 않게 추가한다.
	// Param
	// const T &data :: 노드에 입력될 데이터
	// return(bool) :: 삽입의 성공 여부
	// - 삽입에 성공한 경우 true, 실패한 경우 false 반환
	bool AddLastnOverlap(const T &data)
	{
		if (Find(data))
		{
			return false;
		}

		CNode<T> *newNode = new CNode<T>;

		newNode->SetData(data);

		if (IsEmpty())
		{
			m_nHead = newNode;
			m_nTail = newNode;
		}
		else
		{
			m_nTail->SetNext(newNode);
			newNode->SetPrev(m_nTail);
			m_nTail = newNode;
		}
		m_iDataCount++;

		return true;
	}

	// 데이터 저장소 내부에서 값이 존재하는지 검색하는 함수
	// Param
	// const T &d :: 검색할 값을 함수 내부로 전달
	// return(bool) :: 검색에 성공했을때 true, 실패했을때 false를 반환
	bool Find(const T &d)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			CNode<T> *cur = m_nHead;

			while (cur != nullptr)
			{
				if (cur->GetData() == d)
				{
					return true;
				}
				cur = cur->GetNext();
			}
			return false;
		}
	}

	// 데이터 저장소 내부에서 값을 검색하여 꺼내는 함수
	// Param
	// T &d :: 검색할 값을 함수 내부로 전달
	// - 검색된 데이터는 매개변수 T &d를 통해 함수 외부로 전달
	// return(bool) :: 검색에 성공했을때 true, 실패했을때 false를 반환
	bool FindPeek(T &d)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			CNode<T> *cur = m_nHead;

			while (cur != nullptr)
			{
				if (cur->GetData() == d)
				{
					d = cur->GetData();
					return true;
				}
				cur = cur->GetNext();
			}
			return false;
		}
	}

	// 데이터 저장소 내부에서 값을 검색하여 꺼내고 삭제하는 함수
	// Param
	// T &d :: 검색하여 삭제할 값을 함수 내부로 전달
	// - 삭제된 데이터는 매개변수 T &d를 통해 함수 외부로 전달
	// return(bool) :: 검색에 성공했을때 true, 실패했을때 false를 반환
	bool FindTake(T &d)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			CNode<T> *cur = m_nHead;

			while (cur != nullptr)
			{
				if (cur->GetData() == d)
				{
					d = cur->GetData();

					if (cur == m_nHead && cur == m_nTail)
					{
						m_nHead = m_nTail = nullptr;
					}
					else if (cur == m_nHead)
					{
						m_nHead = m_nHead->GetNext();

						m_nHead->SetPrev(nullptr);
					}
					else if (cur == m_nTail)
					{
						m_nTail = m_nTail->GetPrev();

						m_nTail->SetNext(nullptr);
					}
					else
					{
						cur->GetNext()->SetPrev(cur->GetPrev());
						cur->GetPrev()->SetNext(cur->GetNext());
					}

					delete cur;
					m_iDataCount--;

					return true;
				}
				cur = cur->GetNext();
			}
			return false;
		}
	}

	// 데이터 저장소 내부에서 값을 검색하여 삭제하는 함수
	// Param
	// const T &d :: 검색하여 삭제할 값을 함수 내부로 전달
	// return(bool) :: 삭제에 성공했을때 true, 실패했을때 false를 반환
	bool FindDelete(const T &d)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			CNode<T> *cur = m_nHead;

			while (cur != nullptr)
			{
				if (cur->GetData() == d)
				{
					if (cur == m_nHead && cur == m_nTail)
					{
						m_nHead = m_nTail = nullptr;
					}
					else if (cur == m_nHead)
					{
						m_nHead = m_nHead->GetNext();

						m_nHead->SetPrev(nullptr);
					}
					else if (cur == m_nTail)
					{
						m_nTail = m_nTail->GetPrev();

						m_nTail->SetNext(nullptr);
					}
					else
					{
						cur->GetNext()->SetPrev(cur->GetPrev());
						cur->GetPrev()->SetNext(cur->GetNext());
					}

					delete cur;
					m_iDataCount--;

					return true;
				}
				cur = cur->GetNext();
			}
			return false;
		}
	}

	// 데이터 저장소 외부에서 iterator를 이용해 내부를 순회하는 함수
	// 외부에서 CNode<T>* 타입의 변수를 만들어서 iterator로 활용해야 함
	// return(CNode<T>*) :: 현재 참조 중인 노드를 반환함
	CNode<T>* ExternalTour()
	{
		if (m_nNow == nullptr)
		{
			m_nNow = m_nHead;
			return m_nNow;
		}

		m_nNow = m_nNow->GetNext();

		return m_nNow;
	}

	// 외부 순환을 종료한다.
	void ExternalTourEnd()
	{
		m_nNow = nullptr;
	}

	// 데이터 저장소 앞부분의 노드의 데이터를 꺼내고 삭제한다.
	// Param
	// T &data :: 꺼낸 데이터를 외부로 가져갈 변수
	// - 꺼내진 데이터는 매개변수 T &d를 통해 반환됨
	// return(bool) :: 삭제에 성공했을때 true, 실패했을때 false를 반환
	bool TakeFirst(T &data)
	{
		if (IsEmpty())
		{
			return false;
		}

		CNode<T> *tNode = m_nHead;
		data = tNode->GetData();

		if (m_nHead == m_nTail)
		{
			m_nHead = m_nTail = nullptr;
		}
		else
		{
			m_nHead = m_nHead->GetNext();
			m_nHead->SetPrev(nullptr);
		}

		delete tNode;
		m_iDataCount--;
		return true;
	}

	// 데이터 저장소 뒷부분의 노드의 데이터를 꺼내고 삭제하는 함수
	// Param
	// T &data :: 꺼낸 데이터를 외부로 가져갈 변수
	// - 꺼내진 데이터는 매개변수 T &data를 통해 반환됨
	// return(bool) :: 삭제에 성공했을때 true, 실패했을때 false를 반환
	bool TakeLast(T &data)
	{
		if (IsEmpty())
		{
			return false;
		}

		CNode<T> *tNode = m_nTail;
		data = tNode->GetData();

		if (m_nHead == m_nTail)
		{
			m_nHead = m_nTail = nullptr;
		}
		else
		{
			m_nTail = m_nTail->GetPrev();
			m_nTail->SetNext(nullptr);
		}

		delete tNode;
		m_iDataCount--;
		return true;
	}

	// 데이터 저장소 앞부분의 노드의 데이터를 삭제하는 함수
	// return(bool) :: 삭제에 성공했을때 true, 실패했을때 false를 반환
	bool DeleteFirst()
	{
		if (IsEmpty())
		{
			return false;
		}

		CNode<T> *rNode = m_nHead;

		if (m_nHead == m_nTail)
		{
			m_nHead = m_nTail = nullptr;
		}
		else
		{
			m_nHead = m_nHead->GetNext();
			m_nHead->SetPrev(nullptr);
		}

		delete rNode;
		m_iDataCount--;
		return true;
	}

	// 데이터 저장소 뒷부분의 노드의 데이터를 삭제하는 함수
	// return(bool) :: 삭제에 성공했을때 true, 실패했을때 false를 반환
	bool DeleteLast()
	{
		if (IsEmpty())
		{
			return false;
		}

		CNode<T> *rNode = m_nTail;

		if (m_nHead == m_nTail)
		{
			m_nHead = m_nTail = nullptr;
		}
		else
		{
			m_nTail = m_nTail->GetPrev();
			m_nTail->SetNext(nullptr);
		}

		delete rNode;
		m_iDataCount--;
		return true;
	}

	// 데이터 저장소 내부의 모든 데이터를 삭제하는 함수
	void Clear()
	{
		while (DeleteHead());

		m_iDataCount = 0;
	}
};