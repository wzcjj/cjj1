<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
if(($_POST[a_title] != "") and ($_POST[a_content] != "")){
		$i_sql = "update tb_iss set i_title = '".$_POST[a_title]."', i_content = '".$_POST[a_content]."',i_time = now(),i_state = 3 where id = ".$_POST[id];
		$i_rst = mysql_query($i_sql,$conn);
		if($i_rst){
			echo "<script>alert('�޸ĳɹ�!!');location='au_issuance.php';</script>";
		}else{
			echo "<script>alert('ϵͳ��æ,���Ժ����ԣ���');history.go(-1);</script>";
		}
	}else{
		echo "<script>alert('����ȷ��¼');location='index.php';</script>";
	}
?>
