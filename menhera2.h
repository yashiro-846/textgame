#pragma once
#include <windows.h> 



//元カノのデータ構造・西家
struct motokano {
	int enemyHP;//元カノのHP
	int bossHP;//ボス元カノのHP
	int enemyMaxDice;//元カノの攻撃の最大値
	int enemyMinDice;//元カノの攻撃の最小値
	int enemyDice;//元カノの持っているサイコロ
	int bossMaxDice;//ボス元カノの攻撃の最大値
	int bossMinDice;//ボス元カノの攻撃の最小値
	int bossDice;//ボス元カノの持っているサイコロ
	int enemyAttack;//元カノが振ったサイコロの出目
	int bossAttack;//ボス元カノが振ったサイコロの出目
	int enemyWepon;//元カノの持っている武器
}motokano;

//プレイヤー構造体・高桑
struct player {
	int playerFriend;//現在の仲間の数
	int playerHP;//誠のHP
	int playerMaxDice;//1つあたりのサイコロの最大値
	int playerMinDice;//1つ当たりのサイコロの最小値
	int playerDice;//誠の持ってるサイコロの数
	int playerAttack;//誠が降ったサイコロの出目
	int crazyPhoto;//ヤバい写真の所持を示す
	int selectCommand;//現在選択しているコマンド
	int lastCommand;//最後に選択したコマンド
	int playerArmor;//誠の防具を示す
	int key[5];//鍵の所持を示す
	int aidKitStock;//救急箱のストック
	int win;//誠の勝利条件を満たしたかどうか
	int lose;//誠の敗北条件を満たしたかどうか
	int playerHere;//プレイヤーがいる場所を記録

}player;

//部屋の構造体・川野
struct room {
	int roomNumber;//101号室から1008号室を表す
	int rouka1F;//1階の廊下(Corridor)を表す
	int rouka10F;//10階の廊下(Corridor)を表す
	int elevater;//エレベーターを表す
	int battle;//バトルしているか
	int isEnemy; //敵の有無
	int isPlayer; //プレイヤーが現在いるかどうか
	int playerHasHere; //プレイヤーがここにきたことがあるか
	int lock; //ドアの情報
	int Armor;
	int key; //鍵の情報
	int isLatex; //ゴム手袋の情報
	int isMagazine; //雑誌の情報
	int crazyPhoto; //やばい写真の情報
	int IsElevator; //エレベータの情報
	int aidKit; //救急箱の有無
};

//ダンジョンの構造体・アルリヤミ
struct dungeon {
	int room101;
	int room102;
	int room103;
	int room104;
	int room105;
	int room106;
	int room107;
	int room108;
	int room1001;
	int room1002;
	int room1003;
	int room1004;
	int room1005;
	int room1006;
	int room1007;
	int room1008;
	int rouk1F;
	int rouk10F;
	int elevator;
};

void showFloor1() {//１Ｆ見取り図・西家
	printf("---------------------------------------------------------------------\n");
	printf(" 1F      *101*******102*******103*******104*******\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("**************************************************\n");
	printf("*Elevator*                                       *\n");
	printf("*        *                                       *\n");
	printf("*        *               Makoto                  *\n");
	printf("*        *                                       *\n");
	printf("*        *                                       *\n");
	printf("**************************************************\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *105*******106*******107*******108*******\n");
	printf("--------------------------------------------------------------------\n");
};
void showFloor2() {//10F見取り図・西家
	printf("---------------------------------------------------------------------\n");
	printf(" 10F     *1001******1002******1003******1004******\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("**************************************************\n");
	printf("*Elevator*                                       *\n");
	printf("*        *                                       *\n");
	printf("*        *                 Makoto                *\n");
	printf("*        *                                       *\n");
	printf("*        *                                       *\n");
	printf("**************************************************\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *         *         *         *         *\n");
	printf("         *1005******1006******1007******1008******\n");
	printf("--------------------------------------------------------------------\n");
};

void uwakiSelect() {
	Sleep(300);
	printf("今カノ:   後ろの女は誰よ？\n\n");
	Sleep(300);
	printf("今カノ:   元カノなの？　元カノなのよね！？\n\n");
	Sleep(300);
	printf("今カノ:   誠のそばにいていいのは私だけだものね\n\n");
	Sleep(300);
	printf("今カノ:   ここにも私を助けに来てくれたのよね・・・\n\n");
	Sleep(300);
	printf("今カノ:   そうに決まってるわよね？\n\n");
	printf("今カノ:   そんな女たちと浮気なんてしてないわよね・・・・・？\n\n");
}

void showTitle() {//タイトル・上ノ山
	printf("***************************************\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  __人人人人人人人人人人人人人人人__ *\n");
	printf("*  ＞　　　　　　　　　　　　　 　 ＜ *\n");
	printf("*  ＞　 メンヘラー’ｓ　ノッカー　 ＜ *\n");
	printf("*  ＞　　　　　　　　　　　　　 　 ＜ *\n");
	printf("*  ￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^￣ *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* 　～♡元カノまみれの　　　　　　 　　*\n");
	printf("* 　　　　　血みどろマンション編♡～　 *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("***************************************\n");
}

void showStaffRool() {//タイトル・上ノ山
	printf("***************************************\n");
	printf("* プロジェクトリーダー                *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* C0117242         西家 秋杜          *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* プログラミングスタッフ　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* C0117089         川野 佑斗          *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* C0117179         高桑 貴明          *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* マーケティングスタッフ              *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* C0116021         アルリヤミ・アリ   *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* ゲーム設計スタッフ                  *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  C0117050        上ノ山 海沙        *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  __人人人人人人人人人人人人人人人__ *\n");
	printf("*  ＞　　　　　　　　　　　　　 　 ＜ *\n");
	printf("*  ＞　 メンヘラー’ｓ　ノッカー　 ＜ *\n");
	printf("*  ＞　　　　　　　　　　　　　 　 ＜ *\n");
	printf("*  ￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^￣ *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("* 　～♡元カノまみれの　　　　　　 　　*\n");
	printf("* 　　　　　血みどろマンション編♡～　 *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("*   *******　　**　　 **　*****　　   *\n");
	printf("*   ** 　　　　***　　**  **　 ***　  *\n");
	printf("*   **　　　　 ****　 **　**     **　 *\n");
	printf("*   *******　　**　** **　**　 　 *　 *\n");
	printf("*   ** 　　　　**　 ****  **  　 ** 　*\n");
	printf("*   ** 　　　　**    ***  **   ***　  *\n");
	printf("*   *******　　**　　 **　*****　  　 *\n");
	printf("*  　　 　　　　　　　　　　　　　　　*\n");
	printf("***************************************\n");
}

void imakano() {
	printf("*********************************************************************************\n");
	printf("*                                                 /:::ハ､＼､::::＼＼:::::',    \t*\n");
	printf("*     ▼今カノ(princess) 　攻撃力：無限          i:::ｲ　｀> ー─--ミ::::::|    \t*\n");
	printf("*     ==================================         {:::|　  :＼::／::  ＼::ﾘ-}   \t*\n");
	printf("*     装備：なし                                 'r､:| 　<●>   <●>   !> ｲ    \t*\n");
	printf("*     HP：無限                                   |､`{　  ｀> .: ､　   __ﾉ     \t*\n");
	printf("*                                                |:∧ﾍ　　 ／､__r)＼   |::|    \t*\n");
	printf("*            　　                                |::`~', 〈  ,＿ｨｪｧ 〉 l:::》  \t*\n");
	printf("*            　                                  |::::::'､　 `=＝'´,,ｲ::ﾉﾉ从  \t*\n");
	printf("*            　                                ノ从､::::::`i､, .. .,／|:://:从 \t*\n");
	printf("*            　　＿＿＿_                                                       \t*\n");
	printf("*         　 ／  　　　 　＼                                                   \t*\n");
	printf("*   　　 　／   u　　 ノ　　＼         攻撃力：0        ▼誠(Player)           \t*\n");
	printf("*        ／    　 u （●）　　＼     =================================         \t*\n");
	printf("*        |           （__人__) |                         装備：なし            \t*\n");
	printf("*        ＼　  　u　　 .｀ ⌒／                                                \t*\n");
	printf("*      　ノ　　　　　　　　　＼                                                \t*\n");
	printf("*     ／´　　　 　　　　　 　　ヽ                                             \t*\n");
	printf("*********************************************************************************\n");
}

void showRoomEmpty() {//何もない部屋・西家
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*       Makoto                *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("*        |*********************\n\n");
};

void showRoomEnemyKnife() {//ナイフ元カノ・西家
	printf("***************************\n");
	printf("*    _________________        *\n");
	printf("*    |                |       *\n");
	printf("*    | あなたをずっと |       *\n");
	printf("*    |    待ってたわ　|       *\n");
	printf("*    | もう逃がさない |       *\n");
	printf("*    |_____ __________|       *\n");
	printf("*          V                  *\n");
	printf("*     Motokano                *\n");
	printf("*          &                  *\n");
	printf("*         Knif                *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*       Makoto                *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("*        |*********************\n\n");
};

void showRoomEnemyStan() {//スタンガン元カノ
	printf("***************************\n");
	printf("*    ___________________      *\n");
	printf("*    |                　|     *\n");
	printf("*    | 私と結婚するって |     *\n");
	printf("*    | 　言ったじゃない |     *\n");
	printf("*    | 　　この浮気者　 |     *\n");
	printf("*    |_____ ____________|     *\n");
	printf("*          V                  *\n");
	printf("*     Motokano                *\n");
	printf("*          &                  *\n");
	printf("*         Stun Gun          　*\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*        Makoto               *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("*        |*********************\n\n");
};

void showRoomMagazine() {//雑誌のある部屋・西家
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*          _________          *\n");
	printf("*          |サンデー|         *\n");
	printf("*          |        |         *\n");
	printf("*          |\\(0u0)\\ |         *\n");
	printf("*          |  MHM   |         *\n");
	printf("*          |________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showRoomGomu() {//ゴム手袋部屋・西家
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("* |      |       |      |     *\n");
	printf("* |      |_     _|      |     *\n");
	printf("* |        ]   [        |     *\n");
	printf("* |      |Ｕ   Ｕ|      |     *\n");
	printf("* |      |       |      |     *\n");
	printf("* ||||||||       ||||||||     *\n");
	printf("* ＵＵＵＵ  　   ＵＵＵＵ     *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showRoomAidkit() {	//
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*          _________          *\n");
	printf("*          |        |         *\n");
	printf("*          | AidKit |         *\n");
	printf("*          |  +HP   |         *\n");
	printf("*          |________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};



void showRoomYabai() {//
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*         ______________      *\n");
	printf("*        | __________  |      *\n");
	printf("*        | |         | |      *\n");
	printf("*        | |見せられ | |      *\n");
	printf("*        | | ないよ!!| |      *\n");
	printf("*        | |_________| |      *\n");
	printf("*        |_____________|      *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};


void showRoomEnemyKnifewthKey() {//
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*           Key               *\n");
	printf("*         rt-○               *\n");
	printf("*    _________________        *\n");
	printf("*    |                |       *\n");
	printf("*    | あなたをずっと |       *\n");
	printf("*    |    待ってたわ　|       *\n");
	printf("*    | もう逃がさない |       *\n");
	printf("*    |_____ __________|       *\n");
	printf("*          V                  *\n");
	printf("*     Motokano                *\n");
	printf("*          &                  *\n");
	printf("*        Knife                *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showRoomEnemyStanwithKey() {///
	printf("**************************\n");
	printf("*                             *\n");
	printf("*             Key             *\n");
	printf("*            qt-○            *\n");
	printf("*                             *\n");
	printf("*    ___________________      *\n");
	printf("*    |                　|     *\n");
	printf("*    | 私と結婚するって |     *\n");
	printf("*    | 　言ったじゃない |     *\n");
	printf("*    | 　　この浮気者　 |     *\n");
	printf("*    |_____ ____________|     *\n");
	printf("*          V                  *\n");
	printf("*     Motokano                *\n");
	printf("*          &                  *\n");
	printf("*        Stun Gun             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");

};

void showRoomBoss() {//
	printf("**************************\n");
	printf("*    _____________            *\n");
	printf("*    | Makoto     |           *\n");
	printf("*    |  助けて～  |           *\n");
	printf("*    |_____________>Lover     *\n");
	printf("*    ___________________      *\n");
	printf("*    |                　|     *\n");
	printf("*    |　誠を殺して　　　|     *\n");
	printf("*    | 　　私も死ぬ　　 |     *\n");
	printf("*    | 　　　さようなら |     *\n");
	printf("*    |_____ ____________|     *\n");
	printf("*          V                  *\n");
	printf("*      BossMotokano           *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");

};

void showRoomKey1() {//
	printf("***************************\n");
	printf("*    _____________            *\n");
	printf("*    |            |           *\n");
	printf("*    | Key One    |           *\n");
	printf("*    |            |           *\n");
	printf("*    |___   ______|           *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |      ___         *\n");
	printf("*        | |______| |         *\n");
	printf("*        | |________|         *\n");
	printf("*        | |________          *\n");
	printf("*        |_|________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showRoomKey2() {//
	printf("***************************\n");
	printf("*    _____________            *\n");
	printf("*    |            |           *\n");
	printf("*    | Key Two    |           *\n");
	printf("*    |            |           *\n");
	printf("*    |___   ______|           *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |      ___         *\n");
	printf("*        | |______| |         *\n");
	printf("*        | |________|         *\n");
	printf("*        | |________          *\n");
	printf("*        |_|________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showRoomKey4() {//
	printf("*1004**************************\n");
	printf("*    _____________            *\n");
	printf("*    |            |           *\n");
	printf("*    | Key Four   |           *\n");
	printf("*    |            |           *\n");
	printf("*    |___   ______|           *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |                  *\n");
	printf("*        | |      ___         *\n");
	printf("*        | |______| |         *\n");
	printf("*        | |________|         *\n");
	printf("*        | |________          *\n");
	printf("*        |_|________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
	
};

void showRoomElevatorKey() {//
	printf("***************************\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*        ___________          *\n");
	printf("*        | |        |         *\n");
	printf("*        | |Elevator|         *\n");
	printf("*        | |   Key  |         *\n");
	printf("*        |_|________|         *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*                             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("* Makoto |*********************\n\n");
};

void showElevator() {//
	printf("*******************************\n");
	printf("*               |             *\n");
	printf("*               |             *\n");
	printf("*               |             *\n");
	printf("*               |             *\n");
	printf("*______         |             *\n");
	printf("* 10F  |        |             *\n");
	printf("* ▲   |        |             *\n");
	printf("*      |        |             *\n");
	printf("* ▼   |        |             *\n");
	printf("* 1F   |        |             *\n");
	printf("*￣￣￣|        |             *\n");
	printf("*  開  |        |             *\n");
	printf("*      |        |             *\n");
	printf("*  閉  |        |             *\n");
	printf("*￣￣￣         |             *\n");
	printf("*               |             *\n");
	printf("*               |             *\n");
	printf("*******************************\n\n");
};

//ステータス表示・上ノ山・川野
void showStatus(int* mHP, int* mDice, int* mKey, int* mAidKitStock, int* mPhoto, int* mArmor, int* mHere) {
	printf("========================================\n");
	printf("誠のHP\t\t\t:%d\n", *mHP);
	printf("誠の攻撃力\t\t:%d\n", *mDice);
	printf("ヤバい写真の数\t\t:");
	if (*mPhoto != 0) {
		printf("%d", *mPhoto);
	}
	else {
		printf("-");
	}
	printf("\n");
	printf("装備している防具\t:");
	if (*mArmor == 1) {
		printf("週刊誌");
	}
	else if (*mArmor == 2) {
		printf("ゴム手袋");
	}
	else {
		printf("-");
	}
	printf("\n");
	printf("持っている鍵の番号\t:");
	int sum = 0;
	for (int keynum = 0; keynum < 5; keynum++) {//持っている鍵だけを表示	
		if (mKey[keynum] != 0) {
			printf("鍵%d ", keynum + 1);
		}

		sum += mKey[keynum];
	}
	if (sum == 0) {
		printf("-");
	}
	printf("\n");
	printf("救急箱の回復量ストック\t:");
	if (*mAidKitStock != 0) {
		printf("%d", *mAidKitStock);
	}
	else {
		printf("-");
	}
	printf("\n");
	printf("現在地\t\t\t:%d", *mHere);
	if ((*mHere / 100) >= 1) {//101~1008なら語尾に号室をつける
		printf("号室");
	}
	else if (*mHere == 1 || *mHere == 10) {//1、10なら語尾に階廊下をつける
		printf("階廊下");
	}
	else {
		printf("\bエレベーター");//それ以外の場所はエレベーター
	}
	printf("\n");
	printf("========================================\n");
}

void homo() {
	printf("***************************\n");
	printf("*                             *\n");
	printf("*  ____________               *\n");
	printf("* |        |ロ|               *\n");
	printf("* |        |11|               *\n");
	printf("* |________|ロ|               *\n");
	printf("*           ￣                *\n");
	printf("*                             *\n");
	printf("*    ___________________      *\n");
	printf("*    |  　ヤらないか　　|     *\n");
	printf("*    |_____ ____________|     *\n");
	printf("*          V                  *\n");
	printf("*     Homo♂　                *\n");
	printf("*                             *\n");
	printf("*        Makoto♂             *\n");
	printf("*_________                    *\n");
	printf("*        |                    *\n");
	printf("*        |*********************\n");
}

void makotoDead() {//誠死亡・西家
	for (int i = 0; i < 40; i++)
	{
		Sleep(100);
		printf("│\n");
		printf("└→\n");
	}
	printf("さよなら\n");
	Sleep(1000);
}

//戦闘・上ノ山・高桑・西家
int battle(struct motokano motokanoN, int* mHP, int* mDice, int* mLast, int* mComand, int* mPhoto, int* mArmor, int* mMax, int* mMin, int* mAttack, int* isEnemy, int* gameloop, int* mFri) {

	//makoto.lastCommand = 0;
	int comonHP = 0;//敵の最初のHP 
	int mComonHP = 0;//誠の最初のHP
	int lose = 0;
	int mturn = 1;//1=誠のターン
	int eturn = 1;//1=敵のターン
	int recover = 0;//誠の回復量
	int survival = 0;//0:どちらも生存 1:誠死亡 2:敵死亡

	mComonHP = *mHP;
	system("cls");///////

	switch (*isEnemy) {//敵初期化分岐
	case 1:
		printf("元カノがナイフを持って詰め寄ってきた！！\n");
		motokanoN.enemyHP = 30;
		motokanoN.enemyMaxDice = 6;
		motokanoN.enemyMinDice = 1;
		motokanoN.enemyDice = 1;
		motokanoN.enemyAttack = 0;
		motokanoN.enemyWepon = 1;
		comonHP = motokanoN.enemyHP;
		if (*mPhoto != 0) {
			motokanoN.enemyDice++;
			printf("まずい！持っていたヤバい写真が見られた！！めちゃくちゃ怒ってる！！\n[敵攻撃力上昇]\n");
		}

		break;
	case 2:
		printf("元カノがスタンガンを持って詰め寄ってきた！！\n");
		motokanoN.enemyHP = 30;
		motokanoN.enemyMaxDice = 6;
		motokanoN.enemyMinDice = 1;
		motokanoN.enemyDice = 1;
		motokanoN.enemyAttack = 0;
		motokanoN.enemyWepon = 2;
		comonHP = motokanoN.enemyHP;
		if (*mPhoto != 0) {
			motokanoN.enemyDice++;
			printf("まずい！持っていたヤバい写真が見られた！！めちゃくちゃ怒ってる！！\n[敵攻撃力上昇]\n");
		}
		break;
	case 4:
		printf("ボス元カノが詰め寄ってきた！！\n");
		motokanoN.enemyHP = 40;
		motokanoN.enemyMaxDice = 6;
		motokanoN.enemyMinDice = 1;
		motokanoN.enemyDice = 2;
		motokanoN.enemyAttack = 0;
		motokanoN.enemyWepon = 3;
		comonHP = motokanoN.enemyHP;
		if (*mPhoto != 0) {
			motokanoN.enemyDice++;
			printf("まずい！持っていたヤバい写真が見られた！！めちゃくちゃ怒ってる！！\n[敵攻撃力上昇]\n");
		}
		break;
	}

	///////誠のターン

	while (survival == 0) {

		mturn = 1;
		eturn = 1;

		//対戦風
		printf("*********************************************************************************\n");
		printf("*                                                 /:::ハ､＼､::::＼＼:::::',    \t*\n");
		if (*isEnemy != 4) {//敵表示分岐
			printf("*     ▼元カノ(Enemy)     　攻撃力：%d	         i:::ｲ　｀> ー─--ミ::::::|    \t*\n", motokanoN.enemyDice);
		}
		else if (*isEnemy == 4) {
			printf("*     ▼ボス元カノ(Enemy) 　攻撃力：%d	         i:::ｲ　｀> ー─--ミ::::::|    \t*\n", motokanoN.enemyDice);
		}
		printf("*     ==================================         {:::|　  :＼::／::  ＼::ﾘ-}   \t*\n");
		if (*isEnemy == 1) {
			printf("*     装備：ナイフ                               'r､:| 　<●>   <●>   !> ｲ    \t*\n");
		}
		else if (*isEnemy == 2) {
			printf("*     装備：スタンガン                           'r､:| 　<●>   <●>   !> ｲ    \t*\n");
		}
		else {
			printf("*     装備：なし                                 'r､:| 　<●>   <●>   !> ｲ    \t*\n");
		}
		printf("*     HP：%d / %d                                 |､`{　  ｀> .: ､　   __ﾉ     \t*\n", motokanoN.enemyHP, comonHP);
		printf("*                                                |:∧ﾍ　　 ／､__r)＼   |::|    \t*\n");
		printf("*            　　                                |::`~', 〈  ,＿ｨｪｧ 〉 l:::》  \t*\n");
		printf("*            　                                  |::::::'､　 `=＝'´,,ｲ::ﾉﾉ从  \t*\n");
		printf("*            　                                ノ从､::::::`i､, .. .,／|:://:从 \t*\n");
		printf("*            　　＿＿＿_                                                       \t*\n");
		printf("*         　 ／  　　　 　＼                                                   \t*\n");
		printf("*   　　 　／   u　　 ノ　　＼         攻撃力：%d        ▼誠(Player)          \t*\n", *mDice);
		printf("*        ／    　 u （●）　　＼     =================================         \t*\n");
		if (*mArmor == 1) {
			printf("*        |           （__人__) |                         装備：週刊誌          \t*\n");
		}
		else if (*mArmor == 2) {
			printf("*        |           （__人__) |                         装備：ゴム手袋        \t*\n");
		}
		else {
			printf("*        |           （__人__) |                         装備：なし            \t*\n");
		}
		printf("*        ＼　  　u　　 .｀ ⌒／                          HP：%d / %d           \t*\n", *mHP, mComonHP);
		printf("*      　ノ　　　　　　　　　＼                                                \t*\n");
		printf("*     ／´　　　 　　　　　 　　ヽ                                             \t*\n");
		printf("*********************************************************************************\n");

		Sleep(100);
		while (mturn) {
			*mAttack = 0;

			printf("\n");
			printf("誠はどうする？\n\n");
			printf("==============================================================\n");
			printf("||  1) 口説く                 ||  2) 説得                   ||\n");
			printf("||                            ||                            ||\n");
			printf("||  敵HP半分以下で使用可能    ||  通常攻撃。 [コンボ▼]     ||\n");
			printf("||  強制戦闘終了し復縁する    ||  謝る+説得で攻撃力+2       ||\n");
			printf("||                            ||                            ||\n");
			printf("==============================================================\n");
			printf("||  3) 責める                 ||  4) 謝る                   ||\n");
			printf("||                            ||                            ||\n");
			printf("||  お互いの攻撃力+1[コンボ▼]||  お互いの攻撃力1に固定     ||\n");
			printf("||  謝る+責めるでHP回復+1     ||  二回連続では使えない      ||\n");
			printf("||                            ||                            ||\n");
			printf("==============================================================\n");


			printf("\n");
			scanf_s("%d", &*mComand);
			while (getchar() != '\n');
			printf("\n");
			switch (*mComand) {
			case 1:
				printf("誠は口説くを使った\n");
				Sleep(100);
				if (*isEnemy != 4)
				{
					if (motokanoN.enemyHP >= comonHP / 2) {//敵HP半分以上なら
						printf("元カノ：私がそんなに軽い女だと思ってるのか！！\n…………何の効果もなかった…\n");
						Sleep(100);
						mturn = 1;
					}
					else {
						printf("元カノ：……誠がそんなに言うなら……また前の関係に戻ってもいいよ……？\n元カノを口説き落として復縁した！！\n");
						Sleep(100);
						lose = 1;
						*mFri += lose;
						survival = 2;
						mturn = 0;
						eturn = 0;
					}
				}
				else
				{
					printf("元カノ：私がそんなに軽い女だと思ってるのか！！\n…………何の効果もなかった…\n");
					Sleep(100);
					mturn = 1;
				}
				*mLast = *mComand;
				break;
			case 2:
				system("cls");
				printf("誠は説得を試みた\n");
				Sleep(100);
				if (*mLast != 4) {//通常攻撃
					for (int i = 0; i < *mDice; i++) {
						*mAttack += rand() % 6 + 1;
					}
					motokanoN.enemyHP -= *mAttack;
					printf("元カノに%dのダメージ！！\n", *mAttack);
					Sleep(100);
				}
				else {//前ターン謝るコンボ
					for (int i = 0; i < *mDice + 2; i++) {
						*mAttack += rand() % 6 + 1;
					}
					motokanoN.enemyHP -= *mAttack;
					printf("元カノに%dのダメージ！！\n謝ったからか効果が大きい！！\n", *mAttack);
					Sleep(100);
				}
				mturn = 0;
				*mLast = *mComand;
				break;
			case 3:
				system("cls");
				printf("誠は責め立てた\n");
				Sleep(100);
				if (*mLast != 4) {//通常攻撃
					for (int i = 0; i < *mDice + 1; i++) {
						*mAttack += rand() % 6 + 1;
					}
					motokanoN.enemyHP -= *mAttack;
					printf("元カノに%dのダメージ！！\n", *mAttack);
					Sleep(100);
				}
				else {//前ターン謝るコンボ
					for (int i = 0; i < *mDice + 1; i++) {
						*mAttack += rand() % 6 + 1;
					}
					for (int i = 0; i < 1; i++) {
						recover = rand() % 6 + 1;
					}
					*mHP += recover;
					motokanoN.enemyHP -= *mAttack;
					printf("元カノに%dのダメージ！！\n逆切れしたらストレス解消した！！\n[誠のHP%d回復]\n", *mAttack, recover);
					Sleep(100);
				}
				mturn = 0;
				*mLast = *mComand;
				break;
			case 4:
				
				Sleep(500);
				if (*mLast != 4) {//通常攻撃
					system("cls");
					printf("誠はとにかく謝った\n");
					for (int i = 0; i < *mDice - 1; i++) {
						*mAttack += rand() % 6 + 1;
					}
					motokanoN.enemyHP -= *mAttack;
					printf("元カノに%dのダメージ！！\n", *mAttack);
					Sleep(100);
					mturn = 0;
				}
				else {//前ターン謝るコンボ
					printf("誠はとにかく謝った\n");
					mturn = 1;
					printf("元カノ:お前ずっと謝ってんな……ほんとに悪いと思ってるのか？\n…何か違うことをしなくちゃ！！！\n");
					Sleep(100);
				}
				*mLast = *mComand;
				break;
			}
		}
		if (*isEnemy != 4) {
			if (motokanoN.enemyHP <= 0) {
				survival = 2;
				printf("\n");
				printf("元カノを懐柔することに成功した！！！\n");
				printf("この部屋には今カノはいないようだ．．．\n");
				printf("誠は部屋を出ていった\n");
				printf("\n");
				*mLast = 0;
				Sleep(2000);
			}
		}
		else {//ボス戦勝利
			if (motokanoN.enemyHP <= 0) {
				survival = 3;
				*gameloop = 1;
				printf("\n");
				printf("今カノを助け出すことに成功した！！！！！\n");
				Sleep(100);
				if (*mFri == 0) {
					showStaffRool();
				}
				else
				{
					printf("\n");
					Sleep(1000);
					printf("おや…？\n");
					printf("\n");
					Sleep(1000);
					printf("助けに来た今カノがキレて襲い掛かってきた！！！！\n");
					printf("\n");
					Sleep(1000);
					imakano();
					uwakiSelect();
					int p = 0;
					printf("誠の回答\n");
					printf("1) 正直に話す     2) 嘘をつく     3)開き直ってハーレム宣言     4)黙る\n\n");
					scanf_s("%d", &p); 
					Sleep(1000);
					while (getchar() != '\n');
					if (p == 1) {
						printf("浮気は許さない");
						for (int i = 0; i < 40; i++)
						{
							Sleep(100);
							printf("許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない許さない\n");
						}
					}
					else if (p == 2) {
						printf("嘘つき・・・・・\n");
						for (int j = 0; j < 40; j++)
						{
							Sleep(100);
							printf("嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき嘘つき\n");
						}
					}
					else if (p == 3) {
						printf("ふざけてるの？・・・・・\n");
						for (int j = 0; j < 40; j++)
						{
							Sleep(100);
							printf("殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す殺す\n");
						}
					}
					else if (p == 4) {
						printf("ねえ、なんで黙っているの？\n");
						printf("どうして？\n");
						for (int j = 0; j < 40; j++)

						{
							Sleep(100);
							printf("なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。なんで。\n");
						}
					}
					survival = 1;
					*gameloop = 1;
					makotoDead();
					printf("\n");
					Sleep(1000);
					printf("誠は死んでしまった！！！！！\n");
				}

			}
		}
		//////////敵のターン
		if (motokanoN.enemyHP > 0) {
			while (eturn) {

				motokanoN.enemyAttack = 0;
				motokanoN.bossAttack = 0;
				printf("\n");
				if (*isEnemy == 4) {
				}//ボス分岐
				else if (*isEnemy == *mArmor) {//防具武器相性●
					motokanoN.enemyAttack = -2;
					if (motokanoN.enemyAttack < 0) {
						motokanoN.enemyAttack = 0;
					}
				}
				switch (*mLast) {//誠コンボ処理
				case 3://責めた場合

					for (int i = 0; i < motokanoN.enemyDice + 2; i++) {
						motokanoN.enemyAttack += rand() % 6 + 1;
					}
					*mHP -= motokanoN.enemyAttack;
					printf("誠に%dのダメージ！！\nさっき責めたせいで当たりがかなり強く感じる！！\n", motokanoN.enemyAttack);
					eturn = 0;
					break;
				case 4://謝った場合

					for (int i = 0; i < 1; i++) {
						motokanoN.enemyAttack += rand() % 6 + 1;
					}
					*mHP -= motokanoN.enemyAttack;
					printf("誠に%dのダメージ！！\nさっき謝ったおかげか少し手加減しているように感じる\n", motokanoN.enemyAttack);
					eturn = 0;
					break;
				default:
					for (int i = 0; i < motokanoN.enemyDice; i++) {
						motokanoN.enemyAttack += rand() % 6 + 1;
					}
					*mHP -= motokanoN.enemyAttack;
					printf("誠に%dのダメージ！！\n", motokanoN.enemyAttack);
					eturn = 0;
					break;
				}
			}

		}
		if (*mHP <= 0) {
			survival = 1;
			*gameloop = 1;
			makotoDead();
			printf("\n");
			printf("誠は死んでしまった！！！！！\n");
		}
	}
	return survival;
}