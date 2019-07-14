<?php

header("Expires: Tue, 01 Jan 2000 00:00:00 GMT");
header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");
header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");

include("tsp/main.inc");
$page = $_REQUEST["page"];
$lng="es";
$main = new tspAPI();
echo $main->setBegin($lng);
echo $main->makePageAll();
echo $main->setPages($lng, $page);
echo $main->setEnd($lng);

?>

