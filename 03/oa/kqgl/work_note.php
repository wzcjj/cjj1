<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="1" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list">
		<?php echo read_field($conn,"tb_list","f_name",$_GET[u_id]); ?>
		</td>
	</tr>
</table>
<table width="765" border="0" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF">
<form method="post" action="#">
	<tr>
		<td colspan="5" height="30" align="center" valign="middle">
		<a href="#" onclick="javascript:openWin=open('p_login.php?r_id=<?php echo $_GET[u_id]; ?>' ,'','width=420,height=260,scrollbars=no');">
<?php
	if($_GET[u_id] == 14){
		echo "���°�Ǽ�";
	}else if($_GET[u_id] == 15){
		echo "���¼ٵǼ�";
	}else if($_GET[u_id] == 16){
		echo "�Ӱ�Ǽ�";		
	}
?>
		</a></td>
	</tr>
	<tr>
		<td width="100" height="20" align="center" valign="middle">����</td>
		<td width="100" height="20" align="center" valign="middle">�Ǽ�ʱ��</td>
		<td width="100" align="center" valign="middle">�Ǽ�����</td>
		<td width="100" align="center" valign="middle">�Ǽ�״̬</td>
		<td  align="center" valign="middle">��ע</td>
	</tr>
<?php
	$sqlstr = "select id,r_date,r_time,r_type,r_state,r_remark from tb_register where r_id = ".$_GET[u_id]." and p_id = ".$_SESSION[id]." order by id desc";
	$result = mysql_query($sqlstr,$conn);
	while($rows = mysql_fetch_array($result)){
?>
	<tr>
		<td height="25" align="center" valign="middle"><?php echo $rows[r_date]; ?></td>
		<td height="25" align="center" valign="middle"><?php echo $rows[r_time]; ?></td>
		<td height="25" align="center" valign="middle">
		
		<?php 
			switch($rows[r_type]){
				case 0:
					echo  "�°�";
					break;
				case 1:
					echo "�ϰ�";
					break;
				case 2:
					echo "�Ӱ�ǩ��";
					break;
				case 3:
					echo "�Ӱ�ǩ��";
					break;
				case 4:
					echo "����";
					break;
				case 5:
					echo "�¼�";
					break;
			}
		?>
		
		</td>
		<td height="25" align="center" valign="middle">
		<?php
			switch($rows[r_type]){
				case 1:
					echo ($rows[r_state] == 0)?"�����ϰ�":"�ٵ�"; 
					break;
				case 0:
					echo ($rows[r_state] == 0)?"����":"�����°�"; 
				    break;
				case 2:
					echo ($rows[r_state] == 0)?"����Ӱ�":"���Ӱ�";
					break;
				case 3:
					echo ($rows[r_state] == 0)?"����":"�����°�";
				    break;
				case 4:
					echo ($rows[r_state] == 0)?"����":"�¼�";
					break;
			}
		?>
		</td>
		<td height="25" align="center" valign="middle"><?php echo ($rows[r_remark] != null)?$rows[r_remark]:��; ?></td>
	</tr>
<?php	
	}
?>
</form>
</table>
