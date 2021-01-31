<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$status = 1;
	$user_name = $_POST['user_name'];
	
		$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	$q1 = "SELECT user_id FROM user_list WHERE user_name='".$user_name."'";
	$result = mysqli_query($con,$q1);
	$row= mysqli_fetch_row($result);
	$user_id= $row[0];
	
	$sql = "UPDATE auth SET status='".$status."' WHERE user_id='".$user_id."'";
	mysqli_query($con,$sql);
	mysqli_close($con);
	echo "Gate Will Open Soon";
	?>