<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
	$fields = read_field($conn,"tb_group","u_group",$_GET[id]);
	/*ɾ���û���*/
	$sqlstr = "delete from tb_group where id = ".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	/*****************************/
	/*ɾ��list�����б������Ӧ����*/
	$l_sqlstr = "select * from tb_list";
	$l_result = mysql_query($l_sqlstr,$conn);
	while($l_rows = mysql_fetch_row($l_result)){
		if($l_rows[4] != "0"){
			/* �����û����б� */
			$l_list = split(",",$l_rows[4]);
			$new_fields = "";
			for($num = 0; $num < (count($l_list) -1); $num++){
				if($fields != $l_list[$num]){
					$new_fields .= $l_list[$num].",";
				}
			}
			$n_sqlstr = "update tb_list set o_group = '".$new_fields."' where id = ".$l_rows[0];
			mysql_query($n_sqlstr,$conn);
			
		}
		else{
		
		}
	}
	/******************************/
	if($result)
		echo "<script>alert('ɾ���ɹ���');location='user_group.php';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
?>
