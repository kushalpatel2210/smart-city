<?php
   $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$user_name = $_POST['user_name'];
	$password = $_POST['password'];
	$id = 1;
	if($user_name == "" || $password == ""){
		echo "Enter valid username or password";
	}
	else{
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	
	$sql1 = "SELECT * FROM user_list WHERE user_name='".$user_name."'";
	$result = mysqli_query($con,$sql1);

	if($result->num_rows == 0){
	
	$sql = "INSERT INTO user_list(user_name,password) VALUES('".$user_name."',MD5('".$password."'))" ;

		

	mysqli_query($con,$sql);
	//echo "Registration Successful";	
	$q1 = "SELECT user_id FROM user_list WHERE user_name='".$user_name."'";
	$result = mysqli_query($con,$q1);
	$row= mysqli_fetch_row($result);
	$user_id= $row[0];
	
	$q3 = "INSERT INTO auth(book,status,user_id) VALUES('0','0','".$user_id."')";
	mysqli_query($con,$q3);
	$sql1 = "SELECT pst1, pst2, pst3, pst4, pst5 from parking_status where id = '".$id."'";


$result1 = mysqli_query($con,$sql1);

$response = array();

while($row = mysqli_fetch_array($result1))
{
	array_push($response,array("pst1"=>$row[0],"pst2"=>$row[1],"pst3"=>$row[2],"pst4"=>$row[3],"pst5"=>$row[4]));
}

echo json_encode(array("server_response"=>$response));
mysqli_close($con);
	}
	else{
		echo "user already exists please login or use different username";
	}
	}

?>