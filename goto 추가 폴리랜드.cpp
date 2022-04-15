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
        printf("이용권 종류를 선택하세요.\n");
        printf("1. 종합이용권(롯데월드 + 민속박물관)\n");
        printf("2. 파크이용권(롯데월드)\n");
        scanf("%d", & inputType);
        printf("\n");
        printf("권종을 선택하세요.\n");
        printf("1. 주간권\n");
        printf("2. After4\n");
        scanf("%d", & inputTicket);
        printf("\n");
        printf("주민등록번호앞자리를 입력하세요.\n");
        scanf("%d", & inputRegisterNum);
        printf("\n");
        printf("주민등록번호 뒷자리 첫번째숫자를 입력하세요.\n");
        scanf("%d", & inputRegisterNum2);
        printf("\n");
        printf("우대사항을 선택하세요.\n");
        printf("1. 없음 (나이 우대는 자동처리)\n");
        printf("2. 장애인\n");
        printf("3. 국가유공자\n");
        printf("4. 휴가장병\n");
        printf("5. 임산부\n");
        printf("6. 다둥이 행복카드\n");
        scanf("%d", & inputbenefit);
        printf("\n\n");
        int year = 2022;
        int day = 414;
        int RealAge = 0;

        if (inputType > 2 || inputTicket > 2 || inputRegisterNum%10000/100 > 12 || inputRegisterNum < 100 || inputRegisterNum2 >4 || inputbenefit > 6) { //예외처리
            printf("처음부터 다시입력하세요\n");
            goto back;
        }
        // 만 나이 계산  
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
        //  연령별 가격 책정 
        if (inputType == 1) {
            if (inputTicket == 1) {
                if (RealAge > 65) { // 노인
                    price = AllDayOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //성인
                    price = AllDayAdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // 청소년
                    price = AllDayTeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //어린아
                    price = AllDayChildTK;
                } else if (RealAge < 4) { // 아기
                    price = AllDayBabyTK;
                }
            }
            if (inputTicket == 2) {
                if (RealAge > 65) { // 노인
                    price = ParkDayOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //성인
                    price = ParkDayAdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // 청소년
                    price = ParkDayTeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //어린아
                    price = ParkDayChildTK;
                } else if (RealAge < 4) { // 아기
                    price = ParkDayBabyTK;
                }
            }
            // 가격책정에 할인 적용  
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
                if (RealAge > 65) { // 노인
                    price = AllAfter4BOlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //성인
                    price = AllAfter4AdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // 청소년
                    price = AllAfter4TeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //어린아
                    price = AllAfter4ChildTK;
                } else if (RealAge < 4) { // 아기
                    price = AllAfter4BabyTK;
                }
            }
            if (inputTicket == 2) {
                if (RealAge > 65) { // 노인
                    price = ParkAfter4OlderTK;
                } else if (RealAge < 65 && RealAge > 18) { //성인
                    price = ParkAfter4AdultTK;
                } else if (RealAge > 12 && RealAge < 19) { // 청소년
                    price = ParkAfter4TeenTK;
                } else if (RealAge > 3 && RealAge < 13) { //어린아
                    price = ParkAfter4ChildTK;
                } else if (RealAge < 4) { // 아기
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
                    printf("휴가장병 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
                case 5: {
                    money = price;
                    printf("임산부 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
                case 6: {
                    money = price;
                    printf("다둥이 행복카드 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
            }
        }
        if (price == AllDayOlderTK || price == ParkDayOlderTK || price == AllAfter4BOlderTK || price == ParkAfter4OlderTK) {
            money = price;
            printf("티켓 금액은 %d원 입니다.\n\n", money);
        } else {
            printf("티켓 금액은 %d원 입니다.\n\n", money);
        }
        totalmoney += money;
        printf("결제를 이어서 진행하시겠습니까?\n");
        printf("티켓 추가  : 1\n");
        printf("총 티켓 가격 확인 : 2\n");
        printf("처음부터 다시 : 3\n");
        scanf("%d", & extend);
        printf("\n");
        //if(inputType == 1 && inputTicket == 1 && inputRegisterNum inputRegisterNum2 inputbenefit == 1)
        
        
        if (extend == 1) {} 
		else if (extend == 2) {
            printf("총 결제금액은 ");
            printf("%d원 입니다.", totalmoney);
            break;
        } else if (extend == 3) {
            goto back;
        }
    }
}
