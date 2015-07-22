<?php

/**
 * User类
 * @version 2015年7月11日
 * @author wzcjj
 */
class User extends DB_Connect {

	const STUDENT = 0, ADMIN = 1;	// 学生代表0，管理员代表1，对应数据库authentiate表的permission值
	const LOGIN_SUCCESS = 1, LOGIN_FAIL = 0;	// 成功是1，失败是0 
	const SUCCESS = 1, FAIL = 0;	// 成功是1，失败是0 
	const EXIST = 1, NOT_EXIST = 0;	// 存在是1，不存在是0 
	const USER = 'user';
	
	private $username;

	public function __construct($username) {
		parent::__construct();
		$this->username = $username;
	}

	/**
	 * 验证用户登录,传进的密码已经过MD5加密
	 * 请参照数据库
	 * @return  LOGIN_SUCCESS or LOGIN_FAIL
	 * @version 2015年7月11日 
	 * @author wzcjj
	 */
	public function login($password) {
		$username = change_input($this->username);
		
		$sql = "SELECT username , password , permission
				FROM user
				WHERE username = '$username' AND password = '$password'";
		$query = $this->query($sql);
		$result = mysqli_fetch_assoc($query);
		if(!$result) {
			return User::LOGIN_FAIL;
		}
		
		$_SESSION[User::USER] = array(
			'username' => $username);
		return User::LOGIN_SUCCESS;
	}

	/**
	 * 修改密码,传进的密码已经过MD5加密
	 * 请参照数据库
	 * @return  SUCCESS or FAIL
	 * @version 2015年7月11日 
	 * @author wzcjj
	 */
	public function change_password($old_password, $password) {
		$sql = "SELECT username , password
				FROM user
				WHERE username = '$this->username' AND password = '$old_password'";
		$query = $this->query($sql);
		$result = mysqli_fetch_assoc($query);
		if(!$result) {
			return User::FAIL;
		}
		$sql = "UPDATE authentiate
			SET password='$password'
			WHERE id = '$id'";
		$this->query($sql);
		return User::SUCCESS;
	}

	/**
	 * 检查用户名是否已存在
	 * @return  EXIST or NOT_EXIST
	 * @version 2015年7月11日
	 * @author wzcjj
	 */
	public function user_exist(){
		$sql = "SELECT username 
				FROM user
				WHERE username = '$this->username'";
		$query = $this->query($sql);
		$result = mysqli_fetch_assoc($query);
		if(!$result) {
			return User::NOT_EXIST;
		}
		else {
			return User::EXIST;
		}
	}
	/**
	 * 注册用户,传进的密码已经过MD5加密
	 * @return  SUCCESS or FAIL
	 * @version 2015年7月11日
	 * @author wzcjj
	 */
	public function register($password, $permission = User::STUDENT){
		if(user_exist())return User::FAIL;
		$sql = "INSERT INTO user (username, password, permission)
				VALUES ('$this->username', '$password', '$permission')";
		$query = $this->query($sql);
		//$this->login($password);//可直接登录
		return User::SUCCESS;
	}

	/**
	 * 邮箱验证
	 * @return  SUCCESS or FAIL
	 * @version 2015年7月11日
	 * @author wzcjj
	 */
	public function email() {
		//待填充
	}
}
?>