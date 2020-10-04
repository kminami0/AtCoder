<?php
$N = trim(fgets(STDIN));
$A = trim(fgets(STDIN));
  
for($i = 0; $i < $N; $i++){
  fscanf(STDIN, "%s %d", $op, $B);
  if($op == "/" and $B == 0){
    echo "error\n";
    exit;
  }
  echo ($i+1).":";
  if($op == "+"){
    $A += $B;
  }else if($op == "-"){
    $A -= $B;
  }else if($op == "*"){
    $A *= $B;
  }else{
    $A /= $B;
    if($A >= 0){
       $A = floor($A);
    }else{
       $A = ceil($A);
    }
  }
  echo $A."\n";
}
?>