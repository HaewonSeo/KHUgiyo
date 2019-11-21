//
//  shop.h
//  shop
//
//  Created by seungho on 2019/11/21.
//  Copyright © 2019 seungho. All rights reserved.
//

#ifndef shop_h
#define shop_h
#include <string>
#include "OrderQueue.h"
#include "SortedMenuList.h"
#include "Buffer.h"

class shop{
private:
    string ShopName; // 가게 이름
    int TotalIncome; // 총 매출
    OrderQueue<menu> Order; // 주문 들어온 큐
    SortedMenuList ShopMenu;
    Buffer* bufferptr; // 버퍼에 접근하는 포인터
    
    
public:
    // 생성자
    shop(){};
    
    //소멸자
    ~shop(){};
    
    //어플리케이션 함수 추가
    
    
    /**
      *    @brief   업장의 이름을 설정하는 함수입니다.
      *    @pre none
      *    @post 업장 객체의 이름을 설정해줍니다
      *    @return    none
      */
    void SetShopName();
    /**
      *    @brief   업장의 이름을 리턴합니다
      *    @pre 업장 이름이 세팅되있어야 합니다
      *    @post 업장 이름을 반환합니다
      *    @return    ShopName
      */
    string GetName(){
        return ShopName;
    }
    
        
    /**
      *    @brief   현재 주문 상태를 출력해주는 함수입니다.
      *    @pre none
      *    @post Order의 내용을 출력해줍니다.
      *    @return    none
      */
    void DisplayOrder();
    
    /**
      *    @brief  업장의 메뉴 리스트를 읽어 옵니다.
      *    @pre 디렉토리에 업장의 이름에 맞는 텍스트 파일이 있어야 합니다.
      *    @post 업장 메뉴 리스트에 저장이 됩니다.
      *    @return    파일 읽기 성공시 리턴 1, 실패시 리턴 0
      */

    int ReadMenuFile();
    
    /**
      *    @brief 메뉴 리스트에 있는 요소들을 텍스트 파일로 만들어 줍니다.
      *    @pre 메뉴 리스트에 메뉴들이 정렬되어 있어야합니다.
      *    @post 메뉴 리스트에 있는 요소들이 텍스트 파일로 덮어 씌워집니다.
      *    @return 성공시 리턴 1, 실패시 리턴 0
      */
    int WriteMenuFile();
    
    /**
      *    @brief   업장의 메뉴 리스트를 수정하는 함수입니다..
      *    @pre 메뉴리스트가 설정되어 있어야 합니다.
      *    @post 메뉴 리스트의 내용을 수정합니다.
      *    @return    none
      */
    void ChangeMenueList();
    
    /**
      *    @brief   order를 Dequeue시 Dequeue된 order안의 모든 메뉴의 가격의 합을 더해줍니다.
      *    @pre order의 요소가 설정되어야 합니다.
      *    @post  order를 Dequeue하고, 주문한 메뉴의 가격의 합을 더해줍니다
      *    @return    none
      */
    void GetTotalIncome();
    
    /**
      *    @brief   매장 총매출을 출력하는 함수 입니다.
      *    @pre 총매출액이 설정되어 있어야합니다
      *    @post 총매출액을 출력합니다.
      *    @return    none
      */
    void ShowTotalIncome();
    
    // 버퍼클래스에서 가게 이름을 키값으로 리니어 서치를 해서 오더를 인큐시키는 함수 구현 Buffer.h의 메서드 함수 사용
    
    
};

#endif /* shop_h */
