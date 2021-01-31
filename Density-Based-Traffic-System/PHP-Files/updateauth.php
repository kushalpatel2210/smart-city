<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$user_id = $_GET['user_id'];
	
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);

	
	$q2 = "UPDATE auth SET book = '0', status = '0' WHERE user_id ='".$user_id."'";
	mysqli_query($con,$q2);
	
	//$q1 = "UPDATE done SET is_counted='0',is_parked='1' WHERE user_id='".$user_id."'";
	//mysqli_query($con,$q1);
	mysqli_close($con);
	?>