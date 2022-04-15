#define _CRT_SECURE_NO_WARNINGS    // sprintf 보안 경고로 인한 컴파일 에러 방지
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
    char benefit[50];
    char TypeAge[50];
    while (true) {  	
    	back:
        int money = 0;
        printf("**********************************************************\n");
        printf("이용권 종류를 선택하세요.\n");
        printf("1. 종합이용권(롯데월드 + 민속박물관)\n");
        printf("2. 파크이용권(롯데월드)\n");
        scanf("%d", & inputType);
        printf("\n");
        printf("권종을 선택하세요.\n");
        printf("1. 주간권\n");
        printf("2. After4\n");
        scanf("%d", &inputTicket);
        printf("\n");
        printf("주민등록번호앞자리를 입력하세요.\n");
        scanf("%d", &inputRegisterNum);
        printf("\n");
        printf("주민등록번호 뒷자리 첫번째숫자를 입력하세요.\n");
        scanf("%d", &inputRegisterNum2);
        printf("\n");
        printf("우대사항을 선택하세요.\n");
        printf("1. 없음 (나이 우대는 자동처리)\n");
        printf("2. 장애인\n");
        printf("3. 국가유공자\n");
        printf("4. 휴가장병\n");
        printf("5. 임산부\n");
        printf("6. 다둥이 행복카드\n");
        scanf("%d", &inputbenefit);
        printf("\n\n");
        int year = 2022;
        int day = 414;
        int RealAge = 0;

        if (inputType > 2 || inputTicket > 2 || inputRegisterNum%10000/100 > 12 || inputRegisterNum < 100 || inputRegisterNum2 >4 || inputbenefit > 6) { //예외처리
            printf("처음부터 다시입력하세요\n\n");
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
        }  // ReaLAge 구해짐
		 
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
                	char benefit[50] = "*우대적용 없음"; 
                    money = price;
                    break;
                }
                case 2: {
                	char benefit[50] = "*장애인 우대"; 
                    money = price * 5 / 10;
                    break;
                }
                case 3: {
               	    char benefit[50] = "*국가유공자 우대"; 
                    money = price * 5 / 10;
                    break;
                }
                case 4: {
             	    char benefit[50] = "*휴가장병 우대"; 
                    money = price * 5 / 10;
                    break;
                }
                case 5: {
                	char benefit[50] = "*임산부 우대"; 
                    money = price * 49 / 100;
                    break;
                }
                case 6: {
                	char benefit[50] = "*다둥이 행복카드 우대" ;
                    money = price * 30 / 100;
                    break;
                }
            }
        } 
		else if (inputType == 2) {
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
                	char benefit[50] = "*우대적용 없음"; 
                    money = price;
                    break;
                }
                case 2: {
                	char benefit[50] = "*장애인 우대"; 
                    money = price * 5 / 10;
                    break;
                }
                case 3: {
                	char benefit[50] = "*국가유공자 우대"; 
                    money = price * 5 / 10;
                    break;
                }
                case 4: {
                	char benefit[50] = "*우대적용 없음"; 
                    money = price;
                    printf("휴가장병 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
                case 5: {
                	char benefit[50] = "*우대적용 없음"; 
                    money = price;
                    printf("임산부 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
                case 6: {
                	char benefit[50] = "*우대적용 없음"; 
                    money = price;
                    printf("다둥이 행복카드 우대는 종합이용권만 할인됩니다\n");
                    break;
                }
            }
        }
        if (price == AllDayOlderTK || price == ParkDayOlderTK || price == AllAfter4BOlderTK || price == ParkAfter4OlderTK) {
            money = price; // 노인 가격 
            printf("티켓 금액은 %d원 입니다.\n\n", money);
        } else {
            printf("티켓 금액은 %d원 입니다.\n\n", money);
        }
        totalmoney += money;
        printf("계속 발권 하시겠습니까?\n");
        printf("티켓 발권 : 1\n");
        printf("종료 : 2\n");
        printf("처음으로 : 3\n");
        scanf("%d", & extend);
        printf("\n");        
         
       /* 어른 X 가격 *우대적용 할인 없음 
		청소년 X 가격 *장애인 우대적용 
		어린이 X 가격 
		베이비 X 가격 
		노인 X 가격  */
		if (RealAge > 65 && inputType == 1) { // 노인
          char TypeAge[50] = "종합이용권 65세 이상";
        } else if (RealAge > 65 && inputType == 2) { // 노인
     		 char TypeAge[50] = "파크이용권 65세 이상";
        } else if (RealAge < 65 && RealAge > 18 && inputType == 1) { //성인
            char TypeAge[50] = "종합이용권 어른";
        } else if (RealAge < 65 && RealAge > 18 && inputType == 2) { //성인
            char TypeAge[50] = "파크이용권 어른";
        }  else if (RealAge > 12 && RealAge < 19 && inputType == 1) { // 청소년
            char TypeAge[50] = "종합이용권 청소년";
        } else if (RealAge > 12 && RealAge < 19 && inputType == 2) { // 청소년
            char TypeAge[50] = "파크이용권 청소년";
        } else if (RealAge > 3 && RealAge < 13 && inputType == 1) { //어린이 
            char TypeAge[50] = "종합이용권 어린이";
        }else if (RealAge > 3 && RealAge < 13 && inputType == 2) { //어린이 
            char TypeAge[50] = "파크이용권 어린이";
        } else if (RealAge < 4 && inputType == 1){
            char TypeAge[50] = "종합이용권 베이비";
		}else if (RealAge < 4 && inputType == 2){
            char TypeAge[50] = "파크이용권 베이비";
		}
		if(inputType == 1 || inputType ==2 && inputbenefit == 1){
			char benefit[50] = "*장애인 우대"; 
		} else if(inputType == 1 || inputType ==2 && inputbenefit == 2){
			char benefit[50] = "*국가유공자 우대"; 
		} else if(inputType == 1 && inputbenefit == 3){
			char benefit[50] = "*휴가장병 우대"; 
		} else if(inputType == 1 && inputbenefit == 4){
			char benefit[50] = "*임산부 우대"; 
		} else if(inputType == 1 && inputbenefit == 5){
			char benefit[50] = "*다둥이 행복카드"; 
		} else {
			char benefit[50] = "*우대적용 없음";
		}
		
        if (extend == 1) {
		} 
		else if (extend == 2) {
		
			printf("=============폴리랜드==============\n");
			printf("%s\t X 개수\t %d\t\n", TypeAge, money); 			
            printf("총 결제금액은 %d원 입니다.", totalmoney );
            break;
        } else if (extend == 3) {
        	totalmoney = 0;
            goto back;
        }
    }
}
