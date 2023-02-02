#include <Novice.h>
#include<player.h>
#include<enemy.h>
#include<collision.h>
const char kWindowTitle[] = "K022G1060";

int enemy::enemyCount;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	
	player* Player_ = new player;
	enemy* Enemy_1 = new enemy;
	enemy* Enemy_2 = new enemy;
	
	collision* Collision_ = new collision;
	Player_->Initialize({ 100,600 }, { 10,10 }, 16, RED, 3);
	Enemy_1->Initialize({ 100,100 }, { 5,5 }, 16, WHITE, 1);
	Enemy_2->Initialize({ 100,150 }, { 1,5 }, 8, WHITE, 1);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		Player_->Move(keys);
		Player_->BulletShot(keys, preKeys);
		if (enemy::enemyCount >=2) {
			Enemy_1->Move();
			Enemy_2->Move();
			//当たり判定
			//玉と敵
			if (Collision_->CircleCollision(Enemy_1->getPos(), Enemy_1->getRadius(), Player_->getPosBullet(), Player_->getRadiusBullet()) == true) {
				Enemy_1->OnCollision();
				Player_->OnCollisionBullet();
				enemy::enemyCount--;
			}
			//プレイヤーと敵
			if (Collision_->CircleCollision(Player_->getPos(), Player_->getRadius(), Enemy_1->getPos(), Enemy_1->getRadius()) == true) {
				Player_->OnCollision();
				Enemy_1->OnCollision();
				enemy::enemyCount--;
			}
			if (Collision_->CircleCollision(Enemy_2->getPos(), Enemy_2->getRadius(), Player_->getPosBullet(), Player_->getRadiusBullet()) == true) {
				Enemy_2->OnCollision();
				Player_->OnCollisionBullet();
				enemy::enemyCount--;
			}
			//プレイヤーと敵
			if (Collision_->CircleCollision(Player_->getPos(), Player_->getRadius(), Enemy_2->getPos(), Enemy_2->getRadius()) == true) {
				Player_->OnCollision();
				Enemy_2->OnCollision();
				enemy::enemyCount--;
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Player_->DrawPlayer();
		if (enemy::enemyCount >=2) {
			Enemy_1->DrawEnemy();
			Enemy_2->DrawEnemy();
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
