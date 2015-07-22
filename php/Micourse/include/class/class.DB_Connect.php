<?php

class DB_Connect {
	
	protected $root_conn;

	public function __construct() {
		$this->root_conn = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
		if($this->root_conn->connect_error) {
			die("Connect error: ".mysql_error());
		}
		$this->root_conn->query("set names utf8");
	}

	public function query($sql) {
		$query = $this->root_conn->query($sql);
		if (!$query) {
			die($this->root_conn->error);
		}
		return $query;
	}
}

?>