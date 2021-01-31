<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$user_name = $_POST['user_name'];
	$book = 1;
	
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	$q1 = "SELECT user_id FROM user_list WHERE user_name='".$user_name."'";
	$result = mysqli_query($con,$q1);
	$row= mysqli_fetch_row($result);
	$user_id= $row[0];
	
	/*$q2 = "SELECT is_counted,is_parked,is_exited FROM done WHERE user_id='".$user_id."'";
	$result2 = mysqli_query($con,$q2);
	$row2 = mysqli_fetch_row(result2);
	$count = $row[0];
	$parked = $row[1];
	$exited = $row[2];
	*/
	$sql = "UPDATE auth SET book='".$book."' WHERE user_id='".$user_id."'";
	mysqli_query($con,$sql);
	$q = "INSERT INTO done(user_id,is_counted,is_parked,is_exited) VALUES ('".$user_id."','1','0','0')";
	
	

	mysqli_query($con,$q);
	mysqli_close($con);
	
	echo "0";
	
	/*if($count == 1){
		
		if($parked == 1){
			
				echo "You have to leave the parking area first before booking again";
		}
		else{
			
			echo"you have already booked successfully please proceed to the parking area using your qr code";
			
		}
		
	}*/
	
	
	
	
	
	?>