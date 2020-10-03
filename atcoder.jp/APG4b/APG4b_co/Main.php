<?php
  $p = trim(fgets(STDIN));
  
  // パターン1
  if($p == 1){
    $price = trim(fgets(STDIN));
  }

  // パターン2
  if($p == 2){
    $text = trim(fgets(STDIN));
    $price = trim(fgets(STDIN));
  }

  $N = trim(fgets(STDIN));

  if($text){
    echo $text."!\n";
  }
  echo $price * $N."\n";
?>