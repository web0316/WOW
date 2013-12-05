/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#include "precompiled.h"
#include "sc_gossip.h"
#include "Player.h"
#include "GossipDef.h"
#include "Spell.h"
bool GossipHello_ItemUse_Item_teleport(Player *player, Item* _Item, SpellCastTargets const& targets)
{

		//判断是否战斗状态
		if(player->isInCombat())
		{
			player->SEND_GOSSIP_MENU(100007,_Item->GetGUID());
			return true;
		}
		//判断是否死亡状态
		if( player->isDead() )
	       {
		player->SEND_SPRESURRECT();
		return true;
               }
    player->ADD_GOSSIP_ITEM( 0, " 【世界主城传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, " 【外域地区传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, " 【诺森德大陆传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, " 【世界风景传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, " 【初级副本传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, " 【中级副本传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, " 【团队副本传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, " 【外域副本之一】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, " 【外域副本之二】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, " 【野外BOSS传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, " 【世界战场传送】 "                            , 1, GOSSIP_ACTION_INFO_DEF + 11);
    player->ADD_GOSSIP_ITEM( 0, " 【附加功能】 "                                , 1, GOSSIP_ACTION_INFO_DEF + 12);
    player->SEND_GOSSIP_MENU(99990,_Item->GetGUID());
    return true;
}

void SendDefaultMenu_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 action, SpellCastTargets const& targets)
{
        switch(action) {
                // 主城
                case GOSSIP_ACTION_INFO_DEF + 1 :
		if(player->getRace() == 1 || player->getRace() == 3 || player->getRace() == 4 || player->getRace() == 7 || player->getRace() == 11)//判断是否联盟
		{
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 暴风城】 "                , 2, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 铁炉堡】 "                , 2, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 达纳苏斯】 "              , 2, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 艾克索达】 "              , 2, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 人类出生地】 "            , 2, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 暗夜精灵出生地】 "        , 2, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 地精出生地】 "            , 2, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【联盟 德莱妮出生地】 "          , 2, GOSSIP_ACTION_INFO_DEF + 8);

		}
		else
		{
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 奥格瑞玛】 "              , 2, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 雷霆崖】 "                , 2, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 幽暗城】 "                , 2, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 银月城】 "                , 2, GOSSIP_ACTION_INFO_DEF + 12);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 兽人出生地】 "            , 2, GOSSIP_ACTION_INFO_DEF + 13);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 牛头人出生地】 "          , 2, GOSSIP_ACTION_INFO_DEF + 14);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 亡灵出生地】 "            , 2, GOSSIP_ACTION_INFO_DEF + 15);
                        player->ADD_GOSSIP_ITEM( 0, " 【部落 血精灵出生地】 "          , 2, GOSSIP_ACTION_INFO_DEF + 16);
}
                        player->ADD_GOSSIP_ITEM( 0, " 【中立 棘齿城】 "                , 2, GOSSIP_ACTION_INFO_DEF + 17);
                        player->ADD_GOSSIP_ITEM( 0, " 【中立 藏宝海湾】 "              , 2, GOSSIP_ACTION_INFO_DEF + 18);
                        player->ADD_GOSSIP_ITEM( 0, " 【中立 加基森】 "                  , 2, GOSSIP_ACTION_INFO_DEF + 19);
                        player->ADD_GOSSIP_ITEM( 0, " 【中立 冬泉谷】 "                , 2, GOSSIP_ACTION_INFO_DEF + 20);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "              , 2, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99991,_Item->GetGUID());
                        break;
                                // 外域地区传送
                                case GOSSIP_ACTION_INFO_DEF + 2 :     
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]地狱之火半岛】 "              , 3, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]赞格沼泽】 "                  , 3, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]纳葛兰】 "                    , 3, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]剑刃山脉】 "                  , 3, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]虚空风暴】 "                  , 3, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]泰洛卡森林】 "                , 3, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 1, " 【[外域]影月谷】 "                    , 3, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 1, " 【[副本]太阳之井】 "                , 3, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 1, " 【[副本]魔导师平台】 "                    , 3, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "            , 3, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99996,_Item->GetGUID()); 
                        break;
                                 // 巫妖王大陆地区
                case GOSSIP_ACTION_INFO_DEF + 3 :
                        player->ADD_GOSSIP_ITEM( 0, " 【灰熊丘陵】 "                , 4, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【北风苔原】 "                , 4, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【龙骨荒野】 "              , 4, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【嚎风峡湾】 "              , 4, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【祖达克】 "            , 4, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【风暴峭壁】 "        , 4, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【冰冠冰川】 "            , 4, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【索拉查盆地】 "          , 4, GOSSIP_ACTION_INFO_DEF + 8);	
                        player->ADD_GOSSIP_ITEM( 0, " 【冬拥湖】 "              , 4, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【晶歌森林】 "                , 4, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 0, " 【奥核之心[副本]】 "                , 4, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 0, " 【抚育之渊[副本]】 "            , 4, GOSSIP_ACTION_INFO_DEF + 12);
                        player->ADD_GOSSIP_ITEM( 0, " 【黑色领区[副本]】 "          , 4, GOSSIP_ACTION_INFO_DEF + 13);
                        player->ADD_GOSSIP_ITEM( 7, " 返回到上一级选项菜单】 "           , 4, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99992,_Item->GetGUID());
                        break;

              // 风景传送
                case GOSSIP_ACTION_INFO_DEF + 4 :
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]翡翠圣地】 "                , 5, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]时光之穴】 "                , 5, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]双塔山】 "                  , 5, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]梦境之树】 "                , 5, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]恐怖之岛】 "                , 5, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]暴雪路障】 "                , 5, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]天涯海滩】 "                , 5, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]安戈洛环形山】 "            , 5, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]比吉尔的飞艇残骸】 "        , 5, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]石堡瀑布】 "                 , 5, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]永歌森林】 "                , 5, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]艾克索达】 "                , 5, GOSSIP_ACTION_INFO_DEF + 12);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]翠叶森林】 "                , 5, GOSSIP_ACTION_INFO_DEF + 13);
                        player->ADD_GOSSIP_ITEM( 0, " 【[风景]GM之岛】 "                 , 5, GOSSIP_ACTION_INFO_DEF + 14);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 5, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(100001,_Item->GetGUID()); 
                          break;



                // 初级副本
                case GOSSIP_ACTION_INFO_DEF + 5 :
                        player->ADD_GOSSIP_ITEM( 0, " 【14] 怒焰裂谷】 "            , 6, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【19] 死亡矿井】 "            , 6, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【22] 哀嚎洞穴】 "            , 6, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【24] 影牙城堡】 "            , 6, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【26] 黑暗深渊】 "            , 6, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【27] 暴风城监狱】 "          , 6, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【31] 剃刀沼泽】 "            , 6, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【33] 诺莫瑞根】 "            , 6, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 0, " 【40] 血色修道院】 "          , 6, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【42] 剃刀高地】 "            , 6, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 0, " 【45] 奥达曼】 "              , 6, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 7, " 返回到上一级选项菜单】 "       , 6, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99993,_Item->GetGUID());
                        break;

            // 中级副本
                case GOSSIP_ACTION_INFO_DEF + 6 :
                        player->ADD_GOSSIP_ITEM( 0, " 【46] 祖尔法拉克】 "        , 7, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【49] 玛拉顿】 "            , 7, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【53] 失落的神庙】 "        , 7, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【57] 黑石深渊】 "          , 7, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 通灵学院】 "          , 7, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 厄运之槌 (北区)】 "   , 7, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 厄运之槌 (东区)】 "   , 7, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 厄运之槌 (西区)】 "   , 7, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 斯坦索姆】 "          , 7, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【60] 黑石塔下】 "          , 7, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "     , 7, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99994,_Item->GetGUID());
                        break;

                // 高级副本
                case GOSSIP_ACTION_INFO_DEF + 7 :     
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 溶火之心】 "            , 8, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 黑石塔上】 "            , 8, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 祖尔格拉布】 "          , 8, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 黑翼之巢】 "            , 8, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 安其拉】 "              , 8, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 安其拉废墟】 "          , 8, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 奥妮克希亚的巢穴】 "    , 8, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 纳克萨玛斯】 "          , 8, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 0, " 【团] 冰龙巢穴】 "            , 8, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 7, " 返回到上一级选项菜单 "       , 8, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99995,_Item->GetGUID());
                        break;

                                // 外域副本之一
                                case GOSSIP_ACTION_INFO_DEF + 8 : 
                        player->ADD_GOSSIP_ITEM( 5, " 【[黑暗神庙]】 "                    , 9, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 5, " 【[黑暗神庙]神殿之巅】 "            , 9, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]波塔尼卡】 "                , 9, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]亚克崔兹】 "                , 9, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]麦克那尔】 "                , 9, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]奴隶监狱】 "                , 9, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]蒸汽洞窟】 "                , 9, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]毒牙沼泽】 "                , 9, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 5, " 【[副本]生态船】 "                  , 9, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 5, " 【[副本]能源舰】 "                  , 9, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 5, " 【[副本]奥金尼地穴】 "              , 9, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 5, " 【[副本]法力陵墓】 "                , 9, GOSSIP_ACTION_INFO_DEF + 12);
                        player->ADD_GOSSIP_ITEM( 5, " 【[副本]塞泰克大厅】 "              , 9, GOSSIP_ACTION_INFO_DEF + 13);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]盘牙洞穴】 "                , 9, GOSSIP_ACTION_INFO_DEF + 14);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 9, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99997,_Item->GetGUID()); 
                        break;
                                        // 外域副本之二
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                        player->ADD_GOSSIP_ITEM( 4, " 【[副本]海加尔山】 "                , 10, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 4, " 【[副本]风暴要塞】 "                , 10, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 4, " 【[副本]毒蛇神殿】 "                , 10, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 4, " 【[副本]阿克蒙德】 "                , 10, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]玛瑟里顿的巢穴】 "          , 10, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]破碎大厅】 "                , 10, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]血熔炉】 "                  , 10, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]卡拉赞】 "                  , 10, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]遗忘之井】  "               , 10, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]鬼魂之地】 "                , 10, GOSSIP_ACTION_INFO_DEF + 10);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]地狱火堡垒】 "              , 10, GOSSIP_ACTION_INFO_DEF + 11);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]奥金顿】 "                  , 10, GOSSIP_ACTION_INFO_DEF + 12);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]戈鲁尔之巢】 "              , 10, GOSSIP_ACTION_INFO_DEF + 13);
                        player->ADD_GOSSIP_ITEM( 0, " 【[副本]黑色沼泽】 "                , 10, GOSSIP_ACTION_INFO_DEF + 14);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 10, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99998,_Item->GetGUID()); 
                        break;                                
               // 野外BOSS传送
                case GOSSIP_ACTION_INFO_DEF + 10 :
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]暮色森林】 "                , 11, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]辛特兰】 "                  , 11, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]灰谷】 "                    , 11, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]艾萨拉】 "                  , 11, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]菲拉斯】 "                  , 11, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]诅咒之地】 "                , 11, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【[野外]水晶谷】 "                  , 11, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 11, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(99999,_Item->GetGUID()); 
                          break;
                   // 世界战场传送
                case GOSSIP_ACTION_INFO_DEF + 11 :
                        player->ADD_GOSSIP_ITEM( 0, " 【古拉巴什竞技场】 "                , 12, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 4, " 【[部落]奥特兰战场】 "              , 12, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 4, " 【[部落]战歌峡谷】 "                , 12, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 4, " 【[部落]阿拉希战场】 "              , 12, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 4, " 【[部落]暴风之眼】 "                , 12, GOSSIP_ACTION_INFO_DEF + 5);
                        player->ADD_GOSSIP_ITEM( 4, " 【[联盟]奥特兰战场】 "              , 12, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 4, " 【[联盟]战歌峡谷】 "                , 12, GOSSIP_ACTION_INFO_DEF + 7);
                        player->ADD_GOSSIP_ITEM( 4, " 【[联盟]阿拉希战场】 "              , 12, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 4, " 【[联盟]暴风之眼】 "                , 12, GOSSIP_ACTION_INFO_DEF + 9);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 12, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(100000,_Item->GetGUID()); 
                          break;

  // 附加功能
                case GOSSIP_ACTION_INFO_DEF + 12 :
                        player->ADD_GOSSIP_ITEM( 0, " 【个人银行】 "                , 13, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM( 0, " 【装备修复】 "                , 13, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM( 0, " 【开飞行点】 "                  , 13, GOSSIP_ACTION_INFO_DEF + 3);
                        player->ADD_GOSSIP_ITEM( 0, " 【地图全开】 "                  , 13, GOSSIP_ACTION_INFO_DEF + 4);
                        player->ADD_GOSSIP_ITEM( 0, " 【领取工资10G/小时】 "               , 13, GOSSIP_ACTION_INFO_DEF + 5);
                        //player->ADD_GOSSIP_ITEM( 0, " 【绑定炉石】 "                    , 13, GOSSIP_ACTION_INFO_DEF + 6);
                        player->ADD_GOSSIP_ITEM( 0, " 【技能熟练提升】 "                    , 13, GOSSIP_ACTION_INFO_DEF + 7);
                        //player->ADD_GOSSIP_ITEM( 0, " 【返回炉石点】 "                    , 13, GOSSIP_ACTION_INFO_DEF + 8);
                        player->ADD_GOSSIP_ITEM( 7, " 【返回到上一级选项菜单】 "          , 13, GOSSIP_ACTION_INFO_DEF + 99);
                        player->SEND_GOSSIP_MENU(100002,_Item->GetGUID()); 
                          break;
        }
}

bool GossipSelect_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 sender, uint32 action, SpellCastTargets const& targets)
{
                switch(sender) {
                // 主选单
                case GOSSIP_SENDER_MAIN :
                        SendDefaultMenu_ItemUse_Item_teleport(player, _Item, action,targets);
                        break;
                // 各大主城
                case 2 :
                        switch(action) {
                                                     // 联盟技能训练师 统一格式说明：(MapID, X, Y, Z, 0);


                                   // 暴风城
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(0,-9065,434,94,0);
                                        break;
                                // 铁炉堡
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(0,-5032,-819,495,0);
                                        break;
                                // 达纳苏斯
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(1,9961,2055,1329,0);
                                        break;
                                // 德萊尼主城
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(530,-4071.7f,-12036.7f,-1.5f,0);
                                        break;
                                // ·人类出生地 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(0,-8945.808594,-152.064667,82.491745,0);
                                        break;
                                // ·暗夜精灵出生地
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(1,10321.046875,834.703125,1326.373413,0);
                                        break;
                                // ·地精出生地
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(0,-6238.875488,336.343140,382.963715,0);
                                        break;
                                // ·德莱妮出生地
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(530,-3963.237549,-13929.471680,100.529718,0);
                                        break;
                                // 奥格瑞玛
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(1,1317,-4383,27,0);
                                        break;
                                // 雷霆崖
                                case GOSSIP_ACTION_INFO_DEF + 10 :
                                        player->TeleportTo(1,-1391,140,23,0);
                                        break;
                                // 幽暗城
                                case GOSSIP_ACTION_INFO_DEF + 11 :
                                        player->TeleportTo(0,1909,235,53,0);
                                        break;
                                //血精灵主城
                                case GOSSIP_ACTION_INFO_DEF + 12 :
                                        player->TeleportTo(530,9336.9f,-7278.4f,13.6f,0);
                                        break;
                                // ·兽人出生地
                                case GOSSIP_ACTION_INFO_DEF + 13 :
                                        player->TeleportTo(1,-600.34890,-4263.093262,38.956245,0);
                                        break;
                                // ·牛头人出生地
                                case GOSSIP_ACTION_INFO_DEF + 14 :
                                        player->TeleportTo(1,-2938.627686,-265.806152,53.438744,0);
                                        break;
                                // ·亡灵出生地
                                case GOSSIP_ACTION_INFO_DEF + 15 :
                                        player->TeleportTo(0,1664.067139,1677.903564,120.529999,0);
                                        break;
                                // ·血精灵出生地
                                case GOSSIP_ACTION_INFO_DEF + 16 :
                                        player->TeleportTo(530,10351.513250,-6358.020020,33.610661,0);
                                        break;
                                // 棘齿城 */
                                case GOSSIP_ACTION_INFO_DEF + 17 :
                                        player->TeleportTo(1,-977,-3788,6,0);
                                        break;
                                // 藏宝海湾
                                case GOSSIP_ACTION_INFO_DEF + 18 :
                                        player->TeleportTo(0,-14302,518,9,0);
                                        break;
                              // 加基森
                             case GOSSIP_ACTION_INFO_DEF + 19 :
                                      player->TeleportTo(1,-7177.103516,-3788.077393,8.370177,3.621340);
                                      break;
                             // 冬泉谷
                            case GOSSIP_ACTION_INFO_DEF + 20 :
                                     player->TeleportTo(1,6723.473145,-4649.303711,720.980835,4.653478);
                                     break;
                             //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                                                        }
                            break;
 
                                // 外域地区
               case 3: 
                     switch(action) {
                        case GOSSIP_ACTION_INFO_DEF + 1 :
                        player->TeleportTo(530, -248.160004, 922.348999, 84.379799,0);
                        break;
                        // [外域]赞格沼泽
                        case GOSSIP_ACTION_INFO_DEF + 2 :
                        player->TeleportTo(530, -225.863632, 5405.927246, 22.346397, 0);
                        break;
                        // [外域]纳葛兰
                        case GOSSIP_ACTION_INFO_DEF + 3 :
                        player->TeleportTo(530, -468.232330, 8418.666016, 28.031298, 0);
                        break;
                        // [外域]剑刃山脉
                        case GOSSIP_ACTION_INFO_DEF + 4 :
                        player->TeleportTo(530, 1471.672852, 6828.047852, 107.759239, 0);
                        break;
                        // [外域]虚空风暴
                        case GOSSIP_ACTION_INFO_DEF + 5 :
                        player->TeleportTo(530, 3396.123779, 4182.208008, 137.097992, 0);
                        break;
                        // [外域]泰洛卡森林 
                        case GOSSIP_ACTION_INFO_DEF + 6 :
                        player->TeleportTo(530, -1202.426636, 5313.692871, 33.774723,0);
                        break;
                        // [外域]影月谷
                        case GOSSIP_ACTION_INFO_DEF + 7 :
                        player->TeleportTo(530, -2859.522461, 3182.34773, 10.008426, 0);
                        break;
                        // [副本]太阳之井
                        case GOSSIP_ACTION_INFO_DEF + 8 :
                        player->TeleportTo(530, 12564.9, -6775.37, 15.09,0);
                        break;
                        // [外域]魔导师平台
                        case GOSSIP_ACTION_INFO_DEF + 9 :
                        player->TeleportTo(530, 12887.4, -7327.2, 65.49, 0);
                        break;
                        //返回
                         case GOSSIP_ACTION_INFO_DEF + 99 :
                         GossipHello_ItemUse_Item_teleport(player,_Item,targets);                                                                            break;
                }
                            break;       
                // 巫妖王大陆地区
                case 4 :
                        switch(action) {
                                 // 巫妖王大陆地区：(MapID, X, Y, Z, 0);
                                 // 灰熊丘陵
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(571,4260.314453,-2314.690430,218.016953,0);
                                        break;
                                // 北风苔原
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(571,3292.687500,5258.383301,37.055984,0);
                                        break;
                                // 龙骨荒野
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(571,4289.433105,905.629639,78.972702,0);
                                        break;
                                // 嚎风峡湾
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(571,1347.795654,-4532.550293,175.921127,0);
                                        break;
                                  //祖达克
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(571,5687.527832,-3325.282471,372.795776,0);
                                        break;
                                // ·风暴峭壁
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(571,8913.091797,-1309.078735,1025.499146,0);
                                        break;
                                // ·冰冠冰川
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(571,7520.014160,2301.520508,384.003876,0);
                                        break;
                                // ·索拉查盆地
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(571,5878.264648,4122.937500,-85.512115,0);
                                        break;
                                // 冬拥湖
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(571,4610.811523,2837.539551,396.896851,0);
                                        break;
                                // 晶歌森林
                                case GOSSIP_ACTION_INFO_DEF + 10 :
                                        player->TeleportTo(571,5470.397461,53.802029,149.789978,0);
                                        break;
                                //奥核之心
                                case GOSSIP_ACTION_INFO_DEF + 11 :
                                        player->TeleportTo(576,146,-10,-16,0);
                                        break;
                                // ·抚育之渊
                                case GOSSIP_ACTION_INFO_DEF + 12 :
                                        player->TeleportTo(601,404.28,53.53,252.42,0);
                                        break;
                                // ·黑色领区
                                case GOSSIP_ACTION_INFO_DEF + 13 :
                                        player->TeleportTo(609,2363.65,-5659.17,382.27,0);
                                        break;
                             //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                                                        }
                            break;

                                 // 风景传送
                  case 5 :
                        switch(action) {
                                //翡翠圣地 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(1,3968.264648,-1290.036011,240.326889,5.927989);
                                        break;
                                //时光之穴 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(1,-8173.930176,-4737.463867,33.777351,4.772119);
                                        break;
                                //双塔山 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(1,-3331.353271,2225.728271,30.987701,6.267522);
                                        break;
                                //梦境之树 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(1,-2914.756104,1902.199341,34.741035,5.690404);
                                        break;
                                //恐怖之岛 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(1,4603.946777,-3879.250977,944.183472,1);
                                        break;
                                //暴雪建设公司路障 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(1,5478.060059,-3730.850098,1593.439941,5.610376);
                                        break;
                              //天涯海滩 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(1,-9851.617188,-3608.474121,8.939731,2.513388);
                                        break;
                               //安戈洛环形山 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(1,-8562.096680,-2106.056641,8.852538,0.090425);
                                        break;
                              //比吉尔的飞艇残骸 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(1,-4014.003418,-3768.186523,42.123295,5.220697);
                                        break;
                               //石堡瀑布 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 10 :
                                        player->TeleportTo(0,-9481.493164,-3326.915283,8.864347,0.846896);
                                        break;
                                                          // 永歌森林 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 11 :
                                player->TeleportTo(530,9336.900391,-7278.399902,13.600000,0);
                                break;
                                 // 艾克索达
                                case GOSSIP_ACTION_INFO_DEF + 12 :
                                player->TeleportTo(530,-4043.632813,-11933.284180,-0.057945,0);
                                break;
                                // 翠叶森林
                                case GOSSIP_ACTION_INFO_DEF + 13 :
                                player->TeleportTo(169,2737.508057,-3318.579590,101.882820,0);
                                break;
                               // GM之岛
                                case GOSSIP_ACTION_INFO_DEF + 14 :
                                player->TeleportTo(1,16222.1,16252.1,12.5872,0);
                                break;
                            //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                         }
                         break;


                                case 6:
                        switch(action) {
                                // ·[14] 怒焰裂谷 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(389,2.024650,-10.021000,-16.187500,0);
                                        break;
                                // ·[19] 死亡矿井
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(36,-16.4,-383.07,61.78,0);
                                        break;
                                // ·[22] 哀嚎洞穴
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(43,-161.841995,133.266998,-73.866203,0);
                                        break;
                                // ·[24] 影牙城堡
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(33,-228.19,2110.56,76.89,0);
                                        break;
                                // ·[26] 黑暗深渊
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(48,-150.367004,102.995003,-40.555801,0);
                                        break;
                                // ·[27] 暴风城监狱
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(34,48.29,0.45,-16.14,0);
                                        break;
                                // ·[31] 剃刀沼泽
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(47,1943,1544,82,0);
                                        break;
                                // ·[33] 诺莫瑞根
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(90,-332.562988,-3.445,-152.845993,0);
                                        break;
                                // ·[40] 血色修道院
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(189,855.903992,1321.939941,18.673000,0);
                                        break;
                                // ·[42] 剃刀高地
                                case GOSSIP_ACTION_INFO_DEF + 10 :
                                        player->TeleportTo(129,2593.209961,1109.459961,51.093300,0);
                                        break;
                                // ·[45] 奥达曼
                                case GOSSIP_ACTION_INFO_DEF + 11 :
                                        player->TeleportTo(70,-227.529007,45.009800,-46.019600,0);
                                        break;
                           //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                                                        }
                            break;
 

                // 中级副本
                case 7:
                        switch(action) {
                                // ·[46] 祖尔法拉克 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(209,1213,841,8.9,0);
                                        break;
                                // ·[49] 玛拉顿
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(349,1012.700012,-459.317993,-43.547100,0);
                                        break;
                                // ·[53] 失落的神庙
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(109,-313.369995,99.955399,-131.848999,0);
                                        break;
                                // ·[57] 黑石深渊
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(230,456.928986,34.927700,-69.388100,0);
                                        break;
                                // ·[60] 通灵学院
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(289,199,126,135,0);
                                        break;
                                // ·[60] 厄运之槌 (北区)
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(429,255.164001,-17.024200,-2.560600,0);
                                        break;
                                // ·[60] 厄运之槌 (东区)
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(429,46.24,-155.53,-2.71349,0);
                                        break;
                                // ·[60] 厄运之槌 (西区)
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(429,32.722599,159.417007,-3.470170,0);
                                        break;
                                // ·[60] 斯坦索姆
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(329,3392,-3379,143,0);
                                        break;
                                // ·[60] 黑石塔下
                                case GOSSIP_ACTION_INFO_DEF + 10 :
                                        player->TeleportTo(229,78.19,-227.63,49.72,0);
                                        break;
                            //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;

                                                        }
                            break;

                // 高级副本
                case 8:
                        switch(action) {
                                // ·[团] 溶火之心 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(409,1089.601685,-470.190247,-106.413055,0);
                                        break;
                                // ·[团] 黑石塔上
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(229,78.339836,-227.793518,49.7103,0);
                                        break;
                                // ·[团] 祖尔格拉布
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(309,-11916,-1251.469971,92.32,0);
                                        break;
                                // ·[团] 黑翼之巢
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(469,-7674.470215,-1108.380005,396.649994,0);
                                        break;
                                // ·[团] 安其拉
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(531,-8212.002930,2034.474854,129.141342,0);
                                        break;
                                // ·[团] 安其拉废墟
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(509,-8443.475586,1518.648560,31.906958,0);
                                        break;
                                // ·[团] 奥妮克希亚的巢穴
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(249,30.010290,-58.840508,-5.325367,0);
                                        break;
                                                                //·[团] 纳克萨玛斯 
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(533,3005.87,-3435.01,293.882,0);
                                        break;
                                                            // ·[团] 冰龙巢穴
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(533,3700.35,-5185.92,143.957,4.403038,0);
                                        break;
                           //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;

                 }
                            break;

              
             // 外域地图副本1
               case 9:
                  switch(action) {
                   // [黑暗神庙]：(MapID, X, Y, Z, 0);
                   case GOSSIP_ACTION_INFO_DEF + 1 :
                   player->TeleportTo(530, -3644.052490, 316.709167, 35.027168, 3.087411);
                   break;
                   // [黑暗神庙]神殿之巅
                   case GOSSIP_ACTION_INFO_DEF + 2 :
                   player->TeleportTo(564, 757.632, 312.655, 312.296, 0);
                   break; 
                   // 波塔尼卡
                   case GOSSIP_ACTION_INFO_DEF + 3 :
                   player->TeleportTo(553, 40.000000, -28.600000, -1.100000, 0);
                   break;
                  // 亚克崔兹
                   case GOSSIP_ACTION_INFO_DEF + 4 :
                   player->TeleportTo(552, -1.200000, 0.000000, -0.200000, 0);
                   break;
                   // 麦克那尔
                   case GOSSIP_ACTION_INFO_DEF + 5 :
                   player->TeleportTo(554, -28.900000, 0.700000, -1.800000, 0);
                   break;
                   // 奴隶监狱
                   case GOSSIP_ACTION_INFO_DEF + 6 :
                   player->TeleportTo(547, 123.146225, -122.687210, -0.446336, 0);
                   break;
                                    // 蒸汽洞窟
                   case GOSSIP_ACTION_INFO_DEF + 7 :
                   player->TeleportTo(545, -7.500000, 5.900000, -4.300000, 0);
                   break;
                                    // 毒牙沼泽
                   case GOSSIP_ACTION_INFO_DEF + 8 :
                   player->TeleportTo(546, 14.913731, -19.914341, -2.755679, 0);
                   break;
                                   // 生态船 统一格式说明：(MapID, X, Y, Z, 0);
                   case GOSSIP_ACTION_INFO_DEF + 9 :
                   player->TeleportTo(553, 12.834653, 1.307080, -0.955370, 0);
                   break;
                   // 能源舰
                   case GOSSIP_ACTION_INFO_DEF + 10 :
                   player->TeleportTo(554, -20.094719, -1.743790, -1.812820, 0);
                   break;
                   // 奥金尼地穴
                   case GOSSIP_ACTION_INFO_DEF + 11 :
                   player->TeleportTo(558, -4.480981, 1.313732, -0.120600, 0);
                   break;
                   //  法力陵墓
                   case GOSSIP_ACTION_INFO_DEF + 12 :
                   player->TeleportTo(557, -3.508469, 1.337236, -0.954300, 0);
                   break;
                   // 塞泰克大厅
                   case GOSSIP_ACTION_INFO_DEF + 13 :
                   player->TeleportTo(556, 26.238617, 2.024134, 0.005409, 0);
                   break;
                   // 盘牙洞穴
                    case GOSSIP_ACTION_INFO_DEF + 14 :
                    player->TeleportTo(548, 29.142296, -57.074600, -71.733269, 0);
                        break;
                    //返回
                   case GOSSIP_ACTION_INFO_DEF + 99 :
                   GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                   break;                                   
            }
                   break;


                         // 外域地图副本2
               case 10:
                  switch(action) {
                   //[副本]海加尔山
                                   case GOSSIP_ACTION_INFO_DEF + 1 :
                   player->TeleportTo(534, 4890.761719, -1584.422383, 1333.669312, 0);
                   break;
                                   //[副本]风暴要塞
                                   case GOSSIP_ACTION_INFO_DEF + 2 :
                   player->TeleportTo(550, 7.488912, -1.140651, -2.428264, 0);
                   break;
                                   //毒蛇神殿
                   case GOSSIP_ACTION_INFO_DEF + 3 :
                   player->TeleportTo(548, 5.148121, 1.073185, 822.309021, 0);
                   break;
                                   //阿克蒙德
                   case GOSSIP_ACTION_INFO_DEF + 4 :
                   player->TeleportTo(534, 4494.741211, -2396.779855, 1137.229248, 0);
                   break;
                                   // 玛瑟里顿的巢穴
                   case GOSSIP_ACTION_INFO_DEF + 5 :
                   player->TeleportTo(544, 188.414261, 29.327892, 67.934464,0);
                   break;
                   // 破碎大厅
                   case GOSSIP_ACTION_INFO_DEF + 6 :
                   player->TeleportTo(540, -41.000000, -22.000000, -14.000000, 0);
                   break;
                   // 血熔炉
                   case GOSSIP_ACTION_INFO_DEF + 7 :
                   player->TeleportTo(542, -3.000000, 11.000000, -45.000000, 0);
                   break;
                        // 卡拉赞 
                        case GOSSIP_ACTION_INFO_DEF + 8 :
                        player->TeleportTo(532, -11107.950195, -2002.060059, 49.889999, 0);
                        break;
                        // 遗忘之井 
                        case GOSSIP_ACTION_INFO_DEF + 9 :
                        player->TeleportTo(0, -11068.07313, -1811.069946, 52.820000, 0);
                        break;
                        // 鬼魂之地 
                        case GOSSIP_ACTION_INFO_DEF + 10 :
                        player->TeleportTo(530, 6851.197266, -7993.672852, 192.292496, 0);
                        break;
                        // 地狱火堡垒 
                        case GOSSIP_ACTION_INFO_DEF + 11 :
                        player->TeleportTo(543, -1355.817261, 1646.834595, 68.447365, 0);
                        break;
                        // 奥金顿
                        case GOSSIP_ACTION_INFO_DEF + 12 :
                        player->TeleportTo(555, 2.164014, 0.402381, -1.127880, 0);
                        break;
                        // 戈鲁尔之巢
                        case GOSSIP_ACTION_INFO_DEF + 13 :
                        player->TeleportTo(530, 3543.437012, 5079.009766, 0.952552, 0);
                        break;
                        // 黑色沼泽 统一格式说明：(MapID, X, Y, Z, 0);
                        case GOSSIP_ACTION_INFO_DEF + 14:
                        player->TeleportTo(269, -2095.298584, 7125.536133, 34.588596, 0);
                        break;
                            //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
            }
                   break;

                         
                // 野外BOSS坐标
                case 11:
                        switch(action) {

                                // 暮色森林 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(0,-10526.168945,-434.996796,50.894821,0);
                                        break;
                                // 辛特兰
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(0,759.605713,-3893.341309,116.475304,0);
                                        break;
                                // 灰谷
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(1,3120.289307,-3439.444336,139.566345,1);
                                        break;
                                //  艾萨拉
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(1,2622.219971,-5977.930176,100.562897,1);
                                        break;
                                // 菲拉斯
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(1,-2741.290039,2009.481323,31.877323,1);
                                        break;
                                // 诅咒之地
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(0,-12234.000000,-2474.000000,-3.000000,0);
                                        break;
                                //水晶谷
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(1,-6292.463379,1578.029053,0.155348,1);
                                        break;
                            //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                                                        }
                            break;


                        
                                           // 三大战场坐标
                 case 12 :
                        switch(action) {

                                // 古拉巴什竞技场 统一格式说明：(MapID, X, Y, Z, 0);
                                case GOSSIP_ACTION_INFO_DEF + 1 :
                                        player->TeleportTo(0,-13225.715820,233.165405,33.344490,0);
                                        break;
                                // [部落]奥特兰战场
                                case GOSSIP_ACTION_INFO_DEF + 2 :
                                        player->TeleportTo(30,-1237.976318,-321.319366,60.7065730,0);
                                        break;
                                // [部落]战歌峡谷
                                case GOSSIP_ACTION_INFO_DEF + 3 :
                                        player->TeleportTo(489,1123.168823,1462.474976,315.564148,3.464511,0);
                                        break;
                                // [部落]阿拉希战场
                                case GOSSIP_ACTION_INFO_DEF + 4 :
                                        player->TeleportTo(529,855.156128,828.636108,-57.707348,2.812707,0);
                                        break;
                                                                // [部落]暴风之眼
                                case GOSSIP_ACTION_INFO_DEF + 5 :
                                        player->TeleportTo(566,1857.803101,1522.856323,1217.197510,0);
                                        break;
                                                                // [联盟]奥特兰战场
                                case GOSSIP_ACTION_INFO_DEF + 6 :
                                        player->TeleportTo(30,606.597351,-24.840078,42.931183,0);
                                        break;
                                                                // [联盟]战歌峡谷
                                case GOSSIP_ACTION_INFO_DEF + 7 :
                                        player->TeleportTo(489,1413.284302,1412.571411,345.538391,0);
                                        break;
                                                                // [联盟]阿拉希战场
                                case GOSSIP_ACTION_INFO_DEF + 8 :
                                        player->TeleportTo(529,1169.572266,1157.919312,-56.533646,0);
                                        break;
                                                                // [联盟]暴风之眼
                                case GOSSIP_ACTION_INFO_DEF + 9 :
                                        player->TeleportTo(566,2484.765137,1608.996460,1222.475342,0);
                                        break;
                            //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
                                                        }

                            break;


                  case 13 :
                  switch(action) {
                  // 个人银行
          case GOSSIP_ACTION_INFO_DEF + 1 :
                  player->GetSession()->SendShowBank(player->GetGUID());
                  player->CLOSE_GOSSIP_MENU();
                  break;
                  // 装备修复
          case GOSSIP_ACTION_INFO_DEF + 2 :
                  player->DurabilityRepairAll(true,0,0);
                  player->GetSession()->SendAreaTriggerMessage(" 你的全部装备修理完毕 ");
                  player->CLOSE_GOSSIP_MENU();
                  break;
                  //开飞行点
          case GOSSIP_ACTION_INFO_DEF + 3 :

                  for (uint8 i=0; i<8; i++)
                  { player->SetTaxiCheater(true); }
                  player->GetSession()->SendAreaTriggerMessage(" 你的飞行点已全部打开 ");
                  player->CLOSE_GOSSIP_MENU();

                  break;
                  //开地图
          case GOSSIP_ACTION_INFO_DEF + 4 :

                  for (uint8 i=0; i<64; i++)
                        player->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
                  player->GetSession()->SendAreaTriggerMessage(" 你的地图已全开 ");
                  player->CLOSE_GOSSIP_MENU();
                  break;
                  //领工资
          case GOSSIP_ACTION_INFO_DEF + 5 :
           if(player->GetInGameTime() > 3600) // 条件检查你在线时间大于3600秒．这可以自己改
            { 
            player->ModifyMoney(int32(1000000)*player->GetInGameTime()/3600); //满足条件获得100金币 
            player->SetInGameTime( uint32(0) ); //将玩家在线时间归零
            player->GetSession()->SendAreaTriggerMessage("工资已经领取");
            player->CLOSE_GOSSIP_MENU();             
            }
            else
            { 
            player->GetSession()->SendAreaTriggerMessage("你的在线时间不足");
            player->CLOSE_GOSSIP_MENU(); 
            }

        break; 
                  //绑定炉石
          //  case GOSSIP_ACTION_INFO_DEF + 6 :
//       bool ChatHandler::HandleSetHomeCommand(const char* args)  //
//   {
//         sDatabase.PExecute("UPDATE `character_homebind` SET `map` = '%u', `zone` = '%u', `position_x` = '%f', `position_y` = '%f', `position_z` = '%f' WHERE `guid` = '%u'", m_session->GetPlayer()->GetMapId(), m_session->GetPlayer()->GetZoneId(), m_session->GetPlayer()->GetPositionX(), m_session->GetPlayer()->GetPositionY(), m_session->GetPlayer()->GetPositionZ(), m_session->GetPlayer()->GetGUIDLow());
  //       m_session->GetPlayer()->m_homebindMapId = m_session->GetPlayer()->GetMapId();
    //     m_session->GetPlayer()->m_homebindZoneId = m_session->GetPlayer()->GetZoneId();
      //   m_session->GetPlayer()->m_homebindX = m_session->GetPlayer()->GetPositionX();
        // m_session->GetPlayer()->m_homebindY = m_session->GetPlayer()->GetPositionY();
         //m_session->GetPlayer()->m_homebindZ = m_session->GetPlayer()->GetPositionZ();
         //player->GetSession()->SendAreaTriggerMessage("你已设此地为炉石点");
        //return
//true;
//}

                //技能熟练提升到最大
            case GOSSIP_ACTION_INFO_DEF + 7 :
	    player->UpdateSkillsToMaxSkillsForLevel();
        player->GetSession()->SendAreaTriggerMessage(" 你的技能已提升到最大 ");
	    break;
               //返回炉石点
            //case GOSSIP_ACTION_INFO_DEF + 8 :
            //bool ChatHandler::HandleGoHomeCommand(const char* args)  //       modify by  w1w
            //{
            // QueryResult *resultDB = sDatabase.PQuery("SELECT `position_x`,`position_y`,`position_z`,`map` FROM `character_homebind` WHERE `guid` = '%u'",m_session->GetPlayer()->GetGUIDLow());
           //if (!resultDB) 
            //    return
       // false;
       // Field *fields;
       // fields = resultDB->Fetch();
       // float x=fields[0].GetFloat();
       // float y=fields[1].GetFloat();
       // float z=fields[2].GetFloat();
       // uint32 mapid=fields[3].GetUInt32();
      //  delete resultDB;
      //  m_session->GetPlayer()->TeleportTo(mapid, x, y, z,0.0f);
       // return
//true;
//}
                                                          //返回
                            case GOSSIP_ACTION_INFO_DEF + 99 :
                            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
                            break;
				  }
                         break;


  
                                        }                        
return true;
}

void AddSC_Item_teleport()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="Item_teleport";
        newscript->pItemUse = GossipHello_ItemUse_Item_teleport;
//    newscript->pGossipSelect_Item = GossipSelect_ItemUse_Item_teleport;
    newscript->RegisterSelf();
}
