#pragma once
/*
Player class

・カード
・チップ
・名前
・スート
・order;//今何番目か

CPU class
・カード
・チップ
・名前
・スート 

controller class
・入力処理
・各種サブウィンドウ的情報呼び出し(クリックorキー)
・


場を管理するクラス

GameMgr

・ポッド
・ゲームが今どのフェイズなのか
・どのプレイヤーがどのカードを出していて、何枚チップを賭けているのか
・また今までどのプレイヤーがどのカードを出していたのかの履歴
・ゲームのルールを管理するクラス(カードの強弱やチップの補正)
・背景画像
・優先するプレイヤーの設定

これらの管理、表示


■待ち→自分の選択→待ち→自分の選択→判定→結果





*/

/**
 *
 *
 *
 */

/**
 * \brief Chunkにデータを追加する
 * \warning 入っているデータは未定義
 * \return 作成したEntity
 */
//Entity createEntity();

/**
 * \brief Entityを他のチャンクに移動させる
 * \param entity 移動させるEntity
 * \param other 移動先Chunk
 */
//void moveEntity( Entity& entity, Chunk& other );

/**
 * \brief データを取得する
 * \tparam T Archetypeに設定されているいずれかの型
 * \return Tの配列
 */
/*
template<class T>
[[nodiscard]] ComponentArray<T> getComponentArray()
{
	using TType = std::remove_const_t<std::remove_reference_t<T>>;
	auto offset = mArchetype.getOffset<TType>() * mCapacity;
	return ComponentArray<T>(reinterpret_cast<TType*>(mpBegin.get() + offset), mSize);
}*/


/**
 * \brief
 * Chunk内のデータ構造を表す
 * 型の順番を関係なく扱う
 * Archetype::create<Position,Rotation,Scale>() == Archetype::create<Rotation,Scale,Position>()
 */
//struct Archetype


/**
 * \brief IComponentDataを継承した型までのメモリサイズを取得
 * \details Archetypeに含まれない型の場合getArchetypeSize()と同じ値を返す
 * \tparam Type IComponentData
 * \return Indexまでのバイト数
 */

/**
 * \brief 現在のSizeでCapacityを切り詰める
 */
/**
 * 
 */
//void fit();