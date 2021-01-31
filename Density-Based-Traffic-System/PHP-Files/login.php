<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$user_name = $_POST['user_name'];
	$password = $_POST['password'];
	$id = 1;
	
	$conn = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
if($conn)
{
	$q = "select * from user_list where user_name = '".$user_name."' and password = md5('".$password."')";
	$result = mysqli_query($conn , $q);
	
if(mysqli_num_rows($result) > 0)
{
	//echo "login successful";
	$sql = "SELECT pst1, pst2, pst3, pst4, pst5 from parking_status where id = '".$id."'";


$result1 = mysqli_query($conn,$sql);

$response = array();

while($row = mysqli_fetch_array($result1))
{
	array_push($response,array("pst1"=>$row[0],"pst2"=>$row[1],"pst3"=>$row[2],"pst4"=>$row[3],"pst5"=>$row[4]));
}

echo json_encode(array("server_response"=>$response));
}	else{
	echo "login failed...!";
}
	
	
}else
{
	echo "Not Connnected.....!";
}

mysqli_close($conn);

?>