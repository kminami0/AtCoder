<?php
$S = trim(fgets(STDIN));

$ans = 0;
$op = "+";

for($i = 0; $i < strlen($S); $i++){
  if($S[$i] == "1"){
    if($op == "+"){
      $ans++;
    }else{
      $ans--;
    }
  }else{
    $op = $S[$i];
  }
}
echo $ans."\n";
?>