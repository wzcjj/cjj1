<?php
//�������ܣ���¼��̨������Ϣ
//��¼����Ա�Ĳ���
//��¼���ǳ�����ӡ�ɾ����
//����$actionΪ��������
session_start();
function w_log($act){
	$filename = "./admin/log.txt";
	$f_open = fopen($filename,"a+");
	$str = $_SESSION['u_name'].",".date("Y-m-d H:i:s").",".$_SERVER['REMOTE_ADDR'].",".$act."\n";
	fwrite($f_open,$str);
	fclose($f_open);
}
//�����û�����ȡ��������
//$conn�����ݿ���Դ
//$unmae����¼�û�
//$ugroup���û�������
function getGroup($conn,$uname,$ugroup){
	$sqlstr = "select u_member from tb_group where id = ".$ugroup;
	$result = mysql_query($sqlstr,$conn);
	$rows = mysql_fetch_row($result);
	$num = split(",",$rows[0]);
	$bool = false;
	for($i = 0;$i < count($num);$i++){
		if($uname == $num[$i])
			$bool = true;	
	}
	return $bool;
}
//�ж��Ƿ�����ؼ���
//keyworld��Ҫ���ҵùؼ���
function get_tp($conn){
	$sqlstr = "select f_type from tb_list group by f_type order by id";
	$result = mysql_query($sqlstr,$conn);
	return $result;
}
//��ȡ�ֶ�
//$conn,���ݿ�����
//$dataname�����ݱ�����
//$fieldname��Ҫ�����ֶ�
//$n_id������id��
function read_field($conn,$tablename,$fieldname,$n_id){
	$sqlstr = "select ".$fieldname." from ".$tablename." where id = ".$n_id;
	$result = mysql_query($sqlstr,$conn);
	$rows = mysql_fetch_row($result);
	return $rows[0];
}
//���ش�����Ϣ
//$l_address����ת��ַ
function re_message($result,$l_address){
	if($result)
		echo "<script>alert('�����ɹ���');location='".$l_address."';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
}
?>