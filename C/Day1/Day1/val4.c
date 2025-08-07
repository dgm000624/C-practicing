#include <stdio.h>
#include <string.h>

//문자는 '', 문자열은 ""로 묶는다.
//문자는 char, 문자열은 char[]로 선언한다.
//배열명은 배열의 시작수조를 나타낸드ㅏㅏㅏ
// 문자열은 문자열크기 +1의 배열크기를 가진다. (마지막 눌(\0)때문에)


void main()
{
	char ch = 'a';							//문자
	printf("ch: %c, ch: %d\n", ch, ch);

	char str[6]= "apple";					//배열(배열이름은 시작주소, for)
	printf("str: %s\n", str);

	printf("str[0]: %s\n", str[0]);
	printf("str[4]: %s\n", str[4]);
	printf("str[5]: %s\n", str[5]);

	char str1[] = "banana";
	char str2[];
	str2 = strcat(str, str1);
}
