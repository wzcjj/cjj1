<?php
session_start();
//����list_menuΪѭ������¼����Ų˵�
//$numΪ�ϼ�����id��
//$widΪ�����
//$mΪ��Ԫ��<tr id=..>�ı���ֵ
function list_menu($num,$wid,&$m){
	$conn = mysql_connect("localhost","root","root");
	mysql_select_db("db_office",$conn);
	mysql_query("set names gb2312");
	//��ѯͬ���������
	$sqlstr = "select * from tb_depart where up_depart = ".$num;
	$result = mysql_query($sqlstr,$conn);
?>
<!--������-->
<tr id="OpenRep<?php echo $m; ?>" style="display:none;">
	<td>				
		<table width="<?php echo $wid; ?>%"  border="0" cellspacing="0" cellpadding="0">
			<tr>
				<td height="25" align="center">
					<table width="<?php echo ($wid -3); ?>%"  border="0" cellspacing="0" cellpadding="0">
<?php
	//ѭ�����ͬ������
	while($rows = mysql_fetch_row($result)){
		//�鿴��������
		$sqlstr1 = "select * from tb_depart where up_depart = ".$rows[0];
		$result1 = mysql_query($sqlstr1,$conn);
		$nu = mysql_num_rows($result1);
		//�����ǰ����û����������ʱ
		if(!$nu){
			$m += 1;
?>
						 <tr>
                    		<td width="100%" height="25" align="left">&nbsp;&nbsp;&nbsp;<img src="../images/folder.gif" width="30" height="16" border="0">&nbsp;<?php echo $rows[1] ?>------------------<a href="edit_depart.php?id=<?php echo $rows[0]; ?>">�޸�</a>||<a href="del_depart_chk.php?id=<?php echo $rows[0] ?>" onClick="return cfm();">ɾ��</a></td>
                  		</tr>
									
<?php
		}
		//��ǰ��������������ʱ
		else{
			$m += 1;
?>
						<tr onMouseOver="this.style.background='#96F7F4'" onMouseOut="this.style.background=''">
							<td height="25">&nbsp;<a href="Javascript:ShowTR(img<?php echo $m; ?>,OpenRep<?php echo $m; ?>)"><img src="../Images/jia.gif" alt="չ��" name="img<?php echo $m; ?>" width="32" height="14" border="0" id="img<?php echo $m; ?>">&nbsp;<?php echo $rows[1];?></a>------------------<a href="edit_depart.php?id=<?php echo $rows[0]; ?>">�޸�</a>||ɾ��</td>
						</tr>
<?php
			list_menu($rows[0],$wid,$m);
		}
	}
?>
           		  </table>
				</td>
           	</tr>
         </table>
	</td>
</tr>
<?php
}
//��¼��̨������Ϣ
//��¼����Ա�Ĳ���
//��¼���ǳ�����ӡ�ɾ����
//����$actionΪ��������
function w_log($act){
	$filename = "log.txt";
	if(file_exists($filename)){
		$f_open = fopen($filename,"a+");
	}
	else
	{
		$f_open = fopen($filename,"w+");
	}
		$str = $_SESSION['controller'].",".date("Y-m-d H:i:s").",".$_SERVER['REMOTE_ADDR'].",".$act."\n";
		fwrite($f_open,$str);
		fclose($f_open);
}
//ɾ��ϵͳ��־
function c_log(){
	$filename="../log.txt";
	if(file_exists($filename))
		unlink($filename);
	else
		echo "<script>alert('����ϵͳ��־��');history.go(-1);</script>";
}
//���ش�����Ϣ
//$l_address����ת��ַ
function re_message($result,$l_address){
	if($result)
		echo "<script>alert('�����ɹ���');location='".$l_address."';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
}

//�鿴������Ϣ�Ƿ��ظ�
function isbool($dname){
	$conn = mysql_connect("localhost","root","root");
	mysql_select_db("db_office",$conn);
	mysql_query("set names gb2312");
	$sqlstr = "select * from tb_depart where d_name = '".$dname."'";
	$result = mysql_query($sqlstr,$conn);
	if(mysql_num_rows($result)>0)
		$isbool = true;
	else
		$isbool = false;
	return $isbool;
}
//�����ļ����µ��ļ��б�
function show_file(){
	$folder_name = "../bak";
	$d_open = opendir($folder_name);
	$num = 0;
	while($file = readdir($d_open)){
		$filename[$num] = $file;
		$num++; 
	}
	closedir($d_open);
	return $filename;
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
?>