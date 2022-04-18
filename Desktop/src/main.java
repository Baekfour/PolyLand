import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Scanner;

public class main {
	static final int AllDayAdultTK = 62000;
	static final int ParkDayAdultTK = 59000;
	static final int AllDayTeenTK = 54000;
	static final int ParkDayTeenTK = 52000;
	static final int AllDayChildTK = 47000;
	static final int ParkDayChildTK = 46000;
	static final int AllDayBabyTK = 15000;
	static final int ParkDayBabyTK = 15000;
	static final int AllDayOlderTK = 15000;
	static final int ParkDayOlderTK = 15000;
	static final int AllAfter4AdultTK = 50000;
	static final int ParkAfter4AdultTK = 47000;
	static final int AllAfter4TeenTK = 43000;
	static final int ParkAfter4TeenTK = 41000;
	static final int AllAfter4ChildTK = 36000;
	static final int ParkAfter4ChildTK = 35000;
	static final int AllAfter4BabyTK = 15000;
	static final int ParkAfter4BabyTK = 15000;
	static final int AllAfter4OlderTK = 15000;
	static final int ParkAfter4OlderTK = 15000;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int[][] orderList = new int[20][20];
		int inputType = 0;
		int inputTicket =  0;
		int inputRegisterNum = 0;
		int inputRegisterNum2 = 0;
		int inputbenefit = 0;
		int price = 0;
		int money = 0;
		int extend;
		int totalmoney = 0;
		int numberofticket = 1;
		int basicFeeType = 0;
		int orderCount = 0;
		int addTicket = 0;
		int today;
		int year;
		int month;
		int day;
		Calendar cal = Calendar.getInstance();
	    SimpleDateFormat sdt = new SimpleDateFormat("YYMMdd");
	    today = Integer.parseInt(sdt.format(cal.getTime()));
	    System.out.println(today);
	    year = 2000 + today/10000;
	    month = today%10000/100;
	    day = today%100;
		do {
			money = 0;			
			System.out.printf("**********************************************************");
			System.out.printf("�̿�� ������ �����ϼ���.\n");
			System.out.printf("1. �����̿��(�Ե����� + �μӹڹ���)\n");
			System.out.printf("2. ��ũ�̿��(�Ե�����)\n");
			inputType = scanner.nextInt();
			System.out.printf("\n");
			System.out.printf("������ �����ϼ���.\n");
			System.out.printf("1. �ְ���\n");
			System.out.printf("2. After4\n");
			inputTicket = scanner.nextInt();
			System.out.printf("\n");
			System.out.printf("�ֹε�Ϲ�ȣ���ڸ��� �Է��ϼ���.\n");
			inputRegisterNum = scanner.nextInt();
			System.out.printf("\n");
			System.out.printf("�ֹε�Ϲ�ȣ ���ڸ� ù��°���ڸ� �Է��ϼ���.\n");
			inputRegisterNum2 = scanner.nextInt();
			System.out.printf("\n");
			System.out.printf("�������� �����ϼ���.\n");
			System.out.printf("1. ���� (���� ���� �ڵ�ó��)\n");
			System.out.printf("2. �����\n");
			System.out.printf("3. ����������\n");
			System.out.printf("4. �ް��庴\n");
			System.out.printf("5. �ӻ��\n");
			System.out.printf("6. �ٵ��� �ູī��\n");
			inputbenefit = scanner.nextInt();
			System.out.printf("������ �����Ͻðڽ��ϱ�?.\n");
			addTicket = scanner.nextInt();
			System.out.printf("\n\n");
			int RealAge = 0;

			// �� ���� ���
			if (inputRegisterNum2 == 1 || inputRegisterNum2 == 2) {
				if (inputRegisterNum % 10000  > today%10000) {
					RealAge = year - (1900 + inputRegisterNum / 10000) - 1;
				} else if (inputRegisterNum % 10000  < today%10000) {
					RealAge = year - (1900 + inputRegisterNum / 10000);
				}
			} else if (inputRegisterNum2 == 3 || inputRegisterNum2 == 4) {
				if (inputRegisterNum % 10000  > today%10000) {
					RealAge = year - (2000 + inputRegisterNum / 10000) - 1;
				} else if (inputRegisterNum % 10000  < today%10000) {
					RealAge = year - (2000 + inputRegisterNum / 10000);
				}
			} // ReaLAge ������

			if (RealAge > 65) { // ����
				basicFeeType = 1;
			} else if (RealAge < 65 && RealAge > 18) { // ����
				basicFeeType = 2;
			} else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
				basicFeeType = 3;
			} else if (RealAge > 3 && RealAge < 13) { // ���
				basicFeeType = 4;
			} else if (RealAge < 4) { // �Ʊ�
				basicFeeType = 5;
			}
			// ���ɺ� ���� å��
			if (inputType == 1) {
				if (inputTicket == 1) {
					if (RealAge > 65) { // ����
						price = AllDayOlderTK;
					} else if (RealAge < 65 && RealAge > 18) { // ����
						price = AllDayAdultTK;
					} else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
						price = AllDayTeenTK;
					} else if (RealAge > 3 && RealAge < 13) { // ���
						price = AllDayChildTK;
					} else if (RealAge < 4) { // �Ʊ�
						price = AllDayBabyTK;
					}
				}
				if (inputTicket == 2) {
					if (RealAge > 65) { // ����
						price = ParkDayOlderTK;
					} else if (RealAge < 65 && RealAge > 18) { // ����
						price = ParkDayAdultTK;
					} else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
						price = ParkDayTeenTK;
					} else if (RealAge > 3 && RealAge < 13) { // ���
						price = ParkDayChildTK;
					} else if (RealAge < 4) { // �Ʊ�
						price = ParkDayBabyTK;
					}
				}
				// ����å���� ���� ����
				switch (inputbenefit) {
				case 1: {
					money = price;
					break;
				}
				case 2: {
					money = price * 5 / 10;
					break;
				}
				case 3: {
					money = price * 5 / 10;
					break;
				}
				case 4: {
					money = price * 49 / 100;
					break;
				}
				case 5: {
					money = price * 5 / 10;
					break;
				}
				case 6: {
					money = price * 70 / 100;
					break;
				}
				}
			} else if (inputType == 2) {
				if (inputTicket == 1) {
					if (RealAge > 65) { // ����
						price = AllAfter4OlderTK;
					} else if (RealAge < 65 && RealAge > 18) { // ����
						price = AllAfter4AdultTK;
					} else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
						price = AllAfter4TeenTK;
					} else if (RealAge > 3 && RealAge < 13) { // ���
						price = AllAfter4ChildTK;
					} else if (RealAge < 4) { // �Ʊ�
						price = AllAfter4BabyTK;
					}
				}
				if (inputTicket == 2) {
					if (RealAge > 65) { // ����
						price = ParkAfter4OlderTK;
					} else if (RealAge < 65 && RealAge > 18) { // ����
						price = ParkAfter4AdultTK;
					} else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
						price = ParkAfter4TeenTK;
					} else if (RealAge > 3 && RealAge < 13) { // ���
						price = ParkAfter4ChildTK;
					} else if (RealAge < 4) { // �Ʊ�
						price = ParkAfter4BabyTK;
					}
				}
				switch (inputbenefit) {
				case 1: {
					money = price;
					break;
				}
				case 2: {
					money = price * 5 / 10;
					break;
				}
				case 3: {
					money = price * 5 / 10;
					break;
				}
				case 4: {
					money = price;
					System.out.printf("�ް��庴 ���� �����̿�Ǹ� ���ε˴ϴ�\n");
					break;
				}
				case 5: {
					money = price;
					System.out.printf("�ӻ�� ���� �����̿�Ǹ� ���ε˴ϴ�\n");
					break;
				}
				case 6: {
					money = price;
					System.out.printf("�ٵ��� �ູī�� ���� �����̿�Ǹ� ���ε˴ϴ�\n");
					break;
				}
				}
			}
			
			if (price == AllDayOlderTK || price == ParkDayOlderTK || price == AllAfter4OlderTK
					|| price == ParkAfter4OlderTK) {
				money = price; // ���� ����
				System.out.printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", money);
			} else {
				System.out.printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", money);
			}
			totalmoney += money;

			orderList[orderCount][0] = inputType; // �̿������
			orderList[orderCount][1] = inputTicket; // �̿�� �ɼ�
			orderList[orderCount][2] = basicFeeType; // ���̺� ����
			orderList[orderCount][3] = numberofticket; // ����
			orderList[orderCount][4] = money; // ����
			orderList[orderCount][5] = inputbenefit; // ������
			orderCount++;

			System.out.printf("��� �߱� �Ͻðڽ��ϱ�?\n");
			System.out.printf("Ƽ�� �߱� : 1\n");
			System.out.printf("���� : 2\n");
			System.out.printf("ó������ : 3\n");
			extend = scanner.nextInt();
			System.out.printf("%d", extend);
			System.out.printf("\n");

		} while (extend == 1);
		System.out.printf("\n\n*************************************** ���� ���� *****************************************\n");
		System.out.printf("�̿�� ����\t�̿�� �ɼ�\t���̺� ����\t����\t\t������\n");
		for (int i = 0; i < orderCount; i++) {
			switch (orderList[i][0]) {
			case 1: {
				System.out.printf("�����̿��\t\t");
				break;
			}
			case 2: {
				System.out.printf("��ũ�̿��\t\t");
				break;
			}
			}
			switch (orderList[i][1]) {
			case 1: {
				System.out.printf("1Day\t\t");
				break;
			}
			case 2: {
				System.out.printf("After4\t\t");
				break;
			}
			}
			switch (orderList[i][2]) {
			case 1: {
				System.out.printf("����\tt");
				break;
			}
			case 2: {
				System.out.printf("����\t\t");
				break;
			}
			case 3: {
				System.out.printf("û�ҳ�\t\t");
				break;
			}
			case 4: {
				System.out.printf("���\t\t");
				break;
			}
			case 5: {
				System.out.printf("���̺�\t\t");
				break;
			}

			}
			orderList[orderCount][3] = 1;
			orderList[orderCount][4] = money;
			System.out.printf("%d\t\t", orderList[i][4]);
			if (orderList[i][5] == 2) {
				System.out.printf("*����� ���\n");

			} else if (orderList[i][5] == 3) {
				System.out.printf("*���������� ���\n");

			} else if (inputType == 1 && orderList[i][5] == 4) {
				System.out.printf("*�ް��庴 ���\n");

			} else if (inputType == 1 && orderList[i][5] == 5) {
				System.out.printf("*�ӻ�� ���\n");

			} else if (inputType == 1 && orderList[i][5] == 6) {
				System.out.printf("*�ٵ��� �ູī�� ���\n");

			} else {
				System.out.printf("*������ ����\n");

			}
		}
		System.out.printf("\n---------------------------------------------------------------------------\n");
		System.out.printf("���� �ݾ�\t\t\t\t\t\t\t%d��\n\n", totalmoney);
	}

}
