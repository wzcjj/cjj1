<?
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
	//�ж����벿�������Ƿ��ظ�
	if(isbool($_POST[d_name])){
		echo "<script>alert('�����Ѵ��ڣ�����������!!');history.go(-1);</script>";
		exit();
	}
	//��Ӳ��ţ�ȷ���ϼ����ź͸�����
	if($_POST[u_id] != "0"){
		$sqlstr = "select top_depart from tb_depart where id = ".$_POST[u_id];
		$result = mysql_query($sqlstr,$conn);
		$rows = mysql_fetch_row($result);
		if ($rows[top_depart] != 0)
		$top_depart = $rows[top_depart];
	else
		$top_depart = $_POST[u_id];
	}
	else
		$top_depart = 0;
	$sqlstr = "insert into tb_depart values(null,'".$_POST[d_name]."',".$top_depart.",".$_POST[u_id].",'".$_POST[remark]."')";
	$result = mysql_query($sqlstr,$conn); 
	//�����������
	re_message($result,"show_depart.php")
?>
