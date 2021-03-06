# FullereneViewer
## フラーレンビューア
### 数学

#### NoA (number of automorphisms)
　fullerene の炭素集合から自身への錯体同型写像の数です。

　これは対称軸の全数(src/Config.h で #define CONFIG_DRAW_ALL_AXES_SYMMETRY_IN_GURUGURU_MODE 1 を有効にした場合に表示される)とは違います。  
　例えば C76-2 は NoA=4 ですが、対称軸の数は３本です。これは群論で言うと、位数２の巡回群の直積群は、元の数は４ですが、位数２の元は３個であることに相当します。残り１個は単位元です。

　他の例としては C80-4 は NoA=6 ですが、位数が２の対称軸が３本と、位数が３の対称軸が１本です。これは群論で言うと、S3 という群に相当します。位数が２の対称軸３本にはそれぞれ位数が２の元 (12) と (13) と (23) が対応し、位数が３の対称軸１本には位数が３の元 (123) と (132) の二つが対応し、残る１個は単位元です。

#### 現状
　対称性の高いフラーレンは、`ca->fill_n_polygons_around_carbons_closed_to_center_and_pentagons(val, num);` の組み合わせで、対称性の低いフラーレンは、`ca->fill_n_polygon_around_oldest_carbon(val);` の組み合わせで、すべて網羅できていそう。

　C72 が化学的には存在しないらしいが、数学的には見つかった。

#### EPSILON について
　通常、浮動小数点の等値判定は、

    fabs(a−b)≦DBL_EPSILON×a       (ただし a≠0.0)

で行う。

　本シミュレーションでは、浮動小数点を固定小数点的に使用するためと、精度的には float で十分であることから、本シミュレーションでの浮動小数点の等値判定は、

    fabs(a-b)≦FLT_EPSILON       (ただし a≠0.0)

で行う。
ただし、Quaternion.cc での角度0判定は

    fabs(a-b)≦DBL_EPSILON       (ただし a≠0.0)

で行う。(固有値計算で微小角度が表現できずに無限ループしたため)

#### Euler 標数

* オイラーの閉曲面の分類定理

　g-重トーラスの Euler 標数は 2-2g である。

* 平面の Euler 標数

　平面の Euler 標数は 0 である。

#### C60 の特徴
北南半球：五角形+五角形

筒部：なし(俵積み型)

生成式：S1-5b6c5b6b5b

特性式：12@0 60@1 60@4 12@7

#### C70 の特徴
北南半球：五角形+五角形

筒部：俵積み型(5個の六員環)x1

生成式：S1-5b6d5b6b5b

特性式：12@0 40@1 10@2 20@3 20@4 20@5 20@6 2@8

#### C72 の特徴
北南半球：六角形+六角形

筒部：なし(俵積み型)

生成式：S3-5b6c5b6c

特性式：アサートで計算できない

#### C74 の特徴
三分半球：菱形+菱形+菱形

筒部：なし

生成式：S4-6b5c6b5b6b

特性式：アサートで計算できない

#### C76-1 の特徴
四分半球：小三角形+小三角形+小三角形+小三角形

筒部：なし

生成式：S2-6c5b6c5b6b

特性式：12@0 24@1 24@2 24@3 48@5 12@8

#### C78-1 の特徴
北南半球：大三角形+大三角形

筒部：ガンベルト型(9個の六員環)x1

生成式：S2-5b6c5b6c5b6b

特性式：12@0 42@1 48@4 18@5 24@7

#### C78-2 の特徴
北南半球：小三角形+小三角形

筒部：俵積み型(6個の五員環)x1

生成式：S2-6c5b6d5b6b

特性式：12@0 18@1 30@2 24@3 42@5 12@7 6@8

#### C80-1 の特徴
北南半球：五角形+五角形

筒部：なし(ガンベルト型)

生成式：S1-6b5b6c5b6b5b

特性式：12@0 60@2 60@5 12@9

#### C80-2 の特徴
北南半球：五角形+五角形

筒部：俵積み型(5個の六員環)x2

生成式：S1-5b6e5b6b5b

特性式：12@0 40@1 20@3 20@4 20@5 20@6 10@8 2@9

#### C80-3 の特徴
北南半球：五角形+五角形

筒部：ガンベルト型(10個の六員環)x1

生成式：S1-6b5b6b5b6c5b

特性式：12@0 10@1 40@2 20@3 40@5 20@7 2@9

#### C84-01 の特徴
北南半球：六角形+三菱

筒部：俵積み型(12個の六員環)x1

生成式：S2-6b5b6d5b6d

特性式：12@0 36@1 48@4 24@5 24@7

#### C84-03 の特徴
北南半球：三菱+三菱

筒部：なし

生成式：S2-6b5b6b5b6b5b6c

特性式：12@0 24@1 12@2 24@3 24@4 12@5 24@6 12@9

#### C90-01 の特徴
北南半球：五角形+五角形

筒部：俵積み型(5個の六員環)x3

生成式：S1-5b6f5b6b5b

特性式：12@0 40@1 30@4 20@5 40@7 2@10

#### C96-04 の特徴
北南半球：大三角形+大三角形

筒部：ガンベルト型(9個の六員環)x2

生成式：S2-5b6f5b6b5b6b

特性式：12@0 36@1 36@4 12@5 36@7 6@9 6@10

#### C100-01 の特徴
北南半球：五角形+五角形

筒部：俵積み型(5個の六員環)x4

生成式：S1-5b6g5b6b5b

特性式：12@0 40@1 20@4 20@5 20@7 20@8 10@9 2@11
