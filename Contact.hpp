
#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact 
{
	private:
		std::string 	firstName;
		std::string 	lastName;
		std::string 	nickName;
		std::string 	phoneNum;
		std::string 	darkestSecret;
	public:
		int 			inputContact(void); // 처음에 add 함수 실행시 정보 받음
		void 			printSavedList(int idx); // 써치 할 때 저장된 idx까지 한 줄씩 프린트
		void 			printDetail(void); // 써치 후 선택한 연락처 정보 쭈루룩
		std::string 	getFirstName(void);
		
};

#endif
