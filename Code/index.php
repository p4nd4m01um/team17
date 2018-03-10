<?php

	
	ini_set("display_errors","on");
	error_reporting(E_ALL);
//	define('DB_HOST', 'localhost');
//	define('DB_USER', 'pi');
//	define('DB_PWD', '');
//	define('DB_NAME', 'test');
//
//	$connect = mysqli_connect(DB_HOST, DB_USER, DB_PWD) or die('error1'.mysql_error());
//	mysqli_select_db($connect,DB_NAME) or die('error2'.mysql_error());
//	$query = "SELECT * FROM accounts";
//	$result = mysqli_query($query) or die ('error3'.mysql_error());

//	print_r(mysqli_fetch_array($result,MYSQL_ASSOC));
//	echo "hellow world";
//	$con = mysqli_connect("localhost", "pi", "", "test");
//	echo($con);
//	$db = mysqli_connect('localhost','pi','','test') or die("failed to connect:".mysqli_error());
//	echo "connected ok";
//	mysqli_close($db);

	$mysqli = new mysqli("localhost", "pi", "", "test");
	$sql = "SELECT * FROM accounts";
	$result = $mysqli->query($sql);
	$row = $result->fetch_assoc();
	echo $row["passwd"];
	$result->free();
	$mysqli->close();

?>
