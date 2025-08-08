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
//	printf("시력 입력: ");
//	scanf_s("%lf %lf", &robot.left, &robot.right);
//	robot = exchange(robot);
//	printf("바뀐 시력 : %.2lf %.2lf", robot.left, robot.right);
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