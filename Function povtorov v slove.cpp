#include <iostream>
using namespace std;

// ������� ��� ������ ��������� � ������
// + ����� �������, � ������� ���������� ���������
int pos(char *s, char *c, int n)
{
	int i, j; // �������� ��� ������
	int lenC, lenS; // ����� �����

	//������� ������� ������ ��������� � ��������
	for (lenC = 0; c[lenC]; lenC++);
	for (lenS = 0; s[lenS]; lenS++);

	for (i = 0; i <= (lenS - lenC); i++) // ���� ���� ����������� ������
	{
		for (j = 0; s[i + j] == c[j]; j++); // ��������� ���������� �����������
		// ���� ����������� ��������� �� ����� ��������
		// ������ �� ������� ����� ������, ������ ���������� ����������
		// ��������� 0-����������  ( '\0' )
		if ((j - lenC == 1) && (i == lenS - lenC) && !(n - 1)) return i;
		if (j == lenC)
			if (n - 1) n--;
			else return i;
	}
	//����� ������ -1 ��� ��������� ���������� ���������
	return -1;
}

int main()
{
	char s[] = "Morshynshkashaaaaash";
	char c[] = "s";





	int i, n = 0;

	for (i = 1; n != -1; i++)
	{
		n = pos(s, c, i);

		if (n >= 0)
			std::cout << n << std::endl;
	}
	system("pause");
	return 0;
}