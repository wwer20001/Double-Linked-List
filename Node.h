//-------------------------------------------------------------------
//	Programed by G_rida
//	wwer20001@naver.com
//	Data Node
//	Version 1.02
//	- 양방향 연결 리스트용 노드
//	- 범용 데이터를 처리할 수 있게 템플릿으로 만들어졌음
//-------------------------------------------------------------------
/*	2015-04-07	Version 1.02
//	- SetData 함수의 매개변수의 참조와 포인터에서 받아온 데이터의 변조가
//	없음을 알리기 위해 매개변수에 const 선언을 추가함
//	- 각 Getter 함수 내부에서 데이터의 변조가 없음을 알리기 위해 함수에
//	const 선언을 추가함
//-------------------------------------------------------------------*/
/*	2015-04-03	Version 1.01
//	- 데이터를 노드에 넣는 SetData함수의 복사 생성자의 오버헤드를 줄이기 위해
//	매개변수를 참조형으로 바꿈
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