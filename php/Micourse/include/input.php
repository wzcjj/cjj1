<?php

function change_input($str) {
	if (!get_magic_quotes_gpc())
		return mysqli_real_escape_string(new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME), $str);
}
function show_in_html($str) {
	$str = htmlspecialchars($str, ENT_QUOTES);
	$str = str_replace(" ","&nbsp;", $str);
	$str = str_replace("\r\n","<br />", $str);
	$str = str_replace("\n","<br />", $str);
	return $str;
}

function test_username($str) {
	return preg_match("/^[0-9a-zA-z]{6,10}$/", $str);
}

function test_password($str) {
	return preg_match("/^*{6,20}$/",$str);
}

function test_email($str) {
	if (strlen($str) > 40) return false;
	return preg_match("/^[_\.0-9a-zA-Z-]+@([0-9a-zA-Z][0-9a-zA-Z-]+\.)+[A-Za-z]{2,3}$/",$str);
}

function test_phone($str) {
	return preg_match("/^[0-9]{7,15}$/",$str);
}

?>
