<?php
  fscanf(STDIN, "%d %d %d", $x, $a, $b);
  
  // 1.の出力
  $x++;
  echo $x."\n";

  $x *= $a + $b;
  echo $x."\n";

  $x *= $x;
  echo $x."\n";

  $x--;
  echo $x."\n";
?>