<?php
// 以下に、24時間表記の時計クラス Clock を定義する
class Clock{
  private $hour;
  private $minute;
  private $second;
  
  public function set($h, $m, $s){
    $this->hour = $h;
    $this->minute = $m;
    $this->second = $s;
  }
  
  public function to_str(){
    $HH = str_pad($this->hour, 2, 0, STR_PAD_LEFT);
    $MM = str_pad($this->minute, 2, 0, STR_PAD_LEFT);
    $SS = str_pad($this->second, 2, 0, STR_PAD_LEFT);
    return $HH.":".$MM.":".$SS;
  }
  
  public function shift($diff_second){
    $this->second += $diff_second;
    $diff_minute = floor($this->second / 60);
    $this->second %= 60;
    if($this->second < 0){
      $this->second += 60;
    }
    $this->minute += $diff_minute;
    $diff_hour = floor($this->minute / 60);
    $this->minute %= 60;
    if($this->minute < 0){
      $this->minute += 60;
    }
    $this->hour += $diff_hour;
    $this->hour %= 24;
    if($this->hour < 0){
      $this->hour += 24;
    }
  }
}

// 入力を受け取る
fscanf(STDIN, "%d %d %d", $hour, $minute, $second);
$diff_second = trim(fgets(STDIN));

// Clockクラスのインスタンスを宣言
$clock = new Clock;

// setメソッドを呼び出して時刻を設定する
$clock->set($hour, $minute, $second);

// 時刻を出力
echo $clock->to_str()."\n";

// 時計を進める(戻す)
$clock->shift($diff_second);

// 変更後の時刻を出力
echo $clock->to_str()."\n";
?>