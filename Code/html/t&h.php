<?php
	$mysqli = new mysqli("localhost", "pi", "", "sensor");
	$interval=3;
	echo" DATA:<br>";
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
 ?>
