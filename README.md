# koyofes
powerd by [Siv3D](https://play-siv3d.hateblo.jp)

カメラ映像の上にテクスチャ被せて回したりしてそれっぽいHUD感を出します.

デフォルトで入っている画像は下のようにMicrosoft PowerPointで作ってあります.
<img src="https://imgur.com/Fa1q2JO.jpg" alt="デフォルト" title="サンプル1">

デフォルトではこんな感じ

<img src="https://imgur.com/U4TT42s.jpg" alt="改造例" title="サンプル2">

こんな感じで色とか変えてみたり

用意する機器
 * Siv3D必要環境を満たしたPC
 * Webカメラ、またはWebカメラとして使用する端末

導入手順
 1. [ここ](https://github.com/Siv3D/Reference-JP/wiki/ダウンロードとインストール) を見てSiv3Dをインストール、Visual Studioで使えるように設定(Visual Studio 2017で使う場合、[特殊な手順](https://github.com/Siv3D/Reference-JP/wiki/VS2017-での開発)が入るので注意)
 2. [GitHub Extension for Visual Studio](https://visualstudio.github.com)をインストール
 3. このリポジトリの"Clone or download"->"Open in Visual Studio"
 4. [DroidCam](https://www.dev47apps.com)のような、スマホやタブレットをWebカメラとして認識させるソフトウェアを使用、またはワイヤレスWebカメラを接続
 5. 使用するカメラの番号、表示するモニターの解像度等をこのプロジェクトのMain.cppから設定
 6. ビルド
 
使い方
 * Fキー ... 全画面
 * Wキー ... 全画面解除
 * Escキー ... 終了
