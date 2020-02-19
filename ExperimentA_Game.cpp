#include <iostream>
#include "menhera2.h"
#include <time.h>
#include <stdio.h>


//アイテム入手後の処理
void getitem(int* rKey, int* rAidKit, int* rPhoto, int* rArmor, int* mKey, int* mAidKitStock, int* mPhoto, int* mArmor, int* mHere, int* survival, int* rEnemy) {
	//アイテム加算
	int yn = 0;
	if (*rKey != 0) {
		int x = (*rKey - 1);
		mKey[x] += *rKey;
		if (*rKey == 1) {
			showRoomKey1();
			printf(" 鍵%d を見つけた\n", *rKey);
		}
		else if (*rKey == 2) {
			showRoomKey2();
			printf(" 鍵%d を見つけた\n", *rKey);
		}
		else if (*rKey == 3) {
			showRoomElevatorKey();
			printf(" 鍵%d (エレベーターキー)を見つけた\n", *rKey);
		}
		else if (*rKey == 4) {
			showRoomKey4();
			printf(" 鍵%d を見つけた\n", *rKey);
		}
		*rKey = 0;
	}
	else if (*rAidKit != 0) {
		*mAidKitStock += *rAidKit;
		printf("*%d", *mHere);
		showRoomAidkit();
		printf(" 救急箱（%d回復）を見つけた\n", *rAidKit);
		*rAidKit = 0;
	}
	else if (*rPhoto != 0) {
		*mPhoto += *rPhoto;
		//printf("*%d", *mHere);
		showRoomYabai();
		printf(" ヤバい写真を拾ってしまった！\nこれを持ったまま元カノに遭遇したら大ダメージを食らう気がする！！\n");
		*rPhoto = 0;
	}
	else if (*rArmor != 0) {
		if (*mArmor != 0) {//誠がすでに防具を持っているなら
			if (*rArmor == 1) {//1=週刊誌
				showRoomMagazine();
				printf("（防具）週刊誌");

			}
			else {//2=ゴム手
				showRoomGomu();
				printf("（防具）ゴム手袋");

			}
			printf("を見つけたがすでに違う防具を装備しています。交換しますか？\n1) yes\t2) no\n");
			printf("\n");
			scanf_s("%d", &yn);
			if (yn <= 1) {
				showRoomMagazine();
				*mArmor = *rArmor;
				printf("装備を交換した\n");
			}
			else if (yn >= 2) {
				printf("装備を拾わなかった\n");
				printf("見つけた装備をなくしてしまった…\n");
			}
		}
		else {
			if (*rArmor == 1) {//1=週刊誌
				showRoomMagazine();
				printf("（防具）週刊誌を見つけた。\n");

			}
			else {//2=ゴム手
				showRoomGomu();
				printf("（防具）ゴム手袋を見つけた。\n");

			}
			*mArmor = *rArmor;
			printf("防具を装備した\n");
		}
		*rArmor = 0;
	}
	else {
		if (*survival != 1 && *survival != 3) {//戦闘後に死亡の場合表示しない
			if (*rEnemy == 0) {
				showRoomEmpty();
				printf("ここにはもう何もない\n");
			}
		}
		else {
			printf("\n");
		}
	}
	Sleep(1000);


}



//一般部屋・西家・上ノ山・高桑
void inout(int rLock, int* rEnemy, int* rKey, int* rAidKit, int* rPhoto, int* rArmor, int* rHere, int* mKey, int* mAidKitStock, int* mPhoto, int* mArmor, int* mHere, int* rNum, int* mHP, int* mDice, int* rBat, int* survival) {//入退室処理 最後のmHPmDiceはshowStatus呼び出し用 


	int enemySurvival = 0;
	//int yn = 0;
	//マップ更新図をはさむならここに挿入
	if (rLock != 0) {//ロックされてる？

		printf(" 鍵%d がかかっている\n", rLock);
		if (mKey[0] == rLock || mKey[1] == rLock || mKey[2] == rLock || mKey[3] == rLock) {//鍵持ってる？

			printf(" 鍵%d を持っていたので部屋に入った\n", rLock);
			*mHere = *rNum;
			Sleep(1000);/////
			system("cls");/////
			if (*rHere == 1) {//来たことある？
				printf("*%d", *mHere);
				showRoomEmpty();
				printf("ここには何もない\n");

			}
			else {
				*rHere = 1;
				if (*rEnemy == 1 || *rEnemy == 4 || *rEnemy == 2) {//敵いる？
					enemySurvival = 1;
					if (*rEnemy == 1) {
						printf("*%d", *mHere);
						showRoomEnemyKnife();
					}
					else if (*rEnemy == 2) {
						printf("*%d", *mHere);
						showRoomEnemyStan();
					}
					else if (*rEnemy == 4) {
						printf("*%d", *mHere);
						showRoomBoss();
					}
					Sleep(1000);
					printf("戦闘開始！！\n");
					Sleep(1000);
					*rBat = 1;
					//戦闘プログラムへ
				}
				else {
					getitem(rKey, rAidKit, rPhoto, rArmor, mKey, mAidKitStock, mPhoto, mArmor, mHere, survival, rEnemy);//アイテム加算処理
				}
			}

		}
		else {
			printf("鍵がなくて入れない\n");
		}
	}
	else {
		*mHere = *rNum;
		//ロックされてない
		system("cls");
		printf("*%d", *mHere);
		if (*rHere == 1) {// 来たことある？
			showRoomEmpty();
			printf("ここには何もない\n");
		}
		else {
			*rHere = 1;
			if (*rEnemy == 1 || *rEnemy == 4 || *rEnemy == 2) {//敵いる？
				if (*rEnemy == 1) {
					showRoomEnemyKnife();
				}
				else if (*rEnemy == 2) {
					showRoomEnemyStan();
				}
				else if (*rEnemy == 4) {
					showRoomBoss();
				}
				Sleep(1000);
				printf("戦闘開始！！\n");
				Sleep(1000);
				*rBat = 1;
			}
			else {
				getitem(rKey, rAidKit, rPhoto, rArmor, mKey, mAidKitStock, mPhoto, mArmor, mHere, survival, rEnemy);//アイテム加算処理
			}
		}
	}
	if (*rBat == 0)
	{
		int i = 1;
		int j = 0;

		while (i) {
			printf("\n");
			printf("1) ▼廊下に戻る\t2) ▼ステータスを見る\t3) ▼回復する\n\n");
			scanf_s("%d", &i);
			if (i == 1) {
				printf("部屋を後にした\n");
				if (*rNum / 100 == 1) {
					*mHere = 1;
				}
				else {
					*mHere = 10;
				}

				i = 0;
			}
			else if (i == 2) {
				showStatus(mHP, mDice, mKey, mAidKitStock, mPhoto, mArmor, mHere);
				printf("\n");
				j = 0;
				while (j != 1) {
					printf("1) 戻る\n\n");
					scanf_s("%d", &j);
				}
				i = 1;
			}
			else if (i == 3) {
				if (*mAidKitStock != 0) {
					*mHP += *mAidKitStock;
					printf("誠のHPが%d回復した\n", *mAidKitStock);
					*mAidKitStock = 0;
				}
				else {
					printf("救急箱を持っていない\n");
				}
				i = 1;
			}
			else {
				i = 1;
			}
		}
	}
}

//エレベーター・上ノ山・アルリヤミ
void inout(int eLock, int* eHere, int* mKey, int* mAidKitStock, int* mPhoto, int* mArmor, int* mHere, int* eNum, int* mHP, int* mDice) {

	//マップ更新図をはさむならここに挿入


	int i = 1;
	int j = 0;
	printf("鍵3（エレベーターキー）がないと動かない\n");
	if (mKey[2] == eLock) {//エレベーターキー持ってる？
		printf("鍵3（エレベーターキー）を使った\n");
		*mHere = *eNum;


		while (i) {
			showElevator();
			printf("\n");
			printf("1) ▼1階の廊下に出る\t2) ▼ステータスを見る\t3) ▼回復する\t4) ▼10階の廊下に出る\n\n");
			scanf_s("%d", &i);
			if (i == 1) {
				printf("1階の廊下に出た\n");
				*mHere = 1;
				i = 0;
			}
			else if (i == 2) {
				showStatus(mHP, mDice, mKey, mAidKitStock, mPhoto, mArmor, mHere);
				printf("\n");
				j = 0;
				while (j != 1) {
					printf("1) 戻る\n\n");
					scanf_s("%d", &j);
				}
				i = 1;
			}
			else if (i == 3) {
				if (*mAidKitStock != 0) {
					*mHP += *mAidKitStock;
					printf("誠のHPが%d回復した\n", *mAidKitStock);
					*mAidKitStock = 0;
				}
				else {
					printf("救急箱を持っていない\n");
				}
				i = 1;
			}
			else if (i == 4) {
				printf("10階の廊下に出た\n");
				*mHere = 10;
				i = 0;
			}
			else {
				i = 1;
			}
		}
	}
	else {
		printf("エレベーターキーを手に入れなきゃ\n");
		j = 0;
		while (j != 1) {
			printf("1) 戻る\n\n");
			scanf_s("%d", &j);
		}
	}
}




int main(void) {//西家・上ノ山・川野・高桑
	srand((unsigned int)time(NULL));
	int roompattern = (int)rand() % 3 + 1;

	//構造体の実態を生成
	struct player makoto;
	makoto.playerHP = 30;
	makoto.playerMaxDice = 6;
	makoto.playerMinDice = 1;
	makoto.playerDice = 2;
	makoto.playerAttack = 0;
	makoto.crazyPhoto = 0;
	makoto.selectCommand = 0;
	makoto.lastCommand = 0;
	makoto.playerArmor = 0;
	makoto.key[0] = 0;//鍵なし
	makoto.key[1] = 0;//鍵１
	makoto.key[2] = 0;//鍵２
	makoto.key[3] = 0;//エレベーターキー
	makoto.key[4] = 0;//鍵４
	makoto.aidKitStock = 0;
	makoto.win = 0;
	makoto.lose = 0;
	makoto.playerHere = 1;
	makoto.playerFriend = 0;

	//元カノ1の構造体の実態を生成
	struct motokano motokanoN;
	motokanoN.enemyHP = 30;
	motokanoN.enemyMaxDice = 6;
	motokanoN.enemyMinDice = 1;
	motokanoN.enemyDice = 2;
	motokanoN.enemyAttack = 0;
	motokanoN.enemyWepon = 1;

	//エレベーターの構造体の実態を生成
	struct room elevater;
	elevater.lock = 3;
	elevater.roomNumber = 2;
	elevater.isPlayer = 1;


	//101号室の構造体の実態を生成
	struct room room101;
	room101.roomNumber = 101;
	room101.lock = 1;//かかっている鍵の種類0=なし　または　1~4
	room101.crazyPhoto = 0;//	アイテムは4つのうち一つだけ
	room101.Armor = 0;//		アイテムは4つのうち一つだけ
	room101.aidKit = 20;//		アイテムは4つのうち一つだけ
	room101.isPlayer = 0;
	room101.playerHasHere = 0;
	room101.isEnemy = 0;
	room101.key = 0;//			アイテムは4つのうち一つだけ
	room101.battle = 0;

	//102号室の構造体の実態を生成
	struct room room102;
	room102.roomNumber = 102;
	room102.lock = 0;
	room102.crazyPhoto = 0;
	room102.Armor = 0;
	room102.aidKit = 0;
	room102.isPlayer = 0;
	room102.playerHasHere = 0;
	room102.isEnemy = 0;
	room102.key = 1;
	room102.battle = 0;

	//103号室の構造体の実態を生成
	struct room room103;
	room103.roomNumber = 103;
	room103.lock = 0;
	room103.crazyPhoto = 0;
	room103.Armor = 0;
	room103.aidKit = 0;
	room103.isPlayer = 0;
	room103.playerHasHere = 0;
	room103.isEnemy = 0;
	room103.key = 0;
	room103.battle = 0;

	//104号室の構造体の実態を生成
	struct room room104;
	room104.roomNumber = 104;
	room104.lock = 0;
	room104.crazyPhoto = 0;
	room104.Armor = 0;
	room104.aidKit = 0;
	room104.isPlayer = 0;
	room104.playerHasHere = 0;
	room104.isEnemy = 0;
	room104.key = 3;//3はエレベーターキー
	room104.battle = 0;

	//105号室の構造体の実態を生成
	struct room room105;
	room105.roomNumber = 105;
	room105.lock = 0;
	room105.crazyPhoto = 0;
	room105.Armor = 0;
	room105.aidKit = 0;
	room105.isPlayer = 0;
	room105.playerHasHere = 0;
	room105.isEnemy = 1;
	room105.key = 0;
	room105.battle = 0;

	//106号室の構造体の実態を生成
	struct room room106;
	room106.roomNumber = 106;
	room106.lock = 2;
	room106.crazyPhoto = 0;
	room106.Armor = 2;
	room106.aidKit = 0;
	room106.isPlayer = 0;
	room106.playerHasHere = 0;
	room106.isEnemy = 0;
	room106.key = 0;
	room106.battle = 0;

	//107号室の構造体の実態を生成
	struct room room107;
	room107.roomNumber = 107;
	room107.lock = 0;
	room107.crazyPhoto = 0;
	room107.Armor = 0;
	room107.aidKit = 0;
	room107.isPlayer = 0;
	room107.playerHasHere = 0;
	room107.isEnemy = 2;
	room107.key = 0;
	room107.battle = 0;

	//108号室の構造体の実態を生成
	struct room room108;
	room108.roomNumber = 108;
	room108.lock = 0;
	room108.crazyPhoto = 0;
	room108.Armor = 0;
	room108.aidKit = 30;
	room108.isPlayer = 0;
	room108.playerHasHere = 0;
	room108.isEnemy = 0;
	room108.key = 2;
	room108.battle = 0;

	//模擬戦闘部屋の構造体の実態を生成
	struct room room109;
	room109.roomNumber = 109;
	room109.lock = 0;
	room109.crazyPhoto = 0;
	room109.Armor = 0;
	room109.aidKit = 0;
	room109.isPlayer = 0;
	room109.playerHasHere = 0;
	room109.isEnemy = 5;
	room109.key = 0;
	room109.battle = 0;

	//1001号室の構造体の実態を生成 ここから10階
	struct room room1001;
	room1001.roomNumber = 1001;
	room1001.lock = 0;//かかっている鍵の種類0=なし　または　1~4
	room1001.crazyPhoto = 0;//	アイテムは4つのうち一つだけ
	room1001.Armor = 1;//		アイテムは4つのうち一つだけ
	room1001.aidKit = 0;//		アイテムは4つのうち一つだけ
	room1001.isPlayer = 0;
	room1001.playerHasHere = 0;
	room1001.isEnemy = 0;
	room1001.key = 0;//			アイテムは4つのうち一つだけ
	room1001.battle = 0;

	//1002号室の構造体の実態を生成
	struct room room1002;
	room1002.roomNumber = 1002;
	room1002.lock = 0;
	room1002.crazyPhoto = 0;
	room1002.Armor = 0;
	room1002.aidKit = 0;
	room1002.isPlayer = 0;
	room1002.playerHasHere = 0;
	room1002.isEnemy = 2;
	room1002.key = 0;
	room1002.battle = 0;

	//1003号室の構造体の実態を生成
	struct room room1003;
	room1003.roomNumber = 1003;
	room1003.lock = 0;
	room1003.crazyPhoto = 1;
	room1003.Armor = 0;
	room1003.aidKit = 0;
	room1003.isPlayer = 0;
	room1003.playerHasHere = 0;
	room1003.isEnemy = 0;
	room1003.key = 0;
	room1003.battle = 0;

	//1004号室の構造体の実態を生成
	struct room room1004;
	room1004.roomNumber = 1004;
	room1004.lock = 0;
	room1004.crazyPhoto = 0;
	room1004.Armor = 0;
	room1004.aidKit = 0;
	room1004.isPlayer = 0;
	room1004.playerHasHere = 0;
	room1004.isEnemy = 1;
	room1004.key = 4;//4はボス鍵
	room1004.battle = 0;

	//1005号室の構造体の実態を生成
	struct room room1005;
	room1005.roomNumber = 1005;
	room1005.lock = 4;//仮置きボス部屋
	room1005.crazyPhoto = 0;
	room1005.Armor = 0;
	room1005.aidKit = 0;
	room1005.isPlayer = 0;
	room1005.playerHasHere = 0;
	room1005.isEnemy = 4;
	room1005.key = 0;
	room1005.battle = 0;

	//1006号室の構造体の実態を生成
	struct room room1006;
	room1006.roomNumber = 1006;
	room1006.lock = 0;
	room1006.crazyPhoto = 0;
	room1006.Armor = 0;
	room1006.aidKit = 30;
	room1006.isPlayer = 0;
	room1006.playerHasHere = 0;
	room1006.isEnemy = 0;
	room1006.key = 0;
	room1006.battle = 0;

	//1007号室の構造体の実態を生成
	struct room room1007;
	room1007.roomNumber = 1007;
	room1007.lock = 0;
	room1007.crazyPhoto = 0;
	room1007.Armor = 1;
	room1007.aidKit = 0;
	room1007.isPlayer = 0;
	room1007.playerHasHere = 0;
	room1007.isEnemy = 0;
	room1007.key = 0;
	room1007.battle = 0;

	//1008号室の構造体の実態を生成
	struct room room1008;
	room1008.roomNumber = 1008;
	room1008.lock = 0;
	room1008.crazyPhoto = 0;
	room1008.Armor = 0;
	room1008.aidKit = 0;
	room1008.isPlayer = 0;
	room1008.playerHasHere = 0;
	room1008.isEnemy = 0;
	room1008.key = 0;
	room1008.battle = 0;

	if (roompattern == 2) {//地図パターン２
		room104.key = 0;
		room104.isEnemy = 1;
		room105.key = 3;
		room105.isEnemy = 0;

		room1001.Armor = 0;
		room1001.isEnemy = 2;
		room1002.Armor = 1;
		room1002.isEnemy = 0;

		room1005.lock = 0;
		room1005.Armor = 1;
		room1005.isEnemy = 0;
		room1007.lock = 4;
		room1007.Armor = 0;
		room1007.isEnemy = 4;
	}
	else if(roompattern == 3) {//地図パターン３
		room101.lock = 0;
		room101.aidKit = 0;
		room101.isEnemy = 2;
		room107.lock = 1;
		room107.aidKit = 20;
		room107.isEnemy = 0;

		room1003.crazyPhoto = 0;
		room1003.aidKit = 30;
		room1006.crazyPhoto = 1;
		room1006.aidKit = 0;

		room1001.Armor = 0;
		room1008.Armor = 1;
	}

	int Suv = 0;
	showTitle();

	int select = 0;
	int survival = 0;

	while (select == 0) {//1，2以外の数字が選ばれたときに繰り返す

		makoto.playerHP = 30;//模擬戦闘後の設定を初期化するため
		makoto.crazyPhoto = 0;
		makoto.playerArmor = 0;

		printf("1) ゲームのルールを見る\n");
		printf("2) ゲームスタート\n");
		printf("3) 模擬戦闘\n");
		printf("4) ボス模擬戦闘\n\n");

		int n = 0;
		int yn = 0;//装備をするしない
		int gameloop = 0;//ゲーム開始からゲームオーバー手前までは0、エンディングで1など分岐

		scanf_s("%d", &n);
		while (getchar() != '\n');
		if (n == 1) {

			printf("\n\n\n\n\n\n");
			printf("1) プレイヤーはたらし男となり、元カノたちに誘拐された今カノを助け出すことが目的です。\n");
			printf("2) エンディングはプレイヤーの選択によって変化します。\n");
			printf("3) プレイヤーは各部屋を探索して回復アイテムや防御アイテムを入手できます。\n");
			printf("4) プレイヤーは待ち受ける元カノたちと戦闘をして懐柔したり仲間にできたりします。仲間にすることの意味を考えましょう。\n");
			printf("5) プレイヤーは防具アイテム（ゴム手袋、週刊誌）は一つしか所持できず、新しい防具を発見した場合は、手持ちの防具と交換するかしないか選べ、選ばなかった方は消滅します。\n");
			printf("6) プレイヤーは回復アイテムを複数所持することができ、戦闘以外の好きなタイミングで使用できます。回復量は30と20があり、プレイヤーのHP上限はありません。\n");
			printf("7) プレイヤーは鍵を入手できます。鍵は1度使用するとなくなり、使用された部屋やエレベーターは行き来が自由になります。\n");
			printf("8) プレイヤーはアイテム「ヤバい写真」を発見した場合、以降の戦闘で敵を強化してしまいます。\n");
			printf("9) プレイヤーは戦闘時に4つのコマンドの中から選択して攻撃することができ、それぞれに違った効果があります。\n");
			printf("10) 戦闘では必ず自分が先行攻撃できます。\n\n");
			select = 0;
		}
		else if (n == 2) {
			select = 1;//タイトル画面から出る
			//ゲームプログラムへ
			while (gameloop == 0) {//入退室,基本的にゲーム中はずっと回す
				if (room101.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room101.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room101.key, &room101.aidKit, &room101.crazyPhoto, &room101.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival,&room101.isEnemy);//戦闘後のアイテム取得処理
					room101.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room102.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room102.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room102.key, &room102.aidKit, &room102.crazyPhoto, &room102.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room102.isEnemy);
					room102.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room103.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room103.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room103.key, &room103.aidKit, &room103.crazyPhoto, &room103.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room103.isEnemy);
					room103.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room104.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room104.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room104.key, &room104.aidKit, &room104.crazyPhoto, &room104.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room104.isEnemy);
					room104.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room105.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room105.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room105.key, &room105.aidKit, &room105.crazyPhoto, &room105.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room105.isEnemy);
					room105.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room106.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room106.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room106.key, &room106.aidKit, &room106.crazyPhoto, &room106.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room106.isEnemy);
					room106.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room107.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room107.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room107.key, &room107.aidKit, &room107.crazyPhoto, &room107.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room107.isEnemy);
					room107.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room108.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room108.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room108.key, &room108.aidKit, &room108.crazyPhoto, &room108.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room108.isEnemy);
					room108.battle = 0;
					makoto.playerHere = 1;
				}
				else if (room1001.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1001.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1001.key, &room1001.aidKit, &room1001.crazyPhoto, &room1001.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1001.isEnemy);
					room1001.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1002.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1002.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1002.key, &room1002.aidKit, &room1002.crazyPhoto, &room1002.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1002.isEnemy);
					room1002.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1003.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1003.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1003.key, &room1003.aidKit, &room1003.crazyPhoto, &room1003.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1003.isEnemy);
					room1003.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1004.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1004.isEnemy, &gameloop, &makoto.playerFriend);
					if (survival != 1) {
						getitem(&room1004.key, &room1004.aidKit, &room1004.crazyPhoto, &room1004.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1004.isEnemy);
					}
					Sleep(1000);
					room1004.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1005.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1005.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1005.key, &room1005.aidKit, &room1005.crazyPhoto, &room1005.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1005.isEnemy);
					room1005.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1006.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1006.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1006.key, &room1006.aidKit, &room1006.crazyPhoto, &room1006.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1006.isEnemy);
					room1006.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1007.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1007.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1007.key, &room1007.aidKit, &room1007.crazyPhoto, &room1007.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1007.isEnemy);
					room1007.battle = 0;
					makoto.playerHere = 10;
				}
				else if (room1008.battle == 1)
				{
					survival = battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room1008.isEnemy, &gameloop, &makoto.playerFriend);
					getitem(&room1008.key, &room1008.aidKit, &room1008.crazyPhoto, &room1008.Armor, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &survival, &room1008.isEnemy);
					room108.battle = 0;
					makoto.playerHere = 10;
				}
				else if (makoto.playerHere == 1) //1階
				{
				
				system("cls");////////
					showFloor1();
					printf("\n");
					printf("1) ▼移動\t2) ▼ステータスを見る\t3) ▼回復する\n\n");
					int moveOrStatus = 0;
					scanf_s("%d", &moveOrStatus);
					while (getchar() != '\n');
					if (moveOrStatus == 1) {

						int room = 0;
						printf("▼どこに行く？\n\n1)101号室\t2)102号室\t3)103号室\t4)104号室\t\n5)105号室\t6)106号室\t7)107号室\t8)108号室\t\n9)エレベーター\n\n");
						scanf_s("%d", &room);
						while (getchar() != '\n');
						printf("\n");

						switch (room) {
						case 1:
							inout(room101.lock, &room101.isEnemy, &room101.key, &room101.aidKit, &room101.crazyPhoto, &room101.Armor, &room101.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room101.roomNumber, &makoto.playerHP, &makoto.playerDice, &room101.battle, &survival);
							break;
						case 2:
							inout(room102.lock, &room102.isEnemy, &room102.key, &room102.aidKit, &room102.crazyPhoto, &room102.Armor, &room102.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room102.roomNumber, &makoto.playerHP, &makoto.playerDice, &room102.battle, &survival);
							break;
						case 3:
							inout(room103.lock, &room103.isEnemy, &room103.key, &room103.aidKit, &room103.crazyPhoto, &room103.Armor, &room103.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room103.roomNumber, &makoto.playerHP, &makoto.playerDice, &room103.battle, &survival);
							break;
						case 4:
							inout(room104.lock, &room104.isEnemy, &room104.key, &room104.aidKit, &room104.crazyPhoto, &room104.Armor, &room104.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room104.roomNumber, &makoto.playerHP, &makoto.playerDice, &room104.battle, &survival);
							break;
						case 5:
							inout(room105.lock, &room105.isEnemy, &room105.key, &room105.aidKit, &room105.crazyPhoto, &room105.Armor, &room105.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room105.roomNumber, &makoto.playerHP, &makoto.playerDice, &room105.battle, &survival);
							break;
						case 6:
							inout(room106.lock, &room106.isEnemy, &room106.key, &room106.aidKit, &room106.crazyPhoto, &room106.Armor, &room106.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room106.roomNumber, &makoto.playerHP, &makoto.playerDice, &room106.battle, &survival);
							break;
						case 7:
							inout(room107.lock, &room107.isEnemy, &room107.key, &room107.aidKit, &room107.crazyPhoto, &room107.Armor, &room107.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room107.roomNumber, &makoto.playerHP, &makoto.playerDice, &room107.battle, &survival);
							break;
						case 8:
							inout(room108.lock, &room108.isEnemy, &room108.key, &room108.aidKit, &room108.crazyPhoto, &room108.Armor, &room108.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room108.roomNumber, &makoto.playerHP, &makoto.playerDice, &room108.battle, &survival);
							break;
						case 9://elevator
							inout(elevater.lock, &elevater.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &elevater.roomNumber, &makoto.playerHP, &makoto.playerDice);
							break;
						default:

							break;
						}
					}
					else if (moveOrStatus == 2) {
						//ステータスを見る
						showStatus(&makoto.playerHP, &makoto.playerDice, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere);
						printf("\n");
						while (moveOrStatus != 1) {
							printf("1) 戻る\n\n");
							scanf_s("%d", &moveOrStatus);
							while (getchar() != '\n');
						}
					}
					else if (moveOrStatus == 3) {
						if (makoto.aidKitStock != 0) {
							makoto.playerHP += makoto.aidKitStock;
							printf("誠のHPが%d回復した\n", makoto.aidKitStock);
							makoto.aidKitStock = 0;
						}
						else {
							printf("救急箱を持っていない\n");
						}
					}
					Sleep(1000);



				}
				else {//10階
				system("cls");////
					showFloor2();
					printf("\n");
					printf("1) ▼移動\t2) ▼ステータスを見る\t3) ▼回復する\n\n");
					int moveOrStatus = 0;
					scanf_s("%d", &moveOrStatus);
					while (getchar() != '\n');
					if (moveOrStatus == 1) {

						int room = 0;
						printf("▼どこに行く？\n\n1)1001号室\t2)1002号室\t3)1003号室\t4)1004号室\t\n5)1005号室\t6)1006号室\t7)1007号室\t8)1008号室\t\n9)エレベーター\n\n");
						scanf_s("%d", &room);
						while (getchar() != '\n');
						printf("\n");

						switch (room) {
						case 1:
							inout(room1001.lock, &room1001.isEnemy, &room1001.key, &room1001.aidKit, &room1001.crazyPhoto, &room1001.Armor, &room1001.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1001.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1001.battle, &survival);
							break;
						case 2:
							inout(room1002.lock, &room1002.isEnemy, &room1002.key, &room1002.aidKit, &room1002.crazyPhoto, &room1002.Armor, &room1002.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1002.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1002.battle, &survival);
							break;
						case 3:
							inout(room1003.lock, &room1003.isEnemy, &room1003.key, &room1003.aidKit, &room1003.crazyPhoto, &room1003.Armor, &room1003.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1003.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1003.battle, &survival);
							break;
						case 4:
							inout(room1004.lock, &room1004.isEnemy, &room1004.key, &room1004.aidKit, &room1004.crazyPhoto, &room1004.Armor, &room1004.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1004.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1004.battle, &survival);
							break;
						case 5:
							inout(room1005.lock, &room1005.isEnemy, &room1005.key, &room1005.aidKit, &room1005.crazyPhoto, &room1005.Armor, &room1005.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1005.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1005.battle, &survival);
							break;
						case 6:
							inout(room1006.lock, &room1006.isEnemy, &room1006.key, &room1006.aidKit, &room1006.crazyPhoto, &room1006.Armor, &room1006.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1006.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1006.battle, &survival);
							break;
						case 7:
							inout(room1007.lock, &room1007.isEnemy, &room1007.key, &room1007.aidKit, &room1007.crazyPhoto, &room1007.Armor, &room1007.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1007.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1007.battle, &survival);
							break;
						case 8:
							inout(room1008.lock, &room1008.isEnemy, &room1008.key, &room1008.aidKit, &room1008.crazyPhoto, &room1008.Armor, &room1008.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &room1008.roomNumber, &makoto.playerHP, &makoto.playerDice, &room1008.battle, &survival);
							break;
						case 9://elevator
							inout(elevater.lock, &elevater.playerHasHere, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere, &elevater.roomNumber, &makoto.playerHP, &makoto.playerDice);
							break;
						default:

							break;
						}
					}
					else if (moveOrStatus == 2) {
						//ステータスを見る
						showStatus(&makoto.playerHP, &makoto.playerDice, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere);
						printf("\n");
						while (moveOrStatus != 1) {
							printf("1) 戻る\n\n");
							scanf_s("%d", &moveOrStatus);
							while (getchar() != '\n');
						}
					}
					else if (moveOrStatus == 3) {
						if (makoto.aidKitStock != 0) {
							makoto.playerHP += makoto.aidKitStock;
							printf("誠のHPが%d回復した\n", makoto.aidKitStock);
							makoto.aidKitStock = 0;
						}
						else {
							printf("救急箱を持っていない\n");
						}
					}
				}
			}

			printf("GAME OVER");


		}
		else if (n == 3) {//模擬戦闘
			select = 3;
			room109.isEnemy = 1;
			while (select == 3)
			{
				int p = 0;
				printf("やばい写真を持ちますか？\n");
				printf("1) 持つ     2) 持たない\n");
				scanf_s("%d", &p);
				while (getchar() != '\n');
				if (p == 1) {
					makoto.crazyPhoto = p;
					printf("やばい写真を持ちました。\n");
				}
				else {
					makoto.crazyPhoto = 0;
					printf("やばい写真を諦めた。\n");
				}
				int a = 0;
				printf("防具を装備しますか？\n");
				printf("1) 装備する     2) 装備しない\n");
				scanf_s("%d", &a);
				while (getchar() != '\n');
				if (a == 1) {
					makoto.playerArmor = a;
					printf("防具を装備しました。\n");
				}
				else {
					makoto.playerArmor = 0;
					printf("防具を諦めた。\n");
				}
				int s = 0;
				printf("1) 戦闘開始     2) ステータスを見る\n");
				scanf_s("%d", &s);
				while (getchar() != '\n');
				if (s == 2) {
					int y = 0;
					showStatus(&makoto.playerHP, &makoto.playerDice, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere);
					printf("\n");
					printf(" 戦闘を開始しますか？\n");
					printf("1) 戦闘開始     2) タイトルに戻る\n");
					scanf_s("%d", &y);
					while (getchar() != '\n');
					if (y == 1)
					{
						battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room109.isEnemy, &gameloop, &makoto.playerFriend);
					}
					else
					{
						select = 0;
					}

				}
				else
				{
					battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room109.isEnemy, &gameloop, &makoto.playerFriend);
				}
				select = 0;
			}
		}
		else if (n == 4) {//ボスとの模擬戦闘
			select = 4;
			while (select == 4)
			{
				room109.isEnemy = 4;

				int p = 0;
				printf("やばい写真を持ちますか？\n");
				printf("1) 持つ     2) 持たない\n");
				scanf_s("%d", &p);
				while (getchar() != '\n');
				if (p == 1) {
					makoto.crazyPhoto = p;
					printf("やばい写真を持ちました。\n");
				}
				else {
					makoto.crazyPhoto = 0;
					printf("やばい写真を諦めた。\n");
				}
				int s = 0;
				printf("1) 戦闘開始     2) ステータスを見る\n");
				scanf_s("%d", &s);
				while (getchar() != '\n');
				if (s == 2) {
					int y = 0;
					showStatus(&makoto.playerHP, &makoto.playerDice, makoto.key, &makoto.aidKitStock, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerHere);
					printf("\n");
					printf(" 戦闘を開始しますか？\n");
					printf("1) 戦闘開始     2) タイトルに戻る\n");
					scanf_s("%d", &y);
					while (getchar() != '\n');
					if (y == 1)
					{
						printf("模擬戦闘ルームに入りました。\n");
						battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room109.isEnemy, &gameloop, &makoto.playerFriend);
						room109.isEnemy = 1;
					}
					else
					{
						select = 0;
						room109.isEnemy = 1;
					}

				}
				else
				{
					battle(motokanoN, &makoto.playerHP, &makoto.playerDice, &makoto.lastCommand, &makoto.selectCommand, &makoto.crazyPhoto, &makoto.playerArmor, &makoto.playerMaxDice, &makoto.playerMinDice, &makoto.playerAttack, &room109.isEnemy, &gameloop, &makoto.playerFriend);
					if (makoto.playerHP == 0)
					{
						makotoDead();
					}
				}
				select = 0;
			}
		}
	}
}







