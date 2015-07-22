<?php

class Student extends User {
	const STUDENT = 0;

	/**
	 * 检查用户名是否已存在
	 * @return  EXIST or NOT_EXIST
	 * @version 2015年7月11日
	 * @author wzcjj
	 */
	public function register($password, $permission = User::STUDENT) {
		parent::register($password, $permission = User::STUDENT);
		$nickname = '';
		for(i=0 ; !!$username[i] && $username[i]!='@' ; i++)$nickname += $username[i];
		$this->set_nickname("$nickname");
	}

	//提供学号
	//返回id
	public function fetch_id($name){
		$sql = "SELECT *
			FROM student
			WHERE name = '$name'";
		$query = $this->query($sql);
		$row = mysqli_fetch_assoc($query);
		return $row['uid'];
	}

	public function fetch_name() {
		$sql = "SELECT name
			FROM student
			WHERE id = '$this->id'";
		$query = $this->query($sql);
		$row = mysqli_fetch_assoc($query);
		return $row['name'];
	}

}

?>