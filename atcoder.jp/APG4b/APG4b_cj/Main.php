<?php
$N = trim(fgets(STDIN));
$A = explode(" ", fgets(STDIN));

$sum = 0;
for($i = 0; $i < $N; $i++){
  $sum += $A[$i];
}
$avg = floor($sum / $N);
for($i = 0; $i < $N; $i++){
  echo abs($A[$i] - $avg)."\n";
}
?>