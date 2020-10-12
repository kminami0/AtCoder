<?php
// 参照渡しを用いて、呼び出し側の変数の値を変更する
function saiten(&$A, &$correct_count, &$wrong_count) {
  // 呼び出し側のAの各マスを正しい値に修正する
  // Aのうち、正しい値の書かれたマスの個数を correct_count に入れる
  // Aのうち、誤った値の書かれたマスの個数を wrong_count に入れる
 
  for($i = 0; $i < 9; $i++){
    for($j = 0; $j < 9; $j++){
      if($A[$i][$j] == ($i+1)*($j+1)){
        $correct_count++;
      }
      else{
        $A[$i][$j] = ($i+1)*($j+1);
        $wrong_count++;
      }
    }
  }
}


// A君の回答を受け取る

for($i = 0; $i < 9; $i++){
  $A[] = explode(" ", trim(fgets(STDIN)));
}

$correct_count = 0; // ここに正しい値のマスの個数を入れる
$wrong_count = 0;   // ここに誤った値のマスの個数を入れる

// A, correct_count, wrong_countを参照渡し
saiten($A, $correct_count, $wrong_count);

// 正しく修正した表を出力
for ($i = 0; $i < 9; $i++) {
  for ($j = 0; $j < 9; $j++) {
    echo $A[$i][$j];
    if($j < 8){
      echo " ";
    }
    else{
      echo "\n";
    }
  }
}

// 正しいマスの個数を出力
echo $correct_count."\n";
// 誤っているマスの個数を出力
echo $wrong_count."\n";
?>