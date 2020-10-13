<?php
function f0($N){
  return 1;
}

function f1($N, $M){
  $s = 0;
  for($i = 0; $i < $N; $i++){
    $s++;
  }
  for($i = 0; $i < $M; $i++){
    $s++;
  }
  return $s;
}

function f2($N){
  $s = 0;
  for($i = 0; $i < $N; $i++){
    $t = $N;
    $cnt = 0;
    while($t > 0){
      $cnt++;
      $t = floor($t / 2);
    }
	$s += $cnt;
  }
  return $s;
}

function f3($N){
  $s = 0;
  for($i = 0; $i < 3; $i++){
    for($j = 0; $j < 3; $j++){
      $s++;
    }
  }
  return $s;
}

function f4($N){
  $s = 0;
  for($i = 0; $i < $N; $i++){
    for($j = 0; $j < $N; $j++){
      $s += $i + $j;
    }
  }
  return $s;
}

function f5($N, $M){
  $s = 0;
  for($i = 0; $i < $N; $i++){
    for($j = 0; $j < $M; $j++){
      $s += $i + $j;
    }
  }
  return $s;
}

fscanf(STDIN, "%d %d", $N, $M);
$a0 = -1;
$a1 = -1;
$a2 = -1;
$a3 = -1;
$a4 = -1;
$a5 = -1;

// 計算量が最も大きいもの1つだけコメントアウトする
$a0 = f0($N);
$a1 = f1($N, $M);
$a2 = f2($N);
$a3 = f3($N);
//$a4 = f4($N);
$a5 = f5($N, $M);
while($a5 > 2147483647){
  $a5 -= 2147483648 * 2;
}

echo "f0: ".$a0."\n";
echo "f1: ".$a1."\n";
echo "f2: ".$a2."\n";
echo "f3: ".$a3."\n";
echo "f4: ".$a4."\n";
echo "f5: ".$a5."\n";
?>