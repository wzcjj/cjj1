<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
	//��ȡ�û��ʺ�
	$fields = read_field($conn,"tb_users","u_name",$_GET[id]);
	/*ɾ���û�*/
	$sqlstr = "delete from tb_users where id = ".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	/*******************************/
	/*ɾ��group�������Ӧ���û�*/
	$l_sqlstr = "select * from tb_group";
	$l_result = mysql_query($l_sqlstr,$conn);
	while($l_rows = mysql_fetch_row($l_result)){
		/* �����û����б� */
		$l_list = split(",",$l_rows[2]);
			$new_fields = "";
			for($num = 0; $num < (count($l_list) -1); $num++){
				if($fields != $l_list[$num]){
					$new_fields .= $l_list[$num].",";
				}
			}
			$n_sqlstr = "update tb_group set u_member = '".$new_fields."' where id = ".$l_rows[0];
			mysql_query($n_sqlstr,$conn);
	}
	/******************************/
	if($result)
		echo "<script>alert('ɾ���ɹ���');location='show_staf.php';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
?>