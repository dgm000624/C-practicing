//#include <stdio.h>
//
//struct vision {
//	double left;
//	double right;
//};
//
//struct vision exchange(struct vision view);
//
//void main()
//{
//	struct vision robot;
//	printf("�÷� �Է�: ");
//	scanf_s("%lf %lf", &robot.left, &robot.right);
//	robot = exchange(robot);
//	printf("�ٲ� �÷� : %.2lf %.2lf", robot.left, robot.right);
//
//}
//
//struct vision exchange(struct vision view)
//{
//	struct vision human;
//	human.right = view.left;
//	human.left = view.right;
//	return human;
//}