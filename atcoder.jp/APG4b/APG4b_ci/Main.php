<?php
fscanf(STDIN, "%d %d %d", $A, $B, $C);
echo (max($A, $B, $C) - min($A, $B, $C))."\n";
?>