//-------------------------------------------------------------------
//	Programed by G_rida
//	wwer20001@naver.com
//	Data Node
//	Version 1.02
//	- ����� ���� ����Ʈ�� ���
//	- ���� �����͸� ó���� �� �ְ� ���ø����� ���������
//-------------------------------------------------------------------
/*	2015-04-07	Version 1.02
//	- SetData �Լ��� �Ű������� ������ �����Ϳ��� �޾ƿ� �������� ������
//	������ �˸��� ���� �Ű������� const ������ �߰���
//	- �� Getter �Լ� ���ο��� �������� ������ ������ �˸��� ���� �Լ���
//	const ������ �߰���
//-------------------------------------------------------------------*/
/*	2015-04-03	Version 1.01
//	- �����͸� ��忡 �ִ� SetData�Լ��� ���� �������� ������带 ���̱� ����
//	�Ű������� ���������� �ٲ�
//	void SetData(T d);	->	void SetData(T& d);
//-------------------------------------------------------------------*/
#pragma once

template<typename T>
class CNode
{
private:
	CNode *prev;
	T data;
	CNode *next;
public:	// Constructor & Destructor
	CNode() : prev(nullptr), next(nullptr) {}
public:	// Setter
	void SetData(const T& d) { data = d; }
	void SetPrev(CNode *p) { prev = p; }
	void SetNext(CNode *n) { next = n; }
public:	// Accessor
	T GetData() const { return data; }
	CNode* GetPrev() const { return prev; }
	CNode* GetNext() const { return next; }
};