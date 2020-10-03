<?php
  $aopb = explode(" ", trim(fgets(STDIN)));
  if($aopb[1] == "+"){
    echo $aopb[0] + $aopb[2]."\n";
  }else if($aopb[1] == "-"){
    echo $aopb[0] - $aopb[2]."\n";
  }else if($aopb[1] == "*"){
    echo $aopb[0] * $aopb[2]."\n";
  }else if($aopb[1] == "/"){
    if($aopb[2] == 0){
      echo "error\n";
    }else{
      echo floor($aopb[0] / $aopb[2])."\n";
    }
  }else{
    echo "error\n";
  }
?>