# Program Requirements

1. 가계부 Data 구조 설계
2. 가계부 Data 입력 받기
3. 소비 패턴 분석 및 출력
4. 메뉴 선택 화면

# TODO list

1. 가계부 Data 구조 설계
   - Date(Year, Month, Week, Day)
   - Income
   - Outcome
   - Item
     - name
     - category
     - price
   - History
     - 가계부 Data를 파일로 저장

2. 메뉴 선택 화면
   - Input
     - Income
     - Outcome
   - Spend Pattern Analysis(SPA)

3. 가계부 Data 입력 받기
   - Income
     - Date
     - Income Amount
   - Outcome
     - Date
     - Item
       - name
       - category
       - price

4. 소비 패턴 분석(SPA)
   - 특정 기간 분석
     - Total Income / Outcome
     - Category별 Outcome
   - 특정 날짜(일간, 주간, 월간, 연간) 분석
     - Total Income / Outcome
     - Category별 Outcome

5. Save / Load
    - 프로그램 시작할 때 History 자동으로 Load
    - 프로그램 종료할 때 History 자동으로 Save
