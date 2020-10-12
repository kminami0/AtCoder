<?php
// x番の組織が親組織に提出する枚数を返す
// childrenは組織の関係を表す2次元配列(参照渡し)
function count_report_num(&$children, $x) {
  $cnt = 0;
  foreach($children[$x] as $child){
    $cnt += count_report_num($children, $child);
  }
  return $cnt+1;
}

$N = trim(fgets(STDIN));
$p = explode(" ", trim(fgets(STDIN))); // 各組織の親組織を示す配列
array_unshift($p, -1); // 0番組織の親組織は存在しないので-1を入れておく

// 組織の関係から2次元配列を作る
for($i = 0; $i < $N; $i++){
  $children[] = [];
}
for($i = 1; $i < $N; $i++){
  $parent = $p[$i]; // i番の親組織の番号
  $children[$parent][] = $i; // parentの子組織一覧にi番を追加
}

// 各組織について、答えを出力
for($i = 0; $i < $N; $i++){
  echo count_report_num($children, $i)."\n";
}
?>