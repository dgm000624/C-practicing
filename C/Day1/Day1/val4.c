#include <stdio.h>
#include <string.h>

//���ڴ� '', ���ڿ��� ""�� ���´�.
//���ڴ� char, ���ڿ��� char[]�� �����Ѵ�.
//�迭���� �迭�� ���ۼ����� ��Ÿ���夿����
// ���ڿ��� ���ڿ�ũ�� +1�� �迭ũ�⸦ ������. (������ ��(\0)������)


void main()
{
	char ch = 'a';							//����
	printf("ch: %c, ch: %d\n", ch, ch);

	char str[6]= "apple";					//�迭(�迭�̸��� �����ּ�, for)
	printf("str: %s\n", str);

	printf("str[0]: %s\n", str[0]);
	printf("str[4]: %s\n", str[4]);
	printf("str[5]: %s\n", str[5]);

	char str1[] = "banana";
	char str2[];
	str2 = strcat(str, str1);
}
