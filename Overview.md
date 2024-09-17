# FlyingPlumについて
## 共通テスト　情報Iに登場する独自表記の言語の実行
教育機関で参考程度に使ってもらえるといいね

# 各フォルダの役割
## lexer
ファイルの中身をトークン(Token)に分割する。
トークン＝プログラムの最小単位の単語。
例えば、int main() { return 0; }ならば、
int | main | ( | ) | { | return | 0 | ; | }
に分かれる。
これらはToken*のリストを返す。

## token
トークンには種類があり、
identifier, keyword, paren_l, paren_r, integer_literal, string_literal, ...
という種類がある。
Tokenは以下のような要素を持つことが望ましい
1. 種類
    先ほどあげたやつ
2. 値
    同じidentifierでも、"result"とか、"int"とか「中身」を持つものがある。
    integer_literalならば数字とか、何の数字なのかという情報を格納しておいてほしい。
3. ファイル上の場所
    ファイル何行目の何文字目から何文字目に位置していたのかを記録しておくと、エラーの内容が出しやすい。
    今回はSourcelocation型をsupportフォルダ下に定義しておくことにする。

## parser
連続するトークンの列から、何の文なのかを割り出す作業。
int | main | ( | ) | { | return | 0 | ; | }はFunctionDefinitionみたいな文になることが集約される。
int a = 0;はAssignationという文の形態で、左辺はNewVariableDeclaration、右辺はImmediateIntegerみたいな感じだと思う。
これらはAbstract Syntax Treeとか言ったりするものなので、調べてみてほしい。
これらはAST*のリストを返す。

## AST
文の構造を記憶しておく構造体。

## engine
文が割り出せたので、あとは実行するだけ。
FPObjectみたいな構造体を作って実行するとか
Tagged Memory法などさまざまな方法があるので一緒に相談して作ってみたい

## support
何かとよく使う構造はこの辺に作ってしまおう。
今の所ファイル上での位置を示すSourceLocationはここに入っています。