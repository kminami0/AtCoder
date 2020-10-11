<?php
fscanf(STDIN, "%d %d", $N, $S);
$A = explode(" ", trim(fgets(STDIN)));
$P = explode(" ", trim(fgets(STDIN)));

$ans = 0;
for($i = 0; $i < $N; $i++){
  for($j = 0; $j < $N; $j++){
    if($A[$i] + $P[$j] == $S){
      $ans++;
    }
  }
}
echo $ans . "\n";
?>