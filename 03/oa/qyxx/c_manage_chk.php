<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
	if($_GET[action] == "del"){
		if($_GET[id] == 1)
		{
			echo "<script>alert('��˾��鲻����ɾ��');history.go(-1);</script>";
		}else{
			$del_sql = "delete from tb_company where id = ".$_GET[id];
			$result = mysql_query($del_sql,$conn);
			re_message($result,"r_system.php");
		}
	}
	if($_POST[action] == "add"){
		$add_sql = "insert into tb_company values(null,'".$_POST[u_title]."','".$_POST[u_content]."')";
		$result = mysql_query($add_sql,$conn);
		re_message($result,"r_system.php");
	}else if($_POST[action] == "modify"){
		$md_sql = "update tb_company set f_name = '".$_POST[u_title]."',f_content = '".$_POST[u_content]."' where id = ".$_POST[id];
		$result = mysql_query($md_sql,$conn);
		re_message($result,"r_system.php");
	}
	else{
		echo "<script>alert('�Ƿ����ӣ����¼');location='index.php';</script>";
	}
?>