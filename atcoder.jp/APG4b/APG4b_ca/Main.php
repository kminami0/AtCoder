<?php
$N = trim(fgets(STDIN));
for($i = 0; $i < $N; $i++){
  fscanf(STDIN, "%d %d", $a, $b);
  $array[$b] = $a;
}
ksort($array);
foreach($array as $key => $value){
  echo $value." ".$key."\n";
}
?>