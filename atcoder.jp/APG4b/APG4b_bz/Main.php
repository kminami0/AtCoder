<?php
$N = trim(fgets(STDIN));
$A = explode(" ", trim(fgets(STDIN)));
for($i = 0; $i < $N; $i++){
  $cnt[$A[$i]] = 0;
}
for($i = 0; $i < $N; $i++){
  $cnt[$A[$i]]++;
}
arsort($cnt);
foreach($cnt as $key => $value){
  echo $key." ".$value."\n";
  exit;
}
?>