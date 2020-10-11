<?php
fscanf(STDIN, "%d %d", $N, $M);
for($i = 0; $i < $M; $i++){
  fscanf(STDIN, "%d %d", $A[], $B[]);
}

for($i = 0; $i < $N; $i++){
  $R[] = [];
  for($j = 0; $j < $N; $j++){
    $R[$i][] = '-';
  }
}

for($i = 0; $i < $M; $i++){
  $R[$A[$i]-1][$B[$i]-1] = 'o';
  $R[$B[$i]-1][$A[$i]-1] = 'x';
}

for($i = 0; $i < $N; $i++){
  for($j = 0; $j < $N; $j++){
    echo $R[$i][$j];
    if($j == $N - 1){
      echo "\n";
    }
    else{
      echo " ";
    }
  }
}
?>