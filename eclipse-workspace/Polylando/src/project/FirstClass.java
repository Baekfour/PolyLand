package project;

import java.util.Scanner;

public class FirstClass {
	OrderData orderItem = new OrderData();
	Scanner scanner = new Scanner(System.in);
	public void First() {
		orderItem.disprice = 0;
		System.out.printf("**********************************************************\n");
		System.out.printf("�̿�� ������ �����ϼ���.\n");
		System.out.printf("1. �����̿��(�Ե����� + �μӹڹ���)\n");
		System.out.printf("2. ��ũ�̿��(�Ե�����)\n");
		orderItem.inputTicketType = scanner.nextInt();
		System.out.printf("\n");
		System.out.printf("������ �����ϼ���.\n");
		System.out.printf("1. �ְ���\n");
		System.out.printf("2. After4\n");
		orderItem.inputTicketType = scanner.nextInt();
		System.out.printf("\n");
		System.out.printf("�ֹε�Ϲ�ȣ���ڸ��� �Է��ϼ���.\n");
		orderItem.inputRegisterNum = scanner.nextInt();
		System.out.printf("\n");
		System.out.printf("�ֹε�Ϲ�ȣ ���ڸ� ù��°���ڸ� �Է��ϼ���.\n");
		orderItem.inputRegisterNum2 = scanner.nextInt();
		System.out.printf("\n");
		System.out.printf("�������� �����ϼ���.\n");
		System.out.printf("1. ���� (���� ���� �ڵ�ó��)\n");
		System.out.printf("2. �����\n");
		System.out.printf("3. ����������\n");
		System.out.printf("4. �ް��庴\n");
		System.out.printf("5. �ӻ��\n");
		System.out.printf("6. �ٵ��� �ູī��\n");
		orderItem.inputbenefit = scanner.nextInt();
//		System.out.printf("������ �����Ͻðڽ��ϱ�?.\n");
//		addTicket = scanner.nextInt();
		System.out.printf("\n");
	}
}
