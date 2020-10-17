<?php
// 各操作を行う関数を実装する
  
// AとBに共通して含まれる要素からなる集合を返す
function intersection($A, $B){
  return $A & $B;
}
// AとBのうち少なくとも一方に含まれる要素からなる集合を返す
function union_set($A, $B){
  return $A | $B;
}
// AとBのうちどちらか一方にだけ含まれる要素からなる集合を返す
function symmetric_diff($A, $B){
  return $A ^ $B;
}
// Aから値xを除く
function subtract($A, $x){
  return $A ^ (1 << $x);
}
// Aに含まれる要素に1を加える(ただし、要素49が含まれる場合は0になるものとする)
function increment($A){
  $A = $A << 1;
  if($A >> 50){
    $A++;
  }
  return $A;
}
// Aに含まれる要素から1を引く(ただし、要素0が含まれる場合は49になるものとする)
function decrement($A){
  if($A & 1){
    $A = $A | (1 << 50);
  }
  return $A >> 1;
}

// Sに値xを加える
function add($S, $x){
  $S = $S | (1 << $x);
  return $S;
}

// 集合Sの内容を昇順で出力する(スペース区切りで各要素の値を出力する)
function print_set($S){
  for($i = 0; $i < 50; $i++){
    if($S & (1 << $i)){
      $cont[] = $i;
    }
  }
  for($i = 0; $i < count($cont); $i++){
    if($i > 0){
      echo " ";
    }
    echo $cont[$i];
  }
  echo "\n";
}

$N = trim(fgets(STDIN));
$A = 0;
$arrayA = explode(" ", trim(fgets(STDIN)));
for($i = 0; $i < $N; $i++){
  $x = $arrayA[$i];
  $A = add($A, $x);
}
$M = trim(fgets(STDIN));
$B = 0;
$arrayB = explode(" ", trim(fgets(STDIN)));
for($i = 0; $i < $M; $i++){
  $x = $arrayB[$i];
  $B = add($B, $x);
}

// 操作
$com = explode(" ", trim(fgets(STDIN)));

if($com[0] == "intersection"){
  print_set(intersection($A, $B));
}
else if($com[0] == "union_set"){
  print_set(union_set($A, $B));
}
else if($com[0] == "symmetric_diff"){
  print_set(symmetric_diff($A, $B));
}
else if($com[0] == "subtract"){
  $x = $com[1];
  print_set(subtract($A, $x));
}
else if($com[0] == "increment"){
  print_set(increment($A));
}
else if($com[0] == "decrement"){
  print_set(decrement($A));
}
?>