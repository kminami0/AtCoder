<?php
$data = explode(" ", trim(fgets(STDIN)));
for($i = 0; $i < 4; $i++){
  if($data[$i] == $data[$i+1]){
    echo "YES\n";
    exit;
  }
}
echo "NO\n";
?>