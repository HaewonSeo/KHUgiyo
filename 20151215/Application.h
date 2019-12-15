#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Client.h"
#include "shop.h"
#include "Tree.h"
#include "ClientLinkedList.h"

class Application {
public:
	Application() {
		Clients = new CList;
		Stores = Tree::getInstance();
		pn = NULL;
		m_nCurCommand = 0;
        // ¸ÅÀå ¹× ¸Þ´º ÃÊ±âÈ­

// ÇÑ½Ä ¸ÅÀå Ãß°¡ 
        shop* korean1;
        korean1 = new shop;
        korean1->SetShopName("°¡º»");
        // ¸Þ´º Ãß°¡
        Menu tmp;
        tmp.SetMenu("¸ñ»ì±èÄ¡Âò", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("ºÒ°í±âµ¤¹ä", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("¶±¸¸µÎ±¹", 7000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("ÀåÁ¶¸²¹öÅÍºñºö¹ä", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("¸ÅÄÞÁÖ¸Ô½Ó¹ä", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean1->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* korean2;
        korean2 = new shop;
        korean2->SetShopName("¸ðÀÚ¹ä»ó");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¹é¹ÝÁ¤½Ä", 5500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("Á¦À°ººÀ½Á¤½Ä", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("¼öÁ¦µî½Éµ·±î½ºÁ¤½Ä", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("°íµî¾î±¸ÀÌÁ¤½Ä", 8500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("µ·À°±èÄ¡Âî°³", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean2->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* korean3;
        korean3 = new shop;
        korean3->SetShopName("¹è´Þ»ï°ãµÅÁöµÇÁö");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¿À¸®Áö³¯", 15400, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("¾ç³ä", 15900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("¹Ý¹Ý", 21900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("ÆÄ»ï°ã", 16400, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("º°¹Ì¸·±¹¼ö", 5400, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean3->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* korean4;
        korean4 = new shop;
        korean4->SetShopName("ÀÌ¾¾³×°ñ¸ñ½Ä´ç");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("ÆÄÃ¤µë»ÒÁ¦À°ººÀ½", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("µÎÅùµÎÅù¼öÁ¦µ·±î½º", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("ÇÑ¸¶¸®ÄÚ´Ù¸®Á¶¸²", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("¹è°¡µçµçºÎ´ëÂî°³", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("½Ã¿øÄ®Ä®¼øµÎºÎÂî°³", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean4->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* korean5;
        korean5 = new shop;
        korean5->SetShopName("Á¤¼ºÀÌ°¡µæÂùÁý¹ä");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("°íµî¾î±¸ÀÌÁ¤½Ä", 20000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("¼º½ÇÇÑ¸ç´À¸®ÀÇººÀ½¹ä", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("Á¤¼º°¡µæµî½Éµ·°¡½º", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("°íÁý½º·±¾ÆµéÀÇÂî°³", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("¼º½ÇÇÑ¸ç´À¸®ÀÇÂî°³", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        korean5->SetShopMenu(tmp);


        //Áß½Ä ¸ÅÀå Ãß°¡ 
        shop* chinese1;
        chinese1 = new shop;
        chinese1->SetShopName("´ë¼º°¢");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¸Å¿îÂ«»Í", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("¸Å¿îÂ¥Àå", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("¼øµÎºÎÂ«»Í", 10000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("»ï¼±Â«»Í", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("±¼Â«»Í", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese1->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chinese2;
        chinese2 = new shop;
        chinese2->SetShopName("¶¸´ÙÃ¶°¡¹æ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("Â¥Àå¸é", 5000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("Â«»Í", 6000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("ººÀ½¹ä", 7000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("¿À¹Ç¶óÀÌ½º", 8000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("Äá³ª¹°Â«»Í", 9000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese2->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chinese3;
        chinese3 = new shop;
        chinese3->SetShopName("¹ÌÃ­ÀÌ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("Â¥Àå¸é", 5000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("»ï¼±Â«»Í", 8500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("°úÀÏÅÁ¼öÀ°", 16000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("»ï°ãÁ¦À°µ¤¹ä", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("°íÃßÀâÃ¤¹ä", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese3->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chinese4;
        chinese4 = new shop;
        chinese4->SetShopName("¿ª´ëÂ«»Í");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¿ª´ëÂ«»Í", 7500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("±¼Â«»Í", 8500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("¿ª´ëÂ¥Àå", 6000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("Âý½ÒÅÁ¼öÀ°", 14000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("¾çÀåÇÇ", 30000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese4->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chinese5;
        chinese5 = new shop;
        chinese5->SetShopName("È«Äá¹ÝÁ¡0410");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("Â¥Àå¸é", 4500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("Â«»Í", 5500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("Â¥Àå¹ä", 6500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("ÅÁ¼öÀ°", 11000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("°íÃßÂ«»Í", 6500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chinese5->SetShopMenu(tmp);

        //ºÐ½Ä ¸ÅÀå Ãß°¡ 
        shop* snack1;
        snack1 = new shop;
        snack1->SetShopName("¸¶ÇÇ¾Æ¶±ººÀÌ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¸¶ÇÇ¾Æ¶±ººÀÌ", 12000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("¸¶ÇÇ¾Æ°í±â¶±ººÀÌ", 16000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("¸Å¿î±¹¹°´ß¹ß", 20000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("¸Å¿îµÅÁö°¥ºñÂò", 24000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("¸Å¿î´ßººÀ½ÅÁ", 24000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack1->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* snack2;
        snack2 = new shop;
        snack2->SetShopName("¸¾½ºÄÅ¹ä&¶±ººÀÌ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("ÈÄ·ç·è±¹¹°¶±ººÀÌ", 4000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("½ºÆÔÄÅ¹ä", 5000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("Á¦À°ÄÅ¹ä", 5000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("Ä¡Áî´ß°¥ºñÄÅ¹ä", 6000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("¸ðÂ¥½ºÆÔºñ¿£³ªÄÅ¹ä", 6500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack2->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* snack3;
        snack3 = new shop;
        snack3->SetShopName("º¸¿µ¸¸µÎ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("°í±â¸¸µÎ", 4500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("±èÄ¡¸¸µÎ", 4500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("±º¸¸µÎ", 5000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("Áß°£ÂÌ¸é", 5500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("°í±â¸¸µÎ±¹", 6000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack3->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* snack4;
        snack4 = new shop;
        snack4->SetShopName("¿­Á¤ºÐ½Ä¼Ò");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¿ÀÂ¡Çæ~Æ¢±è", 2500, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("¿ÀÂ¡¾îÁßµ¶ÀÚSET", 23000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("°í°í°¡ºüÁ®¶±", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("µ·±î½ººüÁ®¶±", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("Ä¡Áî´ßºüÁ®¶±", 19000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack4->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* snack5;
        snack5 = new shop;
        snack5->SetShopName("¿µÅë¶±ººÀÌ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("Ä¡Áî¶±ººÀÌ", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("ÇØ¹°Ä¡Áî¶±ººÀÌ", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("Ä«·¹Ä¡Áî¶±ººÀÌ", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("Â¥ÀåÄ¡Áî¶±ººÀÌ", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("ÇØ¹°Ä¡Áî¶±ººÀÌ", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        snack5->SetShopMenu(tmp);

        //Ä¡Å² ¸ÅÀå Ãß°¡ 
        shop* chicken1;
        chicken1 = new shop;
        chicken1->SetShopName("60°èÄ¡Å²");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("°íÃßÄ¡Å²", 18900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("°£ÁöÄ¡Å²", 18900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("ÈÄ¶óÀÌµå", 16900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("Àå½ºÄ¡Å²", 18900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("¾ç³äÄ¡Å²", 17900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken1->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chicken2;
        chicken2 = new shop;
        chicken2->SetShopName("BHC¼­ÃµÁ¡");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("»Ñ¸µÅ¬", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("¸¶¶óÄ­", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("Ä¡ÇÏ¿À", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("¸ÀÃÊÅ·", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("ÈÄ¶óÀÌµå", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken2->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chicken3;
        chicken3 = new shop;
        chicken3->SetShopName("±³ÃÌÄ¡Å²");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("±³ÃÌÇã´Ï¿À¸®Áö³¯", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("±³ÃÌÇã´ÏÄÞº¸", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("±³ÃÌÈÄ¶óÀÌµå", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("±³ÃÌ¿À¸®Áö³¯", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("¼ÒÀÌ»ì»ì", 16000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken3->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chicken4;
        chicken4 = new shop;
        chicken4->SetShopName("³×³×Ä¡Å²");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("¸ÅÄÞÄ¡Áî½º³ëÀ®", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("½º³ëÀ®Ä¡Å²", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("¿À¸®¿£Å»ÆÄ´ß", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("¼ø»ìÄ¡Å²", 17000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("¸¶ÀÏµåÄ¡Å²", 15000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken4->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* chicken5;
        chicken5 = new shop;
        chicken5->SetShopName("Ä¡Å²ÇÃ·¯½º");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("ÇÖÃÝÅ·", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("¼ø»ìÅ©¸®¹Ì¾î´Ï¾ðÄ¡Å²", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("°£ÀåÄ¡Å²", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("¾ç³äÄ¡Å²", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("°³¸Å¿îÄ¡Å²", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        chicken5->SetShopMenu(tmp);


        //ÇÇÀÚ ¸ÅÀå Ãß°¡ 
        shop* pizza1;
        pizza1 = new shop;
        pizza1->SetShopName("¹Ý¿Ã¸²ÇÇÀÚ¼¥");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("ÆúµåÆ÷Å©Ä¡Áî¹ã", 21900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("Æ÷ÅÙÇÇÀÚ", 23900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("¹Ý¹ÝÇÇÀÚ", 16900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("¼öÁ¦°í±¸¸¶°ñµå", 19900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("ºÒ°í±âÇÇÀÚ", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza1->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* pizza2;
        pizza2 = new shop;
        pizza2->SetShopName("ÂøÇÑÇÇÀÚ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("Áø¼ö¼ºÂù", 22900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("¹Ù»èÇÑ½¬¸²ÇÁÇÖÄ¡Å²", 22900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("´Þ´ÞÇÑ°í±¸¸¶", 19900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("¼ö¿ø¿Õ°¥ºñ", 19900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("º£ÀÌÄÁÆ÷Å×ÀÌÅä", 17900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza2->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* pizza3;
        pizza3 = new shop;
        pizza3->SetShopName("Ã»³âÇÇÀÚ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("ÇÒ¶óºÒ°í±â", 13900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("ÁøÂ¥°¨ÀÚÇÇÀÚ", 13900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("¸®¾óÄ¡ÁîÇÇÀÚ", 12900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("¸®¾óºÒ°í±âÇÇÀÚ", 13900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("¾ßÃ¤ÇÇÀÚ", 13900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza3->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* pizza4;
        pizza4 = new shop;
        pizza4->SetShopName("ÇÇÀÚ¾Ëº¼·Î");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("´ÜÈ£¹ÚÇÇÀÚ", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("¾î±úÇÇÀÚ", 24000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("¸ñµ¿ÇÇÀÚ", 18000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("ºÎ»êÇÇÀÚ", 26000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("²ÞÀ»ÇÇÀÚ", 24000, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza4->SetShopMenu(tmp);

        // ¸ÅÀå Ãß°¡ 
        shop* pizza5;
        pizza5 = new shop;
        pizza5->SetShopName("ÇÁ¸®ÇÁ¸®ÇÇÀÚ");
        // ¸Þ´º Ãß°¡
        tmp.SetMenu("»ç»öÇÇÀÚ", 20900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("Ä¥¸®½¬¸²ÇÁ°¡µçÇÇÀÚ", 20900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("º£ÀÌÄÁÃ¼´ÙÇÇÀÚ", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("Æ÷Å×ÀÌÅäÇÇÀÚ", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("Å©¸²Ä¡Áîº£ÀÌÄÁ", 14900, 0); // ÀÌ¸§, °¡°Ý, ÆÈ¸° È½¼ö
        pizza5->SetShopMenu(tmp);


        // Ä«Å×°í¸® Ãß°¡
        Stores->InsertCate("ÇÑ½Ä");
        Stores->InsertCate("Áß½Ä");
        Stores->InsertCate("ºÐ½Ä");
        Stores->InsertCate("Ä¡Å²");
        Stores->InsertCate("ÇÇÀÚ");

        pn = Stores->ReturnRoot();

        // ÇÑ½Ä ¸ÅÀå Ãß°¡ 
        Stores->InsertShop(1, korean1);
        Stores->InsertShop(1, korean2);
        Stores->InsertShop(1, korean3);
        Stores->InsertShop(1, korean4);
        Stores->InsertShop(1, korean5);

        // Áß½Ä ¸ÅÀå Ãß°¡ 
        Stores->InsertShop(2, chinese1);
        Stores->InsertShop(2, chinese2);
        Stores->InsertShop(2, chinese3);
        Stores->InsertShop(2, chinese4);
        Stores->InsertShop(2, chinese5);

        // ºÐ½Ä ¸ÅÀå Ãß°¡ 
        Stores->InsertShop(3, snack1);
        Stores->InsertShop(3, snack2);
        Stores->InsertShop(3, snack3);
        Stores->InsertShop(3, snack4);
        Stores->InsertShop(3, snack5);

        // Ä¡Å² ¸ÅÀå Ãß°¡ 
        Stores->InsertShop(4, chicken1);
        Stores->InsertShop(4, chicken2);
        Stores->InsertShop(4, chicken3);
        Stores->InsertShop(4, chicken4);
        Stores->InsertShop(4, chicken5);

        // ÇÇÀÚ ¸ÅÀå Ãß°¡ 
        Stores->InsertShop(5, pizza1);
        Stores->InsertShop(5, pizza2);
        Stores->InsertShop(5, pizza3);
        Stores->InsertShop(5, pizza4);
        Stores->InsertShop(5, pizza5);
    }

	~Application() {}

	void Run();

	int GetCommand();

	void ClientMode();

	void StoreMode();

private:
	CList* Clients;
	Tree* Stores;
	shop* pn;
	int m_nCurCommand;
};