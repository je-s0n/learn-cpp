#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_

/*
컴파일 에러 발생 예시
*/
// 클래스 템플릿 정의
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0);
	void ShowPosition() const;
};

#endif
