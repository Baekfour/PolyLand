package project;


	import java.text.SimpleDateFormat;
	import java.util.ArrayList;
	import java.util.Calendar;
	import java.util.Scanner;



	public class MethodZip {
		
		Scanner scanner = new Scanner(System.in);
		OrderData orderItem = new OrderData();
		public Object applymethod;
		FirstClass first = new FirstClass();
		RealAgeType RealAge = new RealAgeType();
		FeeType feetype = new FeeType();
		PriceType pricetype = new PriceType();
		DisPriceType dispricetype = new DisPriceType();
		
		public void LastWhile() {
			ArrayList<OrderData> orderList = new ArrayList<OrderData>();
			if (pricetype.orderItem.price == StaticValue.AllDayOlderTK || pricetype.orderItem.price == StaticValue.ParkDayOlderTK
					|| pricetype.orderItem.price == StaticValue.AllAfter4OlderTK
					|| pricetype.orderItem.price == StaticValue.ParkAfter4OlderTK) {
				dispricetype.orderItem.disprice = pricetype.orderItem.price; // ���� ����
				System.out.printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", dispricetype.orderItem.disprice);
			} else {
				System.out.printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", dispricetype.orderItem.disprice);
			}
			orderItem.totalmoney += dispricetype.orderItem.disprice;

			orderList.add(orderItem);
			System.out.printf("��� �߱� �Ͻðڽ��ϱ�?\n");
			System.out.printf("Ƽ�� �߱� : 1\n");
			System.out.printf("���� : 2\n");
			System.out.printf("ó������ : 3\n");
			orderItem.extend = scanner.nextInt();
			System.out.printf("%d", first.orderItem.extend);
			System.out.printf("\n");
		}

		public void ArrayPart() {
			ArrayList<OrderData> orderList = new ArrayList<OrderData>();
			System.out.printf(
					"\n\n*************************************** ���� ���� *****************************************\n");
			System.out.printf("�̿�� ����\t�̿�� �ɼ�\t���̺� ����\t����\t\t������\n");
			for (int index = 0; index < orderList.size(); index++) {
				switch (orderList.get(index).inputTicketType) {
				case 1:
					System.out.printf("�����̿��\t\t");
					break;

				case 2:
					System.out.printf("��ũ�̿��\t\t");
					break;

				}
				switch (orderList.get(index).inputTicketType) {
				case 1:
					System.out.printf("1Day\t\t");
					break;

				case 2:
					System.out.printf("After4\t\t");
					break;

				}
				switch (orderList.get(index).basicFeeType) {
				case 1:
					System.out.printf("����\t\t");
					break;

				case 2:
					System.out.printf("����\t\t");
					break;

				case 3:
					System.out.printf("û�ҳ�\t\t");
					break;

				case 4:
					System.out.printf("���\t\t");
					break;

				case 5:
					System.out.printf("���̺�\t\t");
					break;

				}
//				orderList[orderCount][3] = 1;
				orderList.get(index).disprice = dispricetype.orderItem.disprice;
				System.out.printf("%d\t\t", orderList.get(index).disprice);
				if (orderList.get(index).inputbenefit == 2) {
					System.out.printf("*����� ���\n");
				} else if (orderList.get(index).inputbenefit == 3) {
					System.out.printf("*���������� ���\n");
				} else if (orderItem.inputTicketType == 1 && orderList.get(index).inputbenefit == 4) {
					System.out.printf("*�ް��庴 ���\n");
				} else if (orderItem.inputTicketType == 1 && orderList.get(index).inputbenefit == 5) {
					System.out.printf("*�ӻ�� ���\n");
				} else if (orderItem.inputTicketType == 1 && orderList.get(index).inputbenefit == 6) {
					System.out.printf("*�ٵ��� �ູī�� ���\n");
				} else {
					System.out.printf("*������ ����\n");
				}
			}
			System.out.printf("\n---------------------------------------------------------------------------\n");
			System.out.printf("���� �ݾ�\t\t\t\t\t\t\t%d��\n\n", orderItem.totalmoney);
		}
	}



