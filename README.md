# Double-Linked-List

Programed by G_rida

wwer20001@naver.com

Data Storage
Version 1.08
- 양방향 연결 리스트형의 데이터 저장소
- 모든 타입에 대응 가능하게 템플릿으로 구성되었음

## 2016-10-27
### Version 1.08
- 함수 이름 변경 
Head -> First
Tail -> Last
- AddFirstnOverlap() 함수와 AddLastnOverlap() 함수가 작업에 성공한
이후에 명시적으로 true 값을 반환하지 않던 문제 해결.
- 함수 삭제
void ShowAllData(); - 콘솔 기반의 함수라 삭제함.

## 2015-09-17
### Version 1.06
- 데이터 저장소 외부에서 iterator를 이용해 내부를 순회하는 함수
외부에서 CNode<T>* 타입의 변수를 만들어서 iterator로 활용해야 함
반환되는 노드를 통해서 기존 클래스의 연산자 오버로딩 없이 저장소의
외부에서 필요한 조건에 따라 내용을 검색하고 수정할 수 있음
CNode<T>* ExternalTour();

### Version 1.06a
- CNode<T>* ExternalTour(); 함수의 종료 후 m_nNow가 NULL값으로
재초기화되지 않음으로서 발생하는 버그를 제거하기 위해 ExternalTour가
종료되었음을 알리고 재초기화 하는 함수 추가
void ExternalTourEnd();

## 2015-04-12  
### Version 1.05
- 데이터 저장소 내부에서 값을 검색하여 삭제하는 함수 추가
bool SearchDelete(const T &d);

## 2015-04-11  
### Version 1.04a
- 헤더 파일과 소스 파일의 복잡한 포함관계를 해결하기 위해 템플릿 멤버
함수의 구현부를 헤더파일로 옮겨옴
- 불필요해진 DataStorage.cpp와 DataStoragePack.h를 삭제함

### Version 1.04b
- 데이터를 검색하여 꺼내고 삭제하는 함수 추가
bool SearchTake(T &d);
- 저장소 내부에 해당 값이 존재하는지 검색하는 함수 추가
bool Search(const T &d);
- 중복되지 않은 값만 저장소 내부에 저장하는 함수 추가
bool AddHeadnOverlap(const T &d);
bool AddTailnOverlap(const T &d);

## 2015-04-07  
### Version 1.03
- AddHead, AddTail 함수의 매개변수에서 원본 정보의 변조가 없음을 알리기
위해 매개변수에 const 선언을 추가함

## 2015-04-03  
### Version 1.02
- 데이터를 검색하여 꺼내는 함수 추가
bool SearchPeek(T &d);
- 분리되어 있는 템플릿 클래스의 선언부과 구현부를 이 헤더를 포함하는
곳에서 헤더와 소스파일을 동시에 불러와야되는 불편함을 해소하기 위해
패키지 형태의 헤더로 선언함

## 2015-04-02  
### Version 1.01
- 노드를 삭제하는 함수와 노드를 꺼내고 삭제하는 함수를 분리함
bool TakeHead(T &d);  bool TakeTail(T &d);
bool DeleteHead();    bool DeleteTail();
- 노드를 삭제하거나 꺼낸 이후에 데이터 카운트가 변하지 않던 버그 해결
