<?php
// 1人のテストの点数を表す配列から合計点を計算して返す関数
// 引数 scores: scores.at(i)にi番目のテストの点数が入っている
// 返り値: 1人のテストの合計点
function sum($scores){
  $sum = 0;
  foreach($scores as $num){
    $sum += $num;
  }
  return $sum;
}

// 3人の合計点からプレゼントの予算を計算して出力する関数
// 引数 sum_a: A君のテストの合計点
// 引数 sum_b: B君のテストの合計点
// 引数 sum_c: C君のテストの合計点
// 返り値: なし
function output($sum_a, $sum_b, $sum_c){
	echo ($sum_a * $sum_b * $sum_c) . "\n";
}

// N個の入力を受け取って配列に入れて返す関数
// 引数 N: 入力を受け取る個数
// 返り値: 受け取ったN個の入力の配列
function input($N){
  $vec = explode(" ", trim(fgets(STDIN)));
  return $vec;
}

// 科目の数Nを受け取る
$N = trim(fgets(STDIN));

// それぞれのテストの点数を受け取る
$A = input($N);
$B = input($N);
$C = input($N);

// それぞれの合計点を計算
$sum_A = sum($A);
$sum_B = sum($B);
$sum_C = sum($C);

// プレゼントの予算を出力
output($sum_A, $sum_B, $sum_C);
?>