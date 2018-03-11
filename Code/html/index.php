#<?php
//	phpinfo();
//	get_loaded_extensions();
//	$cmd = shell_exec('/home/pi/team17/Code/sensor_data_test/.thread_t');
	exec('/home/pi/team17/Code/sensor_data_test/.thread_t');
	ini_set("display_errors","on");
	error_reporting(E_ALL);
	$mysqli = new mysqli("localhost", "pi", "", "sensor");
	$interval=3;
	echo" DATA:<br>";
//	$buffer = ini_get('output_buffering');
	ob_end_flush();
	do{
		$sql = "SELECT * FROM THS";
		$result = $mysqli->query($sql);
		$row = $result->fetch_assoc();

		echo "Temperatur degree:\n";
		echo $row["value"];
		echo "<br>";
		echo "Humidity degree:\n";
		echo $row["value2"];
		echo "<br>";
		echo "<br>";
	//	ob_clean();
		//ob_flush();
		//ob_flush();
		//ob_clean();
		//ob_start();
		//echo"<script language=JavaScript> location.reload();</script>";		
		sleep($interval);
		//ob_clean();
		flush();
		//ob_end_flush();
	}while(true);

//	$con = mysqli_connect("localhost", "pi", "", "sensor");

//	echo "this";

 ?>
