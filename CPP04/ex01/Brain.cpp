#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain (const Brain &orig)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = orig;
}

Brain& Brain::operator=(const Brain &orig)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (!(this == &orig)) // 사실 고정 배열이라 필요 없다네~
		std::copy(orig.ideas, orig.ideas + 100, this->ideas);
	return (*this); // 참조 반환
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	// if ideas was heap : _brain 이 프리 담당 ex rules of three delete _brain->Brain destructor -> delete[] ideas
}

const std::string &Brain::getIdea(int idx) const
{
	// std::cout << "get idx = " << idx << std::endl;
	static const std::string error = "-ERROR_getter_idx-"; // 다음엔 걍 참조를 리턴 안하는 게터를 해보자..
	if (idx < 0 || idx >= 100)
	{	
		std::cout << "wrong idx to get: use IDX 0 to 99";
		return (error);
	}
	return (this->ideas[idx]);
}
// 지금도 스태틱으로 빈 문자열 만들어 리턴해두 ㄱㅊ
// if not ref return ? 
// -> std::string return : 걍 return "ERROR";  "" 기타등등
// const std::string* : return nullptr; return &this->ideas[idx];
//                       ******************* 
// 이어서 auto는 c++11 문법, c++98 에선 auto 오른 쪽 값 추정이고 뭐고 없다네 
// if (auto idea = _brain.getIdea(i)) 이건 C++17 의 if (init; condition)
//		std::cout << *idea;
// auto ? 오른쪽 표현식으로 정확히 타입을 추론 ex(auto x = 10; 아 인트구나) 
// -> const std::string* idea = _brain.getIdea(i);
// 즉 위를 다시 쓰면
// const std::string* idea = brain.getIdea(i);
// if (idea) // 포인터는 조건문에서 null 아니면 true
//	std::cout << *idea;
// cosnt std::string& get();
// auto a = get(); 이 경우는 복사임 참조 유지하려면 auto& a = get();

void Brain::setIdea(int idx, std::string input)
{
	// std::cout << "set idx = " << idx << std::endl;
	if (idx < 0 || idx >= 100)
	{	
		std::cout << "wrong idx to set: use IDX 0 to 99 not set" << std::endl;
		return ;
	}
	this->ideas[idx] = input;
}

