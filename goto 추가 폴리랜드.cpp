#include <stdio.h>

int main() {
    const int AllDayAdultTK = 62000;     	const int ParkDayAdultTK = 59000;
    const int AllDayTeenTK = 54000;   	 	const int ParkDayTeenTK = 52000;
    const int AllDayChildTK = 47000;     	const int ParkDayChildTK = 46000;
    const int AllDayBabyTK = 15000;	     	const int ParkDayBabyTK = 15000;  
    const int AllDayOlderTK = 15000;	 	const int ParkDayOlderTK = 15000;
    const int AllAfter4AdultTK = 50000;	 	const int ParkAfter4AdultTK = 47000;
    const int AllAfter4TeenTK = 43000;	 	const int ParkAfter4TeenTK = 41000;
    const int AllAfter4ChildTK = 36000;		const int ParkAfter4ChildTK = 35000;
    const int AllAfter4BabyTK = 15000;	 	const int ParkAfter4BabyTK = 15000;
    const int AllAfter4BOlderTK = 15000;	const int ParkAfter4OlderTK = 15000;
    int inputType;
    int inputTicket;
    int inputRegisterNum;
    int inputRegisterNum2;
    int inputbenefit;
    int price;
    int money;
    int extend;
    int totalmoney = 0;
    while (true) {
    	back:
        int money = 0;
        printf("�̿�� ������ �����ϼ���.\n");
        printf("1. �����̿��(�Ե����� + �μӹڹ���)\n");
        printf("2. ��ũ�̿��(�Ե�����)\n");
        scanf("%d", & inputType);
        printf("\n");
        printf("������ �����ϼ���.\n");
        printf("1. �ְ���\n");
        printf("2. After4\n");
        scanf("%d", & inputTicket);
        printf("\n");
        printf("�ֹε�Ϲ�ȣ���ڸ��� �Է��ϼ���.\n");
        scanf("%d", & inputRegisterNum);
        printf("\n");
        printf("�ֹε�Ϲ�ȣ ���ڸ� ù��°���ڸ� �Է��ϼ���.\n");
        scanf("%d", & inputRegisterNum2);
        printf("\n");
        printf("�������� �����ϼ���.\n");
        printf("1. ���� (���� ���� �ڵ�ó��)\n");
        printf("2. �����\n");
        printf("3. ����������\n");
        printf("4. �ް��庴\n");
        printf("5. �ӻ��\n");
        printf("6. �ٵ��� �ູī��\n");
        scanf("%d", & inputbenefit);
        printf("\n\n");
        int year = 2022;
        int day = 414;
        int RealAge = 0;

        if (inputType > 2 || inputTicket > 2 || inputRegisterNum%10000/100 > 12 || inputRegisterNum < 100 || inputRegisterNum2 >4 || inputbenefit > 6) { //����ó��
            printf("ó������ �ٽ��Է��ϼ���\n");
            goto back;
        }
        // �� ���� ���  
        if (inputRegisterNum2 == 1 || inputRegisterNum2 == 2) {
            if (inputRegisterNum % 10000 / 10 > day) {
                RealAge = year - (1900 + inputRegisterNum / 10000) - 1;
            } else if (inputRegisterNum % 10000 / 10 < day) {
                RealAge = year - (1900 + inputRegisterNum / 10000);
            }
        } else if (inputRegisterNum2 == 3 || inputRegisterNum2 == 4) {
            if (inputRegisterNum % 10000 / 10 > day) {
                RealAge = year - (2000 + inputRegisterNum / 10000) - 1;
            } else if (inputRegisterNum % 10000 / 10 < day) {
                RealAge = year - (2000 + inputRegisterNum / 10000);
            }
        }
        //  ���ɺ� ���� å�� 
        if (inputType == 1) {
            if (inputTicket == 1) {
                if (RealAge > 65) { // ����
                    price = AllDayOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //����
                    price = AllDayAdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
                    price = AllDayTeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //���
                    price = AllDayChildTK;
                } else if (RealAge < 4) { // �Ʊ�
                    price = AllDayBabyTK;
                }
            }
            if (inputTicket == 2) {
                if (RealAge > 65) { // ����
                    price = ParkDayOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //����
                    price = ParkDayAdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
                    price = ParkDayTeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //���
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
                    money = price * 5 / 10;
                    break;
                }
                case 5: {
                    money = price * 49 / 100;
                    break;
                }
                case 6: {
                    money = price * 30 / 100;
                    break;
                }
            }
        } else if (inputType == 2) {
            if (inputTicket == 1) {
                if (RealAge > 65) { // ����
                    price = AllAfter4BOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //����
                    price = AllAfter4AdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
                    price = AllAfter4TeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //���
                    price = AllAfter4ChildTK;
                } else if (RealAge < 4) { // �Ʊ�
                    price = AllAfter4BabyTK;
                }
            }
            if (inputTicket == 2) {
                if (RealAge > 65) { // ����
                    price = ParkAfter4OlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //����
                    price = ParkAfter4AdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // û�ҳ�
                    price = ParkAfter4TeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //���
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
                    printf("�ް��庴 ���� �����̿�Ǹ� ���ε˴ϴ�\n");
                    break;
                }
                case 5: {
                    money = price;
                    printf("�ӻ�� ���� �����̿�Ǹ� ���ε˴ϴ�\n");
                    break;
                }
                case 6: {
                    money = price;
                    printf("�ٵ��� �ູī�� ���� �����̿�Ǹ� ���ε˴ϴ�\n");
                    break;
                }
            }
        }
        if (price == AllDayOlderTK || price == ParkDayOlderTK || price == AllAfter4BOlderTK || price == ParkAfter4OlderTK) {
            money = price;
            printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", money);
        } else {
            printf("Ƽ�� �ݾ��� %d�� �Դϴ�.\n\n", money);
        }
        totalmoney += money;
        printf("������ �̾ �����Ͻðڽ��ϱ�?\n");
        printf("Ƽ�� �߰�  : 1\n");
        printf("�� Ƽ�� ���� Ȯ�� : 2\n");
        printf("ó������ �ٽ� : 3\n");
        scanf("%d", & extend);
        printf("\n");
        //if(inputType == 1 && inputTicket == 1 && inputRegisterNum inputRegisterNum2 inputbenefit == 1)
        
        
        if (extend == 1) {} 
		else if (extend == 2) {
            printf("�� �����ݾ��� ");
            printf("%d�� �Դϴ�.", totalmoney);
            break;
        } else if (extend == 3) {
            goto back;
        }
    }
}
