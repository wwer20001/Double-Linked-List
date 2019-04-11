//--------------------------------------------------------------------
//  Programed by G_rida
//  wwer20001@naver.com
//  Data Storage
//  Version 1.08
//  - ����� ���� ����Ʈ���� ������ �����
//  - ��� Ÿ�Կ� ���� �����ϰ� ���ø����� �����Ǿ���
//--------------------------------------------------------------------
/*  2016-10-27  Version 1.08
//  - �Լ� �̸� ���� 
//  Head -> First
//  Tail -> Last
//  - AddFirstnOverlap() �Լ��� AddLastnOverlap() �Լ��� �۾��� ������
//  ���Ŀ� ��������� true ���� ��ȯ���� �ʴ� ���� �ذ�.
//  - �Լ� ����
//  void ShowAllData(); - �ܼ� ����� �Լ��� ������.
//
//--------------------------------------------------------------------*/
/*  2016-03-24  Version 1.07
//  - ������ ��� ���� ��Ŀ��� ���� ���̺귯�� ������� ����
//
//--------------------------------------------------------------------*/
/*  2015-09-17  Version 1.06
//  - ������ ����� �ܺο��� iterator�� �̿��� ���θ� ��ȸ�ϴ� �Լ�
//  �ܺο��� CNode<T>* Ÿ���� ������ ���� iterator�� Ȱ���ؾ� ��
//  ��ȯ�Ǵ� ��带 ���ؼ� ���� Ŭ������ ������ �����ε� ���� �������
//  �ܺο��� �ʿ��� ���ǿ� ���� ������ �˻��ϰ� ������ �� ����
//  CNode<T>* ExternalTour();
//
//  Version 1.06a
//  - CNode<T>* ExternalTour(); �Լ��� ���� �� m_nNow�� NULL������
//  ���ʱ�ȭ���� �������μ� �߻��ϴ� ���׸� �����ϱ� ���� ExternalTour��
//  ����Ǿ����� �˸��� ���ʱ�ȭ �ϴ� �Լ� �߰�
//  void ExternalTourEnd();
//
//--------------------------------------------------------------------*/
/*	2015-04-12	Version 1.05
//	- ������ ����� ���ο��� ���� �˻��Ͽ� �����ϴ� �Լ� �߰�
//	bool SearchDelete(const T &d);
//
//--------------------------------------------------------------------*/
/*	2015-04-11	Version 1.04a
//	- ��� ���ϰ� �ҽ� ������ ������ ���԰��踦 �ذ��ϱ� ���� ���ø� ���
//	�Լ��� �����θ� ������Ϸ� �Űܿ�
//	- ���ʿ����� DataStorage.cpp�� DataStoragePack.h�� ������
//
//	Version 1.04b
//	- �����͸� �˻��Ͽ� ������ �����ϴ� �Լ� �߰�
//	bool SearchTake(T &d);
//	- ����� ���ο� �ش� ���� �����ϴ��� �˻��ϴ� �Լ� �߰�
//	bool Search(const T &d);
//	- �ߺ����� ���� ���� ����� ���ο� �����ϴ� �Լ� �߰�
//	bool AddHeadnOverlap(const T &d);
//	bool AddTailnOverlap(const T &d);
//
//--------------------------------------------------------------------*/
/*	2015-04-07	Version 1.03
//	- AddHead, AddTail �Լ��� �Ű��������� ���� ������ ������ ������ �˸���
//	���� �Ű������� const ������ �߰���
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

	// ������ ����Ұ� ������� �˻��Ѵ�.
	// return(bool) :: ������ ����Ұ� ����ִٸ� true, �ƴ϶�� false ��ȯ 
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

	// ������ ����� ������ ������ ���� ��ȯ�Ѵ�.
	// return(int) :: ������ ����� ������ ������ ���� 
	int GetDataCount() const
	{
		return m_iDataCount;
	}

	// ������ ����� �պκп� ��带 �߰��Ѵ�.
	// Param
	// const T &data :: ��忡 �Էµ� ������
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
	
	// ������ ����� �޺κп� ��带 �߰��Ѵ�.
	// Param
	// const T &data :: ��忡 �Էµ� ������
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

	// ������ ����� �պκп� ��带 �ߺ����� �ʰ� �߰��Ѵ�.
	// Param
	// const T &data :: ��忡 �Էµ� ������
	// return(bool) :: ������ ���� ����
	// - ���Կ� ������ ��� true, ������ ��� false ��ȯ
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

	// ������ ����� �޺κп� ��带 �ߺ����� �ʰ� �߰��Ѵ�.
	// Param
	// const T &data :: ��忡 �Էµ� ������
	// return(bool) :: ������ ���� ����
	// - ���Կ� ������ ��� true, ������ ��� false ��ȯ
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

	// ������ ����� ���ο��� ���� �����ϴ��� �˻��ϴ� �Լ�
	// Param
	// const T &d :: �˻��� ���� �Լ� ���η� ����
	// return(bool) :: �˻��� ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� ���ο��� ���� �˻��Ͽ� ������ �Լ�
	// Param
	// T &d :: �˻��� ���� �Լ� ���η� ����
	// - �˻��� �����ʹ� �Ű����� T &d�� ���� �Լ� �ܺη� ����
	// return(bool) :: �˻��� ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� ���ο��� ���� �˻��Ͽ� ������ �����ϴ� �Լ�
	// Param
	// T &d :: �˻��Ͽ� ������ ���� �Լ� ���η� ����
	// - ������ �����ʹ� �Ű����� T &d�� ���� �Լ� �ܺη� ����
	// return(bool) :: �˻��� ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� ���ο��� ���� �˻��Ͽ� �����ϴ� �Լ�
	// Param
	// const T &d :: �˻��Ͽ� ������ ���� �Լ� ���η� ����
	// return(bool) :: ������ ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� �ܺο��� iterator�� �̿��� ���θ� ��ȸ�ϴ� �Լ�
	// �ܺο��� CNode<T>* Ÿ���� ������ ���� iterator�� Ȱ���ؾ� ��
	// return(CNode<T>*) :: ���� ���� ���� ��带 ��ȯ��
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

	// �ܺ� ��ȯ�� �����Ѵ�.
	void ExternalTourEnd()
	{
		m_nNow = nullptr;
	}

	// ������ ����� �պκ��� ����� �����͸� ������ �����Ѵ�.
	// Param
	// T &data :: ���� �����͸� �ܺη� ������ ����
	// - ������ �����ʹ� �Ű����� T &d�� ���� ��ȯ��
	// return(bool) :: ������ ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� �޺κ��� ����� �����͸� ������ �����ϴ� �Լ�
	// Param
	// T &data :: ���� �����͸� �ܺη� ������ ����
	// - ������ �����ʹ� �Ű����� T &data�� ���� ��ȯ��
	// return(bool) :: ������ ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� �պκ��� ����� �����͸� �����ϴ� �Լ�
	// return(bool) :: ������ ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� �޺κ��� ����� �����͸� �����ϴ� �Լ�
	// return(bool) :: ������ ���������� true, ���������� false�� ��ȯ
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

	// ������ ����� ������ ��� �����͸� �����ϴ� �Լ�
	void Clear()
	{
		while (DeleteHead());

		m_iDataCount = 0;
	}
};