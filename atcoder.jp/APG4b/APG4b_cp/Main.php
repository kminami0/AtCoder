<?php
  // 変数a,b,cにtrueまたはfalseを代入してAtCoderと出力されるようにする。
  $a = true;
  $b = false;
  $c = true;

  if($a){
    echo "At";
  }else{
    echo "Yo";
  }

  if(!$a and $b){
    echo "Bo";
  }else if(!$b or $c){
    echo "Co";
  }

  if($a and $b and $c){
    echo "foo!";
  }else if(true and false){
    echo "yeah!";
  }else if(!$a or $c){
	echo "der";
  }

  echo "\n";
?>