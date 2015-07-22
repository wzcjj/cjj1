<?php

if(!defined('Micourse_ROOT'))
	exit('The constant Micourse_ROOT must be defined !');

session_start();

include_once(Micourse_ROOT."include/input.php");


include_once(Micourse_ROOT."include/db_cred.php");


function __autoload($class_name) {
	chdir(dirname(__FILE__));
	$filename = "class/class.".$class_name.".php";
	if (file_exists($filename)) {
		include_once($filename);
	}
}
spl_autoload_register("__autoload");
?>
